//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// buildtimecorrelatormatrix.cpp
//
// Code generation for function 'buildtimecorrelatormatrix'
//

// Include files
#include "buildtimecorrelatormatrix.h"
#include "assembleWq.h"
#include "assertValidSizeArg.h"
#include "colon.h"
#include "eml_int_forloop_overflow_check.h"
#include "minOrMax.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "sparse.h"
#include "sparse1.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "unique.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <string>

// Function Declarations
static void kb_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
static void kb_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Domain error. To compute complex results, make at least one "
               "input complex, e.g. \'power(complex(a),b)\'.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

void buildtimecorrelatormatrix(double pri, double priUncert, double priJtr,
                               double reps, coder::sparse &Wq)
{
  static rtBoundsCheckInfo cb_emlrtBCI{
      -1,                              // iFirst
      -1,                              // iLast
      31,                              // lineNo
      27,                              // colNo
      "pulse_position_matrix",         // aName
      "generate_pulse_positions_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "generate_pulse_positions_func.m", // pName
      0                                  // checkKind
  };
  static rtBoundsCheckInfo db_emlrtBCI{
      -1,                              // iFirst
      -1,                              // iLast
      36,                              // lineNo
      23,                              // colNo
      "pulse_position_value",          // aName
      "generate_pulse_positions_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "generate_pulse_positions_func.m", // pName
      0                                  // checkKind
  };
  static rtBoundsCheckInfo eb_emlrtBCI{
      -1,                              // iFirst
      -1,                              // iLast
      42,                              // lineNo
      42,                              // colNo
      "PRI_mean_value",                // aName
      "generate_pulse_positions_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "generate_pulse_positions_func.m", // pName
      0                                  // checkKind
  };
  static rtBoundsCheckInfo fb_emlrtBCI{
      -1,                              // iFirst
      -1,                              // iLast
      42,                              // lineNo
      69,                              // colNo
      "PRI_jitter_value",              // aName
      "generate_pulse_positions_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "generate_pulse_positions_func.m", // pName
      0                                  // checkKind
  };
  static rtBoundsCheckInfo gb_emlrtBCI{
      -1,                              // iFirst
      -1,                              // iLast
      41,                              // lineNo
      35,                              // colNo
      "pulse_position_value",          // aName
      "generate_pulse_positions_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "generate_pulse_positions_func.m", // pName
      0                                  // checkKind
  };
  static rtBoundsCheckInfo hb_emlrtBCI{
      -1,                              // iFirst
      -1,                              // iLast
      41,                              // lineNo
      38,                              // colNo
      "pulse_position_value",          // aName
      "generate_pulse_positions_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "generate_pulse_positions_func.m", // pName
      0                                  // checkKind
  };
  static rtBoundsCheckInfo ib_emlrtBCI{
      -1,                              // iFirst
      -1,                              // iLast
      41,                              // lineNo
      48,                              // colNo
      "pulse_position_value",          // aName
      "generate_pulse_positions_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "generate_pulse_positions_func.m", // pName
      0                                  // checkKind
  };
  static rtBoundsCheckInfo jb_emlrtBCI{
      -1,                              // iFirst
      -1,                              // iLast
      71,                              // lineNo
      75,                              // colNo
      "pulse_position_value",          // aName
      "generate_pulse_positions_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "generate_pulse_positions_func.m", // pName
      0                                  // checkKind
  };
  static rtBoundsCheckInfo kb_emlrtBCI{
      -1,                    // iFirst
      -1,                    // iLast
      31,                    // lineNo
      32,                    // colNo
      "C",                   // aName
      "cartesian_prod_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "cartesian_prod_func.m", // pName
      0                        // checkKind
  };
  static rtBoundsCheckInfo lb_emlrtBCI{
      -1,                    // iFirst
      -1,                    // iLast
      31,                    // lineNo
      9,                     // colNo
      "A",                   // aName
      "cartesian_prod_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "cartesian_prod_func.m", // pName
      0                        // checkKind
  };
  static rtBoundsCheckInfo mb_emlrtBCI{
      -1,                    // iFirst
      -1,                    // iLast
      31,                    // lineNo
      12,                    // colNo
      "C",                   // aName
      "cartesian_prod_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "cartesian_prod_func.m", // pName
      0                        // checkKind
  };
  static rtBoundsCheckInfo nb_emlrtBCI{
      -1,                    // iFirst
      -1,                    // iLast
      31,                    // lineNo
      17,                    // colNo
      "C",                   // aName
      "cartesian_prod_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "cartesian_prod_func.m", // pName
      0                        // checkKind
  };
  static rtBoundsCheckInfo ob_emlrtBCI{
      -1,                              // iFirst
      -1,                              // iLast
      72,                              // lineNo
      30,                              // colNo
      "pulse_position_matrix",         // aName
      "generate_pulse_positions_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "generate_pulse_positions_func.m", // pName
      0                                  // checkKind
  };
  static rtBoundsCheckInfo pb_emlrtBCI{
      -1,                              // iFirst
      -1,                              // iLast
      72,                              // lineNo
      55,                              // colNo
      "pulse_position_matrix",         // aName
      "generate_pulse_positions_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "generate_pulse_positions_func.m", // pName
      0                                  // checkKind
  };
  static rtDoubleCheckInfo ab_emlrtDCI{
      16,                          // lineNo
      24,                          // colNo
      "buildtimecorrelatormatrix", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "buildtimecorrelatormatrix.m", // pName
      4                              // checkKind
  };
  static rtDoubleCheckInfo bb_emlrtDCI{
      16,                          // lineNo
      24,                          // colNo
      "buildtimecorrelatormatrix", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "buildtimecorrelatormatrix.m", // pName
      1                              // checkKind
  };
  static rtDoubleCheckInfo cb_emlrtDCI{
      29,                              // lineNo
      32,                              // colNo
      "generate_pulse_positions_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "generate_pulse_positions_func.m", // pName
      4                                  // checkKind
  };
  static rtDoubleCheckInfo db_emlrtDCI{
      29,                              // lineNo
      32,                              // colNo
      "generate_pulse_positions_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "generate_pulse_positions_func.m", // pName
      1                                  // checkKind
  };
  static rtDoubleCheckInfo eb_emlrtDCI{
      29,                              // lineNo
      50,                              // colNo
      "generate_pulse_positions_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "generate_pulse_positions_func.m", // pName
      4                                  // checkKind
  };
  static rtDoubleCheckInfo fb_emlrtDCI{
      29,                              // lineNo
      50,                              // colNo
      "generate_pulse_positions_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "generate_pulse_positions_func.m", // pName
      1                                  // checkKind
  };
  static rtDoubleCheckInfo gb_emlrtDCI{
      31,                              // lineNo
      39,                              // colNo
      "generate_pulse_positions_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "generate_pulse_positions_func.m", // pName
      1                                  // checkKind
  };
  static rtDoubleCheckInfo hb_emlrtDCI{
      35,                              // lineNo
      31,                              // colNo
      "generate_pulse_positions_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "generate_pulse_positions_func.m", // pName
      1                                  // checkKind
  };
  static rtDoubleCheckInfo ib_emlrtDCI{
      35,                              // lineNo
      1,                               // colNo
      "generate_pulse_positions_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "generate_pulse_positions_func.m", // pName
      1                                  // checkKind
  };
  static rtDoubleCheckInfo jb_emlrtDCI{
      59,                              // lineNo
      32,                              // colNo
      "generate_pulse_positions_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "generate_pulse_positions_func.m", // pName
      4                                  // checkKind
  };
  static rtDoubleCheckInfo kb_emlrtDCI{
      59,                              // lineNo
      32,                              // colNo
      "generate_pulse_positions_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "generate_pulse_positions_func.m", // pName
      1                                  // checkKind
  };
  static rtDoubleCheckInfo lb_emlrtDCI{
      59,                              // lineNo
      55,                              // colNo
      "generate_pulse_positions_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "generate_pulse_positions_func.m", // pName
      4                                  // checkKind
  };
  static rtDoubleCheckInfo mb_emlrtDCI{
      5,            // lineNo
      1,            // colNo
      "assembleWq", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "assembleWq.m", // pName
      1               // checkKind
  };
  static rtDoubleCheckInfo nb_emlrtDCI{
      13,                    // lineNo
      12,                    // colNo
      "cartesian_prod_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "cartesian_prod_func.m", // pName
      4                        // checkKind
  };
  static rtDoubleCheckInfo ob_emlrtDCI{
      13,                    // lineNo
      12,                    // colNo
      "cartesian_prod_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "cartesian_prod_func.m", // pName
      1                        // checkKind
  };
  static rtDoubleCheckInfo pb_emlrtDCI{
      71,                              // lineNo
      5,                               // colNo
      "generate_pulse_positions_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "generate_pulse_positions_func.m", // pName
      1                                  // checkKind
  };
  static rtDoubleCheckInfo qb_emlrtDCI{
      31,                    // lineNo
      12,                    // colNo
      "cartesian_prod_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "cartesian_prod_func.m", // pName
      1                        // checkKind
  };
  static rtDoubleCheckInfo rb_emlrtDCI{
      31,                    // lineNo
      17,                    // colNo
      "cartesian_prod_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "cartesian_prod_func.m", // pName
      1                        // checkKind
  };
  static rtDoubleCheckInfo sb_emlrtDCI{
      72,                              // lineNo
      30,                              // colNo
      "generate_pulse_positions_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "generate_pulse_positions_func.m", // pName
      1                                  // checkKind
  };
  static rtDoubleCheckInfo tb_emlrtDCI{
      72,                              // lineNo
      55,                              // colNo
      "generate_pulse_positions_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "generate_pulse_positions_func.m", // pName
      1                                  // checkKind
  };
  static rtDoubleCheckInfo ub_emlrtDCI{
      75,                              // lineNo
      20,                              // colNo
      "generate_pulse_positions_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "generate_pulse_positions_func.m", // pName
      1                                  // checkKind
  };
  static rtDoubleCheckInfo
      w_emlrtDCI{
          59,       // lineNo
          66,       // colNo
          "repmat", // fName
          "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/"
          "repmat.m", // pName
          4           // checkKind
      };
  static rtDoubleCheckInfo x_emlrtDCI{
      15,                          // lineNo
      24,                          // colNo
      "buildtimecorrelatormatrix", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "buildtimecorrelatormatrix.m", // pName
      4                              // checkKind
  };
  static rtDoubleCheckInfo y_emlrtDCI{
      15,                          // lineNo
      24,                          // colNo
      "buildtimecorrelatormatrix", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "buildtimecorrelatormatrix.m", // pName
      1                              // checkKind
  };
  static rtEqualityCheckInfo h_emlrtECI{
      1,            // nDims
      55,           // lineNo
      15,           // colNo
      "assembleWq", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "assembleWq.m" // pName
  };
  static rtEqualityCheckInfo i_emlrtECI{
      -1,                          // nDims
      24,                          // lineNo
      5,                           // colNo
      "buildtimecorrelatormatrix", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "buildtimecorrelatormatrix.m" // pName
  };
  static rtEqualityCheckInfo j_emlrtECI{
      -1,                          // nDims
      25,                          // lineNo
      5,                           // colNo
      "buildtimecorrelatormatrix", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "buildtimecorrelatormatrix.m" // pName
  };
  static rtEqualityCheckInfo k_emlrtECI{
      -1,                              // nDims
      31,                              // lineNo
      1,                               // colNo
      "generate_pulse_positions_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "generate_pulse_positions_func.m" // pName
  };
  static rtEqualityCheckInfo l_emlrtECI{
      -1,                              // nDims
      72,                              // lineNo
      5,                               // colNo
      "generate_pulse_positions_func", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "generate_pulse_positions_func.m" // pName
  };
  static rtEqualityCheckInfo m_emlrtECI{
      2,            // nDims
      55,           // lineNo
      15,           // colNo
      "assembleWq", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "assembleWq.m" // pName
  };
  static rtRunTimeErrorInfo vc_emlrtRTEI{
      82,         // lineNo
      5,          // colNo
      "fltpower", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/ops/power.m" // pName
  };
  coder::array<double, 3U> pulse_position_value;
  coder::array<double, 2U> WqRowInds;
  coder::array<double, 2U> pattern_matrix;
  coder::array<double, 2U> priJtrList;
  coder::array<double, 2U> priMeansList;
  coder::array<double, 2U> pulsePositionMatrix;
  coder::array<double, 2U> shiftermat;
  coder::array<double, 1U> b_WqRowInds;
  coder::array<double, 1U> b_priMeansList;
  coder::array<double, 1U> r;
  double d;
  double n_rows;
  double num_PRI_patterns;
  double num_position_patterns;
  double stride;
  int sizes[2];
  int i;
  int i1;
  int i2;
  int i3;
  int i4;
  int i5;
  int iacol;
  int ibcol;
  int ibmat;
  int ncols;
  int nrows;
  int num_PRI_jitters;
  int num_members_per_set;
  int outsize_idx_1;
  int result;
  signed char input_sizes_idx_1;
  bool empty_non_axis_sizes;
  // UNTITLED Summary of this function goes here
  //    Detailed explanation goes here
  // First check to make sure all inputs contain the same number of
  // elements
  d = 2.0 * priUncert + 1.0;
  if (!(d >= 0.0)) {
    rtNonNegativeError(d, x_emlrtDCI);
  }
  if (d != static_cast<int>(std::floor(d))) {
    rtIntegerError(d, y_emlrtDCI);
  }
  num_PRI_patterns = 2.0 * priJtr + 1.0;
  if (!(num_PRI_patterns >= 0.0)) {
    rtNonNegativeError(num_PRI_patterns, ab_emlrtDCI);
  }
  if (num_PRI_patterns != static_cast<int>(std::floor(num_PRI_patterns))) {
    rtIntegerError(num_PRI_patterns, bb_emlrtDCI);
  }
  // Change names to align with other code.
  if (std::isnan(-priUncert) || std::isnan(priUncert)) {
    priJtrList.set_size(1, 1);
    priJtrList[0] = rtNaN;
  } else if (priUncert < -priUncert) {
    priJtrList.set_size(1, 0);
  } else if ((std::isinf(-priUncert) || std::isinf(priUncert)) &&
             (-priUncert == priUncert)) {
    priJtrList.set_size(1, 1);
    priJtrList[0] = rtNaN;
  } else if (std::floor(-priUncert) == -priUncert) {
    ncols = static_cast<int>(priUncert - (-priUncert));
    priJtrList.set_size(1, ncols + 1);
    for (i = 0; i <= ncols; i++) {
      priJtrList[i] = -priUncert + static_cast<double>(i);
    }
  } else {
    coder::eml_float_colon(-priUncert, priUncert, priJtrList);
  }
  if (static_cast<int>(d) != priJtrList.size(1)) {
    rtSizeEq1DError(static_cast<int>(d), priJtrList.size(1), i_emlrtECI);
  }
  priMeansList.set_size(1, priJtrList.size(1));
  ncols = priJtrList.size(1);
  for (i = 0; i < ncols; i++) {
    priMeansList[i] = pri + priJtrList[i];
  }
  if (std::isnan(-priJtr) || std::isnan(priJtr)) {
    priJtrList.set_size(1, 1);
    priJtrList[0] = rtNaN;
  } else if (priJtr < -priJtr) {
    priJtrList.set_size(1, 0);
  } else if ((std::isinf(-priJtr) || std::isinf(priJtr)) &&
             (-priJtr == priJtr)) {
    priJtrList.set_size(1, 1);
    priJtrList[0] = rtNaN;
  } else if (std::floor(-priJtr) == -priJtr) {
    ncols = static_cast<int>(priJtr - (-priJtr));
    priJtrList.set_size(1, ncols + 1);
    for (i = 0; i <= ncols; i++) {
      priJtrList[i] = -priJtr + static_cast<double>(i);
    }
  } else {
    coder::eml_float_colon(-priJtr, priJtr, priJtrList);
  }
  if (static_cast<int>(num_PRI_patterns) != priJtrList.size(1)) {
    rtSizeEq1DError(static_cast<int>(num_PRI_patterns), priJtrList.size(1),
                    j_emlrtECI);
  }
  // PPM Contains the column positions (time windows) in the S matrix to search
  // for the K pulses assuming the first pulse arrives at window 1.
  //  generate_pulse_positions_func.m
  //  INPUTS:
  //    PRI_mean_value          row vector of PRI means (scale/index is STFT
  //    step
  //                            size)
  //
  //    PRI_jitter_value        row vector of jitter values (scale/index is STFT
  //    step
  //                            size)
  //
  //    K                       number of pulses forming the pattern
  //
  //  OUTPUTS:
  //    pulse_position_matrix   row is a pattern; each pattern has K pulse
  //                            position values
  //
  //  CALLS:
  //                            cartesion_prod_func()
  //
  //  Author: Paul G. Flikkema
  //  Date:   1 Oct 2021
  num_PRI_jitters = priJtrList.size(1);
  nrows = priJtrList.size(1);
  if ((nrows < 0) && (!std::isnan(reps - 1.0)) &&
      (std::floor(reps - 1.0) != reps - 1.0)) {
    kb_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
  }
  num_PRI_patterns = static_cast<double>(priMeansList.size(1)) *
                     rt_powd_snf(static_cast<double>(nrows), reps - 1.0);
  if (!(num_PRI_patterns >= 0.0)) {
    rtNonNegativeError(num_PRI_patterns, cb_emlrtDCI);
  }
  i = static_cast<int>(std::floor(num_PRI_patterns));
  if (num_PRI_patterns != i) {
    rtIntegerError(num_PRI_patterns, db_emlrtDCI);
  }
  if (!(reps >= 0.0)) {
    rtNonNegativeError(reps, eb_emlrtDCI);
  }
  i1 = static_cast<int>(std::floor(reps));
  if (reps != i1) {
    rtIntegerError(reps, fb_emlrtDCI);
  }
  //  place first pulse at pulse position q = 1
  if (reps < 1.0) {
    rtDynamicBoundsError(1, 1, static_cast<int>(reps), cb_emlrtBCI);
  }
  outsize_idx_1 = static_cast<int>(num_PRI_patterns);
  if (outsize_idx_1 != i) {
    rtIntegerError(num_PRI_patterns, gb_emlrtDCI);
  }
  rtSubAssignSizeCheck(&outsize_idx_1, 1, &outsize_idx_1, 1, k_emlrtECI);
  //  based on the model, generate all the pulse position values in a 3D matrix
  //  pulse_position_value(k, i_position, i_mean )
  i = static_cast<int>(reps);
  if (i != i1) {
    rtIntegerError(reps, hb_emlrtDCI);
  }
  pulse_position_value.set_size(i, priJtrList.size(1), priMeansList.size(1));
  if (i != i1) {
    rtIntegerError(reps, ib_emlrtDCI);
  }
  ncols = i * priJtrList.size(1) * priMeansList.size(1);
  for (i1 = 0; i1 < ncols; i1++) {
    pulse_position_value[i1] = 0.0;
  }
  if (reps < 1.0) {
    rtDynamicBoundsError(1, 1, static_cast<int>(reps), db_emlrtBCI);
  }
  ncols = priMeansList.size(1);
  for (i1 = 0; i1 < ncols; i1++) {
    outsize_idx_1 = priJtrList.size(1);
    for (i2 = 0; i2 < outsize_idx_1; i2++) {
      pulse_position_value[pulse_position_value.size(0) * i2 +
                           pulse_position_value.size(0) *
                               pulse_position_value.size(1) * i1] = 1.0;
    }
  }
  //  first pulse is always in position 1
  //  loop through the mean PRI values
  i1 = priMeansList.size(1);
  for (outsize_idx_1 = 0; outsize_idx_1 < i1; outsize_idx_1++) {
    i2 = i - 1;
    for (int k{0}; k < i2; k++) {
      for (nrows = 0; nrows < num_PRI_jitters; nrows++) {
        if (outsize_idx_1 + 1 > priMeansList.size(1)) {
          rtDynamicBoundsError(outsize_idx_1 + 1, 1, priMeansList.size(1),
                               eb_emlrtBCI);
        }
        if (nrows + 1 > priJtrList.size(1)) {
          rtDynamicBoundsError(nrows + 1, 1, priJtrList.size(1), fb_emlrtBCI);
        }
        if (static_cast<int>(static_cast<unsigned int>(k) + 2U) >
            pulse_position_value.size(0)) {
          rtDynamicBoundsError(
              static_cast<int>(static_cast<unsigned int>(k) + 2U), 1,
              pulse_position_value.size(0), gb_emlrtBCI);
        }
        if (nrows + 1 > pulse_position_value.size(1)) {
          rtDynamicBoundsError(nrows + 1, 1, pulse_position_value.size(1),
                               hb_emlrtBCI);
        }
        if (outsize_idx_1 + 1 > pulse_position_value.size(2)) {
          rtDynamicBoundsError(outsize_idx_1 + 1, 1,
                               pulse_position_value.size(2), ib_emlrtBCI);
        }
        pulse_position_value[((k + pulse_position_value.size(0) * nrows) +
                              pulse_position_value.size(0) *
                                  pulse_position_value.size(1) *
                                  outsize_idx_1) +
                             1] = (((static_cast<double>(k) + 2.0) - 1.0) *
                                       priMeansList[outsize_idx_1] +
                                   1.0) +
                                  priJtrList[nrows];
      }
    }
  }
  //  generate the pulse_position_matrix by considering
  //  all possible combinations of the values;
  //  each row is for one pattern, there are K columns;
  //  pulse_position_matrix( i_pattern, k)
  //
  //  The number of columns is the number of possible positions
  //
  //  we generate a num_PRI_jitters^(K-1) x K matrix
  //  using the function cartesian_prod_func
  //
  //  we stack matrices vertically into the pulse_position_matrix
  nrows = priJtrList.size(1);
  outsize_idx_1 = static_cast<int>(reps) - 1;
  num_position_patterns = static_cast<double>(priMeansList.size(1)) *
                          rt_powd_snf(static_cast<double>(nrows),
                                      static_cast<double>(outsize_idx_1));
  if (!(num_position_patterns >= 0.0)) {
    rtNonNegativeError(num_position_patterns, jb_emlrtDCI);
  }
  i = static_cast<int>(std::floor(num_position_patterns));
  if (num_position_patterns != i) {
    rtIntegerError(num_position_patterns, kb_emlrtDCI);
  }
  result = static_cast<int>(num_position_patterns);
  pulsePositionMatrix.set_size(result, pulsePositionMatrix.size(1));
  if (!(reps - 1.0 >= 0.0)) {
    rtNonNegativeError(reps - 1.0, lb_emlrtDCI);
  }
  pulsePositionMatrix.set_size(pulsePositionMatrix.size(0), outsize_idx_1);
  if (result != i) {
    rtIntegerError(num_position_patterns, mb_emlrtDCI);
  }
  ncols = result * outsize_idx_1;
  for (i1 = 0; i1 < ncols; i1++) {
    pulsePositionMatrix[i1] = 0.0;
  }
  nrows = priJtrList.size(1);
  n_rows = rt_powd_snf(static_cast<double>(nrows),
                       static_cast<double>(outsize_idx_1));
  //  number of rows per PRI mean
  i1 = priMeansList.size(1);
  if (priMeansList.size(1) - 1 >= 0) {
    if (pulse_position_value.size(0) < 2) {
      i3 = 1;
      i4 = 0;
    } else {
      i3 = 2;
      i4 = pulse_position_value.size(0);
    }
    num_members_per_set = pulse_position_value.size(1);
    i5 = i4 - i3;
  }
  for (int i_set{0}; i_set < i1; i_set++) {
    //      % DEBUG
    //      a = [ 1 1 1 ]; b = [ 309 310 311 ]; c = [ 618 619 620 ];
    //      A = [ a; b; c ];
    //  since pattern is "fundamental" pattern starting with a pulse in the
    //  first STFT window, we only need to look at combinations
    //  rows 2:end, and then add the column of ones
    if (i_set + 1 > pulse_position_value.size(2)) {
      rtDynamicBoundsError(i_set + 1, 1, pulse_position_value.size(2),
                           jb_emlrtBCI);
    }
    //    returns the Cartesian product C of the (values in the) rows
    //    of the input matrix A.
    //    Each row of A is taken as a set to draw from
    //    Assumes all sets have the same number of members
    outsize_idx_1 = i4 - i3;
    nrows = pulse_position_value.size(1);
    if ((nrows < 0) && (static_cast<double>(outsize_idx_1) + 1.0 !=
                        static_cast<double>(outsize_idx_1) + 1.0)) {
      kb_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
    }
    num_PRI_patterns = rt_powd_snf(static_cast<double>(nrows),
                                   static_cast<double>(outsize_idx_1) + 1.0);
    if (!(num_PRI_patterns >= 0.0)) {
      rtNonNegativeError(num_PRI_patterns, nb_emlrtDCI);
    }
    i2 = static_cast<int>(std::floor(num_PRI_patterns));
    if (num_PRI_patterns != i2) {
      rtIntegerError(num_PRI_patterns, ob_emlrtDCI);
    }
    ibmat = static_cast<int>(num_PRI_patterns);
    pattern_matrix.set_size(ibmat, outsize_idx_1 + 1);
    if (ibmat != i2) {
      rtIntegerError(num_PRI_patterns, pb_emlrtDCI);
    }
    ncols = ibmat * (outsize_idx_1 + 1);
    for (i2 = 0; i2 < ncols; i2++) {
      pattern_matrix[i2] = 0.0;
    }
    //  loop through columns of C
    for (nrows = 0; nrows <= i5; nrows++) {
      unsigned int i_col_A;
      //  fill the column (aka fill the elements in the column)
      //  stride is number of elements to repeat in a column
      //  num_strides is number of strides per column
      stride = rt_powd_snf(static_cast<double>(num_members_per_set),
                           static_cast<double>(outsize_idx_1 - nrows));
      i_col_A = 0U;
      //  the column in A that we use
      i2 = static_cast<int>(num_PRI_patterns / stride);
      for (iacol = 0; iacol < i2; iacol++) {
        double star;
        i_col_A++;
        if (i_col_A > static_cast<unsigned int>(num_members_per_set)) {
          i_col_A = 1U;
        }
        star = ((static_cast<double>(iacol) + 1.0) - 1.0) * stride + 1.0;
        //  column of C gets elements from row of A
        d = (star + stride) - 1.0;
        if (star > d) {
          ibmat = 0;
          ibcol = 0;
        } else {
          if (star != static_cast<int>(std::floor(star))) {
            rtIntegerError(star, qb_emlrtDCI);
          }
          if ((static_cast<int>(star) < 1) ||
              (static_cast<int>(star) > pattern_matrix.size(0))) {
            rtDynamicBoundsError(static_cast<int>(star), 1,
                                 pattern_matrix.size(0), mb_emlrtBCI);
          }
          ibmat = static_cast<int>(star) - 1;
          if (d != static_cast<int>(std::floor(d))) {
            rtIntegerError(d, rb_emlrtDCI);
          }
          if ((static_cast<int>(d) < 1) ||
              (static_cast<int>(d) > pattern_matrix.size(0))) {
            rtDynamicBoundsError(static_cast<int>(d), 1, pattern_matrix.size(0),
                                 nb_emlrtBCI);
          }
          ibcol = static_cast<int>(d);
        }
        if (nrows + 1 > pattern_matrix.size(1)) {
          rtDynamicBoundsError(nrows + 1, 1, pattern_matrix.size(1),
                               kb_emlrtBCI);
        }
        ncols = ibcol - ibmat;
        for (ibcol = 0; ibcol < ncols; ibcol++) {
          if (nrows + 1 > outsize_idx_1 + 1) {
            rtDynamicBoundsError(nrows + 1, 1, outsize_idx_1 + 1, lb_emlrtBCI);
          }
          if ((static_cast<int>(i_col_A) < 1) ||
              (static_cast<int>(i_col_A) > pulse_position_value.size(1))) {
            rtDynamicBoundsError(static_cast<int>(i_col_A), 1,
                                 pulse_position_value.size(1), lb_emlrtBCI);
          }
          pattern_matrix[(ibmat + ibcol) + pattern_matrix.size(0) * nrows] =
              pulse_position_value[(((i3 + nrows) +
                                     pulse_position_value.size(0) *
                                         (static_cast<int>(i_col_A) - 1)) +
                                    pulse_position_value.size(0) *
                                        pulse_position_value.size(1) * i_set) -
                                   1];
        }
      }
    }
    d = ((static_cast<double>(i_set) + 1.0) - 1.0) * n_rows + 1.0;
    num_PRI_patterns = (static_cast<double>(i_set) + 1.0) * n_rows;
    if (d > num_PRI_patterns) {
      i2 = 0;
      ibmat = 0;
    } else {
      if (d != static_cast<int>(std::floor(d))) {
        rtIntegerError(d, sb_emlrtDCI);
      }
      if ((static_cast<int>(d) < 1) ||
          (static_cast<int>(d) > pulsePositionMatrix.size(0))) {
        rtDynamicBoundsError(static_cast<int>(d), 1,
                             pulsePositionMatrix.size(0), ob_emlrtBCI);
      }
      i2 = static_cast<int>(d) - 1;
      if (num_PRI_patterns != static_cast<int>(std::floor(num_PRI_patterns))) {
        rtIntegerError(num_PRI_patterns, tb_emlrtDCI);
      }
      if ((static_cast<int>(num_PRI_patterns) < 1) ||
          (static_cast<int>(num_PRI_patterns) > pulsePositionMatrix.size(0))) {
        rtDynamicBoundsError(static_cast<int>(num_PRI_patterns), 1,
                             pulsePositionMatrix.size(0), pb_emlrtBCI);
      }
      ibmat = static_cast<int>(num_PRI_patterns);
    }
    sizes[0] = ibmat - i2;
    sizes[1] = pulsePositionMatrix.size(1);
    rtSubAssignSizeCheck(&sizes[0], 2, pattern_matrix.size(), 2, l_emlrtECI);
    ncols = pattern_matrix.size(1);
    for (ibmat = 0; ibmat < ncols; ibmat++) {
      outsize_idx_1 = pattern_matrix.size(0);
      for (ibcol = 0; ibcol < outsize_idx_1; ibcol++) {
        pulsePositionMatrix[(i2 + ibcol) +
                            pulsePositionMatrix.size(0) * ibmat] =
            pattern_matrix[ibcol + pattern_matrix.size(0) * ibmat];
      }
    }
  }
  if (result != i) {
    rtIntegerError(num_position_patterns, ub_emlrtDCI);
  }
  if (num_position_patterns != 0.0) {
    outsize_idx_1 = result;
  } else if ((pulsePositionMatrix.size(0) != 0) &&
             (pulsePositionMatrix.size(1) != 0)) {
    outsize_idx_1 = pulsePositionMatrix.size(0);
  } else {
    outsize_idx_1 = result;
    if (pulsePositionMatrix.size(0) > result) {
      outsize_idx_1 = pulsePositionMatrix.size(0);
    }
  }
  if ((result != outsize_idx_1) && (!(num_position_patterns == 0.0))) {
    db_rtErrorWithMessageID(rb_emlrtRTEI.fName, rb_emlrtRTEI.lineNo);
  }
  if ((pulsePositionMatrix.size(0) != outsize_idx_1) &&
      ((pulsePositionMatrix.size(0) != 0) &&
       (pulsePositionMatrix.size(1) != 0))) {
    db_rtErrorWithMessageID(rb_emlrtRTEI.fName, rb_emlrtRTEI.lineNo);
  }
  empty_non_axis_sizes = (outsize_idx_1 == 0);
  if (empty_non_axis_sizes || (num_position_patterns != 0.0)) {
    input_sizes_idx_1 = 1;
  } else {
    input_sizes_idx_1 = 0;
  }
  if (empty_non_axis_sizes || ((pulsePositionMatrix.size(0) != 0) &&
                               (pulsePositionMatrix.size(1) != 0))) {
    sizes[1] = pulsePositionMatrix.size(1);
  } else {
    sizes[1] = 0;
  }
  //  remove duplicate patterns
  pattern_matrix.set_size(outsize_idx_1, input_sizes_idx_1 + sizes[1]);
  ncols = input_sizes_idx_1;
  for (i = 0; i < ncols; i++) {
    for (i1 = 0; i1 < outsize_idx_1; i1++) {
      pattern_matrix[i1] = 1.0;
    }
  }
  ncols = sizes[1];
  for (i = 0; i < ncols; i++) {
    for (i1 = 0; i1 < outsize_idx_1; i1++) {
      pattern_matrix[i1 + pattern_matrix.size(0) * (i + input_sizes_idx_1)] =
          pulsePositionMatrix[i1 + outsize_idx_1 * i];
    }
  }
  coder::unique_rows(pattern_matrix, pulsePositionMatrix);
  //  if K>1
  //      %n_shifts = min(pulsePositionMatrix(:,2))-1;   %The number of shifts
  //      necessary.
  //
  //  else
  //      n_shifts = max(PRI_means_q)+max(PRI_jitters_q);
  //  end
  // The max element of the ppm for K>1 is (K-1)*(N+M)+J+1 which is the latest
  // possible index of the Kth pulse if the first arrived at n = 1.
  //
  // The max element of the ppm for K=1 is 1 which is the first possible index
  // of the 1st pulse.
  //
  // The size of the STFT matrix is the latest possible location of the Kth
  // pulse which is equal to K*(N+M)+J+1
  //
  // We want to take the PPM matrix that contains the the time locations for
  // the search if the first pulse is at n=1 and shift them to do the search if
  // the first pulse arrives and n = 2,..., N+M+J+1 which is the latest
  // possible location of the pulse pulse. The difference is N+M+J+1-1 = N+M+J
  // This is the max number we need to add the the PPM matrix.
  //
  // For the K = 1 case, the PPM is simply 1 and we add N+M+J which generates a
  // Wq matrix with a dimension of 1+N+M+J. This is equivalent to the STFT
  // size definition for K = 1, which is K(N+M)+J+1 = N+M+J+1, so the sizes
  // will be compatible.
  //
  // For the K > 1 case however the maximum element of the PPM is
  // (K-1)(N+M)+J+1. Adding N+M+J to this will result in a Wq with a dimension
  // of (K-1)(N+M)+J+1+N+M+J = K(N+M)+2J+1. This will be J elements larger than
  // the STFT definitions of K(N+M)+J+1. This extra J comes from the fact that
  // the max element of the PPM include the jitter of the final pulse and we
  // also include the jitter in the shifting. Because jitter is stochastic and
  // zero mean, we don't sum jitter over multiple pulses. We need to remove the
  // extra jitter when shifting for K>1.
  //
  if (reps > 1.0) {
    nrows = priMeansList.size(1);
    b_priMeansList = priMeansList.reshape(nrows);
    num_PRI_patterns = coder::internal::maximum(b_priMeansList);
    // Equivalent to N+M+J-J
  } else {
    nrows = priMeansList.size(1);
    b_priMeansList = priMeansList.reshape(nrows);
    num_PRI_patterns = coder::internal::maximum(b_priMeansList);
    outsize_idx_1 = priJtrList.size(1);
    b_priMeansList = priJtrList.reshape(outsize_idx_1);
    stride = coder::internal::maximum(b_priMeansList);
    num_PRI_patterns += stride;
    // Equivalent to N+M+J
  }
  // Number of rows in pulse_position_matrix
  // Number of cols in pulse_position_matrix --- should always be K
  coder::internal::assertValidSizeArg(num_PRI_patterns + 1.0);
  if (!(num_PRI_patterns + 1.0 >= 0.0)) {
    rtNonNegativeError(num_PRI_patterns + 1.0, p_emlrtDCI);
  }
  outsize_idx_1 =
      pulsePositionMatrix.size(0) * static_cast<int>(num_PRI_patterns + 1.0);
  if (outsize_idx_1 < 0) {
    rtNonNegativeError(static_cast<double>(outsize_idx_1), w_emlrtDCI);
  }
  pattern_matrix.set_size(outsize_idx_1, pulsePositionMatrix.size(1));
  nrows = pulsePositionMatrix.size(0);
  ncols = pulsePositionMatrix.size(1);
  num_PRI_jitters = static_cast<int>(num_PRI_patterns + 1.0);
  if (pulsePositionMatrix.size(1) > 2147483646) {
    coder::check_forloop_overflow_error();
  }
  for (result = 0; result < ncols; result++) {
    iacol = result * nrows;
    ibmat = result * outsize_idx_1 - 1;
    if (static_cast<int>(num_PRI_patterns + 1.0) > 2147483646) {
      coder::check_forloop_overflow_error();
    }
    for (int i_set{0}; i_set < num_PRI_jitters; i_set++) {
      ibcol = ibmat + i_set * nrows;
      if (nrows > 2147483646) {
        coder::check_forloop_overflow_error();
      }
      for (int k{0}; k < nrows; k++) {
        pattern_matrix[(ibcol + k) + 1] = pulsePositionMatrix[iacol + k];
      }
    }
  }
  // Create multiple copies of the PPM matrix. Each copy will eventually be
  // shifted. The second copy will get a 1 added to it, the third a 2 added, and
  // so on up to n_shifts. Use n_shifts+1 to account for the first one that
  // receives no shifting. Get the number of rows in the big PPM matrix
  if (std::isnan(num_PRI_patterns)) {
    priJtrList.set_size(1, 1);
    priJtrList[0] = rtNaN;
  } else if (num_PRI_patterns < 0.0) {
    priJtrList.set_size(1, 0);
  } else {
    priJtrList.set_size(1, static_cast<int>(num_PRI_patterns) + 1);
    ncols = static_cast<int>(num_PRI_patterns);
    for (i = 0; i <= ncols; i++) {
      priJtrList[i] = i;
    }
  }
  coder::repmat(priJtrList, static_cast<double>(pulsePositionMatrix.size(0)),
                shiftermat);
  // Create a matrix of the shifts needed for each copy of the PPM matrix
  outsize_idx_1 = shiftermat.size(0) * shiftermat.size(1);
  b_priMeansList = shiftermat.reshape(outsize_idx_1);
  coder::repmat(b_priMeansList,
                static_cast<double>(pulsePositionMatrix.size(1)), WqRowInds);
  if ((WqRowInds.size(0) != pattern_matrix.size(0)) &&
      ((WqRowInds.size(0) != 1) && (pattern_matrix.size(0) != 1))) {
    emlrtDimSizeImpxCheckR2021b(WqRowInds.size(0), pattern_matrix.size(0),
                                h_emlrtECI);
  }
  if ((WqRowInds.size(1) != pattern_matrix.size(1)) &&
      ((WqRowInds.size(1) != 1) && (pattern_matrix.size(1) != 1))) {
    emlrtDimSizeImpxCheckR2021b(WqRowInds.size(1), pattern_matrix.size(1),
                                m_emlrtECI);
  }
  if ((WqRowInds.size(0) == pattern_matrix.size(0)) &&
      (WqRowInds.size(1) == pattern_matrix.size(1))) {
    ncols = WqRowInds.size(0) * WqRowInds.size(1);
    for (i = 0; i < ncols; i++) {
      WqRowInds[i] = WqRowInds[i] + pattern_matrix[i];
    }
  } else {
    plus(WqRowInds, pattern_matrix);
  }
  if (pattern_matrix.size(0) < 1) {
    priJtrList.set_size(1, 0);
  } else {
    priJtrList.set_size(1, pattern_matrix.size(0));
    ncols = pattern_matrix.size(0) - 1;
    for (i = 0; i <= ncols; i++) {
      priJtrList[i] = static_cast<double>(i) + 1.0;
    }
  }
  coder::internal::assertValidSizeArg(
      static_cast<double>(pulsePositionMatrix.size(1)));
  outsize_idx_1 = priJtrList.size(1) * pulsePositionMatrix.size(1);
  if (outsize_idx_1 < 0) {
    rtNonNegativeError(static_cast<double>(outsize_idx_1), w_emlrtDCI);
  }
  priMeansList.set_size(1, outsize_idx_1);
  ncols = priJtrList.size(1);
  outsize_idx_1 = pulsePositionMatrix.size(1);
  for (num_PRI_jitters = 0; num_PRI_jitters < outsize_idx_1;
       num_PRI_jitters++) {
    nrows = num_PRI_jitters * ncols;
    if (ncols > 2147483646) {
      coder::check_forloop_overflow_error();
    }
    for (result = 0; result < ncols; result++) {
      priMeansList[nrows + result] = priJtrList[result];
    }
  }
  num_PRI_jitters = WqRowInds.size(0) * WqRowInds.size(1);
  nrows = priMeansList.size(1);
  outsize_idx_1 = WqRowInds.size(0) * WqRowInds.size(1);
  r.set_size(outsize_idx_1);
  for (i = 0; i < outsize_idx_1; i++) {
    r[i] = 1.0;
  }
  b_WqRowInds = WqRowInds.reshape(num_PRI_jitters);
  b_priMeansList = priMeansList.reshape(nrows);
  coder::i_sparse(b_WqRowInds, b_priMeansList, r, Wq);
  // , obj.reps(i));
}

// End of code generation (buildtimecorrelatormatrix.cpp)
