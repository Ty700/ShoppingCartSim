#include "ItemToPurchase.h"
#include <iostream>
#include <iomanip>

ItemToPurchase::ItemToPurchase() : itemName("None"), itemQuantity(0), itemPrice(0), itemDescription("None") {} //Default Constructor

ItemToPurchase::ItemToPurchase(std::string itemName, std::string& itemDescription, int& itemQuantity, double itemPrice){
    this->itemName = itemName;
    this->itemDescription = itemDescription;
    this->itemQuantity = itemQuantity;
    this->itemPrice = itemPrice;
}

//Getters 
std::string ItemToPurchase::GetName() const { //Returns item name
    return itemName;
}

double ItemToPurchase::GetPrice() const { //Returns item Price
    return itemPrice;
}

int ItemToPurchase::GetQuantity() const { //Returns item Quantity
    return itemQuantity;
}

std::string ItemToPurchase::GetDescription() const{ //Returns item Description
    return itemDescription;
}

//Setters
void ItemToPurchase::SetName(std::string& itemName){ this->itemName = itemName; } //Name

void ItemToPurchase::SetPrice(double& price){ this->itemPrice = price; } //Price

void ItemToPurchase::SetQuantity(int& quantity){ this->itemQuantity = quantity; } //Quantity

void ItemToPurchase::SetDescription(std::string& itemDescription) { this->itemDescription = itemDescription; } //Description

void ItemToPurchase::PrintItemCost(){
    std::cout << GetName() << " " << GetQuantity() << " @ $" << std::fixed << std::setprecision(2) << GetPrice() << " = $" << std::fixed << std::setprecision(2) << (GetPrice() * GetQuantity()) << std::endl; 
}

void ItemToPurchase::PrintItemDescription(){
    std::cout << GetName() << ": " << GetDescription() << std::endl;
}
