//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// getLocalTime.h
//
// Code generation for function 'getLocalTime'
//

#ifndef GETLOCALTIME_H
#define GETLOCALTIME_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace b_time {
double getLocalTime(double &t_tm_sec, double &t_tm_min, double &t_tm_hour,
                    double &t_tm_mday, double &t_tm_mon, double &t_tm_year,
                    bool &t_tm_isdst);

}
} // namespace internal
} // namespace coder

#endif
// End of code generation (getLocalTime.h)
