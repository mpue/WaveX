/*
  ==============================================================================

    Track.cpp
    Created: 25 Nov 2016 10:00:36pm
    Author:  Matthias Pueski

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "AudioRegion.h"

//==============================================================================
AudioRegion::AudioRegion(File file, AudioFormatManager& manager, double sampleRate)
{
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
}

AudioRegion::~AudioRegion()
{
    delete this->thumbnailCache;
    delete this->thumbnail;
    delete this->audioBuffer;
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

void AudioRegion::setOffset(int offset)
{
	this->offset = offset;
}

int AudioRegion::getOffset()
{
	return offset;
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
    setSize(this->thumbnail->getTotalLength() * this->zoom, 200);
	setBounds(0,0,this->thumbnail->getTotalLength() * this->zoom, 200);
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

void AudioRegion::paintIfFileLoaded(Graphics& g, const Rectangle<int>& thumbnailBounds)
{
    
	if (this->selected) {
		g.setColour(Colours::steelblue.brighter());
	}
	else {
		g.setColour(Colours::steelblue);
	}

    g.fillRect(thumbnailBounds);
    
    g.setColour(Colours::white);
    
    const double audioLength(this->thumbnail->getTotalLength());
    this->thumbnail->drawChannels(g,
                                  thumbnailBounds,
                                  0.0,
                                  audioLength,
                                  1.0f);
    
}



void AudioRegion::resized()
{
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



