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
#include "Project.h"
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
    this->zoom = 40;
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
    constrainer.setRaster(this->zoom / 4);
    constrainer.setMaxX(getMaxLength() * this->zoom);
}

void TrackNavigator::updateTrackLayout(ChangeBroadcaster * source)
{
	int index = -1;

	for (int i = 0; i < tracks.size();i++) {
		if (source == tracks.at(i) && i < tracks.size() - 1) {
			index = i;
			break;
		}
	}

	if (index >= 0 && tracks.size() > index + 1) {

		for (int i = index + 1; i < tracks.size();i++) {
			tracks.at(i)->setTopLeftPosition(tracks.at(i - 1)->getX(), tracks.at(i - 1)->getPosition().getY() + tracks.at(i - 1)->getHeight());
		}

	
	}

	adjustHeight();
	sendChangeMessage();
}

void TrackNavigator::adjustHeight()
{
	int height = 0;

	for (int i = 0; i < tracks.size();i++) {
		height += tracks.at(i)->getHeight();
	}

	if (getHeight() != height) {
		setSize(getWidth(), height);
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
	
	track->addChangeListener(this);
    // track->setTopLeftPosition(0, 200 * tracks.size());

	if (zoom > 0)
        track->setZoom(zoom);

    for (int i = 0; i < tracks.size();i++) {
        tracks.at(i)->setSelected(false);
    }
    track->setSelected(true);
    
    track->setMidiChannel(tracks.size() % 16);

	int yPos = 0;

	for (int i = 0; i < this->tracks.size();i++) {
		yPos += tracks.at(i)->getHeight();
	}

    this->tracks.push_back(track);
    this->currentTrack = track;
    // track->toFront(true);
    this->selector->toFront(false);
    
    Project* p = Project::getInstance();
    
	// int height = this->getParentComponent()->getHeight();
    setBounds(getX(), getY(), getMaxLength() * this->zoom, tracks.size() * 200);
    track->setBounds(0, yPos, p->getTrackLength() * this->zoom, 200);

	this->marker->setSize(2, getHeight());
	this->marker->setLength(getMaxLength());
    this->selector->setSize(getWidth(), getHeight());
    
    constrainer.setRaster(this->zoom / 4);
    constrainer.setMaxX(getMaxLength() * this->zoom);
    
    // repaint();
	sendChangeMessage();    
}

void TrackNavigator::removeSelectedTrack()
{
	for (std::vector<Track*>::iterator it = tracks.begin(); it != tracks.end();) {
		if ((*it)->isSelected()) {
			delete * it;
			it = tracks.erase(it);

			break;
		}
		else {
			++it;
		}
	}

	if (tracks.size() > 0) {

		tracks.at(0)->setTopLeftPosition(tracks.at(0)->getX(), 0);

		for (int i = 1; i < tracks.size();i++) {
			tracks.at(i)->setTopLeftPosition(tracks.at(i - 1)->getX(), tracks.at(i - 1)->getHeight() + tracks.at(i - 1)->getY());
		}

	}

	adjustHeight();
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
    
	this->marker->setSize(2, getHeight());
	this->marker->setDrawingBounds(0, 25, getWidth(), getHeight());
}

WaveSelector* TrackNavigator::getSelector() {
    return this->selector.get();
}

void TrackNavigator::changeListenerCallback(ChangeBroadcaster * source) 
{
	updateTrackLayout(source);

	/*
    if (source == selector) {
        Rectangle<int> range = selector->getSelectedRange();
    }
	*/

}

bool TrackNavigator::keyPressed(const KeyPress& key, Component* originatingComponent) {



    if (key == KeyPress::spaceKey) {
        if (isPlaying())
        {
            setPlaying(false);
        }
        else
        {
            setPlaying(true);
        }
        
    }
    else if (key.getTextCharacter() == '+') {
        if (getMaxLength() == 0) {
            return false;
        }
        this->zoom += 20;
		setSize(getMaxLength() * this->zoom, getHeight());
        setZoom(zoom);
		repaint();
        sendChangeMessage();
    }
    else if (key.getTextCharacter() == '-') {
        if (getMaxLength() == 0) {
            return false;
        }
        this->zoom -= 20;
        setSize(getMaxLength() * this->zoom, getHeight());
        setZoom(zoom);
		repaint();
        sendChangeMessage();
    }
    else if (key.getTextCharacter() == 'l') {
        for (int i = 0; i < tracks.size();i++) {
            tracks.at(i)->toggleLoopSelection();
        }
    }
    else if (key.getTextCharacter() == 'd') {
        for (int i = 0; i < tracks.size();i++) {
            tracks.at(i)->duplicateSelectedRegions();
        }
    }
    else if (key.getTextCharacter() == 'x') {
        for (int i = 0; i < tracks.size();i++) {
            tracks.at(i)->removeSelectedRegions(true);
        }
    }
    else if (key.getTextCharacter() == 't') {
        for (int i = 0; i < tracks.size();i++) {
            tracks.at(i)->splitRegion();
        }
    }
    
    return true;
}

void TrackNavigator::mouseUp (const MouseEvent& event) {
    if (AudioRegion* r = dynamic_cast<AudioRegion*>(event.eventComponent)){

        long tracklen = Project::getInstance()->getTrackLength();
        double sampleRate = Project::getInstance()->getSampleRate();
        
        
        int offset = r->getOffset();
        int dynSampleOffset = r->getDynOffset() / zoom * sampleRate;

        if (r->getSampleOffset() + r->getBuffer()->getNumSamples() + dynSampleOffset >= tracklen * sampleRate) {
            
            r->setSampleOffset(tracklen * sampleRate - r->getBuffer()->getNumSamples(), false, false);
            r->setDynOffset(0);
            return;
        }
        
        
        if (offset >= 0) {
        
            long sampleNum = (tracklen / (tracklen * zoom)) * offset * r->getSampleRate();
            if (sampleNum != r->getSampleOffset()) {
                r->setSampleOffset(sampleNum, true, true);
            }
            
            r->setDynOffset(0);
            r->setOffset(offset);
        
        }
        


    }
}

void TrackNavigator::mouseDrag(const MouseEvent& event) {
    
    if (AudioRegion* r = dynamic_cast<AudioRegion*>(event.eventComponent)){
        dragger.dragComponent(r, event,&constrainer);
        r->setDynOffset(constrainer.snap(event.getDistanceFromDragStartX(),zoom / 4));
        r->repaint();
        repaint();
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
        marker->setPosition(position);
        for (int i = 0; i < tracks.size();i++) {
            tracks.at(i)->setCurrentMarkerPosition(marker->getDrawPosition());
        }
        sendChangeMessage();
    }
    
    if (AudioRegion* r = dynamic_cast<AudioRegion*>(event.eventComponent)){
        for (int i = 0; i < tracks.size();i++) {
            tracks.at(i)->clearSelection();
        }
        r->setSelected(true);
        dragger.startDraggingComponent(r, event);
    }
    else if (Track* r = dynamic_cast<Track*>(event.eventComponent)) {
        for (int i = 0; i < tracks.size();i++) {
            tracks.at(i)->setSelected(false);
            tracks.at(i)->clearSelection();
        }

        r->setSelected(true);
        currentTrack = r;
        sendChangeMessage();
        repaint();
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