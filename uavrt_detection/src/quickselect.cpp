//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// quickselect.cpp
//
// Code generation for function 'quickselect'
//

// Include files
#include "quickselect.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"

// Function Declarations
namespace coder {
namespace internal {
static int thirdOfFive(const ::coder::array<double, 1U> &v, int ia, int ib);

}
} // namespace coder

// Function Definitions
namespace coder {
namespace internal {
static int thirdOfFive(const ::coder::array<double, 1U> &v, int ia, int ib)
{
  int im;
  if ((ia == ib) || (ia + 1 == ib)) {
    im = ia;
  } else if ((ia + 2 == ib) || (ia + 3 == ib)) {
    double v4;
    v4 = v[ia - 1];
    if (v4 < v[ia]) {
      double v5;
      v5 = v[ia + 1];
      if (v[ia] < v5) {
        im = ia + 1;
      } else if (v4 < v5) {
        im = ia + 2;
      } else {
        im = ia;
      }
    } else {
      double v5;
      v5 = v[ia + 1];
      if (v4 < v5) {
        im = ia;
      } else if (v[ia] < v5) {
        im = ia + 2;
      } else {
        im = ia + 1;
      }
    }
  } else {
    double v4;
    double v5;
    int j2;
    int j3;
    int j4;
    int j5;
    v4 = v[ia - 1];
    if (v4 < v[ia]) {
      v5 = v[ia + 1];
      if (v[ia] < v5) {
        im = ia;
        j2 = ia;
        j3 = ia + 2;
      } else if (v4 < v5) {
        im = ia;
        j2 = ia + 1;
        j3 = ia + 1;
      } else {
        im = ia + 2;
        j2 = ia - 1;
        j3 = ia + 1;
      }
    } else {
      v5 = v[ia + 1];
      if (v4 < v5) {
        im = ia + 1;
        j2 = ia - 1;
        j3 = ia + 2;
      } else if (v[ia] < v5) {
        im = ia + 1;
        j2 = ia + 1;
        j3 = ia;
      } else {
        im = ia + 2;
        j2 = ia;
        j3 = ia;
      }
    }
    j4 = ia;
    j5 = ia + 1;
    v4 = v[ia + 2];
    v5 = v[ia + 3];
    if (v5 < v4) {
      j4 = ia + 1;
      j5 = ia;
      v5 = v4;
      v4 = v[ia + 3];
    }
    if (!(v5 < v[im - 1])) {
      if (v5 < v[j2]) {
        im = j5 + 3;
      } else if (v4 < v[j2]) {
        im = j2 + 1;
      } else if (v4 < v[j3 - 1]) {
        im = j4 + 3;
      } else {
        im = j3;
      }
    }
  }
  return im;
}

double quickselect(::coder::array<double, 1U> &v, int n, int vlen, int &nfirst,
                   int &nlast)
{
  double vn;
  if ((n < 1) || (n > vlen)) {
    vn = rtNaN;
    nfirst = 0;
    nlast = 0;
  } else {
    int ia;
    int ib;
    int ilast;
    int ipiv;
    int oldnv;
    bool checkspeed;
    bool exitg1;
    bool isslow;
    ipiv = n;
    ia = 1;
    ib = vlen - 1;
    nfirst = 1;
    ilast = vlen - 1;
    oldnv = vlen;
    checkspeed = false;
    isslow = false;
    exitg1 = false;
    while ((!exitg1) && (ia < ib + 1)) {
      double vk_tmp;
      double vref;
      bool guard1{false};
      vref = v[ipiv - 1];
      v[ipiv - 1] = v[ib];
      v[ib] = vref;
      ilast = ia - 1;
      ipiv = -1;
      for (int k{ia}; k <= ib; k++) {
        vk_tmp = v[k - 1];
        if (vk_tmp == vref) {
          v[k - 1] = v[ilast];
          v[ilast] = vk_tmp;
          ipiv++;
          ilast++;
        } else if (vk_tmp < vref) {
          v[k - 1] = v[ilast];
          v[ilast] = vk_tmp;
          ilast++;
        }
      }
      v[ib] = v[ilast];
      v[ilast] = vref;
      guard1 = false;
      if (n <= ilast + 1) {
        nfirst = ilast - ipiv;
        if (n >= nfirst) {
          exitg1 = true;
        } else {
          ib = ilast - 1;
          guard1 = true;
        }
      } else {
        ia = ilast + 2;
        guard1 = true;
      }
      if (guard1) {
        int c;
        c = (ib - ia) + 2;
        if (checkspeed) {
          isslow = (c > oldnv / 2);
          oldnv = c;
        }
        checkspeed = !checkspeed;
        if (isslow) {
          while (c > 1) {
            int ngroupsof5;
            ngroupsof5 = c / 5;
            nlast = c - ngroupsof5 * 5;
            c = ngroupsof5;
            for (int k{0}; k < ngroupsof5; k++) {
              ipiv = ia + k * 5;
              ipiv = thirdOfFive(v, ipiv, ipiv + 4) - 1;
              ilast = (ia + k) - 1;
              vref = v[ilast];
              v[ilast] = v[ipiv];
              v[ipiv] = vref;
            }
            if (nlast > 0) {
              ipiv = ia + ngroupsof5 * 5;
              ipiv = thirdOfFive(v, ipiv, (ipiv + nlast) - 1) - 1;
              ilast = (ia + ngroupsof5) - 1;
              vref = v[ilast];
              v[ilast] = v[ipiv];
              v[ipiv] = vref;
              c = ngroupsof5 + 1;
            }
          }
        } else if (c >= 3) {
          ipiv = ia + static_cast<int>(static_cast<unsigned int>(c - 1) >> 1);
          vref = v[ipiv - 1];
          vk_tmp = v[ia - 1];
          if (vk_tmp < vref) {
            if (!(vref < v[ib])) {
              if (vk_tmp < v[ib]) {
                ipiv = ib + 1;
              } else {
                ipiv = ia;
              }
            }
          } else if (vk_tmp < v[ib]) {
            ipiv = ia;
          } else if (vref < v[ib]) {
            ipiv = ib + 1;
          }
          if (ipiv > ia) {
            v[ia - 1] = v[ipiv - 1];
            v[ipiv - 1] = vk_tmp;
          }
        }
        ipiv = ia;
        nfirst = ia;
        ilast = ib;
      }
    }
    vn = v[ilast];
    nlast = ilast + 1;
  }
  return vn;
}

} // namespace internal
} // namespace coder

// End of code generation (quickselect.cpp)
