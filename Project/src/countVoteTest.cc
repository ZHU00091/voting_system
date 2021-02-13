#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <ctime>
#include <string>

#include "cpl.h"
#include "countVote.h"

using namespace std;

int main(int argc, char **argv)
{
  ifstream in("../testing/CPL.CSV");
  string temp;
  getline(in,temp);
  CPL * cpl = new CPL(in);
  CountVote *count = new CountVote(cpl);
  // std::vector<string> candidate = cpl->get_candidate();
  // map<char,int> result = count->get_vote_count();
  cout << "The Party is: " << count -> get_vote_count().begin() -> first<<endl;
  cout << "The Vote is:" << count -> get_vote_count().begin() -> second;

}
