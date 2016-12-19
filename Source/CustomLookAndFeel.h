/*
  ==============================================================================

    CustomLookAndFeel.h
    Created: 25 Nov 2016 5:14:44pm
    Author:  Matthias Pueski

  ==============================================================================
*/

#ifndef CUSTOMLOOKANDFEEL_H_INCLUDED
#define CUSTOMLOOKANDFEEL_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class CustomLookAndFeel : public LookAndFeel_V3 {
    
public:
    
    CustomLookAndFeel() {
        gradient = ColourGradient(Colours::red, 0, 0, Colours::chartreuse, 5, 128, false);
        //gradient.addColour(0.3, Colours::chartreuse);
        //gradient.addColour(0.7, Colours::orange);
        gradient.addColour(0.2 , Colours::orange);
    }
    
    void drawLinearSlider (Graphics&, int x, int y, int width, int height,
                           float sliderPos, float minSliderPos, float maxSliderPos,
                           const Slider::SliderStyle, Slider&) override;
    
private:
    ColourGradient gradient;
    
    
};



#endif  // CUSTOMLOOKANDFEEL_H_INCLUDED
