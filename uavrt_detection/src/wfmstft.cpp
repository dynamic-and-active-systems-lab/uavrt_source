//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// wfmstft.cpp
//
// Code generation for function 'wfmstft'
//

// Include files
#include "wfmstft.h"
#include "eml_int_forloop_overflow_check.h"
#include "mean.h"
#include "quickselect.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include <cmath>

// Function Declarations
static void gt(coder::array<bool, 2U> &in1, const coder::array<double, 2U> &in2,
               const coder::array<double, 2U> &in3);

// Function Definitions
static void gt(coder::array<bool, 2U> &in1, const coder::array<double, 2U> &in2,
               const coder::array<double, 2U> &in3)
{
  int aux_0_1;
  int aux_1_1;
  int b_loop_ub;
  int loop_ub;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  int stride_1_1;
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  in1.set_size(loop_ub, in1.size(1));
  if (in3.size(1) == 1) {
    b_loop_ub = in2.size(1);
  } else {
    b_loop_ub = in3.size(1);
  }
  in1.set_size(in1.size(0), b_loop_ub);
  stride_0_0 = (in2.size(0) != 1);
  stride_0_1 = (in2.size(1) != 1);
  stride_1_0 = (in3.size(0) != 1);
  stride_1_1 = (in3.size(1) != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (int i{0}; i < b_loop_ub; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      in1[i1 + in1.size(0) * i] =
          (in2[i1 * stride_0_0 + in2.size(0) * aux_0_1] >
           in3[i1 * stride_1_0 + in3.size(0) * aux_1_1]);
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

void wfmstft::updatepsd()
{
  static rtBoundsCheckInfo cb_emlrtBCI{
      -1,                  // iFirst
      -1,                  // iLast
      161,                 // lineNo
      21,                  // colNo
      "magSqrd",           // aName
      "wfmstft/updatepsd", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "wfmstft.m", // pName
      0            // checkKind
  };
  static rtEqualityCheckInfo h_emlrtECI{
      1,                   // nDims
      160,                 // lineNo
      27,                  // colNo
      "wfmstft/updatepsd", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "wfmstft.m" // pName
  };
  static rtEqualityCheckInfo i_emlrtECI{
      2,                   // nDims
      160,                 // lineNo
      27,                  // colNo
      "wfmstft/updatepsd", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "wfmstft.m" // pName
  };
  coder::array<double, 2U> magSqrd;
  coder::array<double, 2U> movMeanMagSqrd;
  coder::array<double, 1U> b_xv;
  coder::array<double, 1U> medMovMeanMagSqrd;
  coder::array<double, 1U> xv;
  coder::array<double, 1U> yv;
  coder::array<bool, 2U> r;
  double bsum;
  double varargin_1;
  int b_nx;
  int firstBlockLength;
  int hi;
  int k;
  int loop_ub;
  int loop_ub_tmp;
  int midm1;
  int nblocks;
  int nx;
  int outsize_idx_0;
  int stride;
  int vlen;
  int xblockoffset;
  bool b_overflow;
  bool overflow;
  // obj.psd = obj.dt^2/obj.T*mean(abs(obj.S).^2,2);
  // obj.psd = obj.dt^2/obj.T*median(abs(obj.S).^2,2);%use median to exclude
  // outliers from short pulses
  //              runningPsd = obj.dt^2/obj.T*abs(obj.S).^2;
  //              psdStdDev  = stdev(runningPsd,[],2);
  //              psdStdDevMat = repmat(runningPsd,1,size(runningPsd,2));
  // This block calculates a three window moving mean of the power
  // spectral density of the waveform and then thresholds that
  // moving mean for values greater than 10x the median. This
  // thresholding step reduced the energy from very high power
  // pulses that might be in the signal from affecting the PSD
  // estimate. It is assumed here that low signal power pulses will
  // only marginally affect the psd estimate.
  // coder.varsize('magSqrd','movMeanMagSqrd','medMovMeanMagSqrd','medMovMeanMagSqrdMat','magSqrdMask')
  nx = S.size(0) * S.size(1);
  movMeanMagSqrd.set_size(S.size(0), S.size(1));
  if (nx > 2147483646) {
    coder::check_forloop_overflow_error();
  }
  for (k = 0; k < nx; k++) {
    movMeanMagSqrd[k] = rt_hypotd_snf(S[k].re, S[k].im);
  }
  magSqrd.set_size(movMeanMagSqrd.size(0), movMeanMagSqrd.size(1));
  loop_ub_tmp = movMeanMagSqrd.size(0) * movMeanMagSqrd.size(1);
  for (hi = 0; hi < loop_ub_tmp; hi++) {
    varargin_1 = movMeanMagSqrd[hi];
    magSqrd[hi] = varargin_1 * varargin_1;
  }
  movMeanMagSqrd.set_size(magSqrd.size(0), magSqrd.size(1));
  nblocks = magSqrd.size(0) * magSqrd.size(1);
  for (hi = 0; hi < nblocks; hi++) {
    movMeanMagSqrd[hi] = 0.0;
  }
  nx = magSqrd.size(1);
  stride = magSqrd.size(0);
  if (magSqrd.size(0) > 2147483646) {
    coder::check_forloop_overflow_error();
  }
  if (magSqrd.size(0) - 1 >= 0) {
    outsize_idx_0 = magSqrd.size(1);
    loop_ub = magSqrd.size(1);
    overflow = (magSqrd.size(1) > 2147483646);
    b_nx = magSqrd.size(1);
    b_overflow = (magSqrd.size(1) > 2147483646);
  }
  for (int j{0}; j < stride; j++) {
    xv.set_size(outsize_idx_0);
    for (hi = 0; hi < loop_ub; hi++) {
      xv[hi] = 0.0;
    }
    if (overflow) {
      coder::check_forloop_overflow_error();
    }
    for (k = 0; k < nx; k++) {
      xv[k] = magSqrd[j + k * stride];
    }
    yv.set_size(xv.size(0));
    nblocks = xv.size(0);
    for (hi = 0; hi < nblocks; hi++) {
      yv[hi] = 0.0;
    }
    if (b_overflow) {
      coder::check_forloop_overflow_error();
    }
    for (k = 0; k < b_nx; k++) {
      if (k + 1 <= 1) {
        midm1 = 0;
      } else {
        midm1 = k - 1;
      }
      if (k + 2 > xv.size(0)) {
        nblocks = xv.size(0);
      } else {
        nblocks = k + 2;
      }
      vlen = nblocks - midm1;
      if ((xv.size(0) == 0) || (vlen == 0)) {
        varargin_1 = 0.0;
      } else {
        int lastBlockLength;
        if (vlen <= 1024) {
          firstBlockLength = vlen;
          lastBlockLength = 0;
          nblocks = 1;
        } else {
          firstBlockLength = 1024;
          nblocks = vlen / 1024;
          lastBlockLength = vlen - (nblocks << 10);
          if (lastBlockLength > 0) {
            nblocks++;
          } else {
            lastBlockLength = 1024;
          }
        }
        varargin_1 = xv[midm1];
        for (int b_k{2}; b_k <= firstBlockLength; b_k++) {
          varargin_1 += xv[(midm1 + b_k) - 1];
        }
        for (firstBlockLength = 2; firstBlockLength <= nblocks;
             firstBlockLength++) {
          xblockoffset = midm1 + ((firstBlockLength - 1) << 10);
          bsum = xv[xblockoffset];
          if (firstBlockLength == nblocks) {
            hi = lastBlockLength;
          } else {
            hi = 1024;
          }
          for (int b_k{2}; b_k <= hi; b_k++) {
            bsum += xv[(xblockoffset + b_k) - 1];
          }
          varargin_1 += bsum;
        }
      }
      yv[k] = varargin_1 / static_cast<double>(vlen);
    }
    firstBlockLength = yv.size(0);
    if (yv.size(0) > 2147483646) {
      coder::check_forloop_overflow_error();
    }
    for (k = 0; k < firstBlockLength; k++) {
      movMeanMagSqrd[j + k * stride] = yv[k];
    }
  }
  if ((movMeanMagSqrd.size(0) == 0) || (movMeanMagSqrd.size(1) == 0)) {
    medMovMeanMagSqrd.set_size(movMeanMagSqrd.size(0));
    nblocks = movMeanMagSqrd.size(0);
    for (hi = 0; hi < nblocks; hi++) {
      medMovMeanMagSqrd[hi] = rtNaN;
    }
  } else {
    medMovMeanMagSqrd.set_size(movMeanMagSqrd.size(0));
    nblocks = movMeanMagSqrd.size(0);
    for (hi = 0; hi < nblocks; hi++) {
      medMovMeanMagSqrd[hi] = 0.0;
    }
    nx = movMeanMagSqrd.size(1);
    stride = movMeanMagSqrd.size(0);
    if (movMeanMagSqrd.size(0) > 2147483646) {
      coder::check_forloop_overflow_error();
    }
    nblocks = movMeanMagSqrd.size(1);
    overflow = (movMeanMagSqrd.size(1) > 2147483646);
    vlen = movMeanMagSqrd.size(1);
    b_overflow = (movMeanMagSqrd.size(1) > 2147483646);
    for (int j{0}; j < stride; j++) {
      b_xv.set_size(nx);
      for (hi = 0; hi < nblocks; hi++) {
        b_xv[hi] = 0.0;
      }
      if (overflow) {
        coder::check_forloop_overflow_error();
      }
      for (k = 0; k < nx; k++) {
        b_xv[k] = movMeanMagSqrd[j + k * stride];
      }
      if (b_overflow) {
        coder::check_forloop_overflow_error();
      }
      k = 0;
      int exitg1;
      do {
        exitg1 = 0;
        if (k <= vlen - 1) {
          if (std::isnan(b_xv[k])) {
            medMovMeanMagSqrd[j] = rtNaN;
            exitg1 = 1;
          } else {
            k++;
          }
        } else {
          if (vlen <= 4) {
            if (vlen == 1) {
              medMovMeanMagSqrd[j] = b_xv[0];
            } else if (vlen == 2) {
              if (((b_xv[0] < 0.0) != (b_xv[1] < 0.0)) || std::isinf(b_xv[0])) {
                medMovMeanMagSqrd[j] = (b_xv[0] + b_xv[1]) / 2.0;
              } else {
                medMovMeanMagSqrd[j] = b_xv[0] + (b_xv[1] - b_xv[0]) / 2.0;
              }
            } else if (vlen == 3) {
              if (b_xv[0] < b_xv[1]) {
                if (b_xv[1] < b_xv[2]) {
                  xblockoffset = 1;
                } else if (b_xv[0] < b_xv[2]) {
                  xblockoffset = 2;
                } else {
                  xblockoffset = 0;
                }
              } else if (b_xv[0] < b_xv[2]) {
                xblockoffset = 0;
              } else if (b_xv[1] < b_xv[2]) {
                xblockoffset = 2;
              } else {
                xblockoffset = 1;
              }
              medMovMeanMagSqrd[j] = b_xv[xblockoffset];
            } else {
              if (b_xv[0] < b_xv[1]) {
                if (b_xv[1] < b_xv[2]) {
                  firstBlockLength = 0;
                  xblockoffset = 1;
                  hi = 2;
                } else if (b_xv[0] < b_xv[2]) {
                  firstBlockLength = 0;
                  xblockoffset = 2;
                  hi = 1;
                } else {
                  firstBlockLength = 2;
                  xblockoffset = 0;
                  hi = 1;
                }
              } else if (b_xv[0] < b_xv[2]) {
                firstBlockLength = 1;
                xblockoffset = 0;
                hi = 2;
              } else if (b_xv[1] < b_xv[2]) {
                firstBlockLength = 1;
                xblockoffset = 2;
                hi = 0;
              } else {
                firstBlockLength = 2;
                xblockoffset = 1;
                hi = 0;
              }
              if (b_xv[firstBlockLength] < b_xv[3]) {
                if (b_xv[3] < b_xv[hi]) {
                  if (((b_xv[xblockoffset] < 0.0) != (b_xv[3] < 0.0)) ||
                      std::isinf(b_xv[xblockoffset])) {
                    medMovMeanMagSqrd[j] = (b_xv[xblockoffset] + b_xv[3]) / 2.0;
                  } else {
                    medMovMeanMagSqrd[j] = b_xv[xblockoffset] +
                                           (b_xv[3] - b_xv[xblockoffset]) / 2.0;
                  }
                } else if (((b_xv[xblockoffset] < 0.0) != (b_xv[hi] < 0.0)) ||
                           std::isinf(b_xv[xblockoffset])) {
                  medMovMeanMagSqrd[j] = (b_xv[xblockoffset] + b_xv[hi]) / 2.0;
                } else {
                  medMovMeanMagSqrd[j] = b_xv[xblockoffset] +
                                         (b_xv[hi] - b_xv[xblockoffset]) / 2.0;
                }
              } else if (((b_xv[firstBlockLength] < 0.0) !=
                          (b_xv[xblockoffset] < 0.0)) ||
                         std::isinf(b_xv[firstBlockLength])) {
                medMovMeanMagSqrd[j] =
                    (b_xv[firstBlockLength] + b_xv[xblockoffset]) / 2.0;
              } else {
                medMovMeanMagSqrd[j] =
                    b_xv[firstBlockLength] +
                    (b_xv[xblockoffset] - b_xv[firstBlockLength]) / 2.0;
              }
            }
          } else {
            midm1 = vlen >> 1;
            if ((vlen & 1) == 0) {
              varargin_1 = coder::internal::quickselect(b_xv, midm1 + 1, vlen,
                                                        firstBlockLength, hi);
              medMovMeanMagSqrd[j] = varargin_1;
              if (midm1 < firstBlockLength) {
                bsum = coder::internal::quickselect(
                    b_xv, midm1, hi - 1, firstBlockLength, xblockoffset);
                if (((varargin_1 < 0.0) != (bsum < 0.0)) ||
                    std::isinf(varargin_1)) {
                  medMovMeanMagSqrd[j] = (varargin_1 + bsum) / 2.0;
                } else {
                  medMovMeanMagSqrd[j] = varargin_1 + (bsum - varargin_1) / 2.0;
                }
              }
            } else {
              medMovMeanMagSqrd[j] = coder::internal::quickselect(
                  b_xv, midm1 + 1, vlen, xblockoffset, firstBlockLength);
            }
          }
          exitg1 = 1;
        }
      } while (exitg1 == 0);
    }
  }
  // transpose(median(transpose(movMeanMagSqrd)));%median(rand(80,32767),2);
  coder::repmat(medMovMeanMagSqrd, static_cast<double>(magSqrd.size(1)),
                movMeanMagSqrd);
  nblocks = movMeanMagSqrd.size(0) * movMeanMagSqrd.size(1);
  for (hi = 0; hi < nblocks; hi++) {
    movMeanMagSqrd[hi] = 10.0 * movMeanMagSqrd[hi];
  }
  if ((magSqrd.size(0) != movMeanMagSqrd.size(0)) &&
      ((magSqrd.size(0) != 1) && (movMeanMagSqrd.size(0) != 1))) {
    emlrtDimSizeImpxCheckR2021b(magSqrd.size(0), movMeanMagSqrd.size(0),
                                h_emlrtECI);
  }
  if ((magSqrd.size(1) != movMeanMagSqrd.size(1)) &&
      ((magSqrd.size(1) != 1) && (movMeanMagSqrd.size(1) != 1))) {
    emlrtDimSizeImpxCheckR2021b(magSqrd.size(1), movMeanMagSqrd.size(1),
                                i_emlrtECI);
  }
  if ((magSqrd.size(0) == movMeanMagSqrd.size(0)) &&
      (magSqrd.size(1) == movMeanMagSqrd.size(1))) {
    r.set_size(magSqrd.size(0), magSqrd.size(1));
    for (hi = 0; hi < loop_ub_tmp; hi++) {
      r[hi] = (magSqrd[hi] > movMeanMagSqrd[hi]);
    }
  } else {
    gt(r, magSqrd, movMeanMagSqrd);
  }
  firstBlockLength = r.size(0) * r.size(1) - 1;
  for (xblockoffset = 0; xblockoffset <= firstBlockLength; xblockoffset++) {
    if (r[xblockoffset]) {
      hi = magSqrd.size(0) * magSqrd.size(1) - 1;
      if (xblockoffset > hi) {
        rtDynamicBoundsError(xblockoffset, 0, hi, cb_emlrtBCI);
      }
      magSqrd[xblockoffset] = rtNaN;
    }
  }
  varargin_1 = dt;
  varargin_1 = varargin_1 * varargin_1 / T;
  coder::mean(magSqrd, medMovMeanMagSqrd);
  psd.set_size(medMovMeanMagSqrd.size(0));
  nblocks = medMovMeanMagSqrd.size(0);
  for (hi = 0; hi < nblocks; hi++) {
    psd[hi] = varargin_1 * medMovMeanMagSqrd[hi];
  }
  // use median to exclude outliers from short pulses
}

// End of code generation (wfmstft.cpp)
