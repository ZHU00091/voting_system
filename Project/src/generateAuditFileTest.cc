#include "../src/generateAuditFile.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
if (argc <= 1) {
  cout<<"the second argument should be filename\n";
  return 0;
  }
  ifstream in(argv[1]);
    if (!in) {
        cout<<"cannot open the file \n";
        return 0;
  }
  GenerateAuditFile * g = new GenerateAuditFile(in);
  string type = g->get_type_of_election();
  cout<<type<<endl;
}
