#include "Menu.h"
#include <iostream>
using namespace std;

int Menu::displayAndGetChoice() {
    int choice;
    while (true) {
        cout << "\nMenu:\n"
            << "1. Search for item frequency\n"
            << "2. Print frequency of all items\n"
            << "3. Print histogram\n"
            << "4. Exit\n"
            << "Enter your choice: ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 4) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
        }
        else {
            break; // Valid input, exit the loop
        }
    }
    return choice;
}

string Menu::getItemFromUser() {
    string item;
    cout << "Enter the item you wish to search for: ";
    cin >> item;
    return item;
}