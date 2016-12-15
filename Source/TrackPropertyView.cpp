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
#include "TrackNavigator.h"
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
    startTimer(70);
    //[/Constructor]
}

TrackPropertyView::~TrackPropertyView()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..

    for(std::vector<TrackPropertyPanel*>::iterator it = trackProperties.begin(); it != trackProperties.end();it++) {
        delete *it;
    }

    //[/Destructor]
}

//==============================================================================
void TrackPropertyView::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff454545));

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

Track* TrackPropertyView::getTrack(int i) {
    return this->trackProperties.at(i)->getTrack();
    
}

void TrackPropertyView::addTrack(Track* track)
{
	TrackPropertyPanel* panel = new TrackPropertyPanel();
    panel->setName(track->getName());
	panel->setBounds(0, trackProperties.size() * 200, 150, 200);
    panel->setTrack(track);
	addAndMakeVisible(panel);
	trackProperties.push_back(panel);
}

void TrackPropertyView::changeListenerCallback (ChangeBroadcaster* source) {

    if (TrackNavigator* tn = dynamic_cast<TrackNavigator*>(source)){

        int i = tn->getTracks().size() - 1;

        while (tn->getTracks().size() > trackProperties.size()) {
            addTrack(tn->getTracks().at(i--));
        }

    }


}

void TrackPropertyView::timerCallback() {
    for (int i = 0;  i < this->trackProperties.size();i++) {
        this->trackProperties.at(i)->update();
    }
}


//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TrackPropertyView" componentName=""
                 parentClasses="public Component, public ChangeListener, public Timer"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="600"
                 initialHeight="400">
  <BACKGROUND backgroundColour="ff454545"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
