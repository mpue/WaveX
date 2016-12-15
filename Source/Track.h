/*
  ==============================================================================

    Track.h
    Created: 25 Nov 2016 10:00:36pm
    Author:  Matthias Pueski

  ==============================================================================
*/

#ifndef TRACK_H_INCLUDED
#define TRACK_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class Track    : public Component, public ChangeListener
{
public:
    Track(File file, TimeSliceThread* thread);
    ~Track();

    void paint (Graphics&) override;
    void resized() override;
    AudioThumbnail* getThumbnail();
    AudioTransportSource* getSource();
    void setThumbnailBounds(Rectangle<int>* bounds);
    void setZoom(float zoom);
    String getName();
    void setGain(float gain);
    void setVolume(float volume);
    float getVolume();
    AudioSampleBuffer* getBuffer();
    
private:
    AudioSampleBuffer* audioBuffer;
    AudioFormatManager manager;
    AudioThumbnail* thumbnail;
    AudioThumbnailCache* thumbnailCache;
    // AudioFormatReader* reader;
    ScopedPointer<AudioFormatReaderSource> readerSource;
    AudioTransportSource* source;
    Rectangle<int>* thumbnailBounds;
    float zoom;
    String name;
    float volume;
    virtual void changeListenerCallback(ChangeBroadcaster * source) override;
    void paintIfNoFileLoaded(Graphics& g, const Rectangle<int>& thumbnailBounds);
    void paintIfFileLoaded(Graphics& g, const Rectangle<int>& thumbnailBounds);
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Track)
};


#endif  // TRACK_H_INCLUDED
