#include<iostream>
#include<string>
using namespace std;

string compose(string name, const string& domain) {
  cout << "subset(2,4) of name: " << name.substr(1, 4) << endl;
  // strings can be compared
  bool cmp = name == "secret";
  if (cmp)
    cout << "You found a secret!" << endl;
  // string is mutable
  name[0] = toupper(name[0]);
  name.replace(2, 4, "INTERCEPT!");
  return name + '@' + domain;  // addition means concatenation
}

int main(int argc, char *argv[]) {
  if (argc == 3) {
    cout << compose(argv[1], argv[2]) << endl;
  }
  else
    cout << "Please input two strings for name and domain." << endl;
  return 0;
}
