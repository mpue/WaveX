/*
  ==============================================================================

    Track.cpp
    Created: 16 Dec 2016 9:40:38am
    Author:  pueskma

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Track.h"
#include <iostream>

//==============================================================================
Track::Track(double sampleRate)
{
	manager.registerBasicFormats();
	this->sampleRate = sampleRate;
	this->audioBuffer = new AudioSampleBuffer();
	this->maxLength = 600;
	this->name = "empty Track";
    this->volume = 1;
    
}

Track::~Track()
{
	for (std::vector<AudioRegion*>::iterator it = regions.begin(); it != regions.end(); ++it) {
		delete *it;
	}

	delete this->audioBuffer;
}

void Track::clearSelection() {
    for (std::vector<AudioRegion*>::iterator it = regions.begin(); it != regions.end(); ++it) {
        (*it)->setSelected(false);
    }
}

void Track::toggleLoopSelection() {
    for (std::vector<AudioRegion*>::iterator it = regions.begin(); it != regions.end(); ++it) {
        if((*it)->isSelected())
            (*it)->setLoop(!(*it)->isLoop());
    }
}

void Track::removeSelectedRegions() {
    
    for (std::vector<AudioRegion*>::iterator it = regions.begin(); it != regions.end();) {
        if( (*it)->isSelected() ) {
            delete * it;
            it = regions.erase(it);
        }
        else {
            ++it;
        }
    }
    
}

void Track::duplicateSelectedRegions() {
    
    vector<AudioRegion*> selected;
    
    for (std::vector<AudioRegion*>::iterator it = regions.begin(); it != regions.end(); ++it) {
        if((*it)->isSelected())
            selected.push_back((*it));
    }
    
    for (int i = 0;i < selected.size();i++) {
        duplicateRegion(selected.at(i));
    }
    
    selected.clear();
    
}

void Track::duplicateRegion(AudioRegion *region) {
    AudioRegion* duplicate = new AudioRegion(region,manager, sampleRate);
    Rectangle<int>* bounds = new Rectangle<int>(0, 0, region->getThumbnail()->getTotalLength() * 20, 200);
    duplicate->setBounds(region->getWidth() + region->getX(), 0, region->getWidth(), region->getHeight());
    duplicate->setThumbnailBounds(bounds);
    duplicate->setLoopCount(0);
    if (zoom > 0)
        duplicate->setZoom(zoom);
    
    this->regions.push_back(duplicate);
    this->currentRegion = duplicate;
    
    this->currentRegion->toFront(true);
    addAndMakeVisible(duplicate);
    
    clearSelection();
    duplicate->setSelected(true);
    duplicate->setSampleOffset(region->getSampleOffset() + region->getNumSamples());
    duplicate->setOffset(region->getOffset() + region->getWidth());
    
    repaint();
}

void Track::addRegion(File file, double sampleRate) {

	AudioRegion* region = new AudioRegion(file, manager, sampleRate);
	Rectangle<int>* bounds = new Rectangle<int>(0, 0, region->getThumbnail()->getTotalLength() * 20, 200);
    region->setBounds(markerPosition, 0, region->getWidth(), region->getHeight());
	region->setThumbnailBounds(bounds);
    region->setLoopCount(0);
	if (zoom > 0)
		region->setZoom(zoom);

	this->regions.push_back(region);
	this->currentRegion = region;

    this->currentRegion->toFront(true);
    addAndMakeVisible(region);
    
    clearSelection();
    region->setSelected(true);
    
    long sampleNum = (this->maxLength / (this->maxLength * zoom)) * markerPosition * sampleRate;
    region->setSampleOffset(sampleNum);
    
    region->setSampleOffset(sampleNum);
    region->setOffset(markerPosition);
    
	repaint();
}

void Track::setZoom(float zoom)
{
    this->zoom = zoom;
    
    Logger::getCurrentLogger()->writeToLog(String(zoom));
    
    for (std::vector<AudioRegion*>::iterator it = regions.begin(); it != regions.end(); ++it) {
        (*it)->setZoom(zoom);
    }
    
}

String Track::getName()
{
	return name;
}

void Track::setGain(float gain)
{
	this->gain = gain;
}

void Track::setVolume(float volume)
{
	this->volume = volume;
}

float Track::getVolume()
{
	return volume;
}

AudioRegion* Track::getCurrentRegion(long sample) {
    
    AudioRegion* current = NULL;
    
    for (std::vector<AudioRegion*>::iterator it = regions.begin(); it != regions.end(); ++it) {
        
        AudioRegion* r = *it;
        
        long len = r->getBuffer()->getNumSamples();
        long offset = r->getSampleOffset();
        
        if (sample >= offset && sample < (offset + len)) {
            current = r;
            break;
        }
        
    }
    
    return current;
    
}

const float Track::getSample(int channel, long sample) {
    

    this->currentRegion = getCurrentRegion(sample);
    
    if (this->currentRegion != NULL) {
        long offset = currentRegion->getSampleOffset();
        return this->currentRegion->getBuffer()->getReadPointer(channel)[(long)sample - offset];
    }
    else {
        return 0;
    }

}

const float * Track::getReadBuffer(int channel)
{
	return this->currentRegion->getBuffer()->getReadPointer(channel);
}

int Track::getNumSamples()
{
	return numSamples;
}

void Track::setSelected(bool selected)
{
	this->selected = selected;
}

bool Track::isSelected()
{
	return selected;
}

double Track::getMaxLength()
{
	return maxLength;
}

void Track::paint (Graphics& g)
{
	if (selected) {
		g.setColour(Colours::lightgrey.brighter());
	}
	else {
		g.setColour(Colours::lightgrey);
	}
	
    g.fillAll();
     
}

void Track::resized()
{
    for (std::vector<AudioRegion*>::iterator it = regions.begin(); it != regions.end(); ++it) {
        (*it)->setSize((*it)->getWidth(), getHeight());
        (*it)->setZoom(zoom);
    }
}

void Track::setOffset(int offset)
{
	this->offset = offset;
}

int Track::getOffset()
{
	return this->offset;
}

AudioSampleBuffer * Track::getBuffer()
{
	return this->currentRegion->getBuffer();
}

void Track::setCurrentMarkerPosition(int position) {
    this->markerPosition = position;
}
