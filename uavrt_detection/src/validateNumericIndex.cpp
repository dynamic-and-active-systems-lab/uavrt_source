//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// validateNumericIndex.cpp
//
// Code generation for function 'validateNumericIndex'
//

// Include files
#include "validateNumericIndex.h"
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
void sparse_validateNumericIndex(int upperBound,
                                 const ::coder::array<double, 2U> &idx)
{
  int i;
  i = idx.size(1);
  for (int k{0}; k < i; k++) {
    double d;
    double d1;
    d = idx[k];
    d1 = std::floor(d);
    if ((!(d1 == d)) || std::isinf(d) || (!(d > 0.0))) {
      hc_rtErrorWithMessageID(nc_emlrtRTEI.fName, nc_emlrtRTEI.lineNo);
    }
    if (!(d <= upperBound)) {
      rtErrorWithMessageID(static_cast<int>(d1), upperBound, jc_emlrtRTEI.fName,
                           jc_emlrtRTEI.lineNo);
    }
  }
}

} // namespace coder

// End of code generation (validateNumericIndex.cpp)
