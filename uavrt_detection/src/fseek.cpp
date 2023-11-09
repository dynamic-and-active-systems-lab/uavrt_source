//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// fseek.cpp
//
// Code generation for function 'fseek'
//

// Include files
#include "fseek.h"
#include "fileManager.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include <cmath>
#include <cstdio>

// Function Definitions
namespace coder {
void b_fseek(double fileID, double offset)
{
  int wherefrom;
  std::FILE *f;
  std::FILE *filestar;
  bool a;
  wherefrom = SEEK_SET;
  if ((!std::isinf(offset)) && (!std::isnan(offset)) &&
      (std::floor(offset) == offset)) {
    f = internal::getfilestar(fileID, a);
    filestar = f;
    if (f == nullptr) {
      d_rtErrorWithMessageID(c_emlrtRTEI.fName, c_emlrtRTEI.lineNo);
    }
    if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
      filestar = nullptr;
    }
    if (!(filestar == nullptr)) {
      std::fseek(filestar, (long int)offset, wherefrom);
    }
  }
}

} // namespace coder

// End of code generation (fseek.cpp)
