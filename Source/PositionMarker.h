/*
  ==============================================================================

    PositionMarker.h
    Created: 24 Nov 2016 11:00:23am
    Author:  Matthias Pueski

  ==============================================================================
*/

#ifndef POSITIONMARKER_H_INCLUDED
#define POSITIONMARKER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class PositionMarker    : public Component, public Timer, public ChangeListener
{
public:
    PositionMarker(double lengthInSeconds);
    ~PositionMarker();

    void paint (Graphics&) override;
    void resized() override;
    void setLength(double lengthInSeconds);
    void setPosition(double position);
    void setDrawingBounds(int x, int y, int width, int height);
    void setPlaying(bool playing);
	virtual void changeListenerCallback(ChangeBroadcaster * source) override;
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PositionMarker)
    double length;
	double audioPosition;
	double drawPosition;
    void timerCallback() override;
    bool playing;
    int x;
    int y;
    int width;
    int height;
};


#endif  // POSITIONMARKER_H_INCLUDED
