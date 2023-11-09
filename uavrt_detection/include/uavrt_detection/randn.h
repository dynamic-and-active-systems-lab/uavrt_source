//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// randn.h
//
// Code generation for function 'randn'
//

#ifndef RANDN_H
#define RANDN_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void complexLike(creal_T r[1000]);

void complexLike(double varargin_1, ::coder::array<creal_T, 2U> &r);

void randn(double r[1000]);

void randn(double varargin_1, ::coder::array<double, 2U> &r);

} // namespace coder

#endif
// End of code generation (randn.h)
