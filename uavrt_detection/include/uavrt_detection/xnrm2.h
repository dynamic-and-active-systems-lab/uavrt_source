//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// xnrm2.h
//
// Code generation for function 'xnrm2'
//

#ifndef XNRM2_H
#define XNRM2_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace blas {
double xnrm2(int n, const ::coder::array<creal_T, 2U> &x, int ix0);

double xnrm2(int n, const ::coder::array<creal_T, 1U> &x, int ix0);

} // namespace blas
} // namespace internal
} // namespace coder

#endif
// End of code generation (xnrm2.h)
