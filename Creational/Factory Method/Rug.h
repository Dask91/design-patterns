#pragma once

#include <string>
#include "Furniture.h"


class Rug : public Furniture
{

public:

    Rug(std::string Fabric, FurnitureInfo BaseInfo) { Fabric = Fabric, BaseInfo = BaseInfo; };

    std::string GetDescription() override { return BaseInfo.Description; };
    int GetItemCode() override { return BaseInfo.Code; };

    std::string GetFabric() { return Fabric; };

private:

    std::string Fabric;
    FurnitureInfo BaseInfo;
    
};