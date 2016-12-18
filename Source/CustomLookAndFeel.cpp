/*
  ==============================================================================

    CustomLookAndFeel.cpp
    Created: 25 Nov 2016 5:14:44pm
    Author:  Matthias Pueski

  ==============================================================================
*/

#include "CustomLookAndFeel.h"

void CustomLookAndFeel::drawLinearSlider (Graphics& g, int x, int y, int width, int height,
                                        float sliderPos, float minSliderPos, float maxSliderPos,
                                          const Slider::SliderStyle style, Slider& slider) {
     g.fillAll (slider.findColour (Slider::backgroundColourId));
    
    if (style == Slider::SliderStyle::LinearBarVertical) {
        
        float from  = (sliderPos / maxSliderPos) * height;
        float to = height;
        
        for (float val = from ; val <= to; val += 5) {
        
            if (val / height <= 0.05f) {
                g.setColour(Colours::red);
            }
            else if (val / height <= 0.25f) {
                g.setColour(Colours::orange);
            }
            else {
                g.setColour(Colours::chartreuse);
            }
            //g.drawEllipse((float)x, val, 5, 5, 1);
            g.fillRect((float)x, val, (float)width,3.0f);
        }
        
        
        // g.fillRect((float)x,from,(float)width,to);

    }
    else if (style == Slider::SliderStyle::LinearVertical) {
        Image fader = ImageCache::getFromMemory(BinaryData::Fader_png,BinaryData::Fader_pngSize);
        

        float from  = (sliderPos / maxSliderPos) * height;
        LookAndFeel_V3::drawLinearSliderBackground(g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
        
        
        g.setColour(Colours::white);
        g.drawImageAt(fader.rescaled(fader.getWidth(), fader.getHeight()/2),0, from - fader.getHeight()/4 );
        
    }
    else {
        LookAndFeel_V3::drawLinearSlider(g, x, y, width, height, sliderPos, minSliderPos, maxSliderPos, style, slider);
    }
    
    
}
