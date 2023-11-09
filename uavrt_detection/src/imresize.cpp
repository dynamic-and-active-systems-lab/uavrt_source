//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// imresize.cpp
//
// Code generation for function 'imresize'
//

// Include files
#include "imresize.h"
#include "eml_int_forloop_overflow_check.h"
#include "mod.h"
#include "rt_nonfinite.h"
#include "sub2ind.h"
#include "sum.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <string>

// Function Declarations
namespace coder {
static void b_resizeAlongDim(const ::coder::array<double, 2U> &in_,
                             const ::coder::array<double, 2U> &weights,
                             const ::coder::array<int, 2U> &indices,
                             ::coder::array<double, 2U> &out_);

static void contributions(int in_length, double out_length, double scale,
                          double kernel_width,
                          ::coder::array<double, 2U> &weights,
                          ::coder::array<int, 2U> &indices);

static void resizeAlongDim(const ::coder::array<double, 2U> &in_,
                           const ::coder::array<double, 2U> &weights,
                           const ::coder::array<int, 2U> &indices,
                           ::coder::array<double, 2U> &out_);

} // namespace coder
static void lc_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void mc_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
namespace coder {
static void b_resizeAlongDim(const ::coder::array<double, 2U> &in_,
                             const ::coder::array<double, 2U> &weights,
                             const ::coder::array<int, 2U> &indices,
                             ::coder::array<double, 2U> &out_)
{
  int i;
  int out_length;
  int siz_idx_0;
  int siz_idx_1;
  out_length = weights.size(1);
  out_.set_size(in_.size(0), weights.size(1));
  i = in_.size(0);
  if (in_.size(0) - 1 >= 0) {
    siz_idx_0 = in_.size(0);
    siz_idx_1 = in_.size(1);
  }
  for (int inRInd{0}; inRInd < i; inRInd++) {
    if (inRInd + 1 > siz_idx_0) {
      cc_rtErrorWithMessageID(gc_emlrtRTEI.fName, gc_emlrtRTEI.lineNo);
    }
    if (siz_idx_1 < 1) {
      cc_rtErrorWithMessageID(gc_emlrtRTEI.fName, gc_emlrtRTEI.lineNo);
    }
    for (int outCInd{0}; outCInd < out_length; outCInd++) {
      double sumVal1;
      int iv[2];
      int i1;
      int ndx;
      sumVal1 = 0.0;
      //  Core - second dimension
      iv[0] = (*(int(*)[2])((::coder::array<double, 2U> *)&weights)->size())[0];
      iv[1] = (*(int(*)[2])((::coder::array<double, 2U> *)&weights)->size())[1];
      ndx = eml_sub2ind(iv, static_cast<double>(outCInd) + 1.0) - 1;
      i1 = weights.size(0);
      for (int k{0}; k < i1; k++) {
        int sumVal1_tmp;
        sumVal1_tmp = ndx + k;
        sumVal1 += weights[sumVal1_tmp] *
                   in_[inRInd + (indices[sumVal1_tmp] - 1) * in_.size(0)];
      }
      out_[inRInd + out_.size(0) * outCInd] = sumVal1;
    }
  }
}

static void contributions(int in_length, double out_length, double scale,
                          double kernel_width,
                          ::coder::array<double, 2U> &weights,
                          ::coder::array<int, 2U> &indices)
{
  static rtDoubleCheckInfo w_emlrtDCI{
      549,             // lineNo
      54,              // colNo
      "contributions", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/images/"
      "imresize.m", // pName
      4             // checkKind
  };
  static rtDoubleCheckInfo x_emlrtDCI{
      172,                        // lineNo
      28,                         // colNo
      "eml_signed_integer_colon", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/ops/colon.m", // pName
      4 // checkKind
  };
  array<double, 2U> absx;
  array<double, 2U> absx2;
  array<double, 2U> b_x;
  array<double, 2U> y;
  array<double, 1U> u;
  array<double, 1U> x;
  array<int, 2U> aux;
  array<int, 2U> b_indices;
  array<int, 2U> r;
  array<int, 1U> a;
  array<bool, 2U> copyCols;
  double b_kernel_width;
  int acoef;
  int bcoef;
  int csz_idx_0;
  int i;
  int i1;
  int loop_ub_tmp;
  int nx;
  int varargin_3;
  int yk;
  bool iscompatible;
  //  Contributions, using pixel indices
  if (scale < 1.0) {
    kernel_width /= scale;
  }
  if (std::isnan(out_length)) {
    y.set_size(1, 1);
    y[0] = rtNaN;
  } else if (out_length < 1.0) {
    y.set_size(1, 0);
  } else {
    y.set_size(1, static_cast<int>(out_length - 1.0) + 1);
    yk = static_cast<int>(out_length - 1.0);
    for (i = 0; i <= yk; i++) {
      y[i] = static_cast<double>(i) + 1.0;
    }
  }
  b_kernel_width = 0.5 * (1.0 - 1.0 / scale);
  u.set_size(y.size(1));
  yk = y.size(1);
  for (i = 0; i < yk; i++) {
    u[i] = y[i] / scale + b_kernel_width;
  }
  b_kernel_width = kernel_width / 2.0;
  x.set_size(u.size(0));
  yk = u.size(0);
  for (i = 0; i < yk; i++) {
    x[i] = u[i] - b_kernel_width;
  }
  nx = x.size(0);
  if (x.size(0) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int k{0}; k < nx; k++) {
    x[k] = std::floor(x[k]);
  }
  nx = static_cast<int>(std::ceil(kernel_width) + 2.0);
  if (nx - 1 < 0) {
    nx = 0;
  } else if (nx - 1 >= MAX_int32_T) {
    l_rtErrorWithMessageID(r_emlrtRTEI.fName, r_emlrtRTEI.lineNo);
  }
  aux.set_size(1, aux.size(1));
  if (nx < 0) {
    rtNonNegativeError(static_cast<double>(nx), x_emlrtDCI);
  }
  aux.set_size(aux.size(0), nx);
  if (nx > 0) {
    aux[0] = 0;
    yk = 0;
    if (nx > 2147483646) {
      check_forloop_overflow_error();
    }
    for (int k{2}; k <= nx; k++) {
      yk++;
      aux[k - 1] = yk;
    }
  }
  a.set_size(x.size(0));
  yk = x.size(0);
  for (i = 0; i < yk; i++) {
    a[i] = static_cast<int>(x[i]);
  }
  indices.set_size(a.size(0), aux.size(1));
  if ((a.size(0) != 0) && (aux.size(1) != 0)) {
    bcoef = (aux.size(1) != 1);
    i = aux.size(1) - 1;
    acoef = (a.size(0) != 1);
    for (int k{0}; k <= i; k++) {
      varargin_3 = bcoef * k;
      i1 = indices.size(0) - 1;
      for (int b_k{0}; b_k <= i1; b_k++) {
        indices[b_k + indices.size(0) * k] = a[acoef * b_k] + aux[varargin_3];
      }
    }
  }
  absx.set_size(indices.size(0), indices.size(1));
  loop_ub_tmp = indices.size(0) * indices.size(1);
  for (i = 0; i < loop_ub_tmp; i++) {
    absx[i] = indices[i];
  }
  if (absx.size(0) == 1) {
    csz_idx_0 = u.size(0);
  } else if (u.size(0) == 1) {
    csz_idx_0 = absx.size(0);
  } else if (u.size(0) == absx.size(0)) {
    csz_idx_0 = u.size(0);
  } else {
    r_rtErrorWithMessageID(x_emlrtRTEI.fName, x_emlrtRTEI.lineNo);
  }
  b_x.set_size(csz_idx_0, absx.size(1));
  if ((csz_idx_0 != 0) && (absx.size(1) != 0)) {
    bcoef = (absx.size(1) != 1);
    i = absx.size(1) - 1;
    nx = (u.size(0) != 1);
    for (int k{0}; k <= i; k++) {
      varargin_3 = bcoef * k;
      i1 = b_x.size(0) - 1;
      for (int b_k{0}; b_k <= i1; b_k++) {
        yk = nx * b_k;
        b_x[b_k + b_x.size(0) * k] =
            u[yk] - absx[yk + absx.size(0) * varargin_3];
      }
    }
  }
  if (scale < 1.0) {
    yk = b_x.size(0) * b_x.size(1);
    for (i = 0; i < yk; i++) {
      b_x[i] = scale * b_x[i];
    }
  }
  nx = b_x.size(0) * b_x.size(1);
  absx.set_size(b_x.size(0), b_x.size(1));
  if (nx > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int k{0}; k < nx; k++) {
    absx[k] = std::abs(b_x[k]);
  }
  absx2.set_size(absx.size(0), absx.size(1));
  nx = absx.size(0) * absx.size(1);
  if (nx > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int k{0}; k < nx; k++) {
    absx2[k] = absx[k] * absx[k];
  }
  weights.set_size(absx.size(0), absx.size(1));
  for (int k{0}; k < nx; k++) {
    weights[k] = rt_powd_snf(absx[k], 3.0);
  }
  for (i = 0; i < nx; i++) {
    absx2[i] = 2.5 * absx2[i];
  }
  for (i = 0; i < nx; i++) {
    weights[i] = ((1.5 * weights[i] - absx2[i]) + 1.0) *
                     static_cast<double>(absx[i] <= 1.0) +
                 (((-0.5 * weights[i] + absx2[i]) - 4.0 * absx[i]) + 2.0) *
                     static_cast<double>((absx[i] > 1.0) && (absx[i] <= 2.0));
  }
  if (scale < 1.0) {
    for (i = 0; i < nx; i++) {
      weights[i] = scale * weights[i];
    }
  }
  absx.set_size(weights.size(0), weights.size(1));
  for (i = 0; i < nx; i++) {
    absx[i] = weights[i];
  }
  sum(weights, u);
  iscompatible = true;
  if (u.size(0) == 1) {
    csz_idx_0 = weights.size(0);
  } else if (weights.size(0) == 1) {
    csz_idx_0 = u.size(0);
  } else if (weights.size(0) == u.size(0)) {
    csz_idx_0 = weights.size(0);
  } else {
    iscompatible = false;
    nx = u.size(0);
    csz_idx_0 = weights.size(0);
    if (nx <= csz_idx_0) {
      csz_idx_0 = nx;
    }
  }
  nx = weights.size(1);
  if (!iscompatible) {
    r_rtErrorWithMessageID(x_emlrtRTEI.fName, x_emlrtRTEI.lineNo);
  }
  weights.set_size(csz_idx_0, nx);
  if ((csz_idx_0 != 0) && (nx != 0)) {
    acoef = (absx.size(1) != 1);
    i = nx - 1;
    nx = (absx.size(0) != 1);
    bcoef = (u.size(0) != 1);
    for (int k{0}; k <= i; k++) {
      yk = acoef * k;
      i1 = weights.size(0) - 1;
      for (int b_k{0}; b_k <= i1; b_k++) {
        weights[b_k + weights.size(0) * k] =
            absx[nx * b_k + absx.size(0) * yk] / u[bcoef * b_k];
      }
    }
  }
  //  Create the auxiliary matrix:
  nx = in_length << 1;
  aux.set_size(1, aux.size(1));
  if (nx < 0) {
    rtNonNegativeError(static_cast<double>(nx), w_emlrtDCI);
  }
  aux.set_size(aux.size(0), nx);
  aux[0] = 1;
  aux[in_length] = in_length;
  if (in_length > 2147483646) {
    check_forloop_overflow_error();
  }
  for (bcoef = 2; bcoef <= in_length; bcoef++) {
    aux[bcoef - 1] = aux[bcoef - 2] + 1;
    yk = in_length + bcoef;
    aux[yk - 1] = aux[yk - 2] - 1;
  }
  //  Mirror the out-of-bounds indices using mod:
  for (bcoef = 0; bcoef < loop_ub_tmp; bcoef++) {
    indices[bcoef] = aux[static_cast<int>(b_mod(
        static_cast<double>(indices[bcoef]) - 1.0, static_cast<double>(nx)))];
  }
  copyCols.set_size(1, weights.size(1));
  yk = weights.size(1);
  for (i = 0; i < yk; i++) {
    copyCols[i] = false;
  }
  nx = weights.size(1);
  yk = 0;
  if (weights.size(1) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (bcoef = 0; bcoef < nx; bcoef++) {
    bool exitg1;
    varargin_3 = yk + weights.size(0);
    acoef = yk;
    yk = varargin_3;
    if ((acoef + 1 <= varargin_3) && (varargin_3 > 2147483646)) {
      check_forloop_overflow_error();
    }
    exitg1 = false;
    while ((!exitg1) && (acoef + 1 <= varargin_3)) {
      if ((weights[acoef] == 0.0) || std::isnan(weights[acoef])) {
        acoef++;
      } else {
        copyCols[bcoef] = true;
        exitg1 = true;
      }
    }
  }
  yk = copyCols.size(1) - 1;
  nx = 0;
  for (bcoef = 0; bcoef <= yk; bcoef++) {
    if (copyCols[bcoef]) {
      nx++;
    }
  }
  r.set_size(1, nx);
  nx = 0;
  for (bcoef = 0; bcoef <= yk; bcoef++) {
    if (copyCols[bcoef]) {
      r[nx] = bcoef;
      nx++;
    }
  }
  nx = weights.size(0);
  absx.set_size(r.size(1), weights.size(0));
  for (i = 0; i < nx; i++) {
    yk = r.size(1);
    for (i1 = 0; i1 < yk; i1++) {
      absx[i1 + absx.size(0) * i] = weights[i + weights.size(0) * r[i1]];
    }
  }
  weights.set_size(absx.size(0), absx.size(1));
  yk = absx.size(0) * absx.size(1);
  for (i = 0; i < yk; i++) {
    weights[i] = absx[i];
  }
  nx = indices.size(0);
  b_indices.set_size(r.size(1), indices.size(0));
  for (i = 0; i < nx; i++) {
    yk = r.size(1);
    for (i1 = 0; i1 < yk; i1++) {
      b_indices[i1 + b_indices.size(0) * i] =
          indices[i + indices.size(0) * r[i1]];
    }
  }
  indices.set_size(b_indices.size(0), b_indices.size(1));
  yk = b_indices.size(0) * b_indices.size(1);
  for (i = 0; i < yk; i++) {
    indices[i] = b_indices[i];
  }
}

static void resizeAlongDim(const ::coder::array<double, 2U> &in_,
                           const ::coder::array<double, 2U> &weights,
                           const ::coder::array<int, 2U> &indices,
                           ::coder::array<double, 2U> &out_)
{
  int i;
  int out_length;
  out_length = weights.size(1);
  out_.set_size(weights.size(1), in_.size(1));
  i = static_cast<int>(static_cast<double>(in_.size(0) * in_.size(1)) /
                       static_cast<double>(in_.size(0)));
  for (int inCInd{0}; inCInd < i; inCInd++) {
    for (int outRInd{0}; outRInd < out_length; outRInd++) {
      double sumVal1;
      int iv[2];
      int i1;
      int ndx;
      sumVal1 = 0.0;
      iv[0] = (*(int(*)[2])((::coder::array<double, 2U> *)&weights)->size())[0];
      iv[1] = (*(int(*)[2])((::coder::array<double, 2U> *)&weights)->size())[1];
      ndx = eml_sub2ind(iv, static_cast<double>(outRInd) + 1.0) - 1;
      //  Core - first dimension
      i1 = weights.size(0);
      for (int k{0}; k < i1; k++) {
        int sumVal1_tmp;
        sumVal1_tmp = ndx + k;
        sumVal1 += weights[sumVal1_tmp] *
                   in_[(indices[sumVal1_tmp] + in_.size(0) * inCInd) - 1];
      }
      out_[outRInd + out_.size(0) * inCInd] = sumVal1;
    }
  }
}

} // namespace coder
static void lc_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "OUTPUTSIZE must be a two-element vector of positive values.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

static void mc_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Specified output size cannot contain two NaNs.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

namespace coder {
void imresize(const ::coder::array<double, 2U> &Ain, const double varargin_1[2],
              ::coder::array<double, 2U> &Bout)
{
  static rtRunTimeErrorInfo
      vc_emlrtRTEI{
          324,        // lineNo
          5,          // colNo
          "imresize", // fName
          "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/images/"
          "imresize.m" // pName
      };
  static rtRunTimeErrorInfo
      wc_emlrtRTEI{
          319,        // lineNo
          5,          // colNo
          "imresize", // fName
          "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/images/"
          "imresize.m" // pName
      };
  array<double, 2U> APartialResize;
  array<double, 2U> weights;
  array<int, 2U> indices;
  double outputSize_idx_0;
  double outputSize_idx_1;
  double scale_idx_0;
  double scale_idx_1;
  int k;
  bool b[2];
  bool b_b_tmp;
  bool b_tmp;
  bool exitg1;
  bool y;
  if ((Ain.size(0) == 0) || (Ain.size(1) == 0)) {
    g_rtErrorWithMessageID("input number 1, A,", y_emlrtRTEI.fName,
                           y_emlrtRTEI.lineNo);
  }
  b_tmp = std::isnan(varargin_1[0]);
  b[0] = b_tmp;
  b_b_tmp = std::isnan(varargin_1[1]);
  b[1] = b_b_tmp;
  y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= 1)) {
    if (!b[k]) {
      y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (y) {
    lc_rtErrorWithMessageID(wc_emlrtRTEI.fName, wc_emlrtRTEI.lineNo);
  } else {
    b[0] = (varargin_1[0] <= 0.0);
    b[1] = (varargin_1[1] <= 0.0);
    y = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= 1)) {
      if (b[k]) {
        y = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (y) {
      lc_rtErrorWithMessageID(wc_emlrtRTEI.fName, wc_emlrtRTEI.lineNo);
    }
  }
  b[0] = b_tmp;
  b[1] = b_b_tmp;
  y = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= 1)) {
    if (!b[k]) {
      y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (y) {
    mc_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
  }
  if (b_tmp) {
    outputSize_idx_0 =
        std::ceil(varargin_1[1] * static_cast<double>(Ain.size(0)) /
                  static_cast<double>(Ain.size(1)));
    outputSize_idx_1 = std::ceil(varargin_1[1]);
    scale_idx_0 = outputSize_idx_1 / static_cast<double>(Ain.size(1));
    scale_idx_1 = outputSize_idx_1 / static_cast<double>(Ain.size(1));
  } else if (b_b_tmp) {
    outputSize_idx_0 = std::ceil(varargin_1[0]);
    outputSize_idx_1 =
        std::ceil(varargin_1[0] * static_cast<double>(Ain.size(1)) /
                  static_cast<double>(Ain.size(0)));
    scale_idx_0 = outputSize_idx_0 / static_cast<double>(Ain.size(0));
    scale_idx_1 = scale_idx_0;
  } else {
    outputSize_idx_0 = std::ceil(varargin_1[0]);
    outputSize_idx_1 = std::ceil(varargin_1[1]);
    scale_idx_0 = outputSize_idx_0 / static_cast<double>(Ain.size(0));
    scale_idx_1 = outputSize_idx_1 / static_cast<double>(Ain.size(1));
  }
  if (scale_idx_0 <= scale_idx_1) {
    //  Resize first dimension
    contributions(Ain.size(0), outputSize_idx_0, scale_idx_0, 4.0, weights,
                  indices);
    resizeAlongDim(Ain, weights, indices, APartialResize);
    //  Resize second dimension
    contributions(Ain.size(1), outputSize_idx_1, scale_idx_1, 4.0, weights,
                  indices);
    b_resizeAlongDim(APartialResize, weights, indices, Bout);
  } else {
    contributions(Ain.size(1), outputSize_idx_1, scale_idx_1, 4.0, weights,
                  indices);
    b_resizeAlongDim(Ain, weights, indices, APartialResize);
    //  Resize second dimension
    contributions(Ain.size(0), outputSize_idx_0, scale_idx_0, 4.0, weights,
                  indices);
    resizeAlongDim(APartialResize, weights, indices, Bout);
  }
}

} // namespace coder

// End of code generation (imresize.cpp)
