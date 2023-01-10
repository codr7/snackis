#ifndef SNACKIS_DB_RECORD_HPP
#define SNACKIS_DB_RECORD_HPP

#include <any>
#include <optional>
#include <vector>
#include "snackis/db/table.hpp"

namespace snackis::db {
  using namespace std;

  struct Record {
    vector<any> values;
    optional<vector<any>> storedValues;

    Record(Table &table);
  };
}

#endif
