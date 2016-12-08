/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include <iostream>
#include "WaveNavigator.h"
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
    MainContentComponent() : thread("main")
    {
		
        this->zoom = 21.0f;
    

        this->marker = new PositionMarker(600);
        this->navigator = new WaveNavigator(marker);
		this->timeLine = new TimeLine(600);

        this->navigator->setSize(getWidth(), getHeight());
        this->navigator->setBounds(0, 50, getWidth(), getHeight());
        
        this->marker->setSize(getWidth(), getHeight());
        this->marker->setBounds(0, 0, getWidth(), getHeight());

		this->timeLine->setSize(getWidth(), 25);
		this->timeLine->setBounds(0, 50, getWidth(), 25);
		
        addAndMakeVisible(navigator);
		addChildComponent(timeLine);
		addAndMakeVisible(marker);

        /*
		this->transportSource.addChangeListener(this);
		this->transportSource.addChangeListener(this->timeLine);
        this->transportSource.addChangeListener(this->marker);
		this->addChangeListener(marker);
        */
        
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

        
		navigator->getMixerSource()->getNextAudioBlock(bufferToFill);
        
        this->rmsLeft = bufferToFill.buffer->getRMSLevel(0, bufferToFill.startSample, bufferToFill.numSamples);
        this->rmsRight = bufferToFill.buffer->getRMSLevel(1, bufferToFill.startSample, bufferToFill.numSamples);
        
        this->magnitudeLeft = bufferToFill.buffer->getMagnitude(0, bufferToFill.startSample, bufferToFill.numSamples);
        this->magnitudeRight = bufferToFill.buffer->getMagnitude(1, bufferToFill.startSample, bufferToFill.numSamples);
        
        float* leftIn = (float*)bufferToFill.buffer->getReadPointer(0);
        float* rightIn = (float*)bufferToFill.buffer->getReadPointer(1);
        
        float* const leftOut = bufferToFill.buffer->getWritePointer(0);
        float* const rightOut = bufferToFill.buffer->getWritePointer(1);
        
        for (int sample = 0; sample < bufferToFill.buffer->getNumSamples(); ++sample) {
            leftOut[sample] = leftIn[sample] * leftVolume;
            rightOut[sample] = rightIn[sample] * rightVolume;
        }
        
        
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
        g.fillAll (Colours::darkgrey);

    }
     
    void resized() override
	{
		Rectangle<int> area(getLocalBounds());
        marker->setDrawingBounds(0,0,getWidth(),getHeight() - 80);
        
        this->navigator->setSize(getWidth(), getHeight() - 80);
        this->navigator->setBounds(0, 50, getWidth(), getHeight() - 58);
        
        this->marker->setSize(getWidth(), getHeight());
        this->marker->setBounds(0, 0, getWidth(), getHeight());

		this->timeLine->setSize(getWidth(),25);
		this->timeLine->setBounds(0, 25, getWidth(), 25);

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
    
    WaveNavigator* getNavigator() {
        return this->navigator;
    }
    
    PositionMarker* getMarker() {
        return this->marker;
    }
    
private:
    //==============================================================================


	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainContentComponent)

	TimeSliceThread thread;
    ScopedPointer<WaveNavigator> navigator;
    ScopedPointer<PositionMarker> marker;
	ScopedPointer<TimeLine> timeLine;

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
			FileChooser chooser("Select a file to play...",
				File::nonexistent,
				"*.*");

			if (chooser.browseForFileToOpen())
			{
				File file = chooser.getResult();
            
                navigator->addTrack(file, &thread);
                setSize(navigator->getMaxLength() * this->zoom, getHeight());
                // this->navigator->setSize(getWidth(), getHeight());
                // this->navigator->setBounds(0, 50, getWidth(), getHeight());
                this->navigator->repaint();
                this->marker->setDrawingBounds(0,0,getWidth(),getHeight());
                this->marker->setSize(getWidth(), getHeight());
                this->marker->setLength(navigator->getMaxLength());
                this->timeLine->setLength(navigator->getMaxLength());
                this->timeLine->setSize(navigator->getWidth(), 25);
                this->timeLine->setVisible(true);
			}

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
            //setSize(navigator->getMaxLength() * this->zoom, getHeight());
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

			AudioDeviceSelectorComponent* selector = new AudioDeviceSelectorComponent(deviceManager, 2, 2, 2, 2, true, true, true, false);

			DialogWindow::LaunchOptions launchOptions;
			launchOptions.dialogTitle = ("Audio Settings");
			launchOptions.escapeKeyTriggersCloseButton = true;
			launchOptions.resizable = true;
			launchOptions.useNativeTitleBar = true;
			launchOptions.useBottomRightCornerResizer = true;
			launchOptions.componentToCentreAround = this;
			launchOptions.content.setOwned(selector);
			launchOptions.content->setSize(640, 600);
			launchOptions.launchAsync();

			
				


		}
	}

	virtual void changeListenerCallback(ChangeBroadcaster * source) override
	{
		if (source == navigator)
		{
            setSize(navigator->getMaxLength() * this->zoom, getHeight());
            this->marker->setDrawingBounds(0,0,navigator->getWidth(),getHeight());
            this->marker->setSize(navigator->getWidth(), getHeight());
		}
        
	}



};

#endif  // MAINCOMPONENT_H_INCLUDED
