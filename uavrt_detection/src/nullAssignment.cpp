//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// nullAssignment.cpp
//
// Code generation for function 'nullAssignment'
//

// Include files
#include "nullAssignment.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include <sstream>
#include <stdexcept>
#include <string>

// Function Declarations
static void rc_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
static void rc_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Matrix index is out of range for deletion.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

namespace coder {
namespace internal {
void nullAssignment(::coder::array<char, 2U> &x, int idx)
{
  static rtRunTimeErrorInfo vc_emlrtRTEI{
      85,                // lineNo
      27,                // colNo
      "validate_inputs", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/"
      "nullAssignment.m" // pName
  };
  int nxout;
  bool p;
  p = true;
  if ((idx < 1) || (idx > x.size(1))) {
    p = false;
  }
  if (!p) {
    rc_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
  }
  nxout = x.size(1) - 1;
  for (int k{idx}; k <= nxout; k++) {
    x[k - 1] = x[k];
  }
  if (x.size(1) - 1 < 1) {
    nxout = 0;
  } else {
    nxout = x.size(1) - 1;
  }
  x.set_size(x.size(0), nxout);
}

void nullAssignment(::coder::array<creal_T, 3U> &x,
                    const ::coder::array<int, 2U> &idx)
{
  static rtDoubleCheckInfo w_emlrtDCI{
      451,                       // lineNo
      58,                        // colNo
      "general_null_assignment", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/"
      "nullAssignment.m", // pName
      4                   // checkKind
  };
  static rtRunTimeErrorInfo vc_emlrtRTEI{
      81,                // lineNo
      27,                // colNo
      "validate_inputs", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/"
      "nullAssignment.m" // pName
  };
  static rtRunTimeErrorInfo wc_emlrtRTEI{
      448,                       // lineNo
      1,                         // colNo
      "general_null_assignment", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/"
      "nullAssignment.m" // pName
  };
  array<creal_T, 3U> b_x;
  array<bool, 2U> b;
  int k;
  int loop_ub_tmp;
  int npages;
  int nxout;
  int vlen;
  int vstride;
  bool exitg1;
  bool p;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= idx.size(1) - 1)) {
    if ((idx[k] < 1) || (idx[k] > x.size(1))) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (!p) {
    rc_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
  }
  b_x.set_size(x.size(0), x.size(1), x.size(2));
  loop_ub_tmp = x.size(0) * x.size(1);
  nxout = loop_ub_tmp * x.size(2);
  for (npages = 0; npages < nxout; npages++) {
    b_x[npages] = x[npages];
  }
  vlen = x.size(1);
  b.set_size(1, x.size(1));
  nxout = x.size(1);
  for (npages = 0; npages < nxout; npages++) {
    b[npages] = false;
  }
  nxout = idx.size(1);
  if (idx.size(1) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (k = 0; k < nxout; k++) {
    b[idx[k] - 1] = true;
  }
  npages = 0;
  nxout = b.size(1);
  if (b.size(1) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (k = 0; k < nxout; k++) {
    npages += b[k];
  }
  nxout = x.size(1) - npages;
  if (nxout > x.size(1)) {
    h_rtErrorWithMessageID(wc_emlrtRTEI.fName, wc_emlrtRTEI.lineNo);
  }
  if (nxout < 0) {
    rtNonNegativeError(static_cast<double>(nxout), w_emlrtDCI);
  }
  x.set_size(x.size(0), nxout, x.size(2));
  vstride = b_x.size(0);
  nxout *= b_x.size(0);
  npages = b_x.size(2);
  if (b_x.size(2) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int i{0}; i < npages; i++) {
    int ix0;
    int iy0;
    ix0 = i * loop_ub_tmp;
    iy0 = i * nxout;
    if (vlen > 2147483646) {
      check_forloop_overflow_error();
    }
    for (k = 0; k < vlen; k++) {
      if ((k + 1 > b.size(1)) || (!b[k])) {
        if (vstride > 2147483646) {
          check_forloop_overflow_error();
        }
        for (int j{0}; j < vstride; j++) {
          x[iy0 + j] = b_x[ix0 + j];
        }
        iy0 += vstride;
      }
      ix0 += vstride;
    }
  }
}

} // namespace internal
} // namespace coder

// End of code generation (nullAssignment.cpp)
