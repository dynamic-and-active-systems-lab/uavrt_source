//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// stft.cpp
//
// Code generation for function 'stft'
//

// Include files
#include "stft.h"
#include "circshift.h"
#include "eml_int_forloop_overflow_check.h"
#include "fft.h"
#include "formatSTFTOutput.h"
#include "indexShapeCheck.h"
#include "iseven.h"
#include "psdfreqvec.h"
#include "rt_nonfinite.h"
#include "stickyStruct.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "validateattributes.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <string>

// Variable Definitions
static rtBoundsCheckInfo e_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    84,                 // lineNo
    38,                 // colNo
    "",                 // aName
    "computeDFTviaFFT", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/private/"
    "computeDFT.m", // pName
    0               // checkKind
};

static rtBoundsCheckInfo f_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    85,                 // lineNo
    14,                 // colNo
    "",                 // aName
    "computeDFTviaFFT", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/private/"
    "computeDFT.m", // pName
    0               // checkKind
};

static rtEqualityCheckInfo
    c_emlrtECI{
        -1,                 // nDims
        85,                 // lineNo
        9,                  // colNo
        "computeDFTviaFFT", // fName
        "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/private/"
        "computeDFT.m" // pName
    };

static rtRunTimeErrorInfo w_emlrtRTEI{
    12,                                                             // lineNo
    23,                                                             // colNo
    "datawrap",                                                     // fName
    "/Applications/MATLAB_R2023a.app/toolbox/signal/eml/datawrap.m" // pName
};

static rtBoundsCheckInfo g_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    277,                                                            // lineNo
    12,                                                             // colNo
    "",                                                             // aName
    "computeSTFT",                                                  // fName
    "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/stft.m", // pName
    0                                                               // checkKind
};

static rtBoundsCheckInfo h_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    277,                                                            // lineNo
    14,                                                             // colNo
    "",                                                             // aName
    "computeSTFT",                                                  // fName
    "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/stft.m", // pName
    0                                                               // checkKind
};

static rtBoundsCheckInfo i_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    278,                                                            // lineNo
    12,                                                             // colNo
    "",                                                             // aName
    "computeSTFT",                                                  // fName
    "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/stft.m", // pName
    0                                                               // checkKind
};

static rtBoundsCheckInfo j_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    278,                                                            // lineNo
    14,                                                             // colNo
    "",                                                             // aName
    "computeSTFT",                                                  // fName
    "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/stft.m", // pName
    0                                                               // checkKind
};

static rtDoubleCheckInfo b_emlrtDCI{
    23,               // lineNo
    23,               // colNo
    "getSTFTColumns", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/+signal/+internal/"
    "+stft/getSTFTColumns.m", // pName
    1                         // checkKind
};

static rtBoundsCheckInfo k_emlrtBCI{
    -1,               // iFirst
    -1,               // iLast
    23,               // lineNo
    23,               // colNo
    "",               // aName
    "getSTFTColumns", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/+signal/+internal/"
    "+stft/getSTFTColumns.m", // pName
    0                         // checkKind
};

static rtDoubleCheckInfo c_emlrtDCI{
    23,               // lineNo
    42,               // colNo
    "getSTFTColumns", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/+signal/+internal/"
    "+stft/getSTFTColumns.m", // pName
    1                         // checkKind
};

static rtBoundsCheckInfo l_emlrtBCI{
    -1,               // iFirst
    -1,               // iLast
    23,               // lineNo
    42,               // colNo
    "",               // aName
    "getSTFTColumns", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/+signal/+internal/"
    "+stft/getSTFTColumns.m", // pName
    0                         // checkKind
};

static rtBoundsCheckInfo m_emlrtBCI{
    -1,               // iFirst
    -1,               // iLast
    23,               // lineNo
    11,               // colNo
    "",               // aName
    "getSTFTColumns", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/+signal/+internal/"
    "+stft/getSTFTColumns.m", // pName
    0                         // checkKind
};

static rtEqualityCheckInfo d_emlrtECI{
    -1,               // nDims
    23,               // lineNo
    5,                // colNo
    "getSTFTColumns", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/+signal/+internal/"
    "+stft/getSTFTColumns.m" // pName
};

static rtRunTimeErrorInfo cb_emlrtRTEI{
    336,                 // lineNo
    5,                   // colNo
    "verifyDataAndTime", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/+signal/+internal/"
    "+stft/stftParser.m" // pName
};

static rtDoubleCheckInfo d_emlrtDCI{
    14,               // lineNo
    30,               // colNo
    "getSTFTColumns", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/+signal/+internal/"
    "+stft/getSTFTColumns.m", // pName
    1                         // checkKind
};

static rtDoubleCheckInfo e_emlrtDCI{
    14,               // lineNo
    30,               // colNo
    "getSTFTColumns", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/+signal/+internal/"
    "+stft/getSTFTColumns.m", // pName
    4                         // checkKind
};

static rtDoubleCheckInfo f_emlrtDCI{
    81,                 // lineNo
    12,                 // colNo
    "computeDFTviaFFT", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/private/"
    "computeDFT.m", // pName
    1               // checkKind
};

static rtDoubleCheckInfo g_emlrtDCI{
    81,                 // lineNo
    12,                 // colNo
    "computeDFTviaFFT", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/private/"
    "computeDFT.m", // pName
    4               // checkKind
};

static rtDoubleCheckInfo h_emlrtDCI{
    14,               // lineNo
    5,                // colNo
    "getSTFTColumns", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/+signal/+internal/"
    "+stft/getSTFTColumns.m", // pName
    1                         // checkKind
};

static rtDoubleCheckInfo i_emlrtDCI{
    81,                 // lineNo
    1,                  // colNo
    "computeDFTviaFFT", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/private/"
    "computeDFT.m", // pName
    1               // checkKind
};

static rtBoundsCheckInfo p_emlrtBCI{
    -1,                                                              // iFirst
    -1,                                                              // iLast
    35,                                                              // lineNo
    14,                                                              // colNo
    "",                                                              // aName
    "datawrap",                                                      // fName
    "/Applications/MATLAB_R2023a.app/toolbox/signal/eml/datawrap.m", // pName
    0 // checkKind
};

static rtBoundsCheckInfo q_emlrtBCI{
    -1,                                                              // iFirst
    -1,                                                              // iLast
    35,                                                              // lineNo
    7,                                                               // colNo
    "",                                                              // aName
    "datawrap",                                                      // fName
    "/Applications/MATLAB_R2023a.app/toolbox/signal/eml/datawrap.m", // pName
    0 // checkKind
};

static rtBoundsCheckInfo r_emlrtBCI{
    -1,                                                              // iFirst
    -1,                                                              // iLast
    39,                                                              // lineNo
    7,                                                               // colNo
    "",                                                              // aName
    "datawrap",                                                      // fName
    "/Applications/MATLAB_R2023a.app/toolbox/signal/eml/datawrap.m", // pName
    0 // checkKind
};

static rtBoundsCheckInfo s_emlrtBCI{
    -1,                                                              // iFirst
    -1,                                                              // iLast
    45,                                                              // lineNo
    18,                                                              // colNo
    "",                                                              // aName
    "datawrap",                                                      // fName
    "/Applications/MATLAB_R2023a.app/toolbox/signal/eml/datawrap.m", // pName
    0 // checkKind
};

static rtBoundsCheckInfo t_emlrtBCI{
    -1,                                                              // iFirst
    -1,                                                              // iLast
    45,                                                              // lineNo
    25,                                                              // colNo
    "",                                                              // aName
    "datawrap",                                                      // fName
    "/Applications/MATLAB_R2023a.app/toolbox/signal/eml/datawrap.m", // pName
    0 // checkKind
};

static rtBoundsCheckInfo u_emlrtBCI{
    -1,                                                              // iFirst
    -1,                                                              // iLast
    45,                                                              // lineNo
    11,                                                              // colNo
    "",                                                              // aName
    "datawrap",                                                      // fName
    "/Applications/MATLAB_R2023a.app/toolbox/signal/eml/datawrap.m", // pName
    0 // checkKind
};

static rtRunTimeErrorInfo eb_emlrtRTEI{
    14,                 // lineNo
    37,                 // colNo
    "validatepositive", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatepositive.m" // pName
};

// Function Declarations
static void b_rtErrorWithMessageID(const int i, const char *aFcnName,
                                   int aLineNum);

static void k_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

static void s_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
static void b_rtErrorWithMessageID(const int i, const char *aFcnName,
                                   int aLineNum)
{
  std::stringstream outStream;
  ((outStream << "Input signal length must be greater than or equal to the "
                 "window length, ")
   << i)
      << ".";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

static void k_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum)
{
  std::stringstream outStream;
  ((outStream << "Expected ") << r) << " to be positive.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

static void s_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Input signal must have at least 2 samples.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

namespace coder {
void stft(const ::coder::array<creal32_T, 2U> &x, double varargin_1,
          const ::coder::array<double, 1U> &varargin_3, double varargin_5,
          double varargin_7, ::coder::array<creal32_T, 2U> &varargout_1,
          ::coder::array<float, 1U> &varargout_2,
          ::coder::array<float, 1U> &varargout_3)
{
  static rtRunTimeErrorInfo vc_emlrtRTEI{
      318,                 // lineNo
      5,                   // colNo
      "verifyDataAndTime", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/+signal/+internal/"
      "+stft/stftParser.m" // pName
  };
  internal::j_stickyStruct obj;
  array<creal32_T, 2U> c;
  array<creal32_T, 2U> xin;
  array<creal32_T, 2U> xw;
  array<creal32_T, 1U> b_x;
  array<double, 2U> y;
  array<double, 1U> f;
  array<float, 2U> tempT;
  double hopSize;
  double nCol;
  float xtmp_re;
  int iv[2];
  int b_i1;
  int bcoef;
  int csz_idx_0;
  int i;
  int i1;
  int i2;
  int k;
  int offset;
  int vspread;
  bool exitg1;
  bool p;
  validateattributes(varargin_3);
  validateattributes(static_cast<double>(varargin_3.size(0)));
  validateattributes(varargin_5, static_cast<double>(varargin_3.size(0)));
  b_validateattributes(varargin_7, static_cast<double>(varargin_3.size(0)));
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= x.size(1) - 1)) {
    if ((!std::isinf(x[k].re)) && (!std::isinf(x[k].im)) &&
        ((!std::isnan(x[k].re)) && (!std::isnan(x[k].im)))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    i_rtErrorWithMessageID("X", bb_emlrtRTEI.fName, bb_emlrtRTEI.lineNo);
  }
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= x.size(1) - 1)) {
    if ((!std::isnan(x[k].re)) && (!std::isnan(x[k].im))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    h_rtErrorWithMessageID("X", ab_emlrtRTEI.fName, ab_emlrtRTEI.lineNo);
  }
  if (x.size(1) == 0) {
    g_rtErrorWithMessageID("X", y_emlrtRTEI.fName, y_emlrtRTEI.lineNo);
  }
  if (x.size(1) < 2) {
    s_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
  }
  if (varargin_3.size(0) > x.size(1)) {
    b_rtErrorWithMessageID(varargin_3.size(0), cb_emlrtRTEI.fName,
                           cb_emlrtRTEI.lineNo);
  }
  if (std::isinf(varargin_1) || std::isnan(varargin_1)) {
    i_rtErrorWithMessageID("sample rate", bb_emlrtRTEI.fName,
                           bb_emlrtRTEI.lineNo);
  }
  if (varargin_1 <= 0.0) {
    k_rtErrorWithMessageID("sample rate", eb_emlrtRTEI.fName,
                           eb_emlrtRTEI.lineNo);
  }
  obj.value.set_size(varargin_3.size(0));
  bcoef = varargin_3.size(0);
  for (i = 0; i < bcoef; i++) {
    obj.value[i] = static_cast<float>(varargin_3[i]);
  }
  hopSize = static_cast<double>(varargin_3.size(0)) - varargin_5;
  nCol = std::trunc((static_cast<double>(x.size(1)) - varargin_5) / hopSize);
  xin.set_size(varargin_3.size(0), xin.size(1));
  if (!(nCol >= 0.0)) {
    rtNonNegativeError(nCol, e_emlrtDCI);
  }
  if (nCol != static_cast<int>(nCol)) {
    rtIntegerError(nCol, d_emlrtDCI);
  }
  i = static_cast<int>(nCol);
  xin.set_size(xin.size(0), static_cast<int>(nCol));
  if (nCol != static_cast<int>(nCol)) {
    rtIntegerError(nCol, h_emlrtDCI);
  }
  bcoef = varargin_3.size(0) * static_cast<int>(nCol);
  for (i1 = 0; i1 < bcoef; i1++) {
    xin[i1].re = 0.0F;
    xin[i1].im = 0.0F;
  }
  if (nCol - 1.0 < 0.0) {
    y.set_size(y.size(0), 0);
  } else {
    y.set_size(1, static_cast<int>(nCol - 1.0) + 1);
    bcoef = static_cast<int>(nCol - 1.0);
    for (i1 = 0; i1 <= bcoef; i1++) {
      y[i1] = i1;
    }
  }
  for (vspread = 0; vspread < i; vspread++) {
    double d;
    nCol = hopSize * ((static_cast<double>(vspread) + 1.0) - 1.0);
    d = static_cast<double>(varargin_3.size(0)) + nCol;
    if (nCol + 1.0 > d) {
      i1 = 1;
      b_i1 = 0;
    } else {
      if (nCol + 1.0 != static_cast<int>(std::floor(nCol + 1.0))) {
        rtIntegerError(nCol + 1.0, b_emlrtDCI);
      }
      if ((static_cast<int>(nCol + 1.0) < 1) ||
          (static_cast<int>(nCol + 1.0) > x.size(1))) {
        rtDynamicBoundsError(static_cast<int>(nCol + 1.0), 1, x.size(1),
                             k_emlrtBCI);
      }
      i1 = static_cast<int>(nCol + 1.0);
      if (d != static_cast<int>(std::floor(d))) {
        rtIntegerError(d, c_emlrtDCI);
      }
      if ((static_cast<int>(d) < 1) || (static_cast<int>(d) > x.size(1))) {
        rtDynamicBoundsError(static_cast<int>(d), 1, x.size(1), l_emlrtBCI);
      }
      b_i1 = static_cast<int>(d);
    }
    if ((vspread + 1 < 1) || (vspread + 1 > xin.size(1))) {
      rtDynamicBoundsError(vspread + 1, 1, xin.size(1), m_emlrtBCI);
    }
    offset = b_i1 - i1;
    bcoef = offset + 1;
    rtSubAssignSizeCheck(xin.size(), 1, &bcoef, 1, d_emlrtECI);
    for (b_i1 = 0; b_i1 <= offset; b_i1++) {
      xin[b_i1 + xin.size(0) * vspread] = x[(i1 + b_i1) - 1];
    }
  }
  y.set_size(1, y.size(1));
  nCol = static_cast<double>(varargin_3.size(0)) / 2.0;
  bcoef = y.size(1) - 1;
  for (i = 0; i <= bcoef; i++) {
    y[i] = (y[i] * hopSize + nCol) / varargin_1;
  }
  if (xin.size(0) == 1) {
    csz_idx_0 = obj.value.size(0);
  } else if (obj.value.size(0) == 1) {
    csz_idx_0 = xin.size(0);
  } else if (obj.value.size(0) == xin.size(0)) {
    csz_idx_0 = obj.value.size(0);
  } else {
    r_rtErrorWithMessageID(x_emlrtRTEI.fName, x_emlrtRTEI.lineNo);
  }
  c.set_size(csz_idx_0, xin.size(1));
  if ((csz_idx_0 != 0) && (xin.size(1) != 0)) {
    bcoef = (xin.size(1) != 1);
    i = xin.size(1) - 1;
    offset = (obj.value.size(0) != 1);
    for (k = 0; k <= i; k++) {
      csz_idx_0 = bcoef * k;
      i1 = c.size(0) - 1;
      for (vspread = 0; vspread <= i1; vspread++) {
        xtmp_re = obj.value[offset * vspread];
        b_i1 = offset * vspread;
        c[vspread + c.size(0) * k].re =
            xtmp_re * xin[b_i1 + xin.size(0) * csz_idx_0].re;
        c[vspread + c.size(0) * k].im =
            xtmp_re * xin[b_i1 + xin.size(0) * csz_idx_0].im;
      }
    }
  }
  if (!(varargin_7 >= 0.0)) {
    rtNonNegativeError(varargin_7, g_emlrtDCI);
  }
  i = static_cast<int>(std::floor(varargin_7));
  if (varargin_7 != i) {
    rtIntegerError(varargin_7, f_emlrtDCI);
  }
  vspread = static_cast<int>(varargin_7);
  xw.set_size(vspread, c.size(1));
  if (vspread != i) {
    rtIntegerError(varargin_7, i_emlrtDCI);
  }
  bcoef = vspread * c.size(1);
  for (i = 0; i < bcoef; i++) {
    xw[i].re = 0.0F;
    xw[i].im = 0.0F;
  }
  if (c.size(0) > vspread) {
    i = c.size(1);
    for (i2 = 0; i2 < i; i2++) {
      if (i2 + 1 > c.size(1)) {
        rtDynamicBoundsError(i2 + 1, 1, c.size(1), e_emlrtBCI);
      }
      bcoef = c.size(0);
      b_x.set_size(c.size(0));
      for (i1 = 0; i1 < bcoef; i1++) {
        b_x[i1] = c[i1 + c.size(0) * i2];
      }
      if (!(varargin_7 >= 1.0)) {
        c_rtErrorWithMessageID(1, w_emlrtRTEI.fName, w_emlrtRTEI.lineNo);
      }
      if (c.size(0) == 1) {
        xin.set_size(1, vspread);
        for (i1 = 0; i1 < vspread; i1++) {
          xin[i1].re = 0.0F;
          xin[i1].im = 0.0F;
        }
      } else {
        xin.set_size(vspread, 1);
        for (i1 = 0; i1 < vspread; i1++) {
          xin[i1].re = 0.0F;
          xin[i1].im = 0.0F;
        }
      }
      i1 = static_cast<int>(static_cast<unsigned int>(c.size(0)) /
                            static_cast<unsigned int>(varargin_7));
      offset = i1 * vspread;
      bcoef = c.size(0) - offset;
      if (bcoef > 2147483646) {
        check_forloop_overflow_error();
      }
      for (k = 0; k < bcoef; k++) {
        b_i1 = xin.size(0) * xin.size(1);
        if ((k + 1 < 1) || (k + 1 > b_i1)) {
          rtDynamicBoundsError(k + 1, 1, b_i1, q_emlrtBCI);
        }
        csz_idx_0 = (offset + k) + 1;
        p = ((csz_idx_0 < 1) || (csz_idx_0 > c.size(0)));
        if (p) {
          rtDynamicBoundsError(csz_idx_0, 1, c.size(0), p_emlrtBCI);
        }
        xin[k].re = b_x[csz_idx_0 - 1].re;
        if (k + 1 > b_i1) {
          rtDynamicBoundsError(k + 1, 1, b_i1, q_emlrtBCI);
        }
        xin[k].im = b_x[csz_idx_0 - 1].im;
      }
      b_i1 = bcoef + 1;
      for (k = b_i1; k <= vspread; k++) {
        csz_idx_0 = xin.size(0) * xin.size(1);
        if ((k < 1) || (k > csz_idx_0)) {
          rtDynamicBoundsError(k, 1, csz_idx_0, r_emlrtBCI);
        }
        xin[k - 1].re = 0.0F;
        if (k > csz_idx_0) {
          rtDynamicBoundsError(k, 1, csz_idx_0, r_emlrtBCI);
        }
        xin[k - 1].im = 0.0F;
      }
      if (i1 > 2147483646) {
        check_forloop_overflow_error();
      }
      for (bcoef = 0; bcoef < i1; bcoef++) {
        offset = bcoef * vspread;
        for (k = 0; k < vspread; k++) {
          b_i1 = xin.size(0) * xin.size(1);
          if (k + 1 > b_i1) {
            rtDynamicBoundsError(k + 1, 1, b_i1, u_emlrtBCI);
          }
          csz_idx_0 = (offset + k) + 1;
          p = ((csz_idx_0 < 1) || (csz_idx_0 > c.size(0)));
          if (p) {
            rtDynamicBoundsError(csz_idx_0, 1, c.size(0), t_emlrtBCI);
          }
          xin[k].re = xin[k].re + b_x[csz_idx_0 - 1].re;
          if (k + 1 > b_i1) {
            rtDynamicBoundsError(k + 1, 1, b_i1, s_emlrtBCI);
          }
          xin[k].im = xin[k].im + b_x[csz_idx_0 - 1].im;
        }
      }
      if (i2 + 1 > xw.size(1)) {
        rtDynamicBoundsError(i2 + 1, 1, xw.size(1), f_emlrtBCI);
      }
      bcoef = xin.size(0) * xin.size(1);
      rtSubAssignSizeCheck(xw.size(), 1, &bcoef, 1, c_emlrtECI);
      for (i1 = 0; i1 < bcoef; i1++) {
        xw[i1 + xw.size(0) * i2] = xin[i1];
      }
    }
  } else {
    xw.set_size(c.size(0), c.size(1));
    bcoef = c.size(0) * c.size(1);
    for (i = 0; i < bcoef; i++) {
      xw[i] = c[i];
    }
  }
  fft(xw, varargin_7, varargout_1);
  psdfreqvec(varargin_7, varargin_1, f);
  if (signalwavelet::internal::iseven(
          static_cast<double>(varargout_1.size(0)))) {
    circshift(varargout_1,
              static_cast<double>(varargout_1.size(0)) / 2.0 - 1.0);
  } else if (varargout_1.size(0) > 1) {
    csz_idx_0 =
        static_cast<int>(static_cast<unsigned int>(varargout_1.size(0)) >> 1) -
        1;
    offset = varargout_1.size(1) - 1;
    vspread = varargout_1.size(0);
    if ((csz_idx_0 + 1) << 1 == varargout_1.size(0)) {
      i2 = 1;
      if (varargout_1.size(1) > 2147483646) {
        check_forloop_overflow_error();
      }
      for (int b_i{0}; b_i <= offset; b_i++) {
        int ib;
        b_i1 = i2;
        i2 += vspread;
        ib = b_i1 + csz_idx_0;
        for (k = 0; k <= csz_idx_0; k++) {
          float xtmp_im;
          bcoef = (b_i1 + k) - 1;
          xtmp_re = varargout_1[bcoef].re;
          xtmp_im = varargout_1[bcoef].im;
          i = ib + k;
          varargout_1[bcoef] = varargout_1[i];
          varargout_1[i].re = xtmp_re;
          varargout_1[i].im = xtmp_im;
        }
      }
    } else {
      i2 = 1;
      if (varargout_1.size(1) > 2147483646) {
        check_forloop_overflow_error();
      }
      for (int b_i{0}; b_i <= offset; b_i++) {
        float xtmp_im;
        int ib;
        b_i1 = i2;
        i2 += vspread;
        ib = b_i1 + csz_idx_0;
        xtmp_re = varargout_1[ib].re;
        xtmp_im = varargout_1[ib].im;
        for (k = 0; k <= csz_idx_0; k++) {
          i = ib + k;
          i1 = (b_i1 + k) - 1;
          varargout_1[i] = varargout_1[i1];
          varargout_1[i1] = varargout_1[i + 1];
        }
        ib = (ib + csz_idx_0) + 1;
        varargout_1[ib].re = xtmp_re;
        varargout_1[ib].im = xtmp_im;
      }
    }
  }
  if (signalwavelet::internal::iseven(static_cast<double>(f.size(0)))) {
    nCol = static_cast<double>(f.size(0)) / 2.0;
    if (nCol != std::floor(nCol)) {
      rtIntegerError(nCol, k_emlrtDCI);
    }
    if ((static_cast<int>(nCol) < 1) || (static_cast<int>(nCol) > f.size(0))) {
      rtDynamicBoundsError(static_cast<int>(nCol), 1, f.size(0), o_emlrtBCI);
    }
    nCol = f[static_cast<int>(nCol) - 1];
    bcoef = f.size(0);
    for (i = 0; i < bcoef; i++) {
      f[i] = f[i] - nCol;
    }
  } else {
    nCol = (static_cast<double>(f.size(0)) + 1.0) / 2.0;
    if (nCol != std::floor(nCol)) {
      rtIntegerError(nCol, j_emlrtDCI);
    }
    if ((static_cast<int>(nCol) < 1) || (static_cast<int>(nCol) > f.size(0))) {
      rtDynamicBoundsError(static_cast<int>(nCol), 1, f.size(0), n_emlrtBCI);
    }
    nCol = f[static_cast<int>(nCol) - 1];
    bcoef = f.size(0);
    for (i = 0; i < bcoef; i++) {
      f[i] = f[i] - nCol;
    }
  }
  if (varargout_1.size(0) < 1) {
    bcoef = 0;
  } else {
    if (f.size(0) < 1) {
      rtDynamicBoundsError(1, 1, f.size(0), g_emlrtBCI);
    }
    if (varargout_1.size(0) > f.size(0)) {
      rtDynamicBoundsError(varargout_1.size(0), 1, f.size(0), h_emlrtBCI);
    }
    bcoef = varargout_1.size(0);
  }
  iv[0] = 1;
  iv[1] = bcoef;
  internal::indexShapeCheck(f.size(0), iv);
  varargout_2.set_size(bcoef);
  for (i = 0; i < bcoef; i++) {
    varargout_2[i] = static_cast<float>(f[i]);
  }
  if (varargout_1.size(1) < 1) {
    bcoef = 0;
  } else {
    if (y.size(1) < 1) {
      rtDynamicBoundsError(1, 1, y.size(1), i_emlrtBCI);
    }
    if (varargout_1.size(1) > y.size(1)) {
      rtDynamicBoundsError(varargout_1.size(1), 1, y.size(1), j_emlrtBCI);
    }
    bcoef = varargout_1.size(1);
  }
  tempT.set_size(1, bcoef);
  for (i = 0; i < bcoef; i++) {
    tempT[i] = static_cast<float>(y[i]);
  }
  varargout_3.set_size(tempT.size(1));
  bcoef = tempT.size(1);
  for (i = 0; i < bcoef; i++) {
    varargout_3[i] = tempT[i];
  }
}

void stft(const ::coder::array<creal_T, 2U> &x, double varargin_1,
          const ::coder::array<double, 1U> &varargin_3, double varargin_5,
          double varargin_7, ::coder::array<creal_T, 3U> &varargout_1,
          ::coder::array<double, 1U> &varargout_2,
          ::coder::array<double, 1U> &varargout_3)
{
  array<creal_T, 3U> c_xin;
  array<creal_T, 3U> xin;
  array<creal_T, 2U> b_wrappedData;
  array<creal_T, 2U> wrappedData;
  array<creal_T, 1U> b_x;
  array<double, 2U> y;
  array<double, 1U> b_f;
  array<double, 1U> f;
  double hopSize;
  double nCol;
  int d_xin[3];
  int b_xin[2];
  int b_bcoef;
  int bcoef;
  int csz_idx_0;
  int i;
  int i1;
  int i2;
  int i3;
  int iCol;
  int k;
  int loop_ub;
  int xin_tmp;
  bool exitg1;
  bool p;
  validateattributes(varargin_3);
  validateattributes(static_cast<double>(varargin_3.size(0)));
  validateattributes(varargin_5, static_cast<double>(varargin_3.size(0)));
  b_validateattributes(varargin_7, static_cast<double>(varargin_3.size(0)));
  p = true;
  loop_ub = x.size(0) * 100;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= loop_ub - 1)) {
    if ((!std::isinf(x[k].re)) && (!std::isinf(x[k].im)) &&
        ((!std::isnan(x[k].re)) && (!std::isnan(x[k].im)))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    i_rtErrorWithMessageID("X", bb_emlrtRTEI.fName, bb_emlrtRTEI.lineNo);
  }
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= loop_ub - 1)) {
    if ((!std::isnan(x[k].re)) && (!std::isnan(x[k].im))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    h_rtErrorWithMessageID("X", ab_emlrtRTEI.fName, ab_emlrtRTEI.lineNo);
  }
  if (x.size(0) == 0) {
    g_rtErrorWithMessageID("X", y_emlrtRTEI.fName, y_emlrtRTEI.lineNo);
  }
  if (x.size(0) == 1) {
    wrappedData.set_size(100, 1);
    for (i = 0; i < 100; i++) {
      wrappedData[i] = x[i];
    }
  } else {
    wrappedData.set_size(x.size(0), 100);
    for (i = 0; i < loop_ub; i++) {
      wrappedData[i] = x[i];
    }
  }
  if (varargin_3.size(0) > wrappedData.size(0)) {
    b_rtErrorWithMessageID(varargin_3.size(0), cb_emlrtRTEI.fName,
                           cb_emlrtRTEI.lineNo);
  }
  if (std::isinf(varargin_1) || std::isnan(varargin_1)) {
    i_rtErrorWithMessageID("sample rate", bb_emlrtRTEI.fName,
                           bb_emlrtRTEI.lineNo);
  }
  if (varargin_1 <= 0.0) {
    k_rtErrorWithMessageID("sample rate", eb_emlrtRTEI.fName,
                           eb_emlrtRTEI.lineNo);
  }
  hopSize = static_cast<double>(varargin_3.size(0)) - varargin_5;
  nCol = std::trunc((static_cast<double>(wrappedData.size(0)) - varargin_5) /
                    hopSize);
  xin.set_size(varargin_3.size(0), xin.size(1), xin.size(2));
  if (!(nCol >= 0.0)) {
    rtNonNegativeError(nCol, e_emlrtDCI);
  }
  if (nCol != static_cast<int>(nCol)) {
    rtIntegerError(nCol, d_emlrtDCI);
  }
  i = static_cast<int>(nCol);
  xin.set_size(xin.size(0), static_cast<int>(nCol), wrappedData.size(1));
  if (nCol != static_cast<int>(nCol)) {
    rtIntegerError(nCol, h_emlrtDCI);
  }
  loop_ub = varargin_3.size(0) * static_cast<int>(nCol) * wrappedData.size(1);
  for (i1 = 0; i1 < loop_ub; i1++) {
    xin[i1].re = 0.0;
    xin[i1].im = 0.0;
  }
  if (nCol - 1.0 < 0.0) {
    y.set_size(y.size(0), 0);
  } else {
    y.set_size(1, static_cast<int>(nCol - 1.0) + 1);
    loop_ub = static_cast<int>(nCol - 1.0);
    for (i1 = 0; i1 <= loop_ub; i1++) {
      y[i1] = i1;
    }
  }
  if (static_cast<int>(nCol) - 1 >= 0) {
    b_xin[1] = wrappedData.size(1);
    bcoef = wrappedData.size(1);
  }
  for (iCol = 0; iCol < i; iCol++) {
    double d;
    nCol = hopSize * ((static_cast<double>(iCol) + 1.0) - 1.0);
    d = static_cast<double>(varargin_3.size(0)) + nCol;
    if (nCol + 1.0 > d) {
      i1 = 0;
      i2 = 0;
    } else {
      if (nCol + 1.0 != static_cast<int>(std::floor(nCol + 1.0))) {
        rtIntegerError(nCol + 1.0, b_emlrtDCI);
      }
      if ((static_cast<int>(nCol + 1.0) < 1) ||
          (static_cast<int>(nCol + 1.0) > wrappedData.size(0))) {
        rtDynamicBoundsError(static_cast<int>(nCol + 1.0), 1,
                             wrappedData.size(0), k_emlrtBCI);
      }
      i1 = static_cast<int>(nCol + 1.0) - 1;
      if (d != static_cast<int>(std::floor(d))) {
        rtIntegerError(d, c_emlrtDCI);
      }
      if ((static_cast<int>(d) < 1) ||
          (static_cast<int>(d) > wrappedData.size(0))) {
        rtDynamicBoundsError(static_cast<int>(d), 1, wrappedData.size(0),
                             l_emlrtBCI);
      }
      i2 = static_cast<int>(d);
    }
    if ((iCol + 1 < 1) || (iCol + 1 > xin.size(1))) {
      rtDynamicBoundsError(iCol + 1, 1, xin.size(1), m_emlrtBCI);
    }
    d_xin[0] = xin.size(0);
    d_xin[1] = 1;
    d_xin[2] = xin.size(2);
    xin_tmp = i2 - i1;
    b_xin[0] = xin_tmp;
    rtSubAssignSizeCheck(&d_xin[0], 3, &b_xin[0], 2, d_emlrtECI);
    b_wrappedData.set_size(xin_tmp, wrappedData.size(1));
    for (i2 = 0; i2 < bcoef; i2++) {
      for (i3 = 0; i3 < xin_tmp; i3++) {
        b_wrappedData[i3 + b_wrappedData.size(0) * i2] =
            wrappedData[(i1 + i3) + wrappedData.size(0) * i2];
      }
    }
    d_xin[0] = xin.size(0);
    loop_ub = xin.size(2);
    b_bcoef = d_xin[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      for (i2 = 0; i2 < b_bcoef; i2++) {
        xin[(i2 + xin.size(0) * iCol) + xin.size(0) * xin.size(1) * i1] =
            b_wrappedData[i2 + d_xin[0] * i1];
      }
    }
  }
  y.set_size(1, y.size(1));
  nCol = static_cast<double>(varargin_3.size(0)) / 2.0;
  loop_ub = y.size(1) - 1;
  for (i = 0; i <= loop_ub; i++) {
    y[i] = (y[i] * hopSize + nCol) / varargin_1;
  }
  if (xin.size(0) == 1) {
    csz_idx_0 = varargin_3.size(0);
  } else if (varargin_3.size(0) == 1) {
    csz_idx_0 = xin.size(0);
  } else if (varargin_3.size(0) == xin.size(0)) {
    csz_idx_0 = varargin_3.size(0);
  } else {
    r_rtErrorWithMessageID(x_emlrtRTEI.fName, x_emlrtRTEI.lineNo);
  }
  c_xin.set_size(csz_idx_0, xin.size(1), xin.size(2));
  if ((csz_idx_0 != 0) && (xin.size(1) != 0)) {
    bcoef = (xin.size(2) != 1);
    i = xin.size(2) - 1;
    b_bcoef = (xin.size(1) != 1);
    csz_idx_0 = (varargin_3.size(0) != 1);
    for (k = 0; k <= i; k++) {
      loop_ub = bcoef * k;
      i1 = c_xin.size(1) - 1;
      for (xin_tmp = 0; xin_tmp <= i1; xin_tmp++) {
        iCol = b_bcoef * xin_tmp;
        i2 = c_xin.size(0) - 1;
        for (int b_k{0}; b_k <= i2; b_k++) {
          nCol = varargin_3[csz_idx_0 * b_k];
          i3 = csz_idx_0 * b_k;
          c_xin[(b_k + c_xin.size(0) * xin_tmp) +
                c_xin.size(0) * c_xin.size(1) * k]
              .re = nCol * xin[(i3 + xin.size(0) * iCol) +
                               xin.size(0) * xin.size(1) * loop_ub]
                               .re;
          c_xin[(b_k + c_xin.size(0) * xin_tmp) +
                c_xin.size(0) * c_xin.size(1) * k]
              .im = nCol * xin[(i3 + xin.size(0) * iCol) +
                               xin.size(0) * xin.size(1) * loop_ub]
                               .im;
        }
      }
    }
  }
  if (!(varargin_7 >= 0.0)) {
    rtNonNegativeError(varargin_7, g_emlrtDCI);
  }
  i = static_cast<int>(std::floor(varargin_7));
  if (varargin_7 != i) {
    rtIntegerError(varargin_7, f_emlrtDCI);
  }
  csz_idx_0 = static_cast<int>(varargin_7);
  xin.set_size(csz_idx_0, c_xin.size(1), c_xin.size(2));
  if (csz_idx_0 != i) {
    rtIntegerError(varargin_7, i_emlrtDCI);
  }
  loop_ub = csz_idx_0 * c_xin.size(1) * c_xin.size(2);
  for (i = 0; i < loop_ub; i++) {
    xin[i].re = 0.0;
    xin[i].im = 0.0;
  }
  if (c_xin.size(0) > csz_idx_0) {
    i = static_cast<int>(static_cast<double>(c_xin.size(1)) *
                         static_cast<double>(c_xin.size(2)));
    for (iCol = 0; iCol < i; iCol++) {
      loop_ub = c_xin.size(0);
      b_xin[0] = c_xin.size(0);
      xin_tmp = c_xin.size(1) * c_xin.size(2);
      if ((static_cast<int>(static_cast<unsigned int>(iCol) + 1U) < 1) ||
          (static_cast<int>(static_cast<unsigned int>(iCol) + 1U) > xin_tmp)) {
        rtDynamicBoundsError(
            static_cast<int>(static_cast<unsigned int>(iCol) + 1U), 1, xin_tmp,
            e_emlrtBCI);
      }
      b_x.set_size(c_xin.size(0));
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_x[i1] = c_xin[i1 + b_xin[0] * iCol];
      }
      if (!(varargin_7 >= 1.0)) {
        c_rtErrorWithMessageID(1, w_emlrtRTEI.fName, w_emlrtRTEI.lineNo);
      }
      if (c_xin.size(0) == 1) {
        wrappedData.set_size(1, csz_idx_0);
        for (i1 = 0; i1 < csz_idx_0; i1++) {
          wrappedData[i1].re = 0.0;
          wrappedData[i1].im = 0.0;
        }
      } else {
        wrappedData.set_size(csz_idx_0, 1);
        for (i1 = 0; i1 < csz_idx_0; i1++) {
          wrappedData[i1].re = 0.0;
          wrappedData[i1].im = 0.0;
        }
      }
      i1 = static_cast<int>(static_cast<unsigned int>(c_xin.size(0)) /
                            static_cast<unsigned int>(varargin_7));
      b_bcoef = i1 * csz_idx_0;
      bcoef = c_xin.size(0) - b_bcoef;
      if (bcoef > 2147483646) {
        check_forloop_overflow_error();
      }
      for (k = 0; k < bcoef; k++) {
        i2 = wrappedData.size(0) * wrappedData.size(1);
        if ((k + 1 < 1) || (k + 1 > i2)) {
          rtDynamicBoundsError(k + 1, 1, i2, q_emlrtBCI);
        }
        i3 = (b_bcoef + k) + 1;
        p = ((i3 < 1) || (i3 > c_xin.size(0)));
        if (p) {
          rtDynamicBoundsError(i3, 1, c_xin.size(0), p_emlrtBCI);
        }
        wrappedData[k].re = b_x[i3 - 1].re;
        if (k + 1 > i2) {
          rtDynamicBoundsError(k + 1, 1, i2, q_emlrtBCI);
        }
        wrappedData[k].im = b_x[i3 - 1].im;
      }
      i2 = bcoef + 1;
      for (k = i2; k <= csz_idx_0; k++) {
        i3 = wrappedData.size(0) * wrappedData.size(1);
        if ((k < 1) || (k > i3)) {
          rtDynamicBoundsError(k, 1, i3, r_emlrtBCI);
        }
        wrappedData[k - 1].re = 0.0;
        if (k > i3) {
          rtDynamicBoundsError(k, 1, i3, r_emlrtBCI);
        }
        wrappedData[k - 1].im = 0.0;
      }
      if (i1 > 2147483646) {
        check_forloop_overflow_error();
      }
      for (loop_ub = 0; loop_ub < i1; loop_ub++) {
        b_bcoef = loop_ub * csz_idx_0;
        for (k = 0; k < csz_idx_0; k++) {
          i2 = wrappedData.size(0) * wrappedData.size(1);
          if (k + 1 > i2) {
            rtDynamicBoundsError(k + 1, 1, i2, u_emlrtBCI);
          }
          i3 = (b_bcoef + k) + 1;
          p = ((i3 < 1) || (i3 > c_xin.size(0)));
          if (p) {
            rtDynamicBoundsError(i3, 1, c_xin.size(0), t_emlrtBCI);
          }
          wrappedData[k].re = wrappedData[k].re + b_x[i3 - 1].re;
          if (k + 1 > i2) {
            rtDynamicBoundsError(k + 1, 1, i2, s_emlrtBCI);
          }
          wrappedData[k].im = wrappedData[k].im + b_x[i3 - 1].im;
        }
      }
      if ((iCol + 1 < 1) || (iCol + 1 > xin_tmp)) {
        rtDynamicBoundsError(iCol + 1, 1, xin_tmp, f_emlrtBCI);
      }
      b_bcoef = wrappedData.size(0) * wrappedData.size(1);
      rtSubAssignSizeCheck(xin.size(), 1, &b_bcoef, 1, c_emlrtECI);
      b_xin[0] = xin.size(0);
      for (i1 = 0; i1 < b_bcoef; i1++) {
        xin[i1 + b_xin[0] * iCol] = wrappedData[i1];
      }
    }
  } else {
    xin.set_size(c_xin.size(0), c_xin.size(1), c_xin.size(2));
    loop_ub = c_xin.size(0) * c_xin.size(1) * c_xin.size(2);
    for (i = 0; i < loop_ub; i++) {
      xin[i] = c_xin[i];
    }
  }
  fft(xin, varargin_7, varargout_1);
  psdfreqvec(varargin_7, varargin_1, f);
  b_signal::internal::stft::formatSTFTOutput(varargout_1, f, b_f);
  if (varargout_1.size(0) < 1) {
    loop_ub = 0;
  } else {
    if (b_f.size(0) < 1) {
      rtDynamicBoundsError(1, 1, b_f.size(0), g_emlrtBCI);
    }
    if (varargout_1.size(0) > b_f.size(0)) {
      rtDynamicBoundsError(varargout_1.size(0), 1, b_f.size(0), h_emlrtBCI);
    }
    loop_ub = varargout_1.size(0);
  }
  b_xin[0] = 1;
  b_xin[1] = loop_ub;
  internal::indexShapeCheck(b_f.size(0), b_xin);
  varargout_2.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    varargout_2[i] = b_f[i];
  }
  if (varargout_1.size(1) < 1) {
    loop_ub = 0;
  } else {
    if (y.size(1) < 1) {
      rtDynamicBoundsError(1, 1, y.size(1), i_emlrtBCI);
    }
    if (varargout_1.size(1) > y.size(1)) {
      rtDynamicBoundsError(varargout_1.size(1), 1, y.size(1), j_emlrtBCI);
    }
    loop_ub = varargout_1.size(1);
  }
  varargout_3.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    varargout_3[i] = y[i];
  }
}

} // namespace coder

// End of code generation (stft.cpp)
