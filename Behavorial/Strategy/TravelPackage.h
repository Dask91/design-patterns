#pragma once

#include "TravelStrategy.h"


class TravelPackage
{

public:

    TravelPackage() = delete;

    TravelPackage(TravelStrategy* Strategy) { this->Strategy = Strategy; };
    ~TravelPackage() = default;

    HotelBooking SelectHotel(const std::string& Location, std::vector<HotelBooking> Hotels) { return Strategy->SelectHotel(Location, Hotels); };

    TransportTicket SelectTransport(const std::string& From,
                                    const std::string& To,
                                    std::vector<TransportTicket> Transports) 
                    { return this->Strategy->SelectTransport(From, To, Transports); };

private:

    TravelStrategy* Strategy;

};