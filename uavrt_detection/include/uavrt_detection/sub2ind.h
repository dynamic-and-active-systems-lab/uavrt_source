//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// sub2ind.h
//
// Code generation for function 'sub2ind'
//

#ifndef SUB2IND_H
#define SUB2IND_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
bool allinrange(const ::coder::array<double, 2U> &x, int hi);

void eml_sub2ind(const int siz[2], const ::coder::array<double, 2U> &varargin_1,
                 const ::coder::array<double, 2U> &varargin_2,
                 ::coder::array<int, 2U> &idx);

void eml_sub2ind(const int siz[2], const ::coder::array<double, 1U> &varargin_1,
                 const ::coder::array<double, 1U> &varargin_2,
                 ::coder::array<int, 1U> &idx);

int eml_sub2ind(const int siz[2], double varargin_2);

} // namespace coder

#endif
// End of code generation (sub2ind.h)
