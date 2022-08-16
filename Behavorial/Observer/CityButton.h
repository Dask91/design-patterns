#pragma once

#include <vector>
#include <algorithm>
#include <FL/Fl_Button.H>
#include "InfoWidget.h"
#include "InfoSubject.h"


// Displays various informations about a city when pressed.
class CityButton : public Fl_Button, public InfoSubject
{

public:

    CityButton(int X, int Y, int Width, int Height, const char* Label = 0) : Fl_Button(X, Y, Width, Height, Label) {};

    void AttachInfo(InfoWidget* Info) override;
    void DetachInfo(InfoWidget* Info) override;
    void DisplayInfos() override;

protected:

    int handle(int Event) override;

private:

    std::vector<InfoWidget*> CityInfos;

};


void CityButton::AttachInfo(InfoWidget* Info)
{
    CityInfos.push_back(Info);
}

void CityButton::DetachInfo(InfoWidget* Info)
{
    CityInfos.erase(std::remove(CityInfos.begin(), CityInfos.end(), Info), CityInfos.end());
}

void CityButton::DisplayInfos()
{
    // The point of the observer design pattern
    // This generic approach is not coupled to specific UI elements
    for (auto Info : CityInfos)
    {
        Info->Display();
    }
}

int CityButton::handle(int Event)
{
    if (Event == FL_PUSH)
    {
        DisplayInfos();
    }
    
    return Event == FL_PUSH;
}