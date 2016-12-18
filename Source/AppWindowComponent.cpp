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

//==============================================================================
AppWindowComponent::AppWindowComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    this->offsetBottom = 275;
    
    Rectangle<int> r = Desktop::getInstance().getDisplays().getMainDisplay().userArea;
    
    viewport = new AppViewPort();
    viewport->setBounds(150,75,r.getWidth() - 150,r.getHeight() - this->offsetBottom);
    viewport->setSize(r.getWidth() - 150, r.getHeight() - this->offsetBottom);
    
	this->timeLine = new TimeLine(600);
	this->timeLine->setSize(getWidth(), 25);
	this->timeLine->setBounds(150, 50, r.getWidth(), 25);

	viewport->setTimeLine(this->timeLine);

	this->trackProperties = new TrackPropertyView();
	this->trackProperties->setBounds(0, 75, 150, r.getHeight() - this->offsetBottom - 50);

    mcc = new MainContentComponent(timeLine, trackProperties);
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

    setSize(r.getWidth(), r.getHeight());
    setBounds(0,0,r.getWidth(),r.getHeight());

    this->menu->setBounds(0,0,getWidth(),25);
	this->menu->setSize(getWidth(), 25);
    
	this->viewport->setPropertyView(this->trackProperties);

    // addAndMakeVisible(menu);
	addAndMakeVisible(timeLine);
    addAndMakeVisible(viewport);
	addAndMakeVisible(trackProperties);

    mcc->getNavigator()->addChangeListener(this->trackProperties);

	menu->toFront(true);
    
    addMouseListener(this,true);
    
    this->masterPanel = new MasterChannelPanel(mcc);
    this->masterPanel->setTopLeftPosition(getWidth() - this->masterPanel->getWidth() - 50, getHeight() - this->masterPanel->getHeight() - 50);
    mcc->addChangeListener(this->masterPanel);
    addAndMakeVisible(masterPanel);

    this->transport = new TransportPanel(mcc);
    this->transport->setBounds(450,0,320,50);
    
    mcc->getNavigator()->addChangeListener(transport);
    
    this->toolbar = new ToolbarPanel(mcc);
    this->toolbar->setBounds(150, 0, 300, 50);
    
	this->infoPanel = new InfoPanel();
	this->infoPanel->setBounds(0, 0, 150, 75);

    addAndMakeVisible(transport);
    addAndMakeVisible(toolbar);
	addAndMakeVisible(infoPanel);
    
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
    masterPanel = nullptr;
    transport = nullptr;
    toolbar = nullptr;
	infoPanel = nullptr;
	delete trackProperties;
}

void AppWindowComponent::paint (Graphics& g)
{

}

void AppWindowComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    Rectangle<int> area(getLocalBounds());
    // this->menu->setBounds(area.removeFromTop(LookAndFeel::getDefaultLookAndFeel().getDefaultMenuBarHeight()));
    viewport->setSize(getWidth() - 150, getHeight() - this->offsetBottom);
    this->trackProperties->setBounds(0, 75, 150, getHeight() - this->offsetBottom);
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



