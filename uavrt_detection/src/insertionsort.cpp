//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// insertionsort.cpp
//
// Code generation for function 'insertionsort'
//

// Include files
#include "insertionsort.h"
#include "anonymous_function.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_internal_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
namespace internal {
void insertionsort(::coder::array<int, 1U> &x, int xstart, int xend,
                   const c_anonymous_function &cmp)
{
  int a;
  a = xstart + 1;
  if ((xstart + 1 <= xend) && (xend > 2147483646)) {
    check_forloop_overflow_error();
  }
  for (int k{a}; k <= xend; k++) {
    int idx;
    int xc;
    bool exitg1;
    xc = x[k - 1];
    idx = k - 1;
    exitg1 = false;
    while ((!exitg1) && (idx >= xstart)) {
      int i;
      i = x[idx - 1];
      if (cmp.workspace.x[xc - 1] < cmp.workspace.x[i - 1]) {
        x[idx] = i;
        idx--;
      } else {
        exitg1 = true;
      }
    }
    x[idx] = xc;
  }
}

void insertionsort(::coder::array<int, 1U> &x, int xstart, int xend,
                   const anonymous_function &cmp)
{
  int a;
  a = xstart + 1;
  if ((xstart + 1 <= xend) && (xend > 2147483646)) {
    check_forloop_overflow_error();
  }
  for (int k{a}; k <= xend; k++) {
    int idx;
    int xc;
    bool exitg1;
    xc = x[k - 1] - 1;
    idx = k - 2;
    exitg1 = false;
    while ((!exitg1) && (idx + 1 >= xstart)) {
      int i;
      bool varargout_1;
      i = cmp.workspace.a[x[idx] - 1];
      if (cmp.workspace.a[xc] < i) {
        varargout_1 = true;
      } else if (cmp.workspace.a[xc] == i) {
        varargout_1 = (cmp.workspace.b[xc] < cmp.workspace.b[x[idx] - 1]);
      } else {
        varargout_1 = false;
      }
      if (varargout_1) {
        x[idx + 1] = x[idx];
        idx--;
      } else {
        exitg1 = true;
      }
    }
    x[idx + 1] = xc + 1;
  }
}

} // namespace internal
} // namespace coder

// End of code generation (insertionsort.cpp)
