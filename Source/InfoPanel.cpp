/*
  ==============================================================================

    InfoPanel.cpp
    Created: 16 Dec 2016 10:58:41am
    Author:  pueskma

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "InfoPanel.h"

//==============================================================================
InfoPanel::InfoPanel()
{

}

InfoPanel::~InfoPanel()
{
}

void InfoPanel::paint (Graphics& g)
{

    g.fillAll (Colours::darkgrey);
	g.setColour(Colours::steelblue);

	g.drawLine(0, getHeight(), getWidth(), getHeight(), 1.0f);

}

void InfoPanel::resized()
{

}
