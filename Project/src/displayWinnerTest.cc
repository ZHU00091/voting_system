#include "displayWinner.h"
using namespace std;

int main() {
  map<string,int> temp;
  temp.insert(pair<string,int>("Jhon",3));
  temp.insert(pair<string,int>("Parker",10));
  temp.insert(pair<string,int>("James",5));
  DisplayWinner * d = new DisplayWinner(temp);
  string s = d->display();
  cout<< s;
  cout<<"The random num is: "<<d->tie_handler()<<endl;
}
