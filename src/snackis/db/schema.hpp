#ifndef SNACKIS_DB_SCHEMA_HPP
#define SNACKIS_DB_SCHEMA_HPP

#include <optional>
#include <vector>
#include "snackis/db/error.hpp"

namespace snackis::db {
  struct Context;
  struct Table;

  struct Schema {
    vector<Table *> tables;

    optional<Error> create(Context &context, bool force);
    optional<Error> drop(Context &context, bool force);
    optional<Error> sync(Context &context);
  };
}

#endif
