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
#include "PositionMarker.h"
#include "WaveSelector.h"
#include "TimeLine.h"

using namespace std;
//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent : public AudioAppComponent, public MenuBarModel, public ChangeListener, public ChangeBroadcaster, public TimeSliceClient
{
public:
    //==============================================================================
    MainContentComponent(TimeLine* timeLine) : thread("main")
    {		
        this->zoom = 21.0f;

		this->timeLine = timeLine;

		this->marker = new PositionMarker(600);
        this->navigator = new TrackNavigator(marker);

        this->navigator->setSize(getWidth(), getHeight());
        this->navigator->setBounds(0, 0, getWidth(), getHeight());
        
        this->marker->setSize(getWidth(), getHeight());
        this->marker->setBounds(0, 0, getWidth(), getHeight());
		
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
        
    }

    ~MainContentComponent()
    {
        for (int i = 0; i < navigator->getTracks().size();i++) {
            navigator->getTracks().at(i)->getSource()->stop();
        }
        
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
        navigator->getMixerSource()->prepareToPlay(samplesPerBlockExpected, sampleRate);
		Logger::getCurrentLogger()->writeToLog("prepareToPlay");

    }

    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override
    {
        // Your audio-processing code goes here!

        // For more details, see the help for AudioProcessor::getNextAudioBlock()

        // Right now we are not producing any data, in which case we need to clear the buffer
        // (to prevent the output of random noise)
        /*
		if (readerSource == nullptr)
		{
			bufferToFill.clearActiveBufferRegion();
			return;
		}
        */

        
		// navigator->getMixerSource()->getNextAudioBlock(bufferToFill);
        

        /*
        float* leftIn = (float*)bufferToFill.buffer->getReadPointer(0);
        float* rightIn = (float*)bufferToFill.buffer->getReadPointer(1);
        
        float* const leftOut = bufferToFill.buffer->getWritePointer(0);
        float* const rightOut = bufferToFill.buffer->getWritePointer(1);
        */
         
        if (navigator->isPlaying()) {
            for (int i = 0; i < navigator->getTracks().size();i++) {
                const float* trackBufferL = navigator->getTracks().at(i)->getBuffer()->getReadPointer(0);
                const float* trackBufferR = navigator->getTracks().at(i)->getBuffer()->getReadPointer(1);
                for (int j = numSamples; j < numSamples + 512 && j < navigator->getTracks().at(i)->getBuffer()->getNumSamples();j++) {
                    bufferToFill.buffer->addSample(0, j%512, trackBufferL[j] * leftVolume * navigator->getTracks().at(i)->getVolume());
                    bufferToFill.buffer->addSample(1, j%512, trackBufferR[j] * rightVolume * navigator->getTracks().at(i)->getVolume());
                }
                
            }
            numSamples += 512;
        }
        
        /*
        for (int sample = 0; sample < bufferToFill.buffer->getNumSamples(); ++sample) {
            leftOut[sample] = leftIn[sample] * leftVolume;
            rightOut[sample] = rightIn[sample] * rightVolume;
        }
         */
        navigator->setPosition(numSamples / this->sampleRate);
        
        this->rmsLeft = bufferToFill.buffer->getRMSLevel(0, bufferToFill.startSample, bufferToFill.numSamples);
        this->rmsRight = bufferToFill.buffer->getRMSLevel(1, bufferToFill.startSample, bufferToFill.numSamples);
        
        this->magnitudeLeft = bufferToFill.buffer->getMagnitude(0, bufferToFill.startSample, bufferToFill.numSamples);
        this->magnitudeRight = bufferToFill.buffer->getMagnitude(1, bufferToFill.startSample, bufferToFill.numSamples);
        
        
    }

    void releaseResources() override
    {
        // This will be called when the audio device stops, or when it is being
        // restarted due to a setting change.

        // For more details, see the help for AudioProcessor::releaseResources()
		navigator->getMixerSource()->releaseResources();
    }

    //==============================================================================
    void paint (Graphics& g) override
    {
        // (Our component is opaque, so we must completely fill the background with a solid colour)
        g.fillAll (Colours::grey);

    }
     
    void resized() override
	{
		/*
		Logger::getCurrentLogger()->writeToLog(String(getParentWidth()));

		Rectangle<int> area(getLocalBounds());
        marker->setDrawingBounds(0,0,getWidth(),getHeight() - 80);
        
		*/

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
    
    void setPosition(int sample) {
        this->numSamples = sample;
    }
    
    TrackNavigator* getNavigator() {
        return this->navigator;
    }
    
    PositionMarker* getMarker() {
        return this->marker;
    }
    
    void addTrack() {
        FileChooser chooser("Select a file to add...",
                            File::nonexistent,
                            "*.*");
        
        if (chooser.browseForFileToOpen())
        {
            File file = chooser.getResult();
            navigator->addTrack(file, &thread);
            
            // setSize(navigator->getMaxLength() * this->zoom, getHeight());
        }
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


	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainContentComponent)

	TimeSliceThread thread;
    ScopedPointer<TrackNavigator> navigator;
    ScopedPointer<PositionMarker> marker;
	ScopedPointer<TimeLine> timeLine;

    int numSamples = 0;
    double sampleRate = 0;
    
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
                marker->setPlaying(false);
			}
			else
			{
				// transportSource.setPosition(0);
				navigator->setPlaying(true);
                marker->setPlaying(true);
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
	}

	virtual void changeListenerCallback(ChangeBroadcaster * source) override
	{
		if (source == navigator)
		{
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
