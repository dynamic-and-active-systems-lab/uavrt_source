//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// ftell.cpp
//
// Code generation for function 'ftell'
//

// Include files
#include "ftell.h"
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
double b_ftell(double fileID)
{
  std::FILE *f;
  std::FILE *filestar;
  double position;
  bool a;
  f = internal::getfilestar(fileID, a);
  filestar = f;
  if (f == nullptr) {
    d_rtErrorWithMessageID(c_emlrtRTEI.fName, c_emlrtRTEI.lineNo);
  }
  if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
    filestar = nullptr;
  }
  if (filestar == nullptr) {
    position = -1.0;
  } else {
    long position_t;
    position_t = std::ftell(filestar);
    position = (double)position_t;
  }
  return position;
}

} // namespace coder

// End of code generation (ftell.cpp)
