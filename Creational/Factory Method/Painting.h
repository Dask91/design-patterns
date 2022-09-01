#pragma once

#include <string>
#include "Furniture.h"


struct PaintingInfo
{
    std::string Name;
    std::string Author;
    std::string Year;
    std::string Style;
};


class Painting : public Furniture
{

public:

    Painting(PaintingInfo PaintingSpecifics, FurnitureInfo BaseInfo) { PaintingSpecifics = PaintingSpecifics, BaseInfo = BaseInfo; };

    std::string GetDescription() override { return BaseInfo.Description; };
    int GetItemCode() override { return BaseInfo.Code; };

    std::string GetName() { return PaintingSpecifics.Name; };
    std::string GetAuthor() { return PaintingSpecifics.Author; };
    std::string GetYear() { return PaintingSpecifics.Year; };
    std::string GetStyle() { return PaintingSpecifics.Style; };

private:

    PaintingInfo PaintingSpecifics;
    FurnitureInfo BaseInfo;

};