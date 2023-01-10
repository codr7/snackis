#include <filesystem>
#include <iostream>
#include "snackis/lib.hpp"
#include "snackis/model/schema.hpp"
#include "snackis/key.hpp"
#include "snackis/utils.hpp"

using namespace std;
namespace fs = std::filesystem;
namespace db = snackis::db;
namespace model = snackis::model;

int main() {
  cout << "Snackis v" << snackis::VERSION << endl << endl;

  cout << "Random:" << endl << snackis::random(256) << endl << endl;
  
  snackis::Key k;
  cout << "Public Key:" << endl << k.public_hex() << endl;
  cout << "Private:" << endl << k.private_hex() << endl;

  const string DB_PATH = "db";
  
  db::Context c;
  if (auto e = c.open(DB_PATH); e) { cout << "Failed opening database: " << e->message << endl; }
  model::Schema schema;

  if (fs::exists(DB_PATH)) {
    // Existing database
  } else {
    // New database
  }

  return 0;
}
