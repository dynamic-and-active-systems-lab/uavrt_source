//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// sort.h
//
// Code generation for function 'sort'
//

#ifndef SORT_H
#define SORT_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
void sort(::coder::array<double, 2U> &x);

void sort(::coder::array<double, 1U> &x, ::coder::array<int, 1U> &idx);

} // namespace internal
} // namespace coder

#endif
// End of code generation (sort.h)
