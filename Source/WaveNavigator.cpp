/*
  ==============================================================================

    WaveNavigator.cpp
    Created: 24 Nov 2016 8:04:54am
    Author:  Matthias Pueski

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "WaveNavigator.h"
#include <iterator>

//==============================================================================
WaveNavigator::WaveNavigator(PositionMarker* marker)
{

    this->selector = new WaveSelector();
    this->selector->addChangeListener(this);
    this->selector->setSize(getWidth(), getHeight());
    this->selector->setBounds(0, 0, getWidth(), getHeight());
    this->mixerSource = new MixerAudioSource();
    addAndMakeVisible(selector);
    this->zoom = 20;
    this->marker = marker;
}

WaveNavigator::~WaveNavigator()
{
    selector = nullptr;
    mixerSource = nullptr;
    
    for(std::vector<Track*>::iterator it = tracks.begin(); it != tracks.end(); ++it) {
        // *it = nullptr;;
        delete *it;
    }
    
}

void WaveNavigator::paint (Graphics& g)
{

    g.fillAll (Colours::skyblue);
    
    
    for(int i = 0; i < tracks.size();i++) {
        tracks.at(i)->paint(g);
    }
    
}

void WaveNavigator::setZoom(float zoom) {
    this->zoom = zoom;
    for(int i = 0; i < tracks.size();i++) {
        tracks.at(i)->setZoom(zoom);
    }
}

double WaveNavigator::getPosition() {
    
    if (tracks.size() > 0) {
        position = tracks.at(0)->getSource()->getCurrentPosition();
    }
    
    return position;
}

void WaveNavigator::setPosition(double position) {
    for (int i = 0; i < tracks.size();i++) {
        tracks.at(i)->getSource()->setPosition(position);
    }
    this->position = position;
}

double WaveNavigator::getMaxLength() {
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

void WaveNavigator::setPlaying(bool playing) {
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

MixerAudioSource* WaveNavigator::getMixerSource() {
    return this->mixerSource.get();
}

bool WaveNavigator::isPlaying() {
    return playing;
}

std::vector<Track*> WaveNavigator::getTracks() {
    return this->tracks;
}

void WaveNavigator::addTrack(File file, TimeSliceThread* thread) {
    
    Track* track = new Track(file, thread);
    Rectangle<int>* bounds = new Rectangle<int>(0,tracks.size() * 200,track->getThumbnail()->getTotalLength() * 20,200);
    track->setThumbnailBounds(bounds);
    if (zoom > 0)
        track->setZoom(zoom);
    this->tracks.push_back(track);
    this->currentTrack = track;
    this->selector->setSize(getWidth(), getHeight() / tracks.size());
    this->selector->setBounds(0, 0, getWidth(), getHeight() / tracks.size());
    this->mixerSource->addInputSource(track->getSource(), true);
    repaint();
    track->repaint();
}

void WaveNavigator::resized()
{
    int numOfTracks = tracks.size();
    
    if (numOfTracks == 0) {
        numOfTracks = 1;
    }
    
    this->selector->setSize(getWidth(), getHeight() / numOfTracks);
    this->selector->setBounds(0, 0, getWidth(), getHeight() / numOfTracks);

}

AudioThumbnail* WaveNavigator::getThumbnail() {
    return this->currentTrack->getThumbnail();
}

WaveSelector* WaveNavigator::getSelector() {
    return this->selector.get();
}

void WaveNavigator::changeListenerCallback(ChangeBroadcaster * source) 
{
    if (source == this->currentTrack->getThumbnail()) {
        repaint();
    }
    if (source == selector) {
        Rectangle<int> range = selector->getSelectedRange();
    }

}

bool WaveNavigator::keyPressed(const KeyPress& key,
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
        sendChangeMessage();
    }
    else if (key.getTextCharacter() == '-') {
        if (getMaxLength() == 0) {
            return false;
        }
        this->zoom -= 10;
        setSize(getMaxLength() * this->zoom, getHeight());
        setZoom(zoom);
        sendChangeMessage();
    }
    
    return true;
}

void WaveNavigator::mouseDrag(const MouseEvent& event) {
    if (getThumbnail()->getNumChannels() && event.mods.isLeftButtonDown()) {
        getSelector()->setSelectedRange(event.getMouseDownPosition().getX(), event.getOffsetFromDragStart().getX());
    }
}

void WaveNavigator::mouseDown (const MouseEvent& event) {
    
    
    int x = event.x;
    
    
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