/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.3.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_2C4D0C6A45459C02__
#define __JUCE_HEADER_2C4D0C6A45459C02__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "MainComponent.h"
#include "TimeLine.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TransportPanel  : public Component,
                        public ChangeListener,
                        public Timer,
                        public Button::Listener
{
public:
    //==============================================================================
    TransportPanel (MainContentComponent* mcc);
    ~TransportPanel();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

    enum TransportMode {
        STOP,
        PLAY,
        RECORD,
        BACK,
        END,
        PAUSE
    };

    void mouseDown (const MouseEvent& e) override;
    void mouseDrag (const MouseEvent& e) override;
    TransportMode getTransportMode();
    virtual void changeListenerCallback(ChangeBroadcaster * source) override;
    void timerCallback() override;
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;

    // Binary resources:
    static const char* fontawesome_470_stop_32_0_000000_none_png;
    static const int fontawesome_470_stop_32_0_000000_none_pngSize;
    static const char* fontawesome_470_play_32_0_000000_none_png;
    static const int fontawesome_470_play_32_0_000000_none_pngSize;
    static const char* ionicons_201_iosskipbackward_32_0_000000_none_png;
    static const int ionicons_201_iosskipbackward_32_0_000000_none_pngSize;
    static const char* ionicons_201_iosskipforward_32_0_000000_none_png;
    static const int ionicons_201_iosskipforward_32_0_000000_none_pngSize;
    static const char* fontawesome_470_pause_32_0_000000_none_png;
    static const int fontawesome_470_pause_32_0_000000_none_pngSize;
    static const char* fontawesome_470_circle_32_0_000000_none_png;
    static const int fontawesome_470_circle_32_0_000000_none_pngSize;
    static const char* foundationiconfonts_20150216_loop_32_0_000000_none_png;
    static const int foundationiconfonts_20150216_loop_32_0_000000_none_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    ComponentDragger dragger;
    TransportMode mode;
	ScopedPointer<DropShadow> ds;
	ScopedPointer<DropShadower> d;
    MainContentComponent* mcc;

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ImageButton> stopButton;
    ScopedPointer<ImageButton> playButton;
    ScopedPointer<ImageButton> backButton;
    ScopedPointer<ImageButton> endButton;
    ScopedPointer<ImageButton> pauseButton;
    ScopedPointer<Label> timeLabel;
    ScopedPointer<ImageButton> recordButton;
    ScopedPointer<ImageButton> loopButton;
    ScopedPointer<Label> midiLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TransportPanel)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_2C4D0C6A45459C02__
