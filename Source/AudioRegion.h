/*
  ==============================================================================

    Track.h
    Created: 25 Nov 2016 10:00:36pm
    Author:  Matthias Pueski

  ==============================================================================
*/

#ifndef AUDIOREGION_H_INCLUDED 
#define AUDIOREGION_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class AudioRegion : public Component, public ChangeListener
{
public:
    AudioRegion(File file, AudioFormatManager& manager,double sampleRate);
    ~AudioRegion();

    void paint (Graphics&) override;
    void resized() override;
    AudioThumbnail* getThumbnail();
    void setThumbnailBounds(Rectangle<int>* bounds);
    void setZoom(float zoom);
    String getName();
    void setGain(float gain);
    void setVolume(float volume);
    float getVolume();
    AudioSampleBuffer* getBuffer();
    const float* getReadBuffer(int channel);    
	int getNumSamples();
	void setSelected(bool selected);
	bool isSelected();
	void setOffset(int offset);
	int getOffset();

    double magnitudeLeft = 0;
    double magnitudeRight = 0;

private:

    AudioSampleBuffer* audioBuffer;
    AudioThumbnail* thumbnail;
    AudioThumbnailCache* thumbnailCache;
    ScopedPointer<AudioFormatReaderSource> readerSource;
    Rectangle<int>* thumbnailBounds;
    float zoom;
    String name;
    float volume;
    float gain = 1;
	int offset = 0;
	double sampleRate;
	bool selected = false;
    virtual void changeListenerCallback(ChangeBroadcaster * source) override;
    void paintIfNoFileLoaded(Graphics& g, const Rectangle<int>& thumbnailBounds);
    void paintIfFileLoaded(Graphics& g, const Rectangle<int>& thumbnailBounds);
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioRegion)
};


#endif  // AUDIOREGION_H_INCLUDED
