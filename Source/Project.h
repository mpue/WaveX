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
#include <map>

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

    ProjectConfig* getConfig() {
        return config;
    }
    
    void createNew(String name) {
        this->name = name;
        
        if (config != NULL) {
            delete config;
        }
        
        config = new ProjectConfig();
        clear();
    }
    
    float getTempo() {
        return tempo;
    }
    
    void setTempo(float tempo) {
        this->tempo = tempo;
    }
    
    void saveCurrent(File output) {
        ValueTree v = config->getConfig();
        
        std::map<String, String>::iterator it;
        
        ValueTree audioFiles = ValueTree("AudioFiles");
        
        for (it = projectAudio.begin(); it != projectAudio.end(); ++it) {
            ValueTree file = ValueTree("File");
            file.setProperty("refId", it->first, nullptr);
            file.setProperty("path", it->second, nullptr);
            audioFiles.addChild(file, -1, nullptr);
        }
        
        
        XmlElement* xml = v.createXml();
        xml->writeToFile(output, "");
        delete xml;
    }
    
    void save(File output) {
 
        setName(output.getFileNameWithoutExtension());
        
        config->setName(name);
        config->setBufferSize(bufferSize);
        config->setSampleRate(sampleRate);
        config->setTracklength(tracklength);
        config->setTempo(tempo);
        
        ValueTree v = config->getConfig();
 
        std::map<String, String>::iterator it;
        
        ValueTree audioFiles = ValueTree("AudioFiles");
        
        for (it = projectAudio.begin(); it != projectAudio.end(); ++it) {
            ValueTree file = ValueTree("File");
            file.setProperty("refId", it->first, nullptr);
            file.setProperty("path", it->second, nullptr);
            audioFiles.addChild(file, -1, nullptr);
        }
        
        v.addChild(audioFiles, -1, nullptr);
        
        XmlElement* xml = v.createXml();
        xml->writeToFile(output, "");
        delete xml;
        
    }
    
    void load(File file) {
        ScopedPointer<XmlElement> xml = XmlDocument(file).getDocumentElement();
        ValueTree v = ValueTree::fromXml(*xml.get());
        xml = nullptr;
        config->setConfig(v);
        setName(config->getName());
    }
    
    void clear() {
        projectAudio.clear();
    }
    
    void addAudioFile(String id, String path) {
        projectAudio.insert(make_pair(id, path));
    }
    
    static long DEFAULT_TRACK_LENGTH;
    static int  DEFAULT_TRACK_HEIGHT;
    static float DEFAULT_TEMPO;
    
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
    float tempo = DEFAULT_TEMPO;
    
    map<String, String> projectAudio;
    
    ProjectConfig* config = NULL;
    
};



#endif  // PROJECT_H_INCLUDED
