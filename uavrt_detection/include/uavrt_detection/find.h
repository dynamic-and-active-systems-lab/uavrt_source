//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// find.h
//
// Code generation for function 'find'
//

#ifndef FIND_H
#define FIND_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
class sparse;

}
class waveform;

// Function Declarations
void binary_expand_op(coder::array<int, 1U> &in1,
                      const coder::array<double, 1U> &in2, int in3, int in4,
                      int in5, const waveform *in6, int in7, int in8, int in9);

void binary_expand_op(coder::array<int, 1U> &in1,
                      const coder::array<double, 1U> &in2, int in3, int in4,
                      const waveform *in5, int in6, int in7);

namespace coder {
void b_eml_find(const ::coder::array<bool, 2U> &x, ::coder::array<int, 2U> &i);

void c_eml_find(const ::coder::array<bool, 1U> &x, ::coder::array<int, 1U> &i);

void d_eml_find(const ::coder::array<bool, 1U> &x, ::coder::array<int, 1U> &i);

void e_eml_find(const sparse &x, ::coder::array<int, 1U> &i,
                ::coder::array<int, 1U> &j);

void eml_find(const ::coder::array<bool, 2U> &x, ::coder::array<int, 2U> &i);

} // namespace coder

#endif
// End of code generation (find.h)
