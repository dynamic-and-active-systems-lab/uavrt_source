//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// diff.cpp
//
// Code generation for function 'diff'
//

// Include files
#include "diff.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"

// Variable Definitions
static rtRunTimeErrorInfo tb_emlrtRTEI{
    51,     // lineNo
    19,     // colNo
    "diff", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/datafun/diff.m" // pName
};

// Function Definitions
namespace coder {
void diff(const ::coder::array<double, 1U> &x, ::coder::array<double, 1U> &y)
{
  array<double, 1U> work;
  int dimSize;
  dimSize = x.size(0);
  if (x.size(0) == 0) {
    y.set_size(0);
  } else {
    int u0;
    u0 = x.size(0) - 1;
    if (u0 > 1) {
      u0 = 1;
    }
    if (u0 < 1) {
      y.set_size(0);
    } else {
      if (x.size(0) == 1) {
        v_rtErrorWithMessageID(tb_emlrtRTEI.fName, tb_emlrtRTEI.lineNo);
      }
      work.set_size(1);
      y.set_size(x.size(0) - 1);
      work[0] = x[0];
      if (x.size(0) > 2147483646) {
        check_forloop_overflow_error();
      }
      for (u0 = 2; u0 <= dimSize; u0++) {
        double tmp2;
        double work_tmp;
        tmp2 = work[0];
        work_tmp = x[u0 - 1];
        work[0] = work_tmp;
        y[u0 - 2] = work_tmp - tmp2;
      }
    }
  }
}

void diff(const ::coder::array<double, 2U> &x, ::coder::array<double, 2U> &y)
{
  array<double, 1U> work;
  int dimSize;
  dimSize = x.size(0);
  if (x.size(0) == 0) {
    y.set_size(0, x.size(1));
  } else {
    int nHigh;
    nHigh = x.size(0) - 1;
    if (nHigh > 1) {
      nHigh = 1;
    }
    if (nHigh < 1) {
      y.set_size(0, x.size(1));
    } else {
      if (x.size(0) == 1) {
        v_rtErrorWithMessageID(tb_emlrtRTEI.fName, tb_emlrtRTEI.lineNo);
      }
      work.set_size(1);
      y.set_size(x.size(0) - 1, x.size(1));
      if (x.size(1) != 0) {
        int iyStart;
        nHigh = x.size(1);
        iyStart = 0;
        if (x.size(1) > 2147483646) {
          check_forloop_overflow_error();
        }
        for (int r{0}; r < nHigh; r++) {
          int ixLead_tmp;
          ixLead_tmp = r * dimSize;
          work[0] = x[ixLead_tmp];
          if (dimSize > 2147483646) {
            check_forloop_overflow_error();
          }
          for (int m{2}; m <= dimSize; m++) {
            double d;
            double tmp1;
            tmp1 = x[(ixLead_tmp + m) - 1];
            d = tmp1;
            tmp1 -= work[0];
            work[0] = d;
            y[(iyStart + m) - 2] = tmp1;
          }
          iyStart = (iyStart + dimSize) - 1;
        }
      }
    }
  }
}

} // namespace coder

// End of code generation (diff.cpp)
