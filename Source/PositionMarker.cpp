/*
  ==============================================================================

    PositionMarker.cpp
    Created: 24 Nov 2016 11:00:23am
    Author:  Matthias Pueski

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "PositionMarker.h"
#include "MainComponent.cpp"

//==============================================================================
PositionMarker::PositionMarker(double lengthInSeconds)
{
    this->length = lengthInSeconds;
    // startTimer(100);
	this->audioPosition = 0;
	this->drawPosition = 0;
    setInterceptsMouseClicks(false, false);
}

PositionMarker::~PositionMarker()
{
}

void PositionMarker::paint (Graphics& g)
{
	if (length > 0) {
		this->drawPosition = (audioPosition / length) * this->width + this->x;
	}
        
    g.setColour(Colours::green);    
    g.drawLine(this->drawPosition, this->y, this->drawPosition, this->height, 2.0f);
}

void PositionMarker::resized()
{
}

void PositionMarker::setPlaying(bool playing) {
    this->playing = playing;
}

void PositionMarker::setLength(double lengthInSeconds) {
    this->length = lengthInSeconds;
    repaint();
}

void PositionMarker::setPosition(double position) {
	if (position < 0) {
		position = 0;
	}

    this->audioPosition = position;
    repaint();
}

double PositionMarker::getDrawPosition() {
    this->drawPosition = (audioPosition / length) * this->width + this->x;
    return drawPosition;
}

double PositionMarker::getPosition() {
    return audioPosition;
}

void PositionMarker::timerCallback() {
    if (length > 0 && playing) {
        repaint();
    }
}

void PositionMarker::setDrawingBounds(int x, int y, int width, int height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void PositionMarker::changeListenerCallback(ChangeBroadcaster * source)
{
    repaint();
}