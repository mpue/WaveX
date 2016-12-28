/*
  ==============================================================================

    MidiThumbnail.h
    Created: 28 Dec 2016 7:03:57pm
    Author:  Matthias Pueski

  ==============================================================================
*/

#ifndef MIDITHUMBNAIL_H_INCLUDED
#define MIDITHUMBNAIL_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class MidiThumbnail    : public Component
{
public:
    MidiThumbnail(double sampleRate);
    ~MidiThumbnail();

    void paint (Graphics&) override;
    void resized() override;

    double getTotalLength();
    
    void drawChannels (Graphics& g, const Rectangle<int>& area, double startTimeSeconds, double endTimeSeconds, float verticalZoomFactor);
    
    void addMessage(int sampleNum, MidiMessage* message);
    
private:
    
    double sampleRate;
    long totalSamples;
    MidiBuffer* midiBuffer;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MidiThumbnail)
};


#endif  // MIDITHUMBNAIL_H_INCLUDED
