//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// repmat.cpp
//
// Code generation for function 'repmat'
//

// Include files
#include "repmat.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_internal_types.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace coder {
void repmat(const c_struct_T &a, double varargin_1, double varargin_2,
            ::coder::array<c_struct_T, 2U> &b)
{
  double d;
  int loop_ub;
  bool b_b;
  if ((varargin_1 != std::floor(varargin_1)) || std::isinf(varargin_1) ||
      (varargin_1 < -2.147483648E+9) || (varargin_1 > 2.147483647E+9)) {
    c_rtErrorWithMessageID(MIN_int32_T, lb_emlrtRTEI.fName,
                           lb_emlrtRTEI.lineNo);
  } else {
    b_b = true;
  }
  if ((varargin_2 != std::floor(varargin_2)) || std::isinf(varargin_2) ||
      (varargin_2 < -2.147483648E+9) || (varargin_2 > 2.147483647E+9)) {
    b_b = false;
  }
  if (!b_b) {
    c_rtErrorWithMessageID(MIN_int32_T, lb_emlrtRTEI.fName,
                           lb_emlrtRTEI.lineNo);
  }
  if (varargin_1 <= 0.0) {
    d = 0.0;
  } else {
    d = varargin_1;
  }
  if (varargin_2 <= 0.0) {
    d = 0.0;
  } else {
    d *= varargin_2;
  }
  if (!(d <= 2.147483647E+9)) {
    l_rtErrorWithMessageID(o_emlrtRTEI.fName, o_emlrtRTEI.lineNo);
  }
  if (!(varargin_1 >= 0.0)) {
    rtNonNegativeError(varargin_1, p_emlrtDCI);
  }
  if (!(varargin_2 >= 0.0)) {
    rtNonNegativeError(varargin_2, p_emlrtDCI);
  }
  b.set_size(static_cast<int>(varargin_1), static_cast<int>(varargin_2));
  loop_ub = static_cast<int>(varargin_1) * static_cast<int>(varargin_2);
  for (int i{0}; i < loop_ub; i++) {
    b[i] = a;
  }
}

void repmat(const ::coder::array<double, 2U> &a, double varargin_1,
            ::coder::array<double, 2U> &b)
{
  double d;
  int i;
  int ncols;
  if ((varargin_1 != std::floor(varargin_1)) || std::isinf(varargin_1) ||
      (varargin_1 < -2.147483648E+9) || (varargin_1 > 2.147483647E+9)) {
    c_rtErrorWithMessageID(MIN_int32_T, lb_emlrtRTEI.fName,
                           lb_emlrtRTEI.lineNo);
  }
  if (varargin_1 <= 0.0) {
    d = 0.0;
  } else {
    d = varargin_1;
  }
  if (!(d <= 2.147483647E+9)) {
    l_rtErrorWithMessageID(o_emlrtRTEI.fName, o_emlrtRTEI.lineNo);
  }
  if (!(varargin_1 >= 0.0)) {
    rtNonNegativeError(varargin_1, p_emlrtDCI);
  }
  i = static_cast<int>(varargin_1);
  b.set_size(i, a.size(1));
  ncols = a.size(1);
  if (a.size(1) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int jcol{0}; jcol < ncols; jcol++) {
    int ibmat;
    ibmat = jcol * static_cast<int>(varargin_1);
    if (static_cast<int>(varargin_1) > 2147483646) {
      check_forloop_overflow_error();
    }
    for (int itilerow{0}; itilerow < i; itilerow++) {
      b[ibmat + itilerow] = a[jcol];
    }
  }
}

void repmat(const ::coder::array<double, 1U> &a, double varargin_2,
            ::coder::array<double, 2U> &b)
{
  double d;
  int i;
  int nrows;
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
  if (!(varargin_2 >= 0.0)) {
    rtNonNegativeError(varargin_2, p_emlrtDCI);
  }
  i = static_cast<int>(varargin_2);
  b.set_size(a.size(0), i);
  nrows = a.size(0);
  if (static_cast<int>(varargin_2) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int jtilecol{0}; jtilecol < i; jtilecol++) {
    int ibcol;
    ibcol = jtilecol * nrows;
    if (nrows > 2147483646) {
      check_forloop_overflow_error();
    }
    for (int k{0}; k < nrows; k++) {
      b[ibcol + k] = a[k];
    }
  }
}

} // namespace coder

// End of code generation (repmat.cpp)