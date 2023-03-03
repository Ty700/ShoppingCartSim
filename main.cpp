/*
*   Author: Tyler Scotti
*   Date: March 2nd, 2023
*   Description: This program is an online shopping cart simulator
*/

#include "ItemToPurchase.h"
#include "ItemToPurchase.cpp"
#include "ShoppingCart.h"
#include "ShoppingCart.cpp"

#include <string>
#include <iostream>
//Function Declarations
void PrintMenu();
void ExecuteMenu(char choice, ShoppingCart& list);

int main(){
//Variable initalization
    std::string name, date;
    char choice;
//User Input
    std::cout << "Enter customer's name:" << std::endl;
        getline(std::cin, name);
    std::cout << "Enter today's date\n";
        getline(std::cin, date);
    ShoppingCart list(name, date);
    list.Print();

//Inf loop until user answers q, then program is terminated.
    do{
        PrintMenu();
        std::cin >> choice;
        std::cin.ignore();
        ExecuteMenu(choice, list);
    }while(choice != 'q');
}

//Print's the menu 
void PrintMenu(){
    std::cout << "\nMENU\na - Add item to cart\nd - Remove item from cart\nc - Change item quantity\ni - Output item's descriptions\no = Output shopping cart\nq - Quit\n\nChoose an option: ";
}

//Exectutes the menu
void ExecuteMenu(char choice, ShoppingCart& list){
    switch (choice){ 
        case 'a':
        case 'A': //Add item
        {   
            std::string itemName, itemDescription;
            double itemPrice;
            int itemQuantity;

            std::cout << "Enter the item name:" << std::endl;
                getline(std::cin, itemName);
            std::cout << "Enter the item description:" << std::endl;
                getline(std::cin, itemDescription);
            std::cout << "Enter the item's price:\n$";
                std::cin >> itemPrice;
            std::cout << "Enter the item quantity:\n";
                std::cin >> itemQuantity;
            ItemToPurchase obj = ItemToPurchase(itemName, itemDescription, itemQuantity, itemPrice);
            list.AddItem(obj);
            break;
        }
        case 'd':
        case 'D': //Remove item
        {
            std::string itemNameToRemove;
            std::cout << "Enter the name of the item to remove:\n";
                getline(std::cin, itemNameToRemove);
            list.RemoveItem(itemNameToRemove);
            break;
        }
        case 'c':
        case 'C': //Modify quantity
        {   
            std::string itemName; 
            int itemQuantity;
            std::cout << "CHANGE ITEM QUANTITY\nEnter the item name:\n";
                getline(std::cin, itemName);
            std::cout << "Enter the new quantity:\n";
                std::cin >> itemQuantity;
            list.ModifyItem(itemName, itemQuantity);
            break;
        }
        case 'i':
        case 'I': //Print Item Descriptions
        {   
            list.PrintDescriptions();
            break;
        }
        case 'o': 
        case 'O': //Prints total of the items in the cart
        {
            list.PrintTotal();
            break;
        }
        case 'q':
        case 'Q':
            break;
        default:
            std::cout << "That wasn't an option. Try again" << std::endl;
            break;
    }
} 
