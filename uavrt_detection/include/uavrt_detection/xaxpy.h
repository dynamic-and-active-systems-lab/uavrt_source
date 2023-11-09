//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// xaxpy.h
//
// Code generation for function 'xaxpy'
//

#ifndef XAXPY_H
#define XAXPY_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace blas {
void xaxpy(int n, const creal_T a, int ix0, ::coder::array<creal_T, 2U> &y,
           int iy0);

void xaxpy(int n, const creal_T a, const ::coder::array<creal_T, 2U> &x,
           int ix0, ::coder::array<creal_T, 1U> &y, int iy0);

void xaxpy(int n, const creal_T a, const ::coder::array<creal_T, 1U> &x,
           int ix0, ::coder::array<creal_T, 2U> &y, int iy0);

} // namespace blas
} // namespace internal
} // namespace coder

#endif
// End of code generation (xaxpy.h)
