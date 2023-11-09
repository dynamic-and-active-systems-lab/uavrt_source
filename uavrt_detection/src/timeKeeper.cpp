//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// timeKeeper.cpp
//
// Code generation for function 'timeKeeper'
//

// Include files
#include "timeKeeper.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_posix_time.h"
#include <sstream>
#include <stdexcept>
#include <string>

// Variable Definitions
static coderTimespec savedTime;

static bool savedTime_not_empty;

// Function Declarations
static void eb_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
static void eb_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "You must call TIC without an output argument before calling "
               "TOC without an input argument.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

namespace coder {
namespace internal {
namespace b_time {
namespace impl {
void timeKeeper(double newTime_tv_sec, double newTime_tv_nsec)
{
  if (!savedTime_not_empty) {
    coderTimespec b_timespec;
    int status;
    if (!freq_not_empty) {
      freq_not_empty = true;
      status = coderInitTimeFunctions(&freq);
      if (status != 0) {
        rtErrorWithMessageID(std::string(&cv2[0], 22), status,
                             nb_emlrtRTEI.fName, nb_emlrtRTEI.lineNo);
      }
    }
    status = coderTimeClockGettimeMonotonic(&b_timespec, freq);
    if (status != 0) {
      rtErrorWithMessageID(std::string(&cv3[0], 30), status, nb_emlrtRTEI.fName,
                           nb_emlrtRTEI.lineNo);
    }
    savedTime_not_empty = true;
  }
  savedTime.tv_sec = newTime_tv_sec;
  savedTime.tv_nsec = newTime_tv_nsec;
}

double timeKeeper(double &outTime_tv_nsec)
{
  static rtRunTimeErrorInfo vc_emlrtRTEI{
      11,           // lineNo
      9,            // colNo
      "timeKeeper", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/shared/coder/coder/lib/+coder/"
      "+internal/+time/+impl/timeKeeper.m" // pName
  };
  double outTime_tv_sec;
  if (!savedTime_not_empty) {
    eb_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
  }
  outTime_tv_sec = savedTime.tv_sec;
  outTime_tv_nsec = savedTime.tv_nsec;
  return outTime_tv_sec;
}

} // namespace impl
} // namespace b_time
} // namespace internal
} // namespace coder
void savedTime_not_empty_init()
{
  savedTime_not_empty = false;
}

// End of code generation (timeKeeper.cpp)
