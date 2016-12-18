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

#ifndef __JUCE_HEADER_DBA7B4BA7DFB0DD2__
#define __JUCE_HEADER_DBA7B4BA7DFB0DD2__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "MainComponent.cpp"
#include "MasterChannelPanel.h"
#include "TrackNavigator.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MixerPanel  : public Component,
                    public ChangeListener
{
public:
    //==============================================================================
    MixerPanel (MainContentComponent* mcc);
    ~MixerPanel();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    virtual void changeListenerCallback(ChangeBroadcaster * source) override;
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    MainContentComponent* mcc;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<MasterChannelPanel> masterChannel;
    ScopedPointer<MasterChannelPanel> aux1;
    
    vector<MasterChannelPanel*> channels;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MixerPanel)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_DBA7B4BA7DFB0DD2__
