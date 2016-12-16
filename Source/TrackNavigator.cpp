/*
  ==============================================================================

    WaveNavigator.cpp
    Created: 24 Nov 2016 8:04:54am
    Author:  Matthias Pueski

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "TrackNavigator.h"
#include "AudioRegion.h"
#include <iterator>
#include <iostream>

using namespace std;

//==============================================================================
TrackNavigator::TrackNavigator(PositionMarker* marker)
{
    this->selector = new WaveSelector();
    this->selector->addChangeListener(this);
    this->selector->setSize(getWidth(), getHeight());
    this->selector->setBounds(0, 0, getWidth(), getHeight());
    addAndMakeVisible(selector);
    this->zoom = 50;
    this->marker = marker;
	this->position = 0;
	manager.registerBasicFormats();
    
    
    // setInterceptsMouseClicks(true, true);
}

TrackNavigator::~TrackNavigator()
{
    selector = nullptr;
    
    for(std::vector<Track*>::iterator it = tracks.begin(); it != tracks.end(); ++it) {
        delete *it;
    }
    
}

void TrackNavigator::paint (Graphics& g)
{

    g.fillAll (Colours::lightsalmon);
    /*
    for(int i = 0; i < tracks.size();i++) {		
        tracks.at(i)->paint(g);
    }
     */
    
}

float TrackNavigator::getZoom()
{
	return this->zoom;
}

void TrackNavigator::setZoom(float zoom) {
    this->zoom = zoom;
    for(int i = 0; i < tracks.size();i++) {
        tracks.at(i)->setZoom(zoom);
    }	
}

double TrackNavigator::getPosition() {
    return position;
}

void TrackNavigator::setPosition(double position) {
    this->position = position;
}

double TrackNavigator::getMaxLength() {
    double maxlen = 0;
    
    for (int i = 0; i < tracks.size();i++) {

        double len = tracks.at(i)->getMaxLength();
        
        if (len > maxlen) {
            maxlen = len;
        }
    }

    return maxlen;
}

void TrackNavigator::setPlaying(bool playing) {
    this->playing = playing;
}

bool TrackNavigator::isPlaying() {
    return playing;
}

std::vector<Track*> TrackNavigator::getTracks() {
    return this->tracks;
}

void TrackNavigator::addTrack(double sampleRate) {
    
	Track* track = new Track(sampleRate);
    addAndMakeVisible(track);
	
    // track->setTopLeftPosition(0, 200 * tracks.size());

	if (zoom > 0)
        track->setZoom(zoom);

    this->tracks.push_back(track);
    this->currentTrack = track;
    track->toFront(true);
    
    
	// int height = this->getParentComponent()->getHeight();
    setSize(getMaxLength() * this->zoom, tracks.size() * 200);
    track->setBounds(0, (tracks.size() - 1)  * 200, 600 * this->zoom, 200);
	this->marker->setSize(getWidth(), getHeight());
	this->marker->setLength(getMaxLength());
    this->selector->setSize(getWidth(), 200);
    
    repaint();
	sendChangeMessage();    
}

Track * TrackNavigator::getCurrentTrack()
{
	return this->currentTrack;
}

void TrackNavigator::resized()
{
    int numOfTracks = tracks.size();
    
    if (numOfTracks == 0) {
        numOfTracks = 1;
    }
    
	this->marker->setSize(getWidth(), getHeight());
	this->marker->setDrawingBounds(0, 25, getWidth(), getHeight());
}

WaveSelector* TrackNavigator::getSelector() {
    return this->selector.get();
}

void TrackNavigator::changeListenerCallback(ChangeBroadcaster * source) 
{

    if (source == selector) {
        Rectangle<int> range = selector->getSelectedRange();
    }

}

bool TrackNavigator::keyPressed(const KeyPress& key, Component* originatingComponent) {
    if (key == KeyPress::spaceKey) {
        if (isPlaying())
        {
            setPlaying(false);
            marker->setPlaying(false);
        }
        else
        {
            setPlaying(true);
            marker->setPlaying(true);
        }
        
    }
    else if (key.getTextCharacter() == '+') {
        if (getMaxLength() == 0) {
            return false;
        }
        this->zoom += 10;
		setSize(getMaxLength() * this->zoom, getHeight());
        setZoom(zoom);
		repaint();
        sendChangeMessage();
    }
    else if (key.getTextCharacter() == '-') {
        if (getMaxLength() == 0) {
            return false;
        }
        this->zoom -= 10;
        setSize(getMaxLength() * this->zoom, getHeight());
        setZoom(zoom);
		repaint();
        sendChangeMessage();
    }
    
    return true;
}

void TrackNavigator::mouseDrag(const MouseEvent& event) {
    
    if (AudioRegion* r = dynamic_cast<AudioRegion*>(event.eventComponent)){
        dragger.dragComponent(r, event,&constrainer);
    }
    else {
        if (event.mods.isLeftButtonDown()) {
            getSelector()->setSelectedRange(event.getMouseDownPosition().getX(), event.getOffsetFromDragStart().getX());
        }
    }

}

void TrackNavigator::mouseDown (const MouseEvent& event) {

    int x = event.x;
    int y = event.y;
    
    if (!event.mods.isCtrlDown() && event.mods.isRightButtonDown()) {
        float pos = (float)x / getWidth();
        double total = getMaxLength();
        double relative = total * pos;
        setPosition(relative);
        sendChangeMessage();
    }
    
    if (AudioRegion* r = dynamic_cast<AudioRegion*>(event.eventComponent)){
        dragger.startDraggingComponent(r, event);
    }
    else if (Track* r = dynamic_cast<Track*>(event.eventComponent)) {
        for (int i = 0; i < tracks.size();i++) {
            tracks.at(i)->setSelected(false);
        }
        r->setSelected(true);
        currentTrack = r;
        sendChangeMessage();
    }
    else {

        
        if (tracks.size() > 0) {

            
            if (event.mods.isLeftButtonDown()) {
                for (int i = 0; i < tracks.size();i++) {
                    
                    Rectangle<int> bounds =  tracks.at(i)->getBounds();
                    bounds.setY(i * 200);
                    
                    if (bounds.contains(x, y)) {
                        currentTrack = tracks.at(i);
                        Rectangle<int> selectorBounds = this->selector->getBounds();
                        selectorBounds.setY(i * 200);
                        this->selector->setBounds(selectorBounds);
                        this->selector->setSelectedRange(0, 0);
                        tracks.at(i)->setSelected(true);						
                        sendChangeMessage();
                    }
                    else {
                        tracks.at(i)->setSelected(false);
                        sendChangeMessage();
                    }
                    
                }
            }
            
        }
    }
    
    
    
}