/*
  ==============================================================================

    AppWindowComponent.cpp
    Created: 24 Nov 2016 1:48:43pm
    Author:  Matthias Pueski

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "AppWindowComponent.h"
#include "MainComponent.cpp"
#include "Project.h"

//==============================================================================
AppWindowComponent::AppWindowComponent() {
    
    this->offsetBottom = 350;
    
    Rectangle<int> r = Desktop::getInstance().getDisplays().getMainDisplay().userArea;
    
    viewport = new AppViewPort();
    viewport->setBounds(150,75,r.getWidth() - 150,r.getHeight() - this->offsetBottom);
    viewport->setSize(r.getWidth() - 150, r.getHeight() - this->offsetBottom);
    
    long trackLength = Project::getInstance()->getTrackLength();
	this->timeLine = new TimeLine(trackLength);
    
	this->timeLine->setSize(getWidth(), 25);
	this->timeLine->setBounds(150, 50, r.getWidth(), 25);

	viewport->setTimeLine(this->timeLine);

	this->trackProperties = new TrackPropertyView();
	this->trackProperties->setBounds(0, 75, 150, r.getHeight() - this->offsetBottom - 75);
    
    this->mixer = new MixerPanel();
    this->mixerViewport = new Viewport();
    this->mixerViewport->setViewedComponent(mixer);

    mcc = new MainContentComponent(timeLine, trackProperties, mixer);
    mcc->setSize(r.getWidth(), r.getHeight() - this->offsetBottom - 50);
    viewport->setViewedComponent(mcc);
    
    this->menu = new MenuBarComponent();
    
#if JUCE_MAC
    menu->setModel (nullptr);
    MenuBarModel::setMacMainMenu (mcc);
#else
    menu->setModel(mcc);
#endif
    
    Rectangle<int> area(getLocalBounds());

    this->menu->setBounds(0,0,getWidth(),25);
	this->menu->setSize(getWidth(), 25);
    
	this->viewport->setPropertyView(this->trackProperties);

    // addAndMakeVisible(menu);
	addChildComponent(timeLine);
    addAndMakeVisible(viewport);
	addAndMakeVisible(trackProperties);
    addAndMakeVisible(mixerViewport);
    
	menu->toFront(true);
    
    addMouseListener(this,true);
     
    this->transport = new TransportPanel(mcc);
    this->transport->setBounds(500,0,520,50);
    
    mcc->getNavigator()->addChangeListener(transport);
    
    this->toolbar = new ToolbarPanel(mcc);
    this->toolbar->setBounds(150, 0, 320, 50);
    
    this->toolbar->addChangeListener(this);
    
	this->infoPanel = new InfoPanel();
	this->infoPanel->setBounds(0, 0, 155, 75);

    addAndMakeVisible(transport);
    addAndMakeVisible(toolbar);
	addAndMakeVisible(infoPanel);
    
    this->dummyPanel = new InfoPanel();
    this->dummyPanel->setFillColour(Colours::darkgrey);
    this->dummyPanel->setBounds(0, viewport->getHeight() + 25, 150, this->offsetBottom);
    addAndMakeVisible(dummyPanel);
    
    setSize(r.getWidth(), r.getHeight());
    setBounds(0,0,r.getWidth(),r.getHeight());
    
    timeLine->toFront(false);
    toolbar->toFront(false);
    dummyPanel->toFront(false);
    
    mixerViewport->toFront(false);
    viewport->addComponentListener(trackProperties);

    // transport->setTopLeftPosition(50, r.getHeight() - (this->transport->getHeight() + 50));

}

AppWindowComponent::~AppWindowComponent()
{
#if JUCE_MAC
    MenuBarModel::setMacMainMenu (nullptr);
#endif
    menu = nullptr;
    mcc = nullptr;
    viewport = nullptr;
    transport = nullptr;
    toolbar = nullptr;
	infoPanel = nullptr;
    mixer = nullptr;
	delete trackProperties;
}

void AppWindowComponent::paint (Graphics& g)
{
    g.fillAll(Colours::darkgrey);
}

void AppWindowComponent::resized()
{
    Rectangle<int> area(getLocalBounds());
    // this->menu->setBounds(area.removeFromTop(LookAndFeel::getDefaultLookAndFeel().getDefaultMenuBarHeight()));
    viewport->setSize(getWidth() - 150, getHeight() - this->offsetBottom - 3);
    this->trackProperties->setBounds(0, 75, 150, getHeight() - this->offsetBottom - 75);
    this->mixerViewport->setBounds(0,getHeight() - this->offsetBottom + 75 ,getWidth(), this->offsetBottom - 75);
    this->mixer->setBounds(0,50,getWidth()* 2 ,800);
    this->trackProperties->resized();
    this->trackProperties->repaint();
    // viewport->setBounds(getX(), getY()  ,getWidth(),getHeight() - this->offsetBottom);

}


void AppWindowComponent::mouseDown (const MouseEvent& event)  {
    
    this->dragstartX = viewport->getViewPositionX();
    
}

void AppWindowComponent::mouseDrag (const MouseEvent& event) {
    
    if (event.mods.isCtrlDown()) {
        Logger::getCurrentLogger()->writeToLog(String(event.getDistanceFromDragStartX()));
        viewport->setViewPosition(dragstartX - event.getOffsetFromDragStart().getX(), 0);
        Logger::getCurrentLogger()->writeToLog(String(event.x));
    }
    
}

void AppWindowComponent::changeListenerCallback (ChangeBroadcaster* source) {
    
    bool mixerVisible = toolbar->getMixerButton()->getToggleState();
    
    Rectangle<int> area(getLocalBounds());
    if (mixerVisible) {
        this->offsetBottom = 350;
    }
    else {
        this->offsetBottom = 0;
    }
    
    this->mixerViewport->setVisible(mixerVisible);
    this->dummyPanel->setVisible(mixerVisible);
    
    resized();
    repaint();

}


