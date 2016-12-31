/*
  ==============================================================================

    TrackConfig.cpp
    Created: 31 Dec 2016 11:55:18am
    Author:  Matthias Pueski

  ==============================================================================
*/

#include "TrackConfig.h"

TrackConfig::TrackConfig() {
    
}

TrackConfig::~TrackConfig() {
    for(std::vector<RegionConfig*>::iterator it = regions.begin(); it != regions.end();it++) {
        delete *it;
    }
    for(std::vector<EffectConfig*>::iterator it = effects.begin(); it != effects.end();it++) {
        delete *it;
    }
    for(std::vector<AuxSendConfig*>::iterator it = auxSendConfigs.begin(); it != auxSendConfigs.end();it++) {
        delete *it;
    }
    delete instrument;
    
}

String TrackConfig::getName()
{
    return name;
}

void TrackConfig::setGain(float gain)
{
    this->gain = gain;
}

void TrackConfig::setVolume(float volume)
{
    this->volume = volume;
    // sendChangeMessage();
}

float TrackConfig::getVolume()
{
    return volume;
}

void TrackConfig::setPan(float pan)
{
    this->pan = pan;
    // sendChangeMessage();
}

float TrackConfig::getPan()
{
    return pan;
}

void TrackConfig::setSolo(bool solo) {
    this->solo = solo;
    // sendChangeMessage();
}

bool TrackConfig::isSolo() {
    return solo;
}

void TrackConfig::setMute(bool mute) {
    this->mute = mute;
    // sendChangeMessage();
}

bool TrackConfig::isMute() {
    return mute;
}

void TrackConfig::setMono(bool mono) {
    this->mono = mono;
    // sendChangeMessage();
}

bool TrackConfig::isMono() {
    return mono;
}

void TrackConfig::addRegion(RegionConfig* region) {
    regions.push_back(region);
}

void TrackConfig::addEffect(EffectConfig* effect) {
    effects.push_back(effect);
}

void TrackConfig::addAuxSend(AuxSendConfig* aux) {
    auxSendConfigs.push_back(aux);
}

void TrackConfig::setInstrument(InstrumentConfig* instrument) {
    this->instrument = instrument;
}

void TrackConfig::setInputChannels(int* channels) {
    this->inputChannels[0] = channels[0];
    this->inputChannels[1] = channels[1];
}

int* TrackConfig::getInputChannels() {
    return &this->inputChannels[0];
}

void TrackConfig::setOutputChannels(int* channels) {
    this->outputChannels[0] = channels[0];
    this->outputChannels[1] = channels[1];
}

int* TrackConfig::getOutputChannels() {
    return &this->outputChannels[0];
}

Track::Type TrackConfig::getType() {
    return this->type;
}

void TrackConfig::setType(Track::Type type) {
    this->type = type;
}

void TrackConfig::setMidiInputDevice(String name) {
    this->midiInputDevice = name;
}

void TrackConfig::setMidiOutputDevice(String name) {
    this->midiOutputDevice = name;
}

String TrackConfig::getMidiInputDevice() {
    return midiInputDevice;
}

String TrackConfig::getMidiOutputDevice() {
    return midiOutputDevice;
}
