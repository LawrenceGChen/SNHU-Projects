#include "ItemTracker.h"
#include "Menu.h"
#include <iostream>
using namespace std;

int main() {
    ItemTracker itemTracker;

    // Load data from input file
    itemTracker.loadDataFromFile("CS210_Project_Three_Input_File.txt");

    int choice;
    do {
        choice = Menu::displayAndGetChoice();

        switch (choice) {
        case 1:
        {
            string item = Menu::getItemFromUser();
            cout << "Frequency of " << item << ": " << itemTracker.getItemFrequency(item) << endl;
        }
        break;
        case 2:
            itemTracker.printAllItemFrequency();
            break;
        case 3:
            itemTracker.printHistogram();
            break;
        case 4:
            itemTracker.saveDataToFile("frequency.dat"); // Save data to backup file before exiting
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}