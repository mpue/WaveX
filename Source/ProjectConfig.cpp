/*
  ==============================================================================

    ProjectConfig.cpp
    Created: 31 Dec 2016 11:55:04am
    Author:  Matthias Pueski

  ==============================================================================
*/

#include "ProjectConfig.h"

ProjectConfig::ProjectConfig() {
    
}

ProjectConfig::~ProjectConfig() {
    for(std::vector<AudioClip*>::iterator it = audioClips.begin(); it != audioClips.end();it++) {
        delete *it;
    }
    for(std::vector<TrackConfig*>::iterator it = tracks.begin(); it != tracks.end();it++) {
        delete *it;
    }
    // delete mixerConfig;
}

vector<AudioClip*> ProjectConfig::getAudioClips() {
    return audioClips;
}

void ProjectConfig::addClip(AudioClip* clip) {
    audioClips.push_back(clip);
}

vector<TrackConfig*> ProjectConfig::getTracks() {
    return tracks;
}

void ProjectConfig::addTrack(TrackConfig* track) {
    tracks.push_back(track);
}

MixerConfig* ProjectConfig::getMixerConfig() {
    return mixerConfig;
}

void ProjectConfig::setMixerConfig(MixerConfig* config) {
    this->mixerConfig = config;
}

void ProjectConfig::setTracklength(long length) {
    this->trackLength = length;
}

long ProjectConfig::getTrackLength() {
    return trackLength;
}

void ProjectConfig::setName(String name) {
    this->name = name;
}

String ProjectConfig::getName() {
    return name;
}

void ProjectConfig::setSampleRate(double sampleRate) {
    this->sampleRate = sampleRate;
}

double ProjectConfig::getSampleRate() {
    return sampleRate;
}

void ProjectConfig::setBufferSize(double bufferSize) {
    this->bufferSize = bufferSize;
}

double ProjectConfig::getBufferSize() {
    return bufferSize;
}

float ProjectConfig::getTempo() {
    return tempo;
}

void ProjectConfig::setTempo(float tempo) {
    this->tempo = tempo;
}

void ProjectConfig::setConfig(ValueTree & v) {
    
    for(std::vector<TrackConfig*>::iterator it = tracks.begin(); it != tracks.end();it++) {
        delete *it;
    }
    
    tracks.clear();
    
    trackLength = v.getProperty("trackLength").toString().getIntValue();
    name = v.getProperty("name");
    sampleRate = v.getProperty("sampleRate");
    bufferSize = v.getProperty("bufferSize");
    tempo = v.getProperty("tempo");
    
    for (int i = 0; i < v.getNumChildren(); i++) {
    
        ValueTree child = v.getChild(i);
        
        TrackConfig* tc = new TrackConfig();
        
        tc->setVolume(child.getProperty("volume"));
        tc->setGain(child.getProperty("gain"));
        tc->setPan(child.getProperty("pan"));
        tc->setHeight(child.getProperty("height"));
        tc->setMidiChannel(child.getProperty("midiChannel"));
        tc->setSolo(child.getProperty("solo"));
        tc->setMute(child.getProperty("mute"));
        tc->setMono(child.getProperty("mono"));
        
        int* inputChannels = new int[2];
        String sInputChannels = child.getProperty("inputChannels");
        inputChannels[0] = sInputChannels.substring(0, sInputChannels.indexOf(",")).getIntValue();
        inputChannels[1] = sInputChannels.substring(sInputChannels.indexOf(",") + 1).getIntValue();
        
        tc->setInputChannels(inputChannels);
        
        int* outputChannels = new int[2];
        String sOutputChannels = child.getProperty("outputChannels");
        outputChannels[0] = sOutputChannels.substring(0, sOutputChannels.indexOf(",")).getIntValue();
        outputChannels[1] = sOutputChannels.substring(sOutputChannels.indexOf(",") + 1).getIntValue();
        
        tc->setOutputChannels(outputChannels);
        
        tc->setMidiInputDevice(child.getProperty("midiInputDevice"));
        tc->setMidiOutputDevice(child.getProperty("midiOutputDevice"));
        tc->setType(child.getProperty("type"));
        
        tracks.push_back(tc);
        
    }
}

ValueTree ProjectConfig::getConfig() {
    
    ValueTree config = ValueTree("Project");
    
    config.setProperty("trackLength", (int)trackLength, nullptr);
    config.setProperty("name", name, nullptr);
    config.setProperty("sampleRate", sampleRate,nullptr);
    config.setProperty("bufferSize", bufferSize, nullptr);
    config.setProperty("tempo", tempo, nullptr);
    
    for(int i = 0; i < tracks.size(); i++) {
        config.addChild(tracks.at(i)->getConfig(), -1, nullptr);
    }
    
    return config;
    
}