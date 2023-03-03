#include "ShoppingCart.h"
#include <string>
#include <iostream>


ShoppingCart::ShoppingCart() : customerName("None"), currentDate("January 1st, 2016") {} //Default Constructor

ShoppingCart::ShoppingCart(std::string customerName, std::string currentDate){ 
    this->customerName = customerName;
    this->currentDate = currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase& itemName){
    cartItems.push_back(itemName); //Adds item to the vector
}

inline void ShoppingCart::SetCustomerName(std::string& name){ this->customerName = name; } //Sets customer name

std::string ShoppingCart::GetCustomerName(){ return customerName; } //Gets customer name

inline void ShoppingCart::SetDate(std::string& date){ this->currentDate = date; } //Sets Date

std::string ShoppingCart::GetDate(){ return currentDate; } //Gets date

void ShoppingCart::RemoveItem(std::string&  itemName){
    int i = 0;
    if(i < cartItems.size()){
        for(int i = 0; i < cartItems.size(); i++){
            if (cartItems.at(i).GetName().compare(itemName) == 0){ //If any element in cartItems is equal to the parameter, it is in the list, thus is removed.
                cartItems.erase(cartItems.begin() + i); //Erases index i from list.
                std::cout << itemName << " has been removed from the list." << std::endl;
            } else {
                std::cout << "Item not found in cart. Nothing removed." << std::endl;
            }
        }
    } else {
        std::cout << "No items in the list.";
    }
}

void ShoppingCart::Print(){
    std::cout << "\nCustomer name: " << GetCustomerName() <<"\nToday's Date: " << GetDate() << std::endl;
}

void ShoppingCart::PrintDescriptions(){
    std::cout << customerName << "'s Shopping Cart - " << currentDate << std::endl;
    std::cout << "Item Descriptions\n" << std::endl;
    for(int i = 0; i < cartItems.size(); i++){
        cartItems.at(i).PrintItemDescription();
    }
    std::cout << std::endl;
}

void ShoppingCart::ModifyItem(std::string& itemName, int itemQuantity){
    for(int i = 0; i < cartItems.size(); i++){
        if(cartItems.at(i).GetName().compare(itemName) == 0){ //Finds the index of the item name the user typed in.
             //Changes index of the item name the user typed in to the new quantity the provided.
        } else {
            std::cout << "Item not found in cart. Nothing modified." << std::endl; //If item name user entered isn't found, it isn't in the list.
        }
    }

}

int ShoppingCart::GetNumItemsInCart(){ //Returns the amount of items in cart.
    int totalQuantity = 0;
    for(int i = 0; i < cartItems.size(); i++){
        totalQuantity += cartItems.at(i).GetQuantity();
    }
    return totalQuantity;
}

double ShoppingCart::GetCostOfCart(){ //Gets the total cost of the cart
    double total = 0;
    for(int i = 0; i < cartItems.size(); i++){
        total = total +(cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity());
    }
    return total;
}

void ShoppingCart::PrintTotal(){ //Print
    std::cout << customerName << "'s Shopping Cart - " << currentDate << std::endl;
    std::cout << "Number of items: " << GetNumItemsInCart() << "\n\n";

    for(int i = 0; i < cartItems.size(); i++){
        cartItems.at(i).PrintItemCost();
    }
    std::cout << std::endl;
    std::cout << "Total: " << GetCostOfCart() << std::endl;   
} 