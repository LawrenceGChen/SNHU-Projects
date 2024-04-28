#ifndef ITEMTRACKER_H
#define ITEMTRACKER_H

#include <map>
#include <string>
using namespace std;

class ItemTracker {
private:
    map<string, int> itemFrequency;

public:
    // Load item frequency data from a file
    void loadDataFromFile(const string& filename);

    // Save item frequency data to a file
    void saveDataToFile(const string& filename);

    // Get frequency of a specific item
    int getItemFrequency(const string& item) const;

    // Print frequency of all items
    void printAllItemFrequency() const;

    // Print histogram of item frequencies
    void printHistogram() const;
};

#endif