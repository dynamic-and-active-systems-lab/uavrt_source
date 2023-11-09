//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// sortIdx.h
//
// Code generation for function 'sortIdx'
//

#ifndef SORTIDX_H
#define SORTIDX_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
void merge_block(::coder::array<int, 2U> &idx, ::coder::array<double, 2U> &x,
                 int offset, int n, int preSortLevel,
                 ::coder::array<int, 1U> &iwork,
                 ::coder::array<double, 1U> &xwork);

void merge_block(::coder::array<int, 1U> &idx, ::coder::array<double, 1U> &x,
                 int offset, int n, int preSortLevel,
                 ::coder::array<int, 1U> &iwork,
                 ::coder::array<double, 1U> &xwork);

} // namespace internal
} // namespace coder

#endif
// End of code generation (sortIdx.h)
