#include "snackis/model/schema.hpp"

namespace snackis::model {
  Schema::Schema():
    options("options"),
    option_name(options, "option_name"),
    option_value(options, "option_value") {}
}
