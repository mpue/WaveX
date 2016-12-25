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
#include "MultiComponentDragger.h"

//==============================================================================
/*
*/

using namespace std;

class Track    : public Component, public ChangeBroadcaster, public ChangeListener
{
public:
    Track(double sampleRate, MultiComponentDragger* dragger);
    ~Track();

	void setZoom(float zoom);
	String getName();
    void setName(String name);
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
    
    void updateMagnitude(int sample, int buffersize);

    AudioRegion* getCurrentRegion(long sample);
    
    void removeSelectedRegions(bool clear);
    void duplicateSelectedRegions();
    void duplicateRegion(AudioRegion* region);
    void splitRegion();
    
    void setCurrentMarkerPosition(int position);
    
    int getMidiChannel();
    void setMidiChannel(int channel);
    
    vector<AudioRegion*> getRegions();
    
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
    int midiChannel = 1;
    virtual void changeListenerCallback(ChangeBroadcaster * source) override;
    MultiComponentDragger* dragger = NULL;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Track)
};


#endif  // TRACK_H_INCLUDED
