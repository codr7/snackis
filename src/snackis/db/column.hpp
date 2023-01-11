#ifndef SNACKIS_DB_COLUMN_HPP
#define SNACKIS_DB_COLUMN_HPP

#include <cstdint>
#include <optional>
#include <string>
#include "snackis/db/error.hpp"

namespace snackis::db {
  using namespace std;

  struct Context;
  struct Table;
  
  struct Column {
    Table &table;
    const uint8_t pos;
    const string name;
    
    Column(Table &table, string name);
    virtual string columnType() const = 0;
    optional<Error> create(Context &context, bool force) const;
    optional<Error> drop(Context &context, bool force) const;
    
  };
}

#endif
