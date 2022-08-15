#pragma once


// A simple interface for an information widget that can be displayed on screen.
// This interface is superficial in this example, as it would be more direct to handle a Fl_Widget with draw().
// The InfoWidget interface narrows down what a typical base class for an observer may look like.
class InfoWidget
{
public:

    virtual void Display() = 0;
};