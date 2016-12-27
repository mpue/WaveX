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
    
    enum Source {
        MIXER,
        PROPERTYVIEW
    };
    
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
    
    inline void setSource(Source source) {
        this->source = source;
    }
    
    inline Source getSource() {
        return source;
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
    
    
private:
    Mixer() {


    };
    
    ~Mixer() {
        removeAllChangeListeners();
    }
    
    static Mixer* instance;
    vector<Track*> tracks;
    Track* lastModified = NULL;
    Source source;
    
};



#endif  // MIXER_H_INCLUDED
