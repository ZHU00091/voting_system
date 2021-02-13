#include "displayWinnerCPL.h"
using namespace std;

int main() {
  map<char,int> temp;
  temp.insert(pair<char,int>('A',3));
  temp.insert(pair<char,int>('B',10));
  temp.insert(pair<char,int>('C',5));
  std::vector<string> can;
  can.push_back("[John,A,1]");
  can.push_back("[Parker,B,1]");
  DisplayWinnerCPL * d = new DisplayWinnerCPL(temp,can);
  int res = d->display();
  cout<<"\n The index of winner is: "<<res;
  cout<<"\nThe random num is: "<<d->tie_handler()<<endl;
}
