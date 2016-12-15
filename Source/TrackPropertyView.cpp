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

#include "TrackPropertyView.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TrackPropertyView::TrackPropertyView ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..	
    //[/Constructor]
}

TrackPropertyView::~TrackPropertyView()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TrackPropertyView::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff80a599));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TrackPropertyView::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void TrackPropertyView::addTrack()
{
	TrackPropertyPanel* panel = new TrackPropertyPanel();
	panel->setBounds(0, trackProperties.size() * 200, 150, 200);
	addAndMakeVisible(panel);
	trackProperties.push_back(panel);
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TrackPropertyView" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff80a599"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
