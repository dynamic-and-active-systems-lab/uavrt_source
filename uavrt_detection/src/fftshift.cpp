//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// fftshift.cpp
//
// Code generation for function 'fftshift'
//

// Include files
#include "fftshift.h"
#include "eml_int_forloop_overflow_check.h"
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
void fftshift(::coder::array<creal_T, 2U> &x, double dim)
{
  if ((!(dim >= 1.0)) || (!(dim == std::floor(dim))) ||
      (!(dim <= 2.147483647E+9))) {
    tc_rtErrorWithMessageID(rc_emlrtRTEI.fName, rc_emlrtRTEI.lineNo);
  }
  if (!(dim > 2.0)) {
    int a;
    a = x.size(static_cast<int>(dim) - 1);
    if (a > 1) {
      int i;
      int midoffset;
      int npages;
      int upperDim;
      int vlend2;
      int vspread;
      int vstride;
      vlend2 = a / 2;
      vstride = 1;
      upperDim = static_cast<int>(dim);
      for (int k{0}; k <= upperDim - 2; k++) {
        i = x.size(0);
        vstride *= i;
      }
      npages = 1;
      upperDim = static_cast<int>(dim) + 1;
      for (int k{upperDim}; k < 3; k++) {
        npages *= x.size(1);
      }
      vspread = (a - 1) * vstride;
      midoffset = vlend2 * vstride - 1;
      if (vlend2 << 1 == a) {
        int i2;
        i2 = 0;
        if (npages > 2147483646) {
          check_forloop_overflow_error();
        }
        for (int b_i{0}; b_i < npages; b_i++) {
          int i1;
          i1 = i2;
          i2 += vspread;
          if (vstride > 2147483646) {
            check_forloop_overflow_error();
          }
          for (int j{0}; j < vstride; j++) {
            int ib;
            i1++;
            i2++;
            ib = i1 + midoffset;
            for (int k{0}; k < vlend2; k++) {
              double xtmp_im;
              double xtmp_re;
              upperDim = k * vstride;
              a = (i1 + upperDim) - 1;
              xtmp_re = x[a].re;
              xtmp_im = x[a].im;
              x[(i1 + upperDim) - 1] = x[ib + upperDim];
              i = ib + upperDim;
              x[i].re = xtmp_re;
              x[i].im = xtmp_im;
            }
          }
        }
      } else {
        int i2;
        i2 = 0;
        if (npages > 2147483646) {
          check_forloop_overflow_error();
        }
        for (int b_i{0}; b_i < npages; b_i++) {
          int i1;
          i1 = i2;
          i2 += vspread;
          if (vstride > 2147483646) {
            check_forloop_overflow_error();
          }
          for (int j{0}; j < vstride; j++) {
            double xtmp_im;
            double xtmp_re;
            int ib;
            i1++;
            i2++;
            ib = i1 + midoffset;
            xtmp_re = x[ib].re;
            xtmp_im = x[ib].im;
            for (int k{0}; k < vlend2; k++) {
              upperDim = ib + vstride;
              i = (i1 + k * vstride) - 1;
              x[ib] = x[i];
              x[i] = x[upperDim];
              ib = upperDim;
            }
            x[ib].re = xtmp_re;
            x[ib].im = xtmp_im;
          }
        }
      }
    }
  }
}

} // namespace coder

// End of code generation (fftshift.cpp)
