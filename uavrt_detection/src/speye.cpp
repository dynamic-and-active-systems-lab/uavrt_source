//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// speye.cpp
//
// Code generation for function 'speye'
//

// Include files
#include "speye.h"
#include "rt_nonfinite.h"
#include "sparse1.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include <cmath>

// Function Definitions
namespace coder {
void speye(const double m[2], sparse &y)
{
  double b_t;
  double d;
  double t;
  int u0;
  int u1;
  if (m[0] < 0.0) {
    t = 0.0;
  } else {
    t = m[0];
  }
  if ((t != std::floor(t)) || std::isinf(t) || (t < -2.147483648E+9) ||
      (t > 2.147483647E+9)) {
    c_rtErrorWithMessageID(MIN_int32_T, lb_emlrtRTEI.fName,
                           lb_emlrtRTEI.lineNo);
  }
  if (t <= 0.0) {
    d = 0.0;
  } else {
    d = t;
  }
  if (!(d <= 2.147483647E+9)) {
    l_rtErrorWithMessageID(o_emlrtRTEI.fName, o_emlrtRTEI.lineNo);
  }
  if (m[1] < 0.0) {
    b_t = 0.0;
  } else {
    b_t = m[1];
  }
  if ((b_t != std::floor(b_t)) || std::isinf(b_t) || (b_t < -2.147483648E+9) ||
      (b_t > 2.147483647E+9)) {
    c_rtErrorWithMessageID(MIN_int32_T, lb_emlrtRTEI.fName,
                           lb_emlrtRTEI.lineNo);
  }
  if (b_t <= 0.0) {
    d = 0.0;
  } else {
    d = b_t;
  }
  if (!(d <= 2.147483647E+9)) {
    l_rtErrorWithMessageID(o_emlrtRTEI.fName, o_emlrtRTEI.lineNo);
  }
  u0 = static_cast<int>(t);
  u1 = static_cast<int>(b_t);
  if (u0 <= u1) {
    u1 = u0;
  }
  sparse::eyeLike(u1, static_cast<int>(t), static_cast<int>(b_t), y);
}

} // namespace coder

// End of code generation (speye.cpp)
