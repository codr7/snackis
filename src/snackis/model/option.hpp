#ifndef SNACKIS_MODEL_OPTION_HPP
#define SNACKIS_MODEL_OPTION_HPP

#include "snackis/db/record.hpp"

namespace snackis::model {
  struct Schema;
  
  struct Option: db::Record {
    Schema &schema;
    
    Option(Schema &schema);
    string name() const;
    string value() const;
  };
}

#endif
