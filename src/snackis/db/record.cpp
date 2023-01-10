#include "snackis/db/record.hpp"

namespace snackis::db {
  Record::Record(Table &table) {
    values.reserve(table.columns.size());
  }
}
