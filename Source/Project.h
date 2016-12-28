/*
  ==============================================================================

    Project.h
    Created: 21 Dec 2016 7:45:32pm
    Author:  Matthias Pueski

  ==============================================================================
*/

#ifndef PROJECT_H_INCLUDED
#define PROJECT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include <vector>
#include "AudioRegion.h"
#include "Region.h"
#include "CustomLookAndFeel.h"

class Project : public ChangeBroadcaster {
    
public:
    
    static Project* getInstance() {
        if (instance == NULL) {
            instance = new Project();
        }
        return instance;
    }
    
    static void destroy() {
        delete instance;
    }

    inline void setTracklength(long length) {
        this->tracklength = length;
        sendChangeMessage();
    };
    
    inline long getTrackLength() {
        return this->tracklength;
    }

    inline void setName(String name) {
        this->name = name;
        sendChangeMessage();
    }
    
    inline String getName() {
        return name;
    }
    
    inline void setSampleRate(double sampleRate) {
        this->sampleRate = sampleRate;
    }
    
    inline double getSampleRate() {
        return sampleRate;
    }
    
    inline void setBufferSize(double bufferSize) {
        this->bufferSize = bufferSize;
    }
    
    inline double getBufferSize() {
        return bufferSize;
    }
    
    inline void addChangeListener (ChangeListener* listener) {
        ChangeBroadcaster::addChangeListener(listener);
    }
    
    inline void copyRegion(Region* region) {
        regionsClipboard.push_back(region);
    }
    
    inline Region* pasteRegion(long position) {
        
        if (AudioRegion* region = dynamic_cast<AudioRegion*>(regionsClipboard.back())) {
            AudioRegion* copy = new AudioRegion(region,*manager,sampleRate);
            copy->setSampleOffset(position, false, false);
            return copy;
        }
        
        return NULL;

    }
    
    inline void clearRegionsClipboard() {
        regionsClipboard.clear();
    }
    
    inline AudioFormatManager* getAudioFormatManager() {
        return manager;
    }
    
    inline CustomLookAndFeel* getLookAndFeel() {
        return &lookAndFeel;
    };
    
    static long DEFAULT_TRACK_LENGTH;
    static int  DEFAULT_TRACK_HEIGHT;
    
protected:
    Project() {
        this->tracklength = DEFAULT_TRACK_LENGTH;
        name = "empty Project";
        manager = new AudioFormatManager();
        manager->registerBasicFormats();
            };
    
    ~Project() {
        delete manager;
        removeAllChangeListeners();
    }
    
    static Project* instance;
    
    CustomLookAndFeel lookAndFeel;
    String name;
    long tracklength;
    double sampleRate;
    int bufferSize;
    std::vector<Region*> regionsClipboard;
    AudioFormatManager* manager;
    
};



#endif  // PROJECT_H_INCLUDED
