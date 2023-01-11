#include "snackis/db/text_column.hpp"

namespace snackis::db {
  TextColumn::TextColumn(Table &table, string name): Column(table, move(name)) {}

  string TextColumn::columnType() const { return "TEXT"; }

  string TextColumn::get(const vector<any> &source) const {
    return any_cast<string>(source[pos]);
  }
}
