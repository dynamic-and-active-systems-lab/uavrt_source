//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// interp1.h
//
// Code generation for function 'interp1'
//

#ifndef INTERP1_H
#define INTERP1_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void interp1(const double varargin_1[2], const double varargin_2[2],
             const ::coder::array<double, 2U> &varargin_3,
             ::coder::array<double, 2U> &Vq);

void interp1(const ::coder::array<double, 1U> &varargin_1,
             const ::coder::array<double, 1U> &varargin_2,
             const ::coder::array<double, 1U> &varargin_3,
             ::coder::array<double, 1U> &Vq);

} // namespace coder

#endif
// End of code generation (interp1.h)
