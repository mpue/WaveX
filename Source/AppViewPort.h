#include "../JuceLibraryCode/JuceHeader.h"
#include "TimeLine.h"
#include "TrackPropertyView.h"

#pragma once
class AppViewPort : public Viewport
{
public:

	AppViewPort()
	{
		this->timeLine = NULL;		
		this->propertyView = NULL;
	}

	virtual ~AppViewPort()
	{
	}

	void setTimeLine(TimeLine* timeLine) {
		this->timeLine = timeLine;
	}

	void setPropertyView(TrackPropertyView* view) {
		this->propertyView = view;
	}

	void visibleAreaChanged(const Rectangle<int>& r) {
		
		if(this->timeLine != NULL) {
			this->timeLine->setOffset(-r.getX());
		}
		if (this->propertyView != NULL) {
			this->propertyView->setOffset(-r.getY());
		}

	}

private:
	TimeLine* timeLine;
	TrackPropertyView* propertyView;
};

