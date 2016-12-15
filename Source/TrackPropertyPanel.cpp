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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "TrackPropertyPanel.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TrackPropertyPanel::TrackPropertyPanel ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Name")));
    label->setFont (Font (15.00f, Font::plain));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (muteButton = new ToggleButton ("muteButton"));
    muteButton->setButtonText (TRANS("M"));
    muteButton->addListener (this);

    addAndMakeVisible (soloButton = new ToggleButton ("soloButton"));
    soloButton->setButtonText (TRANS("S"));
    soloButton->addListener (this);

    addAndMakeVisible (recordButton = new ToggleButton ("recordButton"));
    recordButton->setButtonText (TRANS("R"));
    recordButton->addListener (this);

    addAndMakeVisible (slider = new Slider ("new slider"));
    slider->setRange (0, 2, 0.1);
    slider->setSliderStyle (Slider::LinearBarVertical);
    slider->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    slider->setColour (Slider::backgroundColourId, Colour (0xff747373));
    slider->setColour (Slider::thumbColourId, Colour (0xff22fd2d));
    slider->addListener (this);

    addAndMakeVisible (slider2 = new Slider ("new slider"));
    slider2->setRange (0, 10, 0);
    slider2->setSliderStyle (Slider::RotaryVerticalDrag);
    slider2->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    slider2->addListener (this);

    addAndMakeVisible (balanceSlider = new Slider ("balanceSlider"));
    balanceSlider->setRange (-1, 1, 0.1);
    balanceSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    balanceSlider->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    balanceSlider->addListener (this);

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("Volume")));
    label2->setFont (Font (12.00f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label3 = new Label ("new label",
                                           TRANS("Pan")));
    label3->setFont (Font (12.00f, Font::plain));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (150, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

TrackPropertyPanel::~TrackPropertyPanel()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    label = nullptr;
    muteButton = nullptr;
    soloButton = nullptr;
    recordButton = nullptr;
    slider = nullptr;
    slider2 = nullptr;
    balanceSlider = nullptr;
    label2 = nullptr;
    label3 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TrackPropertyPanel::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    g.setColour (Colour (0xffbababa));
    g.fillRect (0, 0, 150, 200);

    g.setColour (Colour (0xffa0a0a0));
    g.drawRect (0, 0, 150, 200, 2);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TrackPropertyPanel::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    label->setBounds (8, 8, 136, 24);
    muteButton->setBounds (16, 160, 39, 24);
    soloButton->setBounds (56, 160, 39, 24);
    recordButton->setBounds (96, 160, 39, 24);
    slider->setBounds (101, 32, 8, 120);
    slider2->setBounds (32, 48, 32, 32);
    balanceSlider->setBounds (32, 96, 32, 32);
    label2->setBounds (24, 80, 55, 16);
    label3->setBounds (32, 128, 32, 16);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void TrackPropertyPanel::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == muteButton)
    {
        //[UserButtonCode_muteButton] -- add your button handler code here..
        //[/UserButtonCode_muteButton]
    }
    else if (buttonThatWasClicked == soloButton)
    {
        //[UserButtonCode_soloButton] -- add your button handler code here..
        //[/UserButtonCode_soloButton]
    }
    else if (buttonThatWasClicked == recordButton)
    {
        //[UserButtonCode_recordButton] -- add your button handler code here..
        //[/UserButtonCode_recordButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void TrackPropertyPanel::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == slider)
    {
        //[UserSliderCode_slider] -- add your slider handling code here..
        //[/UserSliderCode_slider]
    }
    else if (sliderThatWasMoved == slider2)
    {
        //[UserSliderCode_slider2] -- add your slider handling code here..
        //[/UserSliderCode_slider2]
    }
    else if (sliderThatWasMoved == balanceSlider)
    {
        //[UserSliderCode_balanceSlider] -- add your slider handling code here..
        //[/UserSliderCode_balanceSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TrackPropertyPanel" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="150" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff">
    <RECT pos="0 0 150 200" fill="solid: ffbababa" hasStroke="1" stroke="2, mitered, butt"
          strokeColour="solid: ffa0a0a0"/>
  </BACKGROUND>
  <LABEL name="new label" id="e816bfe76d3f902e" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="8 8 136 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Name" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <TOGGLEBUTTON name="muteButton" id="7dab003004fb0c0e" memberName="muteButton"
                virtualName="" explicitFocusOrder="0" pos="16 160 39 24" buttonText="M"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="soloButton" id="5d1c874832c3c5df" memberName="soloButton"
                virtualName="" explicitFocusOrder="0" pos="56 160 39 24" buttonText="S"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="recordButton" id="92ee3c4a2e2d50e8" memberName="recordButton"
                virtualName="" explicitFocusOrder="0" pos="96 160 39 24" buttonText="R"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <SLIDER name="new slider" id="a57be949a5f89bda" memberName="slider" virtualName=""
          explicitFocusOrder="0" pos="101 32 8 120" bkgcol="ff747373" thumbcol="ff22fd2d"
          min="0" max="2" int="0.10000000000000000555" style="LinearBarVertical"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="new slider" id="6d202def05db2b28" memberName="slider2"
          virtualName="" explicitFocusOrder="0" pos="32 48 32 32" min="0"
          max="10" int="0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="balanceSlider" id="b241de49a09df77c" memberName="balanceSlider"
          virtualName="" explicitFocusOrder="0" pos="32 96 32 32" min="-1"
          max="1" int="0.10000000000000000555" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <LABEL name="new label" id="85ebf37b370066e6" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="24 80 55 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Volume" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="b8f4f98ce397e313" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="32 128 32 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Pan" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
