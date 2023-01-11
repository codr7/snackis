#include <sstream>
#include "snackis/db/column.hpp"
#include "snackis/db/schema.hpp"
#include "snackis/db/table.hpp"

namespace snackis::db {
  Table::Table(Schema &schema, string name): name(move(name)) {
    schema.tables.push_back(this);
  }

  optional<Error> Table::create(Context &context, bool force) {
    stringstream sql;
    sql << "CREATE TABLE ";
    if (!force) { sql << "IF NOT EXISTS "; }
    sql << name;
    sql << '(';
    int i = 0;
    
    for (Column *const c: columns) {
      if (i++) { sql << ", "; }
      sql << c->name;
    }
    
    sql << ')';
    if (auto e = context.execute(sql.str()); e) { return Error("Failed creating table: ", e->message); }
    return nullopt;
  }

  optional<Error> Table::drop(Context &context, bool force) {
    stringstream sql;
    sql << "DROP TABLE ";
    if (!force) { sql << "IF EXISTS "; }
    sql << name;
    if (auto e = context.execute(sql.str()); e) { return Error("Failed creating table: ", e->message); }
    return nullopt;
  }

  optional<Error> Table::sync(Context &context) {
    if (auto e = create(context, true); e) {
      for (Column *const c: columns) {
	if (auto e = c->create(context, false)) { return e; }
      }
    }

    return nullopt;
  }
}
