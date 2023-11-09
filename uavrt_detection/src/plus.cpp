//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// plus.cpp
//
// Code generation for function 'plus'
//

// Include files
#include "plus.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include <cmath>

// Function Definitions
namespace coder {
namespace matlab {
namespace internal {
namespace coder {
namespace doubledouble {
creal_T c_plus(const creal_T a, double b)
{
  creal_T c;
  double ahi;
  double b_slo;
  double bb;
  double shi_tmp;
  double slo;
  shi_tmp = a.re + b;
  bb = shi_tmp - a.re;
  slo = (a.re - (shi_tmp - bb)) + (b - bb);
  if (std::isnan(slo)) {
    slo = 0.0;
  }
  bb = a.im - a.im;
  b_slo = (a.im - (a.im - bb)) + (0.0 - bb);
  if (std::isnan(b_slo)) {
    b_slo = 0.0;
  }
  ahi = shi_tmp;
  if (a.im != 0.0) {
    slo += a.im;
    ahi = shi_tmp + slo;
    slo -= ahi - shi_tmp;
  }
  if (std::isnan(slo)) {
    slo = 0.0;
  }
  bb = ahi;
  if (b_slo != 0.0) {
    slo += b_slo;
    bb = ahi + slo;
    slo -= bb - ahi;
  }
  if (std::isnan(slo)) {
    slo = 0.0;
  }
  c.re = bb;
  c.im = slo;
  return c;
}

} // namespace doubledouble
} // namespace coder
} // namespace internal
} // namespace matlab
} // namespace coder

// End of code generation (plus.cpp)
