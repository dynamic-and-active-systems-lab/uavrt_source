//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// psdfreqvec.cpp
//
// Code generation for function 'psdfreqvec'
//

// Include files
#include "psdfreqvec.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include <cfloat>
#include <cmath>

// Function Declarations
static double rt_remd_snf(double u0, double u1);

// Function Definitions
static double rt_remd_snf(double u0, double u1)
{
  double y;
  if (std::isnan(u0) || std::isnan(u1) || std::isinf(u0)) {
    y = rtNaN;
  } else if (std::isinf(u1)) {
    y = u0;
  } else if ((u1 != 0.0) && (u1 != std::trunc(u1))) {
    double q;
    q = std::abs(u0 / u1);
    if (!(std::abs(q - std::floor(q + 0.5)) > DBL_EPSILON * q)) {
      y = 0.0 * u0;
    } else {
      y = std::fmod(u0, u1);
    }
  } else {
    y = std::fmod(u0, u1);
  }
  return y;
}

namespace coder {
void psdfreqvec(double varargin_2, double varargin_4,
                ::coder::array<double, 1U> &w)
{
  static rtBoundsCheckInfo cb_emlrtBCI{
      -1,              // iFirst
      -1,              // iLast
      74,              // lineNo
      8,               // colNo
      "",              // aName
      "frequencygrid", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/siglib/psdfreqvec.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo db_emlrtBCI{
      -1,              // iFirst
      -1,              // iLast
      75,              // lineNo
      8,               // colNo
      "",              // aName
      "frequencygrid", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/siglib/psdfreqvec.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo eb_emlrtBCI{
      -1,              // iFirst
      -1,              // iLast
      80,              // lineNo
      4,               // colNo
      "",              // aName
      "frequencygrid", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/siglib/psdfreqvec.m", // pName
      0 // checkKind
  };
  static rtBoundsCheckInfo fb_emlrtBCI{
      -1,              // iFirst
      -1,              // iLast
      78,              // lineNo
      8,               // colNo
      "",              // aName
      "frequencygrid", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/siglib/psdfreqvec.m", // pName
      0 // checkKind
  };
  static rtDoubleCheckInfo w_emlrtDCI{
      74,              // lineNo
      8,               // colNo
      "frequencygrid", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/siglib/psdfreqvec.m", // pName
      1 // checkKind
  };
  static rtDoubleCheckInfo x_emlrtDCI{
      80,              // lineNo
      4,               // colNo
      "frequencygrid", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/siglib/psdfreqvec.m", // pName
      1 // checkKind
  };
  static rtDoubleCheckInfo y_emlrtDCI{
      78,              // lineNo
      8,               // colNo
      "frequencygrid", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/siglib/psdfreqvec.m", // pName
      1 // checkKind
  };
  array<double, 2U> w1;
  double Fs1;
  double Nyq;
  double freq_res;
  double half_res;
  double x;
  int loop_ub;
  bool isNPTSodd;
  if (std::isnan(varargin_4)) {
    Fs1 = 6.2831853071795862;
  } else {
    Fs1 = varargin_4;
  }
  freq_res = Fs1 / varargin_2;
  if (std::isnan(varargin_2 - 1.0)) {
    w1.set_size(1, 1);
    w1[0] = rtNaN;
  } else if (varargin_2 - 1.0 < 0.0) {
    w1.set_size(w1.size(0), 0);
  } else {
    w1.set_size(1, static_cast<int>(varargin_2 - 1.0) + 1);
    loop_ub = static_cast<int>(varargin_2 - 1.0);
    for (int i{0}; i <= loop_ub; i++) {
      w1[i] = i;
    }
  }
  w1.set_size(1, w1.size(1));
  loop_ub = w1.size(1) - 1;
  for (int i{0}; i <= loop_ub; i++) {
    w1[i] = freq_res * w1[i];
  }
  Nyq = Fs1 / 2.0;
  half_res = freq_res / 2.0;
  x = rt_remd_snf(varargin_2, 2.0);
  if (std::isnan(x)) {
    w_rtErrorWithMessageID(jb_emlrtRTEI.fName, jb_emlrtRTEI.lineNo);
  }
  isNPTSodd = (x != 0.0);
  if (isNPTSodd) {
    x = (varargin_2 + 1.0) / 2.0;
  } else {
    x = varargin_2 / 2.0 + 1.0;
  }
  if (std::isnan(rt_remd_snf(x, 2.0))) {
    w_rtErrorWithMessageID(jb_emlrtRTEI.fName, jb_emlrtRTEI.lineNo);
  }
  if (isNPTSodd) {
    if (x != static_cast<int>(std::floor(x))) {
      rtIntegerError(x, w_emlrtDCI);
    }
    if ((static_cast<int>(x) < 1) || (static_cast<int>(x) > w1.size(1))) {
      rtDynamicBoundsError(static_cast<int>(x), 1, w1.size(1), cb_emlrtBCI);
    }
    w1[static_cast<int>(x) - 1] = Nyq - half_res;
    if ((static_cast<int>(static_cast<unsigned int>(x) + 1U) < 1) ||
        (static_cast<int>(static_cast<unsigned int>(x) + 1U) > w1.size(1))) {
      rtDynamicBoundsError(static_cast<int>(static_cast<unsigned int>(x) + 1U),
                           1, w1.size(1), db_emlrtBCI);
    }
    w1[static_cast<int>(static_cast<unsigned int>(x))] = Nyq + half_res;
  } else {
    if (x != static_cast<int>(std::floor(x))) {
      rtIntegerError(x, y_emlrtDCI);
    }
    if ((static_cast<int>(x) < 1) || (static_cast<int>(x) > w1.size(1))) {
      rtDynamicBoundsError(static_cast<int>(x), 1, w1.size(1), fb_emlrtBCI);
    }
    w1[static_cast<int>(x) - 1] = Nyq;
  }
  if (varargin_2 != static_cast<int>(std::floor(varargin_2))) {
    rtIntegerError(varargin_2, x_emlrtDCI);
  }
  if ((static_cast<int>(varargin_2) < 1) ||
      (static_cast<int>(varargin_2) > w1.size(1))) {
    rtDynamicBoundsError(static_cast<int>(varargin_2), 1, w1.size(1),
                         eb_emlrtBCI);
  }
  w1[static_cast<int>(varargin_2) - 1] = Fs1 - freq_res;
  w.set_size(w1.size(1));
  loop_ub = w1.size(1);
  for (int i{0}; i < loop_ub; i++) {
    w[i] = w1[i];
  }
}

} // namespace coder

// End of code generation (psdfreqvec.cpp)
