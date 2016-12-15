#include "../JuceLibraryCode/JuceHeader.h"
#include "TimeLine.h"

#pragma once
class AppViewPort : public Viewport
{
public:

	AppViewPort()
	{
	}

	virtual ~AppViewPort()
	{
	}

	void setTimeLine(TimeLine* timeLine) {
		this->timeLine = timeLine;
	}

	void visibleAreaChanged(const Rectangle<int>& r) {
		
		if(this->timeLine != NULL) {
			this->timeLine->setOffset(-r.getX());
		}

	}

private:
	TimeLine* timeLine;

};

