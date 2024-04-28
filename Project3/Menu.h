#ifndef MENU_H
#define MENU_H

#include <string>
using namespace std;

class Menu {
public:
    // Display menu and get user's choice
    static int displayAndGetChoice();

    // Get item name from user for searching
    static string getItemFromUser();
};

#endif