# Automatically generated makefile, created by the Projucer
# Don't edit this file! Your changes will be overwritten when you re-save the Projucer project!

# (this disables dependency generation if multiple architectures are set)
DEPFLAGS := $(if $(word 2, $(TARGET_ARCH)), , -MMD)

ifndef STRIP
  STRIP=strip
endif

ifndef AR
  AR=ar
endif

ifndef CONFIG
  CONFIG=Debug
endif

ifeq ($(CONFIG),Debug)
  JUCE_BINDIR := build
  JUCE_LIBDIR := build
  JUCE_OBJDIR := build/intermediate/Debug
  JUCE_OUTDIR := build

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := -march=native
  endif

  JUCE_CPPFLAGS := $(DEPFLAGS) -DLINUX=1 -DDEBUG=1 -D_DEBUG=1 -DJUCER_LINUX_MAKE_6D53C8B4=1 -DJUCE_APP_VERSION=1.0.0 -DJUCE_APP_VERSION_HEX=0x10000 $(shell pkg-config --cflags alsa freetype2 libcurl x11 xext xinerama) -pthread -I../../JuceLibraryCode -I../../../../../Downloads/JUCE/modules -I../../../../../vst/JUCE/modules
  JUCE_CFLAGS += $(CFLAGS) $(JUCE_CPPFLAGS) $(TARGET_ARCH) -g -ggdb -O0
  JUCE_CXXFLAGS += $(CXXFLAGS) $(JUCE_CFLAGS) -std=c++11
  JUCE_LDFLAGS += $(LDFLAGS) $(TARGET_ARCH) -L$(JUCE_BINDIR) -L$(JUCE_LIBDIR) $(shell pkg-config --libs alsa freetype2 libcurl x11 xext xinerama) -lGL -ldl -lpthread -lrt 

  TARGET := WaveX
  BLDCMD = $(CXX) -o $(JUCE_OUTDIR)/$(TARGET) $(OBJECTS) $(JUCE_LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
  CLEANCMD = rm -rf $(JUCE_OUTDIR)/$(TARGET) $(JUCE_OBJDIR)
endif

ifeq ($(CONFIG),Release)
  JUCE_BINDIR := build
  JUCE_LIBDIR := build
  JUCE_OBJDIR := build/intermediate/Release
  JUCE_OUTDIR := build

  ifeq ($(TARGET_ARCH),)
    TARGET_ARCH := -march=native
  endif

  JUCE_CPPFLAGS := $(DEPFLAGS) -DLINUX=1 -DNDEBUG=1 -DJUCER_LINUX_MAKE_6D53C8B4=1 -DJUCE_APP_VERSION=1.0.0 -DJUCE_APP_VERSION_HEX=0x10000 $(shell pkg-config --cflags alsa freetype2 libcurl x11 xext xinerama) -pthread -I../../JuceLibraryCode -I../../../../../Downloads/JUCE/modules -I../../../../../vst/JUCE/modules
  JUCE_CFLAGS += $(CFLAGS) $(JUCE_CPPFLAGS) $(TARGET_ARCH) -O3
  JUCE_CXXFLAGS += $(CXXFLAGS) $(JUCE_CFLAGS) -std=c++11
  JUCE_LDFLAGS += $(LDFLAGS) $(TARGET_ARCH) -L$(JUCE_BINDIR) -L$(JUCE_LIBDIR) -fvisibility=hidden $(shell pkg-config --libs alsa freetype2 libcurl x11 xext xinerama) -lGL -ldl -lpthread -lrt 

  TARGET := WaveX
  BLDCMD = $(CXX) -o $(JUCE_OUTDIR)/$(TARGET) $(OBJECTS) $(JUCE_LDFLAGS) $(RESOURCES) $(TARGET_ARCH)
  CLEANCMD = rm -rf $(JUCE_OUTDIR)/$(TARGET) $(JUCE_OBJDIR)
endif

OBJECTS := \
  $(JUCE_OBJDIR)/AudioClip_4d79daa7.o \
  $(JUCE_OBJDIR)/AuxBusConfig_85c8d107.o \
  $(JUCE_OBJDIR)/AuxSendConfig_944e732f.o \
  $(JUCE_OBJDIR)/EffectConfig_8cedd73c.o \
  $(JUCE_OBJDIR)/InstrumentConfig_45bd0412.o \
  $(JUCE_OBJDIR)/MixerConfig_d0725d8c.o \
  $(JUCE_OBJDIR)/Project_cc5166fa.o \
  $(JUCE_OBJDIR)/ProjectConfig_c56c4d9c.o \
  $(JUCE_OBJDIR)/RegionConfig_225c24df.o \
  $(JUCE_OBJDIR)/TrackConfig_a6d4984e.o \
  $(JUCE_OBJDIR)/AppWindowComponent_c01bc215.o \
  $(JUCE_OBJDIR)/CustomLookAndFeel_ab3d772e.o \
  $(JUCE_OBJDIR)/ImageToggleButton_895fbd82.o \
  $(JUCE_OBJDIR)/InfoPanel_a131c57.o \
  $(JUCE_OBJDIR)/MainComponent_a6ffb4a5.o \
  $(JUCE_OBJDIR)/ToolbarPanel_8e4ee752.o \
  $(JUCE_OBJDIR)/TransportPanel_18909a64.o \
  $(JUCE_OBJDIR)/MasterChannelPanel_b4b7ea4c.o \
  $(JUCE_OBJDIR)/Mixer_d95e2aea.o \
  $(JUCE_OBJDIR)/MixerPanel_f7050b84.o \
  $(JUCE_OBJDIR)/AudioRegion_46364bcb.o \
  $(JUCE_OBJDIR)/MidiRegion_c91a6c7e.o \
  $(JUCE_OBJDIR)/MidiThumbnail_900644ac.o \
  $(JUCE_OBJDIR)/PositionMarker_20eac8cc.o \
  $(JUCE_OBJDIR)/Region_b2b8ac7d.o \
  $(JUCE_OBJDIR)/TimeLine_e3c86a6a.o \
  $(JUCE_OBJDIR)/Track_c9ac1f2c.o \
  $(JUCE_OBJDIR)/TrackNavigator_897222d5.o \
  $(JUCE_OBJDIR)/TrackPropertyPanel_23c5992d.o \
  $(JUCE_OBJDIR)/TrackPropertyView_42f565e6.o \
  $(JUCE_OBJDIR)/WaveSelector_5f1b5681.o \
  $(JUCE_OBJDIR)/Main_90ebc5c2.o \
  $(JUCE_OBJDIR)/Session_2ff97f7.o \
  $(JUCE_OBJDIR)/BinaryData_ce4232d4.o \
  $(JUCE_OBJDIR)/juce_audio_basics_6b797ca1.o \
  $(JUCE_OBJDIR)/juce_audio_devices_a742c38b.o \
  $(JUCE_OBJDIR)/juce_audio_formats_5a29c68a.o \
  $(JUCE_OBJDIR)/juce_audio_processors_dea3173d.o \
  $(JUCE_OBJDIR)/juce_audio_utils_c7eb679f.o \
  $(JUCE_OBJDIR)/juce_core_75b14332.o \
  $(JUCE_OBJDIR)/juce_cryptography_6de2ebff.o \
  $(JUCE_OBJDIR)/juce_data_structures_72d3da2c.o \
  $(JUCE_OBJDIR)/juce_events_d2be882c.o \
  $(JUCE_OBJDIR)/juce_graphics_9c18891e.o \
  $(JUCE_OBJDIR)/juce_gui_basics_8a6da59c.o \
  $(JUCE_OBJDIR)/juce_gui_extra_4a026f23.o \
  $(JUCE_OBJDIR)/juce_opengl_cd70b4c2.o \
  $(JUCE_OBJDIR)/juce_video_f128c512.o \

.PHONY: clean

$(JUCE_OUTDIR)/$(TARGET): check-pkg-config $(OBJECTS) $(RESOURCES)
	@echo Linking WaveX
	-@mkdir -p $(JUCE_BINDIR)
	-@mkdir -p $(JUCE_LIBDIR)
	-@mkdir -p $(JUCE_OUTDIR)
	@$(BLDCMD)

check-pkg-config:
	@command -v pkg-config >/dev/null 2>&1 || { echo >&2 "pkg-config not installed. Please, install it."; exit 1; }
	@pkg-config --print-errors alsa freetype2 libcurl x11 xext xinerama

clean:
	@echo Cleaning WaveX
	@$(CLEANCMD)

strip:
	@echo Stripping WaveX
	-@$(STRIP) --strip-unneeded $(JUCE_OUTDIR)/$(TARGET)

$(JUCE_OBJDIR)/AudioClip_4d79daa7.o: ../../Source/AudioClip.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling AudioClip.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AuxBusConfig_85c8d107.o: ../../Source/AuxBusConfig.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling AuxBusConfig.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AuxSendConfig_944e732f.o: ../../Source/AuxSendConfig.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling AuxSendConfig.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/EffectConfig_8cedd73c.o: ../../Source/EffectConfig.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling EffectConfig.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/InstrumentConfig_45bd0412.o: ../../Source/InstrumentConfig.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling InstrumentConfig.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/MixerConfig_d0725d8c.o: ../../Source/MixerConfig.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling MixerConfig.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Project_cc5166fa.o: ../../Source/Project.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling Project.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ProjectConfig_c56c4d9c.o: ../../Source/ProjectConfig.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling ProjectConfig.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/RegionConfig_225c24df.o: ../../Source/RegionConfig.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling RegionConfig.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/TrackConfig_a6d4984e.o: ../../Source/TrackConfig.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling TrackConfig.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AppWindowComponent_c01bc215.o: ../../Source/AppWindowComponent.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling AppWindowComponent.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/CustomLookAndFeel_ab3d772e.o: ../../Source/CustomLookAndFeel.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling CustomLookAndFeel.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ImageToggleButton_895fbd82.o: ../../Source/ImageToggleButton.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling ImageToggleButton.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/InfoPanel_a131c57.o: ../../Source/InfoPanel.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling InfoPanel.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/MainComponent_a6ffb4a5.o: ../../Source/MainComponent.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling MainComponent.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/ToolbarPanel_8e4ee752.o: ../../Source/ToolbarPanel.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling ToolbarPanel.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/TransportPanel_18909a64.o: ../../Source/TransportPanel.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling TransportPanel.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/MasterChannelPanel_b4b7ea4c.o: ../../Source/MasterChannelPanel.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling MasterChannelPanel.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Mixer_d95e2aea.o: ../../Source/Mixer.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling Mixer.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/MixerPanel_f7050b84.o: ../../Source/MixerPanel.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling MixerPanel.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/AudioRegion_46364bcb.o: ../../Source/AudioRegion.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling AudioRegion.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/MidiRegion_c91a6c7e.o: ../../Source/MidiRegion.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling MidiRegion.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/MidiThumbnail_900644ac.o: ../../Source/MidiThumbnail.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling MidiThumbnail.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/PositionMarker_20eac8cc.o: ../../Source/PositionMarker.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling PositionMarker.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Region_b2b8ac7d.o: ../../Source/Region.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling Region.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/TimeLine_e3c86a6a.o: ../../Source/TimeLine.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling TimeLine.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Track_c9ac1f2c.o: ../../Source/Track.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling Track.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/TrackNavigator_897222d5.o: ../../Source/TrackNavigator.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling TrackNavigator.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/TrackPropertyPanel_23c5992d.o: ../../Source/TrackPropertyPanel.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling TrackPropertyPanel.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/TrackPropertyView_42f565e6.o: ../../Source/TrackPropertyView.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling TrackPropertyView.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/WaveSelector_5f1b5681.o: ../../Source/WaveSelector.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling WaveSelector.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Main_90ebc5c2.o: ../../Source/Main.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling Main.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/Session_2ff97f7.o: ../../Source/Session.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling Session.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/BinaryData_ce4232d4.o: ../../JuceLibraryCode/BinaryData.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling BinaryData.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_audio_basics_6b797ca1.o: ../../JuceLibraryCode/juce_audio_basics.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_audio_basics.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_audio_devices_a742c38b.o: ../../JuceLibraryCode/juce_audio_devices.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_audio_devices.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_audio_formats_5a29c68a.o: ../../JuceLibraryCode/juce_audio_formats.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_audio_formats.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_audio_processors_dea3173d.o: ../../JuceLibraryCode/juce_audio_processors.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_audio_processors.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_audio_utils_c7eb679f.o: ../../JuceLibraryCode/juce_audio_utils.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_audio_utils.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_core_75b14332.o: ../../JuceLibraryCode/juce_core.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_core.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_cryptography_6de2ebff.o: ../../JuceLibraryCode/juce_cryptography.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_cryptography.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_data_structures_72d3da2c.o: ../../JuceLibraryCode/juce_data_structures.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_data_structures.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_events_d2be882c.o: ../../JuceLibraryCode/juce_events.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_events.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_graphics_9c18891e.o: ../../JuceLibraryCode/juce_graphics.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_graphics.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_gui_basics_8a6da59c.o: ../../JuceLibraryCode/juce_gui_basics.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_gui_basics.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_gui_extra_4a026f23.o: ../../JuceLibraryCode/juce_gui_extra.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_gui_extra.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_opengl_cd70b4c2.o: ../../JuceLibraryCode/juce_opengl.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_opengl.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

$(JUCE_OBJDIR)/juce_video_f128c512.o: ../../JuceLibraryCode/juce_video.cpp
	-@mkdir -p $(JUCE_OBJDIR)
	@echo "Compiling juce_video.cpp"
	@$(CXX) $(JUCE_CXXFLAGS) -o "$@" -c "$<"

-include $(OBJECTS:%.o=%.d)
