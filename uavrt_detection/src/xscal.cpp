//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// xscal.cpp
//
// Code generation for function 'xscal'
//

// Include files
#include "xscal.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
namespace internal {
namespace blas {
void xscal(int n, const creal_T a, ::coder::array<creal_T, 2U> &x, int ix0)
{
  int b;
  b = (ix0 + n) - 1;
  if ((ix0 <= b) && (b > 2147483646)) {
    check_forloop_overflow_error();
  }
  for (int k{ix0}; k <= b; k++) {
    double b_re_tmp;
    double re_tmp;
    re_tmp = x[k - 1].im;
    b_re_tmp = x[k - 1].re;
    x[k - 1].re = a.re * b_re_tmp - a.im * re_tmp;
    x[k - 1].im = a.re * re_tmp + a.im * b_re_tmp;
  }
}

void xscal(int n, const creal_T a, ::coder::array<creal_T, 1U> &x, int ix0)
{
  int b;
  b = (ix0 + n) - 1;
  if ((ix0 <= b) && (b > 2147483646)) {
    check_forloop_overflow_error();
  }
  for (int k{ix0}; k <= b; k++) {
    double b_re_tmp;
    double re_tmp;
    re_tmp = x[k - 1].im;
    b_re_tmp = x[k - 1].re;
    x[k - 1].re = a.re * b_re_tmp - a.im * re_tmp;
    x[k - 1].im = a.re * re_tmp + a.im * b_re_tmp;
  }
}

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (xscal.cpp)
