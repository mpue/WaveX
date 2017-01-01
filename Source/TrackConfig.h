/*
  ==============================================================================

    TrackConfig.h
    Created: 31 Dec 2016 11:55:18am
    Author:  Matthias Pueski

  ==============================================================================
*/

#ifndef TRACKCONFIG_H_INCLUDED
#define TRACKCONFIG_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

#include "RegionConfig.h"
#include "EffectConfig.h"
#include "InstrumentConfig.h"
#include "AuxSendConfig.h"

#include <vector>

using namespace std;

class TrackConfig {
public:
    TrackConfig();
    ~TrackConfig();
    
    // the possible regins a track can have
    void addRegion(RegionConfig* region);
    // the asscociated fx chain, we need to take care of the order!
    void addEffect(EffectConfig* effect);
    // the aux send channels of a track, order is also important
    void addAuxSend(AuxSendConfig* aux);
    // the associated instrument if this is an instrumen track
    void setInstrument(InstrumentConfig* instrument);
    
    String getName();
    void setName(String name);
    
    void setGain(float gain);
    
    void setVolume(float volume);
    float getVolume();
    
    float getPan();
    void setPan(float pan);
    
    void setInputChannels(int* channels);
    
    int* getInputChannels();
    
    void setOutputChannels(int* channels);
    
    int* getOutputChannels();
    
    String getType();
    
    void setType(String type);
    
    void setMidiInputDevice(String name);
    
    void setMidiOutputDevice(String name);
    
    String getMidiInputDevice();
    
    String getMidiOutputDevice();
    
    bool isSolo();
    void setSolo(bool solo);
    
    bool isMute();
    void setMute(bool mute);
    
    bool isMono();
    void setMono(bool mono);
    
    ValueTree getConfig();
    
private:

    String name;
    
    float volume;
    float gain = 1;
    float pan = 0.0f;
    
    int midiChannel = 1;

    bool solo = false;
    bool mute = false;
    bool mono = false;
    
    int inputChannels[2] = { 0 };
    int outputChannels[2] = { 0 };
    
    String midiInputDevice;
    String midiOutputDevice;
    
    String type;
    vector<RegionConfig*> regions;
    vector<EffectConfig*> effects;
    vector<AuxSendConfig*> auxSendConfigs;
    InstrumentConfig* instrument;
    
};

#endif  // TRACKCONFIG_H_INCLUDED
