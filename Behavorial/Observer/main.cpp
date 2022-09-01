#include <memory>
#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include "ShowCityButton.h"
#include "CityInfoBox.h"
#include "City.h"

using namespace std;


// Observer example (requires FLTK):
// Client subscribes to various informations about a city, which are then displayed when a button is pressed.
int main()
{
    auto Window = make_unique<Fl_Window>(320, 180);

    // The button (subject to our "information" widgets)
    auto Button = make_unique<ShowCityButton>(20, 30, 80, 40, "Show City");
    Button->color(FL_LIGHT2);

    // Create a list of cities
    vector<City> Cities;
    Cities.push_back(City { "Kansas City", "18:22", "29°C", "39°05\'59\"N 94°34\'42\"W", 508090, "Quinton Donald Lucas"});
    Cities.push_back(City { "Québec", "19:22", "28°C", "46°48\'50\"N 71°12\'29\"W", 531902, "Bruno Marchand"});
    Cities.push_back(City { "Tokyo", "8:22", "28°C", "35°41\'23\"N 139°41\'32\"E", 13988129, "Yuriko Koike"});

    // The program selects one of these cities
    City CitySelection = Cities[0];

    // The following text boxes (observers) will be attached to our button
    auto CityNameBox = make_unique<CityInfoBox>(90, 70, 50, 50, CitySelection.Name.c_str());
    auto TimeBox = make_unique<CityInfoBox>(90, 90, 50, 50, CitySelection.Time.c_str());
    auto TempBox = make_unique<CityInfoBox>(90, 110, 50, 50, CitySelection.Temperature.c_str());
    auto CoordinatesBox = make_unique<CityInfoBox>(90, 130, 50, 50, CitySelection.Coordinates.c_str());

    // These informations will only be displayed when the button is pressed
    CityNameBox->hide();
    TempBox->hide();
    TimeBox->hide();
    CoordinatesBox->hide();

    Button->AttachInfo(CityNameBox.get());
    Button->AttachInfo(TempBox.get());
    Button->AttachInfo(TimeBox.get());
    Button->AttachInfo(CoordinatesBox.get());

    Window->end();
    Window->show();

    return Fl::run();
}