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

#include "TransportPanel.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TransportPanel::TransportPanel (MainContentComponent* mcc)
{
    //[Constructor_pre] You can add your own custom stuff here..
    this->mcc = mcc;
    //[/Constructor_pre]

    addAndMakeVisible (stopButton = new ImageButton ("stopButton"));
    stopButton->setTooltip (TRANS("Stop playing"));
    stopButton->setButtonText (TRANS("Stop"));
    stopButton->addListener (this);

    stopButton->setImages (false, true, true,
                           ImageCache::getFromMemory (fontawesome_470_stop_32_0_000000_none_png, fontawesome_470_stop_32_0_000000_none_pngSize), 1.000f, Colours::white,
                           Image(), 1.000f, Colours::cornflowerblue,
                           Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (playButton = new ImageButton ("playButton"));
    playButton->setTooltip (TRANS("Play"));
    playButton->setButtonText (TRANS("Play"));
    playButton->addListener (this);

    playButton->setImages (false, true, true,
                           ImageCache::getFromMemory (fontawesome_470_play_32_0_000000_none_png, fontawesome_470_play_32_0_000000_none_pngSize), 1.000f, Colours::white,
                           Image(), 1.000f, Colours::green,
                           Image(), 1.000f, Colours::green);
    addAndMakeVisible (backButton = new ImageButton ("backButton"));
    backButton->setTooltip (TRANS("To track start"));
    backButton->setButtonText (TRANS("Back"));
    backButton->addListener (this);

    backButton->setImages (false, true, true,
                           ImageCache::getFromMemory (ionicons_201_iosskipbackward_32_0_000000_none_png, ionicons_201_iosskipbackward_32_0_000000_none_pngSize), 1.000f, Colours::white,
                           Image(), 1.000f, Colours::cornflowerblue,
                           Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (endButton = new ImageButton ("endButton"));
    endButton->setTooltip (TRANS("Jump to track end"));
    endButton->setButtonText (TRANS("End"));
    endButton->addListener (this);

    endButton->setImages (false, true, true,
                          ImageCache::getFromMemory (ionicons_201_iosskipforward_32_0_000000_none_png, ionicons_201_iosskipforward_32_0_000000_none_pngSize), 1.000f, Colours::white,
                          Image(), 1.000f, Colours::cornflowerblue,
                          Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (pauseButton = new ImageButton ("pauseButton"));
    pauseButton->setTooltip (TRANS("Pause"));
    pauseButton->setButtonText (TRANS("Pause"));
    pauseButton->addListener (this);

    pauseButton->setImages (false, true, true,
                            ImageCache::getFromMemory (fontawesome_470_pause_32_0_000000_none_png, fontawesome_470_pause_32_0_000000_none_pngSize), 1.000f, Colours::white,
                            Image(), 1.000f, Colours::cornflowerblue,
                            Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (timeLabel = new Label ("timeLabel",
                                              TRANS("00:00:00")));
    timeLabel->setTooltip (TRANS("Time information"));
    timeLabel->setFont (Font (16.00f, Font::plain));
    timeLabel->setJustificationType (Justification::centred);
    timeLabel->setEditable (false, false, false);
    timeLabel->setColour (Label::backgroundColourId, Colour (0xff0c0b0b));
    timeLabel->setColour (Label::textColourId, Colours::cornflowerblue);
    timeLabel->setColour (Label::outlineColourId, Colours::white);
    timeLabel->setColour (TextEditor::textColourId, Colours::black);
    timeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (recordButton = new ImageButton ("recordButton"));
    recordButton->setTooltip (TRANS("Start / stop recording"));
    recordButton->setButtonText (TRANS("Back"));
    recordButton->addListener (this);

    recordButton->setImages (false, true, true,
                             ImageCache::getFromMemory (fontawesome_470_circle_32_0_000000_none_png, fontawesome_470_circle_32_0_000000_none_pngSize), 1.000f, Colours::white,
                             Image(), 1.000f, Colours::red,
                             Image(), 1.000f, Colours::red);
    addAndMakeVisible (loopButton = new ImageButton ("loopButton"));
    loopButton->setTooltip (TRANS("Turn cycle mode on/off"));
    loopButton->setButtonText (TRANS("End"));
    loopButton->addListener (this);

    loopButton->setImages (false, true, true,
                           ImageCache::getFromMemory (foundationiconfonts_20150216_loop_32_0_000000_none_png, foundationiconfonts_20150216_loop_32_0_000000_none_pngSize), 1.000f, Colours::white,
                           Image(), 1.000f, Colours::cornflowerblue,
                           Image(), 1.000f, Colour (0xffff9700));
    addAndMakeVisible (midiLabel = new Label ("midiLabel",
                                              TRANS("no input")));
    midiLabel->setTooltip (TRANS("Midi input"));
    midiLabel->setFont (Font (16.00f, Font::plain));
    midiLabel->setJustificationType (Justification::centred);
    midiLabel->setEditable (false, false, false);
    midiLabel->setColour (Label::backgroundColourId, Colour (0xff0c0b0b));
    midiLabel->setColour (Label::textColourId, Colours::cornflowerblue);
    midiLabel->setColour (Label::outlineColourId, Colours::white);
    midiLabel->setColour (TextEditor::textColourId, Colours::black);
    midiLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (520, 40);


    //[Constructor] You can add your own custom stuff here..
    mode = STOP;

    /*
	ds = new DropShadow(Colour::fromFloatRGBA(0, 0, 0, 0.5), 3, Point<int>(3, 3));
	d = new DropShadower(*ds);
	d->setOwner(this);
    */



    recordButton->setClickingTogglesState(true);
    playButton->setClickingTogglesState(true);
    loopButton->setClickingTogglesState(true);

    recordButton->setToggleState(false, juce::NotificationType::dontSendNotification);

    //[/Constructor]
}

TransportPanel::~TransportPanel()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    stopButton = nullptr;
    playButton = nullptr;
    backButton = nullptr;
    endButton = nullptr;
    pauseButton = nullptr;
    timeLabel = nullptr;
    recordButton = nullptr;
    loopButton = nullptr;
    midiLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..

	ds = nullptr;
	d = nullptr;

    //[/Destructor]
}

//==============================================================================
void TransportPanel::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    /*
    g.setColour (Colours::darkgrey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component
     */
    //[/UserPaint]
}

void TransportPanel::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    stopButton->setBounds (74, 14, 24, 24);
    playButton->setBounds (106, 14, 24, 24);
    backButton->setBounds (42, 14, 22, 24);
    endButton->setBounds (162, 14, 24, 24);
    pauseButton->setBounds (130, 14, 24, 24);
    timeLabel->setBounds (224, 14, 112, 24);
    recordButton->setBounds (8, 14, 24, 24);
    loopButton->setBounds (192, 14, 24, 24);
    midiLabel->setBounds (344, 14, 112, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void TransportPanel::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == stopButton)
    {
        //[UserButtonCode_stopButton] -- add your button handler code here..
        mode = STOP;
        stopTimer();
        playButton->setToggleState(false, juce::NotificationType::sendNotification);
        mcc->getNavigator()->setPlaying(false);
        if (mcc->getNavigator()->isRecording()){
            mcc->getNavigator()->setRecording(false);
        }

        //[/UserButtonCode_stopButton]
    }
    else if (buttonThatWasClicked == playButton)
    {
        //[UserButtonCode_playButton] -- add your button handler code here..
        mode = PLAY;
        startTimer(100);
        mcc->getNavigator()->setPlaying(true);
        //[/UserButtonCode_playButton]
    }
    else if (buttonThatWasClicked == backButton)
    {
        //[UserButtonCode_backButton] -- add your button handler code here..
        mode = BACK;
        mcc->getNavigator()->setPosition(0);
        mcc->getMarker()->setPosition(0);
        mcc->setPosition(0);

        //[/UserButtonCode_backButton]
    }
    else if (buttonThatWasClicked == endButton)
    {
        //[UserButtonCode_endButton] -- add your button handler code here..
        mode = END;
        mcc->getNavigator()->setPosition(mcc->getNavigator()->getMaxLength());
        mcc->getMarker()->setPosition(mcc->getNavigator()->getMaxLength());
        mcc->setPosition(mcc->getNavigator()->getMaxLength() * 44100);
        //[/UserButtonCode_endButton]
    }
    else if (buttonThatWasClicked == pauseButton)
    {
        //[UserButtonCode_pauseButton] -- add your button handler code here..
        mode = PAUSE;
        if (mcc->getNavigator()->isPlaying()) {
            mcc->getNavigator()->setPlaying(false);
        }
        else {
            mcc->getNavigator()->setPlaying(true);
        }
        //[/UserButtonCode_pauseButton]
    }
    else if (buttonThatWasClicked == recordButton)
    {
        //[UserButtonCode_recordButton] -- add your button handler code here..

        if (!recordButton->getToggleState()) {
            mode = STOP;
            stopTimer();
            mcc->getNavigator()->setRecording(false);
        }
        else {
            mode = RECORD;
            startTimer(100);
            mcc->getNavigator()->setRecording(true);
        }
        //[/UserButtonCode_recordButton]
    }
    else if (buttonThatWasClicked == loopButton)
    {
        //[UserButtonCode_loopButton] -- add your button handler code here..
        //[/UserButtonCode_loopButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void TransportPanel::mouseDown (const MouseEvent& e)
{
    dragger.startDraggingComponent (this, e);
}

void TransportPanel::mouseDrag (const MouseEvent& e)
{
    dragger.dragComponent (this, e, nullptr);
}

TransportPanel::TransportMode TransportPanel::getTransportMode() {
    return this->mode;
}

void TransportPanel::changeListenerCallback(ChangeBroadcaster * source) {
    timeLabel->setText(TimeLine::secondsToTime(mcc->getNavigator()->getPosition()), juce::NotificationType::dontSendNotification);
}

void TransportPanel::timerCallback() {
    if (mcc->getNavigator()->getMaxLength() > 0) {
        timeLabel->setText(TimeLine::secondsToTime(mcc->getNavigator()->getPosition()), juce::NotificationType::dontSendNotification);
        mcc->getMarker()->setPosition(mcc->getNavigator()->getPosition());
    }
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TransportPanel" componentName=""
                 parentClasses="public Component, public ChangeListener, public Timer"
                 constructorParams="MainContentComponent* mcc" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="520" initialHeight="40">
  <BACKGROUND backgroundColour="808080"/>
  <IMAGEBUTTON name="stopButton" id="4cd37851bb11a613" memberName="stopButton"
               virtualName="" explicitFocusOrder="0" pos="74 14 24 24" tooltip="Stop playing"
               buttonText="Stop" connectedEdges="0" needsCallback="1" radioGroupId="0"
               keepProportions="1" resourceNormal="fontawesome_470_stop_32_0_000000_none_png"
               opacityNormal="1" colourNormal="ffffffff" resourceOver="" opacityOver="1"
               colourOver="ff6495ed" resourceDown="" opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="playButton" id="c8555f308f9d15ec" memberName="playButton"
               virtualName="" explicitFocusOrder="0" pos="106 14 24 24" tooltip="Play"
               buttonText="Play" connectedEdges="0" needsCallback="1" radioGroupId="0"
               keepProportions="1" resourceNormal="fontawesome_470_play_32_0_000000_none_png"
               opacityNormal="1" colourNormal="ffffffff" resourceOver="" opacityOver="1"
               colourOver="ff008000" resourceDown="" opacityDown="1" colourDown="ff008000"/>
  <IMAGEBUTTON name="backButton" id="c457ade9e0c0c98f" memberName="backButton"
               virtualName="" explicitFocusOrder="0" pos="42 14 22 24" tooltip="To track start"
               buttonText="Back" connectedEdges="0" needsCallback="1" radioGroupId="0"
               keepProportions="1" resourceNormal="ionicons_201_iosskipbackward_32_0_000000_none_png"
               opacityNormal="1" colourNormal="ffffffff" resourceOver="" opacityOver="1"
               colourOver="ff6495ed" resourceDown="" opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="endButton" id="b649d3250331ad42" memberName="endButton"
               virtualName="" explicitFocusOrder="0" pos="162 14 24 24" tooltip="Jump to track end"
               buttonText="End" connectedEdges="0" needsCallback="1" radioGroupId="0"
               keepProportions="1" resourceNormal="ionicons_201_iosskipforward_32_0_000000_none_png"
               opacityNormal="1" colourNormal="ffffffff" resourceOver="" opacityOver="1"
               colourOver="ff6495ed" resourceDown="" opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="pauseButton" id="bc895af41d57982" memberName="pauseButton"
               virtualName="" explicitFocusOrder="0" pos="130 14 24 24" tooltip="Pause"
               buttonText="Pause" connectedEdges="0" needsCallback="1" radioGroupId="0"
               keepProportions="1" resourceNormal="fontawesome_470_pause_32_0_000000_none_png"
               opacityNormal="1" colourNormal="ffffffff" resourceOver="" opacityOver="1"
               colourOver="ff6495ed" resourceDown="" opacityDown="1" colourDown="0"/>
  <LABEL name="timeLabel" id="4b26497a62774d79" memberName="timeLabel"
         virtualName="" explicitFocusOrder="0" pos="224 14 112 24" tooltip="Time information"
         bkgCol="ff0c0b0b" textCol="ff6495ed" outlineCol="ffffffff" edTextCol="ff000000"
         edBkgCol="0" labelText="00:00:00" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="16"
         bold="0" italic="0" justification="36"/>
  <IMAGEBUTTON name="recordButton" id="7521828dc05bc048" memberName="recordButton"
               virtualName="" explicitFocusOrder="0" pos="8 14 24 24" tooltip="Start / stop recording"
               buttonText="Back" connectedEdges="0" needsCallback="1" radioGroupId="0"
               keepProportions="1" resourceNormal="fontawesome_470_circle_32_0_000000_none_png"
               opacityNormal="1" colourNormal="ffffffff" resourceOver="" opacityOver="1"
               colourOver="ffff0000" resourceDown="" opacityDown="1" colourDown="ffff0000"/>
  <IMAGEBUTTON name="loopButton" id="aaf66c812391dd97" memberName="loopButton"
               virtualName="" explicitFocusOrder="0" pos="192 14 24 24" tooltip="Turn cycle mode on/off"
               buttonText="End" connectedEdges="0" needsCallback="1" radioGroupId="0"
               keepProportions="1" resourceNormal="foundationiconfonts_20150216_loop_32_0_000000_none_png"
               opacityNormal="1" colourNormal="ffffffff" resourceOver="" opacityOver="1"
               colourOver="ff6495ed" resourceDown="" opacityDown="1" colourDown="ffff9700"/>
  <LABEL name="midiLabel" id="34b33f8ded844f10" memberName="midiLabel"
         virtualName="" explicitFocusOrder="0" pos="344 14 112 24" tooltip="Midi input"
         bkgCol="ff0c0b0b" textCol="ff6495ed" outlineCol="ffffffff" edTextCol="ff000000"
         edBkgCol="0" labelText="no input" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="16"
         bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: fontawesome_470_stop_32_0_000000_none_png, 166, "../../../../Downloads/font-awesome_4-7-0_stop_32_0_000000_none.png"
static const unsigned char resource_TransportPanel_fontawesome_470_stop_32_0_000000_none_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,32,4,3,0,0,0,129,84,103,199,0,0,0,36,80,
76,84,69,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,166,88,2,71,0,0,0,11,116,82,78,83,8,29,32,92,117,119,128,133,235,237,251,222,237,132,210,0,0,0,38,73,68,65,84,40,83,99,
176,218,141,2,26,25,86,163,10,108,99,64,229,239,222,62,42,48,124,4,102,163,10,108,101,80,43,71,1,14,0,35,128,111,226,133,201,186,23,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* TransportPanel::fontawesome_470_stop_32_0_000000_none_png = (const char*) resource_TransportPanel_fontawesome_470_stop_32_0_000000_none_png;
const int TransportPanel::fontawesome_470_stop_32_0_000000_none_pngSize = 166;

// JUCER_RESOURCE: fontawesome_470_play_32_0_000000_none_png, 422, "../../../../Downloads/font-awesome_4-7-0_play_32_0_000000_none.png"
static const unsigned char resource_TransportPanel_fontawesome_470_play_32_0_000000_none_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,32,8,3,0,0,0,68,164,138,198,0,0,0,138,80,
76,84,69,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,19,2,8,47,0,0,0,45,116,82,78,83,0,1,2,3,4,7,8,11,18,19,25,26,27,37,38,47,48,61,62,75,76,92,93,94,105,108,109,130,131,
133,148,149,170,171,186,200,204,206,217,218,232,241,249,251,253,168,229,109,250,0,0,0,158,73,68,65,84,56,203,133,210,201,14,130,64,16,4,208,2,65,92,193,29,119,20,23,96,164,254,255,247,60,25,35,66,117,
93,231,37,83,221,105,96,18,64,231,85,173,60,9,72,22,51,3,144,249,216,0,100,22,25,128,245,62,208,128,172,150,158,6,100,145,24,160,181,45,27,57,71,6,96,189,11,52,104,182,101,91,158,137,1,200,124,100,128,
111,219,78,192,122,107,0,222,122,18,148,115,249,133,91,251,178,228,33,148,99,94,6,114,81,247,169,92,245,167,91,7,112,27,31,10,28,67,64,128,159,110,255,224,17,203,163,45,23,128,0,46,245,161,192,169,15,
8,112,29,66,37,141,229,243,27,114,99,80,144,81,19,133,109,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* TransportPanel::fontawesome_470_play_32_0_000000_none_png = (const char*) resource_TransportPanel_fontawesome_470_play_32_0_000000_none_png;
const int TransportPanel::fontawesome_470_play_32_0_000000_none_pngSize = 422;

// JUCER_RESOURCE: ionicons_201_iosskipbackward_32_0_000000_none_png, 457, "../../../../Downloads/ionicons_2-0-1_ios-skipbackward_32_0_000000_none.png"
static const unsigned char resource_TransportPanel_ionicons_201_iosskipbackward_32_0_000000_none_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,32,8,3,0,0,0,68,164,138,198,0,0,
0,165,80,76,84,69,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,84,254,73,225,0,0,0,54,116,82,78,83,0,1,2,3,4,5,6,9,
11,14,16,20,23,30,32,36,37,42,47,50,59,65,73,75,79,82,87,93,94,112,113,127,130,133,148,154,157,160,170,173,180,181,190,200,206,211,217,224,226,235,237,243,249,251,230,154,226,223,0,0,0,157,73,68,65,84,
56,203,173,210,183,18,194,80,16,67,81,61,178,77,206,57,152,156,76,50,214,255,127,26,133,105,152,177,181,13,183,212,156,110,23,76,10,144,150,27,121,80,160,25,210,23,160,178,37,5,200,205,98,42,208,185,39,
123,6,240,15,223,57,29,228,231,164,2,189,39,21,168,157,73,1,74,43,82,0,55,136,168,64,227,74,10,80,94,147,2,108,38,111,74,144,213,31,193,113,103,128,0,173,208,0,112,195,72,3,160,184,52,0,80,61,25,0,232,
62,12,128,220,52,214,0,63,87,201,248,201,250,197,0,64,255,101,0,20,22,6,0,252,189,1,128,246,205,0,112,99,15,86,31,196,55,133,249,192,32,41,124,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* TransportPanel::ionicons_201_iosskipbackward_32_0_000000_none_png = (const char*) resource_TransportPanel_ionicons_201_iosskipbackward_32_0_000000_none_png;
const int TransportPanel::ionicons_201_iosskipbackward_32_0_000000_none_pngSize = 457;

// JUCER_RESOURCE: ionicons_201_iosskipforward_32_0_000000_none_png, 449, "../../../../Downloads/ionicons_2-0-1_ios-skipforward_32_0_000000_none.png"
static const unsigned char resource_TransportPanel_ionicons_201_iosskipforward_32_0_000000_none_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,32,8,3,0,0,0,68,164,138,198,0,0,0,
162,80,76,84,69,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,160,17,37,58,0,0,0,53,116,82,78,83,0,1,2,3,4,5,6,8,13,14,16,
18,26,27,30,38,39,47,51,56,60,63,69,70,78,84,88,98,100,108,117,120,127,130,137,142,145,163,176,180,195,202,206,213,217,222,228,233,237,241,245,249,253,170,148,64,48,0,0,0,153,73,68,65,84,56,203,181,211,
201,22,193,80,16,132,225,123,17,65,204,243,60,132,16,179,136,255,253,95,205,194,57,86,78,245,74,173,191,77,119,87,187,117,224,126,165,199,39,53,71,54,52,0,28,155,6,128,93,104,0,242,137,215,0,46,109,3,
64,82,49,0,175,121,65,3,184,117,13,0,135,200,0,176,44,25,128,199,192,0,144,214,13,0,241,204,0,223,252,15,156,98,9,178,145,158,98,21,200,61,236,35,185,201,107,71,222,34,159,122,121,205,109,40,251,144,54,
100,163,238,125,221,201,69,81,182,58,169,202,191,56,183,228,103,61,199,222,41,176,41,27,223,109,229,13,130,179,131,124,82,132,131,233,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* TransportPanel::ionicons_201_iosskipforward_32_0_000000_none_png = (const char*) resource_TransportPanel_ionicons_201_iosskipforward_32_0_000000_none_png;
const int TransportPanel::ionicons_201_iosskipforward_32_0_000000_none_pngSize = 449;

// JUCER_RESOURCE: fontawesome_470_pause_32_0_000000_none_png, 224, "../../../../Downloads/font-awesome_4-7-0_pause_32_0_000000_none.png"
static const unsigned char resource_TransportPanel_fontawesome_470_pause_32_0_000000_none_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,32,8,3,0,0,0,68,164,138,198,0,0,0,54,80,
76,84,69,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,183,118,104,114,0,0,0,17,116,82,78,83,0,8,11,12,31,32,62,64,89,92,128,131,133,151,154,
237,251,143,15,74,19,0,0,0,72,73,68,65,84,56,79,237,202,185,1,128,48,16,196,192,225,255,177,221,127,179,68,192,81,1,137,55,147,86,150,92,158,29,192,249,154,60,11,127,41,45,180,209,100,145,74,7,221,71,
213,160,6,53,248,39,72,145,26,104,162,73,134,117,191,183,141,192,180,61,106,237,47,236,220,55,45,117,156,182,15,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* TransportPanel::fontawesome_470_pause_32_0_000000_none_png = (const char*) resource_TransportPanel_fontawesome_470_pause_32_0_000000_none_png;
const int TransportPanel::fontawesome_470_pause_32_0_000000_none_pngSize = 224;

// JUCER_RESOURCE: fontawesome_470_circle_32_0_000000_none_png, 603, "../Resources/font-awesome_4-7-0_circle_32_0_000000_none.png"
static const unsigned char resource_TransportPanel_fontawesome_470_circle_32_0_000000_none_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,32,8,3,0,0,0,68,164,138,198,0,0,0,234,
80,76,84,69,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,198,225,44,73,0,0,0,77,116,82,78,83,0,1,2,3,6,7,8,15,16,20,21,23,28,29,30,35,38,39,47,48,49,58,60,68,71,73,75,81,84,88,89,
91,93,95,97,98,100,102,104,111,112,113,115,117,119,123,124,136,140,143,148,149,151,155,166,168,170,176,190,195,197,204,206,213,217,220,224,228,233,235,237,239,241,243,245,247,253,157,236,231,80,0,0,0,
211,73,68,65,84,24,25,125,193,7,66,194,80,20,69,193,243,131,68,4,11,216,123,197,138,98,5,11,246,40,40,230,238,127,59,34,32,49,152,188,25,34,174,184,115,253,244,249,254,112,177,146,39,65,118,191,173,129,
151,5,71,156,219,8,21,19,148,248,203,111,232,159,170,99,32,23,40,65,221,163,207,15,148,168,70,143,107,40,69,153,174,77,165,42,208,225,135,74,117,71,199,161,12,83,224,190,100,184,132,162,44,97,134,178,
76,19,220,200,180,200,179,76,187,180,101,58,161,41,83,133,71,153,182,184,146,105,142,85,153,198,40,200,210,116,240,42,195,17,176,44,195,40,224,189,41,213,25,63,166,149,166,53,66,215,169,82,204,208,227,
110,149,104,141,95,94,93,9,214,137,184,3,13,251,152,37,102,252,94,49,231,89,134,149,106,161,250,90,149,28,73,50,147,75,123,213,227,237,249,188,35,242,13,52,211,233,144,91,111,132,67,0,0,0,0,73,69,78,68,
174,66,96,130,0,0};

const char* TransportPanel::fontawesome_470_circle_32_0_000000_none_png = (const char*) resource_TransportPanel_fontawesome_470_circle_32_0_000000_none_png;
const int TransportPanel::fontawesome_470_circle_32_0_000000_none_pngSize = 603;

// JUCER_RESOURCE: foundationiconfonts_20150216_loop_32_0_000000_none_png, 781, "../Resources/foundation-icon-fonts_2015-02-16_loop_32_0_000000_none.png"
static const unsigned char resource_TransportPanel_foundationiconfonts_20150216_loop_32_0_000000_none_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,32,8,3,0,0,0,68,164,138,198,
0,0,1,29,80,76,84,69,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,197,222,130,
97,0,0,0,94,116,82,78,83,0,1,2,3,4,5,6,7,8,10,13,14,15,17,20,22,23,26,27,28,30,31,33,35,37,41,47,49,50,55,56,57,58,60,61,63,65,69,71,74,75,77,78,81,89,91,95,97,99,104,108,109,115,116,119,124,137,139,140,
152,155,162,165,168,170,175,176,178,180,181,190,193,195,199,202,204,206,209,217,218,220,224,228,230,232,233,239,241,243,245,247,249,251,253,136,23,246,219,0,0,1,65,73,68,65,84,24,25,117,193,137,66,18,
81,24,134,225,247,252,160,226,154,75,46,153,65,11,216,130,154,45,46,153,154,180,153,152,137,6,42,148,223,253,95,134,195,192,156,25,100,120,30,18,108,58,255,106,189,252,124,126,136,52,110,229,64,145,227,
82,134,251,242,53,37,221,148,29,73,185,35,221,87,29,3,247,254,198,209,54,85,87,191,230,194,196,137,100,4,30,52,149,230,246,159,36,3,114,117,13,102,192,119,117,125,43,140,155,203,76,150,206,20,51,120,161,
142,139,69,34,79,174,20,49,248,172,208,239,17,188,209,95,138,24,100,63,42,112,53,138,87,104,202,51,2,19,135,210,83,188,29,37,24,161,197,18,177,213,115,197,140,52,83,155,23,234,50,6,152,126,247,87,109,
198,229,207,82,142,84,51,31,26,146,161,192,143,226,8,169,230,138,160,142,202,179,97,210,201,251,82,200,18,115,116,41,161,229,136,88,245,207,35,66,138,93,46,225,125,146,116,56,78,64,222,110,22,239,165,
66,107,128,34,85,35,226,182,212,113,10,200,171,229,29,161,165,99,117,61,4,148,208,218,127,251,122,109,175,161,200,54,1,13,118,228,8,72,218,223,86,154,74,134,54,253,95,133,178,250,237,58,66,143,39,9,204,
156,169,87,99,153,94,174,88,83,172,254,198,232,55,187,241,245,90,82,171,178,57,199,64,206,28,189,238,0,112,113,186,136,149,236,230,14,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* TransportPanel::foundationiconfonts_20150216_loop_32_0_000000_none_png = (const char*) resource_TransportPanel_foundationiconfonts_20150216_loop_32_0_000000_none_png;
const int TransportPanel::foundationiconfonts_20150216_loop_32_0_000000_none_pngSize = 781;


//[EndFile] You can add extra defines here...
//[/EndFile]
