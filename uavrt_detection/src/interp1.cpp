//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// interp1.cpp
//
// Code generation for function 'interp1'
//

// Include files
#include "interp1.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <string>

// Variable Definitions
static rtRunTimeErrorInfo
    wb_emlrtRTEI{
        166,            // lineNo
        13,             // colNo
        "interp1_work", // fName
        "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/polyfun/"
        "interp1.m" // pName
    };

static rtRunTimeErrorInfo
    xb_emlrtRTEI{
        208,            // lineNo
        13,             // colNo
        "interp1_work", // fName
        "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/polyfun/"
        "interp1.m" // pName
    };

// Function Declarations
static void hb_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void ib_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void wb_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void xb_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
static void hb_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "NaN is not an appropriate value for X.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

static void ib_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "The data abscissae must be distinct and strictly monotonic.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

static void wb_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Y must have length(X) rows.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

static void xb_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "A minimum of two data points is required.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

namespace coder {
void interp1(const double varargin_1[2], const double varargin_2[2],
             const ::coder::array<double, 2U> &varargin_3,
             ::coder::array<double, 2U> &Vq)
{
  double x_idx_0;
  double x_idx_1;
  double y_idx_0;
  double y_idx_1;
  int k;
  int nxi;
  bool b;
  y_idx_0 = varargin_2[0];
  x_idx_0 = varargin_1[0];
  y_idx_1 = varargin_2[1];
  x_idx_1 = varargin_1[1];
  Vq.set_size(1, varargin_3.size(1));
  nxi = varargin_3.size(1);
  for (k = 0; k < nxi; k++) {
    Vq[k] = rtNaN;
  }
  b = (varargin_3.size(1) == 0);
  if (!b) {
    k = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (k < 2) {
        if (std::isnan(varargin_1[k])) {
          hb_rtErrorWithMessageID(wb_emlrtRTEI.fName, wb_emlrtRTEI.lineNo);
        } else {
          k++;
        }
      } else {
        if (varargin_1[1] < varargin_1[0]) {
          x_idx_0 = varargin_1[1];
          x_idx_1 = varargin_1[0];
          y_idx_0 = varargin_2[1];
          y_idx_1 = varargin_2[0];
        }
        if (x_idx_1 <= x_idx_0) {
          ib_rtErrorWithMessageID(xb_emlrtRTEI.fName, xb_emlrtRTEI.lineNo);
        }
        nxi = varargin_3.size(1);
        if (varargin_3.size(1) > 2147483646) {
          check_forloop_overflow_error();
        }
        for (k = 0; k < nxi; k++) {
          double r;
          r = varargin_3[k];
          if (std::isnan(r)) {
            Vq[k] = rtNaN;
          } else if ((!(r > x_idx_1)) && (!(r < x_idx_0))) {
            r = (r - x_idx_0) / (x_idx_1 - x_idx_0);
            if (r == 0.0) {
              Vq[k] = y_idx_0;
            } else if (r == 1.0) {
              Vq[k] = y_idx_1;
            } else if (y_idx_0 == y_idx_1) {
              Vq[k] = y_idx_0;
            } else {
              Vq[k] = (1.0 - r) * y_idx_0 + r * y_idx_1;
            }
          }
        }
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
}

void interp1(const ::coder::array<double, 1U> &varargin_1,
             const ::coder::array<double, 1U> &varargin_2,
             const ::coder::array<double, 1U> &varargin_3,
             ::coder::array<double, 1U> &Vq)
{
  static rtRunTimeErrorInfo
      vc_emlrtRTEI{
          155,            // lineNo
          15,             // colNo
          "interp1_work", // fName
          "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/polyfun/"
          "interp1.m" // pName
      };
  static rtRunTimeErrorInfo
      wc_emlrtRTEI{
          139,            // lineNo
          23,             // colNo
          "interp1_work", // fName
          "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/polyfun/"
          "interp1.m" // pName
      };
  array<double, 1U> x;
  array<double, 1U> y;
  int low_i;
  int n;
  int nx;
  int nyrows;
  y.set_size(varargin_2.size(0));
  n = varargin_2.size(0);
  for (low_i = 0; low_i < n; low_i++) {
    y[low_i] = varargin_2[low_i];
  }
  x.set_size(varargin_1.size(0));
  n = varargin_1.size(0);
  for (low_i = 0; low_i < n; low_i++) {
    x[low_i] = varargin_1[low_i];
  }
  nyrows = varargin_2.size(0);
  nx = varargin_1.size(0);
  if (varargin_1.size(0) != varargin_2.size(0)) {
    wb_rtErrorWithMessageID(wc_emlrtRTEI.fName, wc_emlrtRTEI.lineNo);
  }
  if (varargin_1.size(0) <= 1) {
    xb_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
  }
  Vq.set_size(varargin_3.size(0));
  n = varargin_3.size(0);
  for (low_i = 0; low_i < n; low_i++) {
    Vq[low_i] = 0.0;
  }
  if (varargin_3.size(0) != 0) {
    int k;
    if (nx > 2147483646) {
      check_forloop_overflow_error();
    }
    k = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (k <= nx - 1) {
        if (std::isnan(varargin_1[k])) {
          hb_rtErrorWithMessageID(wb_emlrtRTEI.fName, wb_emlrtRTEI.lineNo);
        } else {
          k++;
        }
      } else {
        double maxx;
        double minx;
        double xtmp;
        int nd2;
        if (varargin_1[1] < varargin_1[0]) {
          low_i = nx >> 1;
          for (nd2 = 0; nd2 < low_i; nd2++) {
            xtmp = x[nd2];
            n = (nx - nd2) - 1;
            x[nd2] = x[n];
            x[n] = xtmp;
          }
          if (varargin_2.size(0) > 1) {
            n = varargin_2.size(0) - 1;
            nd2 = varargin_2.size(0) >> 1;
            for (k = 0; k < nd2; k++) {
              xtmp = y[k];
              low_i = n - k;
              y[k] = y[low_i];
              y[low_i] = xtmp;
            }
          }
        }
        for (k = 2; k <= nx; k++) {
          if (x[k - 1] <= x[k - 2]) {
            ib_rtErrorWithMessageID(xb_emlrtRTEI.fName, xb_emlrtRTEI.lineNo);
          }
        }
        minx = x[0];
        maxx = x[x.size(0) - 1];
        n = varargin_3.size(0);
        if (varargin_3.size(0) > 2147483646) {
          check_forloop_overflow_error();
        }
        for (k = 0; k < n; k++) {
          if (std::isnan(varargin_3[k])) {
            Vq[k] = rtNaN;
          } else if (varargin_3[k] > maxx) {
            if (nyrows > 1) {
              double Vq_tmp;
              Vq_tmp = y[nyrows - 1];
              Vq[k] = Vq_tmp + (varargin_3[k] - maxx) /
                                   (maxx - x[x.size(0) - 2]) *
                                   (Vq_tmp - y[nyrows - 2]);
            }
          } else if (varargin_3[k] < minx) {
            Vq[k] =
                y[0] + (varargin_3[k] - minx) / (x[1] - minx) * (y[1] - y[0]);
          } else {
            nd2 = x.size(0);
            low_i = 1;
            nx = 2;
            while (nd2 > nx) {
              int mid_i;
              mid_i = (low_i >> 1) + (nd2 >> 1);
              if (((low_i & 1) == 1) && ((nd2 & 1) == 1)) {
                mid_i++;
              }
              if (varargin_3[k] >= x[mid_i - 1]) {
                low_i = mid_i;
                nx = mid_i + 1;
              } else {
                nd2 = mid_i;
              }
            }
            xtmp = x[low_i - 1];
            xtmp = (varargin_3[k] - xtmp) / (x[low_i] - xtmp);
            if (xtmp == 0.0) {
              Vq[k] = y[low_i - 1];
            } else if (xtmp == 1.0) {
              Vq[k] = y[low_i];
            } else {
              double Vq_tmp;
              Vq_tmp = y[low_i - 1];
              if (Vq_tmp == y[low_i]) {
                Vq[k] = Vq_tmp;
              } else {
                Vq[k] = (1.0 - xtmp) * Vq_tmp + xtmp * y[low_i];
              }
            }
          }
        }
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
}

} // namespace coder

// End of code generation (interp1.cpp)
