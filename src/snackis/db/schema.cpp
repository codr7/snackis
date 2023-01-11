#include "snackis/db/schema.hpp"
#include "snackis/db/table.hpp"

namespace snackis::db {
  optional<Error> Schema::create(Context &context, bool force) {
    for (Table *t: tables) {
      if (auto e = t->create(context, force); e) { return e; }
    }

    return nullopt;
  }
  
  optional<Error> Schema::drop(Context &context, bool force) {
    for (Table *t: tables) {
      if (auto e = t->drop(context, force); e) { return e; }
    }

    return nullopt;
  }
  
  optional<Error> Schema::sync(Context &context) {
    for (Table *t: tables) {
      if (auto e = t->sync(context); e) { return e; }
    }

    return nullopt;
  }
}
