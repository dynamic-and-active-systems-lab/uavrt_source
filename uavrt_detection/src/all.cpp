//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// all.cpp
//
// Code generation for function 'all'
//

// Include files
#include "all.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include <sstream>
#include <stdexcept>
#include <string>

// Function Declarations
static void ac_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
static void ac_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Vector expression with zero stride is not supported.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

namespace coder {
void all(const ::coder::array<bool, 2U> &x, ::coder::array<bool, 1U> &y)
{
  static rtRunTimeErrorInfo vc_emlrtRTEI{
      18,                               // lineNo
      27,                               // colNo
      "eml_int_forloop_overflow_check", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/eml/"
      "eml_int_forloop_overflow_check.m" // pName
  };
  int i1;
  int i2;
  int vstride;
  y.set_size(x.size(0));
  vstride = x.size(0);
  for (i2 = 0; i2 < vstride; i2++) {
    y[i2] = true;
  }
  vstride = x.size(0);
  i2 = (x.size(1) - 1) * x.size(0);
  i1 = 0;
  if (x.size(0) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int j{0}; j < vstride; j++) {
    int ix;
    bool exitg1;
    bool overflow;
    i1++;
    i2++;
    if ((vstride == 0) || (i1 > i2)) {
      overflow = false;
    } else {
      overflow = (i2 > MAX_int32_T - vstride);
    }
    if (vstride == 0) {
      ac_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
    }
    if (overflow) {
      check_forloop_overflow_error();
    }
    ix = i1;
    exitg1 = false;
    while ((!exitg1) && (ix <= i2)) {
      if (!x[ix - 1]) {
        y[j] = false;
        exitg1 = true;
      } else {
        ix += vstride;
      }
    }
  }
}

} // namespace coder

// End of code generation (all.cpp)
