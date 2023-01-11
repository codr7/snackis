#include "snackis/db/table.hpp"

namespace snackis::db {
  using namespace std;

  template <typename RecordT>
  struct RecordTable: Table {
    RecordTable(Schema &schema, string name);
  };

  
  template <typename RecordT>
  RecordTable<RecordT>::RecordTable(Schema &schema, string name): Table(schema, name) {}
}
