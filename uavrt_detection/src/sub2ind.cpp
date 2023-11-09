//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// sub2ind.cpp
//
// Code generation for function 'sub2ind'
//

// Include files
#include "sub2ind.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"

// Function Declarations
namespace coder {
static bool allinrange(const ::coder::array<double, 1U> &x, int hi);

static bool b_allinrange(const ::coder::array<double, 2U> &x, int hi);

} // namespace coder

// Function Definitions
namespace coder {
static bool allinrange(const ::coder::array<double, 1U> &x, int hi)
{
  int k;
  bool p;
  k = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (k <= x.size(0) - 1) {
      if ((x[k] >= 1.0) && (x[k] <= hi)) {
        k++;
      } else {
        p = false;
        exitg1 = 1;
      }
    } else {
      p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return p;
}

static bool b_allinrange(const ::coder::array<double, 2U> &x, int hi)
{
  int k;
  bool p;
  k = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (k <= x.size(1) - 1) {
      if ((x[k] >= 1.0) && (x[k] <= hi)) {
        k++;
      } else {
        p = false;
        exitg1 = 1;
      }
    } else {
      p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return p;
}

bool allinrange(const ::coder::array<double, 2U> &x, int hi)
{
  int i;
  int k;
  bool p;
  i = x.size(0) * x.size(1);
  k = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (k <= i - 1) {
      if ((x[k] >= 1.0) && (x[k] <= hi)) {
        k++;
      } else {
        p = false;
        exitg1 = 1;
      }
    } else {
      p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return p;
}

void eml_sub2ind(const int siz[2], const ::coder::array<double, 2U> &varargin_1,
                 const ::coder::array<double, 2U> &varargin_2,
                 ::coder::array<int, 2U> &idx)
{
  unsigned int b_varargin_1[2];
  unsigned int b_varargin_2[2];
  int k;
  bool exitg1;
  bool p;
  if (!b_allinrange(varargin_1, siz[0])) {
    cc_rtErrorWithMessageID(gc_emlrtRTEI.fName, gc_emlrtRTEI.lineNo);
  }
  b_varargin_1[0] = 1U;
  b_varargin_2[0] = 1U;
  b_varargin_1[1] = static_cast<unsigned int>(varargin_1.size(1));
  b_varargin_2[1] = static_cast<unsigned int>(varargin_2.size(1));
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (static_cast<int>(b_varargin_1[k]) !=
        static_cast<int>(b_varargin_2[k])) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (!p) {
    dc_rtErrorWithMessageID(hc_emlrtRTEI.fName, hc_emlrtRTEI.lineNo);
  }
  if (!b_allinrange(varargin_2, siz[1])) {
    cc_rtErrorWithMessageID(gc_emlrtRTEI.fName, gc_emlrtRTEI.lineNo);
  }
  idx.set_size(1, varargin_1.size(1));
  k = varargin_1.size(1);
  for (int i{0}; i < k; i++) {
    idx[i] = static_cast<int>(varargin_1[i]) +
             siz[0] * (static_cast<int>(varargin_2[i]) - 1);
  }
}

void eml_sub2ind(const int siz[2], const ::coder::array<double, 1U> &varargin_1,
                 const ::coder::array<double, 1U> &varargin_2,
                 ::coder::array<int, 1U> &idx)
{
  unsigned int b_varargin_1[2];
  unsigned int b_varargin_2[2];
  int k;
  bool exitg1;
  bool p;
  if (!allinrange(varargin_1, siz[0])) {
    cc_rtErrorWithMessageID(gc_emlrtRTEI.fName, gc_emlrtRTEI.lineNo);
  }
  b_varargin_1[0] = static_cast<unsigned int>(varargin_1.size(0));
  b_varargin_1[1] = 1U;
  b_varargin_2[0] = static_cast<unsigned int>(varargin_2.size(0));
  b_varargin_2[1] = 1U;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (static_cast<int>(b_varargin_1[k]) !=
        static_cast<int>(b_varargin_2[k])) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (!p) {
    dc_rtErrorWithMessageID(hc_emlrtRTEI.fName, hc_emlrtRTEI.lineNo);
  }
  if (!allinrange(varargin_2, siz[1])) {
    cc_rtErrorWithMessageID(gc_emlrtRTEI.fName, gc_emlrtRTEI.lineNo);
  }
  idx.set_size(varargin_1.size(0));
  k = varargin_1.size(0);
  for (int i{0}; i < k; i++) {
    idx[i] = static_cast<int>(varargin_1[i]) +
             siz[0] * (static_cast<int>(varargin_2[i]) - 1);
  }
}

int eml_sub2ind(const int siz[2], double varargin_2)
{
  if (siz[0] < 1) {
    cc_rtErrorWithMessageID(gc_emlrtRTEI.fName, gc_emlrtRTEI.lineNo);
  }
  if ((!(varargin_2 >= 1.0)) || (!(varargin_2 <= siz[1]))) {
    cc_rtErrorWithMessageID(gc_emlrtRTEI.fName, gc_emlrtRTEI.lineNo);
  }
  return siz[0] * (static_cast<int>(varargin_2) - 1) + 1;
}

} // namespace coder

// End of code generation (sub2ind.cpp)
