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

#include "ToolbarPanel.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ToolbarPanel::ToolbarPanel (MainContentComponent* mcc)
{
    //[Constructor_pre] You can add your own custom stuff here..
    this->mcc = mcc;
    //[/Constructor_pre]

    addAndMakeVisible (addTrackButton = new ImageButton ("addTrackButton"));
    addTrackButton->setTooltip (TRANS("Add a new audio track"));
    addTrackButton->setButtonText (TRANS("new button"));
    addTrackButton->addListener (this);

    addTrackButton->setImages (false, true, true,
                               ImageCache::getFromMemory (ionicons_201_androidaddcircle_24_0_000000_none_png, ionicons_201_androidaddcircle_24_0_000000_none_pngSize), 1.000f, Colours::white,
                               Image(), 1.000f, Colours::cornflowerblue,
                               Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (removeTrackButton = new ImageButton ("removeTrackButton"));
    removeTrackButton->setTooltip (TRANS("Remove selected track"));
    removeTrackButton->setButtonText (TRANS("new button"));
    removeTrackButton->addListener (this);

    removeTrackButton->setImages (false, true, true,
                                  ImageCache::getFromMemory (ionicons_201_androidremovecircle_24_0_000000_none_png, ionicons_201_androidremovecircle_24_0_000000_none_pngSize), 1.000f, Colours::white,
                                  Image(), 1.000f, Colours::cornflowerblue,
                                  Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (copyButton = new ImageButton ("copyButton"));
    copyButton->setTooltip (TRANS("Copy "));
    copyButton->setButtonText (TRANS("new button"));
    copyButton->addListener (this);

    copyButton->setImages (false, true, true,
                           ImageCache::getFromMemory (fontawesome_470_copy_24_0_000000_none_png, fontawesome_470_copy_24_0_000000_none_pngSize), 1.000f, Colours::white,
                           Image(), 1.000f, Colours::cornflowerblue,
                           Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (editButton = new ImageButton ("editButton"));
    editButton->setTooltip (TRANS("Edit"));
    editButton->setButtonText (TRANS("new button"));
    editButton->addListener (this);

    editButton->setImages (false, true, true,
                           ImageCache::getFromMemory (fontawesome_470_pencil_24_0_000000_none_png, fontawesome_470_pencil_24_0_000000_none_pngSize), 1.000f, Colours::white,
                           Image(), 1.000f, Colours::cornflowerblue,
                           Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (settingsButton = new ImageButton ("settingsButton"));
    settingsButton->setTooltip (TRANS("Settings"));
    settingsButton->setButtonText (TRANS("new button"));
    settingsButton->addListener (this);

    settingsButton->setImages (false, true, true,
                               ImageCache::getFromMemory (ionicons_201_settings_24_0_000000_none_png, ionicons_201_settings_24_0_000000_none_pngSize), 1.000f, Colours::white,
                               Image(), 1.000f, Colours::cornflowerblue,
                               Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (importAudioButton = new ImageButton ("importAudioButton"));
    importAudioButton->setTooltip (TRANS("Import audio on selected track"));
    importAudioButton->setButtonText (TRANS("new button"));
    importAudioButton->addListener (this);

    importAudioButton->setImages (false, true, true,
                                  ImageCache::getFromMemory (fontawesome_470_fileaudioo_32_0_000000_none_png, fontawesome_470_fileaudioo_32_0_000000_none_pngSize), 1.000f, Colours::white,
                                  Image(), 1.000f, Colours::cornflowerblue,
                                  Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (pluginsButton = new ImageButton ("pluginsButton"));
    pluginsButton->setButtonText (TRANS("new button"));
    pluginsButton->addListener (this);

    pluginsButton->setImages (false, true, true,
                              ImageCache::getFromMemory (fontawesome_470_plug_32_0_000000_none_png, fontawesome_470_plug_32_0_000000_none_pngSize), 1.000f, Colours::white,
                              Image(), 1.000f, Colours::cornflowerblue,
                              Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (addMidiTrackButton = new ImageButton ("addMidiTrackButton"));
    addMidiTrackButton->setTooltip (TRANS("Add a new Midi track"));
    addMidiTrackButton->setButtonText (TRANS("new button"));
    addMidiTrackButton->addListener (this);

    addMidiTrackButton->setImages (false, true, true,
                                   ImageCache::getFromMemory (fontawesome_470_music_32_0_000000_none_png, fontawesome_470_music_32_0_000000_none_pngSize), 1.000f, Colours::white,
                                   Image(), 1.000f, Colours::cornflowerblue,
                                   Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (mixerButton = new ImageButton ("mixerButton"));
    mixerButton->setTooltip (TRANS("Toggles the mixer"));
    mixerButton->setButtonText (TRANS("new button"));
    mixerButton->addListener (this);

    mixerButton->setImages (false, true, true,
                            ImageCache::getFromMemory (mixer_128px_png, mixer_128px_pngSize), 1.000f, Colours::white,
                            Image(), 1.000f, Colours::cornflowerblue,
                            Image(), 1.000f, Colours::cornflowerblue);

    //[UserPreSize]
    //[/UserPreSize]

    setSize (130, 50);


    //[Constructor] You can add your own custom stuff here..
    mixerButton->setClickingTogglesState(true);
    mixerButton->setToggleState(true, juce::NotificationType::dontSendNotification);
    //[/Constructor]
}

ToolbarPanel::~ToolbarPanel()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    addTrackButton = nullptr;
    removeTrackButton = nullptr;
    copyButton = nullptr;
    editButton = nullptr;
    settingsButton = nullptr;
    importAudioButton = nullptr;
    pluginsButton = nullptr;
    addMidiTrackButton = nullptr;
    mixerButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ToolbarPanel::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    g.setColour(Colours::darkgrey);
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ToolbarPanel::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    addTrackButton->setBounds (66, 14, 24, 24);
    removeTrackButton->setBounds (96, 14, 24, 24);
    copyButton->setBounds (160, 14, 24, 24);
    editButton->setBounds (192, 14, 24, 24);
    settingsButton->setBounds (224, 14, 24, 24);
    importAudioButton->setBounds (256, 14, 24, 24);
    pluginsButton->setBounds (288, 14, 24, 24);
    addMidiTrackButton->setBounds (128, 14, 24, 24);
    mixerButton->setBounds (12, 14, 24, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ToolbarPanel::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == addTrackButton)
    {
        //[UserButtonCode_addTrackButton] -- add your button handler code here..
        mcc->addTrack(Track::Type::AUDIO);
        //[/UserButtonCode_addTrackButton]
    }
    else if (buttonThatWasClicked == removeTrackButton)
    {
        //[UserButtonCode_removeTrackButton] -- add your button handler code here..
		mcc->removeSelectedTrack();
        //[/UserButtonCode_removeTrackButton]
    }
    else if (buttonThatWasClicked == copyButton)
    {
        //[UserButtonCode_copyButton] -- add your button handler code here..
        //[/UserButtonCode_copyButton]
    }
    else if (buttonThatWasClicked == editButton)
    {
        //[UserButtonCode_editButton] -- add your button handler code here..
        //[/UserButtonCode_editButton]
    }
    else if (buttonThatWasClicked == settingsButton)
    {
        //[UserButtonCode_settingsButton] -- add your button handler code here..
        mcc->openSettings();
        //[/UserButtonCode_settingsButton]
    }
    else if (buttonThatWasClicked == importAudioButton)
    {
        //[UserButtonCode_importAudioButton] -- add your button handler code here..
        mcc->importAudio();
        //[/UserButtonCode_importAudioButton]
    }
    else if (buttonThatWasClicked == pluginsButton)
    {
        //[UserButtonCode_pluginsButton] -- add your button handler code here..
        mcc->addPlugin("Trio");
        //[/UserButtonCode_pluginsButton]
    }
    else if (buttonThatWasClicked == addMidiTrackButton)
    {
        //[UserButtonCode_addMidiTrackButton] -- add your button handler code here..
        mcc->addTrack(Track::Type::MIDI);
        //[/UserButtonCode_addMidiTrackButton]
    }
    else if (buttonThatWasClicked == mixerButton)
    {
        //[UserButtonCode_mixerButton] -- add your button handler code here..
        sendChangeMessage();
        //[/UserButtonCode_mixerButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ToolbarPanel" componentName=""
                 parentClasses="public Component, public ChangeBroadcaster" constructorParams="MainContentComponent* mcc"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="130" initialHeight="50">
  <BACKGROUND backgroundColour="ffffff"/>
  <IMAGEBUTTON name="addTrackButton" id="b040fab84432c089" memberName="addTrackButton"
               virtualName="" explicitFocusOrder="0" pos="66 14 24 24" tooltip="Add a new audio track"
               buttonText="new button" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="ionicons_201_androidaddcircle_24_0_000000_none_png"
               opacityNormal="1" colourNormal="ffffffff" resourceOver="" opacityOver="1"
               colourOver="ff6495ed" resourceDown="" opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="removeTrackButton" id="70f6412688935645" memberName="removeTrackButton"
               virtualName="" explicitFocusOrder="0" pos="96 14 24 24" tooltip="Remove selected track"
               buttonText="new button" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="ionicons_201_androidremovecircle_24_0_000000_none_png"
               opacityNormal="1" colourNormal="ffffffff" resourceOver="" opacityOver="1"
               colourOver="ff6495ed" resourceDown="" opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="copyButton" id="14fb30dd46ca0d9a" memberName="copyButton"
               virtualName="" explicitFocusOrder="0" pos="160 14 24 24" tooltip="Copy "
               buttonText="new button" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="fontawesome_470_copy_24_0_000000_none_png"
               opacityNormal="1" colourNormal="ffffffff" resourceOver="" opacityOver="1"
               colourOver="ff6495ed" resourceDown="" opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="editButton" id="aae00a5880931a24" memberName="editButton"
               virtualName="" explicitFocusOrder="0" pos="192 14 24 24" tooltip="Edit"
               buttonText="new button" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="fontawesome_470_pencil_24_0_000000_none_png"
               opacityNormal="1" colourNormal="ffffffff" resourceOver="" opacityOver="1"
               colourOver="ff6495ed" resourceDown="" opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="settingsButton" id="291742b3ea36a25e" memberName="settingsButton"
               virtualName="" explicitFocusOrder="0" pos="224 14 24 24" tooltip="Settings"
               buttonText="new button" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="ionicons_201_settings_24_0_000000_none_png"
               opacityNormal="1" colourNormal="ffffffff" resourceOver="" opacityOver="1"
               colourOver="ff6495ed" resourceDown="" opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="importAudioButton" id="1584ca1f93618745" memberName="importAudioButton"
               virtualName="" explicitFocusOrder="0" pos="256 14 24 24" tooltip="Import audio on selected track"
               buttonText="new button" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="fontawesome_470_fileaudioo_32_0_000000_none_png"
               opacityNormal="1" colourNormal="ffffffff" resourceOver="" opacityOver="1"
               colourOver="ff6495ed" resourceDown="" opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="pluginsButton" id="3f2551fd0588fd22" memberName="pluginsButton"
               virtualName="" explicitFocusOrder="0" pos="288 14 24 24" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="fontawesome_470_plug_32_0_000000_none_png" opacityNormal="1"
               colourNormal="ffffffff" resourceOver="" opacityOver="1" colourOver="ff6495ed"
               resourceDown="" opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="addMidiTrackButton" id="db543ed06f17880d" memberName="addMidiTrackButton"
               virtualName="" explicitFocusOrder="0" pos="128 14 24 24" tooltip="Add a new Midi track"
               buttonText="new button" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="fontawesome_470_music_32_0_000000_none_png"
               opacityNormal="1" colourNormal="ffffffff" resourceOver="" opacityOver="1"
               colourOver="ff6495ed" resourceDown="" opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="mixerButton" id="ff6a6c93dbb88dcf" memberName="mixerButton"
               virtualName="" explicitFocusOrder="0" pos="12 14 24 24" tooltip="Toggles the mixer"
               buttonText="new button" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="mixer_128px_png"
               opacityNormal="1" colourNormal="ffffffff" resourceOver="" opacityOver="1"
               colourOver="ff6495ed" resourceDown="" opacityDown="1" colourDown="ff6495ed"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: fontawesome_470_pencil_24_0_000000_none_png, 285, "../../../../Downloads/font-awesome_4-7-0_pencil_24_0_000000_none.png"
static const unsigned char resource_ToolbarPanel_fontawesome_470_pencil_24_0_000000_none_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,24,0,0,0,24,8,3,0,0,0,215,169,205,202,0,0,0,60,80,
76,84,69,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,208,47,38,48,0,0,0,19,116,82,78,83,0,1,2,4,7,16,52,80,81,145,154,192,193,
195,197,199,206,213,251,69,138,179,254,0,0,0,125,73,68,65,84,40,207,165,145,203,14,131,48,12,4,151,24,218,240,168,75,153,255,255,215,30,80,80,66,220,83,125,156,81,188,86,86,186,77,202,207,164,96,108,3,
183,128,191,32,52,51,68,198,204,252,52,239,38,199,220,47,147,27,14,151,201,13,247,71,49,158,26,62,149,55,85,120,225,224,102,115,196,219,91,107,30,239,249,155,239,63,248,241,217,123,46,103,25,215,128,11,
6,217,26,124,54,72,167,185,149,0,32,141,71,87,14,128,134,165,175,51,202,173,68,207,191,53,6,15,125,77,49,71,165,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* ToolbarPanel::fontawesome_470_pencil_24_0_000000_none_png = (const char*) resource_ToolbarPanel_fontawesome_470_pencil_24_0_000000_none_png;
const int ToolbarPanel::fontawesome_470_pencil_24_0_000000_none_pngSize = 285;

// JUCER_RESOURCE: fontawesome_470_copy_24_0_000000_none_png, 436, "../../../../Downloads/font-awesome_4-7-0_copy_24_0_000000_none.png"
static const unsigned char resource_ToolbarPanel_fontawesome_470_copy_24_0_000000_none_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,24,0,0,0,24,8,3,0,0,0,215,169,205,202,0,0,0,141,80,
76,84,69,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,234,135,51,248,0,0,0,46,116,82,78,83,0,2,3,4,5,6,7,17,26,31,44,46,47,57,64,67,68,75,79,81,92,102,120,154,158,163,
166,173,175,176,178,181,183,186,188,193,195,200,202,206,224,239,243,245,251,253,21,208,222,144,0,0,0,168,73,68,65,84,40,207,189,145,201,18,130,48,16,68,199,96,220,119,196,13,149,32,110,136,244,255,127,
158,19,8,20,196,156,60,248,46,73,245,155,170,116,77,136,74,102,123,165,9,135,212,162,115,128,33,108,231,71,64,21,55,115,24,68,132,192,37,196,5,1,57,132,119,229,188,22,241,96,233,51,171,62,121,55,157,215,
162,226,73,27,32,230,158,56,23,45,56,154,75,38,1,165,229,68,54,213,249,9,59,140,245,132,66,243,57,17,99,221,115,8,110,177,32,249,45,186,247,124,66,46,177,69,202,37,18,140,44,33,76,207,135,180,132,132,
223,216,198,79,34,127,21,63,196,175,90,34,120,87,235,177,68,133,252,131,240,208,34,251,0,13,53,33,46,79,219,200,64,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* ToolbarPanel::fontawesome_470_copy_24_0_000000_none_png = (const char*) resource_ToolbarPanel_fontawesome_470_copy_24_0_000000_none_png;
const int ToolbarPanel::fontawesome_470_copy_24_0_000000_none_pngSize = 436;

// JUCER_RESOURCE: ionicons_201_androidremovecircle_24_0_000000_none_png, 458, "../../../../Downloads/ionicons_2-0-1_android-remove-circle_24_0_000000_none.png"
static const unsigned char resource_ToolbarPanel_ionicons_201_androidremovecircle_24_0_000000_none_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,24,0,0,0,24,8,3,0,0,0,215,169,205,202,0,
0,0,162,80,76,84,69,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,160,17,37,58,0,0,0,53,116,82,78,83,0,1,3,5,6,7,9,12,13,22,
32,33,35,36,46,53,55,61,62,64,68,112,113,115,126,127,128,133,140,149,151,163,166,180,181,183,185,192,193,197,200,204,206,222,224,233,235,237,239,241,243,245,253,166,107,217,0,0,0,0,162,73,68,65,84,40,
207,117,146,217,18,130,48,20,67,83,168,184,161,226,138,59,238,43,42,162,249,255,95,243,129,169,83,244,246,60,38,51,109,147,6,40,8,122,139,99,118,93,15,155,10,54,149,49,13,105,199,210,195,156,22,137,103,
244,46,203,156,117,161,55,248,203,86,1,128,255,248,51,24,3,192,136,2,85,64,191,37,99,10,68,146,206,28,152,139,6,235,216,203,70,27,55,146,156,89,105,53,73,114,128,187,203,56,184,142,114,94,238,124,174,
51,160,92,73,13,128,159,57,74,20,106,223,41,249,163,46,218,100,106,189,108,125,229,89,99,152,124,229,52,42,205,4,65,127,121,122,166,155,56,52,243,249,0,207,125,84,75,193,149,101,141,0,0,0,0,73,69,78,68,
174,66,96,130,0,0};

const char* ToolbarPanel::ionicons_201_androidremovecircle_24_0_000000_none_png = (const char*) resource_ToolbarPanel_ionicons_201_androidremovecircle_24_0_000000_none_png;
const int ToolbarPanel::ionicons_201_androidremovecircle_24_0_000000_none_pngSize = 458;

// JUCER_RESOURCE: ionicons_201_androidaddcircle_24_0_000000_none_png, 509, "../../../../Downloads/ionicons_2-0-1_android-add-circle_24_0_000000_none.png"
static const unsigned char resource_ToolbarPanel_ionicons_201_androidaddcircle_24_0_000000_none_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,24,0,0,0,24,8,3,0,0,0,215,169,205,202,0,0,
0,183,80,76,84,69,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,90,229,159,67,0,
0,0,60,116,82,78,83,0,1,3,5,6,7,9,12,13,22,32,33,35,36,46,53,55,59,61,62,64,68,91,112,113,115,126,127,128,133,140,149,151,163,166,170,176,180,181,183,185,186,192,193,197,200,204,206,222,224,230,232,233,
235,237,239,241,243,245,253,3,62,195,15,0,0,0,185,73,68,65,84,40,145,117,146,215,18,130,48,20,68,23,4,108,168,136,21,123,197,94,176,33,154,255,255,46,9,24,12,146,156,151,29,246,204,16,238,37,64,140,209,
24,239,253,243,178,83,86,192,163,247,8,195,171,113,189,25,16,142,169,202,122,155,164,57,106,113,95,34,255,172,162,131,114,143,140,32,14,21,93,246,212,6,18,147,7,180,183,72,12,0,139,136,68,0,140,132,130,
20,177,165,113,153,135,212,1,26,110,36,170,184,209,24,114,211,106,145,104,225,46,19,59,26,215,69,136,13,208,216,124,95,37,61,92,250,185,210,1,197,43,41,208,37,250,36,131,35,89,251,90,17,255,168,147,198,
102,170,188,248,126,166,254,166,213,251,73,237,89,169,107,2,163,57,57,60,61,215,49,217,245,249,0,50,59,87,48,73,12,78,64,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* ToolbarPanel::ionicons_201_androidaddcircle_24_0_000000_none_png = (const char*) resource_ToolbarPanel_ionicons_201_androidaddcircle_24_0_000000_none_png;
const int ToolbarPanel::ionicons_201_androidaddcircle_24_0_000000_none_pngSize = 509;

// JUCER_RESOURCE: ionicons_201_settings_24_0_000000_none_png, 725, "../../../../Downloads/ionicons_2-0-1_settings_24_0_000000_none.png"
static const unsigned char resource_ToolbarPanel_ionicons_201_settings_24_0_000000_none_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,24,0,0,0,24,8,3,0,0,0,215,169,205,202,0,0,1,32,80,
76,84,69,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,222,138,125,218,
0,0,0,95,116,82,78,83,0,1,2,3,4,5,6,7,8,9,10,11,15,16,18,20,24,25,26,28,29,32,34,35,39,40,44,48,49,50,52,53,54,57,58,62,73,75,76,77,78,81,85,93,95,98,104,107,116,117,124,127,130,133,134,137,142,149,154,
155,157,160,162,166,171,173,175,176,180,181,183,185,186,190,199,202,204,206,207,211,213,215,217,218,226,228,230,235,237,239,243,247,249,251,253,67,127,93,39,0,0,1,5,73,68,65,84,24,25,133,193,231,54,67,
65,24,134,209,103,6,17,17,189,119,162,247,222,75,148,16,34,122,244,242,222,255,93,248,70,142,195,15,107,217,155,136,79,240,39,159,187,174,38,232,62,126,59,75,241,99,71,186,73,2,179,146,38,249,101,91,210,
173,167,77,250,24,32,230,54,62,100,70,96,75,154,35,240,24,151,147,180,209,146,1,238,165,167,52,80,81,104,7,150,101,218,8,238,36,149,106,240,39,154,128,30,5,29,4,235,50,87,117,89,105,0,174,21,228,28,102,
83,145,247,4,189,42,91,5,230,245,109,20,86,148,175,167,106,70,42,205,45,42,242,216,7,20,47,60,38,163,178,65,215,208,217,228,48,119,67,4,181,175,10,198,136,29,180,18,184,67,153,2,63,134,187,48,110,91,95,
214,28,177,4,224,246,20,217,245,252,226,178,50,167,147,50,249,74,98,126,95,230,188,146,25,153,203,36,17,119,36,115,91,13,44,201,148,210,148,77,201,60,164,8,118,101,198,41,91,144,244,92,199,23,95,148,166,
137,52,75,47,141,68,82,143,179,196,210,253,73,98,73,254,241,9,147,155,78,235,246,82,174,74,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* ToolbarPanel::ionicons_201_settings_24_0_000000_none_png = (const char*) resource_ToolbarPanel_ionicons_201_settings_24_0_000000_none_png;
const int ToolbarPanel::ionicons_201_settings_24_0_000000_none_pngSize = 725;

// JUCER_RESOURCE: fontawesome_470_fileaudioo_32_0_000000_none_png, 622, "../Resources/font-awesome_4-7-0_file-audio-o_32_0_000000_none.png"
static const unsigned char resource_ToolbarPanel_fontawesome_470_fileaudioo_32_0_000000_none_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,32,8,3,0,0,0,68,164,138,198,0,0,0,216,
80,76,84,69,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,87,240,186,90,0,0,0,71,116,82,78,83,0,1,2,3,4,5,6,7,8,11,14,19,20,21,23,30,33,34,38,44,48,49,50,51,52,54,56,66,71,78,81,84,86,87,92,94,99,102,103,109,123,128,
130,133,140,146,148,170,178,180,181,183,185,188,192,193,197,199,204,206,213,222,224,226,233,235,239,241,243,249,253,144,85,102,127,0,0,0,254,73,68,65,84,56,141,157,211,89,83,194,48,24,133,225,67,91,163,
113,195,189,138,10,138,251,142,34,138,11,17,215,247,255,255,35,47,90,181,83,210,232,120,110,114,145,103,50,249,78,38,146,90,148,243,188,83,83,33,111,35,0,58,81,1,128,41,122,65,234,184,140,66,192,88,71,
55,10,1,89,199,117,28,2,178,142,94,28,2,178,142,155,40,4,100,29,251,85,96,198,24,99,76,202,171,31,12,127,234,48,94,176,50,252,5,148,47,243,15,176,254,94,175,0,249,27,238,242,20,123,193,106,62,86,60,96,
219,7,82,144,166,6,45,169,193,75,109,20,44,3,210,34,204,41,130,233,18,56,203,230,150,244,200,133,116,69,163,4,186,223,224,0,164,83,54,43,193,30,72,231,108,84,130,91,122,210,61,75,37,176,208,108,246,1,
105,30,82,141,131,29,157,34,233,131,84,231,72,106,243,224,235,33,185,35,107,115,242,131,53,111,147,99,237,108,61,164,19,126,172,217,227,137,48,248,202,159,129,239,111,230,73,36,73,91,149,251,39,249,81,
177,241,39,145,164,79,235,206,92,240,55,73,238,144,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* ToolbarPanel::fontawesome_470_fileaudioo_32_0_000000_none_png = (const char*) resource_ToolbarPanel_fontawesome_470_fileaudioo_32_0_000000_none_png;
const int ToolbarPanel::fontawesome_470_fileaudioo_32_0_000000_none_pngSize = 622;

// JUCER_RESOURCE: fontawesome_470_plug_32_0_000000_none_png, 522, "../Resources/font-awesome_4-7-0_plug_32_0_000000_none.png"
static const unsigned char resource_ToolbarPanel_fontawesome_470_plug_32_0_000000_none_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,32,8,3,0,0,0,68,164,138,198,0,0,0,168,80,76,
84,69,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,44,223,72,134,0,0,0,55,116,82,78,83,0,1,2,3,5,7,10,12,13,22,
23,24,28,32,37,48,53,65,73,79,81,82,84,85,86,87,88,91,102,103,105,123,124,126,127,130,145,148,165,166,168,170,173,178,183,193,206,213,218,222,226,228,243,245,247,88,166,243,10,0,0,0,218,73,68,65,84,56,
141,149,210,233,18,130,32,20,5,224,171,217,158,217,98,105,169,45,182,154,149,165,213,125,255,55,203,61,20,208,233,252,96,96,190,51,12,3,0,48,162,33,62,37,22,164,89,98,152,49,223,23,145,163,194,117,45,
246,35,67,132,120,156,199,126,18,104,23,93,51,28,103,21,142,104,129,202,117,193,141,228,26,251,57,115,35,112,90,89,225,128,121,114,183,195,133,147,206,39,28,199,32,153,75,175,220,3,145,116,52,146,133,
250,219,0,77,210,237,180,237,97,185,145,248,54,117,9,177,212,40,58,244,139,5,180,74,14,50,178,178,129,234,2,225,208,97,248,186,112,207,111,186,176,42,188,196,142,177,133,69,22,186,172,67,168,100,99,79,
187,215,36,188,237,255,237,247,26,63,53,40,255,12,167,249,155,251,35,160,125,16,126,75,101,119,11,30,23,75,6,182,115,82,231,80,231,80,231,160,235,122,175,202,191,52,87,93,217,174,14,186,251,0,0,0,0,73,
69,78,68,174,66,96,130,0,0};

const char* ToolbarPanel::fontawesome_470_plug_32_0_000000_none_png = (const char*) resource_ToolbarPanel_fontawesome_470_plug_32_0_000000_none_png;
const int ToolbarPanel::fontawesome_470_plug_32_0_000000_none_pngSize = 522;

// JUCER_RESOURCE: fontawesome_470_music_32_0_000000_none_png, 549, "../Resources/font-awesome_4-7-0_music_32_0_000000_none.png"
static const unsigned char resource_ToolbarPanel_fontawesome_470_music_32_0_000000_none_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,32,0,0,0,32,8,3,0,0,0,68,164,138,198,0,0,0,195,80,
76,84,69,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,64,
112,171,32,0,0,0,64,116,82,78,83,0,1,2,3,4,5,6,8,11,12,15,16,17,20,23,27,28,41,42,53,60,61,70,75,80,84,95,103,104,109,117,128,130,131,136,140,142,146,151,157,160,162,165,166,170,173,181,186,188,193,197,
209,215,217,220,222,226,232,235,241,243,247,251,253,112,253,127,32,0,0,0,209,73,68,65,84,56,203,197,146,215,18,130,48,16,69,67,48,34,86,192,222,123,23,17,123,103,255,255,171,156,80,148,146,224,155,222,
167,236,158,51,201,78,18,132,184,17,181,74,146,79,165,210,220,2,216,113,104,182,102,130,19,18,133,130,210,58,193,59,97,65,212,250,119,240,39,40,40,244,88,224,11,228,9,16,43,228,224,215,130,53,109,199,
8,183,174,138,105,131,45,28,155,5,193,109,48,4,179,150,241,53,194,194,178,44,5,27,97,33,120,179,255,22,4,28,39,168,189,43,192,115,214,230,8,100,195,127,11,187,30,193,23,225,234,19,18,46,195,114,154,176,
118,216,58,180,106,208,226,48,246,102,48,60,190,151,105,157,138,254,114,109,112,3,120,76,138,246,155,162,5,115,38,140,223,203,139,79,16,17,35,157,15,95,177,56,18,134,30,215,9,98,39,83,215,207,151,117,
35,207,132,47,184,32,91,213,63,98,137,50,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* ToolbarPanel::fontawesome_470_music_32_0_000000_none_png = (const char*) resource_ToolbarPanel_fontawesome_470_music_32_0_000000_none_png;
const int ToolbarPanel::fontawesome_470_music_32_0_000000_none_pngSize = 549;

// JUCER_RESOURCE: mixer_128px_png, 17238, "../Resources/mixer_128px.png"
static const unsigned char resource_ToolbarPanel_mixer_128px_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,128,0,0,0,128,8,6,0,0,0,195,62,97,203,0,0,0,9,112,72,89,115,0,0,11,19,0,0,11,
19,1,0,154,156,24,0,0,57,250,105,84,88,116,88,77,76,58,99,111,109,46,97,100,111,98,101,46,120,109,112,0,0,0,0,0,60,63,120,112,97,99,107,101,116,32,98,101,103,105,110,61,34,239,187,191,34,32,105,100,61,
34,87,53,77,48,77,112,67,101,104,105,72,122,114,101,83,122,78,84,99,122,107,99,57,100,34,63,62,10,60,120,58,120,109,112,109,101,116,97,32,120,109,108,110,115,58,120,61,34,97,100,111,98,101,58,110,115,
58,109,101,116,97,47,34,32,120,58,120,109,112,116,107,61,34,65,100,111,98,101,32,88,77,80,32,67,111,114,101,32,53,46,54,45,99,49,51,50,32,55,57,46,49,53,57,50,56,52,44,32,50,48,49,54,47,48,52,47,49,57,
45,49,51,58,49,51,58,52,48,32,32,32,32,32,32,32,32,34,62,10,32,32,32,60,114,100,102,58,82,68,70,32,120,109,108,110,115,58,114,100,102,61,34,104,116,116,112,58,47,47,119,119,119,46,119,51,46,111,114,103,
47,49,57,57,57,47,48,50,47,50,50,45,114,100,102,45,115,121,110,116,97,120,45,110,115,35,34,62,10,32,32,32,32,32,32,60,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,32,114,100,102,58,97,98,111,
117,116,61,34,34,10,32,32,32,32,32,32,32,32,32,32,32,32,120,109,108,110,115,58,120,109,112,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,34,10,
32,32,32,32,32,32,32,32,32,32,32,32,120,109,108,110,115,58,100,99,61,34,104,116,116,112,58,47,47,112,117,114,108,46,111,114,103,47,100,99,47,101,108,101,109,101,110,116,115,47,49,46,49,47,34,10,32,32,
32,32,32,32,32,32,32,32,32,32,120,109,108,110,115,58,112,104,111,116,111,115,104,111,112,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,112,104,111,116,111,115,104,111,112,
47,49,46,48,47,34,10,32,32,32,32,32,32,32,32,32,32,32,32,120,109,108,110,115,58,120,109,112,77,77,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,
109,109,47,34,10,32,32,32,32,32,32,32,32,32,32,32,32,120,109,108,110,115,58,115,116,69,118,116,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,46,99,111,109,47,120,97,112,47,49,46,48,47,115,
84,121,112,101,47,82,101,115,111,117,114,99,101,69,118,101,110,116,35,34,10,32,32,32,32,32,32,32,32,32,32,32,32,120,109,108,110,115,58,116,105,102,102,61,34,104,116,116,112,58,47,47,110,115,46,97,100,
111,98,101,46,99,111,109,47,116,105,102,102,47,49,46,48,47,34,10,32,32,32,32,32,32,32,32,32,32,32,32,120,109,108,110,115,58,101,120,105,102,61,34,104,116,116,112,58,47,47,110,115,46,97,100,111,98,101,
46,99,111,109,47,101,120,105,102,47,49,46,48,47,34,62,10,32,32,32,32,32,32,32,32,32,60,120,109,112,58,67,114,101,97,116,111,114,84,111,111,108,62,65,100,111,98,101,32,80,104,111,116,111,115,104,111,112,
32,67,67,32,50,48,49,53,46,53,32,40,77,97,99,105,110,116,111,115,104,41,60,47,120,109,112,58,67,114,101,97,116,111,114,84,111,111,108,62,10,32,32,32,32,32,32,32,32,32,60,120,109,112,58,67,114,101,97,116,
101,68,97,116,101,62,50,48,49,54,45,49,50,45,51,48,84,48,57,58,48,51,58,51,48,43,48,49,58,48,48,60,47,120,109,112,58,67,114,101,97,116,101,68,97,116,101,62,10,32,32,32,32,32,32,32,32,32,60,120,109,112,
58,77,111,100,105,102,121,68,97,116,101,62,50,48,49,54,45,49,50,45,51,48,84,48,57,58,48,52,58,52,52,43,48,49,58,48,48,60,47,120,109,112,58,77,111,100,105,102,121,68,97,116,101,62,10,32,32,32,32,32,32,
32,32,32,60,120,109,112,58,77,101,116,97,100,97,116,97,68,97,116,101,62,50,48,49,54,45,49,50,45,51,48,84,48,57,58,48,52,58,52,52,43,48,49,58,48,48,60,47,120,109,112,58,77,101,116,97,100,97,116,97,68,97,
116,101,62,10,32,32,32,32,32,32,32,32,32,60,100,99,58,102,111,114,109,97,116,62,105,109,97,103,101,47,112,110,103,60,47,100,99,58,102,111,114,109,97,116,62,10,32,32,32,32,32,32,32,32,32,60,112,104,111,
116,111,115,104,111,112,58,67,111,108,111,114,77,111,100,101,62,51,60,47,112,104,111,116,111,115,104,111,112,58,67,111,108,111,114,77,111,100,101,62,10,32,32,32,32,32,32,32,32,32,60,120,109,112,77,77,
58,73,110,115,116,97,110,99,101,73,68,62,120,109,112,46,105,105,100,58,99,52,99,52,53,98,97,53,45,51,101,97,102,45,52,100,101,52,45,56,49,48,55,45,51,49,49,48,54,52,55,51,52,55,52,100,60,47,120,109,112,
77,77,58,73,110,115,116,97,110,99,101,73,68,62,10,32,32,32,32,32,32,32,32,32,60,120,109,112,77,77,58,68,111,99,117,109,101,110,116,73,68,62,97,100,111,98,101,58,100,111,99,105,100,58,112,104,111,116,111,
115,104,111,112,58,102,55,57,53,51,98,99,48,45,48,101,102,52,45,49,49,55,97,45,56,102,49,101,45,101,101,102,102,52,56,97,51,57,57,50,57,60,47,120,109,112,77,77,58,68,111,99,117,109,101,110,116,73,68,62,
10,32,32,32,32,32,32,32,32,32,60,120,109,112,77,77,58,79,114,105,103,105,110,97,108,68,111,99,117,109,101,110,116,73,68,62,120,109,112,46,100,105,100,58,52,54,99,53,53,49,48,99,45,52,50,99,56,45,52,56,
49,49,45,98,52,55,54,45,53,99,99,55,55,101,99,49,102,97,55,51,60,47,120,109,112,77,77,58,79,114,105,103,105,110,97,108,68,111,99,117,109,101,110,116,73,68,62,10,32,32,32,32,32,32,32,32,32,60,120,109,112,
77,77,58,72,105,115,116,111,114,121,62,10,32,32,32,32,32,32,32,32,32,32,32,32,60,114,100,102,58,83,101,113,62,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,60,114,100,102,58,108,105,32,114,100,102,58,
112,97,114,115,101,84,121,112,101,61,34,82,101,115,111,117,114,99,101,34,62,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,60,115,116,69,118,116,58,97,99,116,105,111,110,62,99,114,101,97,116,
101,100,60,47,115,116,69,118,116,58,97,99,116,105,111,110,62,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,60,115,116,69,118,116,58,105,110,115,116,97,110,99,101,73,68,62,120,109,112,46,105,
105,100,58,52,54,99,53,53,49,48,99,45,52,50,99,56,45,52,56,49,49,45,98,52,55,54,45,53,99,99,55,55,101,99,49,102,97,55,51,60,47,115,116,69,118,116,58,105,110,115,116,97,110,99,101,73,68,62,10,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,60,115,116,69,118,116,58,119,104,101,110,62,50,48,49,54,45,49,50,45,51,48,84,48,57,58,48,51,58,51,48,43,48,49,58,48,48,60,47,115,116,69,118,116,58,119,104,
101,110,62,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,60,115,116,69,118,116,58,115,111,102,116,119,97,114,101,65,103,101,110,116,62,65,100,111,98,101,32,80,104,111,116,111,115,104,111,112,
32,67,67,32,50,48,49,53,46,53,32,40,77,97,99,105,110,116,111,115,104,41,60,47,115,116,69,118,116,58,115,111,102,116,119,97,114,101,65,103,101,110,116,62,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
60,47,114,100,102,58,108,105,62,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,60,114,100,102,58,108,105,32,114,100,102,58,112,97,114,115,101,84,121,112,101,61,34,82,101,115,111,117,114,99,101,34,62,
10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,60,115,116,69,118,116,58,97,99,116,105,111,110,62,115,97,118,101,100,60,47,115,116,69,118,116,58,97,99,116,105,111,110,62,10,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,60,115,116,69,118,116,58,105,110,115,116,97,110,99,101,73,68,62,120,109,112,46,105,105,100,58,99,52,99,52,53,98,97,53,45,51,101,97,102,45,52,100,101,52,45,56,49,48,
55,45,51,49,49,48,54,52,55,51,52,55,52,100,60,47,115,116,69,118,116,58,105,110,115,116,97,110,99,101,73,68,62,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,60,115,116,69,118,116,58,119,104,
101,110,62,50,48,49,54,45,49,50,45,51,48,84,48,57,58,48,52,58,52,52,43,48,49,58,48,48,60,47,115,116,69,118,116,58,119,104,101,110,62,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,60,115,116,
69,118,116,58,115,111,102,116,119,97,114,101,65,103,101,110,116,62,65,100,111,98,101,32,80,104,111,116,111,115,104,111,112,32,67,67,32,50,48,49,53,46,53,32,40,77,97,99,105,110,116,111,115,104,41,60,47,
115,116,69,118,116,58,115,111,102,116,119,97,114,101,65,103,101,110,116,62,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,60,115,116,69,118,116,58,99,104,97,110,103,101,100,62,47,60,47,115,116,
69,118,116,58,99,104,97,110,103,101,100,62,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,60,47,114,100,102,58,108,105,62,10,32,32,32,32,32,32,32,32,32,32,32,32,60,47,114,100,102,58,83,101,113,62,10,
32,32,32,32,32,32,32,32,32,60,47,120,109,112,77,77,58,72,105,115,116,111,114,121,62,10,32,32,32,32,32,32,32,32,32,60,116,105,102,102,58,79,114,105,101,110,116,97,116,105,111,110,62,49,60,47,116,105,102,
102,58,79,114,105,101,110,116,97,116,105,111,110,62,10,32,32,32,32,32,32,32,32,32,60,116,105,102,102,58,88,82,101,115,111,108,117,116,105,111,110,62,55,50,48,48,48,48,47,49,48,48,48,48,60,47,116,105,102,
102,58,88,82,101,115,111,108,117,116,105,111,110,62,10,32,32,32,32,32,32,32,32,32,60,116,105,102,102,58,89,82,101,115,111,108,117,116,105,111,110,62,55,50,48,48,48,48,47,49,48,48,48,48,60,47,116,105,102,
102,58,89,82,101,115,111,108,117,116,105,111,110,62,10,32,32,32,32,32,32,32,32,32,60,116,105,102,102,58,82,101,115,111,108,117,116,105,111,110,85,110,105,116,62,50,60,47,116,105,102,102,58,82,101,115,
111,108,117,116,105,111,110,85,110,105,116,62,10,32,32,32,32,32,32,32,32,32,60,101,120,105,102,58,67,111,108,111,114,83,112,97,99,101,62,54,53,53,51,53,60,47,101,120,105,102,58,67,111,108,111,114,83,112,
97,99,101,62,10,32,32,32,32,32,32,32,32,32,60,101,120,105,102,58,80,105,120,101,108,88,68,105,109,101,110,115,105,111,110,62,49,50,56,60,47,101,120,105,102,58,80,105,120,101,108,88,68,105,109,101,110,
115,105,111,110,62,10,32,32,32,32,32,32,32,32,32,60,101,120,105,102,58,80,105,120,101,108,89,68,105,109,101,110,115,105,111,110,62,49,50,56,60,47,101,120,105,102,58,80,105,120,101,108,89,68,105,109,101,
110,115,105,111,110,62,10,32,32,32,32,32,32,60,47,114,100,102,58,68,101,115,99,114,105,112,116,105,111,110,62,10,32,32,32,60,47,114,100,102,58,82,68,70,62,10,60,47,120,58,120,109,112,109,101,116,97,62,
10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,
32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,10,60,63,120,112,97,99,107,101,116,
32,101,110,100,61,34,119,34,63,62,235,246,5,173,0,0,0,32,99,72,82,77,0,0,122,37,0,0,128,131,0,0,249,255,0,0,128,233,0,0,117,48,0,0,234,96,0,0,58,152,0,0,23,111,146,95,197,70,0,0,8,214,73,68,65,84,120,
218,236,157,123,140,29,83,28,199,63,179,119,187,173,85,207,162,213,213,7,127,20,41,165,137,170,86,17,143,138,132,150,37,186,8,17,154,32,18,234,253,170,149,212,31,45,18,33,30,137,160,245,8,161,245,126,
172,134,134,160,245,86,170,42,158,177,74,80,69,209,213,221,190,118,199,31,191,115,211,49,247,220,189,51,119,102,247,206,227,247,73,230,143,153,222,57,157,57,191,239,158,57,191,223,249,157,115,28,215,117,
81,242,75,157,86,129,10,64,81,1,40,42,0,37,151,212,7,249,145,227,56,182,203,123,0,147,129,131,128,93,1,7,208,30,101,255,224,152,99,61,240,9,240,14,176,198,255,163,32,29,252,250,42,31,160,17,104,1,142,
7,198,0,59,170,0,106,34,128,13,192,120,96,36,240,0,240,111,232,146,92,215,173,120,248,152,12,172,50,198,214,35,57,199,23,192,145,161,109,27,82,0,211,180,162,19,127,156,18,70,0,78,144,239,132,233,3,140,
52,127,249,59,104,11,156,104,254,5,198,1,237,113,246,1,70,0,115,203,24,127,29,240,135,214,123,77,216,205,116,192,189,12,6,230,1,87,3,63,197,213,7,184,2,232,176,52,55,11,128,209,106,135,154,49,202,216,
192,111,151,78,224,234,56,251,0,207,91,254,147,247,181,254,19,195,135,22,251,180,5,177,109,208,64,208,112,203,181,54,173,247,196,96,179,197,176,56,35,129,3,44,215,182,104,189,39,134,45,101,98,5,177,9,
160,199,114,173,160,245,158,24,108,182,112,227,20,128,146,81,84,0,42,0,69,5,160,228,150,250,26,254,223,45,192,113,72,232,114,30,176,54,134,50,155,128,171,144,104,216,107,192,83,49,61,235,12,96,42,50,252,
122,59,240,75,12,101,14,3,174,71,70,86,151,0,139,106,98,133,128,129,160,229,150,64,195,236,8,255,237,89,190,178,222,44,227,106,134,97,16,18,156,242,150,219,18,67,21,157,225,43,115,25,48,48,98,153,13,166,
156,184,158,181,213,98,159,229,113,6,130,226,102,134,239,252,40,100,0,35,10,7,3,19,125,215,206,137,225,89,253,101,28,142,36,193,68,97,188,41,167,183,58,201,116,31,160,219,114,222,24,177,204,129,213,250,
194,85,196,64,162,182,0,131,44,229,246,228,89,0,174,229,90,28,134,234,238,131,103,141,195,88,221,22,113,118,231,73,0,138,186,129,138,10,64,81,1,40,42,0,69,5,160,168,0,20,21,64,138,234,168,78,5,144,31,
6,104,11,144,111,62,242,157,175,3,190,202,202,203,213,171,125,43,50,23,24,138,12,93,111,64,134,155,127,87,1,228,135,141,192,133,166,181,236,201,218,203,233,39,32,56,61,89,124,41,109,1,236,92,0,28,131,
172,123,80,76,176,240,255,225,108,69,230,222,45,64,18,102,84,0,25,160,1,73,35,155,30,226,158,153,192,233,192,75,250,9,72,63,183,132,52,62,72,114,200,147,192,222,42,128,116,179,29,112,102,149,247,54,154,
86,64,63,1,41,166,9,201,38,246,119,252,186,144,121,118,197,63,150,45,72,74,151,63,64,52,82,5,144,126,252,105,89,159,35,73,161,117,30,1,116,1,205,38,62,208,219,189,42,128,148,97,235,237,175,49,34,240,179,
196,34,0,87,5,144,110,10,150,62,209,56,224,78,203,111,247,45,115,191,10,32,197,116,82,58,167,126,79,96,86,149,159,15,245,2,82,198,207,192,183,17,238,127,75,5,144,254,62,192,77,85,222,251,58,240,130,10,
32,253,180,33,115,244,218,3,254,126,3,240,56,18,60,74,229,88,129,246,1,74,89,4,44,6,142,0,118,42,99,216,98,95,97,149,57,82,139,10,192,78,7,240,74,30,94,180,86,2,40,88,62,69,73,118,163,198,32,235,36,175,
6,158,238,35,151,179,144,39,1,212,89,206,187,18,106,252,201,192,139,192,16,115,126,31,112,49,209,2,63,27,45,46,167,147,4,67,244,23,207,249,206,151,97,143,184,37,129,89,30,227,3,92,4,140,141,88,230,74,
224,189,10,117,146,233,22,224,81,163,248,102,224,55,227,126,109,74,168,0,6,91,174,13,137,88,102,23,112,26,48,7,217,121,229,89,227,77,228,170,19,248,136,57,146,142,109,21,206,173,49,148,251,43,146,121,
148,171,78,224,14,192,206,198,181,178,165,89,245,16,207,2,76,73,166,201,180,126,61,150,62,64,29,240,15,178,24,85,166,4,176,15,112,27,112,136,105,82,203,249,214,46,18,146,157,15,220,147,49,195,207,2,206,
51,2,160,76,39,178,14,89,53,237,99,100,189,255,246,44,8,96,12,240,134,231,197,43,177,59,112,55,146,139,223,154,17,227,223,10,92,19,240,183,67,144,125,0,38,2,71,3,223,165,221,11,184,51,132,241,189,220,
8,76,200,128,241,39,133,48,190,151,189,128,59,210,238,6,238,65,233,114,104,97,56,53,3,2,136,242,14,83,98,240,56,106,250,9,216,9,73,181,246,210,105,252,224,6,223,181,38,74,51,107,119,204,128,0,108,251,
44,181,155,190,142,119,105,188,205,72,2,138,247,90,3,176,11,240,103,90,5,208,99,233,240,173,52,205,162,159,233,148,14,169,118,103,64,0,54,151,241,18,236,187,124,188,7,28,86,161,254,82,215,7,8,138,67,54,
113,146,92,239,125,221,2,148,203,179,251,0,73,171,46,86,206,134,50,29,197,44,236,74,98,123,135,187,128,235,60,205,189,139,4,156,14,176,8,165,46,205,2,248,219,124,219,6,121,174,53,2,135,134,184,63,237,
216,130,58,163,9,182,221,222,102,224,175,52,127,2,214,2,75,35,220,255,108,6,4,16,229,29,222,238,203,14,96,127,125,139,46,35,200,14,150,165,220,76,138,103,221,122,120,159,210,57,4,65,88,13,92,158,246,62,
0,72,36,235,72,100,226,229,4,227,22,149,155,114,93,28,11,184,31,25,119,207,10,179,205,123,205,68,246,96,180,45,54,81,28,11,88,111,250,72,215,1,63,102,65,0,0,63,32,27,47,52,26,191,182,183,193,160,53,25,
245,6,238,53,199,176,10,2,248,203,196,69,50,225,5,248,233,236,207,151,75,40,137,18,120,45,253,209,243,144,61,137,239,71,6,126,250,66,204,73,94,226,109,56,240,160,169,131,115,179,26,7,40,199,185,200,210,
42,69,246,71,54,101,218,24,161,204,63,3,186,96,73,96,59,227,29,20,183,184,57,25,137,122,62,150,151,22,160,217,119,62,197,18,4,9,203,231,166,53,41,242,27,253,48,154,86,37,7,81,186,191,81,115,158,90,0,127,
140,191,199,252,85,68,193,69,150,115,123,21,24,129,172,217,243,125,66,5,48,208,60,175,227,171,131,92,11,32,174,129,159,52,4,143,186,205,59,23,122,169,147,76,11,32,78,14,70,210,180,109,177,5,76,37,255,
131,204,222,93,143,146,25,1,108,143,228,14,78,15,248,249,248,1,184,150,90,237,208,169,2,136,253,185,219,144,13,39,131,50,26,88,136,204,251,91,172,166,175,125,28,32,10,167,132,52,190,151,57,106,246,244,
11,96,74,132,123,199,32,225,88,37,197,159,0,91,146,197,98,224,27,203,245,22,139,193,7,171,233,211,45,0,155,203,52,27,248,212,114,125,172,79,0,113,186,156,42,128,26,97,203,179,59,129,255,103,31,21,71,28,
135,90,238,117,212,244,233,247,2,108,157,187,27,216,54,0,84,140,11,12,180,244,123,92,53,125,186,5,96,203,48,26,64,176,209,191,245,200,204,92,37,197,94,192,66,170,95,81,228,113,162,141,58,170,0,18,64,59,
48,163,10,17,60,131,204,57,84,82,254,9,0,120,25,89,191,231,124,100,169,246,122,236,105,86,142,105,246,151,0,15,169,201,179,35,0,128,21,192,165,106,198,252,125,2,42,49,64,77,155,79,1,76,3,190,68,34,130,
15,242,255,25,73,74,6,63,1,94,134,153,30,126,113,58,246,76,227,238,181,170,153,243,209,2,236,71,233,92,252,67,212,196,249,17,128,45,167,110,139,154,56,63,2,112,3,138,66,201,129,23,160,168,0,20,21,128,
162,2,80,84,0,138,10,64,81,1,40,137,18,128,63,171,215,33,250,146,112,133,128,215,146,80,110,129,210,188,196,66,158,5,80,32,250,202,33,182,44,31,167,143,234,40,234,254,70,93,150,114,115,181,103,208,147,
190,243,55,144,37,100,163,240,41,165,251,240,196,177,35,201,163,190,243,165,192,103,17,203,92,129,44,1,231,101,97,45,12,81,95,67,1,116,3,199,34,27,36,220,66,244,184,253,38,100,31,158,43,145,137,31,175,
17,207,84,241,133,230,89,143,67,50,139,110,71,210,207,163,176,25,56,157,109,171,133,198,245,172,225,113,93,183,226,129,172,215,231,250,142,217,218,133,74,12,173,22,251,44,15,98,91,245,2,212,11,80,84,0,
138,10,64,81,1,244,134,205,71,213,25,182,201,161,187,218,24,72,80,1,184,9,114,33,149,82,26,2,218,172,106,1,216,214,183,61,73,235,61,49,156,104,185,246,75,156,2,120,139,210,240,231,68,100,149,174,81,90,
255,53,99,111,224,97,74,179,159,59,141,205,42,127,219,77,160,167,247,31,57,206,8,100,235,215,51,44,255,188,14,248,67,109,81,19,118,71,150,223,247,243,4,112,173,235,186,63,197,37,128,162,218,86,162,235,
235,36,157,14,224,64,96,117,16,219,134,113,3,219,129,179,181,126,19,207,217,200,118,51,1,187,247,193,198,2,188,76,1,86,81,26,123,214,163,182,199,74,100,186,124,40,219,134,249,4,120,25,140,204,203,159,
10,236,75,249,125,128,148,190,161,184,238,65,7,240,53,50,154,56,31,95,78,69,32,219,86,41,0,144,213,183,38,1,227,145,61,130,85,0,253,47,128,191,145,220,130,119,145,45,250,232,19,1,40,217,69,199,2,84,0,
138,10,64,81,1,40,249,228,191,1,0,118,114,125,99,243,32,253,93,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* ToolbarPanel::mixer_128px_png = (const char*) resource_ToolbarPanel_mixer_128px_png;
const int ToolbarPanel::mixer_128px_pngSize = 17238;


//[EndFile] You can add extra defines here...
//[/EndFile]
