//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// rectwin.cpp
//
// Code generation for function 'rectwin'
//

// Include files
#include "rectwin.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <string>

// Function Declarations
static void f_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

static void q_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
static void f_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum)
{
  std::stringstream outStream;
  ((outStream << "Order, ") << r) << ", must be finite.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

static void q_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Order must be greater than or equal to zero.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

namespace coder {
void rectwin(double n_est, ::coder::array<double, 1U> &w)
{
  static rtDoubleCheckInfo w_emlrtDCI{
      14,                                                             // lineNo
      1,                                                              // colNo
      "rectwin",                                                      // fName
      "/Applications/MATLAB_R2023a.app/toolbox/signal/eml/rectwin.m", // pName
      4 // checkKind
  };
  static rtRunTimeErrorInfo
      vc_emlrtRTEI{
          18,            // lineNo
          5,             // colNo
          "check_order", // fName
          "/Applications/MATLAB_R2023a.app/toolbox/signal/eml/private/"
          "check_order.m" // pName
      };
  static rtRunTimeErrorInfo
      wc_emlrtRTEI{
          22,            // lineNo
          23,            // colNo
          "check_order", // fName
          "/Applications/MATLAB_R2023a.app/toolbox/signal/eml/private/"
          "check_order.m" // pName
      };
  int i;
  int n;
  if (std::isinf(n_est) || std::isnan(n_est)) {
    f_rtErrorWithMessageID("N", vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
  }
  if (!(n_est >= 0.0)) {
    q_rtErrorWithMessageID(wc_emlrtRTEI.fName, wc_emlrtRTEI.lineNo);
  }
  if (n_est == std::floor(n_est)) {
    n = static_cast<int>(n_est);
  } else {
    n = static_cast<int>(std::round(n_est));
  }
  if (n < 0) {
    rtNonNegativeError(static_cast<double>(n), w_emlrtDCI);
  }
  if (n_est == std::floor(n_est)) {
    i = static_cast<int>(n_est);
  } else {
    i = static_cast<int>(std::round(n_est));
  }
  w.set_size(i);
  for (i = 0; i < n; i++) {
    w[i] = 1.0;
  }
}

} // namespace coder

// End of code generation (rectwin.cpp)
