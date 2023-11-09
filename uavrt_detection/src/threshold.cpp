//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// threshold.cpp
//
// Code generation for function 'threshold'
//

// Include files
#include "threshold.h"
#include "anonymous_function.h"
#include "buildtimecorrelatormatrix.h"
#include "eml_int_forloop_overflow_check.h"
#include "evfit.h"
#include "find.h"
#include "fzero.h"
#include "interp1.h"
#include "nullAssignment.h"
#include "randn.h"
#include "rt_nonfinite.h"
#include "sparse1.h"
#include "stft.h"
#include "toc.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_internal_types.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "unaryMinOrMax.h"
#include "waveform.h"
#include "wfmstft.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include <cmath>
#include <cstdio>
#include <sstream>
#include <stdexcept>
#include <string>

// Function Declarations
static void uc_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
void threshold::setthreshprops(double thresh, const waveform &Wfm)
{
  static rtBoundsCheckInfo cb_emlrtBCI{
      -1,                         // iFirst
      -1,                         // iLast
      276,                        // lineNo
      49,                         // colNo
      "Wfm.stft.f",               // aName
      "threshold/setthreshprops", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "threshold.m", // pName
      0              // checkKind
  };
  static rtBoundsCheckInfo db_emlrtBCI{
      -1,                         // iFirst
      -1,                         // iLast
      276,                        // lineNo
      63,                         // colNo
      "Wfm.stft.f",               // aName
      "threshold/setthreshprops", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "threshold.m", // pName
      0              // checkKind
  };
  static rtBoundsCheckInfo eb_emlrtBCI{
      -1,                         // iFirst
      -1,                         // iLast
      290,                        // lineNo
      44,                         // colNo
      "newThresh",                // aName
      "threshold/setthreshprops", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "threshold.m", // pName
      0              // checkKind
  };
  static rtBoundsCheckInfo fb_emlrtBCI{
      -1,                         // iFirst
      -1,                         // iLast
      291,                        // lineNo
      44,                         // colNo
      "newThresh",                // aName
      "threshold/setthreshprops", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "threshold.m", // pName
      0              // checkKind
  };
  static rtBoundsCheckInfo gb_emlrtBCI{
      -1,                         // iFirst
      -1,                         // iLast
      292,                        // lineNo
      44,                         // colNo
      "firstTrueThreshInd",       // aName
      "threshold/setthreshprops", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "threshold.m", // pName
      0              // checkKind
  };
  static rtBoundsCheckInfo hb_emlrtBCI{
      -1,                         // iFirst
      -1,                         // iLast
      292,                        // lineNo
      23,                         // colNo
      "newThresh",                // aName
      "threshold/setthreshprops", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "threshold.m", // pName
      0              // checkKind
  };
  static rtBoundsCheckInfo ib_emlrtBCI{
      -1,                         // iFirst
      -1,                         // iLast
      292,                        // lineNo
      25,                         // colNo
      "newThresh",                // aName
      "threshold/setthreshprops", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "threshold.m", // pName
      0              // checkKind
  };
  static rtBoundsCheckInfo jb_emlrtBCI{
      -1,                         // iFirst
      -1,                         // iLast
      293,                        // lineNo
      41,                         // colNo
      "lastTrueThreshInd",        // aName
      "threshold/setthreshprops", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "threshold.m", // pName
      0              // checkKind
  };
  static rtBoundsCheckInfo kb_emlrtBCI{
      -1,                         // iFirst
      -1,                         // iLast
      293,                        // lineNo
      23,                         // colNo
      "newThresh",                // aName
      "threshold/setthreshprops", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "threshold.m", // pName
      0              // checkKind
  };
  static rtBoundsCheckInfo lb_emlrtBCI{
      -1,                         // iFirst
      -1,                         // iLast
      293,                        // lineNo
      44,                         // colNo
      "newThresh",                // aName
      "threshold/setthreshprops", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "threshold.m", // pName
      0              // checkKind
  };
  static rtEqualityCheckInfo h_emlrtECI{
      -1,                         // nDims
      292,                        // lineNo
      13,                         // colNo
      "threshold/setthreshprops", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "threshold.m" // pName
  };
  static rtEqualityCheckInfo i_emlrtECI{
      -1,                         // nDims
      293,                        // lineNo
      13,                         // colNo
      "threshold/setthreshprops", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "threshold.m" // pName
  };
  coder::array<double, 2U> b_newThresh;
  coder::array<double, 1U> freqBinPSD;
  coder::array<double, 1U> lastTrueThresh;
  coder::array<double, 1U> newThresh;
  coder::array<int, 1U> ii;
  coder::array<bool, 1U> x_tmp;
  double b;
  int i;
  int k;
  int nxi;
  freqBinPSD.set_size(Wfm.stft->psd.size(0));
  nxi = Wfm.stft->psd.size(0);
  for (k = 0; k < nxi; k++) {
    freqBinPSD[k] = Wfm.stft->psd[k];
  }
  // Extract psd for current waveform. Units are W/Hz
  k = Wfm.stft->f.size(0);
  if (k < 2) {
    rtDynamicBoundsError(2, 1, k, cb_emlrtBCI);
  }
  k = Wfm.stft->f.size(0);
  if (k < 1) {
    rtDynamicBoundsError(1, 1, k, db_emlrtBCI);
  }
  b = Wfm.stft->f[1] - Wfm.stft->f[0];
  nxi = freqBinPSD.size(0);
  for (k = 0; k < nxi; k++) {
    freqBinPSD[k] = freqBinPSD[k] * b;
  }
  // PSD (W/Hz) times bin width (Hz/bin) gives bin total power in (W/bin)
  // 1W standard
  newThresh.set_size(freqBinPSD.size(0));
  nxi = freqBinPSD.size(0);
  for (k = 0; k < nxi; k++) {
    newThresh[k] = 0.0;
  }
  if (freqBinPSD.size(0) != 0) {
    nxi = freqBinPSD.size(0);
    if (freqBinPSD.size(0) > 2147483646) {
      coder::check_forloop_overflow_error();
    }
    for (k = 0; k < nxi; k++) {
      if (std::isnan(freqBinPSD[k])) {
        newThresh[k] = rtNaN;
      } else if (freqBinPSD[k] > 1.0) {
        newThresh[k] = thresh + (freqBinPSD[k] - 1.0) * thresh;
      } else if (freqBinPSD[k] < 0.0) {
        newThresh[k] = freqBinPSD[k] * thresh;
      } else if (freqBinPSD[k] == 0.0) {
        newThresh[k] = 0.0;
      } else if (freqBinPSD[k] == 1.0) {
        newThresh[k] = thresh;
      } else if (thresh == 0.0) {
        newThresh[k] = 0.0;
      } else {
        newThresh[k] = (1.0 - freqBinPSD[k]) * 0.0 + freqBinPSD[k] * thresh;
      }
    }
  }
  // Finally,extrapolating the thresholds that are a little beyond the original
  // frequeny range can result in negative thresholds. Here we copy the first
  // and last valid threshold out to the places where the extrapolations would
  // have occured
  x_tmp.set_size(newThresh.size(0));
  nxi = newThresh.size(0);
  for (k = 0; k < nxi; k++) {
    x_tmp[k] = !std::isnan(newThresh[k]);
  }
  coder::c_eml_find(x_tmp, ii);
  freqBinPSD.set_size(ii.size(0));
  nxi = ii.size(0);
  for (k = 0; k < nxi; k++) {
    freqBinPSD[k] = ii[k];
  }
  coder::d_eml_find(x_tmp, ii);
  nxi = freqBinPSD.size(0);
  for (k = 0; k < nxi; k++) {
    i = static_cast<int>(freqBinPSD[k]);
    if ((i < 1) || (i > newThresh.size(0))) {
      rtDynamicBoundsError(i, 1, newThresh.size(0), eb_emlrtBCI);
    }
  }
  lastTrueThresh.set_size(ii.size(0));
  nxi = ii.size(0);
  for (k = 0; k < nxi; k++) {
    if ((ii[k] < 1) || (ii[k] > newThresh.size(0))) {
      rtDynamicBoundsError(ii[k], 1, newThresh.size(0), fb_emlrtBCI);
    }
    lastTrueThresh[k] = newThresh[ii[k] - 1];
  }
  if (freqBinPSD.size(0) < 1) {
    rtDynamicBoundsError(1, 1, freqBinPSD.size(0), gb_emlrtBCI);
  }
  if (newThresh.size(0) < 1) {
    rtDynamicBoundsError(1, 1, newThresh.size(0), hb_emlrtBCI);
  }
  nxi = static_cast<int>(freqBinPSD[0]);
  if ((static_cast<int>(freqBinPSD[0]) < 1) ||
      (static_cast<int>(freqBinPSD[0]) > newThresh.size(0))) {
    rtDynamicBoundsError(static_cast<int>(freqBinPSD[0]), 1, newThresh.size(0),
                         ib_emlrtBCI);
  }
  if (static_cast<int>(freqBinPSD[0]) != freqBinPSD.size(0)) {
    rtSizeEq1DError(static_cast<int>(freqBinPSD[0]), freqBinPSD.size(0),
                    h_emlrtECI);
  }
  b_newThresh.set_size(1, static_cast<int>(freqBinPSD[0]));
  for (k = 0; k < nxi; k++) {
    b_newThresh[k] = newThresh[static_cast<int>(freqBinPSD[k]) - 1];
  }
  nxi = b_newThresh.size(1);
  for (k = 0; k < nxi; k++) {
    newThresh[k] = b_newThresh[k];
  }
  // The (1) call is needed by coder, as it doesn't know that the find call
  // above will only produced a scalar output.
  if (ii.size(0) < 1) {
    rtDynamicBoundsError(1, 1, ii.size(0), jb_emlrtBCI);
  }
  if (ii[0] > newThresh.size(0)) {
    k = 0;
    i = 0;
  } else {
    if ((ii[0] < 1) || (ii[0] > newThresh.size(0))) {
      rtDynamicBoundsError(ii[0], 1, newThresh.size(0), kb_emlrtBCI);
    }
    k = ii[0] - 1;
    if (newThresh.size(0) < 1) {
      rtDynamicBoundsError(newThresh.size(0), 1, newThresh.size(0),
                           lb_emlrtBCI);
    }
    i = newThresh.size(0);
  }
  nxi = i - k;
  if (nxi != lastTrueThresh.size(0)) {
    rtSizeEq1DError(nxi, lastTrueThresh.size(0), i_emlrtECI);
  }
  for (i = 0; i < nxi; i++) {
    newThresh[k + i] = lastTrueThresh[i];
  }
  // The (1) call is needed by coder, as it doesn't know that the find call
  // above will only produced a scalar output. toc
  coder::interp1(Wfm.stft->f, newThresh, Wfm.Wf, threshVecFine);
}

static void uc_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "The required dimensions must be real, integer scalars > 1.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

void threshold::init()
{
  pf = 0.01;
  evMuParam = 0.0;
  evSigmaParam = 0.0;
  threshVecFine.set_size(1);
  threshVecFine[0] = 0.0;
}

void threshold::makenewthreshold(const waveform &Wfm)
{
  static rtBoundsCheckInfo cb_emlrtBCI{
      -1,                           // iFirst
      -1,                           // iLast
      157,                          // lineNo
      55,                           // colNo
      "Ssynth",                     // aName
      "threshold/makenewthreshold", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "threshold.m", // pName
      0              // checkKind
  };
  static rtRunTimeErrorInfo vc_emlrtRTEI{
      180,                                                      // lineNo
      1,                                                        // colNo
      "wgn",                                                    // fName
      "/Applications/MATLAB_R2023a.app/toolbox/comm/comm/wgn.m" // pName
  };
  static const char b_cv2[7]{'c', 'o', 'm', 'p', 'l', 'e', 'x'};
  static const char b_cv[6]{'l', 'i', 'n', 'e', 'a', 'r'};
  static const char b_cv1[6]{'l', 'i', 'n', 'e', 'a', 'r'};
  static const char b_cv3[3]{'d', 'b', 'w'};
  coder::b_anonymous_function theFunc;
  coder::sparse Wq;
  coder::array<creal_T, 3U> Ssynth;
  coder::array<creal_T, 2U> b_b;
  coder::array<creal_T, 2U> xsynth;
  coder::array<creal_T, 2U> y;
  coder::array<double, 2U> a;
  coder::array<double, 2U> b;
  coder::array<double, 2U> r2;
  coder::array<double, 1U> a__1;
  coder::array<double, 1U> a__2;
  coder::array<int, 2U> b_stftSz;
  coder::array<char, 2U> r;
  coder::array<char, 2U> r1;
  coder::array<char, 2U> switch_expression;
  double scores[100];
  double stftSz[2];
  double noisePower;
  double previousToc;
  double s_im;
  int aoffset;
  int exitg2;
  int i;
  int k;
  int loop_ub;
  int n;
  int ns;
  bool x[6];
  bool exitg1;
  bool overflow;
  // BUILDTHRESHOLD generates a threshold vector for the waveform argument
  // based on the false alarm probability input.
  //
  // This function creates a vector of thresholds for the incoherently summed
  // results of the data in the input waveform. The probability of false alarm
  // input is used for threshold generation. The output vector is a spectrally
  // tuned threshold for each frequency in the STFT of the waveform. These
  // thresholds are dependent on the power spectral density for each frequency
  // bin, so areas of the spectrum with a high noise floor will have a higher
  // output thresholde value
  //
  // INPUTS:
  //    Wfm     A single waveform object
  //    PF      A scalar probability of false alarm value (0 1];
  // OUTPUTS:
  //    newThresh   A vector of threshold with as many elements as rows in the
  //                S matrix of the wfmstft object within the Wfm input.
  //
  // Author:    Michael W. Shafer
  // Date:      2022-05-04
  // --------------------------------------------------------------------------
  theFunc.workspace.pf = pf;
  // This will be the reference power for the trials. Thresholds will be
  // interpolated for each bin from this value based on their bin power
  // median(freqBinPow);
  stftSz[0] = Wfm.stft->S.size(0);
  stftSz[1] = Wfm.stft->S.size(1);
  previousToc = coder::toc();
  std::printf("\n \t Building time correlation matrix ...");
  std::fflush(stdout);
  // Build the Wq time correlation matrix
  buildtimecorrelatormatrix(Wfm.N, Wfm.M, Wfm.J, Wfm.K, Wq);
  noisePower = coder::toc() - previousToc;
  std::printf("complete. Elapsed time: %f seconds \n", noisePower);
  std::fflush(stdout);
  previousToc = coder::toc();
  std::printf("\t Building synthetic data and taking STFTs ...");
  std::fflush(stdout);
  i = static_cast<int>(stftSz[1]);
  if (i != Wq.m) {
    rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
  }
  // Here we approximated the number of samples of synthetic noise data needed
  // to get the correct number of time windows. We over estimate here and then
  // clip the number of correct windows after the stft operation.
  s_im = (stftSz[1] + 1.0) * Wfm.n_ws + Wfm.n_ol;
  // Based on the STFT help file for the number of windows as a function of
  // samples. We add an additional windows worth of samples to ensure we have
  // enough in our STFT output. We'll clip off any excess after the STFT Number
  // of sets of synthetic noise to generate Preallocate the scores matrix
  // Calculate the total power in the waveform for all frequency bins. Units are
  // W/bin * # bins = W
  x[0] = (s_im <= 0.0);
  x[1] = false;
  x[2] = false;
  x[3] = false;
  x[4] = (s_im - std::floor(s_im) != 0.0);
  x[5] = false;
  overflow = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= 5)) {
    if (x[k]) {
      overflow = true;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (overflow) {
    uc_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
  }
  r.set((char *)&b_cv[0], 1, 6);
  ns = r.size(1);
  overflow = true;
  if (r.size(1) > 2147483646) {
    coder::check_forloop_overflow_error();
  }
  for (k = 0; k < ns; k++) {
    overflow = (overflow && (static_cast<unsigned char>(r[k]) <= 127));
  }
  if (!overflow) {
    yc_rtErrorWithMessageID(j_emlrtRTEI.fName, j_emlrtRTEI.lineNo);
  }
  switch_expression.set_size(1, r.size(1));
  aoffset = r.size(1);
  for (k = 0; k < aoffset; k++) {
    switch_expression[k] = cv1[static_cast<unsigned char>(r[k]) & 127];
  }
  overflow = false;
  if (switch_expression.size(1) == 6) {
    ns = 0;
    do {
      exitg2 = 0;
      if (ns < 6) {
        if (switch_expression[ns] != b_cv1[ns]) {
          exitg2 = 1;
        } else {
          ns++;
        }
      } else {
        overflow = true;
        exitg2 = 1;
      }
    } while (exitg2 == 0);
  }
  if (overflow) {
    ns = 0;
  } else {
    overflow = false;
    if (switch_expression.size(1) == 3) {
      ns = 0;
      do {
        exitg2 = 0;
        if (ns < 3) {
          if (switch_expression[ns] != b_cv3[ns]) {
            exitg2 = 1;
          } else {
            ns++;
          }
        } else {
          overflow = true;
          exitg2 = 1;
        }
      } while (exitg2 == 0);
    }
    if (overflow) {
      ns = 1;
    } else {
      ns = -1;
    }
  }
  switch (ns) {
  case 0:
    noisePower = stftSz[0];
    break;
  case 1:
    noisePower = rt_powd_snf(10.0, stftSz[0] / 10.0);
    break;
  default:
    noisePower = rt_powd_snf(10.0, (stftSz[0] - 30.0) / 10.0);
    break;
  }
  r1.set((char *)&b_cv2[0], 1, 7);
  overflow = false;
  if (r1.size(1) >= 1) {
    aoffset = static_cast<unsigned char>(r1[0]);
    if (aoffset > 127) {
      yc_rtErrorWithMessageID(j_emlrtRTEI.fName, j_emlrtRTEI.lineNo);
    }
    if (cv1[aoffset] == 'r') {
      overflow = true;
    }
  }
  if (overflow) {
    noisePower = std::sqrt(noisePower);
    coder::randn(s_im, b);
    xsynth.set_size(b.size(0), 100);
    loop_ub = b.size(0) * 100;
    for (aoffset = 0; aoffset < loop_ub; aoffset++) {
      xsynth[aoffset].re = noisePower * b[aoffset];
      xsynth[aoffset].im = 0.0;
    }
  } else {
    noisePower = std::sqrt(noisePower);
    coder::complexLike(s_im, xsynth);
    loop_ub = xsynth.size(0) * 100;
    xsynth.set_size(xsynth.size(0), 100);
    for (aoffset = 0; aoffset < loop_ub; aoffset++) {
      xsynth[aoffset].re = noisePower * xsynth[aoffset].re;
      xsynth[aoffset].im = noisePower * xsynth[aoffset].im;
    }
  }
  // Generate the synthetic data
  coder::stft(xsynth, Wfm.Fs, Wfm.stft->wind, Wfm.n_ol, Wfm.n_w, Ssynth, a__1,
              a__2);
  loop_ub = Ssynth.size(1) - i;
  b_stftSz.set_size(1, loop_ub);
  for (aoffset = 0; aoffset < loop_ub; aoffset++) {
    b_stftSz[aoffset] = (i + aoffset) + 1;
  }
  coder::internal::nullAssignment(Ssynth, b_stftSz);
  // Trim excess so we have the correct number of windows.
  noisePower = coder::toc() - previousToc;
  std::printf("complete. Elapsed time: %f seconds \n", noisePower);
  std::fflush(stdout);
  previousToc = coder::toc();
  std::printf("\t Running pulse summing process for all datasets ...");
  std::fflush(stdout);
  // Preform the incoherent summation using a matrix multiply.
  // Could use pagetimes.m for this, but it isn't supported for
  // code generation with sparse matrices as of R2023a
  loop_ub = Ssynth.size(1);
  n = Ssynth.size(1);
  overflow = (Ssynth.size(1) > 2147483646);
  for (int b_i{0}; b_i < 100; b_i++) {
    int inner;
    int m;
    if (b_i + 1 > Ssynth.size(2)) {
      rtDynamicBoundsError(b_i + 1, 1, Ssynth.size(2), cb_emlrtBCI);
    }
    b_b.set_size(Ssynth.size(0), Ssynth.size(1));
    for (i = 0; i < loop_ub; i++) {
      ns = Ssynth.size(0);
      for (aoffset = 0; aoffset < ns; aoffset++) {
        b_b[aoffset + b_b.size(0) * i] =
            Ssynth[(aoffset + Ssynth.size(0) * i) +
                   Ssynth.size(0) * Ssynth.size(1) * b_i];
      }
    }
    inner = Wfm.W.size(0);
    if (inner != Ssynth.size(0)) {
      if (((inner == 1) && (Wfm.W.size(1) == 1)) ||
          ((Ssynth.size(0) == 1) && (Ssynth.size(1) == 1))) {
        bc_rtErrorWithMessageID(ec_emlrtRTEI.fName, ec_emlrtRTEI.lineNo);
      } else {
        qb_rtErrorWithMessageID(fc_emlrtRTEI.fName, fc_emlrtRTEI.lineNo);
      }
    }
    m = Wfm.W.size(1);
    y.set_size(m, Ssynth.size(1));
    if (overflow) {
      coder::check_forloop_overflow_error();
    }
    for (int j{0}; j < n; j++) {
      int boffset;
      int coffset;
      coffset = j * m;
      boffset = j * Ssynth.size(0);
      if (m > 2147483646) {
        coder::check_forloop_overflow_error();
      }
      for (int c_i{0}; c_i < m; c_i++) {
        aoffset = c_i * Wfm.W.size(0);
        noisePower = 0.0;
        s_im = 0.0;
        if (inner > 2147483646) {
          coder::check_forloop_overflow_error();
        }
        for (k = 0; k < inner; k++) {
          double Wfm_im;
          double Wfm_re;
          double Wfm_re_tmp;
          double b_Wfm_re_tmp;
          ns = aoffset + k;
          Wfm_re = Wfm.W[ns].re;
          Wfm_im = -Wfm.W[ns].im;
          ns = boffset + k;
          Wfm_re_tmp = b_b[ns].im;
          b_Wfm_re_tmp = b_b[ns].re;
          noisePower += Wfm_re * b_Wfm_re_tmp - Wfm_im * Wfm_re_tmp;
          s_im += Wfm_re * Wfm_re_tmp + Wfm_im * b_Wfm_re_tmp;
        }
        i = coffset + c_i;
        y[i].re = noisePower;
        y[i].im = s_im;
      }
    }
    ns = y.size(0) * y.size(1);
    a.set_size(y.size(0), y.size(1));
    if (ns > 2147483646) {
      coder::check_forloop_overflow_error();
    }
    for (k = 0; k < ns; k++) {
      a[k] = rt_hypotd_snf(y[k].re, y[k].im);
    }
    r2.set_size(a.size(0), a.size(1));
    ns = a.size(0) * a.size(1);
    for (i = 0; i < ns; i++) {
      s_im = a[i];
      r2[i] = s_im * s_im;
    }
    Wq.mtimes(r2, a);
    ns = a.size(0) * a.size(1);
    a__1 = a.reshape(ns);
    scores[b_i] = coder::internal::unaryMinOrMax_anonFcn1(a__1);
    // 'all' call finds max across all temporal correlation sets and frequency
    // bins just like we do in the dectection code.
  }
  noisePower = coder::toc() - previousToc;
  std::printf("complete. Elapsed time: %f seconds \n", noisePower);
  std::fflush(stdout);
  previousToc = coder::toc();
  std::printf("\t Extracing extreme value fit parameters ...");
  std::fflush(stdout);
  // Build the distribution for all scores.
  // Old kernel density estimation method
  //  [f,xi]   =
  //  ksdensity(scores(:),'BoundaryCorrection','reflection','Support','positive');
  //  F        = cumtrapz(xi,f);
  // Updated extreme value estimation method
  // xi = linspace(1/2*min(scores),2*max(scores),1000);
  // paramEstsMaxima = evfit(-scores);
  // cdfVals = evcdf(-xi,paramEstsMaxima(1),paramEstsMaxima(2));
  // F = 1 - cdfVals;
  for (i = 0; i < 100; i++) {
    scores[i] = -scores[i];
  }
  coder::evfit(scores, stftSz);
  theFunc.workspace.mu = stftSz[0];
  theFunc.workspace.sigma = stftSz[1];
  // theFunc = @(x) 1-exp(-exp((x-mu)/sigma));%Equivalent to evcdf(x,mu,sigma)
  // theFunc = @(x) exp(-exp((x-mu)/sigma));%Equivalent to 1-evcdf(x,mu,sigma)
  // Equivalent to 1-evcdf(x,mu,sigma)-pf
  s_im = coder::fzero(theFunc);
  // theFunc monitonically decrease, so starting at x = 0 should always converge
  noisePower = coder::toc() - previousToc;
  std::printf("complete. Elapsed time: %f seconds \n", noisePower);
  std::fflush(stdout);
  coder::toc();
  // figure;plot(xi,F)
  // Uncomment to see how fitted distribution compares to histogram of max
  // scores
  //              p = evpdf(-xi,paramEstsMaxima(1),paramEstsMaxima(2));
  //              figure
  //              histogram(scores,'Normalization','pdf');
  //              hold on
  //              plot(xi,p,'DisplayName','EV Fit'); legend('Location','best')
  //              p = 1-evcdf(-xi,paramEstsMaxima(1),paramEstsMaxima(2));
  //              figure
  //              histogram(scores,'Normalization','cdf');
  //              hold on
  //              plot(xi,p,'DisplayName','EV Fit'); legend('Location','best')
  // Now we linearly interpolate the threshold values for different noise
  // powers. We showed elsewhere this linear relationship hold by calculating
  // thresholds for ranges of noise power.
  // Here we deal with points where there is no change in F. Interp needs
  // unique values and at the tails of the distibution, there may be repeated
  // values.
  // nochangelogic = [false,diff(F)==0];
  // threshMedPow =
  // interp1(F(~nochangelogic),xi(~nochangelogic),1-PF,'pchip','extrap');
  //              powGrid    = [0 medPowAllFreqBins];
  //              threshGrid = [0 threshMedPow];
  //              newThresh =
  //              interp1(powGrid,threshGrid,freqBinPow,'linear','extrap');
  //
  //              %Finally,extrapolating the thresholds that are a little beyond
  //              the original %frequeny range can result in negative
  //              thresholds. Here we copy the first %and last valid threshold
  //              out to the places where the extrapolations would %have occured
  //              isnanThreshLogic   = isnan(newThresh);
  //              firstTrueThreshInd = find(~isnanThreshLogic,1,'first');
  //              lastTrueThreshInd  = find(~isnanThreshLogic,1,'last');
  //              firstTrueThresh    = newThresh(firstTrueThreshInd);
  //              lastTrueThresh     = newThresh(lastTrueThreshInd);
  //              newThresh(1:firstTrueThreshInd(1))  = firstTrueThresh; %The
  //              (1) call is needed by coder, as it doesn't know that the find
  //              call above will only produced a scalar output.
  //              newThresh(lastTrueThreshInd(1):end) = lastTrueThresh; %The (1)
  //              call is needed by coder, as it doesn't know that the find call
  //              above will only produced a scalar output. %toc
  //
  //              obj.thresh1W        = threshMedPow;
  //              obj.threshVecCoarse = newThresh;
  //              obj.threshVecFine   =
  //              interp1(Wfm.stft.f,double(newThresh),Wfm.Wf,'linear','extrap');
  evMuParam = stftSz[0];
  evSigmaParam = stftSz[1];
  setthreshprops(s_im, Wfm);
}

void threshold::setthreshold(const waveform &WfmCurr, const waveform *WfmPrev)
{
  coder::b_anonymous_function theFunc;
  coder::array<char, 2U> varargin_1;
  coder::array<char, 2U> whatChanged;
  int i;
  bool b;
  bool needsUpdate;
  // Wq depends on N M J K
  // if old and new N, M, J, K, W, Wf are the same
  //    copy over the fit parameters from prev to curr then
  //    use the updatepf method to set the others
  // else
  //    use the makenewthreshold method to build out
  whatChanged.set_size(1, 0);
  if (WfmCurr.N != WfmPrev->N) {
    whatChanged.set_size(whatChanged.size(0), 2);
    whatChanged[0] = 'N';
    whatChanged[1] = ' ';
  }
  if (WfmCurr.M != WfmPrev->M) {
    i = whatChanged.size(1);
    whatChanged.set_size(whatChanged.size(0), whatChanged.size(1) + 2);
    whatChanged[i] = 'M';
    whatChanged[i + 1] = ' ';
  }
  if (WfmCurr.J != WfmPrev->J) {
    i = whatChanged.size(1);
    whatChanged.set_size(whatChanged.size(0), whatChanged.size(1) + 2);
    whatChanged[i] = 'J';
    whatChanged[i + 1] = ' ';
  }
  if (WfmCurr.K != WfmPrev->K) {
    i = whatChanged.size(1);
    whatChanged.set_size(whatChanged.size(0), whatChanged.size(1) + 2);
    whatChanged[i] = 'K';
    whatChanged[i + 1] = ' ';
  }
  needsUpdate = (WfmCurr.N != WfmPrev->N);
  b = (WfmCurr.M != WfmPrev->M);
  needsUpdate = (needsUpdate || b);
  b = (WfmCurr.J != WfmPrev->J);
  needsUpdate = (needsUpdate || b);
  b = (WfmCurr.K != WfmPrev->K);
  needsUpdate = (needsUpdate || b);
  // W and Wf both affect the thresholds as well, but they only depend on
  // --zetas (never changes)
  // --fftlength of the stft (never changes)
  // --time domain pulse template (never changes)
  // --waveform sample rate (never changes)
  // --ps_pre.t_p (never changes)
  // Thus we don't need to check if W or Wf changes. Note that the
  // code below was causing issue with generated code. In code
  // generation these any(WfmCurr.W ~= WfmPrev.W , 'all') was
  // coming back true even though when looking at the matrices,
  // they looked identical. (Numerical precision error?)
  // needsUpdate = needsUpdate | any(WfmCurr.W ~= WfmPrev.W,'all');
  // needsUpdate = needsUpdate | any(WfmCurr.Wf ~= WfmPrev.Wf,'all');
  if (needsUpdate) {
    int loop_ub;
    varargin_1.set_size(1, whatChanged.size(1) + 1);
    loop_ub = whatChanged.size(1);
    for (i = 0; i < loop_ub; i++) {
      varargin_1[i] = whatChanged[i];
    }
    varargin_1[whatChanged.size(1)] = '\x00';
    std::printf("Thresholds need updating because %s. \n", &varargin_1[0]);
    std::fflush(stdout);
    makenewthreshold(WfmCurr);
  } else {
    double thresh;
    double val;
    thresh = WfmPrev->thresh.evMuParam;
    evMuParam = thresh;
    val = WfmPrev->thresh.evSigmaParam;
    evSigmaParam = val;
    // fprintf('%f\n',obj.evMuParam)
    // fprintf('%f\n',obj.pf)
    theFunc.workspace.mu = thresh;
    theFunc.workspace.sigma = val;
    theFunc.workspace.pf = pf;
    // theFunc = @(x) 1-exp(-exp((x-mu)/sigma));%Equivalent to evcdf(x,mu,sigma)
    // theFunc = @(x) exp(-exp((x-mu)/sigma));%Equivalent to 1-evcdf(x,mu,sigma)
    // Equivalent to 1-evcdf(x,mu,sigma)-pf
    thresh = coder::fzero(theFunc);
    // theFunc monitonically decrease, so starting at x = 0 should always
    // converge Build a single threshold value at 1 W bin power
    setthreshprops(thresh, WfmCurr);
    // Set thresholds for each bin based on their bin powers
    // Not actually updating the pf, just using the method to set all the other
    // parameters
  }
}

// End of code generation (threshold.cpp)
