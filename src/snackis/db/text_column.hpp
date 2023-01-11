#ifndef SNACKIS_DB_TEXT_COLUMN_HPP
#define SNACKIS_DB_TEXT_COLUMN_HPP

#include <any>
#include <vector>
#include "snackis/db/column.hpp"

namespace snackis::db {
  using namespace std;
  
  struct TextColumn: Column {
    TextColumn(Table &table, string name);
    virtual string columnType() const override;
    string get(const vector<any> &source) const;
  };
}

#endif
