#include "ItemTracker.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void ItemTracker::loadDataFromFile(const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error: Unable to open input file!" << endl;
        exit(1);
    }

    string item;
    while (getline(inputFile, item)) {
        // Increment frequency of item or initialize it to 1 if not present
        itemFrequency[item]++;
    }

    inputFile.close();
}

void ItemTracker::saveDataToFile(const string& filename) {
    ofstream backupFile(filename);
    if (!backupFile) {
        cerr << "Error: Unable to open backup file for writing!" << endl;
        exit(1);
    }

    for (const auto& pair : itemFrequency) {
        backupFile << pair.first << " " << pair.second << endl;
    }

    backupFile.close();
}

int ItemTracker::getItemFrequency(const string& item) const {
    if (itemFrequency.find(item) != itemFrequency.end()) {
        return itemFrequency.at(item);
    }
    else {
        return 0;
    }
}

void ItemTracker::printAllItemFrequency() const {
    cout << "Item Frequency:" << endl;
    for (const auto& pair : itemFrequency) {
        cout << pair.first << " " << pair.second << endl;
    }
}

void ItemTracker::printHistogram() const {
    cout << "Item Frequency Histogram:" << endl;
    int maxItemLength = 0;
    for (const auto& pair : itemFrequency) {
        maxItemLength = max(maxItemLength, static_cast<int>(pair.first.length()));
    }

    for (const auto& pair : itemFrequency) {
        cout << setw(maxItemLength) << left << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}