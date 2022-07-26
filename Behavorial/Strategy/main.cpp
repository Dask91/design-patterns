#include <memory>
#include <iostream>
#include "TravelPackage.h"
#include "LuxuryTravelStrategy.h"
#include "BudgetTravelStrategy.h"

using namespace std;


// Strategy example:
// A tour operator must select hotels and transports for different price ranges (expensive or budget friendly).
int main()
{
    // Register available hotel bookings to select from
    vector<HotelBooking> HotelBookings;
    HotelBookings.push_back(HotelBooking { "Hôtels et Suites Le Dauphin", "Montréal", 202.00 });
    HotelBookings.push_back(HotelBooking { "Comfort Inn Sherbrooke", "Sherbrooke", 148.00 });
    HotelBookings.push_back(HotelBooking { "Hôtel Delta", "Trois-Rivieres", 219.00 });
    HotelBookings.push_back(HotelBooking { "L'Hôtel Universel", "Québec", 222.00 });
    HotelBookings.push_back(HotelBooking { "Le Château Frontenac", "Québec", 559.00 });
    HotelBookings.push_back(HotelBooking { "Four Seasons Hôtel Montréal", "Montréal", 775.00 });

    // Register all available transport seats
    vector<TransportTicket> TransportTickets;
    TransportTickets.push_back(TransportTicket { "Montréal", "Québec", "VIA Rail Canada", 160.00 });
    TransportTickets.push_back(TransportTicket { "Montréal", "Québec", "Air Transat", 650.00 });
    TransportTickets.push_back(TransportTicket { "Montréal", "Québec", "VIA Rail Canada", 220.45 });
    TransportTickets.push_back(TransportTicket { "Québec", "Sherbrooke", "VIA Rail Canada", 220.45 });
    TransportTickets.push_back(TransportTicket { "Québec", "Montréal", "Air Transat", 150.00 });
    TransportTickets.push_back(TransportTicket { "Trois-Rivières", "Sherbrooke", "VIA Rail Canada", 220.45 });

    cout << "Do you want the expensive or the budget friendly travel?" << endl;
    cout << "Options:" << endl;
    cout << "1) Expensive" << endl;
    cout << "2) Budget friendly" << endl;
    cout << "(enter option number)" << endl;

    int UserInput;
    cin >> UserInput;
    cout << endl;

    // Boilerplate to map the user input to a strategy
    unique_ptr<TravelStrategy> Strategy;
    switch (UserInput)
    {
        case 1:
            Strategy = make_unique<LuxuryTravelStrategy>();
            break;

        case 2:
            Strategy = make_unique<BudgetTravelStrategy>();
            break;

        default:
            cout << "Please enter a valid option number." << endl;
    }

    if (Strategy)
    {
        TravelPackage Package(Strategy.get());

        string DepartureLocation = "Montréal";
        string Destination = "Québec";
        HotelBooking LuxuryHotel = Package.SelectHotel(Destination, HotelBookings);
        TransportTicket LuxuryTransport = Package.SelectTransport(DepartureLocation, Destination, TransportTickets);

        cout << "The program selected the following bookings for your trip from " << DepartureLocation << " to " << Destination << "." << endl;
        cout << endl << endl;
        cout << "You will transit with " << LuxuryTransport.Operator << " (" << LuxuryTransport.Price << " Cad$)." << endl;
        cout << "Once you arrive in " << Destination << ", a room will be waiting for you at " << LuxuryHotel.Name;
        cout << " (" << LuxuryHotel.Price << " Cad$)." << endl;
        cout << endl;
        cout << "Your trip will cost a total of " << LuxuryTransport.Price + LuxuryHotel.Price << " Cad$." << endl;
    }

    return 0;
}