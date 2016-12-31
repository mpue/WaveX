/*
  ==============================================================================

    AppWindowComponent.h
    Created: 24 Nov 2016 1:48:43pm
    Author:  Matthias Pueski

  ==============================================================================
*/

#ifndef APPWINDOWCOMPONENT_H_INCLUDED
#define APPWINDOWCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "MainComponent.cpp"
#include "TransportPanel.h"
#include "MasterChannelPanel.h"
#include "TimeLine.h"
#include "AppViewPort.h"
#include "TrackPropertyView.h"
#include "ToolbarPanel.h"
#include "InfoPanel.h"
#include "MixerPanel.h"

//==============================================================================
/*
*/
class AppWindowComponent : public Component, public ChangeListener
{
public:
    AppWindowComponent();
    ~AppWindowComponent();

    void paint (Graphics&) override;
    void resized() override;

private:

    ScopedPointer<MenuBarComponent> menu;
    ScopedPointer<AppViewPort> viewport;
    ScopedPointer<Viewport> mixerViewport;
    ScopedPointer<MainContentComponent> mcc;
    ScopedPointer<TransportPanel> transport;
	TrackPropertyView* trackProperties = NULL;
    ScopedPointer<ToolbarPanel> toolbar;
	ScopedPointer<InfoPanel> infoPanel;
    ScopedPointer<InfoPanel> dummyPanel;
    ScopedPointer<MixerPanel> mixer;
	TimeLine* timeLine;

    int dragstartX;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AppWindowComponent)
    
    virtual void mouseDown (const MouseEvent& event) override;
    virtual void mouseDrag (const MouseEvent& event) override;
    
    virtual void changeListenerCallback (ChangeBroadcaster* source) override;

    int offsetBottom;
    


};


#endif  // APPWINDOWCOMPONENT_H_INCLUDED
