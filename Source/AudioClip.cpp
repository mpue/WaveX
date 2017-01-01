/*
  ==============================================================================

    Sample.cpp
    Created: 31 Dec 2016 10:00:19am
    Author:  Matthias Pueski

  ==============================================================================
*/

#include "AudioClip.h"

AudioClip::AudioClip(String name, String path, long length, long offset) {
    this->name = name;
    this->path = path;
    this->length = length;
    this->offset = offset;
}

AudioClip::AudioClip() {

}

AudioClip::~AudioClip() {
    
}

void AudioClip::setLength(long length) {
    this->length = length;
}

long AudioClip::getLength() {
    return length;
}

void AudioClip::setOffset(long offset) {
    this->offset = offset;
}

long AudioClip::getOffset() {
    return offset;
}

void AudioClip::setName(juce::String name) {
    this->name = name;
}

String AudioClip::getName() {
    return name;
}

void AudioClip::setPath(juce::String path) {
    this->path = path;
}

String AudioClip::getPath() {
    return path;
}

ValueTree AudioClip::getConfig() {
    
    ValueTree config = ValueTree("AudioClip");
    
    config.setProperty("name", name, nullptr);
    config.setProperty("path", path, nullptr);
    config.setProperty("length", (int)length, nullptr);
    config.setProperty("offset", name, nullptr);

    return config;
}