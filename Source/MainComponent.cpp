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
        
        setAudioChannels(2,2);
        
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
        
        
        if (navigator->isPlaying()) {
            
            // AudioProcessorPlayer::audioDeviceIOCallback(inputChannelData, numInputChannels, outputChannelData, numOutputChannels, _numSamples);
            
            for (int i = 0; i < navigator->getTracks().size();i++) {
                for (int j = numSamples; j < numSamples + _numSamples;j++) {
                    
                    //outputChannelData[0][j%_numSamples] += inputChannelData[0][j%_numSamples] + navigator->getTracks().at(i)->getSample(0, j) * leftVolume * navigator->getTracks().at(i)->getVolume();
                    //outputChannelData[1][j%_numSamples] += inputChannelData[1][j%_numSamples] + navigator->getTracks().at(i)->getSample(1, j) * leftVolume * navigator->getTracks().at(i)->getVolume();
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
            for (int j = 0; j < _numSamples;j++) {
                
                buffer->setSample(0, j,inputChannelData[0][j] * leftVolume);
                buffer->setSample(1, j,inputChannelData[1][j] * rightVolume);
            }
            // AudioProcessorPlayer::audioDeviceIOCallback(inputChannelData, numInputChannels, outputChannelData, numOutputChannels, _numSamples);
        }
        
        const float* left = buffer->getReadPointer(0);
        const float* right = buffer->getReadPointer(1);
        
        for (int sample = 0; sample < buffer->getNumSamples(); ++sample) {
            outputChannelData[0][sample] = left[sample];
            outputChannelData[1][sample] = right[sample];
        }
        
        this->magnitudeLeft = buffer->getMagnitude(0, 0, _numSamples);
        this->magnitudeRight = buffer->getMagnitude(1, 0, _numSamples);
        
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
        
        if(plugin != NULL) {
        }
        

        
        this->rmsLeft = bufferToFill.buffer->getRMSLevel(0, bufferToFill.startSample, bufferToFill.numSamples);
        this->rmsRight = bufferToFill.buffer->getRMSLevel(1, bufferToFill.startSample, bufferToFill.numSamples);
        
        this->magnitudeLeft = bufferToFill.buffer->getMagnitude(0, bufferToFill.startSample, bufferToFill.numSamples);
        this->magnitudeRight = bufferToFill.buffer->getMagnitude(1, bufferToFill.startSample, bufferToFill.numSamples);
        
    }

    virtual void handleIncomingMidiMessage (MidiInput* source, const MidiMessage& message) override {
        Logger::getCurrentLogger()->writeToLog(String(message.getNoteNumber()));
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
    
    void addPlugin() {
        
        AudioPluginFormatManager* apfm = new AudioPluginFormatManager();
        apfm->addDefaultFormats();
        
        String error = String("Error");
        PluginDescription pd;
        
        File preset = File("/Users/mpue/plugins/Trio");
        ScopedPointer<XmlElement> xml = XmlDocument(preset).getDocumentElement();
        pd.loadFromXml(*xml.get());
        
        plugin = apfm->createPluginInstance(pd, 44100, 512,error);
        plugin->prepareToPlay(44100, 512);
        AudioProcessorEditor* editor = plugin->createEditorIfNeeded();
        
        
        
        setProcessor(plugin);
        

        
        PluginWindow* win = new PluginWindow("Trio",editor);
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
      
            this->plugin = editor;
            setContentOwned (editor, true);
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
    
	virtual StringArray getMenuBarNames() override
	{
		const char* const names[] = { "File", "View", nullptr };

		return StringArray(names);

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
            menu.addItem(9, "Open plugin", true, false, nullptr);
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
        else if (menuItemID == 9) {
            addPlugin();
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
