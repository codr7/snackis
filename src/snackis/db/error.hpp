#include "snackis/error.hpp"

namespace snackis::db {
  using namespace std;
  
  struct Error: snackis::Error {
    template <typename...Args>
    Error(Args &&...args): snackis::Error(forward<Args>(args)...) {}
  };
}
