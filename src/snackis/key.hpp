#include <string>
#include <sodium.h>

namespace snackis {
  using namespace std;
  
  struct Key {
    static const size_t PUBLIC_LEN = crypto_box_PUBLICKEYBYTES;
    unsigned char public_bin[PUBLIC_LEN];

    static const size_t PRIVATE_LEN = crypto_box_SECRETKEYBYTES;
    unsigned char private_bin[PRIVATE_LEN];

    Key();
    string public_hex() const;
    string private_hex() const;
  };
}
