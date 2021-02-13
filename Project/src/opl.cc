#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "opl.h"
using namespace std;

OPL::OPL(ifstream& in) {
  // reading file and store information
    string temp;
    getline(in,temp);
    int index = temp.find(',');
    temp = temp.substr(0,index);
    number_of_seat = stoi(temp);
    getline(in,temp);
    index = temp.find(',');
    temp = temp.substr(0,index);
    number_of_ballot = stoi(temp);
    getline(in,temp);
    index = temp.find(',');
    temp = temp.substr(0,index);
    number_of_candidate = stoi(temp);
    while(getline(in,temp)) {
        if(temp[0]=='1' || temp[0]==',') {  // only add useful information to the vote
            temp +="\n";
            OPL_vote.push_back(temp);
        } else {
            index = temp.find(']');
            temp = temp.substr(0,index+1);
            temp += "\n";
            candidate.push_back(temp);
        }
    }
    in.close();
}

string OPL::get_type_of_election() {
    return "OPL";
}
int OPL::get_number_of_seat() {
    return number_of_seat;
}
int OPL::get_number_of_ballot() {
    return number_of_ballot;
}

vector<string> OPL::get_candidate() {
    return candidate;
}

int OPL::get_number_of_candidate() {
    return number_of_candidate;
}

vector<string> OPL::get_OPL_vote() {
    return OPL_vote;
}
void OPL::generate_audit_file(string filename) {
    ofstream out;
    out.open(filename);
    out<<"The type of election is OPL";
    out<<"\n";
    out<<"number of seat is: "<<number_of_seat;
    out<<"\n";
    out<<"number of ballot is: "<<number_of_ballot;
    out<<"\n";
    out<<"number of candidate is: "<<number_of_candidate;
    out<<"\n";
    out<<"The candidates are listed as following\n";
    for (std::vector<string>::iterator it = candidate.begin() ; it != candidate.end(); ++it) {
        out<<(*it);
    }
    for (std::vector<string>::iterator it = OPL_vote.begin() ; it != OPL_vote.end(); ++it) {
        int index = (*it).find('1');
        out<<"The following vote is voted to "<<candidate[index];
        out<<(*it);
    }
    out.close();
}
