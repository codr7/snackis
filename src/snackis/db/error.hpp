#include "snackis/error.hpp"

namespace snackis::db {
  using namespace std;
  
  struct Error: snackis::Error {
    Error(string message);
  };
}
