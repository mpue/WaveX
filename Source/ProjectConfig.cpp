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
    delete mixerConfig;
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

ValueTree ProjectConfig::getProjectConfig() {
    
    ValueTree config = ValueTree("Project");
    
    config.setProperty("trackLength", (int)trackLength, nullptr);
    config.setProperty("name", name, nullptr);
    config.setProperty("sampleRate", sampleRate,nullptr);
    config.setProperty("bufferSize", bufferSize, nullptr);
    
    return config;
    
}