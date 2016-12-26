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
        gradientVertical = ColourGradient(Colours::red, 0, 0, Colours::chartreuse, 5, 128, false);
        gradientVertical.addColour(0.2 , Colours::orange);
        
        gradientHorizontal = ColourGradient(Colours::chartreuse, 0, 0, Colours::red, 128, 5, false);
        gradientHorizontal.addColour(0.8 , Colours::orange);
    }
    
    void drawLinearSlider (Graphics&, int x, int y, int width, int height,
                           float sliderPos, float minSliderPos, float maxSliderPos,
                           const Slider::SliderStyle, Slider&) override;
    
private:
    ColourGradient gradientVertical;
    ColourGradient gradientHorizontal;
    ComponentAnimator animator;
    
    long triggerTime = 0;
    int maxY = 0xFFFF;
    int maxX = 0;
};



#endif  // CUSTOMLOOKANDFEEL_H_INCLUDED
