//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// fft.cpp
//
// Code generation for function 'fft'
//

// Include files
#include "fft.h"
#include "FFTImplementationCallback.h"
#include "eml_int_forloop_overflow_check.h"
#include "nextpow2.h"
#include "rt_nonfinite.h"
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

// Variable Definitions
static rtRunTimeErrorInfo fb_emlrtRTEI{
    52,    // lineNo
    35,    // colNo
    "fft", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/datafun/fft.m" // pName
};

static rtRunTimeErrorInfo gb_emlrtRTEI{
    48,    // lineNo
    35,    // colNo
    "fft", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/datafun/fft.m" // pName
};

static rtRunTimeErrorInfo hb_emlrtRTEI{
    37,    // lineNo
    31,    // colNo
    "fft", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/datafun/fft.m" // pName
};

static rtRunTimeErrorInfo ib_emlrtRTEI{
    417,                                        // lineNo
    17,                                         // colNo
    "FFTImplementationCallback/get_algo_sizes", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/shared/coder/coder/lib/+coder/"
    "+internal/FFTImplementationCallback.m" // pName
};

// Function Declarations
static void t_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void u_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
static void t_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Requested array exceeds the maximum possible variable size.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

static void u_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "FFT length must be a nonnegative integer scalar.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

namespace coder {
void fft(const ::coder::array<creal32_T, 2U> &x, double varargin_1,
         ::coder::array<creal32_T, 2U> &y)
{
  array<creal32_T, 1U> r;
  array<float, 2U> costab;
  array<float, 2U> costab1q;
  array<float, 2U> sintab;
  array<float, 2U> sintabinv;
  if (x.size(0) == 1) {
    v_rtErrorWithMessageID(hb_emlrtRTEI.fName, hb_emlrtRTEI.lineNo);
  }
  if ((!(varargin_1 >= 0.0)) || (!(varargin_1 == std::floor(varargin_1)))) {
    u_rtErrorWithMessageID(gb_emlrtRTEI.fName, gb_emlrtRTEI.lineNo);
  }
  if (!(varargin_1 <= 2.147483647E+9)) {
    t_rtErrorWithMessageID(fb_emlrtRTEI.fName, fb_emlrtRTEI.lineNo);
  }
  if ((x.size(0) == 0) || (x.size(1) == 0) ||
      (static_cast<int>(varargin_1) == 0)) {
    int nd2;
    y.set_size(static_cast<int>(varargin_1), x.size(1));
    nd2 = static_cast<int>(varargin_1) * x.size(1);
    for (int iDelta{0}; iDelta < nd2; iDelta++) {
      y[iDelta].re = 0.0F;
      y[iDelta].im = 0.0F;
    }
  } else {
    float temp_im;
    int iDelta;
    int ju;
    int k;
    int n;
    int nd2;
    int ySize_idx_0_tmp;
    bool useRadix2;
    ySize_idx_0_tmp = static_cast<int>(varargin_1);
    useRadix2 = ((static_cast<int>(varargin_1) > 0) &&
                 ((static_cast<int>(varargin_1) &
                   (static_cast<int>(varargin_1) - 1)) == 0));
    ju = 1;
    if (useRadix2) {
      nd2 = static_cast<int>(varargin_1);
    } else {
      if (static_cast<int>(varargin_1) > 0) {
        k = nextpow2(
            (static_cast<int>(varargin_1) + static_cast<int>(varargin_1)) - 1);
        if (k >= 0) {
          if (k <= 31) {
            ju = 1 << k;
          } else {
            ju = 0;
          }
        } else {
          ju = 0;
        }
      }
      nd2 = static_cast<int>(varargin_1) << 2;
      if (nd2 < 1) {
        nd2 = 1;
      }
      if (ju > nd2) {
        h_rtErrorWithMessageID(ib_emlrtRTEI.fName, ib_emlrtRTEI.lineNo);
      }
      nd2 = ju;
    }
    temp_im = 6.28318548F / static_cast<float>(nd2);
    n = nd2 / 2 / 2;
    costab1q.set_size(1, costab1q.size(1));
    if (n + 1 < 0) {
      rtNonNegativeError(static_cast<double>(n) + 1.0, m_emlrtDCI);
    }
    costab1q.set_size(costab1q.size(0), n + 1);
    costab1q[0] = 1.0F;
    nd2 = n / 2 - 1;
    for (k = 0; k <= nd2; k++) {
      costab1q[k + 1] = std::cos(temp_im * static_cast<float>(k + 1));
    }
    iDelta = nd2 + 2;
    nd2 = n - 1;
    for (k = iDelta; k <= nd2; k++) {
      costab1q[k] = std::sin(temp_im * static_cast<float>(n - k));
    }
    costab1q[n] = 0.0F;
    if (!useRadix2) {
      n = costab1q.size(1) - 1;
      nd2 = (costab1q.size(1) - 1) << 1;
      if (nd2 + 1 < 0) {
        rtNonNegativeError(-1.0, l_emlrtDCI);
      }
      costab.set_size(1, nd2 + 1);
      sintab.set_size(1, nd2 + 1);
      costab[0] = 1.0F;
      sintab[0] = 0.0F;
      sintabinv.set_size(1, nd2 + 1);
      for (k = 0; k < n; k++) {
        sintabinv[k + 1] = costab1q[(n - k) - 1];
      }
      iDelta = costab1q.size(1);
      for (k = iDelta; k <= nd2; k++) {
        sintabinv[k] = costab1q[k - n];
      }
      for (k = 0; k < n; k++) {
        costab[k + 1] = costab1q[k + 1];
        sintab[k + 1] = -costab1q[(n - k) - 1];
      }
      iDelta = costab1q.size(1);
      for (k = iDelta; k <= nd2; k++) {
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
      costab[0] = 1.0F;
      sintab[0] = 0.0F;
      for (k = 0; k < n; k++) {
        costab[k + 1] = costab1q[k + 1];
        sintab[k + 1] = -costab1q[(n - k) - 1];
      }
      iDelta = costab1q.size(1);
      for (k = iDelta; k <= nd2; k++) {
        costab[k] = -costab1q[nd2 - k];
        sintab[k] = -costab1q[k - n];
      }
      sintabinv.set_size(1, 0);
    }
    if (useRadix2) {
      int i2_tmp;
      int nChan;
      int nRowsD2;
      int nRowsD4;
      int u1;
      nChan = x.size(1);
      y.set_size(static_cast<int>(varargin_1), x.size(1));
      if (static_cast<int>(varargin_1) > x.size(0)) {
        y.set_size(static_cast<int>(varargin_1), x.size(1));
        nd2 = static_cast<int>(varargin_1) * x.size(1);
        for (iDelta = 0; iDelta < nd2; iDelta++) {
          y[iDelta].re = 0.0F;
          y[iDelta].im = 0.0F;
        }
      }
      if (x.size(1) > 2147483646) {
        check_forloop_overflow_error();
      }
      nd2 = x.size(0);
      u1 = static_cast<int>(varargin_1);
      if (nd2 <= u1) {
        u1 = nd2;
      }
      i2_tmp = static_cast<int>(varargin_1) - 2;
      nRowsD2 = static_cast<int>(varargin_1) / 2;
      nRowsD4 = nRowsD2 / 2;
      useRadix2 = (u1 - 1 > 2147483646);
      for (int chan{0}; chan < nChan; chan++) {
        float temp_re;
        float temp_re_tmp;
        float twid_re;
        int i;
        int iDelta2;
        int iheight;
        int ix;
        ix = chan * x.size(0);
        r.set_size(static_cast<int>(varargin_1));
        if (static_cast<int>(varargin_1) > x.size(0)) {
          r.set_size(static_cast<int>(varargin_1));
          for (iDelta = 0; iDelta < ySize_idx_0_tmp; iDelta++) {
            r[iDelta].re = 0.0F;
            r[iDelta].im = 0.0F;
          }
        }
        nd2 = 0;
        ju = 0;
        if (useRadix2) {
          check_forloop_overflow_error();
        }
        for (i = 0; i <= u1 - 2; i++) {
          bool tst;
          r[nd2] = x[ix + i];
          n = static_cast<int>(varargin_1);
          tst = true;
          while (tst) {
            n >>= 1;
            ju ^= n;
            tst = ((ju & n) == 0);
          }
          nd2 = ju;
        }
        ix = (ix + u1) - 1;
        r[nd2] = x[ix];
        if (static_cast<int>(varargin_1) > 1) {
          for (i = 0; i <= i2_tmp; i += 2) {
            temp_re_tmp = r[i + 1].re;
            temp_im = r[i + 1].im;
            temp_re = r[i].re;
            twid_re = r[i].im;
            r[i + 1].re = temp_re - temp_re_tmp;
            r[i + 1].im = twid_re - temp_im;
            r[i].re = temp_re + temp_re_tmp;
            r[i].im = twid_re + temp_im;
          }
        }
        iDelta = 2;
        iDelta2 = 4;
        k = nRowsD4;
        iheight = ((nRowsD4 - 1) << 2) + 1;
        while (k > 0) {
          for (i = 0; i < iheight; i += iDelta2) {
            nd2 = i + iDelta;
            temp_re = r[nd2].re;
            temp_im = r[nd2].im;
            r[nd2].re = r[i].re - temp_re;
            r[nd2].im = r[i].im - temp_im;
            r[i].re = r[i].re + temp_re;
            r[i].im = r[i].im + temp_im;
          }
          nd2 = 1;
          for (ju = k; ju < nRowsD2; ju += k) {
            float twid_im;
            twid_re = costab[ju];
            twid_im = sintab[ju];
            i = nd2;
            ix = nd2 + iheight;
            while (i < ix) {
              n = i + iDelta;
              temp_re_tmp = r[n].im;
              temp_im = r[n].re;
              temp_re = twid_re * temp_im - twid_im * temp_re_tmp;
              temp_im = twid_re * temp_re_tmp + twid_im * temp_im;
              r[n].re = r[i].re - temp_re;
              r[n].im = r[i].im - temp_im;
              r[i].re = r[i].re + temp_re;
              r[i].im = r[i].im + temp_im;
              i += iDelta2;
            }
            nd2++;
          }
          k /= 2;
          iDelta = iDelta2;
          iDelta2 += iDelta2;
          iheight -= iDelta;
        }
        nd2 = r.size(0);
        for (iDelta = 0; iDelta < nd2; iDelta++) {
          y[iDelta + y.size(0) * chan] = r[iDelta];
        }
      }
    } else {
      internal::fft::FFTImplementationCallback::dobluesteinfft(
          x, ju, static_cast<int>(varargin_1), costab, sintab, sintabinv, y);
    }
  }
}

void fft(const ::coder::array<creal_T, 2U> &x, ::coder::array<creal_T, 2U> &y)
{
  array<creal_T, 1U> fv;
  array<creal_T, 1U> fy;
  array<creal_T, 1U> r;
  array<creal_T, 1U> wwc;
  array<double, 2U> costab;
  array<double, 2U> sintab;
  array<double, 2U> sintabinv;
  int nfft;
  if (x.size(0) == 1) {
    v_rtErrorWithMessageID(hb_emlrtRTEI.fName, hb_emlrtRTEI.lineNo);
  }
  nfft = x.size(0);
  if ((x.size(0) == 0) || (x.size(1) == 0)) {
    int rt;
    y.set_size(x.size(0), x.size(1));
    rt = x.size(0) * x.size(1);
    for (int iheight{0}; iheight < rt; iheight++) {
      y[iheight].re = 0.0;
      y[iheight].im = 0.0;
    }
  } else {
    int iDelta2;
    int k;
    int rt;
    bool useRadix2;
    useRadix2 = ((x.size(0) & (x.size(0) - 1)) == 0);
    rt = x.size(0);
    iDelta2 = 1;
    if (!useRadix2) {
      if (rt > 0) {
        k = nextpow2((rt + rt) - 1);
        if (k >= 0) {
          if (k <= 31) {
            iDelta2 = 1 << k;
          } else {
            iDelta2 = 0;
          }
        } else {
          iDelta2 = 0;
        }
      }
      rt <<= 2;
      if (rt < 1) {
        rt = 1;
      }
      if (iDelta2 > rt) {
        h_rtErrorWithMessageID(ib_emlrtRTEI.fName, ib_emlrtRTEI.lineNo);
      }
      rt = iDelta2;
    }
    internal::fft::FFTImplementationCallback::generate_twiddle_tables(
        rt, useRadix2, costab, sintab, sintabinv);
    if (useRadix2) {
      int i2;
      int nChan;
      int nRowsD2;
      int nRowsD4;
      int sz_idx_0;
      int u1;
      nChan = x.size(1);
      y.set_size(x.size(0), x.size(1));
      if (x.size(1) > 2147483646) {
        check_forloop_overflow_error();
      }
      sz_idx_0 = x.size(0);
      rt = x.size(0);
      u1 = x.size(0);
      if (rt <= u1) {
        u1 = rt;
      }
      i2 = x.size(0) - 2;
      nRowsD2 = x.size(0) / 2;
      nRowsD4 = nRowsD2 / 2;
      for (int chan{0}; chan < nChan; chan++) {
        double nt_im;
        double nt_re_tmp;
        double twid_re;
        int i;
        int iDelta;
        int iheight;
        int nInt2;
        int nInt2m1;
        nInt2m1 = chan * x.size(0);
        r.set_size(nfft);
        if (nfft > x.size(0)) {
          r.set_size(sz_idx_0);
          for (iheight = 0; iheight < sz_idx_0; iheight++) {
            r[iheight].re = 0.0;
            r[iheight].im = 0.0;
          }
        }
        rt = 0;
        nInt2 = 0;
        for (i = 0; i <= u1 - 2; i++) {
          r[rt] = x[nInt2m1 + i];
          rt = nfft;
          useRadix2 = true;
          while (useRadix2) {
            rt >>= 1;
            nInt2 ^= rt;
            useRadix2 = ((nInt2 & rt) == 0);
          }
          rt = nInt2;
        }
        nInt2m1 = (nInt2m1 + u1) - 1;
        r[rt] = x[nInt2m1];
        if (nfft > 1) {
          for (i = 0; i <= i2; i += 2) {
            double re_tmp;
            nt_re_tmp = r[i + 1].re;
            nt_im = r[i + 1].im;
            re_tmp = r[i].re;
            twid_re = r[i].im;
            r[i + 1].re = re_tmp - nt_re_tmp;
            r[i + 1].im = twid_re - nt_im;
            r[i].re = re_tmp + nt_re_tmp;
            r[i].im = twid_re + nt_im;
          }
        }
        iDelta = 2;
        iDelta2 = 4;
        k = nRowsD4;
        iheight = ((nRowsD4 - 1) << 2) + 1;
        while (k > 0) {
          double nt_re;
          for (i = 0; i < iheight; i += iDelta2) {
            nInt2m1 = i + iDelta;
            nt_re = r[nInt2m1].re;
            nt_im = r[nInt2m1].im;
            r[nInt2m1].re = r[i].re - nt_re;
            r[nInt2m1].im = r[i].im - nt_im;
            r[i].re = r[i].re + nt_re;
            r[i].im = r[i].im + nt_im;
          }
          rt = 1;
          for (nInt2 = k; nInt2 < nRowsD2; nInt2 += k) {
            double twid_im;
            twid_re = costab[nInt2];
            twid_im = sintab[nInt2];
            i = rt;
            nInt2m1 = rt + iheight;
            while (i < nInt2m1) {
              int minNrowsNx;
              minNrowsNx = i + iDelta;
              nt_re_tmp = r[minNrowsNx].im;
              nt_im = r[minNrowsNx].re;
              nt_re = twid_re * nt_im - twid_im * nt_re_tmp;
              nt_im = twid_re * nt_re_tmp + twid_im * nt_im;
              r[minNrowsNx].re = r[i].re - nt_re;
              r[minNrowsNx].im = r[i].im - nt_im;
              r[i].re = r[i].re + nt_re;
              r[i].im = r[i].im + nt_im;
              i += iDelta2;
            }
            rt++;
          }
          k /= 2;
          iDelta = iDelta2;
          iDelta2 += iDelta2;
          iheight -= iDelta;
        }
        rt = r.size(0);
        for (iheight = 0; iheight < rt; iheight++) {
          y[iheight + y.size(0) * chan] = r[iheight];
        }
      }
    } else {
      double nt_im;
      int iDelta;
      int minNrowsNx;
      int nChan;
      int nInt2;
      int nInt2m1;
      int sz_idx_0;
      bool b_overflow;
      bool overflow;
      nfft = x.size(0);
      nChan = x.size(1);
      nInt2m1 = (x.size(0) + x.size(0)) - 1;
      if (nInt2m1 < 0) {
        rtNonNegativeError(static_cast<double>(nInt2m1), o_emlrtDCI);
      }
      wwc.set_size(nInt2m1);
      rt = 0;
      wwc[x.size(0) - 1].re = 1.0;
      wwc[x.size(0) - 1].im = 0.0;
      nInt2 = x.size(0) << 1;
      iDelta = x.size(0);
      for (k = 0; k <= iDelta - 2; k++) {
        minNrowsNx = ((k + 1) << 1) - 1;
        if (nInt2 - rt <= minNrowsNx) {
          rt += minNrowsNx - nInt2;
        } else {
          rt += minNrowsNx;
        }
        nt_im = -3.1415926535897931 * static_cast<double>(rt) /
                static_cast<double>(nfft);
        wwc[(x.size(0) - k) - 2].re = std::cos(nt_im);
        wwc[(x.size(0) - k) - 2].im = -std::sin(nt_im);
      }
      nInt2 = nInt2m1 - 1;
      for (k = nInt2; k >= nfft; k--) {
        wwc[k] = wwc[(nInt2m1 - k) - 1];
      }
      y.set_size(x.size(0), x.size(1));
      if (x.size(1) > 2147483646) {
        check_forloop_overflow_error();
      }
      sz_idx_0 = x.size(0);
      rt = x.size(0);
      minNrowsNx = x.size(0);
      if (rt <= minNrowsNx) {
        minNrowsNx = rt;
      }
      useRadix2 = (minNrowsNx > 2147483646);
      nInt2 = minNrowsNx + 1;
      overflow = ((minNrowsNx + 1 <= x.size(0)) && (x.size(0) > 2147483646));
      iDelta = wwc.size(0);
      b_overflow = ((x.size(0) <= wwc.size(0)) && (wwc.size(0) > 2147483646));
      for (int chan{0}; chan < nChan; chan++) {
        double re_tmp;
        double twid_im;
        double twid_re;
        int iheight;
        r.set_size(nfft);
        if (nfft > x.size(0)) {
          r.set_size(sz_idx_0);
          for (iheight = 0; iheight < sz_idx_0; iheight++) {
            r[iheight].re = 0.0;
            r[iheight].im = 0.0;
          }
        }
        rt = chan * x.size(0);
        if (useRadix2) {
          check_forloop_overflow_error();
        }
        for (k = 0; k < minNrowsNx; k++) {
          double nt_re;
          nInt2m1 = (nfft + k) - 1;
          nt_re = wwc[nInt2m1].re;
          nt_im = wwc[nInt2m1].im;
          iheight = rt + k;
          twid_im = x[iheight].im;
          re_tmp = x[iheight].re;
          r[k].re = nt_re * re_tmp + nt_im * twid_im;
          r[k].im = nt_re * twid_im - nt_im * re_tmp;
        }
        if (overflow) {
          check_forloop_overflow_error();
        }
        for (k = nInt2; k <= nfft; k++) {
          r[k - 1].re = 0.0;
          r[k - 1].im = 0.0;
        }
        internal::fft::FFTImplementationCallback::r2br_r2dit_trig_impl(
            r, iDelta2, costab, sintab, fy);
        internal::fft::FFTImplementationCallback::r2br_r2dit_trig_impl(
            wwc, iDelta2, costab, sintab, fv);
        rt = fy.size(0);
        for (iheight = 0; iheight < rt; iheight++) {
          re_tmp = fy[iheight].re;
          nt_im = fv[iheight].im;
          twid_re = fy[iheight].im;
          twid_im = fv[iheight].re;
          fy[iheight].re = re_tmp * twid_im - twid_re * nt_im;
          fy[iheight].im = re_tmp * nt_im + twid_re * twid_im;
        }
        internal::fft::FFTImplementationCallback::r2br_r2dit_trig_impl(
            fy, iDelta2, costab, sintabinv, fv);
        if (fv.size(0) > 1) {
          nt_im = 1.0 / static_cast<double>(fv.size(0));
          rt = fv.size(0);
          for (iheight = 0; iheight < rt; iheight++) {
            fv[iheight].re = nt_im * fv[iheight].re;
            fv[iheight].im = nt_im * fv[iheight].im;
          }
        }
        if (b_overflow) {
          check_forloop_overflow_error();
        }
        for (k = nfft; k <= iDelta; k++) {
          twid_im = wwc[k - 1].re;
          re_tmp = fv[k - 1].im;
          nt_im = wwc[k - 1].im;
          twid_re = fv[k - 1].re;
          iheight = k - nfft;
          r[iheight].re = twid_im * twid_re + nt_im * re_tmp;
          r[iheight].im = twid_im * re_tmp - nt_im * twid_re;
        }
        rt = r.size(0);
        for (iheight = 0; iheight < rt; iheight++) {
          y[iheight + y.size(0) * chan] = r[iheight];
        }
      }
    }
  }
}

void fft(const ::coder::array<creal_T, 3U> &x, double varargin_1,
         ::coder::array<creal_T, 3U> &y)
{
  array<creal_T, 1U> r;
  array<double, 2U> costab;
  array<double, 2U> sintab;
  array<double, 2U> sintabinv;
  int i2;
  int nRowsD2;
  int nRowsD4;
  int sz_idx_0;
  int u1;
  bool overflow;
  if (x.size(0) == 1) {
    v_rtErrorWithMessageID(hb_emlrtRTEI.fName, hb_emlrtRTEI.lineNo);
  }
  if ((!(varargin_1 >= 0.0)) || (!(varargin_1 == std::floor(varargin_1)))) {
    u_rtErrorWithMessageID(gb_emlrtRTEI.fName, gb_emlrtRTEI.lineNo);
  }
  if (!(varargin_1 <= 2.147483647E+9)) {
    t_rtErrorWithMessageID(fb_emlrtRTEI.fName, fb_emlrtRTEI.lineNo);
  }
  if ((x.size(0) == 0) || (x.size(1) == 0) || (x.size(2) == 0) ||
      (static_cast<int>(varargin_1) == 0)) {
    int iy;
    y.set_size(static_cast<int>(varargin_1), x.size(1), x.size(2));
    iy = static_cast<int>(varargin_1) * x.size(1) * x.size(2);
    for (int ju{0}; ju < iy; ju++) {
      y[ju].re = 0.0;
      y[ju].im = 0.0;
    }
  } else {
    int istart;
    int iy;
    int k;
    bool useRadix2;
    useRadix2 = ((static_cast<int>(varargin_1) > 0) &&
                 ((static_cast<int>(varargin_1) &
                   (static_cast<int>(varargin_1) - 1)) == 0));
    iy = 1;
    if (useRadix2) {
      istart = static_cast<int>(varargin_1);
    } else {
      if (static_cast<int>(varargin_1) > 0) {
        k = nextpow2(
            (static_cast<int>(varargin_1) + static_cast<int>(varargin_1)) - 1);
        if (k >= 0) {
          if (k <= 31) {
            iy = 1 << k;
          } else {
            iy = 0;
          }
        } else {
          iy = 0;
        }
      }
      istart = static_cast<int>(varargin_1) << 2;
      if (istart < 1) {
        istart = 1;
      }
      if (iy > istart) {
        h_rtErrorWithMessageID(ib_emlrtRTEI.fName, ib_emlrtRTEI.lineNo);
      }
      istart = iy;
    }
    internal::fft::FFTImplementationCallback::generate_twiddle_tables(
        istart, useRadix2, costab, sintab, sintabinv);
    if (useRadix2) {
      int ju;
      int nChan_tmp;
      nChan_tmp = x.size(1) * x.size(2);
      y.set_size(static_cast<int>(varargin_1), x.size(1), x.size(2));
      if (static_cast<int>(varargin_1) > x.size(0)) {
        y.set_size(static_cast<int>(varargin_1), x.size(1), x.size(2));
        iy = static_cast<int>(varargin_1) * x.size(1) * x.size(2);
        for (ju = 0; ju < iy; ju++) {
          y[ju].re = 0.0;
          y[ju].im = 0.0;
        }
      }
      if (nChan_tmp > 2147483646) {
        check_forloop_overflow_error();
      }
      if (nChan_tmp - 1 >= 0) {
        sz_idx_0 = static_cast<int>(varargin_1);
        istart = x.size(0);
        u1 = static_cast<int>(varargin_1);
        if (istart <= u1) {
          u1 = istart;
        }
        i2 = static_cast<int>(varargin_1) - 2;
        nRowsD2 = static_cast<int>(varargin_1) / 2;
        nRowsD4 = nRowsD2 / 2;
        overflow = (u1 - 1 > 2147483646);
      }
      for (int chan{0}; chan < nChan_tmp; chan++) {
        double temp_im;
        double temp_re;
        double temp_re_tmp;
        double twid_re;
        int i;
        int iDelta;
        int iDelta2;
        int iheight;
        int ix;
        ix = chan * x.size(0);
        r.set_size(sz_idx_0);
        if (static_cast<int>(varargin_1) > x.size(0)) {
          r.set_size(sz_idx_0);
          for (ju = 0; ju < sz_idx_0; ju++) {
            r[ju].re = 0.0;
            r[ju].im = 0.0;
          }
        }
        iy = 0;
        ju = 0;
        if (overflow) {
          check_forloop_overflow_error();
        }
        for (i = 0; i <= u1 - 2; i++) {
          r[iy] = x[ix + i];
          istart = static_cast<int>(varargin_1);
          useRadix2 = true;
          while (useRadix2) {
            istart >>= 1;
            ju ^= istart;
            useRadix2 = ((ju & istart) == 0);
          }
          iy = ju;
        }
        ix = (ix + u1) - 1;
        r[iy] = x[ix];
        if (static_cast<int>(varargin_1) > 1) {
          for (i = 0; i <= i2; i += 2) {
            temp_re_tmp = r[i + 1].re;
            temp_im = r[i + 1].im;
            temp_re = r[i].re;
            twid_re = r[i].im;
            r[i + 1].re = temp_re - temp_re_tmp;
            r[i + 1].im = twid_re - temp_im;
            r[i].re = temp_re + temp_re_tmp;
            r[i].im = twid_re + temp_im;
          }
        }
        iDelta = 2;
        iDelta2 = 4;
        k = nRowsD4;
        iheight = ((nRowsD4 - 1) << 2) + 1;
        while (k > 0) {
          for (i = 0; i < iheight; i += iDelta2) {
            istart = i + iDelta;
            temp_re = r[istart].re;
            temp_im = r[istart].im;
            r[istart].re = r[i].re - temp_re;
            r[istart].im = r[i].im - temp_im;
            r[i].re = r[i].re + temp_re;
            r[i].im = r[i].im + temp_im;
          }
          istart = 1;
          for (iy = k; iy < nRowsD2; iy += k) {
            double twid_im;
            twid_re = costab[iy];
            twid_im = sintab[iy];
            i = istart;
            ju = istart + iheight;
            while (i < ju) {
              ix = i + iDelta;
              temp_re_tmp = r[ix].im;
              temp_im = r[ix].re;
              temp_re = twid_re * temp_im - twid_im * temp_re_tmp;
              temp_im = twid_re * temp_re_tmp + twid_im * temp_im;
              r[ix].re = r[i].re - temp_re;
              r[ix].im = r[i].im - temp_im;
              r[i].re = r[i].re + temp_re;
              r[i].im = r[i].im + temp_im;
              i += iDelta2;
            }
            istart++;
          }
          k /= 2;
          iDelta = iDelta2;
          iDelta2 += iDelta2;
          iheight -= iDelta;
        }
        istart = y.size(0);
        iy = r.size(0);
        for (ju = 0; ju < iy; ju++) {
          y[ju + istart * chan] = r[ju];
        }
      }
    } else {
      internal::fft::FFTImplementationCallback::dobluesteinfft(
          x, iy, static_cast<int>(varargin_1), costab, sintab, sintabinv, y);
    }
  }
}

} // namespace coder

// End of code generation (fft.cpp)
