#pragma once

#include <string>
#include <vector>


struct HotelBooking
{
    std::string Name;
    std::string Location;
    float Price;
};

struct TransportTicket
{
    std::string From;
    std::string To;
    std::string Operator;
    float Price;
};

class TravelStrategy
{

public:

    virtual ~TravelStrategy() {};

    virtual HotelBooking SelectHotel(const std::string& Location, std::vector<HotelBooking> Hotels) = 0;

    virtual TransportTicket SelectTransport(const std::string& From,
                                            const std::string& To,
                                            std::vector<TransportTicket> Transports) = 0;
    
};