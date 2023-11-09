//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// dec2bin.cpp
//
// Code generation for function 'dec2bin'
//

// Include files
#include "dec2bin.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"

// Function Definitions
namespace coder {
void decToBinScalar(unsigned char d, char s[8])
{
  int idx;
  int k;
  int nb;
  int npad;
  char sfull[8];
  bool exitg1;
  for (k = 0; k < 8; k++) {
    sfull[k] = '0';
    if ((d & 1 << (7 - k)) != 0) {
      sfull[k] = '1';
    }
  }
  idx = 0;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 8)) {
    if (sfull[k] == '1') {
      idx = k + 1;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (idx == 0) {
    idx = 8;
  }
  nb = 8 - idx;
  if (9 - idx < 8) {
    npad = idx;
    for (k = 0; k <= idx - 2; k++) {
      s[k] = '0';
    }
  } else {
    npad = 1;
  }
  for (k = 0; k <= nb; k++) {
    s[(npad + k) - 1] = sfull[(idx + k) - 1];
  }
}

} // namespace coder

// End of code generation (dec2bin.cpp)
