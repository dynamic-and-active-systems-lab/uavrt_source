//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// xscal.h
//
// Code generation for function 'xscal'
//

#ifndef XSCAL_H
#define XSCAL_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace blas {
void xscal(int n, const creal_T a, ::coder::array<creal_T, 2U> &x, int ix0);

void xscal(int n, const creal_T a, ::coder::array<creal_T, 1U> &x, int ix0);

} // namespace blas
} // namespace internal
} // namespace coder

#endif
// End of code generation (xscal.h)
