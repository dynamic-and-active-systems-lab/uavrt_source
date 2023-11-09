//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// diff.h
//
// Code generation for function 'diff'
//

#ifndef DIFF_H
#define DIFF_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void diff(const ::coder::array<double, 1U> &x, ::coder::array<double, 1U> &y);

void diff(const ::coder::array<double, 2U> &x, ::coder::array<double, 2U> &y);

} // namespace coder

#endif
// End of code generation (diff.h)
