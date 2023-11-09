//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// assertValidSizeArg.cpp
//
// Code generation for function 'assertValidSizeArg'
//

// Include files
#include "assertValidSizeArg.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <string>

// Function Declarations
static void bd_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
static void bd_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  ((((outStream << "Size vector must be a row vector with finite integer "
                   "elements in the range: ")
     << MIN_int32_T)
    << " to ")
   << MAX_int32_T)
      << ".";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

namespace coder {
namespace internal {
void assertValidSizeArg(const double varargin_1[2])
{
  static rtRunTimeErrorInfo vc_emlrtRTEI{
      49,                   // lineNo
      19,                   // colNo
      "assertValidSizeArg", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/"
      "assertValidSizeArg.m" // pName
  };
  double d;
  int exitg2;
  int k;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      if ((varargin_1[k] != std::floor(varargin_1[k])) ||
          std::isinf(varargin_1[k])) {
        bd_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
      } else {
        k++;
      }
    } else {
      k = 0;
      exitg2 = 2;
    }
  } while (exitg2 == 0);
  if (exitg2 != 1) {
    bool exitg1;
    exitg1 = false;
    while ((!exitg1) && (k < 2)) {
      if ((varargin_1[k] < -2.147483648E+9) ||
          (varargin_1[k] > 2.147483647E+9)) {
        bd_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
      } else {
        k++;
      }
    }
  }
  if (varargin_1[0] <= 0.0) {
    d = 0.0;
  } else {
    d = varargin_1[0];
  }
  if (varargin_1[1] <= 0.0) {
    d = 0.0;
  } else {
    d *= varargin_1[1];
  }
  if (!(d <= 2.147483647E+9)) {
    l_rtErrorWithMessageID(o_emlrtRTEI.fName, o_emlrtRTEI.lineNo);
  }
}

void assertValidSizeArg(double varargin_2)
{
  double d;
  if ((varargin_2 != std::floor(varargin_2)) || std::isinf(varargin_2) ||
      (varargin_2 < -2.147483648E+9) || (varargin_2 > 2.147483647E+9)) {
    c_rtErrorWithMessageID(MIN_int32_T, lb_emlrtRTEI.fName,
                           lb_emlrtRTEI.lineNo);
  }
  if (varargin_2 <= 0.0) {
    d = 0.0;
  } else {
    d = varargin_2;
  }
  if (!(d <= 2.147483647E+9)) {
    l_rtErrorWithMessageID(o_emlrtRTEI.fName, o_emlrtRTEI.lineNo);
  }
}

} // namespace internal
} // namespace coder

// End of code generation (assertValidSizeArg.cpp)
