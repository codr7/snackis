#include "snackis/db/table.hpp"

namespace snackis::db {
  using namespace std;

  template <typename RecordT>
  struct RecordTable: Table {
    RecordTable(string name);
  };

  
  template <typename RecordT>
  RecordTable<RecordT>::RecordTable(string name): Table(name) {}
}
