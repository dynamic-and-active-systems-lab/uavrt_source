//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// minOrMax.h
//
// Code generation for function 'minOrMax'
//

#ifndef MINORMAX_H
#define MINORMAX_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
void maximum(const ::coder::array<double, 2U> &x,
             ::coder::array<double, 1U> &ex, ::coder::array<int, 1U> &idx);

double maximum(const ::coder::array<double, 1U> &x, int &idx);

double maximum(const double x[2]);

double maximum(const ::coder::array<double, 1U> &x);

double minimum(const double x[2]);

} // namespace internal
} // namespace coder

#endif
// End of code generation (minOrMax.h)
