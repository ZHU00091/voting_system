#include <iostream>
#include <vector>
#include "countVote.h"
using namespace std;


CountVote::CountVote(CPL* cpl) {
    CPL_count = cpl;
    vote = CPL_count->get_CPL_vote();
    part = CPL_count->get_ballot_ordering();
}

map<char,int> CountVote::get_vote_count() {
    vector<int> temp;
    for (int i=0; i<part.size(); i++) {
        temp.push_back(0);
    }
    for (int i=0; i<vote.size(); i++) {
        string t = vote[i];
        int index = t.find('1');  // the index of '1' in the vote indicates the
        // index of the party they want to vote
        temp[index] += 1;
    }
    for (int i=0; i<part.size(); i++) {
      // store the information in the map
        vote_count.insert(std::pair<char,int>(part[i],temp[i]));
    }
    return vote_count;
}
