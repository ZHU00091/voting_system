#include <ctime>
#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <string>
#include <algorithm>

#include "displayWinnerCPL.h"

using namespace std;

DisplayWinnerCPL::DisplayWinnerCPL(map<char,int> count,std::vector<string> v) {
    result = count;
    cpl_candidate = v;
}

int DisplayWinnerCPL::display() {
    int max = 0;
    int winner = 0;
    int count = 0;
    vector<int> temp;
    for (map<char, int>::iterator it = result.begin(); it != result.end(); it++) {
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
    return winner;
//    count = 0;
//    char winner_party;  // displat winner party information
//    for (map<char, int>::iterator it = result.begin(); it != result.end(); it++) {
//        if(count == winner) {
//            cout<<"the winner party is "<<it->first<<" with total votes "<<it->second<<endl;
//            cout<<"the party "<<it->first<<" has the following candidate(s):\n";
//            winner_party = it->first;
//            return count;
//        }
//        count ++;
//    }
//    // display the candidates belong the winner party
//    for (int i=0; i<cpl_candidate.size(); i++) {
//      int index = cpl_candidate[i].find(',');
//      if (cpl_candidate[i].at(index+1) == winner_party) {
//        cout<<cpl_candidate[i];
//      }
//    }

}

int DisplayWinnerCPL::tie_handler() {
    srand(time(0));
    return rand()%2;
}
