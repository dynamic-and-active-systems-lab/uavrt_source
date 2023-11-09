//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// nullAssignment.h
//
// Code generation for function 'nullAssignment'
//

#ifndef NULLASSIGNMENT_H
#define NULLASSIGNMENT_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
void nullAssignment(::coder::array<char, 2U> &x, int idx);

void nullAssignment(::coder::array<creal_T, 3U> &x,
                    const ::coder::array<int, 2U> &idx);

} // namespace internal
} // namespace coder

#endif
// End of code generation (nullAssignment.h)
