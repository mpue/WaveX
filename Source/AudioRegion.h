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
#include "MultiComponentDragger.h"

//==============================================================================
/*
*/
class AudioRegion : public Component,  public ChangeListener, public ChangeBroadcaster
{
public:
    
    AudioRegion(AudioRegion* other, AudioFormatManager& manager, double sampleRate);
    AudioRegion(AudioRegion* other, AudioFormatManager& manager, double sampleRate, long startSample, long numSamples);
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
    void setLoop(bool loop);
    bool isLoop();
	void setOffset(int offset);
	int getOffset();
    void setLoopCount(int count);
    int getLoopCount();
    
    long getSampleOffset();
    void setSampleOffset(long offset,bool reminder, bool notify);
    long getOldOffset();
    
    void setDragging(bool dragging);
    bool isDragging();
    void move(int offset);
    
    double getSampleRate();
    
    double magnitudeLeft = 0;
    double magnitudeRight = 0;

    void mouseDown(const MouseEvent & e) override;
    void mouseUp(const MouseEvent & e) override;
    void mouseDrag(const MouseEvent & e) override;
    
    inline void setDragger(MultiComponentDragger* dragger) {
        this->dragger = dragger;
    }
    
private:

    AudioSampleBuffer* audioBuffer;
    AudioThumbnail* thumbnail;
    AudioThumbnailCache* thumbnailCache;
    ScopedPointer<AudioFormatReaderSource> readerSource;
    Rectangle<int>* thumbnailBounds = NULL;
    float zoom;
    String name;
    float volume;
    float gain = 1;
	int offset = 0;
	double sampleRate;
    long sampleOffset = 0;
    long oldOffset = 0;
    int loopCount = 1;
	bool selected = false;
    bool loop = false;
    bool dragging = false;
    int dragStartX = 0;
    virtual void changeListenerCallback(ChangeBroadcaster * source) override;
    void paintIfNoFileLoaded(Graphics& g, const Rectangle<int>& thumbnailBounds);
    void paintIfFileLoaded(Graphics& g, const Rectangle<int>& thumbnailBounds);
    ResizableEdgeComponent* resizerR;
    ResizableEdgeComponent* resizerL;
    MultiComponentDragger* dragger = NULL;
    


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioRegion)
};


#endif  // AUDIOREGION_H_INCLUDED
