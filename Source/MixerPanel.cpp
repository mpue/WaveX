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
#include "Track.h"
#include "Mixer.h"
//[/Headers]

#include "MixerPanel.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MixerPanel::MixerPanel ()
{
    //[Constructor_pre] You can add your own custom stuff here..


    //[/Constructor_pre]

    addAndMakeVisible (masterChannel = new MasterChannelPanel());
    masterChannel->setName ("Master");

    addAndMakeVisible (aux1 = new MasterChannelPanel());
    aux1->setName ("Aux 1");


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    // startTimer(100);
    Mixer::getInstance()->addChangeListener(this);
    //[/Constructor]
}

MixerPanel::~MixerPanel()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    masterChannel = nullptr;
    aux1 = nullptr;

    //[Destructor]. You can add your own custom destruction code here..
	for (std::vector<MasterChannelPanel*>::iterator it = channels.begin(); it != channels.end(); ++it) {
		delete *it;
	}
    //[/Destructor]
}

//==============================================================================
void MixerPanel::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::grey);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MixerPanel::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    masterChannel->setBounds (90, 0, 90, 250);
    aux1->setBounds (0, 0, 90, 250);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void MixerPanel::changeListenerCallback(ChangeBroadcaster * source) {

    /*
    if (Mixer::getInstance() == source){

        if (Mixer::getInstance()->getTracks().size() > channels.size()){
            MasterChannelPanel* panel = new MasterChannelPanel();
            panel->setTrack(Mixer::getInstance()->getTracks().back());
            Mixer::getInstance()->addChangeListener(panel);
            panel->setTopLeftPosition((channels.size() + 2) * 90, 0);
            addAndMakeVisible(panel);
            channels.push_back(panel);

        }

    }
     */

}

vector<MasterChannelPanel*> MixerPanel::getChannels() {
    return channels;
}

void MixerPanel::setMasterVolume(int channel, float volume) {
    masterChannel->setMagnitude(channel,volume);
}

void MixerPanel::timerCallback() {
    /*
    for (int i = 0; i < mcc->getNavigator()->getTracks().size();i++) {
        Track* t = mcc->getNavigator()->getTracks().at(i);
        channels.at(i)->setMagnitude(t->magnitudeLeft);
    }
    masterChannel->setMagnitude(mcc->getMagnitude(0));
    */
}

void MixerPanel::addTrack(Track* track) {
    MasterChannelPanel* panel = new MasterChannelPanel();
    panel->setTrack(track);
    Mixer::getInstance()->addChangeListener(panel);
    panel->setTopLeftPosition((channels.size() + 2) * 90, 0);
    addAndMakeVisible(panel);
    channels.push_back(panel);
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MixerPanel" componentName=""
                 parentClasses="public Component, public ChangeListener, public Timer"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="600"
                 initialHeight="400">
  <BACKGROUND backgroundColour="ff808080"/>
  <GENERICCOMPONENT name="Master" id="dac96aabc1eedcee" memberName="masterChannel"
                    virtualName="MasterChannelPanel" explicitFocusOrder="0" pos="90 0 90 250"
                    class="MasterChannelPanel" params=""/>
  <GENERICCOMPONENT name="Aux 1" id="fbda51a6d9971c30" memberName="aux1" virtualName="MasterChannelPanel"
                    explicitFocusOrder="0" pos="0 0 90 250" class="MasterChannelPanel"
                    params=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
