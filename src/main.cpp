#include <iostream>
#include "snackis/db/table.hpp"
#include "snackis/lib.hpp"
#include "snackis/key.hpp"
#include "snackis/utils.hpp"

using namespace std;
namespace db = snackis::db;

int main() {
  cout << "Snackis v" << snackis::VERSION << endl << endl;

  cout << "Random:" << endl << snackis::random(256) << endl << endl;
  
  snackis::Key k;
  cout << "Public Key:" << endl << k.public_hex() << endl;
  cout << "Private:" << endl << k.private_hex() << endl;

  db::Context c;
  if (auto e = c.open("db"); e) { cout << "Failed opening database: " << e->message << endl; }
  db::Table t("peers");
  if (auto e = t.create(c, true); e) { cout << "Failed creating table: " << e->message << endl; }
  return 0;
}
