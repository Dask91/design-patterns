#pragma once

#include "FurnitureFactory.h"
#include "Painting.h"
#include "Rug.h"


class LivingRoomFurnitureFactory : public FurnitureFactory
{
public:
    std::unique_ptr<Furniture> Suggest(DecorStyle Style) override;

};


std::unique_ptr<Furniture> LivingRoomFurnitureFactory::Suggest(DecorStyle Style)
{
    std::unique_ptr<Furniture> Suggestion;
    switch (Style)
    {
        case DecorStyle::Contemporary:
        {
            FurnitureInfo BaseInfo { "A hard rug colored with beige, orange and turquoise diamonds.", 128232 };
            Suggestion = std::make_unique<Rug>("Polypropylene", BaseInfo);
            break;
        }

        case DecorStyle::Rustic:
        {
            FurnitureInfo BaseInfo { "A thick brown rug in faux fur.", 874007 };
            Suggestion = std::make_unique<Rug>("Polyester Fur", BaseInfo);
            break;
        }

        case DecorStyle::Bohemian:
        {
            FurnitureInfo BaseInfo { "A calm watercolor of a woman resting under a tree.", 914558 };
            PaintingInfo PaintingSpecifics;
            PaintingSpecifics.Name = "Jeune femme se reposant sous un pommier";
            PaintingSpecifics.Author = "Tiny";
            PaintingSpecifics.Year = "2010";
            PaintingSpecifics.Style = "Naïve art";

            Suggestion = std::make_unique<Painting>(PaintingSpecifics, BaseInfo);
            break;
        }
    }

    return Suggestion;
}