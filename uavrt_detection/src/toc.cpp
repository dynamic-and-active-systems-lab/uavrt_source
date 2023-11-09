//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// toc.cpp
//
// Code generation for function 'toc'
//

// Include files
#include "toc.h"
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
double toc()
{
  coderTimespec b_timespec;
  double tstart_tv_nsec;
  double tstart_tv_sec;
  int status;
  tstart_tv_sec = internal::b_time::impl::timeKeeper(tstart_tv_nsec);
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
  return (b_timespec.tv_sec - tstart_tv_sec) +
         (b_timespec.tv_nsec - tstart_tv_nsec) / 1.0E+9;
}

} // namespace coder

// End of code generation (toc.cpp)
