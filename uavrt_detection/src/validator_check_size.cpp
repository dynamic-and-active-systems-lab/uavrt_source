//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// validator_check_size.cpp
//
// Code generation for function 'validator_check_size'
//

// Include files
#include "validator_check_size.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_internal_types.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include <sstream>
#include <stdexcept>
#include <string>

// Variable Definitions
static rtRunTimeErrorInfo l_emlrtRTEI{
    218,               // lineNo
    32,                // colNo
    "expandOrReshape", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/"
    "validator_check_size.m" // pName
};

// Function Declarations
static void i_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void m_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
static void i_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream
      << "Number of elements must not change. Use [] as one of the size inputs "
         "to automatically calculate the appropriate size for that di"
         "mension.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

static void m_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Value must be a vector.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

namespace coder {
namespace internal {
bool b_validator_check_size(const ::coder::array<bool, 1U> &in)
{
  bool out;
  if (in.size(0) != 1) {
    rtErrorWithMessageID(in.size(0), 1, 1, k_emlrtRTEI.fName,
                         k_emlrtRTEI.lineNo);
  } else {
    out = in[0];
  }
  return out;
}

void validator_check_size(const ::coder::array<double, 2U> &in,
                          ::coder::array<double, 2U> &out)
{
  int sizes_idx_0;
  bool isequal_the_empty_in;
  bool isscalar_in;
  isscalar_in = ((in.size(0) == 1) && (in.size(1) == 1));
  if ((in.size(0) == 0) && (in.size(1) == 0)) {
    isequal_the_empty_in = true;
    if (in.size(1) != 2) {
      sizes_idx_0 = 0;
    } else {
      sizes_idx_0 = in.size(0);
    }
  } else {
    isequal_the_empty_in = false;
    sizes_idx_0 = in.size(0);
  }
  if ((!isscalar_in) && (!isequal_the_empty_in)) {
    isequal_the_empty_in = (in.size(0) == sizes_idx_0);
    if (!isequal_the_empty_in) {
      rtErrorWithMessageID(in.size(0), sizes_idx_0, 1, k_emlrtRTEI.fName,
                           k_emlrtRTEI.lineNo);
    }
    if (in.size(1) != 2) {
      rtErrorWithMessageID(in.size(1), 2, 2, k_emlrtRTEI.fName,
                           k_emlrtRTEI.lineNo);
    }
  }
  if (isscalar_in) {
    int maxdimlen;
    unsigned int u;
    if (sizes_idx_0 <= 0) {
      u = 0U;
    } else {
      u = static_cast<unsigned int>(sizes_idx_0);
    }
    if ((u << 1) > 2147483647U) {
      l_rtErrorWithMessageID(o_emlrtRTEI.fName, o_emlrtRTEI.lineNo);
    }
    out.set_size(sizes_idx_0, 2);
    maxdimlen = sizes_idx_0 << 1;
    for (sizes_idx_0 = 0; sizes_idx_0 < maxdimlen; sizes_idx_0++) {
      out[sizes_idx_0] = in[0];
    }
  } else if ((in.size(0) == 0) || (in.size(1) == 0)) {
    if (sizes_idx_0 != 0) {
      i_rtErrorWithMessageID(l_emlrtRTEI.fName, l_emlrtRTEI.lineNo);
    }
    out.set_size(0, 2);
  } else {
    int maxdimlen;
    int nx;
    nx = in.size(0) * in.size(1);
    maxdimlen = in.size(0);
    if (in.size(1) > in.size(0)) {
      maxdimlen = in.size(1);
    }
    if (nx >= maxdimlen) {
      maxdimlen = nx;
    }
    if (sizes_idx_0 > maxdimlen) {
      j_rtErrorWithMessageID(m_emlrtRTEI.fName, m_emlrtRTEI.lineNo);
    }
    if (maxdimlen < 2) {
      j_rtErrorWithMessageID(m_emlrtRTEI.fName, m_emlrtRTEI.lineNo);
    }
    maxdimlen = sizes_idx_0 << 1;
    if (maxdimlen != nx) {
      k_rtErrorWithMessageID(n_emlrtRTEI.fName, n_emlrtRTEI.lineNo);
    }
    out.set_size(sizes_idx_0, 2);
    for (sizes_idx_0 = 0; sizes_idx_0 < maxdimlen; sizes_idx_0++) {
      out[sizes_idx_0] = in[sizes_idx_0];
    }
  }
}

void validator_check_size(const ::coder::array<c_struct_T, 2U> &in,
                          ::coder::array<c_struct_T, 2U> &out)
{
  static rtRunTimeErrorInfo vc_emlrtRTEI{
      276,                                          // lineNo
      5,                                            // colNo
      "getExclusiveNonSingletonDimSizeOr1IfScalar", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/"
      "validator_check_size.m" // pName
  };
  int inVectorLength;
  bool hitNotSingletonDim;
  bool isequal_the_empty_in;
  bool isscalar_in;
  bool szNot1;
  isscalar_in = ((in.size(0) == 1) && (in.size(1) == 1));
  if ((in.size(0) == 0) && (in.size(1) == 0)) {
    isequal_the_empty_in = true;
  } else {
    isequal_the_empty_in = false;
  }
  if ((!isscalar_in) && (!isequal_the_empty_in)) {
    isequal_the_empty_in = true;
  } else {
    isequal_the_empty_in = false;
  }
  inVectorLength = 1;
  if (in.size(0) != 1) {
    hitNotSingletonDim = true;
    inVectorLength = in.size(0);
  } else {
    hitNotSingletonDim = false;
  }
  szNot1 = (in.size(1) != 1);
  if (isequal_the_empty_in && hitNotSingletonDim && szNot1) {
    m_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
  }
  if (szNot1) {
    inVectorLength = in.size(1);
  }
  if (isscalar_in) {
    out.set_size(1, inVectorLength);
    for (int nx{0}; nx < inVectorLength; nx++) {
      out[nx] = in[0];
    }
  } else if ((in.size(0) == 0) || (in.size(1) == 0)) {
    if (inVectorLength != 0) {
      i_rtErrorWithMessageID(l_emlrtRTEI.fName, l_emlrtRTEI.lineNo);
    }
    out.set_size(1, 0);
  } else {
    int n;
    int nx;
    nx = in.size(0) * in.size(1);
    n = in.size(0);
    if (in.size(1) > in.size(0)) {
      n = in.size(1);
    }
    if (nx >= n) {
      n = nx;
    }
    if (inVectorLength > n) {
      j_rtErrorWithMessageID(m_emlrtRTEI.fName, m_emlrtRTEI.lineNo);
    }
    if (inVectorLength != nx) {
      k_rtErrorWithMessageID(n_emlrtRTEI.fName, n_emlrtRTEI.lineNo);
    }
    out.set_size(1, inVectorLength);
    for (nx = 0; nx < inVectorLength; nx++) {
      out[nx] = in[nx];
    }
  }
}

} // namespace internal
} // namespace coder

// End of code generation (validator_check_size.cpp)
