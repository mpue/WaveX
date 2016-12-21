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
#include "DragConstrainer.h"
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

    WaveSelector* getSelector();
    
    void addTrack(double sampleRate);
	void removeSelectedTrack();
    Track* getCurrentTrack();
    std::vector<Track*> getTracks();
    
    bool isPlaying();
    void setPlaying(bool playing);
    
    double getMaxLength();
    void setPosition(double position);
    double getPosition();
    
	float getZoom();
    void setZoom(float zoom);
    
	void updateTrackLayout(ChangeBroadcaster * source);
	void adjustHeight();

    


private:
    ComponentDragger dragger;
    DragConstrainer constrainer;
    
    Track* currentTrack = NULL;
    AudioFormatManager manager;
    PositionMarker* marker;
    
    std::vector<Track*> tracks;
    ScopedPointer<WaveSelector> selector;

    bool playing = false;
    double position;
    float zoom;
    // length of the track in seconds
    long tracklength;
    
    virtual void changeListenerCallback(ChangeBroadcaster * source) override;
    virtual void mouseDown (const MouseEvent& event) override;
    virtual void mouseUp (const MouseEvent& event) override;
    virtual bool keyPressed(const KeyPress& key, Component* originatingComponent) override;
    virtual void mouseDrag(const MouseEvent& event) override;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TrackNavigator)
};


#endif  // WAVENAVIGATOR_H_INCLUDED
