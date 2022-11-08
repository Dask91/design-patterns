#include "Delivery.h"

class DeliveryFactory
{
public:

    Delivery MakeClone(Delivery PreviousDelivery) { return PreviousDelivery.Clone(); };
};