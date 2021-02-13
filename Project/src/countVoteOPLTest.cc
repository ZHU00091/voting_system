#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <ctime>
#include <string>

#include "opl.h"
#include "countVoteOPL.h"

using namespace std;

int main(int argc, char **argv)
{
  ifstream in("../testing/OPL.CSV");
  string temp;
  getline(in,temp);
  OPL * opl = new OPL(in);
  CountVoteOPL *count = new CountVoteOPL(opl);
  // std::vector<string> candidate = cpl->get_candidate();
  // map<char,int> result = count->get_vote_count();
  cout << "The Party is: " << count -> get_vote_count().begin() -> first;
  cout << "The Vote is:" << count -> get_vote_count().begin() -> second;

}
