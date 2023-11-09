//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// xdotc.cpp
//
// Code generation for function 'xdotc'
//

// Include files
#include "xdotc.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
namespace internal {
namespace blas {
creal_T xdotc(int n, const ::coder::array<creal_T, 2U> &x, int ix0,
              const ::coder::array<creal_T, 2U> &y, int iy0)
{
  creal_T d;
  d.re = 0.0;
  d.im = 0.0;
  if (n >= 1) {
    if (n > 2147483646) {
      check_forloop_overflow_error();
    }
    for (int k{0}; k < n; k++) {
      double b_im;
      double b_re;
      double im;
      double re;
      int re_tmp;
      re_tmp = (ix0 + k) - 1;
      re = x[re_tmp].re;
      im = x[re_tmp].im;
      re_tmp = (iy0 + k) - 1;
      b_re = y[re_tmp].re;
      b_im = y[re_tmp].im;
      d.re += re * b_re + im * b_im;
      d.im += re * b_im - im * b_re;
    }
  }
  return d;
}

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (xdotc.cpp)
