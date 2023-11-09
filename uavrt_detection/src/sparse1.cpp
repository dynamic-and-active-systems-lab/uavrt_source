//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// sparse1.cpp
//
// Code generation for function 'sparse1'
//

// Include files
#include "sparse1.h"
#include "anonymous_function.h"
#include "bigProduct.h"
#include "eml_int_forloop_overflow_check.h"
#include "ind2sub.h"
#include "indexShapeCheck.h"
#include "locBsearch.h"
#include "rt_nonfinite.h"
#include "sparse.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_internal_types.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "validateNumericIndex.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include <cmath>
#include <cstddef>
#include <cstring>
#include <sstream>
#include <stdexcept>
#include <string>

// Variable Definitions
static rtRunTimeErrorInfo cc_emlrtRTEI{
    29,              // lineNo
    23,              // colNo
    "sparse/mtimes", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/shared/coder/coder/+coder/"
    "+internal/@sparse/mtimes.m" // pName
};

static rtDoubleCheckInfo s_emlrtDCI{
    136,        // lineNo
    13,         // colNo
    "fsmtimes", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/shared/coder/coder/+coder/"
    "+internal/@sparse/mtimes.m", // pName
    4                             // checkKind
};

static rtDoubleCheckInfo u_emlrtDCI{
    211,            // lineNo
    45,             // colNo
    "sparse/binOp", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/shared/coder/coder/+coder/"
    "+internal/@sparse/binOp.m", // pName
    4                            // checkKind
};

static rtRunTimeErrorInfo mc_emlrtRTEI{
    1629,              // lineNo
    9,                 // colNo
    "assertValidSize", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/shared/coder/coder/+coder/"
    "+internal/@sparse/sparse.m" // pName
};

static rtRunTimeErrorInfo oc_emlrtRTEI{
    92,                        // lineNo
    1,                         // colNo
    "parenReference2DColumns", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/shared/coder/coder/+coder/"
    "+internal/@sparse/parenReference2D.m" // pName
};

static rtRunTimeErrorInfo tc_emlrtRTEI{
    11,                     // lineNo
    23,                     // colNo
    "sparse/parenAssign1D", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/shared/coder/coder/+coder/"
    "+internal/@sparse/parenAssign1D.m" // pName
};

// Function Declarations
static void ec_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void fc_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void gc_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void nb_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void ob_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void pb_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void wc_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void xc_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
namespace coder {
void sparse::b_realloc(f_sparse *b_this, int numAllocRequested, int ub1,
                       int lb2, int ub2)
{
  static rtRunTimeErrorInfo vc_emlrtRTEI{
      237,            // lineNo
      13,             // colNo
      "sparse/numel", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/coder/coder/+coder/"
      "+internal/@sparse/sparse.m" // pName
  };
  array<int, 1U> rowidxt;
  array<bool, 1U> dt;
  int numAlloc;
  int overflow;
  rowidxt.set_size(b_this->rowidx.size(0));
  numAlloc = b_this->rowidx.size(0);
  for (overflow = 0; overflow < numAlloc; overflow++) {
    rowidxt[overflow] = b_this->rowidx[overflow];
  }
  dt.set_size(b_this->d.size(0));
  numAlloc = b_this->d.size(0);
  for (overflow = 0; overflow < numAlloc; overflow++) {
    dt[overflow] = b_this->d[overflow];
  }
  internal::b_bigProduct(b_this->m, b_this->n, overflow);
  if (overflow == 0) {
    internal::b_bigProduct(b_this->m, b_this->n, overflow);
    if (overflow != 0) {
      xc_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
    }
    numAlloc = b_this->m * b_this->n;
    if (numAllocRequested <= numAlloc) {
      numAlloc = numAllocRequested;
    }
    if (numAlloc <= 1) {
      numAlloc = 1;
    }
  } else if (numAllocRequested <= 1) {
    numAlloc = 1;
  } else {
    numAlloc = numAllocRequested;
  }
  b_this->rowidx.set_size(numAlloc);
  b_this->d.set_size(numAlloc);
  for (overflow = 0; overflow < numAlloc; overflow++) {
    b_this->rowidx[overflow] = 0;
    b_this->d[overflow] = false;
  }
  b_this->maxnz = numAlloc;
  if (ub1 > 2147483646) {
    check_forloop_overflow_error();
  }
  for (numAlloc = 0; numAlloc < ub1; numAlloc++) {
    b_this->rowidx[numAlloc] = rowidxt[numAlloc];
    b_this->d[numAlloc] = dt[numAlloc];
  }
  if ((lb2 <= ub2) && (ub2 > 2147483646)) {
    check_forloop_overflow_error();
  }
  for (numAlloc = lb2; numAlloc <= ub2; numAlloc++) {
    b_this->rowidx[numAlloc] = rowidxt[numAlloc - 1];
    b_this->d[numAlloc] = dt[numAlloc - 1];
  }
}

void f_sparse::parenAssign2D(bool rhs, double r, double c)
{
  double b_d;
  int vidx;
  bool b;
  bool thisv;
  b_d = std::floor(r);
  if ((!(b_d == r)) || std::isinf(r) || (!(r > 0.0))) {
    hc_rtErrorWithMessageID(nc_emlrtRTEI.fName, nc_emlrtRTEI.lineNo);
  }
  if (!(r <= m)) {
    rtErrorWithMessageID(static_cast<int>(b_d), m, jc_emlrtRTEI.fName,
                         jc_emlrtRTEI.lineNo);
  }
  b_d = std::floor(c);
  if ((!(b_d == c)) || std::isinf(c) || (!(c > 0.0))) {
    hc_rtErrorWithMessageID(nc_emlrtRTEI.fName, nc_emlrtRTEI.lineNo);
  }
  if (!(c <= n)) {
    rtErrorWithMessageID(static_cast<int>(b_d), n, jc_emlrtRTEI.fName,
                         jc_emlrtRTEI.lineNo);
  }
  vidx = b_sparse_locBsearch(rowidx, static_cast<int>(r),
                             colidx[static_cast<int>(c) - 1],
                             colidx[static_cast<int>(c)], thisv);
  if (thisv) {
    thisv = d[vidx - 1];
  } else {
    thisv = false;
  }
  b = !thisv;
  if ((!b) || rhs) {
    if (thisv && rhs) {
      d[vidx - 1] = true;
    } else if (b) {
      int nelem;
      if (colidx[colidx.size(0) - 1] - 1 == maxnz) {
        sparse::b_realloc(this, colidx[colidx.size(0) - 1] + 9, vidx, vidx + 1,
                          colidx[colidx.size(0) - 1] - 1);
        rowidx[vidx] = static_cast<int>(r);
        d[vidx] = rhs;
      } else {
        nelem = (colidx[colidx.size(0) - 1] - vidx) - 1;
        if (nelem > 0) {
          std::memmove((void *)&rowidx[vidx + 1], (void *)&rowidx[vidx],
                       (unsigned int)((size_t)nelem * sizeof(int)));
          std::memmove((void *)&d[vidx + 1], (void *)&d[vidx],
                       (unsigned int)((size_t)nelem * sizeof(bool)));
        }
        d[vidx] = rhs;
        rowidx[vidx] = static_cast<int>(r);
      }
      nelem = static_cast<int>(c) + 1;
      vidx = n + 1;
      if ((nelem <= n + 1) && (n + 1 > 2147483646)) {
        check_forloop_overflow_error();
      }
      for (int k{nelem}; k <= vidx; k++) {
        colidx[k - 1] = colidx[k - 1] + 1;
      }
    } else {
      int nelem;
      nelem = (colidx[colidx.size(0) - 1] - vidx) - 1;
      if (nelem > 0) {
        std::memmove((void *)&rowidx[vidx - 1], (void *)&rowidx[vidx],
                     (unsigned int)((size_t)nelem * sizeof(int)));
        std::memmove((void *)&d[vidx - 1], (void *)&d[vidx],
                     (unsigned int)((size_t)nelem * sizeof(bool)));
      }
      nelem = static_cast<int>(c) + 1;
      vidx = n + 1;
      if ((nelem <= vidx) && (vidx > 2147483646)) {
        check_forloop_overflow_error();
      }
      for (int k{nelem}; k <= vidx; k++) {
        colidx[k - 1] = colidx[k - 1] - 1;
      }
    }
  }
}

} // namespace coder
static void ec_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Sparse matrix sizes must be non-negative integers.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

static void fc_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "The number of nonzeros must be at least as large as the number "
               "of elements specified by the first 3 arguments to sparse.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

static void gc_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Unable to represent result of \'~\' because it contains too "
               "many nonzero elements.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

static void nb_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Index into matrix must be an integer.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

static void ob_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Index into matrix is too large.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

static void pb_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Index into matrix must be positive.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

static void wc_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "In an assignment  A(:) = B, the number of elements in A and B "
               "must be the same.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

static void xc_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Number of elements exceeds maximum representable value.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

namespace coder {
void sparse::assertValidIndexArg(const ::coder::array<double, 1U> &s,
                                 ::coder::array<int, 1U> &sint)
{
  static rtRunTimeErrorInfo vc_emlrtRTEI{
      1660,                  // lineNo
      31,                    // colNo
      "assertValidIndexArg", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/coder/coder/+coder/"
      "+internal/@sparse/sparse.m" // pName
  };
  static rtRunTimeErrorInfo wc_emlrtRTEI{
      1658,                  // lineNo
      31,                    // colNo
      "assertValidIndexArg", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/coder/coder/+coder/"
      "+internal/@sparse/sparse.m" // pName
  };
  static rtRunTimeErrorInfo xc_emlrtRTEI{
      1662,                  // lineNo
      31,                    // colNo
      "assertValidIndexArg", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/coder/coder/+coder/"
      "+internal/@sparse/sparse.m" // pName
  };
  int ns;
  ns = s.size(0);
  sint.set_size(s.size(0));
  if (s.size(0) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int k{0}; k < ns; k++) {
    if (!(std::floor(s[k]) == s[k])) {
      nb_rtErrorWithMessageID(wc_emlrtRTEI.fName, wc_emlrtRTEI.lineNo);
    }
    if (!(s[k] < 2.147483647E+9)) {
      ob_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
    }
    if (!(s[k] > 0.0)) {
      pb_rtErrorWithMessageID(xc_emlrtRTEI.fName, xc_emlrtRTEI.lineNo);
    }
    sint[k] = static_cast<int>(s[k]);
  }
}

void f_sparse::b_mtimes(const ::coder::array<double, 2U> &a,
                        ::coder::array<double, 2U> &c) const
{
  int aoff;
  int b_m;
  int b_n;
  int cidx;
  if (a.size(1) != m) {
    qb_rtErrorWithMessageID(cc_emlrtRTEI.fName, cc_emlrtRTEI.lineNo);
  }
  b_m = a.size(0);
  b_n = n - 1;
  c.set_size(a.size(0), c.size(1));
  if (n < 0) {
    rtNonNegativeError(static_cast<double>(n), s_emlrtDCI);
  }
  c.set_size(c.size(0), n);
  aoff = a.size(0) * n;
  for (cidx = 0; cidx < aoff; cidx++) {
    c[cidx] = 0.0;
  }
  if ((a.size(1) != 0) && (a.size(0) != 0) && (n != 0) &&
      (colidx[colidx.size(0) - 1] - 1 != 0)) {
    if (a.size(0) == 1) {
      aoff = n;
      if (n > 2147483646) {
        check_forloop_overflow_error();
      }
      for (int aidx_tmp{0}; aidx_tmp < aoff; aidx_tmp++) {
        double cd;
        int b_a;
        cd = 0.0;
        cidx = colidx[aidx_tmp + 1] - 1;
        b_a = colidx[aidx_tmp];
        if ((colidx[aidx_tmp] <= cidx) && (cidx > 2147483646)) {
          check_forloop_overflow_error();
        }
        for (int mend{b_a}; mend <= cidx; mend++) {
          cd += static_cast<double>(d[mend - 1]) * a[rowidx[mend - 1] - 1];
        }
        c[aidx_tmp] = cd;
      }
    } else if (a.size(0) >= 4) {
      if (n > 2147483646) {
        check_forloop_overflow_error();
      }
      for (int ccol{0}; ccol <= b_n; ccol++) {
        int b_a;
        int bpend_tmp;
        int coff;
        coff = ccol * c.size(0);
        bpend_tmp = colidx[ccol + 1] - 1;
        b_a = colidx[ccol];
        if ((colidx[ccol] <= bpend_tmp) && (bpend_tmp > 2147483646)) {
          check_forloop_overflow_error();
        }
        for (int bp{b_a}; bp <= bpend_tmp; bp++) {
          int aoff_tmp;
          int mend;
          bool bd;
          aoff_tmp = rowidx[bp - 1] - 1;
          aoff = aoff_tmp * a.size(0);
          bd = d[bp - 1];
          mend = (b_m / 4) << 2;
          if (mend > 2147483643) {
            check_forloop_overflow_error();
          }
          for (int crow{1}; crow <= mend; crow += 4) {
            int aidx_tmp;
            cidx = crow + coff;
            aidx_tmp = crow + aoff;
            c[cidx - 1] =
                c[cidx - 1] + a[aidx_tmp - 1] * static_cast<double>(bd);
            c[cidx] = c[cidx] + a[aidx_tmp] * static_cast<double>(bd);
            c[cidx + 1] =
                c[cidx + 1] + a[aidx_tmp + 1] * static_cast<double>(bd);
            c[cidx + 2] =
                c[cidx + 2] + a[aidx_tmp + 2] * static_cast<double>(bd);
          }
          aoff = mend + 1;
          if ((mend + 1 <= b_m) && (b_m > 2147483646)) {
            check_forloop_overflow_error();
          }
          for (int crow{aoff}; crow <= b_m; crow++) {
            cidx = (crow + coff) - 1;
            c[cidx] = c[cidx] + a[(crow + a.size(0) * aoff_tmp) - 1] *
                                    static_cast<double>(bd);
          }
        }
      }
    } else {
      if (n > 2147483646) {
        check_forloop_overflow_error();
      }
      for (int ccol{0}; ccol <= b_n; ccol++) {
        int b_a;
        int bpend_tmp;
        bpend_tmp = colidx[ccol + 1] - 1;
        b_a = colidx[ccol];
        if ((colidx[ccol] <= bpend_tmp) && (bpend_tmp > 2147483646)) {
          check_forloop_overflow_error();
        }
        for (int bp{b_a}; bp <= bpend_tmp; bp++) {
          for (int crow{0}; crow < b_m; crow++) {
            c[crow + c.size(0) * ccol] =
                c[crow + c.size(0) * ccol] +
                a[crow + a.size(0) * (rowidx[bp - 1] - 1)] *
                    static_cast<double>(d[bp - 1]);
          }
        }
      }
    }
  }
}

void d_sparse::b_not(d_sparse &out) const
{
  static rtRunTimeErrorInfo vc_emlrtRTEI{
      83,       // lineNo
      27,       // colNo
      "notnnz", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/coder/coder/+coder/"
      "+internal/@sparse/not.m" // pName
  };
  int b;
  int larger;
  int q;
  int smaller;
  int writeStart;
  if (n < 1) {
    smaller = n;
    larger = 1;
  } else {
    smaller = 1;
    larger = n;
  }
  if (smaller == 0) {
    smaller = 0;
  } else {
    writeStart = colidx[colidx.size(0) - 1];
    q = div_s32(writeStart - 1, smaller);
    larger -= q;
    if (larger == 0) {
      smaller = 0;
    } else {
      if ((larger > div_s32(MAX_int32_T, smaller)) ||
          (smaller > div_s32(MAX_int32_T, larger))) {
        gc_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
      }
      smaller = ((smaller * larger - writeStart) + q * smaller) + 1;
    }
  }
  larger = smaller;
  out.n = n;
  if (smaller < 1) {
    larger = 1;
  }
  out.d.set_size(larger);
  out.rowidx.set_size(larger);
  if (n + 1 < 0) {
    rtNonNegativeError(static_cast<double>(n + 1), t_emlrtDCI);
  }
  out.colidx.set_size(n + 1);
  if (smaller < 1) {
    smaller = 0;
  }
  for (larger = 0; larger < smaller; larger++) {
    out.d[larger] = true;
  }
  q = 0;
  b = n;
  if (n > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int c{0}; c < b; c++) {
    out.colidx[c] = q + 1;
    larger = colidx[c + 1];
    if (colidx[c] == larger) {
      out.rowidx[q] = 1;
      q++;
    } else {
      smaller = rowidx[colidx[c] - 1];
      if (smaller - 1 > 2147483646) {
        check_forloop_overflow_error();
      }
      for (int writeRow{0}; writeRow <= smaller - 2; writeRow++) {
        out.rowidx[q + writeRow] = writeRow + 1;
      }
      q = (q + smaller) - 1;
      larger = (larger - colidx[c]) - 2;
      if (larger > 2147483646) {
        check_forloop_overflow_error();
      }
      for (int i{0}; i <= larger; i++) {
        smaller = colidx[c] + i;
        writeStart = rowidx[smaller - 1] + 1;
        smaller = rowidx[smaller] - 1;
        if ((writeStart <= smaller) && (smaller > 2147483646)) {
          check_forloop_overflow_error();
        }
        for (int writeRow{writeStart}; writeRow <= smaller; writeRow++) {
          out.rowidx[(q + writeRow) - writeStart] = writeRow;
        }
        q = ((q + smaller) - writeStart) + 1;
      }
      writeStart = rowidx[colidx[c] + larger] + 1;
      for (int writeRow{writeStart}; writeRow < 2; writeRow++) {
        out.rowidx[(q + writeRow) - writeStart] = writeRow;
      }
      q = (q - writeStart) + 2;
    }
  }
  out.colidx[n] = q + 1;
}

void f_sparse::b_parenAssign(const ::coder::array<bool, 2U> &rhs,
                             const ::coder::array<double, 2U> &varargin_1)
{
  int nidx;
  int overflow;
  int varargout_4;
  internal::bigProduct(m, n, overflow);
  if (rhs.size(1) != varargin_1.size(1)) {
    wc_rtErrorWithMessageID(tc_emlrtRTEI.fName, tc_emlrtRTEI.lineNo);
  }
  if (overflow == 0) {
    sparse_validateNumericIndex(m * n, varargin_1);
  } else {
    sparse_validateNumericIndex(MAX_int32_T, varargin_1);
  }
  nidx = varargin_1.size(1);
  if (varargin_1.size(1) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int k{0}; k < nidx; k++) {
    double b_this[2];
    b_this[0] = m;
    b_this[1] = n;
    overflow = ind2sub_indexClass(b_this, varargin_1[k], varargout_4);
    parenAssign2D(rhs[k], static_cast<double>(overflow),
                  static_cast<double>(varargout_4));
  }
}

void b_sparse::c_le(d_sparse &s) const
{
  array<bool, 2U> S;
  int a;
  int b_n;
  S.set_size(1, S.size(1));
  if (n < 0) {
    rtNonNegativeError(static_cast<double>(n), u_emlrtDCI);
  }
  b_n = n;
  S.set_size(S.size(0), n);
  for (a = 0; a < b_n; a++) {
    S[a] = true;
  }
  b_n = n;
  if (n > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int col{0}; col < b_n; col++) {
    int b_tmp;
    a = colidx[col];
    b_tmp = colidx[col + 1] - 1;
    if ((colidx[col] <= b_tmp) && (b_tmp > 2147483646)) {
      check_forloop_overflow_error();
    }
    for (int idx{a}; idx <= b_tmp; idx++) {
      S[(rowidx[idx - 1] + col) - 1] = (d[idx - 1] <= 0.0);
    }
  }
  j_sparse(S, s);
}

void f_sparse::c_parenAssign(const h_sparse &rhs,
                             const ::coder::array<double, 2U> &varargin_1)
{
  e_sparse s;
  double varargout_1_tmp[2];
  int cend;
  int nidx;
  int overflow;
  int tmp;
  int varargout_4;
  bool rhsv;
  internal::bigProduct(m, n, overflow);
  varargout_1_tmp[0] = rhs.m;
  varargout_1_tmp[1] = 1.0;
  tmp = internal::bigProduct(rhs.m, 1, cend);
  if (((varargin_1.size(1) & 65535) + ((varargin_1.size(1) >> 16) << 16) !=
       tmp) ||
      (cend != 0)) {
    wc_rtErrorWithMessageID(tc_emlrtRTEI.fName, tc_emlrtRTEI.lineNo);
  }
  if (overflow == 0) {
    sparse_validateNumericIndex(m * n, varargin_1);
  } else {
    sparse_validateNumericIndex(MAX_int32_T, varargin_1);
  }
  nidx = varargin_1.size(1);
  if (varargin_1.size(1) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int k{0}; k < nidx; k++) {
    double b_this[2];
    int varargout_3;
    b_this[0] = m;
    b_this[1] = n;
    varargout_3 = ind2sub_indexClass(b_this, varargin_1[k], varargout_4);
    tmp = rhs.m >> 16;
    overflow = tmp >> 16;
    if ((rhs.m & 65535) > MAX_int32_T - (tmp << 16)) {
      overflow++;
    }
    if ((overflow == 0) && (k + 1 > rhs.m)) {
      rtErrorWithMessageID(k + 1, rhs.m, jc_emlrtRTEI.fName,
                           jc_emlrtRTEI.lineNo);
    }
    s.colidx.set_size(2);
    s.colidx[0] = 1;
    s.colidx[1] = 1;
    cend = ind2sub_indexClass(varargout_1_tmp, k + 1, tmp);
    overflow = sparse_locBsearch(rhs.rowidx, static_cast<double>(cend),
                                 rhs.colidx[tmp - 1], rhs.colidx[tmp], rhsv);
    if (rhsv) {
      s.d.set_size(1);
      s.d[0] = rhs.d[overflow - 1];
      s.colidx[1] = 2;
    } else {
      s.d.set_size(1);
      s.d[0] = false;
    }
    rhsv = false;
    cend = s.colidx[1] - 1;
    tmp = s.colidx[0];
    for (overflow = tmp; overflow <= cend; overflow++) {
      rhsv = s.d[overflow - 1];
    }
    parenAssign2D(rhsv, static_cast<double>(varargout_3),
                  static_cast<double>(varargout_4));
  }
}

void f_sparse::c_parenAssign(const ::coder::array<double, 2U> &rhs,
                             const ::coder::array<double, 2U> &varargin_1)
{
  int nidx;
  int overflow;
  int varargout_4;
  bool thisv;
  internal::bigProduct(m, n, overflow);
  if (rhs.size(1) != varargin_1.size(1)) {
    wc_rtErrorWithMessageID(tc_emlrtRTEI.fName, tc_emlrtRTEI.lineNo);
  }
  if (overflow == 0) {
    sparse_validateNumericIndex(m * n, varargin_1);
  } else {
    sparse_validateNumericIndex(MAX_int32_T, varargin_1);
  }
  nidx = varargin_1.size(1);
  if (varargin_1.size(1) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int k{0}; k < nidx; k++) {
    double b_this[2];
    int lowOrderSize;
    bool b;
    b_this[0] = m;
    b_this[1] = n;
    lowOrderSize = ind2sub_indexClass(b_this, varargin_1[k], varargout_4);
    if (lowOrderSize <= 0) {
      hc_rtErrorWithMessageID(nc_emlrtRTEI.fName, nc_emlrtRTEI.lineNo);
    }
    if (lowOrderSize > m) {
      rtErrorWithMessageID(lowOrderSize, m, jc_emlrtRTEI.fName,
                           jc_emlrtRTEI.lineNo);
    }
    if (varargout_4 <= 0) {
      hc_rtErrorWithMessageID(nc_emlrtRTEI.fName, nc_emlrtRTEI.lineNo);
    }
    if (varargout_4 > n) {
      rtErrorWithMessageID(varargout_4, n, jc_emlrtRTEI.fName,
                           jc_emlrtRTEI.lineNo);
    }
    overflow =
        b_sparse_locBsearch(rowidx, lowOrderSize, colidx[varargout_4 - 1],
                            colidx[varargout_4], thisv);
    if (thisv) {
      thisv = d[overflow - 1];
    } else {
      thisv = false;
    }
    b = !thisv;
    if ((!b) || (!(rhs[k] == 0.0))) {
      if (thisv && (rhs[k] != 0.0)) {
        d[overflow - 1] = (rhs[k] != 0.0);
      } else if (b) {
        int nelem;
        if (colidx[colidx.size(0) - 1] - 1 == maxnz) {
          sparse::b_realloc(this, colidx[colidx.size(0) - 1] + 9, overflow,
                            overflow + 1, colidx[colidx.size(0) - 1] - 1);
          rowidx[overflow] = lowOrderSize;
          d[overflow] = (rhs[k] != 0.0);
        } else {
          nelem = (colidx[colidx.size(0) - 1] - overflow) - 1;
          if (nelem > 0) {
            std::memmove((void *)&rowidx[overflow + 1],
                         (void *)&rowidx[overflow],
                         (unsigned int)((size_t)nelem * sizeof(int)));
            std::memmove((void *)&d[overflow + 1], (void *)&d[overflow],
                         (unsigned int)((size_t)nelem * sizeof(bool)));
          }
          d[overflow] = (rhs[k] != 0.0);
          rowidx[overflow] = lowOrderSize;
        }
        overflow = varargout_4 + 1;
        lowOrderSize = n + 1;
        if ((varargout_4 + 1 <= n + 1) && (n + 1 > 2147483646)) {
          check_forloop_overflow_error();
        }
        for (nelem = overflow; nelem <= lowOrderSize; nelem++) {
          colidx[nelem - 1] = colidx[nelem - 1] + 1;
        }
      } else {
        int nelem;
        nelem = (colidx[colidx.size(0) - 1] - overflow) - 1;
        if (nelem > 0) {
          std::memmove((void *)&rowidx[overflow - 1], (void *)&rowidx[overflow],
                       (unsigned int)((size_t)nelem * sizeof(int)));
          std::memmove((void *)&d[overflow - 1], (void *)&d[overflow],
                       (unsigned int)((size_t)nelem * sizeof(bool)));
        }
        overflow = varargout_4 + 1;
        lowOrderSize = n + 1;
        if ((varargout_4 + 1 <= lowOrderSize) && (lowOrderSize > 2147483646)) {
          check_forloop_overflow_error();
        }
        for (nelem = overflow; nelem <= lowOrderSize; nelem++) {
          colidx[nelem - 1] = colidx[nelem - 1] - 1;
        }
      }
    }
  }
}

void b_sparse::eq(const c_sparse &b, d_sparse &s) const
{
  static rtRunTimeErrorInfo vc_emlrtRTEI{
      460,                // lineNo
      34,                 // colNo
      "sparse/spfunImpl", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/coder/coder/+coder/"
      "+internal/@sparse/sparse.m" // pName
  };
  static rtRunTimeErrorInfo wc_emlrtRTEI{
      178,             // lineNo
      39,              // colNo
      "sparse/sparse", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/coder/coder/+coder/"
      "+internal/@sparse/sparse.m" // pName
  };
  d_anonymous_function uniOp;
  array<bool, 2U> S;
  array<bool, 1U> tmpd;
  if (b.colidx[b.colidx.size(0) - 1] - 1 > 0) {
    uniOp.workspace.sb = b.d[0];
  } else {
    uniOp.workspace.sb = 0.0;
  }
  if (!(uniOp.workspace.sb == 0.0)) {
    int b_n;
    int b_tmp;
    int i;
    int idx;
    b_tmp = colidx[colidx.size(0) - 1];
    if (b_tmp - 1 < 1) {
      b_n = 0;
    } else {
      b_n = b_tmp - 1;
    }
    tmpd.set_size(b_n);
    for (i = 0; i < b_n; i++) {
      tmpd[i] = (d[i] == uniOp.workspace.sb);
    }
    if (tmpd.size(0) != b_tmp - 1) {
      mb_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
    }
    if (n < 0) {
      ec_rtErrorWithMessageID(mc_emlrtRTEI.fName, mc_emlrtRTEI.lineNo);
    }
    if (n >= MAX_int32_T) {
      ad_rtErrorWithMessageID(kc_emlrtRTEI.fName, kc_emlrtRTEI.lineNo);
    }
    s.n = n;
    if (b_tmp - 1 < 0) {
      ec_rtErrorWithMessageID(mc_emlrtRTEI.fName, mc_emlrtRTEI.lineNo);
    }
    if (b_tmp - 1 >= MAX_int32_T) {
      ad_rtErrorWithMessageID(kc_emlrtRTEI.fName, kc_emlrtRTEI.lineNo);
    }
    if (b_tmp - 1 < 0) {
      fc_rtErrorWithMessageID(wc_emlrtRTEI.fName, wc_emlrtRTEI.lineNo);
    }
    if (b_tmp - 1 >= 1) {
      b_n = b_tmp - 2;
    } else {
      b_n = 0;
    }
    s.d.set_size(b_n + 1);
    s.colidx.set_size(n + 1);
    s.rowidx.set_size(b_n + 1);
    for (i = 0; i <= b_n; i++) {
      s.d[i] = false;
      s.rowidx[i] = 0;
    }
    b_n = n;
    for (int col{0}; col < b_n; col++) {
      s.colidx[col + 1] = 1;
    }
    i = s.colidx.size(0);
    for (int col{0}; col <= i - 2; col++) {
      s.colidx[col] = 1;
    }
    if (b_tmp - 1 < 1) {
      b_n = 1;
    } else {
      b_n = b_tmp;
    }
    for (i = 0; i <= b_n - 2; i++) {
      s.rowidx[i] = rowidx[i];
    }
    s.colidx.set_size(colidx.size(0));
    b_n = colidx.size(0);
    for (i = 0; i < b_n; i++) {
      s.colidx[i] = colidx[i];
    }
    if (b_tmp - 1 > 2147483646) {
      check_forloop_overflow_error();
    }
    for (b_n = 0; b_n <= b_tmp - 2; b_n++) {
      s.d[b_n] = tmpd[b_n];
    }
    idx = 1;
    i = colidx.size(0);
    for (int col{0}; col <= i - 2; col++) {
      b_n = s.colidx[col];
      s.colidx[col] = idx;
      while (b_n < s.colidx[col + 1]) {
        int currRowIdx;
        bool val;
        currRowIdx = s.rowidx[b_n - 1];
        val = s.d[b_n - 1];
        b_n++;
        if (val) {
          s.d[idx - 1] = true;
          s.rowidx[idx - 1] = currRowIdx;
          idx++;
        }
      }
    }
    s.colidx[s.colidx.size(0) - 1] = idx;
  } else {
    int b_n;
    S.set_size(1, S.size(1));
    if (n < 0) {
      rtNonNegativeError(static_cast<double>(n), u_emlrtDCI);
    }
    b_n = n;
    S.set_size(S.size(0), n);
    for (int i{0}; i < b_n; i++) {
      S[i] = true;
    }
    b_n = n;
    if (n > 2147483646) {
      check_forloop_overflow_error();
    }
    for (int col{0}; col < b_n; col++) {
      int b_tmp;
      int currRowIdx;
      currRowIdx = colidx[col];
      b_tmp = colidx[col + 1] - 1;
      if ((colidx[col] <= b_tmp) && (b_tmp > 2147483646)) {
        check_forloop_overflow_error();
      }
      for (int idx{currRowIdx}; idx <= b_tmp; idx++) {
        S[(rowidx[idx - 1] + col) - 1] = (d[idx - 1] == uniOp.workspace.sb);
      }
    }
    j_sparse(S, s);
  }
}

void sparse::eyeLike(int ndiag, int b_m, int b_n, sparse &b_I)
{
  int b;
  int nzmax;
  b_I.m = b_m;
  nzmax = ndiag;
  b_I.n = b_n;
  if (ndiag < 1) {
    nzmax = 1;
  }
  b_I.maxnz = nzmax;
  b_I.d.set_size(nzmax);
  b_I.rowidx.set_size(nzmax);
  if (b_n + 1 < 0) {
    rtNonNegativeError(static_cast<double>(b_n + 1), t_emlrtDCI);
  }
  b_I.colidx.set_size(b_n + 1);
  if (ndiag > 2147483646) {
    check_forloop_overflow_error();
  }
  for (nzmax = 0; nzmax < ndiag; nzmax++) {
    b_I.d[nzmax] = 1.0;
    b_I.rowidx[nzmax] = nzmax + 1;
  }
  b_I.colidx[0] = 1;
  for (int c{2}; c <= ndiag; c++) {
    b_I.colidx[c - 1] = c;
  }
  nzmax = ndiag + 1;
  b = b_n + 1;
  if ((ndiag + 1 <= b_n + 1) && (b_n + 1 > 2147483646)) {
    check_forloop_overflow_error();
  }
  for (int c{nzmax}; c <= b; c++) {
    b_I.colidx[c - 1] = ndiag + 1;
  }
}

void sparse::fillIn()
{
  int i;
  int idx;
  idx = 1;
  i = colidx.size(0);
  for (int c{0}; c <= i - 2; c++) {
    int ridx;
    ridx = colidx[c];
    colidx[c] = idx;
    int exitg1;
    int i1;
    do {
      exitg1 = 0;
      i1 = colidx[c + 1];
      if (ridx < i1) {
        double val;
        int currRowIdx;
        val = 0.0;
        currRowIdx = rowidx[ridx - 1];
        while ((ridx < i1) && (rowidx[ridx - 1] == currRowIdx)) {
          val += d[ridx - 1];
          ridx++;
        }
        if (val != 0.0) {
          d[idx - 1] = val;
          rowidx[idx - 1] = currRowIdx;
          idx++;
        }
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  colidx[colidx.size(0) - 1] = idx;
}

void g_sparse::logical(h_sparse &y) const
{
  int numalloc;
  if (m < 0) {
    ec_rtErrorWithMessageID(mc_emlrtRTEI.fName, mc_emlrtRTEI.lineNo);
  }
  if (m >= MAX_int32_T) {
    ad_rtErrorWithMessageID(kc_emlrtRTEI.fName, kc_emlrtRTEI.lineNo);
  }
  y.m = m;
  if (maxnz < 0) {
    ec_rtErrorWithMessageID(mc_emlrtRTEI.fName, mc_emlrtRTEI.lineNo);
  }
  if (maxnz >= MAX_int32_T) {
    ad_rtErrorWithMessageID(kc_emlrtRTEI.fName, kc_emlrtRTEI.lineNo);
  }
  numalloc = maxnz;
  if (numalloc < 1) {
    numalloc = 1;
  }
  y.d.set_size(numalloc);
  for (int k{0}; k < numalloc; k++) {
    y.d[k] = false;
  }
  y.rowidx.set_size(rowidx.size(0));
  numalloc = rowidx.size(0);
  for (int k{0}; k < numalloc; k++) {
    y.rowidx[k] = rowidx[k];
  }
  y.colidx.set_size(colidx.size(0));
  numalloc = colidx.size(0);
  for (int k{0}; k < numalloc; k++) {
    y.colidx[k] = colidx[k];
  }
  numalloc = colidx[colidx.size(0) - 1] - 1;
  if (numalloc < 1) {
    numalloc = 1;
  }
  for (int k{0}; k < numalloc; k++) {
    if (std::isnan(d[k])) {
      w_rtErrorWithMessageID(jb_emlrtRTEI.fName, jb_emlrtRTEI.lineNo);
    }
  }
  for (int k{0}; k < numalloc; k++) {
    y.d[k] = (d[k] != 0.0);
  }
}

void sparse::logical(f_sparse &y) const
{
  int i;
  int numalloc;
  if (m < 0) {
    ec_rtErrorWithMessageID(mc_emlrtRTEI.fName, mc_emlrtRTEI.lineNo);
  }
  if (m >= MAX_int32_T) {
    ad_rtErrorWithMessageID(kc_emlrtRTEI.fName, kc_emlrtRTEI.lineNo);
  }
  if (n < 0) {
    ec_rtErrorWithMessageID(mc_emlrtRTEI.fName, mc_emlrtRTEI.lineNo);
  }
  if (n >= MAX_int32_T) {
    ad_rtErrorWithMessageID(kc_emlrtRTEI.fName, kc_emlrtRTEI.lineNo);
  }
  y.m = m;
  y.n = n;
  if (maxnz < 0) {
    ec_rtErrorWithMessageID(mc_emlrtRTEI.fName, mc_emlrtRTEI.lineNo);
  }
  if (maxnz >= MAX_int32_T) {
    ad_rtErrorWithMessageID(kc_emlrtRTEI.fName, kc_emlrtRTEI.lineNo);
  }
  numalloc = maxnz;
  if (numalloc < 1) {
    numalloc = 1;
  }
  y.d.set_size(numalloc);
  for (i = 0; i < numalloc; i++) {
    y.d[i] = false;
  }
  y.maxnz = numalloc;
  y.colidx.set_size(n + 1);
  numalloc = n;
  for (int c{0}; c < numalloc; c++) {
    y.colidx[c + 1] = 1;
  }
  i = y.colidx.size(0);
  for (int c{0}; c <= i - 2; c++) {
    y.colidx[c] = 1;
  }
  y.rowidx.set_size(rowidx.size(0));
  numalloc = rowidx.size(0);
  for (i = 0; i < numalloc; i++) {
    y.rowidx[i] = rowidx[i];
  }
  y.colidx.set_size(colidx.size(0));
  numalloc = colidx.size(0);
  for (i = 0; i < numalloc; i++) {
    y.colidx[i] = colidx[i];
  }
  numalloc = colidx[colidx.size(0) - 1] - 1;
  if (numalloc < 1) {
    numalloc = 1;
  }
  for (int c{0}; c < numalloc; c++) {
    if (std::isnan(d[c])) {
      w_rtErrorWithMessageID(jb_emlrtRTEI.fName, jb_emlrtRTEI.lineNo);
    }
  }
  for (i = 0; i < numalloc; i++) {
    y.d[i] = (d[i] != 0.0);
  }
}

void f_sparse::mtimes(const ::coder::array<double, 2U> &b,
                      ::coder::array<double, 2U> &c) const
{
  static rtDoubleCheckInfo w_emlrtDCI{
      209,        // lineNo
      11,         // colNo
      "sfmtimes", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/coder/coder/+coder/"
      "+internal/@sparse/mtimes.m", // pName
      4                             // checkKind
  };
  int apendm1_tmp;
  int b_n;
  int nap;
  if (n != b.size(0)) {
    qb_rtErrorWithMessageID(cc_emlrtRTEI.fName, cc_emlrtRTEI.lineNo);
  }
  b_n = b.size(1);
  if (m < 0) {
    rtNonNegativeError(static_cast<double>(m), w_emlrtDCI);
  }
  c.set_size(m, b.size(1));
  nap = m * b.size(1);
  for (apendm1_tmp = 0; apendm1_tmp < nap; apendm1_tmp++) {
    c[apendm1_tmp] = 0.0;
  }
  if ((n != 0) && (m != 0) && (b.size(1) != 0) &&
      (colidx[colidx.size(0) - 1] - 1 != 0)) {
    if (b.size(1) == 1) {
      int b_b;
      b_b = n;
      if (n > 2147483646) {
        check_forloop_overflow_error();
      }
      for (int acol{0}; acol < b_b; acol++) {
        double bc;
        int a;
        int nap_tmp;
        bc = b[acol];
        a = colidx[acol];
        nap_tmp = colidx[acol + 1];
        nap = nap_tmp - colidx[acol];
        if (nap >= 4) {
          nap = ((nap_tmp - nap) + ((nap / 4) << 2)) - 1;
          if ((colidx[acol] <= nap) && (nap > 2147483643)) {
            check_forloop_overflow_error();
          }
          for (int ap{a}; ap <= nap; ap += 4) {
            apendm1_tmp = rowidx[ap - 1] - 1;
            c[apendm1_tmp] =
                c[apendm1_tmp] + static_cast<double>(d[ap - 1]) * bc;
            c[rowidx[ap] - 1] =
                c[rowidx[ap] - 1] + static_cast<double>(d[ap]) * bc;
            apendm1_tmp = rowidx[ap + 1] - 1;
            c[apendm1_tmp] =
                c[apendm1_tmp] + static_cast<double>(d[ap + 1]) * bc;
            apendm1_tmp = rowidx[ap + 2] - 1;
            c[apendm1_tmp] =
                c[apendm1_tmp] + static_cast<double>(d[ap + 2]) * bc;
          }
          apendm1_tmp = nap_tmp - 1;
          a = nap + 1;
          if ((nap + 1 <= nap_tmp - 1) && (nap_tmp - 1 > 2147483646)) {
            check_forloop_overflow_error();
          }
          for (int ap{a}; ap <= apendm1_tmp; ap++) {
            nap = rowidx[ap - 1] - 1;
            c[nap] = c[nap] + static_cast<double>(d[ap - 1]) * bc;
          }
        } else {
          nap = nap_tmp - 1;
          if ((colidx[acol] <= nap_tmp - 1) && (nap_tmp - 1 > 2147483646)) {
            check_forloop_overflow_error();
          }
          for (int ap{a}; ap <= nap; ap++) {
            apendm1_tmp = rowidx[ap - 1] - 1;
            c[apendm1_tmp] =
                c[apendm1_tmp] + static_cast<double>(d[ap - 1]) * bc;
          }
        }
      }
    } else {
      int b_b;
      bool overflow;
      if (b.size(1) > 2147483646) {
        check_forloop_overflow_error();
      }
      b_b = n;
      overflow = (n > 2147483646);
      for (int j{0}; j < b_n; j++) {
        int coff;
        coff = j * c.size(0) - 1;
        if (overflow) {
          check_forloop_overflow_error();
        }
        for (int acol{0}; acol < b_b; acol++) {
          double bc;
          int a;
          int nap_tmp;
          bc = b[acol + b.size(0) * j];
          a = colidx[acol];
          nap_tmp = colidx[acol + 1];
          nap = nap_tmp - colidx[acol];
          if (nap >= 4) {
            nap = ((nap_tmp - nap) + ((nap / 4) << 2)) - 1;
            if ((colidx[acol] <= nap) && (nap > 2147483643)) {
              check_forloop_overflow_error();
            }
            for (int ap{a}; ap <= nap; ap += 4) {
              apendm1_tmp = rowidx[ap - 1] + coff;
              c[apendm1_tmp] =
                  c[apendm1_tmp] + static_cast<double>(d[ap - 1]) * bc;
              apendm1_tmp = rowidx[ap] + coff;
              c[apendm1_tmp] = c[apendm1_tmp] + static_cast<double>(d[ap]) * bc;
              apendm1_tmp = rowidx[ap + 1] + coff;
              c[apendm1_tmp] =
                  c[apendm1_tmp] + static_cast<double>(d[ap + 1]) * bc;
              apendm1_tmp = rowidx[ap + 2] + coff;
              c[apendm1_tmp] =
                  c[apendm1_tmp] + static_cast<double>(d[ap + 2]) * bc;
            }
            apendm1_tmp = nap_tmp - 1;
            a = nap + 1;
            if ((nap + 1 <= nap_tmp - 1) && (nap_tmp - 1 > 2147483646)) {
              check_forloop_overflow_error();
            }
            for (int ap{a}; ap <= apendm1_tmp; ap++) {
              nap = rowidx[ap - 1] - 1;
              c[nap + c.size(0) * j] =
                  c[nap + c.size(0) * j] + static_cast<double>(d[ap - 1]) * bc;
            }
          } else {
            nap = nap_tmp - 1;
            if ((colidx[acol] <= nap_tmp - 1) && (nap_tmp - 1 > 2147483646)) {
              check_forloop_overflow_error();
            }
            for (int ap{a}; ap <= nap; ap++) {
              apendm1_tmp = rowidx[ap - 1] + coff;
              c[apendm1_tmp] =
                  c[apendm1_tmp] + static_cast<double>(d[ap - 1]) * bc;
            }
          }
        }
      }
    }
  }
}

void sparse::mtimes(const ::coder::array<double, 2U> &a,
                    ::coder::array<double, 2U> &c) const
{
  int aoff;
  int b_m;
  int b_n;
  int cidx;
  if (a.size(1) != m) {
    qb_rtErrorWithMessageID(cc_emlrtRTEI.fName, cc_emlrtRTEI.lineNo);
  }
  b_m = a.size(0);
  b_n = n - 1;
  c.set_size(a.size(0), c.size(1));
  if (n < 0) {
    rtNonNegativeError(static_cast<double>(n), s_emlrtDCI);
  }
  c.set_size(c.size(0), n);
  aoff = a.size(0) * n;
  for (cidx = 0; cidx < aoff; cidx++) {
    c[cidx] = 0.0;
  }
  if ((a.size(1) != 0) && (a.size(0) != 0) && (n != 0) &&
      (colidx[colidx.size(0) - 1] - 1 != 0)) {
    if (a.size(0) == 1) {
      aoff = n;
      if (n > 2147483646) {
        check_forloop_overflow_error();
      }
      for (int aidx_tmp{0}; aidx_tmp < aoff; aidx_tmp++) {
        double bd;
        int b_a;
        bd = 0.0;
        cidx = colidx[aidx_tmp + 1] - 1;
        b_a = colidx[aidx_tmp];
        if ((colidx[aidx_tmp] <= cidx) && (cidx > 2147483646)) {
          check_forloop_overflow_error();
        }
        for (int mend{b_a}; mend <= cidx; mend++) {
          bd += d[mend - 1] * a[rowidx[mend - 1] - 1];
        }
        c[aidx_tmp] = bd;
      }
    } else if (a.size(0) >= 4) {
      if (n > 2147483646) {
        check_forloop_overflow_error();
      }
      for (int ccol{0}; ccol <= b_n; ccol++) {
        int b_a;
        int bpend_tmp;
        int coff;
        coff = ccol * c.size(0);
        bpend_tmp = colidx[ccol + 1] - 1;
        b_a = colidx[ccol];
        if ((colidx[ccol] <= bpend_tmp) && (bpend_tmp > 2147483646)) {
          check_forloop_overflow_error();
        }
        for (int bp{b_a}; bp <= bpend_tmp; bp++) {
          double bd;
          int aoff_tmp;
          int mend;
          aoff_tmp = rowidx[bp - 1] - 1;
          aoff = aoff_tmp * a.size(0);
          bd = d[bp - 1];
          mend = (b_m / 4) << 2;
          if (mend > 2147483643) {
            check_forloop_overflow_error();
          }
          for (int crow{1}; crow <= mend; crow += 4) {
            int aidx_tmp;
            cidx = crow + coff;
            aidx_tmp = crow + aoff;
            c[cidx - 1] = c[cidx - 1] + a[aidx_tmp - 1] * bd;
            c[cidx] = c[cidx] + a[aidx_tmp] * bd;
            c[cidx + 1] = c[cidx + 1] + a[aidx_tmp + 1] * bd;
            c[cidx + 2] = c[cidx + 2] + a[aidx_tmp + 2] * bd;
          }
          aoff = mend + 1;
          if ((mend + 1 <= b_m) && (b_m > 2147483646)) {
            check_forloop_overflow_error();
          }
          for (int crow{aoff}; crow <= b_m; crow++) {
            cidx = (crow + coff) - 1;
            c[cidx] = c[cidx] + a[(crow + a.size(0) * aoff_tmp) - 1] * bd;
          }
        }
      }
    } else {
      if (n > 2147483646) {
        check_forloop_overflow_error();
      }
      for (int ccol{0}; ccol <= b_n; ccol++) {
        int b_a;
        int bpend_tmp;
        bpend_tmp = colidx[ccol + 1] - 1;
        b_a = colidx[ccol];
        if ((colidx[ccol] <= bpend_tmp) && (bpend_tmp > 2147483646)) {
          check_forloop_overflow_error();
        }
        for (int bp{b_a}; bp <= bpend_tmp; bp++) {
          for (int crow{0}; crow < b_m; crow++) {
            c[crow + c.size(0) * ccol] =
                c[crow + c.size(0) * ccol] +
                a[crow + a.size(0) * (rowidx[bp - 1] - 1)] * d[bp - 1];
          }
        }
      }
    }
  }
}

void f_sparse::parenAssign(const ::coder::array<bool, 1U> &rhs,
                           const ::coder::array<double, 2U> &varargin_1)
{
  int nidx;
  int overflow;
  int varargout_4;
  internal::bigProduct(m, n, overflow);
  if (rhs.size(0) != varargin_1.size(1)) {
    wc_rtErrorWithMessageID(tc_emlrtRTEI.fName, tc_emlrtRTEI.lineNo);
  }
  if (overflow == 0) {
    sparse_validateNumericIndex(m * n, varargin_1);
  } else {
    sparse_validateNumericIndex(MAX_int32_T, varargin_1);
  }
  nidx = varargin_1.size(1);
  if (varargin_1.size(1) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int k{0}; k < nidx; k++) {
    double b_this[2];
    b_this[0] = m;
    b_this[1] = n;
    overflow = ind2sub_indexClass(b_this, varargin_1[k], varargout_4);
    parenAssign2D(rhs[k], static_cast<double>(overflow),
                  static_cast<double>(varargout_4));
  }
}

void b_sparse::parenReference(c_sparse &s) const
{
  int overflow;
  int tmp;
  bool found;
  tmp = n >> 16;
  overflow = tmp >> 16;
  if ((n & 65535) > MAX_int32_T - (tmp << 16)) {
    overflow++;
  }
  if ((overflow == 0) && (n < 1)) {
    rtErrorWithMessageID(1, n, jc_emlrtRTEI.fName, jc_emlrtRTEI.lineNo);
  }
  s.colidx.set_size(2);
  s.colidx[0] = 1;
  s.colidx[1] = 1;
  if (n < 1) {
    cc_rtErrorWithMessageID(ic_emlrtRTEI.fName, ic_emlrtRTEI.lineNo);
  }
  tmp = sparse_locBsearch(rowidx, 1.0, colidx[0], colidx[1], found);
  if (found) {
    s.d.set_size(1);
    s.d[0] = d[tmp - 1];
    s.rowidx.set_size(1);
    s.rowidx[0] = 1;
    s.colidx[1] = 2;
  } else {
    s.d.set_size(1);
    s.d[0] = 0.0;
    s.rowidx.set_size(1);
    s.rowidx[0] = 0;
  }
}

void sparse::parenReference(g_sparse &s) const
{
  int i;
  int nd_tmp;
  int numalloc;
  if (n < 1) {
    rtErrorWithMessageID(1, n, jc_emlrtRTEI.fName, jc_emlrtRTEI.lineNo);
  }
  nd_tmp = colidx[1] - colidx[0];
  if ((nd_tmp > m) && (m != 0)) {
    h_rtErrorWithMessageID(oc_emlrtRTEI.fName, oc_emlrtRTEI.lineNo);
  }
  if (m < 0) {
    ec_rtErrorWithMessageID(mc_emlrtRTEI.fName, mc_emlrtRTEI.lineNo);
  }
  if (m >= MAX_int32_T) {
    ad_rtErrorWithMessageID(kc_emlrtRTEI.fName, kc_emlrtRTEI.lineNo);
  }
  s.m = m;
  if (nd_tmp < 0) {
    ec_rtErrorWithMessageID(mc_emlrtRTEI.fName, mc_emlrtRTEI.lineNo);
  }
  if (nd_tmp >= MAX_int32_T) {
    ad_rtErrorWithMessageID(kc_emlrtRTEI.fName, kc_emlrtRTEI.lineNo);
  }
  if (nd_tmp >= 1) {
    numalloc = nd_tmp;
  } else {
    numalloc = 1;
  }
  s.d.set_size(numalloc);
  s.maxnz = numalloc;
  s.colidx.set_size(2);
  s.rowidx.set_size(numalloc);
  for (i = 0; i < numalloc; i++) {
    s.d[i] = 0.0;
    s.rowidx[i] = 0;
  }
  s.colidx[0] = 1;
  s.colidx[1] = 1;
  if (nd_tmp != 0) {
    numalloc = colidx[0] - 2;
    for (int k{0}; k < nd_tmp; k++) {
      i = (numalloc + k) + 1;
      s.d[k] = d[i];
      s.rowidx[k] = rowidx[i];
    }
    s.colidx[1] = nd_tmp + 1;
  }
}

void sparse::parenReference(const ::coder::array<double, 1U> &varargin_2,
                            sparse &s) const
{
  int i;
  int nd;
  int nd_tmp;
  int sn;
  int ub;
  ub = n;
  i = varargin_2.size(0);
  for (int k{0}; k < i; k++) {
    double b_d;
    b_d = std::floor(varargin_2[k]);
    if ((!(b_d == varargin_2[k])) || std::isinf(varargin_2[k]) ||
        (!(varargin_2[k] > 0.0))) {
      hc_rtErrorWithMessageID(nc_emlrtRTEI.fName, nc_emlrtRTEI.lineNo);
    }
    if (!(varargin_2[k] <= ub)) {
      rtErrorWithMessageID(static_cast<int>(b_d), ub, jc_emlrtRTEI.fName,
                           jc_emlrtRTEI.lineNo);
    }
  }
  sn = varargin_2.size(0) - 1;
  ub = m * varargin_2.size(0);
  nd = 0;
  if (varargin_2.size(0) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int cidx{0}; cidx <= sn; cidx++) {
    nd_tmp = static_cast<int>(varargin_2[cidx]);
    nd = (nd + colidx[nd_tmp]) - colidx[nd_tmp - 1];
  }
  if ((nd > ub) && (ub != 0)) {
    h_rtErrorWithMessageID(oc_emlrtRTEI.fName, oc_emlrtRTEI.lineNo);
  }
  if (m < 0) {
    ec_rtErrorWithMessageID(mc_emlrtRTEI.fName, mc_emlrtRTEI.lineNo);
  }
  if (m >= MAX_int32_T) {
    ad_rtErrorWithMessageID(kc_emlrtRTEI.fName, kc_emlrtRTEI.lineNo);
  }
  s.m = m;
  s.n = varargin_2.size(0);
  if (nd < 0) {
    ec_rtErrorWithMessageID(mc_emlrtRTEI.fName, mc_emlrtRTEI.lineNo);
  }
  if (nd >= MAX_int32_T) {
    ad_rtErrorWithMessageID(kc_emlrtRTEI.fName, kc_emlrtRTEI.lineNo);
  }
  if (nd >= 1) {
    ub = nd;
  } else {
    ub = 1;
  }
  s.d.set_size(ub);
  s.maxnz = ub;
  s.colidx.set_size(varargin_2.size(0) + 1);
  s.colidx[0] = 1;
  s.rowidx.set_size(ub);
  for (i = 0; i < ub; i++) {
    s.d[i] = 0.0;
    s.rowidx[i] = 0;
  }
  ub = varargin_2.size(0);
  for (nd_tmp = 0; nd_tmp < ub; nd_tmp++) {
    s.colidx[nd_tmp + 1] = 1;
  }
  s.fillIn();
  if (nd != 0) {
    nd = 0;
    for (int cidx{0}; cidx <= sn; cidx++) {
      int colstart_tmp;
      ub = static_cast<int>(varargin_2[cidx]);
      colstart_tmp = colidx[ub - 1];
      ub = colidx[ub] - colstart_tmp;
      if (ub > 2147483646) {
        check_forloop_overflow_error();
      }
      for (int k{0}; k < ub; k++) {
        i = (colstart_tmp + k) - 1;
        nd_tmp = nd + k;
        s.d[nd_tmp] = d[i];
        s.rowidx[nd_tmp] = rowidx[i];
      }
      nd += ub;
      s.colidx[cidx + 1] = s.colidx[cidx] + ub;
    }
  }
}

void f_sparse::parenReference(const ::coder::array<double, 2U> &varargin_1,
                              d_sparse &s) const
{
  array<double, 2U> linidx;
  double dv[2];
  double varargout_1_tmp[2];
  int colNnz;
  int i;
  int loop_ub;
  int ncol;
  int overflow;
  bool found;
  linidx.set_size(1, varargin_1.size(1));
  loop_ub = varargin_1.size(1);
  for (i = 0; i < loop_ub; i++) {
    linidx[i] = varargin_1[i];
  }
  internal::b_bigProduct(m, n, overflow);
  if (overflow == 0) {
    overflow = m * n;
    i = linidx.size(1);
    for (loop_ub = 0; loop_ub < i; loop_ub++) {
      double b_d;
      double d1;
      b_d = linidx[loop_ub];
      d1 = std::floor(b_d);
      if ((!(d1 == b_d)) || std::isinf(b_d) || (!(b_d > 0.0))) {
        hc_rtErrorWithMessageID(nc_emlrtRTEI.fName, nc_emlrtRTEI.lineNo);
      }
      if (!(b_d <= overflow)) {
        rtErrorWithMessageID(static_cast<int>(d1), overflow, jc_emlrtRTEI.fName,
                             jc_emlrtRTEI.lineNo);
      }
    }
  } else {
    i = linidx.size(1);
    for (loop_ub = 0; loop_ub < i; loop_ub++) {
      double b_d;
      double d1;
      b_d = linidx[loop_ub];
      d1 = std::floor(b_d);
      if ((!(d1 == b_d)) || std::isinf(b_d) || (!(b_d > 0.0))) {
        hc_rtErrorWithMessageID(nc_emlrtRTEI.fName, nc_emlrtRTEI.lineNo);
      }
      if (!(b_d <= 2.147483647E+9)) {
        rtErrorWithMessageID(static_cast<int>(d1), MAX_int32_T,
                             jc_emlrtRTEI.fName, jc_emlrtRTEI.lineNo);
      }
    }
  }
  ncol = varargin_1.size(1);
  varargout_1_tmp[0] = m;
  varargout_1_tmp[1] = n;
  dv[0] = 1.0;
  dv[1] = (static_cast<double>(varargin_1.size(1)) - 1.0) + 1.0;
  internal::indexShapeCheck(varargout_1_tmp, dv);
  s.n = varargin_1.size(1);
  found = (varargin_1.size(1) + 1 < 0);
  if (found) {
    rtNonNegativeError(static_cast<double>(varargin_1.size(1) + 1), t_emlrtDCI);
  }
  s.d.set_size(0);
  s.rowidx.set_size(0);
  loop_ub = varargin_1.size(1) + 1;
  s.colidx.set_size(varargin_1.size(1) + 1);
  for (i = 0; i < loop_ub; i++) {
    s.colidx[i] = 0;
  }
  s.colidx[0] = 1;
  colNnz = 1;
  if (varargin_1.size(1) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int cidx{0}; cidx < ncol; cidx++) {
    overflow = ind2sub_indexClass(varargout_1_tmp,
                                  static_cast<int>(varargin_1[cidx]), loop_ub);
    overflow = sparse_locBsearch(rowidx, static_cast<double>(overflow),
                                 colidx[loop_ub - 1], colidx[loop_ub], found);
    if (found) {
      i = s.d.size(0);
      s.d.set_size(s.d.size(0) + 1);
      s.d[i] = d[overflow - 1];
      i = s.rowidx.size(0);
      s.rowidx.set_size(s.rowidx.size(0) + 1);
      s.rowidx[i] = 1;
      colNnz++;
    }
    s.colidx[cidx + 1] = colNnz;
  }
  if (s.d.size(0) == 0) {
    s.d.set_size(1);
    s.d[0] = false;
    s.rowidx.set_size(1);
    s.rowidx[0] = 0;
  }
}

} // namespace coder

// End of code generation (sparse1.cpp)
