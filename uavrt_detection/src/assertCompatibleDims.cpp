//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// assertCompatibleDims.cpp
//
// Code generation for function 'assertCompatibleDims'
//

// Include files
#include "assertCompatibleDims.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
namespace internal {
void assertCompatibleDims(const ::coder::array<double, 2U> &x,
                          const ::coder::array<double, 2U> &y)
{
  if (((x.size(0) != 1) && (y.size(0) != 1) && (x.size(0) != y.size(0))) ||
      ((x.size(1) != 1) && (y.size(1) != 1) && (x.size(1) != y.size(1)))) {
    ab_rtErrorWithMessageID(mb_emlrtRTEI.fName, mb_emlrtRTEI.lineNo);
  }
}

} // namespace internal
} // namespace coder

// End of code generation (assertCompatibleDims.cpp)
