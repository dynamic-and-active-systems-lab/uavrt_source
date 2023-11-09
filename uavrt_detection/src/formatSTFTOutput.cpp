//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// formatSTFTOutput.cpp
//
// Code generation for function 'formatSTFTOutput'
//

// Include files
#include "formatSTFTOutput.h"
#include "eml_int_forloop_overflow_check.h"
#include "iseven.h"
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
namespace b_signal {
namespace internal {
namespace stft {
void formatSTFTOutput(::coder::array<creal_T, 3U> &S,
                      const ::coder::array<double, 1U> &F,
                      ::coder::array<double, 1U> &Fout)
{
  array<creal_T, 2U> buffer;
  double xtmp_re;
  int b_i;
  int lowerDim;
  if (signalwavelet::internal::iseven(static_cast<double>(S.size(0)))) {
    int vlend2;
    xtmp_re = static_cast<double>(S.size(0)) / 2.0 - 1.0;
    vlend2 = 1;
    if (S.size(0) != 1) {
      vlend2 = 0;
    } else if ((S.size(1) == 1) && (S.size(2) != 1)) {
      vlend2 = 2;
    }
    if (static_cast<int>(xtmp_re) != xtmp_re) {
      rtErrorWithMessageID("int32", "int32", qc_emlrtRTEI.fName,
                           qc_emlrtRTEI.lineNo);
    }
    if ((S.size(0) != 0) && (S.size(1) != 0) && (S.size(2) != 0) &&
        ((S.size(0) != 1) || (S.size(1) != 1) || (S.size(2) != 1))) {
      int i2;
      int ib;
      int npages;
      int ns;
      int vspread;
      bool shiftright;
      if (xtmp_re < 0.0) {
        ns = 1;
        shiftright = false;
      } else {
        ns = static_cast<int>(xtmp_re);
        shiftright = true;
      }
      if (S.size(vlend2) <= 1) {
        ns = 0;
      } else {
        if (ns > S.size(vlend2)) {
          unsigned int u;
          u = static_cast<unsigned int>(S.size(vlend2));
          if (u == 0U) {
            rtDivisionByZeroError(uc_emlrtRTEI);
          } else {
            b_i = static_cast<int>(static_cast<unsigned int>(ns) / u);
          }
          ns -= S.size(vlend2) * b_i;
        }
        if (ns > (S.size(vlend2) >> 1)) {
          ns = S.size(vlend2) - ns;
          shiftright = !shiftright;
        }
      }
      lowerDim = S.size(0);
      if ((S.size(0) > 0) && ((S.size(1) == 0) || (S.size(1) > S.size(0)))) {
        lowerDim = S.size(1);
      }
      if ((lowerDim > 0) && ((S.size(2) == 0) || (S.size(2) > lowerDim))) {
        lowerDim = S.size(2);
      }
      lowerDim /= 2;
      buffer.set_size(1, lowerDim);
      for (b_i = 0; b_i < lowerDim; b_i++) {
        buffer[b_i].re = 0.0;
        buffer[b_i].im = 0.0;
      }
      b_i = S.size(vlend2);
      i2 = S.size(vlend2);
      ib = 1;
      for (int k{0}; k < vlend2; k++) {
        ib *= S.size(k);
      }
      npages = 1;
      lowerDim = vlend2 + 2;
      for (int k{lowerDim}; k < 4; k++) {
        npages *= S.size(k - 1);
      }
      vspread = ib * S.size(vlend2);
      if ((S.size(vlend2) > 1) && (ns > 0)) {
        if (npages > 2147483646) {
          check_forloop_overflow_error();
        }
        for (int i{0}; i < npages; i++) {
          lowerDim = i * vspread;
          if (ib > 2147483646) {
            check_forloop_overflow_error();
          }
          for (vlend2 = 0; vlend2 < ib; vlend2++) {
            int i1;
            i1 = lowerDim + vlend2;
            if (shiftright) {
              int b_i1;
              for (int k{0}; k < ns; k++) {
                buffer[k] = S[i1 + ((k + b_i) - ns) * ib];
              }
              b_i1 = ns + 1;
              for (int k{i2}; k >= b_i1; k--) {
                S[i1 + (k - 1) * ib] = S[i1 + ((k - ns) - 1) * ib];
              }
              for (int k{0}; k < ns; k++) {
                S[i1 + k * ib] = buffer[k];
              }
            } else {
              int b_i1;
              for (int k{0}; k < ns; k++) {
                buffer[k] = S[i1 + k * ib];
              }
              b_i1 = (b_i - ns) - 1;
              for (int k{0}; k <= b_i1; k++) {
                S[i1 + k * ib] = S[i1 + (k + ns) * ib];
              }
              for (int k{0}; k < ns; k++) {
                S[i1 + ((k + b_i) - ns) * ib] = buffer[k];
              }
            }
          }
        }
      }
    }
  } else if (S.size(0) > 1) {
    int npages;
    int vlend2;
    int vspread;
    vlend2 = static_cast<int>(static_cast<unsigned int>(S.size(0)) >> 1) - 1;
    npages = S.size(1) * S.size(2);
    vspread = S.size(0);
    if ((vlend2 + 1) << 1 == S.size(0)) {
      int i2;
      i2 = 1;
      if (npages > 2147483646) {
        check_forloop_overflow_error();
      }
      for (int i{0}; i < npages; i++) {
        int i1;
        int ib;
        i1 = i2;
        i2 += vspread;
        ib = i1 + vlend2;
        for (int k{0}; k <= vlend2; k++) {
          double xtmp_im;
          lowerDim = (i1 + k) - 1;
          xtmp_re = S[lowerDim].re;
          xtmp_im = S[lowerDim].im;
          b_i = ib + k;
          S[lowerDim] = S[b_i];
          S[b_i].re = xtmp_re;
          S[b_i].im = xtmp_im;
        }
      }
    } else {
      int i2;
      i2 = 1;
      if (npages > 2147483646) {
        check_forloop_overflow_error();
      }
      for (int i{0}; i < npages; i++) {
        double xtmp_im;
        int i1;
        int ib;
        i1 = i2;
        i2 += vspread;
        ib = i1 + vlend2;
        xtmp_re = S[ib].re;
        xtmp_im = S[ib].im;
        for (int k{0}; k <= vlend2; k++) {
          int b_i1;
          b_i = ib + k;
          b_i1 = (i1 + k) - 1;
          S[b_i] = S[b_i1];
          S[b_i1] = S[b_i + 1];
        }
        ib = (ib + vlend2) + 1;
        S[ib].re = xtmp_re;
        S[ib].im = xtmp_im;
      }
    }
  }
  if (signalwavelet::internal::iseven(static_cast<double>(F.size(0)))) {
    xtmp_re = static_cast<double>(F.size(0)) / 2.0;
    if (xtmp_re != std::floor(xtmp_re)) {
      rtIntegerError(xtmp_re, k_emlrtDCI);
    }
    if ((static_cast<int>(xtmp_re) < 1) ||
        (static_cast<int>(xtmp_re) > F.size(0))) {
      rtDynamicBoundsError(static_cast<int>(xtmp_re), 1, F.size(0), o_emlrtBCI);
    }
    xtmp_re = F[static_cast<int>(xtmp_re) - 1];
    Fout.set_size(F.size(0));
    lowerDim = F.size(0);
    for (b_i = 0; b_i < lowerDim; b_i++) {
      Fout[b_i] = F[b_i] - xtmp_re;
    }
  } else {
    xtmp_re = (static_cast<double>(F.size(0)) + 1.0) / 2.0;
    if (xtmp_re != std::floor(xtmp_re)) {
      rtIntegerError(xtmp_re, j_emlrtDCI);
    }
    if ((static_cast<int>(xtmp_re) < 1) ||
        (static_cast<int>(xtmp_re) > F.size(0))) {
      rtDynamicBoundsError(static_cast<int>(xtmp_re), 1, F.size(0), n_emlrtBCI);
    }
    xtmp_re = F[static_cast<int>(xtmp_re) - 1];
    Fout.set_size(F.size(0));
    lowerDim = F.size(0);
    for (b_i = 0; b_i < lowerDim; b_i++) {
      Fout[b_i] = F[b_i] - xtmp_re;
    }
  }
}

} // namespace stft
} // namespace internal
} // namespace b_signal
} // namespace coder

// End of code generation (formatSTFTOutput.cpp)
