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

using namespace std;
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
                             public TimeSliceClient

{
public:
    //============================================================================
    MainContentComponent(TimeLine* timeLine, TrackPropertyView* trackProperties) : thread("main")
    {		
        this->zoom = 21.0f;

		this->timeLine = timeLine;
		this->trackProperties = trackProperties;

		this->marker = new PositionMarker(600);
        this->navigator = new TrackNavigator(marker);

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
        //thread.addTimeSliceClient(this);

        this->leftShiftPressed = false;
        this->ctrlPressed = false;
        this->masterVisible = true;
    
        this->leftVolume = 1.0;
        this->rightVolume = 1.0;
        
        setAudioChannels(0,2);
        
        deviceManager.setMidiInputEnabled("MPKmini2", true);
        deviceManager.addMidiInputCallback("MPKmini2",this);
    
        
		this->numSamples = 0;
    }

    ~MainContentComponent()
    {
		/*
        for (int i = 0; i < navigator->getTracks().size();i++) {
            navigator->getTracks().at(i)->getBuffer()->clear();
        }
		*/

        
        shutdownAudio();
		// readerSource = nullptr;
        navigator = nullptr;
        marker = nullptr;
		timeLine = nullptr;
        delete buffer;
        delete win;
    
    }
    
    int useTimeSlice() override {
        if (navigator->isPlaying())
            sendChangeMessage();
        return 70;
    }

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override
    {
        // This function will be called when the audio device is started, or when
        // its settings (i.e. sample rate, block size, etc) are changed.

        // You can use this function to initialise any resources you might need,
        // but be careful - it will be called on the audio thread, not the GUI thread.

        // For more details, see the help for AudioProcessor::prepareToPlay()
        this->sampleRate = sampleRate;
        this->buffersize = samplesPerBlockExpected;
        
        deviceManager.addAudioCallback (this);
        deviceManager.addMidiInputCallback (String(),this);
        
        this->buffer = new AudioSampleBuffer(2,this->buffersize);
        this->buffer->clear(0, this->buffersize);

    }
    
    virtual void audioDeviceIOCallback (const float** inputChannelData,
                                        int numInputChannels,
                                        float** outputChannelData,
                                        int numOutputChannels,
                                        int _numSamples) override {
        
        if (plugin != NULL)
            plugin->processBlock(*buffer, midiBuffer);
        
        if (navigator->isPlaying()) {
            
            // AudioProcessorPlayer::audioDeviceIOCallback(inputChannelData, numInputChannels, outputChannelData, numOutputChannels, _numSamples);
            
            for (int i = 0; i < navigator->getTracks().size();i++) {
                for (int j = numSamples; j < numSamples + _numSamples;j++) {

                    buffer->addSample(0, j%this->buffersize, navigator->getTracks().at(i)->getSample(0, j) * leftVolume * navigator->getTracks().at(i)->getVolume());
                    buffer->addSample(1, j%this->buffersize, navigator->getTracks().at(i)->getSample(1, j) * rightVolume * navigator->getTracks().at(i)->getVolume());
                }
                navigator->getTracks().at(i)->setOffset(numSamples);
                
                AudioRegion* ar = navigator->getTracks().at(i)->getCurrentRegion(numSamples);
                
                if (ar != NULL) {
                    
                    if (numSamples - ar->getSampleOffset() + this->buffersize < ar->getBuffer()->getNumSamples()) {
                        navigator->getTracks().at(i)->magnitudeLeft  = ar->getBuffer()->getMagnitude(0, numSamples - ar->getSampleOffset() , this->buffersize);
                        navigator->getTracks().at(i)->magnitudeRight = ar->getBuffer()->getMagnitude(1, numSamples - ar->getSampleOffset() , this->buffersize);
                    }
                    else {
                        navigator->getTracks().at(i)->magnitudeLeft = 0;
                        navigator->getTracks().at(i)->magnitudeRight = 0;
                    }
                    
                }
            }
            numSamples += _numSamples;
            navigator->setPosition(numSamples / this->sampleRate);
            

        }
        else {
            
            // AudioProcessorPlayer::audioDeviceIOCallback(inputChannelData, numInputChannels, outputChannelData, numOutputChannels, _numSamples);
            
            /*
            for (int j = 0; j < _numSamples;j++) {
                
                buffer->addSample(0, j,inputChannelData[0][j] * leftVolume);
                buffer->addSample(1, j,inputChannelData[1][j] * rightVolume);
            }
             */
            
            
        }

        
        
        const float* left = buffer->getReadPointer(0);
        const float* right = buffer->getReadPointer(1);
        
        for (int sample = 0; sample < buffer->getNumSamples(); ++sample) {
            outputChannelData[0][sample] = left[sample] * leftVolume;
            outputChannelData[1][sample] = right[sample] * rightVolume;
        }
        
        
        this->magnitudeLeft = buffer->getMagnitude(0, 0, _numSamples);
        this->magnitudeRight = buffer->getMagnitude(1, 0, _numSamples);
        
        this->rmsLeft = buffer->getRMSLevel(0, 0,_numSamples);
        this->rmsRight = buffer->getRMSLevel(1, 0,_numSamples);
        
        buffer->clear();
        
    }
    
    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override
    {
        /*
        bufferToFill.clearActiveBufferRegion();
        
        if (navigator->isPlaying()) {
            for (int i = 0; i < navigator->getTracks().size();i++) {
                for (int j = numSamples; j < numSamples + this->buffersize;j++) {
                    bufferToFill.buffer->addSample(0, j%this->buffersize, navigator->getTracks().at(i)->getSample(0, j) * leftVolume * navigator->getTracks().at(i)->getVolume());
                    bufferToFill.buffer->addSample(1, j%this->buffersize, navigator->getTracks().at(i)->getSample(1, j) * rightVolume * navigator->getTracks().at(i)->getVolume());
                }
				navigator->getTracks().at(i)->setOffset(numSamples);
                
                AudioRegion* ar = navigator->getTracks().at(i)->getCurrentRegion(numSamples);
            
                if (ar != NULL) {
                    
                    if (numSamples - ar->getSampleOffset() + this->buffersize < ar->getBuffer()->getNumSamples()) {
                        navigator->getTracks().at(i)->magnitudeLeft  = ar->getBuffer()->getMagnitude(0, numSamples - ar->getSampleOffset() , this->buffersize);
                        navigator->getTracks().at(i)->magnitudeRight = ar->getBuffer()->getMagnitude(1, numSamples - ar->getSampleOffset() , this->buffersize);
                    }
                    else {
                        navigator->getTracks().at(i)->magnitudeLeft = 0;
                        navigator->getTracks().at(i)->magnitudeRight = 0;
                    }
                    
                }
                
            }
            numSamples += this->buffersize;
            navigator->setPosition(numSamples / this->sampleRate);
            
        }
        else {
            for (int i = 0; i < navigator->getTracks().size();i++) {
                navigator->getTracks().at(i)->magnitudeLeft = 0;
                navigator->getTracks().at(i)->magnitudeRight = 0;
            }
        }
        */
        
        /*
        for (int sample = 0; sample < bufferToFill.buffer->getNumSamples(); ++sample) {
            leftOut[sample] = leftIn[sample] * leftVolume;
            rightOut[sample] = rightIn[sample] * rightVolume;
        }
         */
    
        
    }

    virtual void handleIncomingMidiMessage (MidiInput* source, const MidiMessage& message) override {
        midiBuffer.addEvent(message, numSamples);
        getMidiMessageCollector().addMessageToQueue(message);
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
        
        AudioPluginFormatManager* apfm = new AudioPluginFormatManager();
        apfm->addDefaultFormats();
        
        String error = String("Error");
        PluginDescription pd;
        
        File preset = File("/Users/mpue/plugins/"+name);
        ScopedPointer<XmlElement> xml = XmlDocument(preset).getDocumentElement();
        pd.loadFromXml(*xml.get());
        
        plugin = apfm->createPluginInstance(pd, sampleRate, buffersize,error);
        plugin->prepareToPlay(sampleRate, buffersize);
        AudioProcessorEditor* editor = plugin->createEditorIfNeeded();
        
        juce::AudioProcessor::BusesLayout layout =  plugin->getBusesLayout();
        
        setProcessor(plugin);
        
        
        
        win = new PluginWindow(name,editor);
        win->setVisible(true);
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
        FileChooser chooser("Select a file to add...",
                            File::nonexistent,
                            "*.*");
        
        if (chooser.browseForFileToOpen())
        {
            File file = chooser.getResult();
            navigator->getCurrentTrack()->addRegion(file, this->sampleRate);
            
        }
    }
    
    void addTrack() {
		navigator->addTrack(this->sampleRate);
    }
    
    void openSettings() {
        AudioDeviceSelectorComponent* selector = new AudioDeviceSelectorComponent(deviceManager, 2, 2, 2, 2, true, true, true, false);
        
        DialogWindow::LaunchOptions launchOptions;
        launchOptions.dialogTitle = ("Audio Settings");
        launchOptions.escapeKeyTriggersCloseButton = true;
        launchOptions.resizable = true;
        launchOptions.useNativeTitleBar = true;
        launchOptions.useBottomRightCornerResizer = true;
        launchOptions.componentToCentreAround = this->getParentComponent()->getParentComponent()->getParentComponent();
        launchOptions.content.setOwned(selector);
        launchOptions.content->setSize(600, 580);
        launchOptions.launchAsync();
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
        }

        
    private:
        ScopedPointer<AudioProcessorEditor> plugin;
    };
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainContentComponent)

    AudioPluginInstance* plugin = NULL;
    AudioProcessorPlayer* player;
    AudioSampleBuffer* buffer;
    PluginWindow* win;
    MidiBuffer midiBuffer;
    
	TimeSliceThread thread;
    ScopedPointer<TrackNavigator> navigator;
    ScopedPointer<PositionMarker> marker;
	ScopedPointer<TimeLine> timeLine;
	TrackPropertyView* trackProperties;

    long numSamples = 0;
    double sampleRate = 0;
    
    int buffersize = 0;
    
    bool ctrlPressed;
    bool leftShiftPressed;
    double rmsLeft;
    double rmsRight;
    double magnitudeLeft;
    double magnitudeRight;
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
			menu.addItem(1, "Add track", true, false, nullptr);
			menu.addItem(2, "Play/Stop", true, false, nullptr);
			menu.addItem(7, "Settings", true, false, nullptr);
			menu.addItem(3, "Exit", true, false, nullptr);
		}
        else if (index == 1) {
            menu.addItem(4, "Show/hide master", true, false, nullptr);
            menu.addItem(5, "Zoom in", true, false, nullptr);
            menu.addItem(6, "Zoom out", true, false, nullptr);
            menu.addItem(8, "Manage Plugins", true, false, nullptr);
        }
        else if (index == 2) {
            buildPluginMenu(menu);
        }
        
		return menu;
	}
    

    
	virtual void menuItemSelected(int menuItemID, int topLevelMenuIndex) override
	{
		if (menuItemID == 1) {
            addTrack();
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
            
            this->zoom += 10;
            // setSize(navigator->getMaxLength() * this->zoom, getHeight());
            navigator->setZoom(zoom);
        }
        else if(menuItemID == 6) {
            if (navigator->getMaxLength()== 0) {
                return;
            }
            if (this->zoom - 10 >= 1)
            this->zoom -= 10;

            // setSize(navigator->getMaxLength() * this->zoom, getHeight());
            navigator->setZoom(zoom);
        }
		else if (menuItemID == 7) {
            openSettings();
		}
        else if (menuItemID == 8) {
            scanPlugins();
        }
        else if (menuItemID >= 100) {
            addPlugin(availableInstruments.at(menuItemID - 100));
        }
        
	}

	virtual void changeListenerCallback(ChangeBroadcaster * source) override
	{
		if (source == navigator)
		{
            // we need to snap the position on a multiple of the block size, to prevent the buffer being accessed in a odd way
            // because this leads to a broken audio stream
            
            this->numSamples = navigator->getPosition() * this->sampleRate - ((long)(navigator->getPosition() * this->sampleRate) % this->buffersize) ;
        
            marker->setPosition(navigator->getPosition());
            
			this->zoom = navigator->getZoom();
			int newWidth = navigator->getMaxLength() * this->zoom;
            setSize(newWidth, getHeight());
			this->timeLine->setLength(navigator->getMaxLength());
			this->timeLine->setSize(navigator->getMaxLength() * zoom, 25);
			this->marker->setDrawingBounds(0,0,navigator->getWidth(),getHeight());
			this->marker->setSize(navigator->getWidth(), getHeight());
			repaint();
		}
        
	}



};

#endif  // MAINCOMPONENT_H_INCLUDED
