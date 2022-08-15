#include <memory>
#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include "CityButton.h"
#include "CityInfoBox.h"
#include "City.h"

using namespace std;


// Observer example (requires FLTK):
// Client subscribes to various informations about a city, which are then displayed when a button is pressed.
int main()
{
    auto Window = std::make_unique<Fl_Window>(320, 180);

    auto Button = std::make_unique<CityButton>(20, 30, 80, 40, "Show City");
    Button->color(FL_LIGHT2);

    // Create a list of cities
    std::vector<City> Cities;
    Cities.push_back(City { "Kansas City", "18:22", "29°C", "39°05\'59\"N 94°34\'42\"W", 508090, "Quinton Donald Lucas"});
    Cities.push_back(City { "Québec", "19:22", "28°C", "46°48\'50\"N 71°12\'29\"W", 531902, "Bruno Marchand"});
    Cities.push_back(City { "Tokyo", "8:22", "28°C", "35°41\'23\"N 139°41\'32\"E", 13988129, "Yuriko Koike"});

    // The program selects one of these cities
    City City = Cities[0];

    auto CityNameBox = make_unique<CityInfoBox>(90, 70, 50, 50, City.Name.c_str());
    CityNameBox->labelsize(10);
    auto TimeBox = make_unique<CityInfoBox>(90, 90, 50, 50, City.Time.c_str());
    TimeBox->labelsize(10);
    auto TempBox = make_unique<CityInfoBox>(90, 110, 50, 50, City.Temperature.c_str());
    TempBox->labelsize(10);
    auto CoordinatesBox = make_unique<CityInfoBox>(90, 130, 50, 50, City.Coordinates.c_str());
    CoordinatesBox->labelsize(10);

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