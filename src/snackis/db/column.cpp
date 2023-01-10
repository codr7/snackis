#include "snackis/db/column.hpp"
#include "snackis/db/table.hpp"

namespace snackis::db {
  Column::Column(Table &table, string name): pos(table.columns.size()), name(name) {
    table.columns.push_back(this);
  }
}
