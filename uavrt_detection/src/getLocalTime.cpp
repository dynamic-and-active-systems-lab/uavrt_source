//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// getLocalTime.cpp
//
// Code generation for function 'getLocalTime'
//

// Include files
#include "getLocalTime.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_posix_time.h"
#include <string>

// Function Definitions
namespace coder {
namespace internal {
namespace b_time {
double getLocalTime(double &t_tm_sec, double &t_tm_min, double &t_tm_hour,
                    double &t_tm_mday, double &t_tm_mon, double &t_tm_year,
                    bool &t_tm_isdst)
{
  static const char fcn[14]{'c', 'o', 'd', 'e', 'r', 'L', 'o',
                            'c', 'a', 'l', 'T', 'i', 'm', 'e'};
  coderTm structTm;
  double t_tm_nsec;
  int status;
  status = coderLocalTime(&structTm);
  if (status != 0) {
    rtErrorWithMessageID(std::string(&fcn[0], 14), status, nb_emlrtRTEI.fName,
                         nb_emlrtRTEI.lineNo);
  }
  t_tm_nsec = (double)structTm.tm_nsec;
  t_tm_sec = structTm.tm_sec;
  t_tm_min = structTm.tm_min;
  t_tm_hour = structTm.tm_hour;
  t_tm_mday = structTm.tm_mday;
  t_tm_mon = structTm.tm_mon;
  t_tm_year = structTm.tm_year;
  t_tm_isdst = (structTm.tm_isdst != 0);
  return t_tm_nsec;
}

} // namespace b_time
} // namespace internal
} // namespace coder

// End of code generation (getLocalTime.cpp)
