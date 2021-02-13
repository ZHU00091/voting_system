#include <ctime>
#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <string>
#include <algorithm>

#include "displayWinner.h"

using namespace std;

DisplayWinner::DisplayWinner(map<string,int> count) {
    result = count;
}

string DisplayWinner::display() {
    string res = "";
    int max = 0;
    int winner = 0;
    int count = 0;
    vector<int> temp;
    for (map<string, int>::iterator it = result.begin(); it != result.end(); it++) {
        temp.push_back(it->second);
        if (it->second >= max) {
            if(it->second == max) {  // if two candidates have the same vote
              // we call tie_handler to deal with it
                int tie = tie_handler();
                if(tie >= 0.99) {
                    winner = count;
                    max = it->second;
                }
            } else {
              max = it->second;
              winner = count;
            }
        }
        count++;
    }
    count = 0;
    for (map<string, int>::iterator it = result.begin(); it != result.end(); it++) {
        if(count == winner) {
            res += "\nthe winner is: ";
            res += it->first;
            res += "the winner has total votes: ";
            res += to_string(it->second);
            return res;
        }
        count ++;
    }

}

int DisplayWinner::tie_handler() {
    srand(time(0));
    return rand()%2;
}
