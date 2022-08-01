#pragma once

#include <algorithm>
#include <assert.h>
#include "TravelStrategy.h"


class BudgetTravelStrategy : public TravelStrategy
{

public:

    BudgetTravelStrategy() = default;
    ~BudgetTravelStrategy() = default;

    HotelBooking SelectHotel(const std::string& Location, std::vector<HotelBooking> Hotels) override;
    
    TransportTicket SelectTransport(const std::string& From,
                                    const std::string& To,
                                    std::vector<TransportTicket> Transports) override;

};


HotelBooking BudgetTravelStrategy::SelectHotel(const std::string& Location, std::vector<HotelBooking> Hotels)
{
    // Clear vector of bookings outside of our target location
    auto GoodLocations = std::remove_if(Hotels.begin(), Hotels.end(), [Location](auto H){ return H.Location != Location; });

    auto LeastExpensive = std::min_element(Hotels.begin(), GoodLocations, [](auto H1, auto H2){ return H1.Price < H2.Price; });
    assert(LeastExpensive != Hotels.end());
    return *LeastExpensive;
}
    
TransportTicket BudgetTravelStrategy::SelectTransport(const std::string& From,
                                                      const std::string& To,
                                                      std::vector<TransportTicket> Transports)
{
    // Clear vector of transports that don't match our itinerary
    auto GoodItineraries = std::remove_if(Transports.begin(), Transports.end(), [From](auto T){ return T.From != From; });
    GoodItineraries = std::remove_if(Transports.begin(), GoodItineraries, [To](auto T){ return T.To != To; });

    auto LeastExpensive = std::min_element(Transports.begin(), GoodItineraries, [](auto T1, auto T2){ return T1.Price < T2.Price; });
    assert(LeastExpensive != Transports.end());
    return *LeastExpensive;
}