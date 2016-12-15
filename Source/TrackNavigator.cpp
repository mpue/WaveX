/*
  ==============================================================================

    WaveNavigator.cpp
    Created: 24 Nov 2016 8:04:54am
    Author:  Matthias Pueski

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "TrackNavigator.h"
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
    this->mixerSource = new MixerAudioSource();
    addAndMakeVisible(selector);
    this->zoom = 50;
    this->marker = marker;
}

TrackNavigator::~TrackNavigator()
{
    selector = nullptr;
    mixerSource = nullptr;
    
    for(std::vector<Track*>::iterator it = tracks.begin(); it != tracks.end(); ++it) {
        // *it = nullptr;;
        delete *it;
    }
    
}

void TrackNavigator::paint (Graphics& g)
{

    g.fillAll (Colours::darkgrey);
    
    
    for(int i = 0; i < tracks.size();i++) {
        tracks.at(i)->paint(g);
    }
    
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
    
    if (tracks.size() > 0) {
        position = tracks.at(0)->getSource()->getCurrentPosition();
    }
    
    return position;
}

void TrackNavigator::setPosition(double position) {
    for (int i = 0; i < tracks.size();i++) {
        tracks.at(i)->getSource()->setPosition(position);
    }
    this->position = position;
}

double TrackNavigator::getMaxLength() {
    double maxlen = 0;
    
    for (int i = 0; i < tracks.size();i++) {
        
        AudioTransportSource* source = tracks.at(i)->getSource();        
        double len = source->getLengthInSeconds();

        if (len > maxlen) {
            maxlen = len;
        }
    }

    return maxlen;
}

void TrackNavigator::setPlaying(bool playing) {
    this->playing = playing;
    
    for (int i = 0; i < tracks.size();i++) {
        if (playing) {
            tracks.at(i)->getSource()->start();
        }
        else {
            tracks.at(i)->getSource()->stop();
        }
    }
}

MixerAudioSource* TrackNavigator::getMixerSource() {
    return this->mixerSource.get();
}

bool TrackNavigator::isPlaying() {
    return playing;
}

std::vector<Track*> TrackNavigator::getTracks() {
    return this->tracks;
}

void TrackNavigator::addTrack(File file, TimeSliceThread* thread) {
    
    Track* track = new Track(file, thread);
    Rectangle<int>* bounds = new Rectangle<int>(0,tracks.size() * 200,track->getThumbnail()->getTotalLength() * 20,200);
    track->setThumbnailBounds(bounds);
    if (zoom > 0)
        track->setZoom(zoom);

    this->tracks.push_back(track);
    this->currentTrack = track;

	int height = this->getParentComponent()->getHeight();
	setSize(getMaxLength() * this->zoom, height);
	this->marker->setSize(getWidth(), getHeight());
	this->marker->setLength(getMaxLength());
    this->selector->setSize(getWidth(), getHeight() / tracks.size());
    this->selector->setBounds(0, 0, getWidth(), getHeight() / tracks.size());
    this->mixerSource->addInputSource(track->getSource(), true);
    repaint();
	sendChangeMessage();    
}

void TrackNavigator::resized()
{
    int numOfTracks = tracks.size();
    
    if (numOfTracks == 0) {
        numOfTracks = 1;
    }
    
    this->selector->setSize(getWidth(), getHeight() / numOfTracks);
    this->selector->setBounds(0, 0, getWidth(), getHeight() / numOfTracks);
	this->marker->setSize(getWidth(), getHeight());
	this->marker->setDrawingBounds(0, 25, getWidth(), getHeight());
}

AudioThumbnail* TrackNavigator::getThumbnail() {
    return this->currentTrack->getThumbnail();
}

WaveSelector* TrackNavigator::getSelector() {
    return this->selector.get();
}

void TrackNavigator::changeListenerCallback(ChangeBroadcaster * source) 
{
    if (source == this->currentTrack->getThumbnail()) {
        repaint();
    }
    if (source == selector) {
        Rectangle<int> range = selector->getSelectedRange();
    }

}

bool TrackNavigator::keyPressed(const KeyPress& key,
                        Component* originatingComponent) {
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
    if (getThumbnail()->getNumChannels() && event.mods.isLeftButtonDown()) {
        getSelector()->setSelectedRange(event.getMouseDownPosition().getX(), event.getOffsetFromDragStart().getX());
    }
}

void TrackNavigator::mouseDown (const MouseEvent& event) {
    
    
    int x = event.x;

	if (tracks.size() > 0) {
		if (getThumbnail()->getNumChannels()) {
        
			if (!event.mods.isCtrlDown() && event.mods.isRightButtonDown()) {
				float pos = (float)x / getWidth();
				double total = getMaxLength();
				double relative = total * pos;
				setPosition(relative);
				sendChangeMessage();
			}
        
		}
	}
    
}