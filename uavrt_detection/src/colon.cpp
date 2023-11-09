//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// colon.cpp
//
// Code generation for function 'colon'
//

// Include files
#include "colon.h"
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
void b_eml_integer_colon_dispatcher(int b, ::coder::array<int, 2U> &y)
{
  int n;
  if (b < 1) {
    n = 0;
  } else {
    n = b;
  }
  y.set_size(1, n);
  if (n > 0) {
    int yk;
    y[0] = 1;
    yk = 1;
    if (n > 2147483646) {
      check_forloop_overflow_error();
    }
    for (int k{2}; k <= n; k++) {
      yk++;
      y[k - 1] = yk;
    }
  }
}

void c_eml_integer_colon_dispatcher(int a, ::coder::array<int, 2U> &y)
{
  int n;
  if (a > 5800321) {
    n = 0;
  } else {
    unsigned int nm1;
    if (a < 0) {
      nm1 = 5800321U - static_cast<unsigned int>(a);
    } else {
      nm1 = static_cast<unsigned int>(5800321 - a);
    }
    if (nm1 >= 2147483647U) {
      l_rtErrorWithMessageID(r_emlrtRTEI.fName, r_emlrtRTEI.lineNo);
    }
    n = static_cast<int>(nm1) + 1;
  }
  y.set_size(1, n);
  if (n > 0) {
    int yk;
    y[0] = a;
    yk = a;
    if (n > 2147483646) {
      check_forloop_overflow_error();
    }
    for (int k{2}; k <= n; k++) {
      yk++;
      y[k - 1] = yk;
    }
  }
}

void eml_float_colon(double a, double b, ::coder::array<double, 2U> &y)
{
  static rtDoubleCheckInfo w_emlrtDCI{
      320,               // lineNo
      28,                // colNo
      "eml_float_colon", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/ops/colon.m", // pName
      4 // checkKind
  };
  double apnd;
  double cdiff;
  double ndbl;
  int n;
  ndbl = std::floor((b - a) + 0.5);
  apnd = a + ndbl;
  cdiff = apnd - b;
  if (std::abs(cdiff) <
      4.4408920985006262E-16 * std::fmax(std::abs(a), std::abs(b))) {
    ndbl++;
    apnd = b;
  } else if (cdiff > 0.0) {
    apnd = a + (ndbl - 1.0);
  } else {
    ndbl++;
  }
  if (ndbl >= 0.0) {
    n = static_cast<int>(ndbl);
  } else {
    n = 0;
  }
  if (ndbl > 2.147483647E+9) {
    l_rtErrorWithMessageID(r_emlrtRTEI.fName, r_emlrtRTEI.lineNo);
  }
  y.set_size(1, y.size(1));
  if (n < 0) {
    rtNonNegativeError(static_cast<double>(n), w_emlrtDCI);
  }
  y.set_size(y.size(0), n);
  if (n > 0) {
    y[0] = a;
    if (n > 1) {
      int nm1d2;
      y[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      for (int k{0}; k <= nm1d2 - 2; k++) {
        y[k + 1] = a + (static_cast<double>(k) + 1.0);
        y[(n - k) - 2] = apnd - (static_cast<double>(k) + 1.0);
      }
      if (nm1d2 << 1 == n - 1) {
        y[nm1d2] = (a + apnd) / 2.0;
      } else {
        y[nm1d2] = a + static_cast<double>(nm1d2);
        y[nm1d2 + 1] = apnd - static_cast<double>(nm1d2);
      }
    }
  }
}

void eml_integer_colon_dispatcher(int a, ::coder::array<int, 2U> &y)
{
  int n;
  if (a > 600651) {
    n = 0;
  } else {
    unsigned int nm1;
    if (a < 0) {
      nm1 = 600651U - static_cast<unsigned int>(a);
    } else {
      nm1 = static_cast<unsigned int>(600651 - a);
    }
    if (nm1 >= 2147483647U) {
      l_rtErrorWithMessageID(r_emlrtRTEI.fName, r_emlrtRTEI.lineNo);
    }
    n = static_cast<int>(nm1) + 1;
  }
  y.set_size(1, n);
  if (n > 0) {
    int yk;
    y[0] = a;
    yk = a;
    if (n > 2147483646) {
      check_forloop_overflow_error();
    }
    for (int k{2}; k <= n; k++) {
      yk++;
      y[k - 1] = yk;
    }
  }
}

void eml_integer_colon_dispatcher(int a, int b, ::coder::array<int, 2U> &y)
{
  static rtRunTimeErrorInfo vc_emlrtRTEI{
      291,                            // lineNo
      9,                              // colNo
      "integer_colon_length_nonnegd", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/ops/colon.m" // pName
  };
  int bma;
  if (b < a) {
    bma = 0;
  } else {
    unsigned int nm1;
    if ((a < 0) && (b >= 0)) {
      nm1 = static_cast<unsigned int>(b) - static_cast<unsigned int>(a);
    } else {
      bma = b - a;
      if (bma < 0) {
        h_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
      }
      nm1 = static_cast<unsigned int>(bma);
    }
    if (nm1 >= 2147483647U) {
      l_rtErrorWithMessageID(r_emlrtRTEI.fName, r_emlrtRTEI.lineNo);
    }
    bma = static_cast<int>(nm1) + 1;
  }
  y.set_size(1, bma);
  if (bma > 0) {
    int yk;
    y[0] = a;
    yk = a;
    if (bma > 2147483646) {
      check_forloop_overflow_error();
    }
    for (int k{2}; k <= bma; k++) {
      yk++;
      y[k - 1] = yk;
    }
  }
}

} // namespace coder

// End of code generation (colon.cpp)
