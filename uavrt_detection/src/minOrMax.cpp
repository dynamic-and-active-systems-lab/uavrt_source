//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// minOrMax.cpp
//
// Code generation for function 'minOrMax'
//

// Include files
#include "minOrMax.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace coder {
namespace internal {
void maximum(const ::coder::array<double, 2U> &x,
             ::coder::array<double, 1U> &ex, ::coder::array<int, 1U> &idx)
{
  int loop_ub;
  int m;
  int n;
  if (x.size(1) < 1) {
    lb_rtErrorWithMessageID(bc_emlrtRTEI.fName, bc_emlrtRTEI.lineNo);
  }
  m = x.size(0);
  n = x.size(1);
  ex.set_size(x.size(0));
  idx.set_size(x.size(0));
  loop_ub = x.size(0);
  for (int j{0}; j < loop_ub; j++) {
    idx[j] = 1;
  }
  if (x.size(0) >= 1) {
    if (x.size(0) > 2147483646) {
      check_forloop_overflow_error();
    }
    for (loop_ub = 0; loop_ub < m; loop_ub++) {
      ex[loop_ub] = x[loop_ub];
    }
    if (x.size(1) > 2147483646) {
      check_forloop_overflow_error();
    }
    for (int j{2}; j <= n; j++) {
      if (m > 2147483646) {
        check_forloop_overflow_error();
      }
      for (loop_ub = 0; loop_ub < m; loop_ub++) {
        double b;
        bool p;
        b = x[loop_ub + x.size(0) * (j - 1)];
        if (std::isnan(b)) {
          p = false;
        } else if (std::isnan(ex[loop_ub])) {
          p = true;
        } else {
          p = (ex[loop_ub] < b);
        }
        if (p) {
          ex[loop_ub] = b;
          idx[loop_ub] = j;
        }
      }
    }
  }
}

double maximum(const ::coder::array<double, 1U> &x, int &idx)
{
  double ex;
  int last;
  if (x.size(0) < 1) {
    lb_rtErrorWithMessageID(bc_emlrtRTEI.fName, bc_emlrtRTEI.lineNo);
  }
  last = x.size(0);
  if (x.size(0) <= 2) {
    if (x.size(0) == 1) {
      ex = x[0];
      idx = 1;
    } else if ((x[0] < x[1]) || (std::isnan(x[0]) && (!std::isnan(x[1])))) {
      ex = x[1];
      idx = 2;
    } else {
      ex = x[0];
      idx = 1;
    }
  } else {
    int k;
    if (!std::isnan(x[0])) {
      idx = 1;
    } else {
      bool exitg1;
      idx = 0;
      if (x.size(0) > 2147483646) {
        check_forloop_overflow_error();
      }
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!std::isnan(x[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = x[0];
      idx = 1;
    } else {
      int a;
      ex = x[idx - 1];
      a = idx + 1;
      if ((idx + 1 <= x.size(0)) && (x.size(0) > 2147483646)) {
        check_forloop_overflow_error();
      }
      for (k = a; k <= last; k++) {
        double d;
        d = x[k - 1];
        if (ex < d) {
          ex = d;
          idx = k;
        }
      }
    }
  }
  return ex;
}

double maximum(const double x[2])
{
  double ex;
  if ((x[0] < x[1]) || (std::isnan(x[0]) && (!std::isnan(x[1])))) {
    ex = x[1];
  } else {
    ex = x[0];
  }
  return ex;
}

double maximum(const ::coder::array<double, 1U> &x)
{
  double ex;
  int last;
  if (x.size(0) < 1) {
    lb_rtErrorWithMessageID(bc_emlrtRTEI.fName, bc_emlrtRTEI.lineNo);
  }
  last = x.size(0);
  if (x.size(0) <= 2) {
    if (x.size(0) == 1) {
      ex = x[0];
    } else if ((x[0] < x[1]) || (std::isnan(x[0]) && (!std::isnan(x[1])))) {
      ex = x[1];
    } else {
      ex = x[0];
    }
  } else {
    int idx;
    int k;
    if (!std::isnan(x[0])) {
      idx = 1;
    } else {
      bool exitg1;
      idx = 0;
      if (x.size(0) > 2147483646) {
        check_forloop_overflow_error();
      }
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!std::isnan(x[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = x[0];
    } else {
      int a;
      ex = x[idx - 1];
      a = idx + 1;
      if ((idx + 1 <= x.size(0)) && (x.size(0) > 2147483646)) {
        check_forloop_overflow_error();
      }
      for (k = a; k <= last; k++) {
        double d;
        d = x[k - 1];
        if (ex < d) {
          ex = d;
        }
      }
    }
  }
  return ex;
}

double minimum(const double x[2])
{
  double ex;
  if ((x[0] > x[1]) || (std::isnan(x[0]) && (!std::isnan(x[1])))) {
    ex = x[1];
  } else {
    ex = x[0];
  }
  return ex;
}

} // namespace internal
} // namespace coder

// End of code generation (minOrMax.cpp)
