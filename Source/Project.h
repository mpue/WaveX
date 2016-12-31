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

#include "CustomLookAndFeel.h"
#include "AudioClip.h"
#include <vector>

using namespace std;

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

    vector<AudioClip*> getAudioClips() {
        return audioClips;
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
    

    
    static long DEFAULT_TRACK_LENGTH;
    static int  DEFAULT_TRACK_HEIGHT;
    
    inline double snap(double location, double raster) {
        
        int toleranceWindow = (raster / tolerance);
        
        if (location > 0) {
            
            
            if ((fmod(location,raster )) > toleranceWindow) {
                location = location + (raster - (fmod(location,raster)));
            }
            else {
                location = location - (fmod(location,raster));
            }
        }
        else {
            if ((fmod(location,raster)) < toleranceWindow) {
                location = location + (raster - (fmod(location,raster))) - raster;
            }
            else {
                location = location - (fmod(location, raster)) - raster;
            }
        }
        
        return location;
    }
    
protected:
    Project() {
        this->tracklength = DEFAULT_TRACK_LENGTH;
        name = "empty Project";
    };
    
    ~Project() {

    }
    
    static Project* instance;
        
    int tolerance = 1;
    

    String name;
    long tracklength;
    double sampleRate;
    int bufferSize;
    
    vector<AudioClip*> audioClips;
    
};



#endif  // PROJECT_H_INCLUDED
