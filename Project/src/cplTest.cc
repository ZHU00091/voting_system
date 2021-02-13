#include "cpl.h"
using namespace std;


int main(int argc, char *argv[]) {
  ifstream in;
  in.open("../testing/CPL.CSV");
  if (!in) {
      cout<<"cannot open the file \n";
      return 0;
    }
  string temp;
  getline(in, temp);
  CPL * cpl = new CPL(in);
  string type = cpl->get_type_of_election();
  int num = cpl->get_number_of_parties();
  int set = cpl->get_number_of_seat();
  int num_can = cpl->get_number_of_candidate();
  int ballot = cpl->get_number_of_ballot();

  vector<string> candidates = cpl->get_candidate();
  vector<char> parties = cpl->get_ballot_ordering();
  std::vector<string> vote = cpl->get_CPL_vote();
/******************display result*****************************/
  cout<<"The type of election is: "<<type<<endl;
  cout<<"The numer of parties is: "<<num<<endl;
  cout<<"The numer of sets is: "<<set<<endl;
  cout<<"The numer of ballots is: "<<ballot<<endl;
  cout<<"The numer of candidates is: "<<num_can<<endl;
  cout<<"The first candidate is: "<<candidates[0];
  cout<<"The first party is: "<<parties[0]<<endl;
  cout<<"The first vote is: "<<vote[0]<<endl;
}
