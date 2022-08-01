#pragma once

#include "TravelStrategy.h"


class TravelPackage
{

public:

    TravelPackage() = delete;

    TravelPackage(TravelStrategy* Strategy) { _Strategy = Strategy; };
    ~TravelPackage() = default;

    HotelBooking SelectHotel(const std::string& Location, std::vector<HotelBooking> Hotels) { return _Strategy->SelectHotel(Location, Hotels); };

    TransportTicket SelectTransport(const std::string& From,
                                    const std::string& To,
                                    std::vector<TransportTicket> Transports) 
                    { return _Strategy->SelectTransport(From, To, Transports); };

private:

    TravelStrategy* _Strategy;

};