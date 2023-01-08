#include <iostream>
#include "snackis/lib.hpp"
#include "snackis/key.hpp"
#include "snackis/utils.hpp"

using namespace std;

int main() {
  cout << "Snackis v" << snackis::VERSION << endl << endl;

  cout << "Random:" << endl << snackis::random(256) << endl << endl;
  
  snackis::Key k;
  cout << "Public Key:" << endl << k.public_hex() << endl;
  cout << "Private:" << endl << k.private_hex() << endl;
  return 0;
}
