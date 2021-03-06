//
//  PluginManager.cpp
//  WaveX - App
//
//  Created by Matthias Pueski on 06.04.18.
//  Copyright © 2018 pueski.de. All rights reserved.
//

#include "PluginManager.h"

PluginManager* PluginManager::instance = NULL;

PluginManager::PluginManager() {
    apfm = new AudioPluginFormatManager();
    apfm->addDefaultFormats();
}

void PluginManager::scanPlugins() {
    
    AudioPluginFormatManager* apfm = new AudioPluginFormatManager();
    apfm->addDefaultFormats();
    
    KnownPluginList *pluginList = new KnownPluginList();
    PropertiesFile::Options options;
    
    String userHome = File::getSpecialLocation(File::userHomeDirectory).getFullPathName();
    
    File appDir = File(userHome+"/.WaveX");
    
    if (!appDir.exists()) {
        appDir.createDirectory();
    }
    
    File file = File(userHome+"/.WaveX/plugin.properties");
    PropertiesFile* props = new PropertiesFile(file,options);
    
    PluginListComponent* pluginListComponent = new PluginListComponent(*apfm,*pluginList,File(), props);
    
    DialogWindow::LaunchOptions launchOptions;
    launchOptions.dialogTitle = ("Manage Plugins");
    launchOptions.escapeKeyTriggersCloseButton = true;
    launchOptions.resizable = true;
    launchOptions.useNativeTitleBar = true;
    launchOptions.useBottomRightCornerResizer = true;
    launchOptions.componentToCentreAround = nullptr;
    launchOptions.content.setOwned(pluginListComponent);
    launchOptions.content->setSize(600, 580);
    launchOptions.runModal();
    
    File pluginDir = File(userHome+"/.WaveX/plugins");
    
    if (!pluginDir.exists()) {
        pluginDir.createDirectory();
    }
    
    for (int i = 0; i < pluginList->getNumTypes();i++) {
        pluginList->getType(i)->createXml()->writeToFile(File(userHome+"/.WaveX/plugins/"+pluginList->getType(i)->name),"");
    }

}


void PluginManager::configureBusLayout(AudioPluginInstance* plugin, AudioDeviceManager* deviceManager, AudioAppComponent* component) {
    juce::AudioProcessor::BusesLayout layout =  plugin->getBusesLayout();
    
    int numPluginInputs = plugin->getBusCount(true) * 2;
    int numPluginOutputs = plugin->getBusCount(false) * 2;
    
    // check input and output bus configuration
    
    
    juce::BigInteger activeInputChannels = deviceManager->getCurrentAudioDevice()->getActiveInputChannels();
    juce::BigInteger activeOutputChannels = deviceManager->getCurrentAudioDevice()->getActiveOutputChannels();
    
    int numInputChannels = deviceManager->getCurrentAudioDevice()->getInputChannelNames().size();
    int numOutputChannels = deviceManager->getCurrentAudioDevice()->getOutputChannelNames().size();
    
    
    int numActiveHostInputs = getNumActiveChannels(activeInputChannels.toInteger());
    int numActiveHostOutputs = getNumActiveChannels(activeOutputChannels.toInteger());
    
    int requestedInputChannelSize = numActiveHostInputs;
    int requestedOutputChannelSize = numActiveHostOutputs;
    
    // we have a problem if a plugin has more inputs and outputs that are active
    // try to set the num of inputs/ouputs accordingly, if this fails we are fucked anyway
    
    if (numPluginInputs > numActiveHostInputs) {
        requestedInputChannelSize = numPluginInputs;
    }
    if (numPluginOutputs > numActiveHostOutputs) {
        requestedOutputChannelSize = numPluginOutputs;
    }
    
    component->setAudioChannels(requestedInputChannelSize, requestedOutputChannelSize);
    
    Logger::getCurrentLogger()->writeToLog("Active output channels "+String(numActiveHostOutputs));
    Logger::getCurrentLogger()->writeToLog("Active input channels "+String(numActiveHostInputs));
}


void PluginManager::addPlugin(String name, AudioDeviceManager* deviceManager, AudioAppComponent* component) {
    

    String error = String("Error");
    PluginDescription pd;
    
    String userHome = File::getSpecialLocation(File::userHomeDirectory).getFullPathName();
    
    File preset = File(userHome+"/.WaveX/plugins/"+name);
    ScopedPointer<XmlElement> xml = XmlDocument(preset).getDocumentElement();
    pd.loadFromXml(*xml.get());
    
    AudioPluginInstance* plugin = apfm->createPluginInstance(pd, Project::getInstance()->getSampleRate(), Project::getInstance()->getBufferSize(),error);
    plugin->prepareToPlay(Project::getInstance()->getSampleRate(), Project::getInstance()->getBufferSize());
    AudioProcessorEditor* editor = plugin->createEditorIfNeeded();
    
    // configureBusLayout(plugin, deviceManager,component);
    
    pluginMap[name] = plugin;
    
    PluginWindow* win = new PluginWindow(name,editor);
    pluginWindowMap[name] = win;
    
}

PluginManager::PluginWindow* PluginManager::getPluginWindow(String name) {
    return pluginWindowMap[name];
}

AudioPluginInstance* PluginManager::getPlugin(juce::String name) {
    return pluginMap[name];
}

long PluginManager::getNextPluginId() {
    
    // first 10 ids are reserved for default channels
    return pluginMap.size() + 10;
}

void PluginManager::cleanup() {
    
    for(std::map<String, PluginWindow*>::iterator itr = pluginWindowMap.begin(); itr != pluginWindowMap.end(); itr++)
    {
        if (itr->second->isVisible()) {
            itr->second->setVisible(false);
        }
        delete (itr->second);
    }
    
}

