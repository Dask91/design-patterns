#pragma once

#include <iostream>
#include <list>
#include "Article.h"


// A Delivery contains a list of articles to purchase
class Delivery
{
public:

    Delivery Clone();

    void AddArticle(Article Article);
    void Print();
    double GetTotalCost() { return TotalCost; };

private:

    std::list<Article> Articles;
    double TotalCost = 0;

};


void Delivery::AddArticle(Article Article)
{
    Articles.push_back(Article);
    TotalCost += Article.Cost;
}

void Delivery::Print()
{
    std::cout << "Delivery includes: " << std::endl;
    for (auto Article : Articles)
    {
        std::cout << "\t" << Article.Name << std::endl;
    }
}

Delivery Delivery::Clone()
{
    Delivery Clone;
    for (auto Article : Articles)
    {
        Clone.AddArticle(Article);
    }

    return Clone;
}