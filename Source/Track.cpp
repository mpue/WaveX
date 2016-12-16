/*
  ==============================================================================

    Track.cpp
    Created: 16 Dec 2016 9:40:38am
    Author:  pueskma

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Track.h"

//==============================================================================
Track::Track(double sampleRate)
{
	manager.registerBasicFormats();
	this->sampleRate = sampleRate;
	this->audioBuffer = new AudioSampleBuffer();
	this->maxLength = 600;
	this->name = "empty Track";
}

Track::~Track()
{
	for (std::vector<AudioRegion*>::iterator it = regions.begin(); it != regions.end(); ++it) {
		delete *it;
	}

	delete this->audioBuffer;
}

void Track::addRegion(File file, double sampleRate) {

	AudioRegion* region = new AudioRegion(file, manager, sampleRate);
	Rectangle<int>* bounds = new Rectangle<int>(0, 0, region->getThumbnail()->getTotalLength() * 20, 200);
	region->setThumbnailBounds(bounds);
	if (zoom > 0)
		region->setZoom(zoom);

	this->regions.push_back(region);
	this->currentRegion = region;


	repaint();
}

void Track::setZoom(float zoom)
{
	this->zoom = zoom;
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

const float * Track::getReadBuffer(int channel)
{
	


	return nullptr;
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
	
	g.fillRect(getBounds().getX(),getBounds().getY(),getBounds().getWidth(),getBounds().getHeight()-1);

	for (int i = 0; i < regions.size();i++) {
		regions.at(i)->paint(g);	
	}
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
	return audioBuffer;
}
