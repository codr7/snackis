#ifndef SNACKIS_ERROR_HPP
#define SNACKIS_ERROR_HPP

#include <string>
#include "snackis/utils.hpp"

namespace snackis {
  using namespace std;
  
  struct Error {
    const string message;

    template <typename...Args>
    Error(Args &&...args): message(format(forward<Args>(args)...)) {}
  };
}

#endif
