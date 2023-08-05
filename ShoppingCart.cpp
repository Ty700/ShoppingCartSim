#include "ShoppingCart.h"
#include <string>
#include <iostream>
#include <iomanip>

ShoppingCart::ShoppingCart() : customerName("None"), currentDate("January 1st, 2016") {} //Default Constructor

ShoppingCart::ShoppingCart(std::string customerName, std::string currentDate){ 
    this->customerName = customerName;
    this->currentDate = currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase& itemName){
    cartItems.push_back(itemName); //Adds item to the vector
}

 void ShoppingCart::SetCustomerName(std::string& name){ this->customerName = name; } //Sets customer name

std::string ShoppingCart::GetCustomerName(){ return customerName; } //Gets customer name

void ShoppingCart::SetDate(std::string& date){ this->currentDate = date; } //Sets Date

std::string ShoppingCart::GetDate(){ return currentDate; } //Gets date

void ShoppingCart::RemoveItem(std::string&  itemName){
    if(cartItems.size() > 0){
        for(int i = 0; i < cartItems.size(); i++){
            bool found = false;
            if (cartItems.at(i).GetName().compare(itemName) == 0){ //If any element in cartItems is equal to the parameter, it is in the list, thus is removed.
                cartItems.erase(cartItems.begin() + i); //Erases index i from list.
                found = true;
                std::cout << std::endl << itemName << " has been removed from the list." << std::endl;
            } else if (found != true){
                std::cout << "\nItem not found in cart. Nothing removed." << std::endl; //If for loop iterates through them all and doesn't find anything, then item can't be in cart
            }
        }
    } else {
        std::cout << "\nNo items in the list." << std::endl;
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
    if(cartItems.size() > 0){
        for(int i = 0; i < cartItems.size(); i++){
            if(cartItems.at(i).GetName().compare(itemName) == 0){ //Finds the index of the item name the user typed in.
                cartItems.at(i).SetQuantity(itemQuantity);//Changes index of the item name the user typed in to the new quantity the provided.
            } else {
                std::cout << "\nItem not found in cart. Nothing modified." << std::endl; //If item name user entered isn't found, it isn't in the list.
            }
        }
    } else {
        std::cout << "\nItem not found in cart. Nothing modified." << std::endl; //In case anyone tries to modify an item in an empty list
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
    if(cartItems.size() > 0){
        std::cout << customerName << "'s Shopping Cart - " << currentDate << std::endl;
        std::cout << "Number of items: " << GetNumItemsInCart() << "\n\n";

        for(int i = 0; i < cartItems.size(); i++){
            cartItems.at(i).PrintItemCost();
        }
        std::cout << "\nTotal: $" << std::fixed << std::setprecision(2) << GetCostOfCart() << std::endl;
    } else {
        std::cout << "\nShopping cart is empty." << std::endl;
    }
} 
