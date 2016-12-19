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

#ifndef __JUCE_HEADER_24A4BC1316782CBC__
#define __JUCE_HEADER_24A4BC1316782CBC__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "Track.h"
#include "CustomLookAndFeel.h"
#include "TrackPropertyConstrainer.h"
#include "TrackResizer.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TrackPropertyPanel  : public Component,
                            public KeyListener,
                            public LabelListener,
                            public ButtonListener,
                            public SliderListener
{
public:
    //==============================================================================
    TrackPropertyPanel ();
    ~TrackPropertyPanel();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void setName(juce::String name );
    void setTrack(Track* track);
    Track* getTrack();
    void update();
	void setSelected(bool selected);
	virtual bool keyPressed(const KeyPress& key, Component* originatingComponent) override;
	virtual bool keyStateChanged(bool isKeyDown, Component* originatingComponent) override;

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void labelTextChanged (Label* labelThatHasChanged) override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    Track* track = NULL;
    CustomLookAndFeel* clf;
	bool selected;
	ResizableEdgeComponent* resizer;
    TrackPropertyConstrainer* constrainer;
	bool shiftPressed = false;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Label> nameLabel;
    ScopedPointer<ToggleButton> muteButton;
    ScopedPointer<ToggleButton> soloButton;
    ScopedPointer<ToggleButton> recordButton;
    ScopedPointer<Slider> volumeViewSlider;
    ScopedPointer<Slider> volumeSlider;
    ScopedPointer<Slider> balanceSlider;
    ScopedPointer<Label> label2;
    ScopedPointer<Label> label3;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TrackPropertyPanel)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_24A4BC1316782CBC__
