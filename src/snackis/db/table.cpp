#include <sstream>
#include "snackis/db/table.hpp"

namespace snackis::db {
  Table::Table(string name): name(move(name)) {
  }

  optional<Error> Table::create(Context &context, bool force) {
    stringstream sql;
    sql << "CREATE TABLE " << name;
    if (!force) { sql << "IF NOT EXISTS "; }
    sql << '(';
    
    sql << ')';
    if (auto e = context.execute(sql.str()); e) { return Error("Failed creating table: ", e->message); }
    return nullopt;
  }
}
