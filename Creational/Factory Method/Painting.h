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

    Painting(PaintingInfo PaintingSpecifics, FurnitureInfo BaseInfo) { _PaintingSpecifics = PaintingSpecifics, _BaseInfo = BaseInfo; };
    ~Painting() = default;

    std::string GetDescription() override { return _BaseInfo.Description; };
    int GetItemCode() override { return _BaseInfo.Code; };

    std::string GetName() { return _PaintingSpecifics.Name; };
    std::string GetAuthor() { return _PaintingSpecifics.Author; };
    std::string GetYear() { return _PaintingSpecifics.Year; };
    std::string GetStyle() { return _PaintingSpecifics.Style; };

private:

    PaintingInfo _PaintingSpecifics;
    FurnitureInfo _BaseInfo;

};