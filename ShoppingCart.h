#pragma once
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>

#include "ItemToPurchase.h"
class ShoppingCart {
    public:
        ShoppingCart(); //Default
        ShoppingCart(std::string customerName, std::string currentDate); //Parameterized Constructor

        std::string GetCustomerName();
        void SetCustomerName(std::string& name);

        std::string GetDate();
        void SetDate(std::string& date);

        void AddItem(ItemToPurchase& item);
        void RemoveItem(std::string& itemName);
        void ModifyItem(std::string& itemName, int itemQuantity);
        
        int GetNumItemsInCart();
        double GetCostOfCart();

        void PrintTotal();
        void Print();
        void PrintDescriptions();

    private:
    std::string customerName, currentDate;
    std::vector<ItemToPurchase> cartItems;
};
