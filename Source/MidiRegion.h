/*
  ==============================================================================

    MidiRegion.h
    Created: 28 Dec 2016 6:55:16pm
    Author:  Matthias Pueski

  ==============================================================================
*/

#ifndef MIDIREGION_H_INCLUDED
#define MIDIREGION_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "MultiComponentDragger.h"
#include "Region.h"
#include "MidiThumbnail.h"
#include "Project.h"

#include <map>
#include <vector>

class MidiRegion : public Region {
    
public:
    
    MidiRegion(long startSample, long sampleLength, double sampleRate);
    virtual ~MidiRegion();
    
    virtual void paint (Graphics&) override;
    virtual void resized() override;

    virtual void setThumbnailBounds(Rectangle<int>* bounds) override;
    void setNumSamples(int numSamples);
    virtual int getNumSamples() override;
    
    MidiBuffer* getBuffer();
    
    MidiThumbnail* getThumbnail();
    
    virtual void setZoom(float zoom) override;
    virtual void setLoop(bool loop) override;
    
    // the timer is needed to updat the thumbnail during record
    virtual void timerCallback() override;    
    virtual void stopRecording() override;
    virtual void startRecording() override;
    
    void clear();
    MidiMessage* getMessage(int sampleNum);
    void addMessage(int sampleNum, MidiMessage* m);
    
    // component dragger used to drag and drop regions
    void setDragger(MultiComponentDragger* dragger);
    
    virtual void updateThumb() override;
    virtual void componentMovedOrResized (Component& component,bool wasMoved, bool wasResized) override;

private:
    MidiBuffer* midiBuffer;
    Rectangle<int>* thumbnailBounds = NULL;
    virtual void changeListenerCallback(ChangeBroadcaster * source) override;
    MidiThumbnail* midiThumbnail;
    int numSamples;
    MidiBuffer::Iterator* iterator = NULL;
    MidiMessage message;
    std::map<int, MidiMessage*> midiMessages;
    
};


#endif  // MIDIREGION_H_INCLUDED
