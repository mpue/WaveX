/*
  ==============================================================================

    Project.cpp
    Created: 21 Dec 2016 8:18:45pm
    Author:  Matthias Pueski

  ==============================================================================
*/

#include "Project.h"


Project *Project::instance = NULL;
long  Project::DEFAULT_TRACK_LENGTH = 600;
int   Project::DEFAULT_TRACK_HEIGHT = 280;
float Project::DEFAULT_TEMPO = 120.0f;