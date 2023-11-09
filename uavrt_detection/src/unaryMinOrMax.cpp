//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// unaryMinOrMax.cpp
//
// Code generation for function 'unaryMinOrMax'
//

// Include files
#include "unaryMinOrMax.h"
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
double b_unaryMinOrMax_anonFcn1(const ::coder::array<double, 1U> &x)
{
  double varargout_1;
  int last;
  if (x.size(0) < 1) {
    lb_rtErrorWithMessageID(bc_emlrtRTEI.fName, bc_emlrtRTEI.lineNo);
  }
  last = x.size(0);
  if (x.size(0) <= 2) {
    if (x.size(0) == 1) {
      varargout_1 = x[0];
    } else if ((x[0] > x[1]) || (std::isnan(x[0]) && (!std::isnan(x[1])))) {
      varargout_1 = x[1];
    } else {
      varargout_1 = x[0];
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
      varargout_1 = x[0];
    } else {
      int a;
      varargout_1 = x[idx - 1];
      a = idx + 1;
      if ((idx + 1 <= x.size(0)) && (x.size(0) > 2147483646)) {
        check_forloop_overflow_error();
      }
      for (k = a; k <= last; k++) {
        double d;
        d = x[k - 1];
        if (varargout_1 > d) {
          varargout_1 = d;
        }
      }
    }
  }
  return varargout_1;
}

double unaryMinOrMax_anonFcn1(const ::coder::array<double, 1U> &x)
{
  double varargout_1;
  int last;
  if (x.size(0) < 1) {
    lb_rtErrorWithMessageID(bc_emlrtRTEI.fName, bc_emlrtRTEI.lineNo);
  }
  last = x.size(0);
  if (x.size(0) <= 2) {
    if (x.size(0) == 1) {
      varargout_1 = x[0];
    } else if ((x[0] < x[1]) || (std::isnan(x[0]) && (!std::isnan(x[1])))) {
      varargout_1 = x[1];
    } else {
      varargout_1 = x[0];
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
      varargout_1 = x[0];
    } else {
      int a;
      varargout_1 = x[idx - 1];
      a = idx + 1;
      if ((idx + 1 <= x.size(0)) && (x.size(0) > 2147483646)) {
        check_forloop_overflow_error();
      }
      for (k = a; k <= last; k++) {
        double d;
        d = x[k - 1];
        if (varargout_1 < d) {
          varargout_1 = d;
        }
      }
    }
  }
  return varargout_1;
}

} // namespace internal
} // namespace coder

// End of code generation (unaryMinOrMax.cpp)
