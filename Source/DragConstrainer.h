/*
  ==============================================================================

    DragConstrainer.h
    Created: 16 Dec 2016 5:55:25pm
    Author:  Matthias Pueski

  ==============================================================================
*/

#ifndef DRAGCONSTRAINER_H_INCLUDED
#define DRAGCONSTRAINER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class DragConstrainer : public ComponentBoundsConstrainer {
    
    virtual void checkBounds (Rectangle<int>& bounds,
                              const Rectangle<int>& previousBounds,
                              const Rectangle<int>& limits,
                              bool isStretchingTop,
                              bool isStretchingLeft,
                              bool isStretchingBottom,
                              bool isStretchingRight) override {
        if (bounds.getY() != previousBounds.getY()) {
            bounds.setY(previousBounds.getY());
        }
    }
    
    
};




#endif  // DRAGCONSTRAINER_H_INCLUDED
