//
//  main.cpp
//  Quantcast Coding Task
//
//  Created by Evan Zhang on 9/30/21.
//

#include <iostream>
#include <array>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <fstream>

using namespace std;
int main(int argc, const char * argv[]) {
    
    // Error Checking For Paramters
    if (argc != 4){
        cout << "Not Enough Paramters" << endl;
        return 1;
    }
    

    string fileName = argv[1];
    string date = argv[3];
    
    // Open file
    ifstream myfile;
    myfile.open(fileName);
    
    if (!myfile.is_open()){
        cout << "Couldn't open file" << endl;
        return 1;
    }
    
    string line;
    // Length of 10 for Date
    const int delimT = 10;
    const char delim = ',';
    
    // Get rid of first line
    getline(myfile, line);
    
    // Hold {cookie, date}, number
    map<pair<string, string>, int> table;
    map<pair<string, string>, int> filteredTable;
    
    // Parsing CSV
    while (getline(myfile, line)){
        
        // Gets cookie and day strings
        string cookie = line.substr(0, line.find(delim));
        string day = line.substr(line.find(delim) + 1, delimT);
        table[make_pair(cookie, day)]++;
    }

    // Find Max Number Cookies Possible For The Given Date
    int max = 0;
    for (auto i : table){
        if (i.first.second == date){
            if (i.second > max){
                max = i.second;
            }
            // Adds cookie pair to new map
            filteredTable[{i.first.first, i.first.second}] = i.second;
        }
    }
    
    // Prints cookie the cookie number matches the max
    for (auto j : filteredTable){
        if (j.second == max){
            cout << j.first.first << endl;
        }
    }
    
    return 0;
}
