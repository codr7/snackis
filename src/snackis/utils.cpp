#include <vector>
#include <sodium.h>
#include "snackis/utils.hpp"

namespace snackis {
  string random(size_t len) {
    vector<unsigned char> bin;
    bin.reserve(len);
    randombytes_buf(bin.data(), len);
    const size_t HEX_LEN = len*2 + 1;
    vector<char> hex;
    hex.reserve(HEX_LEN);
    sodium_bin2hex(hex.data(), HEX_LEN, bin.data(), len);
    return hex.data();
  }
}
