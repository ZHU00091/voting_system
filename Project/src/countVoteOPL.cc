#include <iostream>
#include <vector>
#include "countVoteOPL.h"
using namespace std;


CountVoteOPL::CountVoteOPL(OPL* opl) {
    OPL_count = opl;
    vote = OPL_count->get_OPL_vote();
    can = OPL_count->get_candidate();
}

map<string,int> CountVoteOPL::get_vote_count() {
     vector<int> temp;
     for (int i=0; i<can.size(); i++) {
         temp.push_back(0);
     }
     for (int i=0; i<vote.size(); i++) {
         string t = vote[i];
         int index = t.find('1');  // the index of '1' in the vote indicates the
         // index of the party they want to vote
         temp[index] += 1;
     }
     for (int i=0; i<can.size(); i++) {
         vote_count.insert(std::pair<string,int>(can[i],temp[i]));
     }
     return vote_count;
}
