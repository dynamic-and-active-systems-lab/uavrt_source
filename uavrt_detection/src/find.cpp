//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// find.cpp
//
// Code generation for function 'find'
//

// Include files
#include "find.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"
#include "sparse1.h"
#include "threshold.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "waveform.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"

// Variable Definitions
static rtRunTimeErrorInfo h_emlrtRTEI{
    81,         // lineNo
    1,          // colNo
    "eml_find", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/find.m" // pName
};

static rtRunTimeErrorInfo i_emlrtRTEI{
    392,                  // lineNo
    1,                    // colNo
    "find_first_indices", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/find.m" // pName
};

// Function Definitions
void binary_expand_op(coder::array<int, 1U> &in1,
                      const coder::array<double, 1U> &in2, int in3, int in4,
                      int in5, const waveform *in6, int in7, int in8, int in9)
{
  coder::array<bool, 1U> b_in2;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  i = div_s32((in9 - in7) + 1, in8) + 1;
  stride_0_0 = div_s32((in5 - in3) + 1, in4) + 1;
  if (i == 1) {
    loop_ub = stride_0_0;
  } else {
    loop_ub = i;
  }
  b_in2.set_size(loop_ub);
  stride_0_0 = (stride_0_0 != 1);
  stride_1_0 = (i != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in2[i] = (in2[(in3 + in4 * (i * stride_0_0)) - 1] <
                in6->thresh.threshVecFine[(in7 + in8 * (i * stride_1_0)) - 1]);
  }
  coder::c_eml_find(b_in2, in1);
}

void binary_expand_op(coder::array<int, 1U> &in1,
                      const coder::array<double, 1U> &in2, int in3, int in4,
                      const waveform *in5, int in6, int in7)
{
  coder::array<bool, 1U> b_in2;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  i = in7 - in6;
  stride_0_0 = in4 - in3;
  if (i == 1) {
    loop_ub = stride_0_0;
  } else {
    loop_ub = i;
  }
  b_in2.set_size(loop_ub);
  stride_0_0 = (stride_0_0 != 1);
  stride_1_0 = (i != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in2[i] = (in2[in3 + i * stride_0_0] <
                in5->thresh.threshVecFine[in6 + i * stride_1_0]);
  }
  coder::c_eml_find(b_in2, in1);
}

namespace coder {
void b_eml_find(const ::coder::array<bool, 2U> &x, ::coder::array<int, 2U> &i)
{
  int idx;
  int ii;
  int nx;
  bool exitg1;
  nx = x.size(1);
  idx = 0;
  i.set_size(1, x.size(1));
  if (x.size(1) > 2147483646) {
    check_forloop_overflow_error();
  }
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (x[ii]) {
      idx++;
      i[idx - 1] = ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (idx > x.size(1)) {
    h_rtErrorWithMessageID(i_emlrtRTEI.fName, i_emlrtRTEI.lineNo);
  }
  if (x.size(1) == 1) {
    if (idx == 0) {
      i.set_size(1, 0);
    }
  } else {
    if (idx < 1) {
      idx = 0;
    }
    i.set_size(i.size(0), idx);
  }
}

void c_eml_find(const ::coder::array<bool, 1U> &x, ::coder::array<int, 1U> &i)
{
  int idx;
  int ii;
  int k;
  bool exitg1;
  k = (x.size(0) >= 1);
  if (k > x.size(0)) {
    h_rtErrorWithMessageID(h_emlrtRTEI.fName, h_emlrtRTEI.lineNo);
  }
  idx = 0;
  i.set_size(k);
  if (x.size(0) > 2147483646) {
    check_forloop_overflow_error();
  }
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= x.size(0) - 1)) {
    if (x[ii]) {
      idx++;
      i[idx - 1] = ii + 1;
      if (idx >= k) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (idx > k) {
    h_rtErrorWithMessageID(i_emlrtRTEI.fName, i_emlrtRTEI.lineNo);
  }
  if (k == 1) {
    if (idx == 0) {
      i.set_size(0);
    }
  } else {
    int iv[2];
    k = (idx >= 1);
    iv[0] = 1;
    iv[1] = k;
    internal::indexShapeCheck(i.size(0), iv);
    i.set_size(k);
  }
}

void d_eml_find(const ::coder::array<bool, 1U> &x, ::coder::array<int, 1U> &i)
{
  static rtRunTimeErrorInfo vc_emlrtRTEI{
      447,                 // lineNo
      1,                   // colNo
      "find_last_indices", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/find.m" // pName
  };
  int idx;
  int ii;
  int k;
  bool exitg1;
  k = (x.size(0) >= 1);
  if (k > x.size(0)) {
    h_rtErrorWithMessageID(h_emlrtRTEI.fName, h_emlrtRTEI.lineNo);
  }
  ii = x.size(0);
  idx = 0;
  i.set_size(k);
  exitg1 = false;
  while ((!exitg1) && (ii > 0)) {
    if (x[ii - 1]) {
      idx++;
      i[idx - 1] = ii;
      if (idx >= k) {
        exitg1 = true;
      } else {
        ii--;
      }
    } else {
      ii--;
    }
  }
  if (idx > k) {
    h_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
  }
  if (k == 1) {
    if (idx == 0) {
      i.set_size(0);
    }
  } else {
    int iv[2];
    k = (idx >= 1);
    iv[0] = 1;
    iv[1] = k;
    internal::indexShapeCheck(i.size(0), iv);
    i.set_size(k);
  }
}

void e_eml_find(const sparse &x, ::coder::array<int, 1U> &i,
                ::coder::array<int, 1U> &j)
{
  static rtDoubleCheckInfo w_emlrtDCI{
      195,                           // lineNo
      30,                            // colNo
      "find_first_nonempty_triples", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/find.m", // pName
      4 // checkKind
  };
  static rtRunTimeErrorInfo vc_emlrtRTEI{
      239,                           // lineNo
      1,                             // colNo
      "find_first_nonempty_triples", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/find.m" // pName
  };
  array<double, 1U> v;
  int nx;
  int nx_tmp;
  nx_tmp = x.colidx[x.colidx.size(0) - 1];
  nx = nx_tmp - 2;
  if (nx_tmp - 1 == 0) {
    i.set_size(0);
    j.set_size(0);
  } else {
    int idx;
    if (nx_tmp - 1 < 0) {
      rtNonNegativeError(static_cast<double>(nx_tmp - 1), w_emlrtDCI);
    }
    i.set_size(nx_tmp - 1);
    j.set_size(nx_tmp - 1);
    v.set_size(nx_tmp - 1);
    if (nx_tmp - 1 > 2147483646) {
      check_forloop_overflow_error();
    }
    for (idx = 0; idx <= nx; idx++) {
      i[idx] = x.rowidx[idx];
    }
    if (nx_tmp - 1 > 2147483646) {
      check_forloop_overflow_error();
    }
    for (idx = 0; idx <= nx; idx++) {
      v[idx] = x.d[idx];
    }
    idx = 0;
    nx = 1;
    while (idx < nx_tmp - 1) {
      if (idx == x.colidx[nx] - 1) {
        nx++;
      } else {
        idx++;
        j[idx - 1] = nx;
      }
    }
    if (idx > nx_tmp - 1) {
      h_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
    }
    if (nx_tmp - 1 == 1) {
      if (idx == 0) {
        i.set_size(0);
        j.set_size(0);
      }
    } else {
      int iv[2];
      if (idx < 1) {
        nx = 0;
      } else {
        nx = idx;
      }
      iv[0] = 1;
      iv[1] = nx;
      internal::indexShapeCheck(i.size(0), iv);
      i.set_size(nx);
      iv[0] = 1;
      iv[1] = nx;
      internal::indexShapeCheck(j.size(0), iv);
      j.set_size(nx);
      iv[0] = 1;
      iv[1] = nx;
      internal::indexShapeCheck(v.size(0), iv);
    }
  }
}

void eml_find(const ::coder::array<bool, 2U> &x, ::coder::array<int, 2U> &i)
{
  int idx;
  int ii;
  int k;
  bool exitg1;
  k = (x.size(1) >= 1);
  if (k > x.size(1)) {
    h_rtErrorWithMessageID(h_emlrtRTEI.fName, h_emlrtRTEI.lineNo);
  }
  idx = 0;
  i.set_size(1, k);
  if (x.size(1) > 2147483646) {
    check_forloop_overflow_error();
  }
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= x.size(1) - 1)) {
    if (x[ii]) {
      idx++;
      i[idx - 1] = ii + 1;
      if (idx >= k) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (idx > k) {
    h_rtErrorWithMessageID(i_emlrtRTEI.fName, i_emlrtRTEI.lineNo);
  }
  if (k == 1) {
    if (idx == 0) {
      i.set_size(1, 0);
    }
  } else {
    i.set_size(i.size(0), static_cast<int>(idx >= 1));
  }
}

} // namespace coder

// End of code generation (find.cpp)
