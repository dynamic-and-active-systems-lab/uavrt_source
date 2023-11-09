//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// wgn.cpp
//
// Code generation for function 'wgn'
//

// Include files
#include "wgn.h"
#include "eml_int_forloop_overflow_check.h"
#include "randn.h"
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
void wgn(creal_T y[1000])
{
  static const char b_cv2[7]{'c', 'o', 'm', 'p', 'l', 'e', 'x'};
  static const char b_cv[6]{'l', 'i', 'n', 'e', 'a', 'r'};
  static const char b_cv1[6]{'l', 'i', 'n', 'e', 'a', 'r'};
  static const char b_cv3[3]{'d', 'b', 'w'};
  array<char, 2U> r;
  array<char, 2U> r1;
  array<char, 2U> switch_expression;
  double noisePower;
  int exitg1;
  int ns;
  bool p;
  r.set((char *)&b_cv[0], 1, 6);
  ns = r.size(1);
  p = true;
  if (r.size(1) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int k{0}; k < ns; k++) {
    p = (p && (static_cast<unsigned char>(r[k]) <= 127));
  }
  if (!p) {
    yc_rtErrorWithMessageID(j_emlrtRTEI.fName, j_emlrtRTEI.lineNo);
  }
  switch_expression.set_size(1, r.size(1));
  ns = r.size(1);
  for (int k{0}; k < ns; k++) {
    switch_expression[k] = cv1[static_cast<unsigned char>(r[k]) & 127];
  }
  p = false;
  if (switch_expression.size(1) == 6) {
    ns = 0;
    do {
      exitg1 = 0;
      if (ns < 6) {
        if (switch_expression[ns] != b_cv1[ns]) {
          exitg1 = 1;
        } else {
          ns++;
        }
      } else {
        p = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  if (p) {
    ns = 0;
  } else {
    p = false;
    if (switch_expression.size(1) == 3) {
      ns = 0;
      do {
        exitg1 = 0;
        if (ns < 3) {
          if (switch_expression[ns] != b_cv3[ns]) {
            exitg1 = 1;
          } else {
            ns++;
          }
        } else {
          p = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
    if (p) {
      ns = 1;
    } else {
      ns = -1;
    }
  }
  switch (ns) {
  case 0:
    noisePower = 1.0;
    break;
  case 1:
    noisePower = 1.2589254117941673;
    break;
  default:
    noisePower = 0.0012589254117941675;
    break;
  }
  r1.set((char *)&b_cv2[0], 1, 7);
  p = false;
  if (r1.size(1) >= 1) {
    ns = static_cast<unsigned char>(r1[0]);
    if (ns > 127) {
      yc_rtErrorWithMessageID(j_emlrtRTEI.fName, j_emlrtRTEI.lineNo);
    }
    if (cv1[ns] == 'r') {
      p = true;
    }
  }
  if (p) {
    double b[1000];
    noisePower = std::sqrt(noisePower);
    randn(b);
    for (ns = 0; ns < 1000; ns++) {
      y[ns].re = noisePower * b[ns];
      y[ns].im = 0.0;
    }
  } else {
    noisePower = std::sqrt(noisePower);
    complexLike(y);
    for (ns = 0; ns < 1000; ns++) {
      y[ns].re *= noisePower;
      y[ns].im *= noisePower;
    }
  }
}

} // namespace coder

// End of code generation (wgn.cpp)
