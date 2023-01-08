#include <optional>
#include <string>
#include "snackis/db/context.hpp"

namespace snackis::db {
  using namespace std;
  
  struct Table {
    string name;

    Table(string name);
    optional<Error> create(Context &context, bool force);
  };
}
