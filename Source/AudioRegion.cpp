/*
  ==============================================================================

    Track.cpp
    Created: 25 Nov 2016 10:00:36pm
    Author:  Matthias Pueski

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "AudioRegion.h"

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
    setSize(length * this->zoom, 200);
    
    this->volume = 1;
    this->offset = 0;
    
    // addAndMakeVisible(resizerL);
    // addAndMakeVisible(resizerR);
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
    setSize(this->thumbnail->getTotalLength() * this->zoom, 200);
    this->volume = 1;
	this->offset = 0;
    
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

int AudioRegion::getNumSamples() {
    return audioBuffer->getNumSamples();
}

void AudioRegion::setSelected(bool selected)
{
	this->selected = selected;
	repaint();
}

bool AudioRegion::isSelected()
{
	return this->selected;
}

int AudioRegion::getLoopCount() {
    return this->loopCount;
}

void AudioRegion::setLoopCount(int count) {
    this->loopCount = count;
}

void AudioRegion::setLoop(bool loop)
{
    if (loop) {
         setSize(this->thumbnail->getTotalLength() * (loopCount + 1) * this->zoom, 200);
    }
    else {
         setSize(this->thumbnail->getTotalLength() * this->zoom, 200);
    }
    
    this->loop = loop;
    repaint();
}

bool AudioRegion::isLoop()
{
    return this->loop;
}

void AudioRegion::setDynOffset(int amount) {
    this->dynOffset = amount;
}

void AudioRegion::setSampleOffset(long offset)
{
    this->sampleOffset = offset;
}

long AudioRegion::getSampleOffset() {
    return this->sampleOffset;
}


void AudioRegion::setOffset(int offset)
{
	this->offset = offset;
}

double AudioRegion::getSampleRate() {
    return this->sampleRate;
}

int AudioRegion::getOffset()
{
	return offset + dynOffset;
}

const float* AudioRegion::getReadBuffer(int channel) {
    return audioBuffer->getReadPointer(channel);
}

AudioSampleBuffer* AudioRegion::getBuffer() {
    return audioBuffer;
}

void AudioRegion::setGain(float gain) {
    this->gain = gain;
}

void AudioRegion::setVolume(float volume) {
    this->volume = volume * gain;
}

float AudioRegion::getVolume() {
    return volume * gain;
}

void AudioRegion::setZoom(float zoom) {
    this->zoom = zoom;
    
    if (loop) {
        setSize(this->thumbnail->getTotalLength() * (loopCount + 1) * this->zoom, 200);
    }
    else {
        setSize(this->thumbnail->getTotalLength() * this->zoom, 200);
    }
    /*
    resizerR->setSize(5, getHeight());
    resizerR->setTopLeftPosition(getWidth() - 5, 0);
    
    resizerL->setSize(5, getHeight());
    resizerL->setTopLeftPosition(0, 0);
    */
    // setBounds(0,0,this->thumbnail->getTotalLength() * this->zoom, 200);
    this->thumbnailBounds->setSize(this->thumbnail->getTotalLength() * this->zoom, 200);
    repaint();
}

void AudioRegion::setThumbnailBounds(Rectangle<int>* bounds) {
    this->thumbnailBounds = bounds;
}

void AudioRegion::paint (Graphics& g)
{    
    if (this->thumbnail->getNumChannels() == 0)
        paintIfNoFileLoaded(g, *this->thumbnailBounds);
    else
        paintIfFileLoaded(g, *this->thumbnailBounds);
    
}

void AudioRegion::paintIfNoFileLoaded(Graphics& g, const Rectangle<int>& thumbnailBounds)
{
	g.setColour(Colours::cadetblue);
    g.fillRect(thumbnailBounds);
    g.setColour(Colours::white);
    g.setFont (Font (30.00f, Font::plain));
    g.drawFittedText("No File Loaded", thumbnailBounds, Justification::centred, 1.0f);
}

void AudioRegion::paintIfFileLoaded(Graphics& g, const Rectangle<int>& b)
{
    
	if (this->selected) {
		g.setColour(Colours::steelblue.brighter());
	}
	else {
		g.setColour(Colours::steelblue);
	}

    g.fillRoundedRectangle(b.getX(),b.getY(),b.getWidth(),b.getHeight(),10);
    g.setColour(Colours::white);
    
    const double audioLength(this->thumbnail->getTotalLength());
    this->thumbnail->drawChannels(g,
                                  b,
                                  0.0,
                                  audioLength,
                                  1.0f);
    
    g.setColour(Colours::steelblue.darker());    
    g.drawRoundedRectangle(b.getX(),b.getY(),b.getWidth(),b.getHeight(),10,1.0f);
    
    if(loop) {
        for (int i = 1; i <= loopCount;i++) {
            g.setColour(Colours::steelblue);
            Rectangle<int> loopBounds(b.getX() + i * getWidth() / (loopCount + 1),b.getY(),b.getWidth(),b.getHeight());
            g.fillRoundedRectangle(b.getX() + i * getWidth() / (loopCount + 1) ,b.getY(),b.getWidth(),b.getHeight(),10);
            g.setColour(Colours::white);

            const double audioLength(this->thumbnail->getTotalLength());
            this->thumbnail->drawChannels(g,
                                          loopBounds,
                                          0.0,
                                          audioLength,
                                          1.0f);
        }
    }
}



void AudioRegion::resized()
{
    if (this->thumbnail->getNumChannels() > 0) {

        // resizerR->setTopLeftPosition(getWidth() - 5, 0);
        // resizerL->setTopLeftPosition(0, 0);
    }

}

AudioThumbnail* AudioRegion::getThumbnail() {
    return this->thumbnail;
}

void AudioRegion::changeListenerCallback(ChangeBroadcaster * source)
{
    if (source == this->thumbnail) {
        repaint();
    }
}

String AudioRegion::getName(){
    return this->name;
}



