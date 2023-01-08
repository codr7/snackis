#include <string>

namespace snackis {
  using namespace std;
  
  struct Error {
    const string message;
    Error(string message);
  };
}
