//
//  MainComponent.h
//  WaveX
//
//  Created by Matthias Pueski on 08.04.18.
//  Copyright © 2018 pueski.de. All rights reserved.
//

#ifndef MainComponent_h
#define MainComponent_h

#include "../JuceLibraryCode/JuceHeader.h"
#include <iostream>
#include <queue>
#include "TrackNavigator.h"
#include "TrackPropertyView.h"
#include "Track.h"
#include "PositionMarker.h"
#include "WaveSelector.h"
#include "TimeLine.h"
#include "MixerPanel.h"
#include "Project.h"
#include "Session.h"
#include "Mixer.h"
#include "SequenceEditor.h"
#include "Plugins/PluginManager.h"
#include "MidiRecorder/MidiRecorderPanel.h"

class MainContentComponent : public AudioAppComponent,
                                public AudioProcessorPlayer,
                                public MenuBarModel,
                                public ChangeListener,
                                public ChangeBroadcaster,
                                public Timer
{
 
public:
                                    
    MainContentComponent(TimeLine* timeLine, TrackPropertyView* trackProperties, MixerPanel* mixer);
   ~MainContentComponent();
    void setupIO();
    void setupIO(int inchannels, int outchannels);
    void timerCallback() override;
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void handlePlayBack(int _numSamples, Track* t);
    void handleRecording(int _numSamples, const float** inputChannelData, float** outputChannelData);
    virtual void audioDeviceIOCallback (const float** inputChannelData,
                                        int numInputChannels,
                                        float** outputChannelData,
                                        int numOutputChannels,
                                        int _numSamples) override;
    void processOutputMerge(float** outputChannelData, int numOutputChannels, int _numSamples);
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
    virtual void handleIncomingMidiMessage (MidiInput* source, const MidiMessage& message) override;
    void releaseResources() override;
    void paint (Graphics& g) override;
    void resized() override;
    double getRms(int channel);
    double getMagnitude(int channel);
    bool isMasterVisible();
    void setVolume(int channel, float volume);
    void setPosition(long sample);
    TrackNavigator* getNavigator();
    PositionMarker* getMarker();
    int getNumActiveChannels(int i);
    void importAudio();
    void removeSelectedTrack();
    void addTrack(Track::Type type);
    void exportAudio();
    void openStepSequencer();
    void openEventRecorder();
    void openSettings();
    void setTracklength(long length);
    long getTrackLength();
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainContentComponent)
    
    AudioProcessorGraph* processorGraph;
    
    AudioProcessorPlayer* player;
    MidiMessageSequence midiSequence;
    vector<AudioSampleBuffer*> outputBuffers;
    ScopedPointer<AudioSampleBuffer> buffer;
    
    TimeSliceThread thread;
    ScopedPointer<TrackNavigator> navigator;
    ScopedPointer<PositionMarker> marker;
    ScopedPointer<TimeLine> timeLine;
    MixerPanel* mixer;
    TrackPropertyView* trackProperties;
    
    // track length in seconds
    long tracklength = 0;
    
    long numSamples = 0;
    double sampleRate = 0;
    
    int buffersize = 0;
    
    bool ctrlPressed;
    bool leftShiftPressed;
    double rmsLeft;
    double rmsRight;
    double magnitudeLeft = 0;
    double magnitudeRight = 0;
    bool masterVisible;
    
    float leftVolume;
    float rightVolume;
    
    float zoom;
  
    std::queue<MidiMessage*> pendingMessages;
    MidiBuffer midiBuffer;
    vector<String> availableInstruments;
    void buildPluginMenu(PopupMenu &menu);
    virtual StringArray getMenuBarNames() override;
    virtual PopupMenu getMenuForIndex(int index, const String & menuName) override;
    virtual void menuItemSelected(int menuItemID, int topLevelMenuIndex) override;
    virtual void changeListenerCallback(ChangeBroadcaster * source) override;
    

    
};


#endif /* MainComponent_h */
