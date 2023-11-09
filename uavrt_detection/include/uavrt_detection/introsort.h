//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// introsort.h
//
// Code generation for function 'introsort'
//

#ifndef INTROSORT_H
#define INTROSORT_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
class anonymous_function;

class c_anonymous_function;

} // namespace coder

// Function Declarations
namespace coder {
namespace internal {
void introsort(::coder::array<int, 1U> &x, int xend,
               const c_anonymous_function &cmp);

void introsort(::coder::array<int, 1U> &x, int xend,
               const anonymous_function &cmp);

} // namespace internal
} // namespace coder

#endif
// End of code generation (introsort.h)
