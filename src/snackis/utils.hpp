#include <sstream>
#include <string>

#ifndef SNACKIS_UTILS_HPP
#define SNACKIS_UTILS_HPP

namespace snackis {
  using namespace std;

  template <typename...Args>
  string format(Args &&...args) {
    stringstream buf;
    ((buf << forward<Args>(args)), ...);
    return buf.str();
  }

  string random(size_t len);
}

#endif
