#include <iostream>
using namespace std;

bool accept() {
  cout << "Do you want to proceed? (y or n)\n";

  char answer = 0;
  cin >> answer;  // read answer

  if (answer == 'y') return true;
  return false;
}

bool accept2() {
  cout << "Do you want to proceed? (y or n)\n";

  char answer = 0;
  cin >> answer;

  switch (answer) {
    case 'y':
      return true;
    case 'n':
      return false;
    default:
      cout << "I'll take that for a no.\n";
      return false;
  }
}

bool accept3() {
  int tries = 1;
  while (tries < 4) {
    cout << "Do you want to proceed? (y or n)\n";

    char answer = 0;
    cin >> answer;

    switch (answer) {
      case 'y':
        return true;
      case 'n':
        return false;
      default:
        cout << "Sorry, I don't understand that.\n";
        ++tries;  // increment
    }
  }
  cout << "I'll take that for a no.\n";
  return false;
}

int main() {
  bool result;

  cout << ":: bool accept ::\n";
  result = accept();
  cout << result << "\n";

  cout << ":: bool accept2 ::\n";
  result = accept2();
  cout << result << "\n";

  cout << ":: bool accept3 ::\n";
  result = accept3();
  cout << result << "\n";
  return 0;
}
