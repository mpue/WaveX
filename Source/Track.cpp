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

void Track::addRegion(File file, double sampleRate) {

	AudioRegion* region = new AudioRegion(file, manager, sampleRate);
	Rectangle<int>* bounds = new Rectangle<int>(0, 0, region->getThumbnail()->getTotalLength() * 20, 200);
	region->setThumbnailBounds(bounds);
    region->setLoopCount(3);
	if (zoom > 0)
		region->setZoom(zoom);

	this->regions.push_back(region);
	this->currentRegion = region;

    this->currentRegion->toFront(true);
    addAndMakeVisible(region);
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

const float Track::getSample(int channel, long sample) {
    
    for (std::vector<AudioRegion*>::iterator it = regions.begin(); it != regions.end(); ++it) {
        AudioRegion* r = *it;
        
        long len = r->getBuffer()->getNumSamples();
        
        if (r->isLoop()) {
            if (sample % len >= r->getSampleOffset() && sample % len < (r->getSampleOffset() + r->getBuffer()->getNumSamples())) {
                currentRegion = r;
                break;
            }
        }
        else {
            if (sample >= r->getSampleOffset() && sample < (r->getSampleOffset() + r->getBuffer()->getNumSamples())) {
                currentRegion = r;
                break;
            }
        }
    }
    
    long len = currentRegion->getBuffer()->getNumSamples();
    
    // sample index is not within sample range of current region
    if (currentRegion->isLoop()) {
        if (sample % len < currentRegion->getSampleOffset() || sample % len >= (currentRegion->getSampleOffset() + currentRegion->getBuffer()->getNumSamples())) {
            return 0;
        }
    }
    else {
        if (sample < currentRegion->getSampleOffset() || sample >= (currentRegion->getSampleOffset() + currentRegion->getBuffer()->getNumSamples())) {
            return 0;
        }
    }

    
    // Logger::getCurrentLogger()->writeToLog(String(sample - currentRegion->getSampleOffset()));
    
    // cout << "Sample : " << sample << " offset : " << currentRegion->getSampleOffset() << " numSamples " << currentRegion->getBuffer()->getNumSamples() << endl;
    
    
    return this->currentRegion->getBuffer()->getReadPointer(channel)[(long)(sample % len - currentRegion->getSampleOffset())];
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
    
    /*
	for (int i = 0; i < regions.size();i++) {
        if (regions.at(i)->isLoop()) {
            regions.at(i)->paint(g);
        }
		
	}
     */
    
}

void Track::resized()
{

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
