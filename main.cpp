/*
*   Author: Tyler Scotti
*   Date: March 2nd, 2023
*   Description: This program is an online shopping cart simulator
*   Note: 8/5/23 - Realized after a while I had an misuse of the inline and was causing errors. Fixed now, other code left the same but main could
*   use a bit of a clean up. Task for another day. - Welp, another day turned out to be a few mins later.
*/

#include "ShoppingCart.h"
#include "menu.h"

int main(){
//Variable initalization
    std::string name, date;
    char choice;
//User Input
    gatherNameandDate(name, date);

//Creates list obj & prints the user's name and the current date in a formatted form
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
