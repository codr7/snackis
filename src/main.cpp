#include <iostream>
#include "snackis/key.hpp"

using namespace std;

int main() {
  snackis::Key k;
  cout << "Public: " << endl << k.public_hex() << endl;
  cout << "Private: " << endl << k.private_hex() << endl;
  return 0;
}
