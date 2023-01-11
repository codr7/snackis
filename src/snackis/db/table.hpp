#ifndef SNACKIS_DB_TABLE_HPP
#define SNACKIS_DB_TABLE_HPP

#include <optional>
#include <string>
#include <vector>

#include "snackis/db/context.hpp"

namespace snackis::db {
  using namespace std;

  struct Column;
  struct Schema;
  
  struct Table {
    const string name;
    vector<Column *> columns;
    
    Table(Schema &schema, string name);
    optional<Error> create(Context &context, bool force);
    optional<Error> drop(Context &context, bool force);
    optional<Error> sync(Context &context);
  };
}

#endif
