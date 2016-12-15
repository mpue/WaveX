/*
  ==============================================================================

    WaveNavigator.h
    Created: 24 Nov 2016 8:04:54am
    Author:  Matthias Pueski

  ==============================================================================
*/

#ifndef WAVENAVIGATOR_H_INCLUDED
#define WAVENAVIGATOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "WaveSelector.h"
#include "PositionMarker.h"
#include "Track.h"
#include <vector>

//==============================================================================
/*
*/
class TrackNavigator    : public Component, public ChangeListener, public ChangeBroadcaster, public KeyListener
{
public:
    TrackNavigator(PositionMarker* marker);
    ~TrackNavigator();

    void paint (Graphics&) override;
    void resized() override;

    AudioThumbnail* getThumbnail();
    WaveSelector* getSelector();
    
    void addTrack(File file, TimeSliceThread* thread);
    Track* getCurrentTrack();
    std::vector<Track*> getTracks();
    
    bool isPlaying();
    void setPlaying(bool playing);
    
    double getMaxLength();
    void setPosition(double position);
    double getPosition();
    
	float getZoom();
    void setZoom(float zoom);
    
    MixerAudioSource* getMixerSource();
    
private:

    Track* currentTrack;
    AudioFormatManager manager;
    PositionMarker* marker;
    
    std::vector<Track*> tracks;
    ScopedPointer<WaveSelector> selector;

    ScopedPointer<MixerAudioSource> mixerSource;
    
    bool playing;
    double position;
    float zoom;
    
    virtual void changeListenerCallback(ChangeBroadcaster * source) override;
    virtual void mouseDown (const MouseEvent& event) override;
    virtual bool keyPressed(const KeyPress& key, Component* originatingComponent) override;
    virtual void mouseDrag(const MouseEvent& event) override;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TrackNavigator)
};


#endif  // WAVENAVIGATOR_H_INCLUDED
