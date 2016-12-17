/*
  ==============================================================================

    Track.h
    Created: 16 Dec 2016 9:40:38am
    Author:  pueskma

  ==============================================================================
*/

#ifndef TRACK_H_INCLUDED
#define TRACK_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "AudioRegion.h"
#include <vector>

//==============================================================================
/*
*/

using namespace std;

class Track    : public Component
{
public:
    Track(double sampleRate);
    ~Track();

	void setZoom(float zoom);
	String getName();
	void setGain(float gain);
	void setVolume(float volume);
	float getVolume();
	const float* getReadBuffer(int channel);
    const float getSample(int channel, long sample);
	int getNumSamples();
	void setSelected(bool selected);
	bool isSelected();
	double getMaxLength();
	void addRegion(File file, double sampleRate);

    void paint (Graphics&) override;
    void resized() override;

	void setOffset(int offset);
	int getOffset();
    void toggleLoopSelection();
    void clearSelection();
    
	AudioSampleBuffer* getBuffer();

	double magnitudeLeft = 0;
	double magnitudeRight = 0;

    AudioRegion* getCurrentRegion(long sample);
    
    void duplicateSelectedRegions();
    void duplicateRegion(AudioRegion* region);
    
    void setCurrentMarkerPosition(int position);
    
private:

	float zoom = 20;
	String name;
	float volume;
	float gain = 1;
	double sampleRate;
	bool selected = false;
	AudioRegion* currentRegion = NULL;
	AudioFormatManager manager;
	vector<AudioRegion*> regions;
	long numSamples = 0;
	double maxLength = 600 * this->sampleRate;
	int offset = 0;
	AudioSampleBuffer* audioBuffer;
    int markerPosition = 0;
    int bufferSize;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Track)
};


#endif  // TRACK_H_INCLUDED
