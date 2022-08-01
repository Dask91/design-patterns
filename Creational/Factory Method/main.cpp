#include <iostream>
#include <string>
#include "LivingRoomFurnitureFactory.h"

using namespace std;


// Factory method example:
// An interior design service returns furniture suggestions from a given decoration style.
int main()
{
    // Client needs to redecorate the living room
    std::unique_ptr<FurnitureFactory> FurnitureService = make_unique<LivingRoomFurnitureFactory>();

    cout << "What decorative style are you searching for?" << endl;
    cout << "Options:" << endl;
    cout << "1) Contemporary" << endl;
    cout << "2) Rustic" << endl;
    cout << "3) Bohemian" << endl;
    cout << "(enter option number)" << endl;
    
    int UserInput;
    cin >> UserInput;
    cout << endl;

    // Boilerplate to map the user input to a DecorStyle
    DecorStyle Style = DecorStyle::None;
    switch (UserInput)
    {
    case 1:
        Style = DecorStyle::Contemporary;
        break;
    
    case 2:
        Style = DecorStyle::Rustic;
        break;

    case 3:
        Style = DecorStyle::Bohemian;
        break;

    default:
        cout << "Please enter a valid option number." << endl;
    }

    if (Style != DecorStyle::None)
    {
        // Use the factory method!
        // Initialization of the Furniture object is deferred to the FurnitureFactory
        std::unique_ptr<Furniture> Suggestion = FurnitureService->Suggest(Style);

        if (Suggestion)
        {
            cout << "We recommend the following item:" << endl << endl;
            cout << Suggestion->GetDescription() << endl;
            cout << "Item code: #" << Suggestion->GetItemCode() << endl;
        }
        else
        {
            cout << "There is no available item at the moment for the requested decorative style." << endl;
        }
    }
    
    return 0;
}