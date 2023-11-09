//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// log10.cpp
//
// Code generation for function 'log10'
//

// Include files
#include "log10.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace coder {
void b_log10(::coder::array<double, 2U> &x)
{
  static rtRunTimeErrorInfo vc_emlrtRTEI{
      14,      // lineNo
      9,       // colNo
      "log10", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elfun/log10.m" // pName
  };
  int i;
  bool p;
  p = false;
  i = x.size(0) * x.size(1);
  for (int k{0}; k < i; k++) {
    if (p || (x[k] < 0.0)) {
      p = true;
    }
  }
  if (p) {
    m_rtErrorWithMessageID("log10", vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
  }
  if (i > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int k{0}; k < i; k++) {
    x[k] = std::log10(x[k]);
  }
}

} // namespace coder

// End of code generation (log10.cpp)
