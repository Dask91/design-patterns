#include <iostream>
#include "Article.h"
#include "Delivery.h"
#include "DeliveryFactory.h"

using namespace std;


// Prototype example:
// Grocery delivery system needs to repeat previous orders.
int main()
{
    // Initialize a few Articles that can be purchased
    Article Flour { .Name = "Flour", .Cost = 7.99 };
    Article Chicken { .Name = "2 Chicken Thigh High", .Cost = 11.99 };
    Article Mustard { .Name = "Dijon Mustard", .Cost = 3.99 };

    // Client sets up a Delivery with articles
    Delivery SeptemberDelivery;
    SeptemberDelivery.AddArticle(Flour);
    SeptemberDelivery.AddArticle(Chicken);
    SeptemberDelivery.AddArticle(Mustard);

    cout << "September delivery total cost: " << "$" << SeptemberDelivery.GetTotalCost() << endl;
    SeptemberDelivery.Print();

    // Client needs to repeat the delivery for next month
    // As the Articles are private within the Delivery, the Prototype pattern is useful
    DeliveryFactory Factory;
    auto OctoberDelivery = Factory.MakeClone(SeptemberDelivery);

    cout << endl << "October delivery total cost: " << "$" << OctoberDelivery.GetTotalCost() << endl;
    OctoberDelivery.Print();
}