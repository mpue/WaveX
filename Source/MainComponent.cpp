/*
 ==============================================================================
 
 This file was auto-generated!
 
 ==============================================================================
 */

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include <iostream>
#include "TrackNavigator.h"
#include "TrackPropertyView.h"
#include "PositionMarker.h"
#include "WaveSelector.h"
#include "TimeLine.h"
#include "MixerPanel.h"
#include "Project.h"
#include "Session.h"
#include "Mixer.h"
#include "SequenceEditor.h"

//==============================================================================
/*
 This component lives inside our window, and this is where you should put all
 your controls and content.
 */
class MainContentComponent : public AudioAppComponent,
public AudioProcessorPlayer,
public MenuBarModel,
public ChangeListener,
public ChangeBroadcaster,
public TimeSliceClient,
public Timer {
public:
    //============================================================================
    MainContentComponent(TimeLine* timeLine, TrackPropertyView* trackProperties, MixerPanel* mixer) : thread("main")
    {
        this->zoom = 21.0f;
        
        this->tracklength = Project::getInstance()->getTrackLength();;
        
        this->mixer = mixer;
        this->timeLine = timeLine;
        this->trackProperties = trackProperties;
        
        this->marker = new PositionMarker(tracklength);
        this->navigator = new TrackNavigator(marker,&deviceManager);
        
        this->navigator->setSize(getWidth(), getHeight());
        this->navigator->setBounds(0, 0, getWidth(), getHeight());
        
        // this->marker->setSize(getWidth(), getHeight());
        this->marker->setBounds(0, 0, 2, getHeight());
        
        addAndMakeVisible(navigator);
        // addChildComponent(timeLine);
        addAndMakeVisible(marker);
        
        navigator->addChangeListener(this);
        setWantsKeyboardFocus(true);
        addKeyListener(navigator);
        addMouseListener(navigator,true);
        
        this->navigator->repaint();
        thread.startThread(3);
        // thread.addTimeSliceClient(this);
        
        this->leftShiftPressed = false;
        this->ctrlPressed = false;
        this->masterVisible = true;
        
        this->leftVolume = 1.0;
        this->rightVolume = 1.0;
        
        setAudioChannels(2,2);
        
        deviceManager.setMidiInputEnabled("Oxygen 49", true);
        // deviceManager.addMidiInputCallback("Oxygen 49",this);
        // deviceManager.setDefaultMidiOutput("MIDI4x4 Midi Out 1");
        
        apfm = new AudioPluginFormatManager();
        apfm->addDefaultFormats();
        
        this->numSamples = 0;
        
        setupIO(2,2);
        
        startTimer(50);
        
    }
    
    ~MainContentComponent()
    {
        /*
         for (int i = 0; i < navigator->getTracks().size();i++) {
         navigator->getTracks().at(i)->getBuffer()->clear();
         }
         */
        
        for (std::vector<AudioSampleBuffer*>::iterator it = outputBuffers.begin(); it != outputBuffers.end(); ++it) {
            delete *it;
        }
        
        
        shutdownAudio();
        // readerSource = nullptr;
        navigator = nullptr;
        marker = nullptr;
        timeLine = nullptr;
        buffer = nullptr;
        apfm = nullptr;
        
    }
    
    void setupIO() {
        juce::BigInteger activeInputChannels = deviceManager.getCurrentAudioDevice()->getActiveInputChannels();
        juce::BigInteger activeOutputChannels = deviceManager.getCurrentAudioDevice()->getActiveOutputChannels();
        
        int numInputChannels = deviceManager.getCurrentAudioDevice()->getInputChannelNames().size();
        int numOutputChannels = deviceManager.getCurrentAudioDevice()->getOutputChannelNames().size();
        
        int numActiveHostInputs = getNumActiveChannels(activeInputChannels.toInteger());
        int numActiveHostOutputs = getNumActiveChannels(activeOutputChannels.toInteger());
        
        int requestedInputChannelSize = numActiveHostInputs;
        int requestedOutputChannelSize = numActiveHostOutputs;
        
        /*
         for (std::vector<AudioSampleBuffer*>::iterator it = outputBuffers.begin(); it != outputBuffers.end(); ++it) {
         delete *it;
         }
         */
        
        AudioDeviceManager::AudioDeviceSetup config;
        deviceManager.getAudioDeviceSetup (config);
        
        config.useDefaultInputChannels = false;
        config.useDefaultOutputChannels = false;
        config.inputChannels.setRange(0, numInputChannels, true);
        config.outputChannels.setRange(0, numOutputChannels, true);
        
        
        String error = deviceManager.setAudioDeviceSetup(config,true);
        
        setAudioChannels(numInputChannels, numOutputChannels);
        
        activeInputChannels = deviceManager.getCurrentAudioDevice()->getActiveInputChannels();
        activeOutputChannels = deviceManager.getCurrentAudioDevice()->getActiveOutputChannels();
        
        numActiveHostInputs = getNumActiveChannels(activeInputChannels.toInteger());
        numActiveHostOutputs = getNumActiveChannels(activeOutputChannels.toInteger());
        
        if (error != "") {
            Logger::getCurrentLogger()->writeToLog(error);
        }
        else {
            Logger::getCurrentLogger()->writeToLog("Initialized audio device with " + String(numActiveHostInputs) + " inputs and " + String(numActiveHostInputs) + " outputs.");
        }
        
        for (std::vector<AudioSampleBuffer*>::iterator it = outputBuffers.begin(); it != outputBuffers.end(); ++it) {
            delete *it;
        }
        
        outputBuffers.clear();
        
        for (int i = 0; i < numOutputChannels;i++) { // Only Stereo channels for the moment
            AudioSampleBuffer* buffer = new AudioSampleBuffer(1,this->buffersize);
            buffer->clear(0, this->buffersize);
            outputBuffers.push_back(buffer);
        }
        
    }
    
    void setupIO(int inchannels, int outchannels) {
        juce::BigInteger activeInputChannels = deviceManager.getCurrentAudioDevice()->getActiveInputChannels();
        juce::BigInteger activeOutputChannels = deviceManager.getCurrentAudioDevice()->getActiveOutputChannels();
        
        int numInputChannels = deviceManager.getCurrentAudioDevice()->getInputChannelNames().size();
        int numOutputChannels = deviceManager.getCurrentAudioDevice()->getOutputChannelNames().size();
        
        int numActiveHostInputs = getNumActiveChannels(activeInputChannels.toInteger());
        int numActiveHostOutputs = getNumActiveChannels(activeOutputChannels.toInteger());
        
        int requestedInputChannelSize = inchannels;
        int requestedOutputChannelSize = outchannels;
        
        
        AudioDeviceManager::AudioDeviceSetup config;
        deviceManager.getAudioDeviceSetup (config);
        
        config.useDefaultInputChannels = false;
        config.useDefaultOutputChannels = false;
        config.inputChannels.setRange(0, inchannels, true);
        config.outputChannels.setRange(0, outchannels, true);
        
        
        String error = deviceManager.setAudioDeviceSetup(config,true);
        
        setAudioChannels(numInputChannels, numOutputChannels);
        
        activeInputChannels = deviceManager.getCurrentAudioDevice()->getActiveInputChannels();
        activeOutputChannels = deviceManager.getCurrentAudioDevice()->getActiveOutputChannels();
        
        numActiveHostInputs = getNumActiveChannels(activeInputChannels.toInteger());
        numActiveHostOutputs = getNumActiveChannels(activeOutputChannels.toInteger());
        
        if (error != "") {
            Logger::getCurrentLogger()->writeToLog(error);
        }
        else {
            Logger::getCurrentLogger()->writeToLog("Initialized audio device with " + String(numActiveHostInputs) + " inputs and " + String(numActiveHostInputs) + " outputs.");
        }
        
        for (std::vector<AudioSampleBuffer*>::iterator it = outputBuffers.begin(); it != outputBuffers.end(); ++it) {
            delete *it;
        }
        outputBuffers.clear();
        
        for (int i = 0; i < numOutputChannels;i++) { // Only Stereo channels for the moment
            AudioSampleBuffer* buffer = new AudioSampleBuffer(1,this->buffersize);
            buffer->clear(0, this->buffersize);
            outputBuffers.push_back(buffer);
        }
        
    }
    
    
    void timerCallback() override {
        
        trackProperties->timerCallback();
        
        for (int i = 0; i < navigator->getTracks().size();i++) {
            
            Track* t = navigator->getTracks().at(i);
            
            if (i < mixer->getChannels().size()) {
                mixer->getChannels().at(i)->setMagnitude(0,t->getMagnitude(0));
                mixer->getChannels().at(i)->setMagnitude(1,t->getMagnitude(1));
            }
            
        }
        
        mixer->setMasterVolume(0, magnitudeLeft);
        mixer->setMasterVolume(1, magnitudeRight);
        
        repaint();
    }
    
    int useTimeSlice() override {
        return 1000;
    }
    
    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override {
        
        this->sampleRate = sampleRate;
        this->buffersize = samplesPerBlockExpected;
        
        deviceManager.addAudioCallback (this);
        deviceManager.addMidiInputCallback (String(),this);
        
        this->buffer = new AudioSampleBuffer(2,this->buffersize);
        this->buffer->clear(0, this->buffersize);
        
        Project::getInstance()->setSampleRate(sampleRate);
        Project::getInstance()->setBufferSize(buffersize);
        
        Mixer::getInstance()->setAvailableInputChannelNames(deviceManager.getCurrentAudioDevice()->getInputChannelNames());
        Mixer::getInstance()->setAvailableOutputChannelNames(deviceManager.getCurrentAudioDevice()->getOutputChannelNames());

        Mixer::getInstance()->clearMidiInputs();
        Mixer::getInstance()->clearMidiOutputs();

        StringArray midiInputDevices = MidiInput::getDevices();
        
        for (int i = 0; i < midiInputDevices.size();i++) {
            if (deviceManager.isMidiInputEnabled(midiInputDevices.getReference(i))) {
                Mixer::getInstance()->addMidiInput(midiInputDevices.getReference(i));
            }
        }

        StringArray midiOutputDevices = MidiOutput::getDevices();
        
        for (int i = 0; i < midiOutputDevices.size();i++) {
            Mixer::getInstance()->addMidiOutput(midiOutputDevices.getReference(i));
        }

    }
    
    virtual void audioDeviceIOCallback (const float** inputChannelData,
                                        int numInputChannels,
                                        float** outputChannelData,
                                        int numOutputChannels,
                                        int _numSamples) override {
        
        
        if (plugin != NULL) {
            
            if (navigator->getTracks().size() == 1) {
                
                // plugin->processBlock(*buffer, navigator->getTracks().at(0)->get);
                
                AudioSampleBuffer* outL = outputBuffers.at(navigator->getTracks().at(0)->getOutputChannels()[0]);
                AudioSampleBuffer* outR = outputBuffers.at(navigator->getTracks().at(0)->getOutputChannels()[1]);
                
                double pan = navigator->getTracks().at(0)->getPan();
                
                float gainLeft = cos((M_PI*(pan + 1) / 4));
                float gainRight = sin((M_PI*(pan + 1) / 4));
                
                for (int j = 0; j <  _numSamples;j++) {
                    
                    float sampleL = buffer->getSample(0, j) * navigator->getTracks().at(0)->getVolume() * gainLeft;
                    float sampleR = buffer->getSample(1, j) * navigator->getTracks().at(0)->getVolume() * gainRight;
                    
                    outL->addSample(0, j, sampleL);
                    outR->addSample(0, j, sampleR);
                    
                }

                navigator->getTracks().at(0)->updateMagnitude(0, _numSamples, gainLeft, gainRight);
            }
            
            buffer->clear();
            
        }
        
        if (navigator->isPlaying()) {
            
            for (int i = 0; i < navigator->getTracks().size();i++) {
            
                Track* t = navigator->getTracks().at(i);
                
                if (t->getType() == Track::Type::AUDIO) {
                    AudioSampleBuffer* outL = outputBuffers.at(t->getOutputChannels()[0]);
                    AudioSampleBuffer* outR = outputBuffers.at(t->getOutputChannels()[1]);
                    
                    double pan = t->getPan();
                    
                    float gainLeft = cos((M_PI*(pan + 1) / 4));
                    float gainRight = sin((M_PI*(pan + 1) / 4));
                    
                    for (int j = numSamples; j < numSamples + _numSamples;j++) {
                        
                        float sampleL = t->getSample(0, j) * t->getVolume() * gainLeft;
                        float sampleR = t->getSample(1, j) * t->getVolume() * gainRight;
                        
                        outL->addSample(0, j%this->buffersize, sampleL);
                        outR->addSample(0, j%this->buffersize, sampleR);
                        
                    }
                    
                    t->setOffset(numSamples);
                    t->updateMagnitude(numSamples, _numSamples, gainLeft, gainRight);
                    
                }
                else if (t->getType() == Track::Type::MIDI) {
                    
                    double seconds = Time::getMillisecondCounterHiRes() * 0.001 ;
                    double time = seconds - Session::getInstance()->getRecordingStartTime();

                    MidiMessage* m = t->getMessage(time, numSamples);
                    
                    
                    if (m != NULL) {
                        deviceManager.getDefaultMidiOutput()->sendMessageNow(*m);
                    }
                    else {
                        m = new MidiMessage();
                        m->allNotesOff(t->getMidiChannel());
                        deviceManager.getDefaultMidiOutput()->sendMessageNow(*m);
                    }
                }

                
            }
            
            
            numSamples += _numSamples;
            navigator->setPosition(numSamples / this->sampleRate);
            
            
        }
        else if (navigator->isRecording()){
            
            for (int i = 0; i < navigator->getTracks().size();i++) {
                
                Track* t = navigator->getTracks().at(i);
                
                if (t->getType() == Track::Type::AUDIO) {
                    
                    AudioSampleBuffer* outL = outputBuffers.at(navigator->getTracks().at(i)->getOutputChannels()[0]);
                    AudioSampleBuffer* outR = outputBuffers.at(navigator->getTracks().at(i)->getOutputChannels()[1]);
                    
                    double pan = navigator->getTracks().at(i)->getPan();
                    
                    float gainLeft = cos((M_PI*(pan + 1) / 4));
                    float gainRight = sin((M_PI*(pan + 1) / 4));
                    
                    for (int j = numSamples; j < numSamples + _numSamples;j++) {
                        
                        if (t->isRecording()) {
                            t->getRecordingBuffer()->addSample(0, j,inputChannelData[t->getInputChannels()[0]][j%this->buffersize] * leftVolume * gainLeft);
                            t->getRecordingBuffer()->addSample(1, j,inputChannelData[t->getInputChannels()[1]][j%this->buffersize] * rightVolume * gainRight);
                        }
                    }
                    
                    for (int j = 0; j < _numSamples;j++) {
                        outL->copyFrom(0, numSamples % this->buffersize, *t->getRecordingBuffer(), 0, numSamples , _numSamples);
                        outR->copyFrom(0, numSamples % this->buffersize, *t->getRecordingBuffer(), 1, numSamples , _numSamples);
                        
                    }
                    
                    if (t->isRecording()) {
                        AudioRegion* region = static_cast<AudioRegion*>(t->getCurrentRecorder());
                        region->getThumbnail()->addBlock(numSamples,  *t->getRecordingBuffer(),numSamples,_numSamples);
                    }
                    
                    t->updateMagnitude(numSamples, _numSamples, gainLeft, gainRight);
                    t->setOffset(numSamples);
                }
                else if (t->getType() == Track::Type::MIDI) {
                    
                    double seconds = Time::getMillisecondCounterHiRes() * 0.001 ;
                    double time = seconds - Session::getInstance()->getRecordingStartTime();
                    
                    MidiMessage* m = t->getMessage(time, numSamples);
                    
                    if (m != NULL) {
                        deviceManager.getDefaultMidiOutput()->sendMessageNow(*m);
                    }
                    else {
                        m = new MidiMessage();
                        m->allNotesOff(t->getMidiChannel());
                        deviceManager.getDefaultMidiOutput()->sendMessageNow(*m);
                    }
                }
                
            }
            
            numSamples += _numSamples;
            navigator->setPosition(numSamples / this->sampleRate);
        }
        else {
            
            for (int i = 0; i < navigator->getTracks().size();i++) {
                
                Track* t = navigator->getTracks().at(i);
                
                AudioSampleBuffer* outL = outputBuffers.at(navigator->getTracks().at(i)->getOutputChannels()[0]);
                AudioSampleBuffer* outR = outputBuffers.at(navigator->getTracks().at(i)->getOutputChannels()[1]);
                
                if (t->isRecording()) {
                    float pan = 0;
                    
                    float gainLeft  = cos((M_PI*(pan + 1) / 4));
                    float gainRight = sin((M_PI*(pan + 1) / 4));
                    
                    for (int j = 0; j < this->buffersize;j++) {
                        outL->addSample(0, j,inputChannelData[t->getInputChannels()[0]][j] * leftVolume * gainLeft);
                        outR->addSample(0, j,inputChannelData[t->getInputChannels()[1]][j] * rightVolume * gainRight);
                    }
                    
                    float magLeftIn  = outL->getMagnitude(0, 0, _numSamples);
                    float magRightIn = outR->getMagnitude(0, 0, _numSamples);
                    
                    navigator->getTracks().at(i)->setMagnitude(0, magLeftIn);
                    navigator->getTracks().at(i)->setMagnitude(1, magRightIn);
                    
                    /*
                     for (int i = 0; i < navigator->getTracks().size();i++) {
                     navigator->getTracks().at(i)->setMagnitude(0, 0);
                     navigator->getTracks().at(i)->setMagnitude(1, 0);
                     }
                     */
                    
                }
                else {
                    navigator->getTracks().at(i)->setMagnitude(0, 0);
                    navigator->getTracks().at(i)->setMagnitude(1, 0);
                }
                
            }
            
        }
        
        for (int i = 0; i < navigator->getTracks().size();i++) {
            
            Track* t = navigator->getTracks().at(i);
            
            AudioSampleBuffer* outL = outputBuffers.at(navigator->getTracks().at(i)->getOutputChannels()[0]);
            AudioSampleBuffer* outR = outputBuffers.at(navigator->getTracks().at(i)->getOutputChannels()[1]);
            
            const float* left = outL->getReadPointer(0);
            const float* right = outR->getReadPointer(0);
            
            for (int sample = 0; sample < outL->getNumSamples(); ++sample) {
                outputChannelData[t->getOutputChannels()[0]][sample] = left[sample] * leftVolume;
                outputChannelData[t->getOutputChannels()[1]][sample] = right[sample] * rightVolume;
            }
            
            this->magnitudeLeft = outL->getMagnitude(0, 0, _numSamples);
            this->magnitudeRight = outR->getMagnitude(0, 0, _numSamples);
            
            this->rmsLeft = outL->getRMSLevel(0, 0,_numSamples);
            this->rmsRight = outR->getRMSLevel(0, 0,_numSamples);
        
            
            // Maybe we can use this later to display the peak at a specific sample point
            /*
             for (int i = 0; i < navigator->getTracks().size();i++) {
             navigator->getTracks().at(i)->updateMagnitude(numSamples, _numSamples);
             }
             */
            
            /*
             if (i == navigator->getTracks().size() - 1) {
             outL->clear();
             outR->clear();
             }
             */
            
        }
        
        if (navigator->getTracks().size() == 0) {
            for (int i = 0; i < numOutputChannels;i++) {
                for (int sample = 0; sample < _numSamples; ++sample) {
                    outputChannelData[i][sample] = 0;
                }
            }
        }
        else {
            for (int i = 0; i < outputBuffers.size();i++) {
                outputBuffers.at(i)->clear();
            }
            
        }

    }
    
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override
    {
        
    }
    
    virtual void handleIncomingMidiMessage (MidiInput* source, const MidiMessage& message) override {
        
        double seconds = Time::getMillisecondCounterHiRes() * 0.001;
        double currentTime = seconds - Session::getInstance()->getRecordingStartTime();
        
        if (navigator->getTracks().size() == 0) {
            return;
        }
        
        if (navigator->isRecording()) {
            
            for (int i = 0; i < navigator->getTracks().size();i++) {
                
                Track* t = navigator->getTracks().at(i);
                
                // check each track if its in record mode and MIDI type
                if (t->getType() == Track::Type::MIDI && t->isRecording()) {
                    MidiMessage* messageToSend = new MidiMessage(message);
                    // adjust channel according to track
                    messageToSend->setChannel(t->getMidiChannel());
                    messageToSend->setTimeStamp(currentTime);
                    // add the message to the track, which will pass the message to the current recording region
                    t->addMessage(messageToSend, currentTime, numSamples);
                    deviceManager.getDefaultMidiOutput()->sendMessageNow(*messageToSend);
                }
            }
            
        }
        else {
            MidiMessage* messageToSend = new MidiMessage(message);
            messageToSend->setChannel(navigator->getCurrentTrack()->getMidiChannel());
            deviceManager.getDefaultMidiOutput()->sendMessageNow(*messageToSend);
        }
        
        /*
        if(win->isVisible()) {
            getMidiMessageCollector().addMessageToQueue(message);
        }        
        else {
            deviceManager.getDefaultMidiOutput()->sendMessageNow(message);
        }
         */
        
    }
    
    void releaseResources() override
    {
    }
    
    //==============================================================================
    void paint (Graphics& g) override
    {
        // (Our component is opaque, so we must completely fill the background with a solid colour)
        g.fillAll (Colours::grey);
        
    }
    
    
    void resized() override
    {
    }
    
    double getRms(int channel) {
        if (channel == 0)
            return this->rmsLeft;
        else
            return this->rmsRight;
    }
    
    double getMagnitude(int channel) {
        if (channel == 0)
            return this->magnitudeLeft;
        else
            return this->magnitudeRight;
    }
    
    bool isMasterVisible() {
        return this->masterVisible;
    }
    
    void setVolume(int channel, float volume) {
        if (channel == 0) {
            leftVolume = volume;
        }
        else {
            rightVolume = volume;
        }
    }
    
    void setPosition(long sample) {
        this->numSamples = sample;
    }
    
    TrackNavigator* getNavigator() {
        return this->navigator;
    }
    
    PositionMarker* getMarker() {
        return this->marker;
    }
    
    void addPlugin(String name) {
        
        if (plugin == nullptr) {
            String error = String("Error");
            PluginDescription pd;
            
            File preset = File("/Users/mpue/plugins/"+name);
            ScopedPointer<XmlElement> xml = XmlDocument(preset).getDocumentElement();
            pd.loadFromXml(*xml.get());
            
            plugin = apfm->createPluginInstance(pd, sampleRate, buffersize,error);
            plugin->prepareToPlay(sampleRate, buffersize);
            AudioProcessorEditor* editor = plugin->createEditorIfNeeded();
            
            juce::AudioProcessor::BusesLayout layout =  plugin->getBusesLayout();
            
            int numPluginInputs = plugin->getBusCount(true) * 2;
            int numPluginOutputs = plugin->getBusCount(false) * 2;
            
            // check input and output bus configuration
            
            juce::BigInteger activeInputChannels = deviceManager.getCurrentAudioDevice()->getActiveInputChannels();
            juce::BigInteger activeOutputChannels = deviceManager.getCurrentAudioDevice()->getActiveOutputChannels();
            
            int numInputChannels = deviceManager.getCurrentAudioDevice()->getInputChannelNames().size();
            int numOutputChannels = deviceManager.getCurrentAudioDevice()->getOutputChannelNames().size();
            
            int numActiveHostInputs = getNumActiveChannels(activeInputChannels.toInteger());
            int numActiveHostOutputs = getNumActiveChannels(activeOutputChannels.toInteger());
            
            int requestedInputChannelSize = numActiveHostInputs;
            int requestedOutputChannelSize = numActiveHostOutputs;
            
            // we have a problem if a plugin has more inputs and outputs that are active
            // try to set the num of inputs/ouputs accordingly, if this fails we are fucked anyway
            
            if (numPluginInputs > numActiveHostInputs) {
                requestedInputChannelSize = numPluginInputs;
            }
            if (numPluginOutputs > numActiveHostOutputs) {
                requestedOutputChannelSize = numPluginOutputs;
            }
            
            setAudioChannels(requestedInputChannelSize, requestedOutputChannelSize);
            
            Logger::getCurrentLogger()->writeToLog("Active output channels "+String(numActiveHostOutputs));
            Logger::getCurrentLogger()->writeToLog("Active input channels "+String(numActiveHostInputs));
            
            setProcessor(plugin);
            
            win = new PluginWindow(name,editor);
        }
        
        
        win->setVisible(true);
    }
    
    int getNumActiveChannels(int i) {
        i = i - ((i >> 1) & 0x55555555);
        i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
        return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
    }
    
    void scanPlugins() {
        /*
         AudioPluginFormatManager apfm;
         apfm.addDefaultFormats();
         
         for (int i = 0; i < apfm.getNumFormats();i++) {
         AudioPluginFormat* format = apfm.getFormat(i);
         Logger::getCurrentLogger()->writeToLog(format->getName());
         
         KnownPluginList *pluginList = new KnownPluginList();
         
         FileSearchPath* path = new FileSearchPath("/Users/mpue/Library/Audio/Plug-Ins/Components/");
         
         PluginDirectoryScanner* scanner = new PluginDirectoryScanner(*pluginList,*apfm.getFormat(0),*path,false,File(),false);
         
         String name;
         
         while(scanner->scanNextFile(false, name) != false) {
         Logger::getCurrentLogger()->writeToLog("Found plugin : "+name);
         }
         
         
         delete scanner;
         delete path;
         delete pluginList;
         
         }
         */
        
        AudioPluginFormatManager* apfm = new AudioPluginFormatManager();
        apfm->addDefaultFormats();
        
        KnownPluginList *pluginList = new KnownPluginList();
        PropertiesFile::Options options;
        File file = File("/Users/mpue/plugin.properties");
        PropertiesFile* props = new PropertiesFile(file,options);
        
        PluginListComponent* pluginListComponent = new PluginListComponent(*apfm,*pluginList,File(), props);
        
        DialogWindow::LaunchOptions launchOptions;
        launchOptions.dialogTitle = ("Manage Plugins");
        launchOptions.escapeKeyTriggersCloseButton = true;
        launchOptions.resizable = true;
        launchOptions.useNativeTitleBar = true;
        launchOptions.useBottomRightCornerResizer = true;
        launchOptions.componentToCentreAround = this->getParentComponent()->getParentComponent()->getParentComponent();
        launchOptions.content.setOwned(pluginListComponent);
        launchOptions.content->setSize(600, 580);
        launchOptions.runModal();
        
        for (int i = 0; i < pluginList->getNumTypes();i++) {
            pluginList->getType(i)->createXml()->writeToFile(File("/Users/mpue/plugins/"+pluginList->getType(i)->name),"");
        }
        
    }
    
    void importAudio() {
        
        FileChooser chooser("Select a file to add...", File::nonexistent, "*");
        
        if (chooser.browseForFileToOpen()) {
            File file = chooser.getResult();
            
            if (file.getFileExtension() == ".wav" || file.getFileExtension() == ".aif" || file.getFileExtension() == ".mp3") {
                navigator->getCurrentTrack()->addRegion(file.getFileNameWithoutExtension(),file, this->sampleRate);
                Project::getInstance()->addAudioFile(file.getFileNameWithoutExtension(), file.getFullPathName());
            }
        
        }
        
    }
    
    void removeSelectedTrack() {
        navigator->removeSelectedTrack();
    }
    
    void addTrack(Track::Type type) {
        Track* t = navigator->addTrack(type, this->sampleRate);
        mixer->addTrack(t);
        trackProperties->addTrack(t);
    }
    
    void openStepSequencer() {
        
        SequenceEditor* sequenceEditor = new SequenceEditor();
        sequenceEditor->setMouseClickGrabsKeyboardFocus(true);
        sequenceEditor->setDeviceManager(&deviceManager);
        
        Viewport* view = new Viewport();
        
        view->setSize(500,208);
        view->setViewedComponent(sequenceEditor);
        view->setScrollBarsShown(true,true);
        view->setScrollOnDragEnabled(true);
        view->setWantsKeyboardFocus(false);
        view->setMouseClickGrabsKeyboardFocus(false);
        
        DialogWindow::LaunchOptions launchOptions;
        launchOptions.dialogTitle = ("Step sequencer");
        launchOptions.escapeKeyTriggersCloseButton = true;
        launchOptions.resizable = true;
        launchOptions.useNativeTitleBar = false;
        launchOptions.useBottomRightCornerResizer = true;
        launchOptions.componentToCentreAround = this->getParentComponent()->getParentComponent()->getParentComponent();
        launchOptions.content.setOwned(view);
        launchOptions.content->setSize(500, 280);
        launchOptions.runModal();
        
    }
    
    void openSettings() {
        AudioDeviceSelectorComponent* selector = new AudioDeviceSelectorComponent(deviceManager, 2, 16, 2, 16, true, true, true, false);
        selector->setLookAndFeel(Session::getInstance()->getLookAndFeel());
        
        DialogWindow::LaunchOptions launchOptions;
        launchOptions.dialogTitle = ("Audio Settings");
        launchOptions.escapeKeyTriggersCloseButton = true;
        launchOptions.resizable = true;
        launchOptions.useNativeTitleBar = false;
        launchOptions.useBottomRightCornerResizer = true;
        launchOptions.componentToCentreAround = this->getParentComponent()->getParentComponent()->getParentComponent();
        launchOptions.content.setOwned(selector);
        launchOptions.content->setSize(600, 580);
        launchOptions.runModal();
        
        // setupIO();
    }
    
    void setTracklength(long length) {
        this->tracklength = length;
    }
    
    long getTrackLength( ) {
        return tracklength;
    }
    
private:
    //==============================================================================
    
    class PluginWindow    : public DocumentWindow
    {
    public:
        PluginWindow (String name, AudioProcessorEditor* editor)  : DocumentWindow (name,
                                                                                    Colours::lightgrey,
                                                                                    DocumentWindow::allButtons)
        {
            setUsingNativeTitleBar(true);
            this->plugin = editor;
            setContentOwned (editor, true);
            setAlwaysOnTop(true);
            setResizable (true, true);
            centreWithSize(editor->getWidth(),editor->getHeight()+25);
            setVisible (true);
            
        }
        
        ~PluginWindow() {
            plugin = nullptr;
        }
        
        void closeButtonPressed() override
        {
            this->setVisible(false);
        }
        
    private:
        ScopedPointer<AudioProcessorEditor> plugin;
    };
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainContentComponent)
    
    ScopedPointer<AudioPluginFormatManager> apfm;
    ScopedPointer<AudioPluginInstance> plugin = nullptr;
    AudioProcessorPlayer* player;
    
    MidiMessageSequence midiSequence;
    
    vector<AudioSampleBuffer*> outputBuffers;
    
    ScopedPointer<AudioSampleBuffer> buffer;
    ScopedPointer<PluginWindow> win = nullptr;
    
    
    TimeSliceThread thread;
    ScopedPointer<TrackNavigator> navigator;
    ScopedPointer<PositionMarker> marker;
    ScopedPointer<TimeLine> timeLine;
    MixerPanel* mixer;
    TrackPropertyView* trackProperties;
    
    // track length in seconds
    long tracklength = 0;
    
    long numSamples = 0;
    double sampleRate = 0;
    
    int buffersize = 0;
    
    bool ctrlPressed;
    bool leftShiftPressed;
    double rmsLeft;
    double rmsRight;
    double magnitudeLeft = 0;
    double magnitudeRight = 0;
    bool masterVisible;
    
    float leftVolume;
    float rightVolume;
    
    float zoom;
    
    
    
    vector<String> availableInstruments;
    
    virtual StringArray getMenuBarNames() override
    {
        const char* const names[] = { "File", "View", "Plugins", nullptr };
        
        return StringArray(names);
        
    }
    
    virtual void buildPluginMenu(PopupMenu &menu) {
        String appDataPath = File::getSpecialLocation(File::userApplicationDataDirectory).getFullPathName();
        String presetPath = "/Users/mpue/plugins";
        
        File presets = File(presetPath);
        
        int index = 100;
        
        if(presets.exists() && presets.isDirectory()) {
            ScopedPointer<DirectoryIterator> iter = new DirectoryIterator(presets, false);
            while(iter->next()) {
                ScopedPointer<XmlElement> xml = XmlDocument(iter->getFile()).getDocumentElement();
                PluginDescription pd;
                pd.loadFromXml(*xml.get());
                
                if (pd.isInstrument) {
                    availableInstruments.push_back(pd.name);
                    menu.addItem(index, pd.name, true, false,nullptr);
                    index++;
                }
                
            }
            iter = nullptr;
            
        }
    }
    
    virtual PopupMenu getMenuForIndex(int index, const String & menuName) override
    {
        PopupMenu menu;
        
        if (index == 0) {
            menu.addItem(11, "New project", true, false, nullptr);
            menu.addItem(9, "Load project", true, false, nullptr);
            menu.addItem(10, "Save project as", true, false, nullptr);
            menu.addItem(1, "Add track", true, false, nullptr);
            menu.addItem(12, "Remove track", true, false, nullptr);
            menu.addItem(2, "Play/Stop", true, false, nullptr);
            menu.addItem(7, "Settings", true, false, nullptr);
            menu.addItem(3, "Exit", true, false, nullptr);
        }
        else if (index == 1) {
            menu.addItem(4, "Show/hide master", true, false, nullptr);
            menu.addItem(5, "Zoom in", true, false, nullptr);
            menu.addItem(6, "Zoom out", true, false, nullptr);
            menu.addItem(8, "Manage Plugins", true, false, nullptr);
            menu.addItem(13, "Step sequencer", true, false, nullptr);
        }
        else if (index == 2) {
            buildPluginMenu(menu);
        }
        
        return menu;
    }
    
    
    
    virtual void menuItemSelected(int menuItemID, int topLevelMenuIndex) override
    {
        if (menuItemID == 1) {
            addTrack(Track::Type::AUDIO);
        }
        else if (menuItemID == 2) {
            if (navigator->isPlaying())
            {
                navigator->setPlaying(false);
            }
            else
            {
                // transportSource.setPosition(0);
                navigator->setPlaying(true);
            }
        }
        else if (menuItemID == 3) {
            JUCEApplication::getInstance()->shutdown();
        }
        else if (menuItemID == 4) {
            this->masterVisible = !this->masterVisible;
            sendChangeMessage();
        }
        else if(menuItemID == 5) {
            if (navigator->getMaxLength() == 0) {
                return;
            }
            
            this->zoom += 20;
            // setSize(navigator->getMaxLength() * this->zoom, getHeight());
            navigator->setZoom(zoom);
        }
        else if(menuItemID == 6) {
            if (navigator->getMaxLength()== 0) {
                return;
            }
            if (this->zoom - 20 >= 1)
                this->zoom -= 20;
            
            // setSize(navigator->getMaxLength() * this->zoom, getHeight());
            navigator->setZoom(zoom);
        }
        else if (menuItemID == 7) {
            openSettings();
        }
        else if (menuItemID == 8) {
            scanPlugins();
        }
        else if (menuItemID == 9) {
            FileChooser chooser("Select project file...", File::nonexistent, "*.xml");
            
            if (chooser.browseForFileToOpen()) {
                Project::getInstance()->getConfig()->getTracks().clear();
                File file = chooser.getResult();
                Project::getInstance()->load(file);
                
                vector<TrackConfig*> _tracks = Project::getInstance()->getConfig()->getTracks();
                vector<AudioClip*> clips = Project::getInstance()->getConfig()->getAudioClips();
                // Project::getInstance()->getConfig()->getAudioClips();
                // Project::getInstance()->getConfig()->
                
                Logger::getCurrentLogger()->writeToLog("Found "+ String(_tracks.size())+" track(s).");
                
                int num = 0;
                
                for (int i = 0; i < _tracks.size();i++) {
                    TrackConfig* tc = _tracks.at(i);
                    Logger::getCurrentLogger()->writeToLog("Trying to add track "+tc->getName());
                    
                    Track* t = navigator->addTrack(tc);
                    mixer->addTrack(t);
                    trackProperties->addTrack(t);
                    
                    for (int j = 0; j < tc->getRegions().size();j++) {
                        
                        AudioClip* c = tc->getRegions().at(j)->getAudioClip();
                        
                        for (int k = 0; k < clips.size();k++ ) {
                            if (c->getRefId() == clips.at(k)->getRefId()) {
                                
                                Logger::getCurrentLogger()->writeToLog("Adding region : "+c->getName()+ " at offset "+String(c->getOffset()));
                                
                                t->addRegion(c->getRefId(), File(clips.at(k)->getName()), Project::getInstance()->getSampleRate(),c->getOffset(),c->getLength());
                                
                                // t->addRegion(c->getRefId(), File(clips.at(k)->getName()), Project::getInstance()->getSampleRate());
                            }
                        }
                        
                    }
                    
                    num++;
                }
        
            }
            
        }
        else if (menuItemID == 10) {
            FileChooser chooser("Select target file...", File::nonexistent, "*");
            
            if (chooser.browseForFileToSave(true)) {
                
                Project::getInstance()->getConfig()->getTracks().clear();
                
                for (int i = 0; i < navigator->getTracks().size();i++) {
                    Track* t = navigator->getTracks().at(i);
                    TrackConfig* tc = new TrackConfig();
                    tc->setName(t->getName());
                    tc->setPan(t->getPan());
                    tc->setGain(t->getGain());
                    tc->setVolume(t->getVolume());
                    tc->setMono(t->isMono());
                    tc->setMute(t->isMute());
                    tc->setSolo(t->isSolo());
                    tc->setHeight(t->getHeight());
                    
                    if (t->getType() == Track::Type::AUDIO)
                        tc->setType("audio");
                    else if (t->getType() == Track::Type::MIDI)
                        tc->setType("midi");
                    
                    for (int j = 0; j < t->getRegions().size();j++) {
                        Region* r = t->getRegions().at(j);
                        RegionConfig* rc = new RegionConfig();
                        AudioClip* ac = new AudioClip();
                        ac->setName(r->getName());
                        
                        if (AudioRegion* ar = dynamic_cast<AudioRegion*>(r)) {
                            ac->setRefId(ar->getClipRefid());
                        }
                        
                        ac->setLength(r->getNumSamples());
                        ac->setOffset(r->getSampleOffset());
                        rc->setAudioClip(ac);
                        tc->addRegion(rc);
                    }
                    
                    Project::getInstance()->getConfig()->addTrack(tc);
                }
                
                File file = chooser.getResult();
                Project::getInstance()->save(file);
            }
            
        }
        else if (menuItemID == 11) {
            Project::getInstance()->getConfig()->getTracks().clear();
            navigator->clearTracks();
            navigator->setSize(getWidth(), getHeight());
            navigator->setBounds(0, 0, getWidth(), getHeight());
            trackProperties->clearTracks();
            mixer->clearTracks();
            Mixer::getInstance()->clearTracks();
            
            
        }
        else if (menuItemID == 12) {
            removeSelectedTrack();
        }
        else if (menuItemID == 13) {
            openStepSequencer();
        }

        else if (menuItemID >= 100) {
            addPlugin(availableInstruments.at(menuItemID - 100));
        }
        
    }
    
    virtual void changeListenerCallback(ChangeBroadcaster * source) override
    {
        if (source == navigator || source == Project::getInstance())
        {
            long trackLength = Project::getInstance()->getTrackLength();
            
            // we need to snap the position on a multiple of the block size, to prevent the buffer being accessed in a odd way
            // because this leads to a broken audio stream
            
            this->numSamples = navigator->getPosition() * this->sampleRate - ((long)(navigator->getPosition() * this->sampleRate) % this->buffersize) ;
            
            // marker->setPosition(navigator->getPosition());
            
            this->zoom = navigator->getZoom();
            int newWidth = trackLength * this->zoom;
            
            if (getHeight() < navigator->getTracks().size() * 200)
                setSize(newWidth, navigator->getTracks().size() * 200);
            else {
                setSize(newWidth, getHeight());
            }
            
            if (navigator->getTracks().size() == 0) {
                this->timeLine->setVisible(false);
            }
            else {
                this->timeLine->setVisible(true);
                this->timeLine->setLength(trackLength);
                this->timeLine->setSize(trackLength * zoom, 25);
            }

            this->marker->setDrawingBounds(0,0,navigator->getWidth(),getHeight());
            this->marker->setSize(navigator->getWidth(), getHeight());
            
            repaint();
            
            if (!navigator->isPlaying()) {
                for (int i = 0; i < navigator->getTracks().size();i++) {
                    
                    Track* t = navigator->getTracks().at(i);
                    
                    if (t->isSelected() && t->getType() == Track::Type::MIDI){
                    
                        if (deviceManager.isMidiInputEnabled(t->getMidiInputDevice())) {
                            deviceManager.addMidiInputCallback(t->getMidiInputDevice(),this);
                        }
                        if (t->getMidiOutputDevice() != "") {
                            deviceManager.setDefaultMidiOutput(t->getMidiOutputDevice());
                        }
                    }
                    
                    MidiMessage m;
                    
                    if (deviceManager.getDefaultMidiOutput() != nullptr) {
                        deviceManager.getDefaultMidiOutput()->sendMessageNow(m.allNotesOff(t->getMidiChannel()));
                    }
                }
            }
        }
    }
    
};

#endif  // MAINCOMPONENT_H_INCLUDED
