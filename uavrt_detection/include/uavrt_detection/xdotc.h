//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// xdotc.h
//
// Code generation for function 'xdotc'
//

#ifndef XDOTC_H
#define XDOTC_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace blas {
creal_T xdotc(int n, const ::coder::array<creal_T, 2U> &x, int ix0,
              const ::coder::array<creal_T, 2U> &y, int iy0);

}
} // namespace internal
} // namespace coder

#endif
// End of code generation (xdotc.h)
