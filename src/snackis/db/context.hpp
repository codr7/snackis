#ifndef SNACKIS_DB_CONTEXT_HPP
#define SNACKIS_DB_CONTEXT_HPP

#include <optional>
#include <sqlite3.h>
#include "snackis/db/error.hpp"

namespace snackis::db {
  using namespace std;
  
  struct Context {
    sqlite3 *db;

    Context();
    optional<Error> open(string path);
    optional<Error> execute(string sql) const;
  };
}

#endif
