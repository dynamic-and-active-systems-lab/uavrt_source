//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// incohsumtoeplitz.cpp
//
// Code generation for function 'incohsumtoeplitz'
//

// Include files
#include "incohsumtoeplitz.h"
#include "any1.h"
#include "assertValidSizeArg.h"
#include "eml_int_forloop_overflow_check.h"
#include "find.h"
#include "indexShapeCheck.h"
#include "minOrMax.h"
#include "mtimes.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "sparse.h"
#include "sparse1.h"
#include "speye.h"
#include "sub2ind.h"
#include "sum.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"

// Function Definitions
void incohsumtoeplitz(const coder::array<bool, 1U> &Fb,
                      const coder::array<creal_T, 2U> &Wfherm,
                      const coder::array<creal_T, 2U> &S,
                      const coder::array<double, 1U> &Tb,
                      const coder::sparse &Wq,
                      coder::array<double, 2U> &Sscores,
                      coder::array<double, 2U> &Scols)
{
  static rtBoundsCheckInfo cb_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      163,                // lineNo
      37,                 // colNo
      "Fb",               // aName
      "incohsumtoeplitz", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "incohsumtoeplitz.m", // pName
      0                     // checkKind
  };
  static rtBoundsCheckInfo db_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      176,                // lineNo
      37,                 // colNo
      "Tb",               // aName
      "incohsumtoeplitz", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "incohsumtoeplitz.m", // pName
      0                     // checkKind
  };
  static rtBoundsCheckInfo eb_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      198,                // lineNo
      1,                  // colNo
      "Scols",            // aName
      "incohsumtoeplitz", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "incohsumtoeplitz.m", // pName
      0                     // checkKind
  };
  static rtBoundsCheckInfo fb_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      197,                // lineNo
      1,                  // colNo
      "Sscores",          // aName
      "incohsumtoeplitz", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "incohsumtoeplitz.m", // pName
      0                     // checkKind
  };
  static rtBoundsCheckInfo gb_emlrtBCI{
      -1,                 // iFirst
      -1,                 // iLast
      192,                // lineNo
      24,                 // colNo
      "allScores",        // aName
      "incohsumtoeplitz", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "incohsumtoeplitz.m", // pName
      0                     // checkKind
  };
  static rtDoubleCheckInfo w_emlrtDCI{
      272,           // lineNo
      23,            // colNo
      "sparse/full", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/coder/coder/+coder/"
      "+internal/@sparse/sparse.m", // pName
      4                             // checkKind
  };
  coder::b_sparse pulsesInEachColumn;
  coder::c_sparse firstPulseNum;
  coder::d_sparse b_this;
  coder::d_sparse sameAsFirst;
  coder::e_sparse c_this;
  coder::f_sparse FbSparseMat;
  coder::f_sparse TbSparseMat;
  coder::g_sparse r1;
  coder::h_sparse Tbdiags;
  coder::sparse b_y;
  coder::array<creal_T, 2U> e_y;
  coder::array<double, 2U> FbmatDiagInds;
  coder::array<double, 2U> allScores;
  coder::array<double, 2U> c_y;
  coder::array<double, 2U> r2;
  coder::array<double, 2U> selectedCombinedScores;
  coder::array<double, 1U> ex;
  coder::array<int, 2U> r;
  coder::array<int, 1U> b_idx;
  coder::array<int, 1U> jj;
  coder::array<int, 1U> r3;
  coder::array<bool, 2U> Fbdiags;
  coder::array<bool, 2U> b_Fb;
  coder::array<bool, 2U> d_y;
  double Ssz[2];
  double K;
  double varargin_1;
  unsigned int Tbsz[2];
  int b_Ssz[2];
  int Tbnumrows_tmp;
  int a;
  int b_minval_tmp;
  int cend;
  int loop_ub_tmp;
  int maxdimlen;
  int minval_tmp;
  bool exitg1;
  bool y;
  // INCOHSUMTOEPLITZ Performs the incoherent summation of time windows of an
  // input matrix S per the elements in the time selection matrix Wq.
  //    This function performs the incoherent summation of time elements within
  //    the short time Fourier transform matrix S per the selections within the
  //    Wq matrix. The rows of the S matrix represent frequency bins, whereas
  //    the columns represent the time windows. The Wq matrix is a Toeplitz
  //    based matrix with non-zero elements of each column used to select and
  //    then sum through matrix multiplication the time windows of S.
  //     abs(S).^2    *  Wq
  //    [1   2  3  4]  [1 0]
  //    [5   6  7  8]  [0 1]
  //    [9  10 11 12]  [1 0]
  //    [13 14 15 16]  [0 1]
  //
  //    The other matricies are used to select and weight the frequency and
  //    time elements of S through matrix multiplication. The Wfherm matrix
  //    applies weightings to the S matrix across frequency in order to capture
  //    energy spread across frequency bins. Fb is a matrix or a vector with 1s
  //    in elements associated with the frequency bins of Wh that are to be
  //    included for consideration. Similarly, the Tb matrix (vector) uses 1s
  //    to select time elements for consideration. Both Fb and Tb can use zeros
  //    to exclude particular frequencies or times from consideration in
  //    processing.
  //
  //    The code performs the matrix multiplication Fb*Wfherm*abs(S).^2*Tb*Wq.
  //    The sizes of these matricies must be set so that this matrix
  //    multiplication can be performed. The functions checks for correct
  //    dimensions and will generate an error of dimensional mismatch occurs.
  //    After performing the matrix multiplication of Fb*Wfherm*S*Tb*Wq, it
  //    determines which columns of the resulting matrix are maximum in each
  //    row (frequency bin). The function reports the a matrix that has the
  //    same number of rows as Fb and K columns that contains the scores for
  //    in each S time window that the maximum summed score based on the Wq
  //    matrix selections for each frequency bin. It also reports a similarly
  //    size matrix that contains the columns in S where these max scores were
  //    found
  //
  //    The number of pulses for summation (K) is extracted from Wq by querying
  //    the number of non-zero elements in the first column of the Wq matrix.
  //
  // INPUTS:
  //    Fb      Frequency blinder matrix: A matrix (fz x fz) or vector (fz x 1)
  //            of elements with 1s for frequencies of the Wfherm matrix that
  //            should be considered when looking for maximum incoheren
  //            summation. If the rows of the Wfherm matrix represent
  //            frequencies of [100 50 0 -50 -100] and the search needs to
  //            focus only on the 0 and 50 Hz bins, Fb should be [0 1 1 0 0]
  //            or diag([0 1 1 0 0]). Inputs can be full or sparse.
  //    Wfherm  Hermitian of the spectral weighting matrix. This matrix should
  //            have the same number of columns as the number of rows in S. See
  //            weightingmatrix.m for information on this matrix. The function
  //            weightingmatrix.m generates Wf, so when passing Wf to this
  //            function, Wf' should be used.
  //    S       STFT output matrix
  //    Tb      Time blinder matrix: A matrix with only diagonal elements or a
  //            vector that contains 1s that corresponds to the columns (time
  //            windows) of the S matrix that should be considered for
  //            summation. If priori information informs the caller as to the
  //            potential location of the pulses in the block being processed,
  //            the Tb matrix can be used to exclude other times from
  //            consideration which can considerably decrease processing time
  //            for this function. If no-priori is available, this entry should
  //            be the identity matrix or vector of size equal to the number
  //            of columns of S.
  //    Wq      Time correlation matrix: A matrix containing 1s in entries in
  //            each column for S matrix time windows that should be summed.
  //            Wq must have the same number of rows as columns of S, but can
  //            have as many columns as summation cases that need to be
  //            considered.
  //
  // OUTPUTS:
  //    Sscores The results of the incoherent summation of S per the time
  //            selections of the inputs after looking for maximums for each
  //            frequency bin. This has the same number of rows as that of the
  //            input Fb and the same number of columns a the number of pulses
  //            used for summation. The matrix has K columns. The scores
  //            represent the square magnitudes of the selected elements of the
  //            S matrix.
  //
  //    Scols   A matrix of the columns of S (time windows of STFT)
  //            that correspond to the potential pulses identified
  //            in Sscors. The size of this matrix is the same as Sscores.
  //
  // Author: Michael W. Shafer
  // Date:   2022-03-31
  //
  if (Tb.size(0) > 1) {
    minval_tmp = 1;
  } else {
    minval_tmp = Tb.size(0);
  }
  if (Fb.size(0) > 1) {
    b_minval_tmp = 1;
  } else {
    b_minval_tmp = Fb.size(0);
  }
  if ((minval_tmp != 1) && (Tb.size(0) != 1)) {
    rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
  }
  if ((b_minval_tmp != 1) && (Fb.size(0) != 1)) {
    rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
  }
  if (Tb.size(0) < 1) {
    Tbnumrows_tmp = 1;
  } else {
    Tbnumrows_tmp = Tb.size(0);
  }
  if (Fb.size(0) < 1) {
    maxdimlen = 1;
  } else {
    maxdimlen = Fb.size(0);
  }
  if (maxdimlen != Wfherm.size(0)) {
    rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
  }
  if (S.size(0) != Wfherm.size(1)) {
    rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
  }
  if (S.size(1) != Tbnumrows_tmp) {
    rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
  }
  if (Tbnumrows_tmp != Wq.m) {
    rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
  }
  // Make sure the number of pulses considered for all Wq columns is the same
  coder::sum(Wq, pulsesInEachColumn);
  pulsesInEachColumn.parenReference(firstPulseNum);
  pulsesInEachColumn.c_le(b_this);
  coder::any(b_this, c_this);
  y = false;
  cend = c_this.colidx[1] - 1;
  a = c_this.colidx[0];
  if ((c_this.colidx[0] <= c_this.colidx[1] - 1) &&
      (c_this.colidx[1] - 1 > 2147483646)) {
    coder::check_forloop_overflow_error();
  }
  for (int idx{a}; idx <= cend; idx++) {
    y = c_this.d[idx - 1];
  }
  if (y) {
    rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
  }
  pulsesInEachColumn.eq(firstPulseNum, sameAsFirst);
  sameAsFirst.b_not(b_this);
  coder::any(b_this, c_this);
  y = false;
  cend = c_this.colidx[1] - 1;
  a = c_this.colidx[0];
  if ((c_this.colidx[0] <= c_this.colidx[1] - 1) &&
      (c_this.colidx[1] - 1 > 2147483646)) {
    coder::check_forloop_overflow_error();
  }
  for (int idx{a}; idx <= cend; idx++) {
    y = c_this.d[idx - 1];
  }
  if (y) {
    // numel(unique(full(pulsesInEachColumn)))~=1 %Unique doesn't support sparse
    // for code-generation. %numel(unique(sum(Wq,1)))~=1
    rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
  }
  //  Generate Tb and Fb sparse matrices if entered as vectors
  // Frequency Blinder (Fb) matrix definitions:
  Ssz[0] = maxdimlen;
  Ssz[1] = maxdimlen;
  coder::speye(Ssz, b_y);
  b_y.logical(FbSparseMat);
  // Prototype Fb matrix with identity logical matrix
  if (maxdimlen < 1) {
    FbmatDiagInds.set_size(1, 0);
    c_y.set_size(1, 0);
  } else {
    FbmatDiagInds.set_size(1, maxdimlen);
    loop_ub_tmp = maxdimlen - 1;
    c_y.set_size(1, maxdimlen);
    for (a = 0; a <= loop_ub_tmp; a++) {
      FbmatDiagInds[a] = static_cast<double>(a) + 1.0;
      c_y[a] = static_cast<double>(a) + 1.0;
    }
  }
  b_Ssz[0] = maxdimlen;
  b_Ssz[1] = maxdimlen;
  coder::eml_sub2ind(b_Ssz, FbmatDiagInds, c_y, r);
  FbmatDiagInds.set_size(1, r.size(1));
  maxdimlen = r.size(1);
  for (a = 0; a < maxdimlen; a++) {
    FbmatDiagInds[a] = r[a];
  }
  if (b_minval_tmp == 1) {
    // Passed a vector, so make the matrix
    Fbdiags.set_size(Fb.size(0), 1);
    maxdimlen = Fb.size(0);
    for (a = 0; a < maxdimlen; a++) {
      Fbdiags[a] = Fb[a];
    }
    // FbSparseMat = logical(speye(max(Fbsz)));
    FbSparseMat.parenAssign(Fb, FbmatDiagInds);
  } else {
    // Passed a matrix, so make sparse.
    // FbSparseMat = logical(sparse(Fb));
    b_Fb.set_size(1, FbmatDiagInds.size(1));
    maxdimlen = FbmatDiagInds.size(1);
    for (a = 0; a < maxdimlen; a++) {
      b_minval_tmp = static_cast<int>(FbmatDiagInds[a]);
      if ((b_minval_tmp < 1) || (b_minval_tmp > Fb.size(0))) {
        rtDynamicBoundsError(b_minval_tmp, 1, Fb.size(0), cb_emlrtBCI);
      }
      b_Fb[a] = Fb[b_minval_tmp - 1];
    }
    FbSparseMat.b_parenAssign(b_Fb, FbmatDiagInds);
    // Had do do it this way rather than with logical(sparse(Fb)) to get code to
    // work with Fb being either a vector or matrix.
    FbSparseMat.parenReference(FbmatDiagInds, b_this);
    if (b_this.n < 0) {
      rtNonNegativeError(static_cast<double>(b_this.n), w_emlrtDCI);
    }
    d_y.set_size(1, b_this.n);
    loop_ub_tmp = b_this.n;
    for (a = 0; a < loop_ub_tmp; a++) {
      d_y[a] = false;
    }
    if (b_this.n > 2147483646) {
      coder::check_forloop_overflow_error();
    }
    for (cend = 0; cend < loop_ub_tmp; cend++) {
      maxdimlen = b_this.colidx[cend + 1] - 1;
      a = b_this.colidx[cend];
      if ((b_this.colidx[cend] <= maxdimlen) && (maxdimlen > 2147483646)) {
        coder::check_forloop_overflow_error();
      }
      for (int idx{a}; idx <= maxdimlen; idx++) {
        d_y[(b_this.rowidx[idx - 1] + d_y.size(0) * cend) - 1] =
            b_this.d[idx - 1];
      }
    }
    Fbdiags.set_size(d_y.size(1), 1);
    maxdimlen = d_y.size(1);
    for (a = 0; a < maxdimlen; a++) {
      Fbdiags[a] = d_y[d_y.size(0) * a];
    }
    // Get the diag elements. Transpose needed for size considerations for code
    // generation.
  }
  // Time Blinder (Tb) matrix definitions:
  Ssz[0] = Tbnumrows_tmp;
  Ssz[1] = Tbnumrows_tmp;
  coder::speye(Ssz, b_y);
  b_y.logical(TbSparseMat);
  // Prototype Fb matrix with identity logical matrix
  if (Tbnumrows_tmp < 1) {
    FbmatDiagInds.set_size(1, 0);
    c_y.set_size(1, 0);
  } else {
    FbmatDiagInds.set_size(1, Tbnumrows_tmp);
    loop_ub_tmp = Tbnumrows_tmp - 1;
    c_y.set_size(1, Tbnumrows_tmp);
    for (a = 0; a <= loop_ub_tmp; a++) {
      FbmatDiagInds[a] = static_cast<double>(a) + 1.0;
      c_y[a] = static_cast<double>(a) + 1.0;
    }
  }
  b_Ssz[0] = Tbnumrows_tmp;
  b_Ssz[1] = Tbnumrows_tmp;
  coder::eml_sub2ind(b_Ssz, FbmatDiagInds, c_y, r);
  FbmatDiagInds.set_size(1, r.size(1));
  maxdimlen = r.size(1);
  for (a = 0; a < maxdimlen; a++) {
    FbmatDiagInds[a] = r[a];
  }
  if (minval_tmp == 1) {
    coder::i_sparse(Tb, r1);
    r1.logical(Tbdiags);
    coder::internal::assertValidSizeArg(static_cast<double>(Tbnumrows_tmp));
    coder::sparse::eyeLike(Tbnumrows_tmp, Tbnumrows_tmp, Tbnumrows_tmp, b_y);
    b_y.logical(TbSparseMat);
    TbSparseMat.c_parenAssign(Tbdiags, FbmatDiagInds);
  } else {
    c_y.set_size(1, FbmatDiagInds.size(1));
    maxdimlen = FbmatDiagInds.size(1);
    for (a = 0; a < maxdimlen; a++) {
      b_minval_tmp = static_cast<int>(FbmatDiagInds[a]);
      if ((b_minval_tmp < 1) || (b_minval_tmp > Tb.size(0))) {
        rtDynamicBoundsError(b_minval_tmp, 1, Tb.size(0), db_emlrtBCI);
      }
      c_y[a] = Tb[b_minval_tmp - 1];
    }
    TbSparseMat.c_parenAssign(c_y, FbmatDiagInds);
    // Had do do it this way rather than with logical(sparse(Tb)) to get code to
    // work with Tb being either a vector or matrix.
  }
  //  Perform the incoherent summation
  // S          = abs(S).^2;
  Wq.parenReference(r1);
  coder::sum(r1, firstPulseNum);
  K = 0.0;
  cend = firstPulseNum.colidx[1] - 1;
  a = firstPulseNum.colidx[0];
  if ((firstPulseNum.colidx[0] <= firstPulseNum.colidx[1] - 1) &&
      (firstPulseNum.colidx[1] - 1 > 2147483646)) {
    coder::check_forloop_overflow_error();
  }
  for (int idx{a}; idx <= cend; idx++) {
    K = firstPulseNum.d[idx - 1];
  }
  if (S.size(0) != Wfherm.size(1)) {
    if (((Wfherm.size(0) == 1) && (Wfherm.size(1) == 1)) ||
        ((S.size(0) == 1) && (S.size(1) == 1))) {
      bc_rtErrorWithMessageID(ec_emlrtRTEI.fName, ec_emlrtRTEI.lineNo);
    } else {
      qb_rtErrorWithMessageID(fc_emlrtRTEI.fName, fc_emlrtRTEI.lineNo);
    }
  }
  coder::internal::blas::mtimes(Wfherm, S, e_y);
  cend = e_y.size(0) * e_y.size(1);
  selectedCombinedScores.set_size(e_y.size(0), e_y.size(1));
  if (cend > 2147483646) {
    coder::check_forloop_overflow_error();
  }
  for (maxdimlen = 0; maxdimlen < cend; maxdimlen++) {
    selectedCombinedScores[maxdimlen] =
        rt_hypotd_snf(e_y[maxdimlen].re, e_y[maxdimlen].im);
  }
  allScores.set_size(selectedCombinedScores.size(0),
                     selectedCombinedScores.size(1));
  loop_ub_tmp = selectedCombinedScores.size(0) * selectedCombinedScores.size(1);
  for (a = 0; a < loop_ub_tmp; a++) {
    varargin_1 = selectedCombinedScores[a];
    allScores[a] = varargin_1 * varargin_1;
  }
  FbSparseMat.mtimes(allScores, selectedCombinedScores);
  TbSparseMat.b_mtimes(selectedCombinedScores, r2);
  Wq.mtimes(r2, selectedCombinedScores);
  coder::internal::maximum(selectedCombinedScores, ex, b_idx);
  // Check max on each row (frequency). This gives the columns of the resulting
  // matrix output with the max for each frequency bin This and the next line
  // gets the column numbers (time windows) of the S matrix where the highest
  // K-summed entries exist for each row (frequency bin)
  ex.set_size(b_idx.size(0));
  maxdimlen = b_idx.size(0);
  for (a = 0; a < maxdimlen; a++) {
    ex[a] = b_idx[a];
  }
  Wq.parenReference(ex, b_y);
  coder::e_eml_find(b_y, b_idx, jj);
  ex.set_size(b_idx.size(0));
  maxdimlen = b_idx.size(0);
  for (a = 0; a < maxdimlen; a++) {
    ex[a] = b_idx[a];
  }
  // Get the rows that had 1s in them that corresponded to the winning columns
  varargin_1 = static_cast<double>(ex.size(0)) / K;
  coder::internal::assertValidSizeArg(K);
  coder::internal::assertValidSizeArg(varargin_1);
  maxdimlen = ex.size(0);
  if (ex.size(0) < 1) {
    maxdimlen = 1;
  }
  cend = ex.size(0);
  if (cend >= maxdimlen) {
    maxdimlen = cend;
  }
  if (static_cast<int>(K) > maxdimlen) {
    j_rtErrorWithMessageID(m_emlrtRTEI.fName, m_emlrtRTEI.lineNo);
  }
  if (static_cast<int>(varargin_1) > maxdimlen) {
    j_rtErrorWithMessageID(m_emlrtRTEI.fName, m_emlrtRTEI.lineNo);
  }
  y = (static_cast<int>(K) >= 0);
  if ((!y) || (static_cast<int>(varargin_1) < 0)) {
    y = false;
  }
  if (!y) {
    gb_rtErrorWithMessageID(vb_emlrtRTEI.fName, vb_emlrtRTEI.lineNo);
  }
  if (static_cast<int>(K) * static_cast<int>(varargin_1) != ex.size(0)) {
    k_rtErrorWithMessageID(n_emlrtRTEI.fName, n_emlrtRTEI.lineNo);
  }
  cend = static_cast<int>(K);
  maxdimlen = static_cast<int>(varargin_1);
  Scols.set_size(static_cast<int>(varargin_1), static_cast<int>(K));
  for (a = 0; a < cend; a++) {
    for (b_minval_tmp = 0; b_minval_tmp < maxdimlen; b_minval_tmp++) {
      Scols[b_minval_tmp + Scols.size(0) * a] =
          ex[a + static_cast<int>(K) * b_minval_tmp];
    }
  }
  if (Wfherm.size(0) < 1) {
    FbmatDiagInds.set_size(1, 0);
  } else {
    FbmatDiagInds.set_size(1, Wfherm.size(0));
    maxdimlen = Wfherm.size(0) - 1;
    for (a = 0; a <= maxdimlen; a++) {
      FbmatDiagInds[a] = static_cast<double>(a) + 1.0;
    }
  }
  ex.set_size(FbmatDiagInds.size(1));
  maxdimlen = FbmatDiagInds.size(1);
  for (a = 0; a < maxdimlen; a++) {
    ex[a] = FbmatDiagInds[a];
  }
  coder::repmat(ex, K, selectedCombinedScores);
  b_Ssz[0] = allScores.size(0);
  if (!coder::allinrange(selectedCombinedScores, allScores.size(0))) {
    cc_rtErrorWithMessageID(gc_emlrtRTEI.fName, gc_emlrtRTEI.lineNo);
  }
  Ssz[0] = selectedCombinedScores.size(0);
  Tbsz[0] = static_cast<unsigned int>(Scols.size(0));
  Ssz[1] = selectedCombinedScores.size(1);
  Tbsz[1] = static_cast<unsigned int>(Scols.size(1));
  y = true;
  maxdimlen = 0;
  exitg1 = false;
  while ((!exitg1) && (maxdimlen < 2)) {
    if (static_cast<int>(Ssz[maxdimlen]) != static_cast<int>(Tbsz[maxdimlen])) {
      y = false;
      exitg1 = true;
    } else {
      maxdimlen++;
    }
  }
  if (!y) {
    dc_rtErrorWithMessageID(hc_emlrtRTEI.fName, hc_emlrtRTEI.lineNo);
  }
  if (!coder::allinrange(Scols, allScores.size(1))) {
    cc_rtErrorWithMessageID(gc_emlrtRTEI.fName, gc_emlrtRTEI.lineNo);
  }
  cend = selectedCombinedScores.size(0) * selectedCombinedScores.size(1);
  for (a = 0; a < cend; a++) {
    selectedCombinedScores[a] = static_cast<int>(selectedCombinedScores[a]) +
                                b_Ssz[0] * (static_cast<int>(Scols[a]) - 1);
  }
  int iv[2];
  b_Ssz[0] = (*(int(*)[2])allScores.size())[0];
  b_Ssz[1] = (*(int(*)[2])allScores.size())[1];
  iv[0] = (*(int(*)[2])selectedCombinedScores.size())[0];
  iv[1] = (*(int(*)[2])selectedCombinedScores.size())[1];
  coder::internal::indexShapeCheck(b_Ssz, iv);
  Sscores.set_size(selectedCombinedScores.size(0),
                   selectedCombinedScores.size(1));
  for (a = 0; a < cend; a++) {
    b_minval_tmp = static_cast<int>(selectedCombinedScores[a]);
    if ((b_minval_tmp < 1) || (b_minval_tmp > loop_ub_tmp)) {
      rtDynamicBoundsError(b_minval_tmp, 1, loop_ub_tmp, gb_emlrtBCI);
    }
    Sscores[a] = allScores[b_minval_tmp - 1];
  }
  // Extract individual pulse scores
  // The max function will just return the first index if all elements are
  // equal. Here we zero out the scores and set the cols to NaN for frequencies
  // were ignored with the frequency blinder matrix.
  maxdimlen = Fbdiags.size(0) - 1;
  cend = 0;
  for (b_minval_tmp = 0; b_minval_tmp <= maxdimlen; b_minval_tmp++) {
    if (!Fbdiags[b_minval_tmp]) {
      cend++;
    }
  }
  r3.set_size(cend);
  cend = 0;
  for (b_minval_tmp = 0; b_minval_tmp <= maxdimlen; b_minval_tmp++) {
    if (!Fbdiags[b_minval_tmp]) {
      r3[cend] = b_minval_tmp;
      cend++;
    }
  }
  maxdimlen = selectedCombinedScores.size(1);
  for (a = 0; a < maxdimlen; a++) {
    cend = r3.size(0);
    for (b_minval_tmp = 0; b_minval_tmp < cend; b_minval_tmp++) {
      if (r3[b_minval_tmp] > selectedCombinedScores.size(0) - 1) {
        rtDynamicBoundsError(r3[b_minval_tmp], 0,
                             selectedCombinedScores.size(0) - 1, fb_emlrtBCI);
      }
      Sscores[r3[b_minval_tmp] + Sscores.size(0) * a] = rtNaN;
    }
  }
  maxdimlen = Scols.size(1);
  for (a = 0; a < maxdimlen; a++) {
    cend = r3.size(0);
    for (b_minval_tmp = 0; b_minval_tmp < cend; b_minval_tmp++) {
      if (r3[b_minval_tmp] > Scols.size(0) - 1) {
        rtDynamicBoundsError(r3[b_minval_tmp], 0, Scols.size(0) - 1,
                             eb_emlrtBCI);
      }
      Scols[r3[b_minval_tmp] + Scols.size(0) * a] = rtNaN;
    }
  }
}

// End of code generation (incohsumtoeplitz.cpp)
