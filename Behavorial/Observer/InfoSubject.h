#pragma once

#include "InfoWidget.h"


// Base subject class, inherited by a UI element such as a button that
// controls when the informations are to be displayed on screen.
class InfoSubject
{

public:

    virtual ~InfoSubject() {};

    virtual void AttachInfo(InfoWidget* Info) = 0;
    virtual void DetachInfo(InfoWidget* Info) = 0;
    virtual void DisplayInfos() = 0;

};