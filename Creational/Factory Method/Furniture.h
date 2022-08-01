#pragma once

#include <string>


// Basic information required to initialize a Furniture
struct FurnitureInfo
{
    std::string Description;
    int Code;
};

class Furniture
{

public:

    virtual ~Furniture() {};
    virtual std::string GetDescription() = 0;
    virtual int GetItemCode() = 0;
    
};