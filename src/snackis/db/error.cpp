#include "snackis/db/error.hpp"

namespace snackis::db {
  Error::Error(string message): snackis::Error(move(message)) {
  }
}
