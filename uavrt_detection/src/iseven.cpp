//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// iseven.cpp
//
// Code generation for function 'iseven'
//

// Include files
#include "iseven.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <string>

// Function Declarations
static void x_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
static void x_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Argument must be integer-valued.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

namespace coder {
namespace signalwavelet {
namespace internal {
bool iseven(double x)
{
  static rtRunTimeErrorInfo vc_emlrtRTEI{
      12,       // lineNo
      1,        // colNo
      "iseven", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/signalwavelet/"
      "signalwavelet/+signalwavelet/+internal/iseven.m" // pName
  };
  double r;
  if (x - std::trunc(x) != 0.0) {
    x_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
  }
  if (std::isnan(x) || std::isinf(x)) {
    r = rtNaN;
  } else if (x == 0.0) {
    r = 0.0;
  } else {
    r = std::fmod(x, 2.0);
    if (r == 0.0) {
      r = 0.0;
    } else if (x < 0.0) {
      r += 2.0;
    }
  }
  return r == 0.0;
}

} // namespace internal
} // namespace signalwavelet
} // namespace coder

// End of code generation (iseven.cpp)
