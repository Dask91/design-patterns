#pragma once


// A simple interface for a widget that can be displayed on screen.
// The interface is superfluous in this example, as it would be more direct to handle a Fl_Widget with draw().
class InfoWidget
{
public:

    virtual ~InfoWidget() {};
    virtual void Display() = 0;
};