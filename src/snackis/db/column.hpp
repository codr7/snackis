#ifndef SNACKIS_DB_COLUMN_HPP
#define SNACKIS_DB_COLUMN_HPP

#include <cstdint>
#include <string>

namespace snackis::db {
  using namespace std;

  struct Table;
  
  struct Column {
    const uint8_t pos;
    const string name;
    
    Column(Table &table, string name);
  };
}

#endif
