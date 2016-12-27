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
#include "MasterChannelPanel.h"
#include "ImageToggleButton.h"
#include "Project.h"
#include "Mixer.h"
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
    nameLabel->setColour (Label::textColourId, Colours::white);
    nameLabel->setColour (TextEditor::textColourId, Colours::black);
    nameLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    nameLabel->addListener (this);

    addAndMakeVisible (volumeViewSlider = new Slider ("volumeViewSlider"));
    volumeViewSlider->setRange (0, 1.5, 0.01);
    volumeViewSlider->setSliderStyle (Slider::LinearBar);
    volumeViewSlider->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    volumeViewSlider->setColour (Slider::backgroundColourId, Colour (0xff747373));
    volumeViewSlider->setColour (Slider::thumbColourId, Colour (0xff1997ff));
    volumeViewSlider->addListener (this);

    addAndMakeVisible (volumeSlider = new Slider ("volumeSlider"));
    volumeSlider->setRange (0, 1, 0.01);
    volumeSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    volumeSlider->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    volumeSlider->setColour (Slider::thumbColourId, Colours::white);
    volumeSlider->setColour (Slider::rotarySliderFillColourId, Colours::steelblue);
    volumeSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0x7cffffff));
    volumeSlider->addListener (this);

    addAndMakeVisible (balanceSlider = new Slider ("balanceSlider"));
    balanceSlider->setRange (-1, 1, 0.02);
    balanceSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    balanceSlider->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    balanceSlider->setColour (Slider::rotarySliderFillColourId, Colours::steelblue);
    balanceSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0x7cffffff));
    balanceSlider->addListener (this);

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("Volume")));
    label2->setFont (Font (12.00f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (Label::textColourId, Colours::white);
    label2->setColour (Label::outlineColourId, Colour (0x00ffffff));
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label3 = new Label ("new label",
                                           TRANS("Pan")));
    label3->setFont (Font (12.00f, Font::plain));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (Label::textColourId, Colours::white);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (muteButton = new ImageToggleButton());
    muteButton->setName ("muteButton");

    addAndMakeVisible (soloButton = new ImageToggleButton());
    soloButton->setName ("soloButton");

    addAndMakeVisible (recButton = new ImageToggleButton());
    recButton->setName ("recButton");


    //[UserPreSize]

    constrainer = new TrackPropertyConstrainer(50,300);

    resizer = new ResizableEdgeComponent(this,constrainer,ResizableEdgeComponent::bottomEdge);
    addAndMakeVisible(resizer);
    //[/UserPreSize]

    setSize (150, 200);


    //[Constructor] You can add your own custom stuff here..
    setSize(150,Project::DEFAULT_TRACK_HEIGHT);
    clf = new CustomLookAndFeel();
    volumeViewSlider->setLookAndFeel(clf);
	addKeyListener(this);

    muteButton->setText("M");
    soloButton->setText("S");
    recButton->setText("R");

    muteButton->setImages (false, true, true,
                          ImageCache::getFromMemory (ImageToggleButton::round_button_png, ImageToggleButton::round_button_pngSize), 1.000f, Colour (0x00000000),
                             Image(), 1.000f, Colour (0x00000000),
                           ImageCache::getFromMemory (ImageToggleButton::round_button_pushed_png, ImageToggleButton::round_button_pushed_pngSize), 1.000f, Colours::steelblue);

    soloButton->setImages (false, true, true,
                           ImageCache::getFromMemory (ImageToggleButton::round_button_png, ImageToggleButton::round_button_pngSize), 1.000f, Colour (0x00000000),
                           Image(), 1.000f, Colour (0x00000000),
                           ImageCache::getFromMemory (ImageToggleButton::round_button_pushed_png, ImageToggleButton::round_button_pushed_pngSize), 1.000f, Colours::darkorange);


    recButton->setImages (false, true, true,
                           ImageCache::getFromMemory (ImageToggleButton::round_button_png, ImageToggleButton::round_button_pngSize), 1.000f, Colour (0x00000000),
                           Image(), 1.000f, Colour (0x00000000),
                           ImageCache::getFromMemory (ImageToggleButton::round_button_pushed_png, ImageToggleButton::round_button_pushed_pngSize), 1.000f, Colours::darkred);


    muteButton->getButton()->addListener(this);
    soloButton->getButton()->addListener(this);
    recButton->getButton()->addListener(this);
    
    
    //[/Constructor]
}

TrackPropertyPanel::~TrackPropertyPanel()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    nameLabel = nullptr;
    volumeViewSlider = nullptr;
    volumeSlider = nullptr;
    balanceSlider = nullptr;
    label2 = nullptr;
    label3 = nullptr;
    muteButton = nullptr;
    soloButton = nullptr;
    recButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    delete clf;
    delete resizer;
    delete constrainer;
    //[/Destructor]
}

//==============================================================================
void TrackPropertyPanel::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff454545));

    //[UserPaint] Add your own custom painting code here..

	if (selected) {
		g.setColour(Colour(0xff454545).brighter());
		g.fillRect(0, 0, 150, getHeight());
	}
	else {
		g.setColour(Colour(0xff454545));
		g.fillRect(0, 0, 150, getHeight());
	}

	g.setColour(Colours::darkgrey);
	g.drawLine(0, getHeight(), 150, getHeight(),0.5);

    //[/UserPaint]
}

void TrackPropertyPanel::resized()
{
    //[UserPreResize] Add your own custom resize code here..

    //[/UserPreResize]

    nameLabel->setBounds (8, 8, 136, 24);
    volumeViewSlider->setBounds (16, 88, 128, 8);
    volumeSlider->setBounds (16, 32, 32, 32);
    balanceSlider->setBounds (64, 32, 32, 32);
    label2->setBounds (8, 64, 55, 16);
    label3->setBounds (64, 64, 32, 16);
    muteButton->setBounds (16, 112, 24, 24);
    soloButton->setBounds (48, 112, 24, 24);
    recButton->setBounds (80, 112, 24, 24);
    //[UserResized] Add your own custom resize handling here..
    resizer->setBounds(0,getHeight()-5, getWidth(),5);


    if (track != NULL)
        track->setBounds(0, track->getY(), track->getWidth(), getHeight());

    /*

	if (getBounds().getHeight() < 150) {

        volumeViewSlider->setBounds(10, 36, 120,8);
        volumeViewSlider->setSliderStyle(juce::Slider::LinearBar);
		// volumeViewSlider->setVisible(false);
	}
	else {
        volumeViewSlider->setBounds(101, 32, 8, 120);
        volumeViewSlider->setSliderStyle(juce::Slider::LinearBarVertical);
		// volumeViewSlider->setVisible(true);
	}

    */


    //[/UserResized]
}

void TrackPropertyPanel::labelTextChanged (Label* labelThatHasChanged)
{
    //[UserlabelTextChanged_Pre]
    //[/UserlabelTextChanged_Pre]

    if (labelThatHasChanged == nameLabel)
    {
        //[UserLabelCode_nameLabel] -- add your label text handling code here..
        track->setName(nameLabel->getText());
        //[/UserLabelCode_nameLabel]
    }

    //[UserlabelTextChanged_Post]
    //[/UserlabelTextChanged_Post]
}

void TrackPropertyPanel::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    Mixer::getInstance()->setSource(Mixer::Source::PROPERTYVIEW);
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
        //[/UserSliderCode_volumeSlider]
    }
    else if (sliderThatWasMoved == balanceSlider)
    {
        //[UserSliderCode_balanceSlider] -- add your slider handling code here..
        track->setPan(balanceSlider->getValue());
        //[/UserSliderCode_balanceSlider]
    }

    //[UsersliderValueChanged_Post]
    Mixer::getInstance()->sendChangeMessage();
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void TrackPropertyPanel::setName(juce::String name ) {
    this->nameLabel->setText(name, juce::NotificationType::dontSendNotification);
}

void TrackPropertyPanel::setTrack(Track *track) {
    this->track = track;
    this->volumeSlider->setValue(track->getVolume());
}

Track* TrackPropertyPanel::getTrack() {
    return this->track;
}

void TrackPropertyPanel::update() {
    this->volumeViewSlider->setValue(track->getMagnitude(0));
}

void TrackPropertyPanel::setSelected(bool selected)
{
	this->selected = selected;
	track->setSelected(this->selected);
	repaint();
}

bool TrackPropertyPanel::keyPressed(const KeyPress & key, Component * originatingComponent)
{
	if (key.getModifiers().shiftModifier) {
		Logger::getCurrentLogger()->writeToLog("Shift pressed");
	}

	return false;
}

bool TrackPropertyPanel::keyStateChanged(bool isKeyDown, Component * originatingComponent)
{
	Logger::getCurrentLogger()->writeToLog("keyStateChanged to "+String(isKeyDown));
	return false;
}


void TrackPropertyPanel::changeListenerCallback(ChangeBroadcaster * source) {
    if (MasterChannelPanel* channel = dynamic_cast<MasterChannelPanel*>(source)){
        muteButton->setToggleState(false, juce::NotificationType::dontSendNotification);
    }
    else if (Mixer::getInstance() == source) {
        
        if (Mixer::getInstance()->getSource() == Mixer::Source::PROPERTYVIEW) {
            return;
        }
        
        Track* t = Mixer::getInstance()->getLastModifiedTrack();
        
        if (track == t) {
            setName(t->getName());
            muteButton->setToggleState(t->isMute(), juce::NotificationType::dontSendNotification);
            soloButton->setToggleState(t->isSolo(), juce::NotificationType::dontSendNotification);
            volumeSlider->setValue(t->getVolume(),  juce::NotificationType::dontSendNotification);
            balanceSlider->setValue(t->getPan(),  juce::NotificationType::dontSendNotification);
        }

    }
}

void TrackPropertyPanel::buttonClicked (Button* buttonThatWasClicked) {
    Mixer::getInstance()->setSource(Mixer::Source::PROPERTYVIEW);
    if (buttonThatWasClicked == muteButton->getButton()) {
        track->setMute(muteButton->getButton()->getToggleState());
    }
    else if(buttonThatWasClicked == soloButton->getButton()) {
        track->setSolo(soloButton->getButton()->getToggleState());
    }
    else if(buttonThatWasClicked == recButton->getButton()) {
        track->setRecording(recButton->getButton()->getToggleState());
    }
    Mixer::getInstance()->sendChangeMessage();
}



//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TrackPropertyPanel" componentName=""
                 parentClasses="public Component, public ChangeListener, public KeyListener, public ButtonListener"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="150"
                 initialHeight="200">
  <BACKGROUND backgroundColour="ff454545"/>
  <LABEL name="nameLabel" id="e816bfe76d3f902e" memberName="nameLabel"
         virtualName="" explicitFocusOrder="0" pos="8 8 136 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Name" editableSingleClick="0"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="volumeViewSlider" id="a57be949a5f89bda" memberName="volumeViewSlider"
          virtualName="" explicitFocusOrder="0" pos="16 88 128 8" bkgcol="ff747373"
          thumbcol="ff1997ff" min="0" max="1.5" int="0.010000000000000000208"
          style="LinearBar" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="volumeSlider" id="6d202def05db2b28" memberName="volumeSlider"
          virtualName="" explicitFocusOrder="0" pos="16 32 32 32" thumbcol="ffffffff"
          rotarysliderfill="ff4682b4" rotaryslideroutline="7cffffff" min="0"
          max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="balanceSlider" id="b241de49a09df77c" memberName="balanceSlider"
          virtualName="" explicitFocusOrder="0" pos="64 32 32 32" rotarysliderfill="ff4682b4"
          rotaryslideroutline="7cffffff" min="-1" max="1" int="0.020000000000000000416"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <LABEL name="new label" id="85ebf37b370066e6" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="8 64 55 16" textCol="ffffffff" outlineCol="ffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Volume" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="12" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="b8f4f98ce397e313" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="64 64 32 16" textCol="ffffffff" edTextCol="ff000000"
         edBkgCol="0" labelText="Pan" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         bold="0" italic="0" justification="33"/>
  <GENERICCOMPONENT name="muteButton" id="5f1537d979acf69a" memberName="muteButton"
                    virtualName="ImageToggleButton" explicitFocusOrder="0" pos="16 112 24 24"
                    class="ImageToggleButton" params=""/>
  <GENERICCOMPONENT name="soloButton" id="2429c117450e5fa4" memberName="soloButton"
                    virtualName="ImageToggleButton" explicitFocusOrder="0" pos="48 112 24 24"
                    class="ImageToggleButton" params=""/>
  <GENERICCOMPONENT name="recButton" id="8a55a8aa642c1153" memberName="recButton"
                    virtualName="ImageToggleButton" explicitFocusOrder="0" pos="80 112 24 24"
                    class="ImageToggleButton" params=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
