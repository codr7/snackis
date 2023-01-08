#include "snackis/error.hpp"

namespace snackis {
  Error::Error(string message): message(move(message)) {
  }
}
