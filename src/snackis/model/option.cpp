#include "snackis/model/option.hpp"
#include "snackis/model/schema.hpp"

namespace snackis::model {
  Option::Option(Schema &schema): Record(schema.options), schema(schema) {}
  
  string Option::name() const {
    return schema.option_name.get(values);
  }
  
  string Option::value() const {
    return schema.option_value.get(values);
  }
}
