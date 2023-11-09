//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// lower.cpp
//
// Code generation for function 'lower'
//

// Include files
#include "lower.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
void lower(const ::coder::array<char, 2U> &x, ::coder::array<char, 2U> &y)
{
  int ns;
  bool p;
  ns = x.size(1);
  p = true;
  if (x.size(1) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int k{0}; k < ns; k++) {
    p = (p && (static_cast<unsigned char>(x[k]) <= 127));
  }
  if (!p) {
    yc_rtErrorWithMessageID(j_emlrtRTEI.fName, j_emlrtRTEI.lineNo);
  }
  y.set_size(1, x.size(1));
  ns = x.size(1);
  for (int k{0}; k < ns; k++) {
    y[k] = cv1[static_cast<unsigned char>(x[k]) & 127];
  }
}

} // namespace coder

// End of code generation (lower.cpp)
