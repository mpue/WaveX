/*
  ==============================================================================

    Track.cpp
    Created: 25 Nov 2016 10:00:36pm
    Author:  Matthias Pueski

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "AudioRegion.h"
#include "Project.h"

AudioRegion::AudioRegion(AudioRegion* other, AudioFormatManager& manager, double sampleRate, long startSample, long numSamples) {

    this->sampleRate = sampleRate;
    
    this->thumbnailCache = new AudioThumbnailCache(1);
    this->thumbnail = new AudioThumbnail(512, manager, *this->thumbnailCache);
    this->thumbnail->addChangeListener(this);
    
    audioBuffer = new AudioSampleBuffer(2, numSamples);
    audioBuffer->copyFrom(0, 0, *other->getBuffer(), 0, startSample, numSamples);
    audioBuffer->copyFrom(1, 0, *other->getBuffer(), 1, startSample, numSamples);
    
    this->thumbnail->reset(2, sampleRate);
    this->thumbnail->addBlock(0, *audioBuffer, 0,numSamples);
    
    this->name = other->getName();
    this->zoom = 20;
    
    double length = this->thumbnail->getTotalLength();
    setSize(length * this->zoom, other->getHeight());
    
    this->offset = 0;
    
    addComponentListener(this);
    
}


AudioRegion::AudioRegion(AudioSampleBuffer* source, AudioFormatManager& manager, long startSample, long sampleLength, double sampleRate) {
    
    // resizerR = new ResizableEdgeComponent(this,nullptr,ResizableEdgeComponent::rightEdge);
    // resizerL = new ResizableEdgeComponent(this,nullptr,ResizableEdgeComponent::leftEdge);
    
    this->sampleRate = sampleRate;
    
    this->thumbnailCache = new AudioThumbnailCache(1);
    this->thumbnail = new AudioThumbnail(512, manager, *this->thumbnailCache);
    this->thumbnail->addChangeListener(this);
    
    audioBuffer = new AudioSampleBuffer(2, sampleLength);
    audioBuffer->copyFrom(0, 0, *source, 0, 0, sampleLength);
    audioBuffer->copyFrom(1, 0, *source, 1, 0, sampleLength);
    
    this->thumbnail->reset(2, sampleRate);
    this->thumbnail->addBlock(0, *audioBuffer, 0, sampleLength);
    
    this->name = "new";
    this->zoom = 20;
    
    double length = this->thumbnail->getTotalLength();
    setSize(length * this->zoom, Project::DEFAULT_TRACK_HEIGHT);
    
    this->offset = 0;
    
    // addAndMakeVisible(resizerL);
    // addAndMakeVisible(resizerR);
    
    addComponentListener(this);
}

AudioRegion::AudioRegion(AudioRegion* other, AudioFormatManager& manager, double sampleRate) {
    
    // resizerR = new ResizableEdgeComponent(this,nullptr,ResizableEdgeComponent::rightEdge);
    // resizerL = new ResizableEdgeComponent(this,nullptr,ResizableEdgeComponent::leftEdge);
    
    this->sampleRate = sampleRate;
    
    this->thumbnailCache = new AudioThumbnailCache(1);
    this->thumbnail = new AudioThumbnail(512, manager, *this->thumbnailCache);
    this->thumbnail->addChangeListener(this);
    
    audioBuffer = new AudioSampleBuffer(2, other->getBuffer()->getNumSamples());
    audioBuffer->copyFrom(0, 0, *other->getBuffer(), 0, 0, other->getNumSamples());
    audioBuffer->copyFrom(1, 0, *other->getBuffer(), 1, 0, other->getNumSamples());
    
    this->thumbnail->reset(2, sampleRate);
    this->thumbnail->addBlock(0, *audioBuffer, 0,other->getNumSamples());
    
    this->name = other->getName();
    this->zoom = 20;
    
    double length = this->thumbnail->getTotalLength();
    setSize(length * this->zoom, other->getHeight());

    this->offset = 0;
    
    // addAndMakeVisible(resizerL);
    // addAndMakeVisible(resizerR);
   
    addComponentListener(this);
}

//==============================================================================
AudioRegion::AudioRegion(File file, AudioFormatManager& manager, double sampleRate)
{
    // resizerR = new ResizableEdgeComponent(this,nullptr,ResizableEdgeComponent::rightEdge);
    // resizerL = new ResizableEdgeComponent(this,nullptr,ResizableEdgeComponent::leftEdge);

	this->sampleRate = sampleRate;

    AudioFormatReader* reader = manager.createReaderFor(file);
    ScopedPointer<AudioFormatReaderSource> afr = new AudioFormatReaderSource(reader, true);

    this->thumbnailCache = new AudioThumbnailCache(1);
    this->thumbnail = new AudioThumbnail(512, manager, *this->thumbnailCache);
    this->thumbnail->addChangeListener(this);
    
    audioBuffer = new AudioSampleBuffer(2, reader->lengthInSamples);
    reader->read(audioBuffer, 0, reader->lengthInSamples, 0, true, true);

    this->thumbnail->reset(2, sampleRate);
    this->thumbnail->addBlock(0, *audioBuffer, 0,reader->lengthInSamples);
     
    this->name = file.getFileNameWithoutExtension();
    this->zoom = 20;
    setSize(this->thumbnail->getTotalLength() * this->zoom, Project::DEFAULT_TRACK_HEIGHT);

	this->offset = 0;
    
    addComponentListener(this);
    
    // addAndMakeVisible(resizerL);
    // addAndMakeVisible(resizerR);
}

AudioRegion::~AudioRegion()
{
    delete this->thumbnailCache;
    delete this->thumbnail;
    delete this->audioBuffer;
    // delete this->resizerL;
    // delete this->resizerR;
}

void AudioRegion::timerCallback() {
    updateThumb();
}

void AudioRegion::updateThumb()
{
    double length = this->thumbnail->getTotalLength();
    setSize(length * this->zoom, getHeight());
    this->thumbnailBounds->setWidth(length * this->zoom);
    repaint();
}


void AudioRegion::setDragger(MultiComponentDragger *dragger) {
    this->dragger = dragger;
}



void AudioRegion::setLoop(bool loop)
{
    if (loop) {
         setSize(this->thumbnail->getTotalLength() * (loopCount + 1) * this->zoom, getHeight());
    }
    else {
         setSize(this->thumbnail->getTotalLength() * this->zoom, getHeight());
    }
    
    this->loop = loop;
    repaint();
}



const float* AudioRegion::getReadBuffer(int channel) {
    return audioBuffer->getReadPointer(channel);
}

AudioSampleBuffer* AudioRegion::getBuffer() {
    return audioBuffer;
}

void AudioRegion::setZoom(float zoom) {
    this->zoom = zoom;
    
    if (loop) {
        setSize(this->thumbnail->getTotalLength() * (loopCount + 1) * this->zoom, getHeight());
    }
    else {
        setSize(this->thumbnail->getTotalLength() * this->zoom, getHeight());
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
    this->thumbnailBounds->setSize(this->thumbnail->getTotalLength() * this->zoom, getHeight());
    
    dragger->setRaster(this->zoom / 4);
    
    repaint();
}

void AudioRegion::setThumbnailBounds(Rectangle<int>* bounds) {
    this->thumbnailBounds = bounds;
}

void AudioRegion::paint (Graphics& g)
{    
    Rectangle<int> b = *this->thumbnailBounds;
    
	if (dragger->isSelected(this)) {
		g.setColour(Colours::steelblue.brighter());
	}
	else {
		g.setColour(Colours::steelblue);
	}

    g.fillRoundedRectangle(b.getX(),b.getY(),b.getWidth(),b.getHeight(),10);
    g.setColour(Colours::white);
    
    const double audioLength(this->thumbnail->getTotalLength());
    this->thumbnail->drawChannels(g, b, 0.0, audioLength, 1.0f);
    
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
            g.setColour(Colours::white);

            const double audioLength(this->thumbnail->getTotalLength());
            this->thumbnail->drawChannels(g, loopBounds,0.0,audioLength, 1.0f);
        }
    }
}

void AudioRegion::resized()
{   
    if (this->thumbnailBounds != NULL)
        this->thumbnailBounds->setHeight(getHeight());
}

AudioThumbnail* AudioRegion::getThumbnail() {
    return this->thumbnail;
}

void AudioRegion::changeListenerCallback(ChangeBroadcaster * source)
{
    if (source == this->thumbnail) {
        // repaint();
    }
}

int AudioRegion::getNumSamples() {
    return audioBuffer->getNumSamples();
}

void AudioRegion::componentMovedOrResized (Component& component, bool wasMoved, bool wasResized) {
    
    if (wasMoved) {
        long tracklen = Project::getInstance()->getTrackLength();
        double sampleRate = Project::getInstance()->getSampleRate();
        
        long sampleNum = (tracklen / (tracklen * zoom)) * getBounds().getX() * getSampleRate();
        if (sampleNum != getSampleOffset()) {
            setSampleOffset(sampleNum, true, true);
        }
        
        if (getSampleOffset() >= tracklen * sampleRate) {
            
            setSampleOffset(tracklen * sampleRate - getBuffer()->getNumSamples(), false, false);
        }
        
        Logger::getCurrentLogger()->writeToLog("AudioRegion sampleOffset " + String(sampleOffset));
    }
}
