//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// tic.cpp
//
// Code generation for function 'tic'
//

// Include files
#include "tic.h"
#include "rt_nonfinite.h"
#include "timeKeeper.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_posix_time.h"
#include <string>

// Function Definitions
namespace coder {
void tic()
{
  coderTimespec b_timespec;
  int status;
  if (!freq_not_empty) {
    freq_not_empty = true;
    status = coderInitTimeFunctions(&freq);
    if (status != 0) {
      rtErrorWithMessageID(std::string(&cv2[0], 22), status, nb_emlrtRTEI.fName,
                           nb_emlrtRTEI.lineNo);
    }
  }
  status = coderTimeClockGettimeMonotonic(&b_timespec, freq);
  if (status != 0) {
    rtErrorWithMessageID(std::string(&cv3[0], 30), status, nb_emlrtRTEI.fName,
                         nb_emlrtRTEI.lineNo);
  }
  internal::b_time::impl::timeKeeper(b_timespec.tv_sec, b_timespec.tv_nsec);
}

} // namespace coder

// End of code generation (tic.cpp)
