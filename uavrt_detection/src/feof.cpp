//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// feof.cpp
//
// Code generation for function 'feof'
//

// Include files
#include "feof.h"
#include "fileManager.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include <cstdio>

// Function Definitions
namespace coder {
double b_feof(double fileID)
{
  std::FILE *f;
  double st;
  bool a;
  f = internal::getfilestar(fileID, a);
  if (f == nullptr) {
    d_rtErrorWithMessageID(d_emlrtRTEI.fName, d_emlrtRTEI.lineNo);
  } else {
    int b_st;
    b_st = std::feof(f);
    st = ((int)b_st != 0);
  }
  return st;
}

} // namespace coder

// End of code generation (feof.cpp)
