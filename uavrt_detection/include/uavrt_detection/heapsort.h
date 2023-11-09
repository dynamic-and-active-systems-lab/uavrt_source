//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// heapsort.h
//
// Code generation for function 'heapsort'
//

#ifndef HEAPSORT_H
#define HEAPSORT_H

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
void b_heapsort(::coder::array<int, 1U> &x, int xstart, int xend,
                const c_anonymous_function &cmp);

void b_heapsort(::coder::array<int, 1U> &x, int xstart, int xend,
                const anonymous_function &cmp);

} // namespace internal
} // namespace coder

#endif
// End of code generation (heapsort.h)
