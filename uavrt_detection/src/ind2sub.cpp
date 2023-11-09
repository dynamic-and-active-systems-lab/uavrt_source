//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// ind2sub.cpp
//
// Code generation for function 'ind2sub'
//

// Include files
#include "ind2sub.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"

// Function Definitions
namespace coder {
int ind2sub_indexClass(const double siz[2], double ndx, int &varargout_2)
{
  int vk;
  if ((static_cast<int>(ndx) < 1) ||
      (static_cast<int>(ndx) >
       static_cast<int>(siz[0]) * static_cast<int>(siz[1]))) {
    cc_rtErrorWithMessageID(ic_emlrtRTEI.fName, ic_emlrtRTEI.lineNo);
  }
  vk = div_s32(static_cast<int>(ndx) - 1, static_cast<int>(siz[0]));
  varargout_2 = vk + 1;
  return static_cast<int>(ndx) - vk * static_cast<int>(siz[0]);
}

int ind2sub_indexClass(const double siz[2], int ndx, int &varargout_2)
{
  int vk;
  if ((ndx < 1) ||
      (ndx > static_cast<int>(siz[0]) * static_cast<int>(siz[1]))) {
    cc_rtErrorWithMessageID(ic_emlrtRTEI.fName, ic_emlrtRTEI.lineNo);
  }
  vk = div_s32(ndx - 1, static_cast<int>(siz[0]));
  varargout_2 = vk + 1;
  return ndx - vk * static_cast<int>(siz[0]);
}

} // namespace coder

// End of code generation (ind2sub.cpp)
