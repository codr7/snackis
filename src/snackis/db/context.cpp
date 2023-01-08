#include "snackis/db/context.hpp"

namespace snackis::db {
  Context::Context(): db(nullptr) {
  }

  optional<Error> Context::open(string path) {
    if (sqlite3_open(path.c_str(), &db)) {
      return Error(sqlite3_errmsg(db));
    }

    return nullopt;
  }
  
  optional<Error> Context::execute(string sql) const {
    if (!db) { return Error("Context isn't open"); }
    if (sqlite3_exec(db, sql.c_str(), nullptr, 0, nullptr)) { return Error(sqlite3_errmsg(db)); }
    return nullopt;
  }
}
