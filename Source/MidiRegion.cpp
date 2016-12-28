/*
  ==============================================================================

    MidiRegion.cpp
    Created: 28 Dec 2016 6:55:16pm
    Author:  Matthias Pueski

  ==============================================================================
*/

#include "MidiRegion.h"

MidiRegion::MidiRegion(long startSample, long sampleLength, double sampleRate) {
    this->midiBuffer = new MidiBuffer();
    this->midiThumbnail = new MidiThumbnail(sampleRate);
    this->sampleRate = sampleRate;
    this->sampleOffset = startSample;
    this->name = "new";
    this->zoom = 20;
    double length = this->midiThumbnail->getTotalLength();
    setSize(length * this->zoom, Project::DEFAULT_TRACK_HEIGHT);
    this->offset = 0;
}

MidiRegion::~MidiRegion() {
    delete midiThumbnail;
    delete midiBuffer;
}

void MidiRegion::paint (Graphics& g) {
    
    Rectangle<int> b = *this->thumbnailBounds;
    
    if (dragger->isSelected(this)) {
        g.setColour(Colours::steelblue.brighter());
    }
    else {
        g.setColour(Colours::steelblue);
    }
    
    g.fillRoundedRectangle(b.getX(),b.getY(),b.getWidth(),b.getHeight(),10);
    g.setColour(Colours::lightgrey);
    
    const double audioLength(this->midiThumbnail->getTotalLength());
    this->midiThumbnail->drawChannels(g, b, 0.0, audioLength, 1.0f);
    
    g.setColour(Colours::steelblue.darker());
    g.drawRoundedRectangle(b.getX(),b.getY(),b.getWidth(),b.getHeight(),10,1.0f);
    
    g.setColour(Colours::darkblue);
    g.setFont(14.0);
    g.drawText(name, 10, 10, 140, 20, juce::Justification::left);
    
    if(loop) {
        for (int i = 1; i <= loopCount;i++) {
            g.setColour(Colours::steelblue);
            Rectangle<int> loopBounds(b.getX() + i * getWidth() / (loopCount + 1),b.getY(),b.getWidth(),b.getHeight());
            g.fillRoundedRectangle(b.getX() + i * getWidth() / (loopCount + 1) ,b.getY(),b.getWidth(),b.getHeight(),10);
            g.setColour(Colours::grey);
            
            const double audioLength(this->midiThumbnail->getTotalLength());
            this->midiThumbnail->drawChannels(g, loopBounds,0.0,audioLength, 1.0f);
        }
    }
}

void MidiRegion::resized() {
    if (this->thumbnailBounds != NULL)
        this->thumbnailBounds->setHeight(getHeight());
}

void MidiRegion::setThumbnailBounds(Rectangle<int>* bounds) {
    this->thumbnailBounds = bounds;
}

void MidiRegion::setNumSamples(int numSamples) {
    this->numSamples = numSamples;
}

int MidiRegion::getNumSamples() {
    return numSamples;;
}

MidiBuffer* MidiRegion::getBuffer() {
    return midiBuffer;
}

MidiThumbnail* MidiRegion::getThumbnail() {
    return midiThumbnail;
}

void MidiRegion::setZoom(float zoom) {
    this->zoom = zoom;
    
    if (loop) {
        setSize(this->midiThumbnail->getTotalLength() * (loopCount + 1) * this->zoom, getHeight());
    }
    else {
        setSize(this->midiThumbnail->getTotalLength() * this->zoom, getHeight());
    }
    
    int newOffset = (this->sampleOffset / this->sampleRate) * zoom;
    this->setOffset(newOffset);
    
    this->setTopLeftPosition(newOffset, 0);
    
    /*
     resizerR->setSize(5, getHeight());
     resizerR->setTopLeftPosition(getWidth() - 5, 0);
     
     resizerL->setSize(5, getHeight());
     resizerL->setTopLeftPosition(0, 0);
     */
    // setBounds(0,0,this->thumbnail->getTotalLength() * this->zoom, 200);
    this->thumbnailBounds->setSize(this->midiThumbnail->getTotalLength() * this->zoom, getHeight());
    
    dragger->setRaster(this->zoom / 4);
    
    repaint();
}

void MidiRegion::setLoop(bool loop) {
    if (loop) {
        setSize(this->midiThumbnail->getTotalLength() * (loopCount + 1) * this->zoom, getHeight());
    }
    else {
        setSize(this->midiThumbnail->getTotalLength() * this->zoom, getHeight());
    }
    
    this->loop = loop;
    repaint();
}

// the timer is needed to updat the thumbnail during record
void MidiRegion::timerCallback() {
    updateThumb();
}

void MidiRegion::startRecording() {
    startTimer(100);
}

void MidiRegion::stopRecording() {

    stopTimer();    
    MidiMessage message;
    int sampleNumber;
    
    if (iterator == NULL) {
        iterator = new MidiBuffer::Iterator(*midiBuffer);
    }
    
    while(iterator->getNextEvent(message, sampleNumber)) {
        
        MidiMessage* m = new MidiMessage(message);
        
        m->setTimeStamp(dragger->snap(m->getTimeStamp(),512));
        
        if (m->getRawDataSize() > 0)
            midiMessages.insert(std::make_pair(sampleNumber,m ));        
        
    }

}

void MidiRegion::setDragger(MultiComponentDragger* dragger) {
    this->dragger = dragger;
}

void MidiRegion::updateThumb() {
    double length = this->midiThumbnail->getTotalLength();
    setSize(length * this->zoom, getHeight());
    this->thumbnailBounds->setWidth(length * this->zoom);
    repaint();
}

void MidiRegion::componentMovedOrResized (Component& component,bool wasMoved, bool wasResized) {
    if (wasMoved) {
        long tracklen = Project::getInstance()->getTrackLength();
        double sampleRate = Project::getInstance()->getSampleRate();
        
        long sampleNum = (tracklen / (tracklen * zoom)) * getBounds().getX() * getSampleRate();
        if (sampleNum != getSampleOffset()) {
            setSampleOffset(sampleNum, true, true);
        }
        
        if (getSampleOffset() >= tracklen * sampleRate) {
            
            setSampleOffset(tracklen * sampleRate - numSamples, false, false);
        }
        
        Logger::getCurrentLogger()->writeToLog("MidiRegion sampleOffset " + String(sampleOffset));
    }
}

void MidiRegion::changeListenerCallback(ChangeBroadcaster * source) {
    
}

void MidiRegion::clear() {
    midiMessages.clear();
    midiBuffer->clear();
}

void MidiRegion::addMessage(int sampleNum, MidiMessage* m) {
    midiMessages.insert(std::make_pair(sampleNum,m));
    numSamples = sampleNum;
    this->midiThumbnail->addMessage(sampleNum,m);
}

MidiMessage* MidiRegion::getMessage(int sampleNum) {
    std::map<int,MidiMessage*>::iterator it;
    it = midiMessages.find(sampleNum);
    if (it != midiMessages.end()) {
        return it->second;
    }
    return NULL;
}
