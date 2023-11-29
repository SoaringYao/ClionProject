#include "System.h"

int main() {
  system();
  while (true) {
    cout << "Do you want to continue? (y/n)" << endl;
    char c;
    cin >> c;
    if (c == 'n') {
      break;
    } else if (c == 'y') {
      system();
      continue;
    } else {
      cout << "Invalid input" << endl;
      continue;
    }
  }
  return 0;
}
