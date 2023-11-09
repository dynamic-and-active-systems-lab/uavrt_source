//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// validateattributes.cpp
//
// Code generation for function 'validateattributes'
//

// Include files
#include "validateattributes.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_data.h"
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
static void rtErrorWithMessageID(const char *r, const char *r1, const char *r2,
                                 const char *aFcnName, int aLineNum);

// Function Definitions
static void rtErrorWithMessageID(const char *r, const char *r1, const char *r2,
                                 const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  ((((((outStream << "Expected ") << r) << " to be a scalar with value ") << r1)
    << " ")
   << r2)
      << ".";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

namespace coder {
void b_validateattributes(double a, double attributesMixed_f9)
{
  static rtRunTimeErrorInfo vc_emlrtRTEI{
      22,           // lineNo
      27,           // colNo
      "validatege", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/"
      "+valattr/validatege.m" // pName
  };
  if (std::isinf(a) || std::isnan(a) || (!(std::floor(a) == a))) {
    j_rtErrorWithMessageID("FFTLength", db_emlrtRTEI.fName,
                           db_emlrtRTEI.lineNo);
  }
  if (a < 0.0) {
    e_rtErrorWithMessageID("FFTLength", t_emlrtRTEI.fName, t_emlrtRTEI.lineNo);
  }
  if (!(a >= attributesMixed_f9)) {
    rtErrorWithMessageID("FFTLength", ">=", "NaN", vc_emlrtRTEI.fName,
                         vc_emlrtRTEI.lineNo);
  }
}

void validateattributes(const ::coder::array<double, 1U> &a)
{
  int k;
  bool exitg1;
  bool p;
  if (a.size(0) == 0) {
    g_rtErrorWithMessageID("Window", y_emlrtRTEI.fName, y_emlrtRTEI.lineNo);
  }
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= a.size(0) - 1)) {
    if ((!std::isinf(a[k])) && (!std::isnan(a[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    i_rtErrorWithMessageID("Window", bb_emlrtRTEI.fName, bb_emlrtRTEI.lineNo);
  }
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= a.size(0) - 1)) {
    if (!std::isnan(a[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    h_rtErrorWithMessageID("Window", ab_emlrtRTEI.fName, ab_emlrtRTEI.lineNo);
  }
}

void validateattributes(double a)
{
  static rtRunTimeErrorInfo vc_emlrtRTEI{
      22,           // lineNo
      27,           // colNo
      "validategt", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/"
      "+valattr/validategt.m" // pName
  };
  if (std::isinf(a) || std::isnan(a) || (!(std::floor(a) == a))) {
    j_rtErrorWithMessageID("WindowLength", db_emlrtRTEI.fName,
                           db_emlrtRTEI.lineNo);
  }
  if (a < 0.0) {
    e_rtErrorWithMessageID("WindowLength", t_emlrtRTEI.fName,
                           t_emlrtRTEI.lineNo);
  }
  if (!(a > 1.0)) {
    rtErrorWithMessageID("WindowLength", ">", "1", vc_emlrtRTEI.fName,
                         vc_emlrtRTEI.lineNo);
  }
}

void validateattributes(double a, double attributesMixed_f11)
{
  static rtRunTimeErrorInfo vc_emlrtRTEI{
      22,           // lineNo
      27,           // colNo
      "validatelt", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/"
      "+valattr/validatelt.m" // pName
  };
  if (std::isinf(a) || std::isnan(a) || (!(std::floor(a) == a))) {
    j_rtErrorWithMessageID("OverlapLength", db_emlrtRTEI.fName,
                           db_emlrtRTEI.lineNo);
  }
  if (a < 0.0) {
    e_rtErrorWithMessageID("OverlapLength", t_emlrtRTEI.fName,
                           t_emlrtRTEI.lineNo);
  }
  if (!(a < attributesMixed_f11)) {
    rtErrorWithMessageID("OverlapLength", "<", "NaN", vc_emlrtRTEI.fName,
                         vc_emlrtRTEI.lineNo);
  }
}

} // namespace coder

// End of code generation (validateattributes.cpp)
