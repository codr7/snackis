#include "snackis/db/column.hpp"
#include "snackis/db/table.hpp"

namespace snackis::db {
  Column::Column(Table &table, string name): table(table), pos(table.columns.size()), name(name) {
    table.columns.push_back(this);
  }

  optional<Error> Column::create(Context &context, bool force) const {
    stringstream sql;
    sql << "ALTER TABLE " << table.name << " ADD COLUMN ";
    if (!force) { sql << "IF NOT EXISTS "; }
    sql << name << ' ' << columnType();
    if (auto e = context.execute(sql.str()); e) { return Error("Failed creating column: ", e->message); }
    return nullopt;

  }
  
  optional<Error> Column::drop(Context &context, bool force) const {
    stringstream sql;
    sql << "ALTER TABLE " << table.name << " DROP COLUMN ";
    if (!force) { sql << "IF EXISTS "; }
    sql << name;
    if (auto e = context.execute(sql.str()); e) { return Error("Failed creating column: ", e->message); }
    return nullopt;
  }
}
