//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// strtok.cpp
//
// Code generation for function 'strtok'
//

// Include files
#include "strtok.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
void b_strtok(const char x[200], ::coder::array<char, 2U> &token)
{
  int i;
  int itoken;
  int k;
  k = 1;
  while ((k <= 200) && (x[k - 1] == '\x00')) {
    k++;
  }
  itoken = k;
  while ((k <= 200) && (x[k - 1] != '\x00')) {
    k++;
  }
  if (itoken > k - 1) {
    i = 0;
    k = 0;
  } else {
    i = itoken - 1;
    k--;
  }
  itoken = k - i;
  token.set_size(1, itoken);
  for (k = 0; k < itoken; k++) {
    token[k] = x[i + k];
  }
}

} // namespace coder

// End of code generation (strtok.cpp)
