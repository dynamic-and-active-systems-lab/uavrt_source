//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// norm.cpp
//
// Code generation for function 'norm'
//

// Include files
#include "norm.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_rtwutil.h"
#include "xzsvdc.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace coder {
double b_norm(const ::coder::array<creal_T, 2U> &x)
{
  array<creal_T, 2U> b_x;
  array<double, 1U> s;
  double y;
  bool MATRIX_INPUT_AND_P_IS_TWO;
  bool VECTOR_INPUT_AND_P_IS_NUMERIC;
  VECTOR_INPUT_AND_P_IS_NUMERIC = false;
  MATRIX_INPUT_AND_P_IS_TWO = false;
  if ((x.size(0) == 1) || (x.size(1) == 1)) {
    VECTOR_INPUT_AND_P_IS_NUMERIC = true;
  } else {
    MATRIX_INPUT_AND_P_IS_TWO = true;
  }
  if ((x.size(0) == 0) || (x.size(1) == 0)) {
    y = 0.0;
  } else if (MATRIX_INPUT_AND_P_IS_TWO) {
    int m;
    int n;
    m = x.size(0);
    n = x.size(1);
    y = 0.0;
    if (x.size(1) > 2147483646) {
      check_forloop_overflow_error();
    }
    VECTOR_INPUT_AND_P_IS_NUMERIC = (x.size(0) > 2147483646);
    for (int j{0}; j < n; j++) {
      if (VECTOR_INPUT_AND_P_IS_NUMERIC) {
        check_forloop_overflow_error();
      }
      for (int i{0}; i < m; i++) {
        double scale;
        scale = rt_hypotd_snf(x[i + x.size(0) * j].re, x[i + x.size(0) * j].im);
        if (std::isnan(scale) || (scale > y)) {
          y = scale;
        }
      }
    }
    if ((!std::isinf(y)) && (!std::isnan(y))) {
      b_x.set_size(x.size(0), x.size(1));
      m = x.size(0) * x.size(1) - 1;
      for (n = 0; n <= m; n++) {
        b_x[n] = x[n];
      }
      internal::reflapack::xzsvdc(b_x, s);
      y = s[0];
    }
  } else if (VECTOR_INPUT_AND_P_IS_NUMERIC) {
    int n;
    n = x.size(0) * x.size(1);
    y = 0.0;
    if (n >= 1) {
      if (n == 1) {
        y = rt_hypotd_snf(x[0].re, x[0].im);
      } else {
        double scale;
        scale = 3.3121686421112381E-170;
        if (n > 2147483646) {
          check_forloop_overflow_error();
        }
        for (int m{0}; m < n; m++) {
          double absxk;
          double t;
          absxk = std::abs(x[m].re);
          if (absxk > scale) {
            t = scale / absxk;
            y = y * t * t + 1.0;
            scale = absxk;
          } else {
            t = absxk / scale;
            y += t * t;
          }
          absxk = std::abs(x[m].im);
          if (absxk > scale) {
            t = scale / absxk;
            y = y * t * t + 1.0;
            scale = absxk;
          } else {
            t = absxk / scale;
            y += t * t;
          }
        }
        y = scale * std::sqrt(y);
      }
    }
  } else {
    y = rtNaN;
  }
  return y;
}

} // namespace coder

// End of code generation (norm.cpp)
