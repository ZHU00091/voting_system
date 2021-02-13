#include "opl.h"
using namespace std;


int main(int argc, char *argv[]) {
  ifstream in;
  in.open("../testing/OPL.CSV");
  if (!in) {
      cout<<"cannot open the file \n";
      return 0;
    }
  string temp;
  getline(in, temp);
  OPL * opl = new OPL(in);
  string type = opl->get_type_of_election();
  int set = opl->get_number_of_seat();
  int num_can = opl->get_number_of_candidate();
  int ballot = opl->get_number_of_ballot();

  vector<string> candidates = opl->get_candidate();
  std::vector<string> vote = opl->get_OPL_vote();
/******************display result*****************************/
  cout<<"The type of election is: "<<type<<endl;
  cout<<"The numer of sets is: "<<set<<endl;
  cout<<"The numer of ballots is: "<<ballot<<endl;
  cout<<"The numer of candidates is: "<<num_can<<endl;
  cout<<"The first candidate is: "<<candidates[0];
  cout<<"The first vote is: "<<vote[0]<<endl;
}
