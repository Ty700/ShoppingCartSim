#pragma once
#include <string>

class ItemToPurchase { 
public:
    ItemToPurchase(); //Default Constructor
    ItemToPurchase(std::string itemName, std::string& itemDescription, int& itemQuantity, double itemPrice);
    void SetName(std::string& itemName);
        std::string GetName() const;
    void SetPrice(double& itemPrice);
        double GetPrice() const;
    void SetQuantity(int& itemQuantity);
        int GetQuantity() const;
    void SetDescription (std::string& itemDescription);
        std::string GetDescription() const;
    
    void PrintItemCost();
    void PrintItemDescription();

private:
        std::string itemName, itemDescription;
        double itemPrice;
        int itemQuantity;
};

