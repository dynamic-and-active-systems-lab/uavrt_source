//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// xaxpy.cpp
//
// Code generation for function 'xaxpy'
//

// Include files
#include "xaxpy.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
namespace internal {
namespace blas {
void xaxpy(int n, const creal_T a, int ix0, ::coder::array<creal_T, 2U> &y,
           int iy0)
{
  if ((n >= 1) && ((!(a.re == 0.0)) || (!(a.im == 0.0)))) {
    int i;
    i = n - 1;
    for (int k{0}; k <= i; k++) {
      double a_re_tmp;
      double b_a_re_tmp;
      int a_re_tmp_tmp;
      a_re_tmp_tmp = (ix0 + k) - 1;
      a_re_tmp = y[a_re_tmp_tmp].im;
      b_a_re_tmp = y[a_re_tmp_tmp].re;
      a_re_tmp_tmp = (iy0 + k) - 1;
      y[a_re_tmp_tmp].re =
          y[a_re_tmp_tmp].re + (a.re * b_a_re_tmp - a.im * a_re_tmp);
      y[a_re_tmp_tmp].im =
          y[a_re_tmp_tmp].im + (a.re * a_re_tmp + a.im * b_a_re_tmp);
    }
  }
}

void xaxpy(int n, const creal_T a, const ::coder::array<creal_T, 2U> &x,
           int ix0, ::coder::array<creal_T, 1U> &y, int iy0)
{
  if ((n >= 1) && ((!(a.re == 0.0)) || (!(a.im == 0.0)))) {
    int i;
    i = n - 1;
    for (int k{0}; k <= i; k++) {
      double a_re_tmp;
      double b_a_re_tmp;
      int a_re_tmp_tmp;
      a_re_tmp_tmp = (ix0 + k) - 1;
      a_re_tmp = x[a_re_tmp_tmp].im;
      b_a_re_tmp = x[a_re_tmp_tmp].re;
      a_re_tmp_tmp = (iy0 + k) - 1;
      y[a_re_tmp_tmp].re =
          y[a_re_tmp_tmp].re + (a.re * b_a_re_tmp - a.im * a_re_tmp);
      y[a_re_tmp_tmp].im =
          y[a_re_tmp_tmp].im + (a.re * a_re_tmp + a.im * b_a_re_tmp);
    }
  }
}

void xaxpy(int n, const creal_T a, const ::coder::array<creal_T, 1U> &x,
           int ix0, ::coder::array<creal_T, 2U> &y, int iy0)
{
  if ((n >= 1) && ((!(a.re == 0.0)) || (!(a.im == 0.0)))) {
    int i;
    i = n - 1;
    for (int k{0}; k <= i; k++) {
      double a_re_tmp;
      double b_a_re_tmp;
      int a_re_tmp_tmp;
      a_re_tmp_tmp = (ix0 + k) - 1;
      a_re_tmp = x[a_re_tmp_tmp].im;
      b_a_re_tmp = x[a_re_tmp_tmp].re;
      a_re_tmp_tmp = (iy0 + k) - 1;
      y[a_re_tmp_tmp].re =
          y[a_re_tmp_tmp].re + (a.re * b_a_re_tmp - a.im * a_re_tmp);
      y[a_re_tmp_tmp].im =
          y[a_re_tmp_tmp].im + (a.re * a_re_tmp + a.im * b_a_re_tmp);
    }
  }
}

} // namespace blas
} // namespace internal
} // namespace coder

// End of code generation (xaxpy.cpp)
