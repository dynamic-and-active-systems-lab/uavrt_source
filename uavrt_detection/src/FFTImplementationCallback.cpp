//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// FFTImplementationCallback.cpp
//
// Code generation for function 'FFTImplementationCallback'
//

// Include files
#include "FFTImplementationCallback.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include <cmath>

// Variable Definitions
static rtDoubleCheckInfo n_emlrtDCI{
    19,               // lineNo
    34,               // colNo
    "allocFftOutput", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/+fft/"
    "allocFftOutput.m", // pName
    4                   // checkKind
};

// Function Definitions
namespace coder {
namespace internal {
namespace fft {
void FFTImplementationCallback::r2br_r2dit_trig_impl(
    const ::coder::array<creal32_T, 1U> &x, int unsigned_nRows,
    const ::coder::array<float, 2U> &costab,
    const ::coder::array<float, 2U> &sintab, ::coder::array<creal32_T, 1U> &y)
{
  float temp_im;
  float temp_re;
  float temp_re_tmp;
  float twid_re;
  int i;
  int i2;
  int iDelta;
  int iDelta2;
  int iheight;
  int iy;
  int j;
  int ju;
  int k;
  int nRowsD2;
  if (unsigned_nRows < 0) {
    rtNonNegativeError(static_cast<double>(unsigned_nRows), n_emlrtDCI);
  }
  y.set_size(unsigned_nRows);
  if (unsigned_nRows > x.size(0)) {
    y.set_size(unsigned_nRows);
    for (iy = 0; iy < unsigned_nRows; iy++) {
      y[iy].re = 0.0F;
      y[iy].im = 0.0F;
    }
  }
  j = x.size(0);
  if (j > unsigned_nRows) {
    j = unsigned_nRows;
  }
  i2 = unsigned_nRows - 2;
  nRowsD2 = unsigned_nRows / 2;
  k = nRowsD2 / 2;
  iy = 0;
  ju = 0;
  if (j - 1 > 2147483646) {
    check_forloop_overflow_error();
  }
  for (i = 0; i <= j - 2; i++) {
    bool tst;
    y[iy] = x[i];
    iy = unsigned_nRows;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }
    iy = ju;
  }
  y[iy] = x[j - 1];
  if (unsigned_nRows > 1) {
    for (i = 0; i <= i2; i += 2) {
      temp_re_tmp = y[i + 1].re;
      temp_im = y[i + 1].im;
      temp_re = y[i].re;
      twid_re = y[i].im;
      y[i + 1].re = temp_re - temp_re_tmp;
      y[i + 1].im = twid_re - temp_im;
      y[i].re = temp_re + temp_re_tmp;
      y[i].im = twid_re + temp_im;
    }
  }
  iDelta = 2;
  iDelta2 = 4;
  iheight = ((k - 1) << 2) + 1;
  while (k > 0) {
    for (i = 0; i < iheight; i += iDelta2) {
      iy = i + iDelta;
      temp_re = y[iy].re;
      temp_im = y[iy].im;
      y[iy].re = y[i].re - temp_re;
      y[iy].im = y[i].im - temp_im;
      y[i].re = y[i].re + temp_re;
      y[i].im = y[i].im + temp_im;
    }
    iy = 1;
    for (j = k; j < nRowsD2; j += k) {
      float twid_im;
      twid_re = costab[j];
      twid_im = sintab[j];
      i = iy;
      i2 = iy + iheight;
      while (i < i2) {
        ju = i + iDelta;
        temp_re_tmp = y[ju].im;
        temp_im = y[ju].re;
        temp_re = twid_re * temp_im - twid_im * temp_re_tmp;
        temp_im = twid_re * temp_re_tmp + twid_im * temp_im;
        y[ju].re = y[i].re - temp_re;
        y[ju].im = y[i].im - temp_im;
        y[i].re = y[i].re + temp_re;
        y[i].im = y[i].im + temp_im;
        i += iDelta2;
      }
      iy++;
    }
    k /= 2;
    iDelta = iDelta2;
    iDelta2 += iDelta2;
    iheight -= iDelta;
  }
}

void FFTImplementationCallback::dobluesteinfft(
    const ::coder::array<creal32_T, 2U> &x, int n2blue, int nfft,
    const ::coder::array<float, 2U> &costab,
    const ::coder::array<float, 2U> &sintab,
    const ::coder::array<float, 2U> &sintabinv,
    ::coder::array<creal32_T, 2U> &y)
{
  array<creal32_T, 1U> fv;
  array<creal32_T, 1U> fy;
  array<creal32_T, 1U> r;
  array<creal32_T, 1U> wwc;
  float nt_im;
  int iDelta;
  int k;
  int nChan;
  int nInt2;
  int nInt2m1;
  int rt;
  int xidx;
  nChan = x.size(1);
  nInt2m1 = (nfft + nfft) - 2;
  if (nInt2m1 + 1 < 0) {
    rtNonNegativeError(static_cast<double>(nInt2m1 + 1), o_emlrtDCI);
  }
  wwc.set_size(nInt2m1 + 1);
  rt = 0;
  wwc[nfft - 1].re = 1.0F;
  wwc[nfft - 1].im = 0.0F;
  nInt2 = nfft << 1;
  if (nfft - 1 > 2147483646) {
    check_forloop_overflow_error();
  }
  for (k = 0; k <= nfft - 2; k++) {
    xidx = ((k + 1) << 1) - 1;
    if (nInt2 - rt <= xidx) {
      rt += xidx - nInt2;
    } else {
      rt += xidx;
    }
    nt_im = -3.14159274F * static_cast<float>(rt) / static_cast<float>(nfft);
    iDelta = (nfft - k) - 2;
    wwc[iDelta].re = std::cos(nt_im);
    wwc[iDelta].im = -std::sin(nt_im);
  }
  if ((nInt2m1 >= nfft) && (nfft < -2147483647)) {
    check_forloop_overflow_error();
  }
  for (k = nInt2m1; k >= nfft; k--) {
    wwc[k] = wwc[nInt2m1 - k];
  }
  if (nfft < 0) {
    rtNonNegativeError(static_cast<double>(nfft), n_emlrtDCI);
  }
  y.set_size(nfft, x.size(1));
  if (nfft > x.size(0)) {
    y.set_size(nfft, x.size(1));
    xidx = nfft * x.size(1);
    for (iDelta = 0; iDelta < xidx; iDelta++) {
      y[iDelta].re = 0.0F;
      y[iDelta].im = 0.0F;
    }
  }
  if (x.size(1) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int chan{0}; chan < nChan; chan++) {
    float nt_re;
    float nt_re_tmp;
    float re_tmp;
    float twid_im;
    float twid_re;
    int i;
    int iDelta2;
    int iheight;
    int nRowsD2;
    r.set_size(nfft);
    if (nfft > x.size(0)) {
      r.set_size(nfft);
      for (iDelta = 0; iDelta < nfft; iDelta++) {
        r[iDelta].re = 0.0F;
        r[iDelta].im = 0.0F;
      }
    }
    nInt2m1 = x.size(0);
    if (nfft <= nInt2m1) {
      nInt2m1 = nfft;
    }
    xidx = chan * x.size(0);
    if (nInt2m1 > 2147483646) {
      check_forloop_overflow_error();
    }
    for (k = 0; k < nInt2m1; k++) {
      rt = (nfft + k) - 1;
      nt_re = wwc[rt].re;
      nt_im = wwc[rt].im;
      iDelta = xidx + k;
      twid_im = x[iDelta].im;
      re_tmp = x[iDelta].re;
      r[k].re = nt_re * re_tmp + nt_im * twid_im;
      r[k].im = nt_re * twid_im - nt_im * re_tmp;
    }
    xidx = nInt2m1 + 1;
    if ((nInt2m1 + 1 <= nfft) && (nfft > 2147483646)) {
      check_forloop_overflow_error();
    }
    for (k = xidx; k <= nfft; k++) {
      r[k - 1].re = 0.0F;
      r[k - 1].im = 0.0F;
    }
    if (n2blue < 0) {
      rtNonNegativeError(static_cast<double>(n2blue), n_emlrtDCI);
    }
    fy.set_size(n2blue);
    if (n2blue > r.size(0)) {
      fy.set_size(n2blue);
      for (iDelta = 0; iDelta < n2blue; iDelta++) {
        fy[iDelta].re = 0.0F;
        fy[iDelta].im = 0.0F;
      }
    }
    rt = r.size(0);
    if (rt > n2blue) {
      rt = n2blue;
    }
    nInt2 = n2blue - 2;
    nRowsD2 = n2blue / 2;
    k = nRowsD2 / 2;
    nInt2m1 = 0;
    xidx = 0;
    if (rt - 1 > 2147483646) {
      check_forloop_overflow_error();
    }
    for (i = 0; i <= rt - 2; i++) {
      bool tst;
      fy[nInt2m1] = r[i];
      nInt2m1 = n2blue;
      tst = true;
      while (tst) {
        nInt2m1 >>= 1;
        xidx ^= nInt2m1;
        tst = ((xidx & nInt2m1) == 0);
      }
      nInt2m1 = xidx;
    }
    fy[nInt2m1] = r[rt - 1];
    if (n2blue > 1) {
      for (i = 0; i <= nInt2; i += 2) {
        nt_re_tmp = fy[i + 1].re;
        nt_im = fy[i + 1].im;
        re_tmp = fy[i].re;
        twid_re = fy[i].im;
        fy[i + 1].re = re_tmp - nt_re_tmp;
        fy[i + 1].im = twid_re - nt_im;
        fy[i].re = re_tmp + nt_re_tmp;
        fy[i].im = twid_re + nt_im;
      }
    }
    iDelta = 2;
    iDelta2 = 4;
    iheight = ((k - 1) << 2) + 1;
    while (k > 0) {
      for (i = 0; i < iheight; i += iDelta2) {
        rt = i + iDelta;
        nt_re = fy[rt].re;
        nt_im = fy[rt].im;
        fy[rt].re = fy[i].re - nt_re;
        fy[rt].im = fy[i].im - nt_im;
        fy[i].re = fy[i].re + nt_re;
        fy[i].im = fy[i].im + nt_im;
      }
      nInt2m1 = 1;
      for (rt = k; rt < nRowsD2; rt += k) {
        twid_re = costab[rt];
        twid_im = sintab[rt];
        i = nInt2m1;
        nInt2 = nInt2m1 + iheight;
        while (i < nInt2) {
          xidx = i + iDelta;
          nt_re_tmp = fy[xidx].im;
          nt_im = fy[xidx].re;
          nt_re = twid_re * nt_im - twid_im * nt_re_tmp;
          nt_im = twid_re * nt_re_tmp + twid_im * nt_im;
          fy[xidx].re = fy[i].re - nt_re;
          fy[xidx].im = fy[i].im - nt_im;
          fy[i].re = fy[i].re + nt_re;
          fy[i].im = fy[i].im + nt_im;
          i += iDelta2;
        }
        nInt2m1++;
      }
      k /= 2;
      iDelta = iDelta2;
      iDelta2 += iDelta2;
      iheight -= iDelta;
    }
    FFTImplementationCallback::r2br_r2dit_trig_impl(wwc, n2blue, costab, sintab,
                                                    fv);
    xidx = fy.size(0);
    for (iDelta = 0; iDelta < xidx; iDelta++) {
      re_tmp = fy[iDelta].re;
      nt_im = fv[iDelta].im;
      twid_re = fy[iDelta].im;
      twid_im = fv[iDelta].re;
      fy[iDelta].re = re_tmp * twid_im - twid_re * nt_im;
      fy[iDelta].im = re_tmp * nt_im + twid_re * twid_im;
    }
    FFTImplementationCallback::r2br_r2dit_trig_impl(fy, n2blue, costab,
                                                    sintabinv, fv);
    if (fv.size(0) > 1) {
      nt_im = 1.0F / static_cast<float>(fv.size(0));
      xidx = fv.size(0);
      for (iDelta = 0; iDelta < xidx; iDelta++) {
        fv[iDelta].re = nt_im * fv[iDelta].re;
        fv[iDelta].im = nt_im * fv[iDelta].im;
      }
    }
    xidx = static_cast<int>(static_cast<float>(nfft));
    nInt2m1 = wwc.size(0);
    if ((static_cast<int>(static_cast<float>(nfft)) <= wwc.size(0)) &&
        (wwc.size(0) > 2147483646)) {
      check_forloop_overflow_error();
    }
    for (k = xidx; k <= nInt2m1; k++) {
      twid_im = wwc[k - 1].re;
      re_tmp = fv[k - 1].im;
      nt_im = wwc[k - 1].im;
      twid_re = fv[k - 1].re;
      iDelta = k - static_cast<int>(static_cast<float>(nfft));
      r[iDelta].re = twid_im * twid_re + nt_im * re_tmp;
      r[iDelta].im = twid_im * re_tmp - nt_im * twid_re;
    }
    xidx = r.size(0);
    for (iDelta = 0; iDelta < xidx; iDelta++) {
      y[iDelta + y.size(0) * chan] = r[iDelta];
    }
  }
}

void FFTImplementationCallback::dobluesteinfft(
    const ::coder::array<creal_T, 3U> &x, int n2blue, int nfft,
    const ::coder::array<double, 2U> &costab,
    const ::coder::array<double, 2U> &sintab,
    const ::coder::array<double, 2U> &sintabinv, ::coder::array<creal_T, 3U> &y)
{
  array<creal_T, 1U> fv;
  array<creal_T, 1U> fy;
  array<creal_T, 1U> r;
  array<creal_T, 1U> wwc;
  double nt_im;
  int a;
  int b;
  int b_y;
  int i;
  int minNrowsNx;
  int nChan;
  int nInt2;
  int nInt2m1;
  int rt;
  bool b_overflow;
  bool c_overflow;
  bool overflow;
  nChan = x.size(1) * x.size(2);
  nInt2m1 = (nfft + nfft) - 2;
  if (nInt2m1 + 1 < 0) {
    rtNonNegativeError(static_cast<double>(nInt2m1 + 1), o_emlrtDCI);
  }
  wwc.set_size(nInt2m1 + 1);
  rt = 0;
  wwc[nfft - 1].re = 1.0;
  wwc[nfft - 1].im = 0.0;
  nInt2 = nfft << 1;
  if (nfft - 1 > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int k{0}; k <= nfft - 2; k++) {
    b_y = ((k + 1) << 1) - 1;
    if (nInt2 - rt <= b_y) {
      rt += b_y - nInt2;
    } else {
      rt += b_y;
    }
    nt_im = -3.1415926535897931 * static_cast<double>(rt) /
            static_cast<double>(nfft);
    i = (nfft - k) - 2;
    wwc[i].re = std::cos(nt_im);
    wwc[i].im = -std::sin(nt_im);
  }
  if ((nInt2m1 >= nfft) && (nfft < -2147483647)) {
    check_forloop_overflow_error();
  }
  for (int k{nInt2m1}; k >= nfft; k--) {
    wwc[k] = wwc[nInt2m1 - k];
  }
  if (nfft < 0) {
    rtNonNegativeError(static_cast<double>(nfft), n_emlrtDCI);
  }
  y.set_size(nfft, x.size(1), x.size(2));
  if (nfft > x.size(0)) {
    y.set_size(nfft, x.size(1), x.size(2));
    b_y = nfft * x.size(1) * x.size(2);
    for (i = 0; i < b_y; i++) {
      y[i].re = 0.0;
      y[i].im = 0.0;
    }
  }
  if (nChan > 2147483646) {
    check_forloop_overflow_error();
  }
  if (nChan - 1 >= 0) {
    minNrowsNx = x.size(0);
    if (nfft <= minNrowsNx) {
      minNrowsNx = nfft;
    }
    overflow = (minNrowsNx > 2147483646);
    a = minNrowsNx + 1;
    b_overflow = ((minNrowsNx + 1 <= nfft) && (nfft > 2147483646));
    b = wwc.size(0);
    c_overflow = ((nfft <= wwc.size(0)) && (wwc.size(0) > 2147483646));
  }
  for (rt = 0; rt < nChan; rt++) {
    double b_re_tmp;
    double nt_re;
    double re_tmp;
    r.set_size(nfft);
    if (nfft > x.size(0)) {
      r.set_size(nfft);
      for (i = 0; i < nfft; i++) {
        r[i].re = 0.0;
        r[i].im = 0.0;
      }
    }
    nInt2m1 = rt * x.size(0);
    if (overflow) {
      check_forloop_overflow_error();
    }
    for (int k{0}; k < minNrowsNx; k++) {
      b_y = (nfft + k) - 1;
      nt_re = wwc[b_y].re;
      nt_im = wwc[b_y].im;
      i = nInt2m1 + k;
      re_tmp = x[i].im;
      b_re_tmp = x[i].re;
      r[k].re = nt_re * b_re_tmp + nt_im * re_tmp;
      r[k].im = nt_re * re_tmp - nt_im * b_re_tmp;
    }
    if (b_overflow) {
      check_forloop_overflow_error();
    }
    for (int k{a}; k <= nfft; k++) {
      r[k - 1].re = 0.0;
      r[k - 1].im = 0.0;
    }
    FFTImplementationCallback::r2br_r2dit_trig_impl(r, n2blue, costab, sintab,
                                                    fy);
    FFTImplementationCallback::r2br_r2dit_trig_impl(wwc, n2blue, costab, sintab,
                                                    fv);
    b_y = fy.size(0);
    for (i = 0; i < b_y; i++) {
      nt_re = fy[i].re;
      nt_im = fv[i].im;
      re_tmp = fy[i].im;
      b_re_tmp = fv[i].re;
      fy[i].re = nt_re * b_re_tmp - re_tmp * nt_im;
      fy[i].im = nt_re * nt_im + re_tmp * b_re_tmp;
    }
    FFTImplementationCallback::r2br_r2dit_trig_impl(fy, n2blue, costab,
                                                    sintabinv, fv);
    if (fv.size(0) > 1) {
      nt_re = 1.0 / static_cast<double>(fv.size(0));
      b_y = fv.size(0);
      for (i = 0; i < b_y; i++) {
        fv[i].re = nt_re * fv[i].re;
        fv[i].im = nt_re * fv[i].im;
      }
    }
    if (c_overflow) {
      check_forloop_overflow_error();
    }
    for (int k{nfft}; k <= b; k++) {
      re_tmp = wwc[k - 1].re;
      b_re_tmp = fv[k - 1].im;
      nt_re = wwc[k - 1].im;
      nt_im = fv[k - 1].re;
      i = k - nfft;
      r[i].re = re_tmp * nt_im + nt_re * b_re_tmp;
      r[i].im = re_tmp * b_re_tmp - nt_re * nt_im;
    }
    nInt2m1 = y.size(0);
    b_y = r.size(0);
    for (i = 0; i < b_y; i++) {
      y[i + nInt2m1 * rt] = r[i];
    }
  }
}

void FFTImplementationCallback::generate_twiddle_tables(
    int nRows, bool useRadix2, ::coder::array<double, 2U> &costab,
    ::coder::array<double, 2U> &sintab, ::coder::array<double, 2U> &sintabinv)
{
  array<double, 2U> costab1q;
  double e;
  int i;
  int n;
  int nd2;
  e = 6.2831853071795862 / static_cast<double>(nRows);
  n = nRows / 2 / 2;
  costab1q.set_size(1, costab1q.size(1));
  if (n + 1 < 0) {
    rtNonNegativeError(static_cast<double>(n) + 1.0, m_emlrtDCI);
  }
  costab1q.set_size(costab1q.size(0), n + 1);
  costab1q[0] = 1.0;
  nd2 = n / 2 - 1;
  for (int k{0}; k <= nd2; k++) {
    costab1q[k + 1] = std::cos(e * (static_cast<double>(k) + 1.0));
  }
  i = nd2 + 2;
  nd2 = n - 1;
  for (int k{i}; k <= nd2; k++) {
    costab1q[k] = std::sin(e * static_cast<double>(n - k));
  }
  costab1q[n] = 0.0;
  if (!useRadix2) {
    n = costab1q.size(1) - 1;
    nd2 = (costab1q.size(1) - 1) << 1;
    if (nd2 + 1 < 0) {
      rtNonNegativeError(-1.0, l_emlrtDCI);
    }
    costab.set_size(1, nd2 + 1);
    sintab.set_size(1, nd2 + 1);
    costab[0] = 1.0;
    sintab[0] = 0.0;
    sintabinv.set_size(1, nd2 + 1);
    for (int k{0}; k < n; k++) {
      sintabinv[k + 1] = costab1q[(n - k) - 1];
    }
    i = costab1q.size(1);
    for (int k{i}; k <= nd2; k++) {
      sintabinv[k] = costab1q[k - n];
    }
    for (int k{0}; k < n; k++) {
      costab[k + 1] = costab1q[k + 1];
      sintab[k + 1] = -costab1q[(n - k) - 1];
    }
    i = costab1q.size(1);
    for (int k{i}; k <= nd2; k++) {
      costab[k] = -costab1q[nd2 - k];
      sintab[k] = -costab1q[k - n];
    }
  } else {
    n = costab1q.size(1) - 1;
    nd2 = (costab1q.size(1) - 1) << 1;
    if (nd2 + 1 < 0) {
      rtNonNegativeError(-1.0, l_emlrtDCI);
    }
    costab.set_size(1, nd2 + 1);
    sintab.set_size(1, nd2 + 1);
    costab[0] = 1.0;
    sintab[0] = 0.0;
    for (int k{0}; k < n; k++) {
      costab[k + 1] = costab1q[k + 1];
      sintab[k + 1] = -costab1q[(n - k) - 1];
    }
    i = costab1q.size(1);
    for (int k{i}; k <= nd2; k++) {
      costab[k] = -costab1q[nd2 - k];
      sintab[k] = -costab1q[k - n];
    }
    sintabinv.set_size(1, 0);
  }
}

void FFTImplementationCallback::r2br_r2dit_trig_impl(
    const ::coder::array<creal_T, 1U> &x, int unsigned_nRows,
    const ::coder::array<double, 2U> &costab,
    const ::coder::array<double, 2U> &sintab, ::coder::array<creal_T, 1U> &y)
{
  double temp_im;
  double temp_re;
  double temp_re_tmp;
  double twid_re;
  int i;
  int i2;
  int iDelta;
  int iDelta2;
  int iheight;
  int iy;
  int j;
  int ju;
  int k;
  int nRowsD2;
  if (unsigned_nRows < 0) {
    rtNonNegativeError(static_cast<double>(unsigned_nRows), n_emlrtDCI);
  }
  y.set_size(unsigned_nRows);
  if (unsigned_nRows > x.size(0)) {
    y.set_size(unsigned_nRows);
    for (iy = 0; iy < unsigned_nRows; iy++) {
      y[iy].re = 0.0;
      y[iy].im = 0.0;
    }
  }
  j = x.size(0);
  if (j > unsigned_nRows) {
    j = unsigned_nRows;
  }
  i2 = unsigned_nRows - 2;
  nRowsD2 = unsigned_nRows / 2;
  k = nRowsD2 / 2;
  iy = 0;
  ju = 0;
  if (j - 1 > 2147483646) {
    check_forloop_overflow_error();
  }
  for (i = 0; i <= j - 2; i++) {
    bool tst;
    y[iy] = x[i];
    iy = unsigned_nRows;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }
    iy = ju;
  }
  y[iy] = x[j - 1];
  if (unsigned_nRows > 1) {
    for (i = 0; i <= i2; i += 2) {
      temp_re_tmp = y[i + 1].re;
      temp_im = y[i + 1].im;
      temp_re = y[i].re;
      twid_re = y[i].im;
      y[i + 1].re = temp_re - temp_re_tmp;
      y[i + 1].im = twid_re - temp_im;
      y[i].re = temp_re + temp_re_tmp;
      y[i].im = twid_re + temp_im;
    }
  }
  iDelta = 2;
  iDelta2 = 4;
  iheight = ((k - 1) << 2) + 1;
  while (k > 0) {
    for (i = 0; i < iheight; i += iDelta2) {
      iy = i + iDelta;
      temp_re = y[iy].re;
      temp_im = y[iy].im;
      y[iy].re = y[i].re - temp_re;
      y[iy].im = y[i].im - temp_im;
      y[i].re = y[i].re + temp_re;
      y[i].im = y[i].im + temp_im;
    }
    iy = 1;
    for (j = k; j < nRowsD2; j += k) {
      double twid_im;
      twid_re = costab[j];
      twid_im = sintab[j];
      i = iy;
      i2 = iy + iheight;
      while (i < i2) {
        ju = i + iDelta;
        temp_re_tmp = y[ju].im;
        temp_im = y[ju].re;
        temp_re = twid_re * temp_im - twid_im * temp_re_tmp;
        temp_im = twid_re * temp_re_tmp + twid_im * temp_im;
        y[ju].re = y[i].re - temp_re;
        y[ju].im = y[i].im - temp_im;
        y[i].re = y[i].re + temp_re;
        y[i].im = y[i].im + temp_im;
        i += iDelta2;
      }
      iy++;
    }
    k /= 2;
    iDelta = iDelta2;
    iDelta2 += iDelta2;
    iheight -= iDelta;
  }
}

} // namespace fft
} // namespace internal
} // namespace coder

// End of code generation (FFTImplementationCallback.cpp)
