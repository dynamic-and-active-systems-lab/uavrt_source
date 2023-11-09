//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// circshift.cpp
//
// Code generation for function 'circshift'
//

// Include files
#include "circshift.h"
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
void b_circshift(::coder::array<double, 2U> &a)
{
  array<double, 2U> buffer;
  if ((a.size(0) != 0) && (a.size(1) != 0) &&
      ((a.size(0) != 1) || (a.size(1) != 1))) {
    int i;
    int npages;
    int ns;
    int nv;
    int pageroot;
    ns = 1;
    if (a.size(0) <= 1) {
      ns = 0;
    }
    pageroot = static_cast<int>(static_cast<unsigned int>(a.size(0)) >> 1);
    buffer.set_size(1, pageroot);
    for (i = 0; i < pageroot; i++) {
      buffer[i] = 0.0;
    }
    nv = a.size(0);
    npages = a.size(1);
    if ((a.size(0) > 1) && (ns > 0)) {
      if (a.size(1) > 2147483646) {
        check_forloop_overflow_error();
      }
      for (ns = 0; ns < npages; ns++) {
        pageroot = ns * nv;
        buffer[0] = a[pageroot];
        for (int k{0}; k <= nv - 2; k++) {
          i = pageroot + k;
          a[i] = a[i + 1];
        }
        a[(pageroot + nv) - 1] = buffer[0];
      }
    }
  }
}

void c_circshift(::coder::array<double, 2U> &a)
{
  array<double, 2U> buffer;
  if ((a.size(0) != 0) && (a.size(1) != 0) &&
      ((a.size(0) != 1) || (a.size(1) != 1))) {
    int i;
    int npages;
    int ns;
    int nv;
    bool shiftright;
    ns = 1;
    shiftright = true;
    if (a.size(0) <= 1) {
      ns = -1;
    } else if ((a.size(0) >> 1) < 2) {
      ns = a.size(0) - 3;
      shiftright = false;
    }
    nv = static_cast<int>(static_cast<unsigned int>(a.size(0)) >> 1);
    buffer.set_size(1, nv);
    for (i = 0; i < nv; i++) {
      buffer[i] = 0.0;
    }
    nv = a.size(0);
    npages = a.size(1);
    if ((a.size(0) > 1) && (ns + 1 > 0)) {
      if (a.size(1) > 2147483646) {
        check_forloop_overflow_error();
      }
      for (int b_i{0}; b_i < npages; b_i++) {
        int pageroot;
        pageroot = b_i * nv;
        if (shiftright) {
          for (int k{0}; k <= ns; k++) {
            buffer[k] = a[(((pageroot + k) + nv) - ns) - 1];
          }
          i = ns + 2;
          for (int k{nv}; k >= i; k--) {
            int i1;
            i1 = pageroot + k;
            a[i1 - 1] = a[(i1 - ns) - 2];
          }
          for (int k{0}; k <= ns; k++) {
            a[pageroot + k] = buffer[k];
          }
        } else {
          for (int k{0}; k <= ns; k++) {
            buffer[k] = a[pageroot + k];
          }
          i = nv - ns;
          for (int k{0}; k <= i - 2; k++) {
            int i1;
            i1 = pageroot + k;
            a[i1] = a[(i1 + ns) + 1];
          }
          for (int k{0}; k <= ns; k++) {
            a[(((pageroot + k) + nv) - ns) - 1] = buffer[k];
          }
        }
      }
    }
  }
}

void circshift(::coder::array<creal32_T, 2U> &a, double p)
{
  array<creal32_T, 2U> buffer;
  int dim;
  int i;
  bool pok;
  dim = 1;
  if (a.size(0) != 1) {
    dim = 0;
  }
  pok = true;
  if ((static_cast<int>(p) != p) || (p == -2.147483648E+9)) {
    pok = false;
  }
  if (!pok) {
    rtErrorWithMessageID("int32", "int32", qc_emlrtRTEI.fName,
                         qc_emlrtRTEI.lineNo);
  }
  if ((a.size(0) != 0) && (a.size(1) != 0) &&
      ((a.size(0) != 1) || (a.size(1) != 1))) {
    int lowerDim;
    int npages;
    int ns;
    int nv;
    int pageroot;
    int pagesize;
    int stride;
    if (p < 0.0) {
      ns = -static_cast<int>(p);
      pok = false;
    } else {
      ns = static_cast<int>(p);
      pok = true;
    }
    if (a.size(dim) <= 1) {
      ns = 0;
    } else {
      if (ns > a.size(dim)) {
        unsigned int u;
        u = static_cast<unsigned int>(a.size(dim));
        if (u == 0U) {
          rtDivisionByZeroError(uc_emlrtRTEI);
        } else {
          i = static_cast<int>(static_cast<unsigned int>(ns) / u);
        }
        ns -= a.size(dim) * i;
      }
      if (ns > (a.size(dim) >> 1)) {
        ns = a.size(dim) - ns;
        pok = !pok;
      }
    }
    if ((a.size(0) == 0) || (a.size(1) == 0)) {
      pageroot = 0;
    } else {
      lowerDim = a.size(0);
      pageroot = a.size(1);
      if (lowerDim >= pageroot) {
        pageroot = lowerDim;
      }
    }
    lowerDim = pageroot / 2;
    buffer.set_size(1, lowerDim);
    for (i = 0; i < lowerDim; i++) {
      buffer[i].re = 0.0F;
      buffer[i].im = 0.0F;
    }
    i = a.size(dim);
    nv = a.size(dim);
    stride = 1;
    for (int k{0}; k < dim; k++) {
      stride *= a.size(0);
    }
    npages = 1;
    lowerDim = dim + 2;
    for (int k{lowerDim}; k < 3; k++) {
      npages *= a.size(1);
    }
    pagesize = stride * a.size(dim);
    if ((a.size(dim) > 1) && (ns > 0)) {
      if (npages > 2147483646) {
        check_forloop_overflow_error();
      }
      for (int b_i{0}; b_i < npages; b_i++) {
        pageroot = b_i * pagesize;
        if (stride > 2147483646) {
          check_forloop_overflow_error();
        }
        for (int j{0}; j < stride; j++) {
          lowerDim = pageroot + j;
          if (pok) {
            for (int k{0}; k < ns; k++) {
              buffer[k] = a[lowerDim + ((k + i) - ns) * stride];
            }
            dim = ns + 1;
            for (int k{nv}; k >= dim; k--) {
              a[lowerDim + (k - 1) * stride] =
                  a[lowerDim + ((k - ns) - 1) * stride];
            }
            for (int k{0}; k < ns; k++) {
              a[lowerDim + k * stride] = buffer[k];
            }
          } else {
            for (int k{0}; k < ns; k++) {
              buffer[k] = a[lowerDim + k * stride];
            }
            dim = (i - ns) - 1;
            for (int k{0}; k <= dim; k++) {
              a[lowerDim + k * stride] = a[lowerDim + (k + ns) * stride];
            }
            for (int k{0}; k < ns; k++) {
              a[lowerDim + ((k + i) - ns) * stride] = buffer[k];
            }
          }
        }
      }
    }
  }
}

void circshift(::coder::array<creal_T, 2U> &a, double dim)
{
  array<creal_T, 2U> buffer;
  bool overflow;
  if ((a.size(0) != 0) && (a.size(1) != 0) &&
      ((a.size(0) != 1) || (a.size(1) != 1))) {
    int i;
    int lowerDim;
    int npages;
    int ns;
    int pagesize;
    int stride;
    int upperDim;
    if ((!(dim >= 1.0)) || (!(dim == std::floor(dim))) ||
        (!(dim <= 2.147483647E+9))) {
      tc_rtErrorWithMessageID(rc_emlrtRTEI.fName, rc_emlrtRTEI.lineNo);
    }
    ns = 1;
    if (dim <= 2.0) {
      i = a.size(static_cast<int>(dim) - 1);
    } else {
      i = 1;
    }
    if (i <= 1) {
      ns = 0;
    }
    if ((a.size(0) == 0) || (a.size(1) == 0)) {
      lowerDim = 0;
    } else {
      upperDim = a.size(0);
      lowerDim = a.size(1);
      if (upperDim >= lowerDim) {
        lowerDim = upperDim;
      }
    }
    upperDim = lowerDim / 2;
    buffer.set_size(1, upperDim);
    for (i = 0; i < upperDim; i++) {
      buffer[i].re = 0.0;
      buffer[i].im = 0.0;
    }
    if (dim <= 2.0) {
      i = a.size(static_cast<int>(dim) - 1);
      stride = 1;
      upperDim = static_cast<int>(dim);
      for (int k{0}; k <= upperDim - 2; k++) {
        lowerDim = a.size(0);
        stride *= lowerDim;
      }
      npages = 1;
      lowerDim = static_cast<int>(dim) + 1;
      for (int k{lowerDim}; k < 3; k++) {
        npages *= a.size(1);
      }
    } else {
      i = 1;
      stride = a.size(0) * a.size(1);
      npages = 1;
    }
    pagesize = stride * i;
    if ((i > 1) && (ns > 0)) {
      if (npages > 2147483646) {
        check_forloop_overflow_error();
      }
      if (npages - 1 >= 0) {
        overflow = (stride > 2147483646);
      }
      for (ns = 0; ns < npages; ns++) {
        upperDim = ns * pagesize;
        if (overflow) {
          check_forloop_overflow_error();
        }
        for (int j{0}; j < stride; j++) {
          lowerDim = upperDim + j;
          buffer[0] = a[lowerDim];
          for (int k{0}; k <= i - 2; k++) {
            a[lowerDim + k * stride] = a[lowerDim + (k + 1) * stride];
          }
          a[lowerDim + (i - 1) * stride] = buffer[0];
        }
      }
    }
  }
}

void circshift(::coder::array<double, 2U> &a)
{
  array<double, 2U> buffer;
  if ((a.size(0) != 0) && (a.size(1) != 0) &&
      ((a.size(0) != 1) || (a.size(1) != 1))) {
    int i;
    int npages;
    int ns;
    int nv;
    int pageroot;
    ns = 1;
    if (a.size(0) <= 1) {
      ns = 0;
    }
    pageroot = static_cast<int>(static_cast<unsigned int>(a.size(0)) >> 1);
    buffer.set_size(1, pageroot);
    for (i = 0; i < pageroot; i++) {
      buffer[i] = 0.0;
    }
    nv = a.size(0);
    npages = a.size(1);
    if ((a.size(0) > 1) && (ns > 0)) {
      if (a.size(1) > 2147483646) {
        check_forloop_overflow_error();
      }
      for (ns = 0; ns < npages; ns++) {
        pageroot = ns * nv;
        buffer[0] = a[(pageroot + nv) - 1];
        for (int k{nv}; k >= 2; k--) {
          i = pageroot + k;
          a[i - 1] = a[i - 2];
        }
        a[pageroot] = buffer[0];
      }
    }
  }
}

void d_circshift(::coder::array<double, 2U> &a)
{
  array<double, 2U> buffer;
  if ((a.size(0) != 0) && (a.size(1) != 0) &&
      ((a.size(0) != 1) || (a.size(1) != 1))) {
    int i;
    int npages;
    int ns;
    int nv;
    bool shiftright;
    ns = 1;
    shiftright = false;
    if (a.size(0) <= 1) {
      ns = -1;
    } else if ((a.size(0) >> 1) < 2) {
      ns = a.size(0) - 3;
      shiftright = true;
    }
    nv = static_cast<int>(static_cast<unsigned int>(a.size(0)) >> 1);
    buffer.set_size(1, nv);
    for (i = 0; i < nv; i++) {
      buffer[i] = 0.0;
    }
    nv = a.size(0);
    npages = a.size(1);
    if ((a.size(0) > 1) && (ns + 1 > 0)) {
      if (a.size(1) > 2147483646) {
        check_forloop_overflow_error();
      }
      for (int b_i{0}; b_i < npages; b_i++) {
        int pageroot;
        pageroot = b_i * nv;
        if (shiftright) {
          for (int k{0}; k <= ns; k++) {
            buffer[k] = a[(((pageroot + k) + nv) - ns) - 1];
          }
          i = ns + 2;
          for (int k{nv}; k >= i; k--) {
            int i1;
            i1 = pageroot + k;
            a[i1 - 1] = a[(i1 - ns) - 2];
          }
          for (int k{0}; k <= ns; k++) {
            a[pageroot + k] = buffer[k];
          }
        } else {
          for (int k{0}; k <= ns; k++) {
            buffer[k] = a[pageroot + k];
          }
          i = nv - ns;
          for (int k{0}; k <= i - 2; k++) {
            int i1;
            i1 = pageroot + k;
            a[i1] = a[(i1 + ns) + 1];
          }
          for (int k{0}; k <= ns; k++) {
            a[(((pageroot + k) + nv) - ns) - 1] = buffer[k];
          }
        }
      }
    }
  }
}

void e_circshift(::coder::array<double, 2U> &a)
{
  array<double, 2U> buffer;
  if ((a.size(0) != 0) && (a.size(1) != 0) &&
      ((a.size(0) != 1) || (a.size(1) != 1))) {
    int ns;
    int stride;
    int unnamed_idx_1;
    ns = 1;
    if (a.size(1) <= 1) {
      ns = 0;
    }
    unnamed_idx_1 = static_cast<int>(static_cast<unsigned int>(a.size(1)) >> 1);
    buffer.set_size(1, unnamed_idx_1);
    for (stride = 0; stride < unnamed_idx_1; stride++) {
      buffer[stride] = 0.0;
    }
    unnamed_idx_1 = a.size(1);
    stride = a.size(0);
    if ((a.size(1) > 1) && (ns > 0)) {
      if (a.size(0) > 2147483646) {
        check_forloop_overflow_error();
      }
      for (ns = 0; ns < stride; ns++) {
        buffer[0] = a[ns + (unnamed_idx_1 - 1) * stride];
        for (int k{unnamed_idx_1}; k >= 2; k--) {
          a[ns + (k - 1) * stride] = a[ns + (k - 2) * stride];
        }
        a[ns] = buffer[0];
      }
    }
  }
}

void f_circshift(::coder::array<double, 2U> &a)
{
  array<double, 2U> buffer;
  if ((a.size(0) != 0) && (a.size(1) != 0) &&
      ((a.size(0) != 1) || (a.size(1) != 1))) {
    int ns;
    int stride;
    int unnamed_idx_1;
    ns = 1;
    if (a.size(1) <= 1) {
      ns = 0;
    }
    unnamed_idx_1 = static_cast<int>(static_cast<unsigned int>(a.size(1)) >> 1);
    buffer.set_size(1, unnamed_idx_1);
    for (stride = 0; stride < unnamed_idx_1; stride++) {
      buffer[stride] = 0.0;
    }
    unnamed_idx_1 = a.size(1) - 2;
    stride = a.size(0);
    if ((a.size(1) > 1) && (ns > 0)) {
      if (a.size(0) > 2147483646) {
        check_forloop_overflow_error();
      }
      for (ns = 0; ns < stride; ns++) {
        buffer[0] = a[ns];
        for (int k{0}; k <= unnamed_idx_1; k++) {
          a[ns + k * stride] = a[ns + (k + 1) * stride];
        }
        a[ns + (unnamed_idx_1 + 1) * stride] = buffer[0];
      }
    }
  }
}

void g_circshift(::coder::array<bool, 2U> &a)
{
  array<bool, 2U> buffer;
  if ((a.size(0) != 0) && (a.size(1) != 0) &&
      ((a.size(0) != 1) || (a.size(1) != 1))) {
    int ns;
    int stride;
    int unnamed_idx_1;
    ns = 1;
    if (a.size(1) <= 1) {
      ns = 0;
    }
    unnamed_idx_1 = static_cast<int>(static_cast<unsigned int>(a.size(1)) >> 1);
    buffer.set_size(1, unnamed_idx_1);
    for (stride = 0; stride < unnamed_idx_1; stride++) {
      buffer[stride] = false;
    }
    unnamed_idx_1 = a.size(1) - 2;
    stride = a.size(0);
    if ((a.size(1) > 1) && (ns > 0)) {
      if (a.size(0) > 2147483646) {
        check_forloop_overflow_error();
      }
      for (ns = 0; ns < stride; ns++) {
        buffer[0] = a[ns];
        for (int k{0}; k <= unnamed_idx_1; k++) {
          a[ns + k * stride] = a[ns + (k + 1) * stride];
        }
        a[ns + (unnamed_idx_1 + 1) * stride] = buffer[0];
      }
    }
  }
}

} // namespace coder

// End of code generation (circshift.cpp)
