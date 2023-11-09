//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// sum.h
//
// Code generation for function 'sum'
//

#ifndef SUM_H
#define SUM_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
class sparse;

class b_sparse;

class g_sparse;

class c_sparse;

} // namespace coder

// Function Declarations
namespace coder {
void sum(const sparse &x, b_sparse &y);

void sum(const g_sparse &x, c_sparse &y);

void sum(const ::coder::array<double, 2U> &x, ::coder::array<double, 1U> &y);

} // namespace coder

#endif
// End of code generation (sum.h)
