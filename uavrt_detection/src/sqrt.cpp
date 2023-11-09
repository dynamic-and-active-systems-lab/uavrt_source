//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// sqrt.cpp
//
// Code generation for function 'sqrt'
//

// Include files
#include "sqrt.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace coder {
void b_sqrt(::coder::array<double, 2U> &x)
{
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
    m_rtErrorWithMessageID("sqrt", yb_emlrtRTEI.fName, yb_emlrtRTEI.lineNo);
  }
  if (i > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int k{0}; k < i; k++) {
    x[k] = std::sqrt(x[k]);
  }
}

} // namespace coder

// End of code generation (sqrt.cpp)
