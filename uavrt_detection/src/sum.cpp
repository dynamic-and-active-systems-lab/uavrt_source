//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// sum.cpp
//
// Code generation for function 'sum'
//

// Include files
#include "sum.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "sparse1.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
void sum(const sparse &x, b_sparse &y)
{
  static rtDoubleCheckInfo w_emlrtDCI{
      132,                     // lineNo
      39,                      // colNo
      "combineVectorElements", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/datafun/private/"
      "combineVectorElements.m", // pName
      4                          // checkKind
  };
  static rtDoubleCheckInfo
      x_emlrtDCI{
          20,    // lineNo
          1,     // colNo
          "sum", // fName
          "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/datafun/"
          "sum.m", // pName
          4        // checkKind
      };
  if ((x.m == 0) || (x.n == 0) || (x.m == 0)) {
    int t;
    if (x.n < 0) {
      t = 1;
    } else {
      t = x.n + 1;
    }
    y.n = t - 1;
    if (t < 0) {
      rtNonNegativeError(static_cast<double>(t), x_emlrtDCI);
    }
    y.colidx.set_size(t);
    for (int outidx{0}; outidx < t; outidx++) {
      y.colidx[outidx] = 1;
    }
    y.d.set_size(1);
    y.d[0] = 0.0;
    y.rowidx.set_size(1);
    y.rowidx[0] = 1;
  } else {
    int outidx;
    int t;
    t = x.n;
    outidx = x.colidx[x.colidx.size(0) - 1] - 1;
    if (t <= outidx) {
      outidx = t;
    }
    y.n = x.n;
    if (outidx < 1) {
      outidx = 1;
    }
    y.d.set_size(outidx);
    y.rowidx.set_size(outidx);
    if (x.n + 1 < 0) {
      rtNonNegativeError(static_cast<double>(x.n + 1), t_emlrtDCI);
    }
    y.colidx.set_size(x.n + 1);
    y.colidx[0] = 1;
    outidx = 1;
    t = x.n;
    if (x.n > 2147483646) {
      check_forloop_overflow_error();
    }
    for (int col{0}; col < t; col++) {
      double r;
      int xend;
      int xstart_tmp;
      xstart_tmp = x.colidx[col];
      xend = x.colidx[col + 1] - 1;
      r = 0.0;
      if ((xstart_tmp <= x.colidx[col + 1] - 1) &&
          (x.colidx[col + 1] - 1 > 2147483646)) {
        check_forloop_overflow_error();
      }
      for (int xp{xstart_tmp}; xp <= xend; xp++) {
        r += x.d[xp - 1];
      }
      if (r != 0.0) {
        y.d[outidx - 1] = r;
        outidx++;
      }
      y.colidx[col + 1] = outidx;
    }
    t = y.colidx[y.colidx.size(0) - 1];
    if (t - 1 > 2147483646) {
      check_forloop_overflow_error();
    }
    for (outidx = 0; outidx <= t - 2; outidx++) {
      y.rowidx[outidx] = 1;
    }
    if (x.n < 0) {
      rtNonNegativeError(static_cast<double>(x.n), w_emlrtDCI);
    }
  }
}

void sum(const g_sparse &x, c_sparse &y)
{
  if (x.m == 0) {
    y.colidx.set_size(2);
    y.colidx[0] = 1;
    y.colidx[1] = 1;
    y.d.set_size(1);
    y.d[0] = 0.0;
    y.rowidx.set_size(1);
    y.rowidx[0] = 1;
  } else {
    double r;
    int xend;
    int xstart;
    y.d.set_size(1);
    y.rowidx.set_size(1);
    y.colidx.set_size(2);
    y.colidx[0] = 1;
    y.colidx[1] = 1;
    xstart = x.colidx[0];
    xend = x.colidx[1] - 1;
    r = 0.0;
    if ((x.colidx[0] <= x.colidx[1] - 1) && (x.colidx[1] - 1 > 2147483646)) {
      check_forloop_overflow_error();
    }
    for (int xp{xstart}; xp <= xend; xp++) {
      r += x.d[xp - 1];
    }
    if (r != 0.0) {
      y.d[0] = r;
      y.colidx[1] = 2;
    }
    if (y.colidx[1] - 2 >= 0) {
      y.rowidx[0] = 1;
    }
  }
}

void sum(const ::coder::array<double, 2U> &x, ::coder::array<double, 1U> &y)
{
  array<double, 1U> bsum;
  if ((x.size(0) == 0) || (x.size(1) == 0)) {
    int firstBlockLength;
    y.set_size(x.size(0));
    firstBlockLength = x.size(0);
    for (int xblockoffset{0}; xblockoffset < firstBlockLength; xblockoffset++) {
      y[xblockoffset] = 0.0;
    }
  } else {
    int bvstride;
    int firstBlockLength;
    int lastBlockLength;
    int nblocks;
    int vstride;
    int xoffset;
    vstride = x.size(0);
    bvstride = x.size(0) << 10;
    y.set_size(x.size(0));
    bsum.set_size(x.size(0));
    if (x.size(1) <= 1024) {
      firstBlockLength = x.size(1);
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = static_cast<int>(static_cast<unsigned int>(x.size(1)) >> 10);
      lastBlockLength = x.size(1) - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    if (x.size(0) > 2147483646) {
      check_forloop_overflow_error();
    }
    for (int xj{0}; xj < vstride; xj++) {
      y[xj] = x[xj];
      bsum[xj] = 0.0;
    }
    for (int k{2}; k <= firstBlockLength; k++) {
      xoffset = (k - 1) * vstride;
      if (vstride > 2147483646) {
        check_forloop_overflow_error();
      }
      for (int xj{0}; xj < vstride; xj++) {
        y[xj] = y[xj] + x[xoffset + xj];
      }
    }
    for (int ib{2}; ib <= nblocks; ib++) {
      int xblockoffset;
      xblockoffset = (ib - 1) * bvstride;
      if (vstride > 2147483646) {
        check_forloop_overflow_error();
      }
      for (int xj{0}; xj < vstride; xj++) {
        bsum[xj] = x[xblockoffset + xj];
      }
      if (ib == nblocks) {
        firstBlockLength = lastBlockLength;
      } else {
        firstBlockLength = 1024;
      }
      for (int k{2}; k <= firstBlockLength; k++) {
        xoffset = xblockoffset + (k - 1) * vstride;
        for (int xj{0}; xj < vstride; xj++) {
          bsum[xj] = bsum[xj] + x[xoffset + xj];
        }
      }
      for (int xj{0}; xj < vstride; xj++) {
        y[xj] = y[xj] + bsum[xj];
      }
    }
  }
}

} // namespace coder

// End of code generation (sum.cpp)
