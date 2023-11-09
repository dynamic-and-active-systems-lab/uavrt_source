//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// abs.cpp
//
// Code generation for function 'abs'
//

// Include files
#include "abs.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_rtwutil.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
void b_abs(const ::coder::array<creal_T, 2U> &x, ::coder::array<double, 2U> &y)
{
  int nx;
  nx = x.size(0) * x.size(1);
  y.set_size(x.size(0), x.size(1));
  if (nx > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int k{0}; k < nx; k++) {
    y[k] = rt_hypotd_snf(x[k].re, x[k].im);
  }
}

} // namespace coder

// End of code generation (abs.cpp)
