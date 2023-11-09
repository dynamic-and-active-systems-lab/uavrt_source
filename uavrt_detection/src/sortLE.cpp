//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// sortLE.cpp
//
// Code generation for function 'sortLE'
//

// Include files
#include "sortLE.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace coder {
namespace internal {
bool sortLE(const ::coder::array<double, 2U> &v,
            const ::coder::array<int, 2U> &dir, int idx1, int idx2)
{
  int k;
  bool exitg1;
  bool p;
  p = true;
  if (dir.size(1) > 2147483646) {
    check_forloop_overflow_error();
  }
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= dir.size(1) - 1)) {
    double v1;
    double v2;
    int abscolk;
    if (dir[k] < 0) {
      abscolk = -dir[k];
    } else {
      abscolk = dir[k];
    }
    v1 = v[(idx1 + v.size(0) * (abscolk - 1)) - 1];
    v2 = v[(idx2 + v.size(0) * (abscolk - 1)) - 1];
    if (v1 == v2) {
      k++;
    } else {
      bool b;
      b = std::isnan(v1);
      if (b && std::isnan(v2)) {
        k++;
      } else {
        if (dir[k] < 0) {
          if ((!(v1 >= v2)) && (!b)) {
            p = false;
          }
        } else if ((!(v1 <= v2)) && (!std::isnan(v2))) {
          p = false;
        }
        exitg1 = true;
      }
    }
  }
  return p;
}

} // namespace internal
} // namespace coder

// End of code generation (sortLE.cpp)
