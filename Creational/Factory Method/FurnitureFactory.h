#pragma once

#include <memory>
#include "Furniture.h"


enum class DecorStyle
{
    None,
    Contemporary,
    Rustic,
    Bohemian
};

class FurnitureFactory
{

public:

    virtual ~FurnitureFactory() {};

    // The factory method
    virtual std::unique_ptr<Furniture> Suggest(DecorStyle Style) = 0;

};