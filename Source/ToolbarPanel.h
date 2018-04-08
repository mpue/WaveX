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

#ifndef __JUCE_HEADER_BE5A0412565AC66__
#define __JUCE_HEADER_BE5A0412565AC66__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "MainComponent.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ToolbarPanel  : public Component,
                      public ChangeBroadcaster,
                    public Button::Listener
{
public:
    //==============================================================================
    ToolbarPanel (MainContentComponent* mcc);
    ~ToolbarPanel();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    ImageButton* getMixerButton () {
        return this->mixerButton.get();
    }
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;

    // Binary resources:
    static const char* fontawesome_470_pencil_24_0_000000_none_png;
    static const int fontawesome_470_pencil_24_0_000000_none_pngSize;
    static const char* fontawesome_470_copy_24_0_000000_none_png;
    static const int fontawesome_470_copy_24_0_000000_none_pngSize;
    static const char* ionicons_201_androidremovecircle_24_0_000000_none_png;
    static const int ionicons_201_androidremovecircle_24_0_000000_none_pngSize;
    static const char* ionicons_201_androidaddcircle_24_0_000000_none_png;
    static const int ionicons_201_androidaddcircle_24_0_000000_none_pngSize;
    static const char* ionicons_201_settings_24_0_000000_none_png;
    static const int ionicons_201_settings_24_0_000000_none_pngSize;
    static const char* fontawesome_470_fileaudioo_32_0_000000_none_png;
    static const int fontawesome_470_fileaudioo_32_0_000000_none_pngSize;
    static const char* fontawesome_470_plug_32_0_000000_none_png;
    static const int fontawesome_470_plug_32_0_000000_none_pngSize;
    static const char* fontawesome_470_music_32_0_000000_none_png;
    static const int fontawesome_470_music_32_0_000000_none_pngSize;
    static const char* mixer_128px_png;
    static const int mixer_128px_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    MainContentComponent* mcc;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ImageButton> addTrackButton;
    ScopedPointer<ImageButton> removeTrackButton;
    ScopedPointer<ImageButton> copyButton;
    ScopedPointer<ImageButton> editButton;
    ScopedPointer<ImageButton> settingsButton;
    ScopedPointer<ImageButton> importAudioButton;
    ScopedPointer<ImageButton> pluginsButton;
    ScopedPointer<ImageButton> addMidiTrackButton;
    ScopedPointer<ImageButton> mixerButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ToolbarPanel)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_BE5A0412565AC66__
