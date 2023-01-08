#include "snackis/key.hpp"

namespace snackis {
  Key::Key() {
    crypto_box_keypair(public_bin, private_bin);
  }

  string Key::public_hex() {
    static const size_t LEN = PUBLIC_LEN*2 + 1;
    char hex[LEN];
    sodium_bin2hex(hex, LEN, public_bin, PUBLIC_LEN);
    return hex;
  }
  
  string Key::private_hex() {
    static const size_t LEN = PRIVATE_LEN*2 + 1;
    char hex[LEN];
    sodium_bin2hex(hex, LEN, private_bin, PRIVATE_LEN);
    return hex;
  }
}
