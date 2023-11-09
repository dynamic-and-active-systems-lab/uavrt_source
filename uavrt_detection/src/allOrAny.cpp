//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// allOrAny.cpp
//
// Code generation for function 'allOrAny'
//

// Include files
#include "allOrAny.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
namespace internal {
bool allOrAny_anonFcn1(const ::coder::array<bool, 1U> &x)
{
  int ix;
  bool exitg1;
  bool varargout_1;
  varargout_1 = false;
  if (x.size(0) > 2147483646) {
    check_forloop_overflow_error();
  }
  ix = 1;
  exitg1 = false;
  while ((!exitg1) && (ix <= x.size(0))) {
    if (x[ix - 1]) {
      varargout_1 = true;
      exitg1 = true;
    } else {
      ix++;
    }
  }
  return varargout_1;
}

} // namespace internal
} // namespace coder

// End of code generation (allOrAny.cpp)
