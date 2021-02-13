#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <fstream>
#include "cpl.h"
using namespace std;

CPL::CPL(ifstream& in) {
  // reading file and store information
    string temp;
    getline(in,temp);
    int index = temp.find(',');
    temp = temp.substr(0,index);
    number_of_parties = stoi(temp);
    getline(in,temp);
    index = temp.find(']');
    temp = temp.substr(0,index+1);
    ballot_ordering = temp;
    getline(in,temp);
    index = temp.find(',');
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
            CPL_vote.push_back(temp);
        } else {
            index = temp.find(']');
            temp = temp.substr(0,index+1);
            temp += "\n";
            candidate.push_back(temp);
        }
    }
    in.close();
}

string CPL::get_type_of_election() {
    return "CPL";
}
int CPL::get_number_of_seat() {
    return number_of_seat;
}
int CPL::get_number_of_ballot() {
    return number_of_ballot;
}

vector<string> CPL::get_candidate() {
    return candidate;
}

int CPL::get_number_of_candidate() {
    return number_of_candidate;
}
int CPL::get_number_of_parties() {
    return number_of_parties;
}
vector<char> CPL::get_ballot_ordering() {
    std::vector<char> parties;
    for(int i=0; i<ballot_ordering.length(); i++) {  // only add usefule information
      // to the vector, ignore ',' and '[]'
      if (ballot_ordering[i] != '[' && ballot_ordering[i] != ',' &&
    ballot_ordering[i] != ']') {
      parties.push_back(ballot_ordering[i]);
      }
    }
    return parties;
}
vector<string> CPL::get_CPL_vote() {
    return CPL_vote;
}
void CPL::generate_audit_file(string filename) {
    ofstream out;
    out.open(filename);  // generate audit file
    out<<"Type of electon is: CPL";
    out<<"\n";
    out<<"number of party is: "<<number_of_parties;  // add annotate
    out<<"\n";
    out<<"The ballot ordering is: "<<ballot_ordering;
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
    for (std::vector<string>::iterator it = CPL_vote.begin() ; it != CPL_vote.end(); ++it) {
        int index = (*it).find('1');
        out<<"The following vote is voted to party: "<<ballot_ordering[2*index+1]<<"\n";
        out<<(*it);
        out<<"\n";
    }
    out.close();
}
