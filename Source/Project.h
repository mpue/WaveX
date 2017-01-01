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

#include "ProjectConfig.h"
#include "CustomLookAndFeel.h"
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
    
    void setTracklength(long length) {
        this->tracklength = length;
        sendChangeMessage();
    };
    
    long getTrackLength() {
        return this->tracklength;
    }

    void setName(String name) {
        this->name = name;
        sendChangeMessage();
    }
    
    String getName() {
        return name;
    }
    
    void setSampleRate(double sampleRate) {
        this->sampleRate = sampleRate;
    }
    
    double getSampleRate() {
        return sampleRate;
    }
    
    void setBufferSize(double bufferSize) {
        this->bufferSize = bufferSize;
    }
    
    double getBufferSize() {
        return bufferSize;
    }
    
    inline void addChangeListener (ChangeListener* listener) {
        ChangeBroadcaster::addChangeListener(listener);
    }

    void createNew(String name) {
        this->name = name;
        
        if (config != NULL) {
            delete config;
        }
        
        config = new ProjectConfig();
    }
    
    void save(File output) {
 
        config->setName(name);
        config->setBufferSize(bufferSize);
        config->setSampleRate(sampleRate);
        config->setTracklength(tracklength);
        
        config->getTracks().clear();
        
        for(int i = 0; i < config->getTracks().size();i++) {
            
        }
        
        ValueTree v = config->getProjectConfig();
        
        XmlElement* xml = v.createXml();
        xml->writeToFile(output, "");
        delete xml;
        
    }
    
    void load() {
        
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
        this->config = new ProjectConfig();
    };
    
    ~Project() {
        delete config;
    }
    
    static Project* instance;
        
    int tolerance = 1;
    

    String name;
    long tracklength;
    double sampleRate;
    int bufferSize;
    
    ProjectConfig* config = NULL;
    
};



#endif  // PROJECT_H_INCLUDED
