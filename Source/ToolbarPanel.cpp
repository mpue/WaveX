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
                               ImageCache::getFromMemory (ionicons_201_androidaddcircle_24_0_000000_none_png, ionicons_201_androidaddcircle_24_0_000000_none_pngSize), 1.000f, Colour (0x00000000),
                               Image(), 1.000f, Colours::cornflowerblue,
                               Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (removeTrackButton = new ImageButton ("removeTrackButton"));
    removeTrackButton->setTooltip (TRANS("Remove selected track"));
    removeTrackButton->setButtonText (TRANS("new button"));
    removeTrackButton->addListener (this);

    removeTrackButton->setImages (false, true, true,
                                  ImageCache::getFromMemory (ionicons_201_androidremovecircle_24_0_000000_none_png, ionicons_201_androidremovecircle_24_0_000000_none_pngSize), 1.000f, Colour (0x00000000),
                                  Image(), 1.000f, Colours::cornflowerblue,
                                  Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (copyButton = new ImageButton ("copyButton"));
    copyButton->setTooltip (TRANS("Copy "));
    copyButton->setButtonText (TRANS("new button"));
    copyButton->addListener (this);

    copyButton->setImages (false, true, true,
                           ImageCache::getFromMemory (fontawesome_470_copy_24_0_000000_none_png, fontawesome_470_copy_24_0_000000_none_pngSize), 1.000f, Colour (0x00000000),
                           Image(), 1.000f, Colours::cornflowerblue,
                           Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (editButton = new ImageButton ("editButton"));
    editButton->setTooltip (TRANS("Edit"));
    editButton->setButtonText (TRANS("new button"));
    editButton->addListener (this);

    editButton->setImages (false, true, true,
                           ImageCache::getFromMemory (fontawesome_470_pencil_24_0_000000_none_png, fontawesome_470_pencil_24_0_000000_none_pngSize), 1.000f, Colour (0x00000000),
                           Image(), 1.000f, Colours::cornflowerblue,
                           Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (settingsButton = new ImageButton ("settingsButton"));
    settingsButton->setTooltip (TRANS("Settings"));
    settingsButton->setButtonText (TRANS("new button"));
    settingsButton->addListener (this);

    settingsButton->setImages (false, true, true,
                               ImageCache::getFromMemory (ionicons_201_settings_24_0_000000_none_png, ionicons_201_settings_24_0_000000_none_pngSize), 1.000f, Colour (0x00000000),
                               Image(), 1.000f, Colours::cornflowerblue,
                               Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (importAudioButton = new ImageButton ("importAudioButton"));
    importAudioButton->setTooltip (TRANS("Import audio on selected track"));
    importAudioButton->setButtonText (TRANS("new button"));
    importAudioButton->addListener (this);

    importAudioButton->setImages (false, true, true,
                                  ImageCache::getFromMemory (fontawesome_470_fileaudioo_32_0_000000_none_png, fontawesome_470_fileaudioo_32_0_000000_none_pngSize), 1.000f, Colour (0x00000000),
                                  Image(), 1.000f, Colours::cornflowerblue,
                                  Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (pluginsButton = new ImageButton ("pluginsButton"));
    pluginsButton->setButtonText (TRANS("new button"));
    pluginsButton->addListener (this);

    pluginsButton->setImages (false, true, true,
                              ImageCache::getFromMemory (fontawesome_470_plug_32_0_000000_none_png, fontawesome_470_plug_32_0_000000_none_pngSize), 1.000f, Colour (0x00000000),
                              Image(), 1.000f, Colours::cornflowerblue,
                              Image(), 1.000f, Colour (0x00000000));
    addAndMakeVisible (addMidiTrackButton = new ImageButton ("addMidiTrackButton"));
    addMidiTrackButton->setTooltip (TRANS("Add a new Midi track"));
    addMidiTrackButton->setButtonText (TRANS("new button"));
    addMidiTrackButton->addListener (this);

    addMidiTrackButton->setImages (false, true, true,
                                   ImageCache::getFromMemory (fontawesome_470_music_32_0_000000_none_png, fontawesome_470_music_32_0_000000_none_pngSize), 1.000f, Colour (0x00000000),
                                   Image(), 1.000f, Colours::cornflowerblue,
                                   Image(), 1.000f, Colour (0x00000000));

    //[UserPreSize]
    //[/UserPreSize]

    setSize (130, 50);


    //[Constructor] You can add your own custom stuff here..
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


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ToolbarPanel::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ToolbarPanel::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    addTrackButton->setBounds (10, 14, 24, 24);
    removeTrackButton->setBounds (40, 14, 24, 24);
    copyButton->setBounds (104, 14, 24, 24);
    editButton->setBounds (136, 14, 24, 24);
    settingsButton->setBounds (168, 14, 24, 24);
    importAudioButton->setBounds (200, 14, 24, 24);
    pluginsButton->setBounds (232, 14, 24, 24);
    addMidiTrackButton->setBounds (72, 14, 24, 24);
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
                 parentClasses="public Component" constructorParams="MainContentComponent* mcc"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="130" initialHeight="50">
  <BACKGROUND backgroundColour="ffffff"/>
  <IMAGEBUTTON name="addTrackButton" id="b040fab84432c089" memberName="addTrackButton"
               virtualName="" explicitFocusOrder="0" pos="10 14 24 24" tooltip="Add a new audio track"
               buttonText="new button" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="ionicons_201_androidaddcircle_24_0_000000_none_png"
               opacityNormal="1" colourNormal="0" resourceOver="" opacityOver="1"
               colourOver="ff6495ed" resourceDown="" opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="removeTrackButton" id="70f6412688935645" memberName="removeTrackButton"
               virtualName="" explicitFocusOrder="0" pos="40 14 24 24" tooltip="Remove selected track"
               buttonText="new button" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="ionicons_201_androidremovecircle_24_0_000000_none_png"
               opacityNormal="1" colourNormal="0" resourceOver="" opacityOver="1"
               colourOver="ff6495ed" resourceDown="" opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="copyButton" id="14fb30dd46ca0d9a" memberName="copyButton"
               virtualName="" explicitFocusOrder="0" pos="104 14 24 24" tooltip="Copy "
               buttonText="new button" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="fontawesome_470_copy_24_0_000000_none_png"
               opacityNormal="1" colourNormal="0" resourceOver="" opacityOver="1"
               colourOver="ff6495ed" resourceDown="" opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="editButton" id="aae00a5880931a24" memberName="editButton"
               virtualName="" explicitFocusOrder="0" pos="136 14 24 24" tooltip="Edit"
               buttonText="new button" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="fontawesome_470_pencil_24_0_000000_none_png"
               opacityNormal="1" colourNormal="0" resourceOver="" opacityOver="1"
               colourOver="ff6495ed" resourceDown="" opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="settingsButton" id="291742b3ea36a25e" memberName="settingsButton"
               virtualName="" explicitFocusOrder="0" pos="168 14 24 24" tooltip="Settings"
               buttonText="new button" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="ionicons_201_settings_24_0_000000_none_png"
               opacityNormal="1" colourNormal="0" resourceOver="" opacityOver="1"
               colourOver="ff6495ed" resourceDown="" opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="importAudioButton" id="1584ca1f93618745" memberName="importAudioButton"
               virtualName="" explicitFocusOrder="0" pos="200 14 24 24" tooltip="Import audio on selected track"
               buttonText="new button" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="fontawesome_470_fileaudioo_32_0_000000_none_png"
               opacityNormal="1" colourNormal="0" resourceOver="" opacityOver="1"
               colourOver="ff6495ed" resourceDown="" opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="pluginsButton" id="3f2551fd0588fd22" memberName="pluginsButton"
               virtualName="" explicitFocusOrder="0" pos="232 14 24 24" buttonText="new button"
               connectedEdges="0" needsCallback="1" radioGroupId="0" keepProportions="1"
               resourceNormal="fontawesome_470_plug_32_0_000000_none_png" opacityNormal="1"
               colourNormal="0" resourceOver="" opacityOver="1" colourOver="ff6495ed"
               resourceDown="" opacityDown="1" colourDown="0"/>
  <IMAGEBUTTON name="addMidiTrackButton" id="db543ed06f17880d" memberName="addMidiTrackButton"
               virtualName="" explicitFocusOrder="0" pos="72 14 24 24" tooltip="Add a new Midi track"
               buttonText="new button" connectedEdges="0" needsCallback="1"
               radioGroupId="0" keepProportions="1" resourceNormal="fontawesome_470_music_32_0_000000_none_png"
               opacityNormal="1" colourNormal="0" resourceOver="" opacityOver="1"
               colourOver="ff6495ed" resourceDown="" opacityDown="1" colourDown="0"/>
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


//[EndFile] You can add extra defines here...
//[/EndFile]
