#include <assert.h>
#include <FL/Fl_Box.H>
#include "InfoSubject.h"


class CityInfoBox : public InfoWidget, public Fl_Box
{
public:

    CityInfoBox(int X, int Y, int Width, int Height, const char *Label = 0) : Fl_Box(X, Y, Width, Height, Label) {};
    void Display() override;   
};


void CityInfoBox::Display()
{
    draw();
};