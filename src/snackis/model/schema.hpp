#ifndef SNACKIS_MODEL_SCHEMA_HPP
#define SNACKIS_MODEL_SCHEMA_HPP

#include "snackis/db/record_table.hpp"
#include "snackis/db/text_column.hpp"
#include "snackis/model/option.hpp"

namespace snackis::model {
  struct Schema {
    db::RecordTable<Option> options;
    db::TextColumn option_name;
    db::TextColumn option_value;
    
    Schema();
  };
}

#endif
