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

    addAndMakeVisible (nameLabel = new Label ("nameLabel",
                                              TRANS("Name")));
    nameLabel->setFont (Font (15.00f, Font::plain));
    nameLabel->setJustificationType (Justification::centredLeft);
    nameLabel->setEditable (false, true, false);
    nameLabel->setColour (TextEditor::textColourId, Colours::black);
    nameLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    nameLabel->addListener (this);

    addAndMakeVisible (muteButton = new ToggleButton ("muteButton"));
    muteButton->setButtonText (TRANS("M"));
    muteButton->addListener (this);

    addAndMakeVisible (soloButton = new ToggleButton ("soloButton"));
    soloButton->setButtonText (TRANS("S"));
    soloButton->addListener (this);

    addAndMakeVisible (recordButton = new ToggleButton ("recordButton"));
    recordButton->setButtonText (TRANS("R"));
    recordButton->addListener (this);

    addAndMakeVisible (volumeViewSlider = new Slider ("volumeViewSlider"));
    volumeViewSlider->setRange (0, 1.5, 0.01);
    volumeViewSlider->setSliderStyle (Slider::LinearBarVertical);
    volumeViewSlider->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    volumeViewSlider->setColour (Slider::backgroundColourId, Colour (0xff747373));
    volumeViewSlider->setColour (Slider::thumbColourId, Colour (0xff1997ff));
    volumeViewSlider->addListener (this);

    addAndMakeVisible (volumeSlider = new Slider ("volumeSlider"));
    volumeSlider->setRange (0, 1, 0.01);
    volumeSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    volumeSlider->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    volumeSlider->setColour (Slider::rotarySliderFillColourId, Colours::steelblue);
    volumeSlider->addListener (this);

    addAndMakeVisible (balanceSlider = new Slider ("balanceSlider"));
    balanceSlider->setRange (-1, 1, 0.1);
    balanceSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    balanceSlider->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    balanceSlider->setColour (Slider::rotarySliderFillColourId, Colours::steelblue);
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

    setSize (150, 200);


    //[Constructor] You can add your own custom stuff here..
    // clf = new CustomLookAndFeel();
    // volumeViewSlider->setLookAndFeel(clf);
    //[/Constructor]
}

TrackPropertyPanel::~TrackPropertyPanel()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    nameLabel = nullptr;
    muteButton = nullptr;
    soloButton = nullptr;
    recordButton = nullptr;
    volumeViewSlider = nullptr;
    volumeSlider = nullptr;
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

    //[UserPaint] Add your own custom painting code here..

	if (selected) {
		g.setColour(Colour(0xffa0a0a0).brighter());
		g.fillRect(0, 0, 150, 200);
	}
	else {
		g.setColour(Colour(0xffa0a0a0));
		g.fillRect(0, 0, 150, 200);
	}

	g.setColour(Colours::darkgrey);
	g.drawLine(0, 200, 150, 200,0.5);

    //[/UserPaint]
}

void TrackPropertyPanel::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    nameLabel->setBounds (8, 8, 136, 24);
    muteButton->setBounds (16, 160, 39, 24);
    soloButton->setBounds (56, 160, 39, 24);
    recordButton->setBounds (96, 160, 39, 24);
    volumeViewSlider->setBounds (101, 32, 8, 120);
    volumeSlider->setBounds (32, 48, 32, 32);
    balanceSlider->setBounds (32, 96, 32, 32);
    label2->setBounds (24, 80, 55, 16);
    label3->setBounds (32, 128, 32, 16);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void TrackPropertyPanel::labelTextChanged (Label* labelThatHasChanged)
{
    //[UserlabelTextChanged_Pre]
    //[/UserlabelTextChanged_Pre]

    if (labelThatHasChanged == nameLabel)
    {
        //[UserLabelCode_nameLabel] -- add your label text handling code here..
        //[/UserLabelCode_nameLabel]
    }

    //[UserlabelTextChanged_Post]
    //[/UserlabelTextChanged_Post]
}

void TrackPropertyPanel::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == muteButton)
    {
        //[UserButtonCode_muteButton] -- add your button handler code here..

        if (muteButton->getToggleState()) {
            track->setGain(0);
        }
        else {
            track->setGain(1);
        }
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

    if (sliderThatWasMoved == volumeViewSlider)
    {
        //[UserSliderCode_volumeViewSlider] -- add your slider handling code here..
        //[/UserSliderCode_volumeViewSlider]
    }
    else if (sliderThatWasMoved == volumeSlider)
    {
        //[UserSliderCode_volumeSlider] -- add your slider handling code here..
        track->setVolume(volumeSlider->getValue());
        track->setGain(volumeSlider->getValue());
        //[/UserSliderCode_volumeSlider]
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
void TrackPropertyPanel::setName(juce::String name ) {
    this->nameLabel->setText(name, juce::NotificationType::dontSendNotification);
}

void TrackPropertyPanel::setTrack(Track *track) {
    this->track = track;
    this->volumeSlider->setValue(1.0);
}

Track* TrackPropertyPanel::getTrack() {
    return this->track;
}

void TrackPropertyPanel::update() {
    this->volumeViewSlider->setValue(track->magnitudeLeft);
	if (this->selected != track->isSelected()) {
		this->selected = track->isSelected();
		repaint();
	}

}

void TrackPropertyPanel::setSelected(bool selected)
{
	this->selected = selected;
	track->setSelected(this->selected);
	repaint();
}




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
                 fixedSize="0" initialWidth="150" initialHeight="200">
  <BACKGROUND backgroundColour="ffffffff"/>
  <LABEL name="nameLabel" id="e816bfe76d3f902e" memberName="nameLabel"
         virtualName="" explicitFocusOrder="0" pos="8 8 136 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Name" editableSingleClick="0" editableDoubleClick="1"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="muteButton" id="7dab003004fb0c0e" memberName="muteButton"
                virtualName="" explicitFocusOrder="0" pos="16 160 39 24" buttonText="M"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="soloButton" id="5d1c874832c3c5df" memberName="soloButton"
                virtualName="" explicitFocusOrder="0" pos="56 160 39 24" buttonText="S"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="recordButton" id="92ee3c4a2e2d50e8" memberName="recordButton"
                virtualName="" explicitFocusOrder="0" pos="96 160 39 24" buttonText="R"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <SLIDER name="volumeViewSlider" id="a57be949a5f89bda" memberName="volumeViewSlider"
          virtualName="" explicitFocusOrder="0" pos="101 32 8 120" bkgcol="ff747373"
          thumbcol="ff1997ff" min="0" max="1.5" int="0.010000000000000000208"
          style="LinearBarVertical" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="volumeSlider" id="6d202def05db2b28" memberName="volumeSlider"
          virtualName="" explicitFocusOrder="0" pos="32 48 32 32" rotarysliderfill="ff4682b4"
          min="0" max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="balanceSlider" id="b241de49a09df77c" memberName="balanceSlider"
          virtualName="" explicitFocusOrder="0" pos="32 96 32 32" rotarysliderfill="ff4682b4"
          min="-1" max="1" int="0.10000000000000000555" style="RotaryVerticalDrag"
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
