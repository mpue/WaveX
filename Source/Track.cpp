/*
  ==============================================================================

    Track.cpp
    Created: 25 Nov 2016 10:00:36pm
    Author:  Matthias Pueski

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Track.h"

//==============================================================================
Track::Track(File file, TimeSliceThread* thread)
{
    manager.registerBasicFormats();
    AudioFormatReader* reader = manager.createReaderFor(file);
    ScopedPointer<AudioFormatReaderSource> afr = new AudioFormatReaderSource(reader, true);

    this->thumbnailCache = new AudioThumbnailCache(1);
    this->thumbnail = new AudioThumbnail(512, manager, *this->thumbnailCache);
    this->thumbnail->addChangeListener(this);
    // this->thumbnail->setSource(new FileInputSource(file));
    
    audioBuffer = new AudioSampleBuffer(2, reader->lengthInSamples);
    reader->read(audioBuffer, 0, reader->lengthInSamples, 0, true, true);
    //

    this->thumbnail->reset(2, 44100);
    this->thumbnail->addBlock(0, *audioBuffer, 0,reader->lengthInSamples);
    
    /*
    this->source = new AudioTransportSource();
    this->source->setSource(afr,
                              0,                   // tells it to buffer this many samples ahead
                              thread,                 // this is the background thread to use for reading-ahead
                              reader->sampleRate);     // allows for sample rate correction
    
    this->readerSource = afr.release();
    */
     
    this->name = file.getFileNameWithoutExtension();
    this->zoom = 20;
    setSize(this->thumbnail->getTotalLength() * this->zoom, 200);
    this->volume = 1;
    

}

Track::~Track()
{
    delete this->thumbnailCache;
    delete this->thumbnail;
    delete this->audioBuffer;
    // this->readerSource->releaseResources();
    // this->readerSource = nullptr;
}

int Track::getNumSamples() {
    return audioBuffer->getNumSamples();
}


const float* Track::getReadBuffer(int channel) {
    return audioBuffer->getReadPointer(channel);
}

AudioSampleBuffer* Track::getBuffer() {
    return audioBuffer;
}

AudioTransportSource* Track::getSource() {
    return this->source;
}

void Track::setGain(float gain) {
    this->gain = gain;
}

void Track::setVolume(float volume) {
    this->volume = volume * gain;
}

float Track::getVolume() {
    return volume * gain;
}

void Track::setZoom(float zoom) {
    this->zoom = zoom;
    setSize(this->thumbnail->getTotalLength() * this->zoom, 200);
	setBounds(0,0,this->thumbnail->getTotalLength() * this->zoom, 200);
    this->thumbnailBounds->setSize(this->thumbnail->getTotalLength() * this->zoom, 200);
    repaint();
}

void Track::setThumbnailBounds(Rectangle<int>* bounds) {
    this->thumbnailBounds = bounds;
}

void Track::paint (Graphics& g)
{    
    if (this->thumbnail->getNumChannels() == 0)
        paintIfNoFileLoaded(g, *this->thumbnailBounds);
    else
        paintIfFileLoaded(g, *this->thumbnailBounds);
    
}

void Track::paintIfNoFileLoaded(Graphics& g, const Rectangle<int>& thumbnailBounds)
{
    g.setColour(Colours::cadetblue);
    g.fillRect(thumbnailBounds);
    g.setColour(Colours::white);
    g.setFont (Font (30.00f, Font::plain));
    g.drawFittedText("No File Loaded", thumbnailBounds, Justification::centred, 1.0f);
}

void Track::paintIfFileLoaded(Graphics& g, const Rectangle<int>& thumbnailBounds)
{
    
    g.setColour(Colours::steelblue);
    g.fillRect(thumbnailBounds);
    
    g.setColour(Colours::white);
    
    const double audioLength(this->thumbnail->getTotalLength());
    this->thumbnail->drawChannels(g,
                                  thumbnailBounds,
                                  0.0,
                                  audioLength,
                                  1.0f);
    
}



void Track::resized()
{
}

AudioThumbnail* Track::getThumbnail() {
    return this->thumbnail;
}

void Track::changeListenerCallback(ChangeBroadcaster * source)
{
    if (source == this->thumbnail) {
        repaint();
    }
}

String Track::getName(){
    return this->name;
}