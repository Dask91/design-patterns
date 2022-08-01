#pragma once

#include <string>
#include "Furniture.h"


class Rug : public Furniture
{

public:

    Rug(std::string Fabric, FurnitureInfo BaseInfo) { _Fabric = Fabric, _BaseInfo = BaseInfo; };
    ~Rug() = default;

    std::string GetDescription() override { return _BaseInfo.Description; };
    int GetItemCode() override { return _BaseInfo.Code; };

    std::string GetFabric() { return _Fabric; };

private:

    std::string _Fabric;
    FurnitureInfo _BaseInfo;
    
};