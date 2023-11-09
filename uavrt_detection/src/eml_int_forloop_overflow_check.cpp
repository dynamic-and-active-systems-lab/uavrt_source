//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// eml_int_forloop_overflow_check.cpp
//
// Code generation for function 'eml_int_forloop_overflow_check'
//

// Include files
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include <sstream>
#include <stdexcept>
#include <string>

// Function Declarations
static void c_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

// Function Definitions
static void c_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum)
{
  std::stringstream outStream;
  ((outStream << "The loop variable of class ") << r)
      << " might overflow on the last iteration of the for loop. This could "
         "lead to an infinite loop.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

namespace coder {
void check_forloop_overflow_error()
{
  static rtRunTimeErrorInfo vc_emlrtRTEI{
      87,                             // lineNo
      33,                             // colNo
      "check_forloop_overflow_error", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/eml/"
      "eml_int_forloop_overflow_check.m" // pName
  };
  c_rtErrorWithMessageID("int32", vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
}

} // namespace coder

// End of code generation (eml_int_forloop_overflow_check.cpp)
