/*
  ==============================================================================

    InfoPanel.h
    Created: 16 Dec 2016 10:58:41am
    Author:  pueskma

  ==============================================================================
*/

#ifndef INFOPANEL_H_INCLUDED
#define INFOPANEL_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class InfoPanel    : public Component
{
public:
    InfoPanel();
    ~InfoPanel();

    void paint (Graphics&) override;
    void resized() override;
    
    void setFillColour(Colour c) {
        this->fillColour = c;
    }

private:
    
    Colour fillColour = Colours::darkgrey;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (InfoPanel)
};


#endif  // INFOPANEL_H_INCLUDED
