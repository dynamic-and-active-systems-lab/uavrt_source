//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// fwrite.cpp
//
// Code generation for function 'fwrite'
//

// Include files
#include "fwrite.h"
#include "fileManager.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdio>

// Function Definitions
namespace coder {
double b_fwrite(double fileID, const ::coder::array<float, 1U> &x)
{
  static rtRunTimeErrorInfo
      vc_emlrtRTEI{
          33,       // lineNo
          5,        // colNo
          "fwrite", // fName
          "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/iofun/"
          "fwrite.m" // pName
      };
  static rtRunTimeErrorInfo
      wc_emlrtRTEI{
          163,           // lineNo
          5,             // colNo
          "getFileStar", // fName
          "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/iofun/"
          "fwrite.m" // pName
      };
  std::FILE *f;
  std::FILE *filestar;
  double count;
  bool autoflush;
  if (!(fileID != 0.0)) {
    f_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
  }
  f = internal::getfilestar(fileID, autoflush);
  filestar = f;
  if (f == nullptr) {
    d_rtErrorWithMessageID(wc_emlrtRTEI.fName, wc_emlrtRTEI.lineNo);
  }
  if ((filestar == nullptr) || (x.size(0) == 0)) {
    count = 0.0;
  } else {
    size_t bytesOutSizet;
    bytesOutSizet = std::fwrite(&(((::coder::array<float, 1U> *)&x)->data())[0],
                                sizeof(float), (size_t)x.size(0), filestar);
    count = (double)bytesOutSizet;
    if (((double)bytesOutSizet > 0.0) && autoflush) {
      int status;
      status = std::fflush(filestar);
      if (status != 0) {
        count = 0.0;
      }
    }
  }
  return count;
}

} // namespace coder

// End of code generation (fwrite.cpp)
