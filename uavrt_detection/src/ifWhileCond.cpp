//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// ifWhileCond.cpp
//
// Code generation for function 'ifWhileCond'
//

// Include files
#include "ifWhileCond.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
namespace internal {
bool b_ifWhileCond(const ::coder::array<bool, 2U> &x)
{
  bool y;
  y = ((x.size(0) != 0) && (x.size(1) != 0));
  if (y) {
    int b;
    int k;
    bool exitg1;
    b = x.size(0) * x.size(1);
    if (b > 2147483646) {
      check_forloop_overflow_error();
    }
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= b - 1)) {
      if (!x[k]) {
        y = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  return y;
}

bool ifWhileCond(const ::coder::array<bool, 1U> &x)
{
  bool y;
  y = (x.size(0) != 0);
  if (y) {
    int k;
    bool exitg1;
    if (x.size(0) > 2147483646) {
      check_forloop_overflow_error();
    }
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= x.size(0) - 1)) {
      if (!x[k]) {
        y = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  return y;
}

} // namespace internal
} // namespace coder

// End of code generation (ifWhileCond.cpp)
