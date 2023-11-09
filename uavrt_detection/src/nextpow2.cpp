//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// nextpow2.cpp
//
// Code generation for function 'nextpow2'
//

// Include files
#include "nextpow2.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"

// Function Definitions
namespace coder {
int nextpow2(int n)
{
  int b_n;
  int p;
  int pmax;
  b_n = n;
  pmax = 31;
  if (n > MIN_int32_T) {
    if (n < 0) {
      b_n = -n;
    }
    if (b_n <= 1) {
      pmax = 0;
    } else {
      int pmin;
      bool exitg1;
      pmin = 0;
      exitg1 = false;
      while ((!exitg1) && (pmax - pmin > 1)) {
        int pow2p;
        p = (pmin + pmax) >> 1;
        pow2p = 1 << p;
        if (pow2p == b_n) {
          pmax = p;
          exitg1 = true;
        } else if (pow2p > b_n) {
          pmax = p;
        } else {
          pmin = p;
        }
      }
    }
  }
  return pmax;
}

} // namespace coder

// End of code generation (nextpow2.cpp)
