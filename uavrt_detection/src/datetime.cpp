//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// datetime.cpp
//
// Code generation for function 'datetime'
//

// Include files
#include "datetime.h"
#include "getLocalTime.h"
#include "plus.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <string>

// Function Declarations
static void bb_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
static void bb_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Year, month, day, hour, minute, and second components must be "
               "integer values when milliseconds is specified.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

namespace coder {
void datetime::init()
{
  static rtRunTimeErrorInfo vc_emlrtRTEI{
      1,                   // lineNo
      1,                   // colNo
      "createFromDateVec", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/matlab/datatypes/codegen/"
      "datetime/+matlab/+internal/+coder/+datetime/createFromDateVec.p" // pName
  };
  double b_second;
  double c_tm_hour;
  double c_tm_min;
  double c_tm_mon;
  double check;
  double fracSecs;
  double shi;
  double slo;
  bool expl_temp;
  check = internal::b_time::getLocalTime(b_second, c_tm_min, c_tm_hour, shi,
                                         c_tm_mon, slo, expl_temp);
  fracSecs = check / 1.0E+6;
  check = (((((slo + c_tm_mon) + shi) + c_tm_hour) + c_tm_min) + b_second) +
          fracSecs;
  if ((!std::isinf(check)) && (!std::isnan(check))) {
    creal_T ahi;
    if ((!(std::ceil(slo) == slo)) || (!(std::ceil(c_tm_mon) == c_tm_mon)) ||
        (!(std::ceil(shi) == shi)) || (!(std::ceil(c_tm_hour) == c_tm_hour)) ||
        (!(std::ceil(c_tm_min) == c_tm_min))) {
      bb_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
    }
    if (std::ceil(b_second) != b_second) {
      bb_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
    }
    if ((c_tm_mon < 1.0) || (c_tm_mon > 12.0)) {
      check = std::floor((c_tm_mon - 1.0) / 12.0);
      slo += check;
      c_tm_mon = ((c_tm_mon - 1.0) - check * 12.0) + 1.0;
    }
    if (c_tm_mon < 3.0) {
      slo--;
      c_tm_mon += 9.0;
    } else {
      c_tm_mon -= 3.0;
    }
    c_tm_mon =
        ((((((365.0 * slo + std::floor(slo / 4.0)) - std::floor(slo / 100.0)) +
            std::floor(slo / 400.0)) +
           std::floor((153.0 * c_tm_mon + 2.0) / 5.0)) +
          shi) +
         60.0) -
        719529.0;
    if (std::abs(c_tm_mon) <= 6.69692879491417E+299) {
      check = 1.34217729E+8 * c_tm_mon;
      check -= check - c_tm_mon;
      slo = c_tm_mon - check;
    } else if ((!std::isinf(c_tm_mon)) && (!std::isnan(c_tm_mon))) {
      shi = c_tm_mon * 3.7252902984619141E-9;
      check = 1.34217729E+8 * shi;
      check -= check - shi;
      slo = shi - check;
      check *= 2.68435456E+8;
      slo *= 2.68435456E+8;
    } else {
      check = c_tm_mon;
      slo = 0.0;
    }
    shi = c_tm_mon * 8.64E+7;
    slo = slo * 8.64E+7 + (check * 8.64E+7 - shi);
    if (std::isnan(slo)) {
      slo = 0.0;
    }
    if (std::isnan(slo)) {
      slo = 0.0;
    }
    if ((fracSecs < 0.0) || (fracSecs >= 1000.0)) {
      check = std::floor(fracSecs / 1000.0);
      b_second += check;
      fracSecs -= check * 1000.0;
    }
    ahi.re = shi;
    ahi.im = slo;
    data = matlab::internal::coder::doubledouble::c_plus(
        matlab::internal::coder::doubledouble::c_plus(
            matlab::internal::coder::doubledouble::c_plus(
                ahi, (60.0 * c_tm_hour + c_tm_min) * 60000.0),
            b_second * 1000.0),
        fracSecs);
  } else {
    data.re = check;
    data.im = 0.0;
  }
}

} // namespace coder

// End of code generation (datetime.cpp)
