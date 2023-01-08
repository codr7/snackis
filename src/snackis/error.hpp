#include <string>

namespace snackis {
  using namespace std;
  
  struct Error {
    string message;
    Error(string message);
  };
}
