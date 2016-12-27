/*
  ==============================================================================

    Mixer.h
    Created: 27 Dec 2016 10:15:02am
    Author:  Matthias Pueski

  ==============================================================================
*/

#ifndef MIXER_H_INCLUDED
#define MIXER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Track.h"

#include <vector>

using namespace std;

class Mixer : public ChangeBroadcaster, public ChangeListener {
    
public:
        
    static Mixer* getInstance() {
        if (instance == NULL) {
            instance = new Mixer();
        }
        return instance;
    }
    
    static void destroy() {
        delete instance;
    }
    
    inline void addTrack(Track* track) {
        this->tracks.push_back(track);
        track->addChangeListener(this);
        sendChangeMessage();
    }
    
    vector<Track*> getTracks() {
        return this->tracks;
    }
    
    Track* getLastModifiedTrack() {
        return this->lastModified;
    }
    
    inline virtual void changeListenerCallback (ChangeBroadcaster* source) override {
        
        if (Track* t = dynamic_cast<Track*>(source)) {
            lastModified = t;
            sendChangeMessage();
        }
        
    }
    
    inline void addChangeListener (ChangeListener* listener) {
        ChangeBroadcaster::addChangeListener(listener);
    }
    
    void setAvailableInputChannelNames(StringArray channels) {
        this->availableInputChannels = channels;
    }
    
    StringArray getInputChannels() {
        return this->availableInputChannels;
    }
    
    void setAvailableOutputChannelNames(StringArray channels) {
        this->availableOutputChannels = channels;
    }
    
    StringArray getOutputChannels() {
        return this->availableOutputChannels;
    }
    
    
private:
    Mixer() {


    };
    
    ~Mixer() {
        removeAllChangeListeners();
    }
    
    static Mixer* instance;
    vector<Track*> tracks;
    Track* lastModified = NULL;
    StringArray availableInputChannels;
    StringArray availableOutputChannels;
    
};



#endif  // MIXER_H_INCLUDED
