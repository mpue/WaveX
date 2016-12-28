/*
  ==============================================================================

    MidiThumbnail.cpp
    Created: 28 Dec 2016 7:03:57pm
    Author:  Matthias Pueski

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "MidiThumbnail.h"
#include "Project.h"

//==============================================================================
MidiThumbnail::MidiThumbnail(double sampleRate)
{
    this->sampleRate = sampleRate;
    midiBuffer = new MidiBuffer();
}

MidiThumbnail::~MidiThumbnail()
{
}



void MidiThumbnail::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (Colours::white);   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (Colours::lightblue);
    g.setFont (14.0f);
    g.drawText ("MidiThumbnail", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
}

void MidiThumbnail::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

double MidiThumbnail::getTotalLength() 
{
    return sampleRate > 0 ? (totalSamples / sampleRate) : 0;
}

void MidiThumbnail::drawChannels (Graphics& g, const Rectangle<int>& area, double startTimeSeconds, double endTimeSeconds, float verticalZoomFactor) {
    
}

void MidiThumbnail::addMessage(int sampleNum, MidiMessage* message) {
    midiBuffer->addEvent(*message, sampleNum);
    totalSamples = sampleNum;
    repaint();
}