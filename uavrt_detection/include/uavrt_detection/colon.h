//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// colon.h
//
// Code generation for function 'colon'
//

#ifndef COLON_H
#define COLON_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void b_eml_integer_colon_dispatcher(int b, ::coder::array<int, 2U> &y);

void c_eml_integer_colon_dispatcher(int a, ::coder::array<int, 2U> &y);

void eml_float_colon(double a, double b, ::coder::array<double, 2U> &y);

void eml_integer_colon_dispatcher(int a, ::coder::array<int, 2U> &y);

void eml_integer_colon_dispatcher(int a, int b, ::coder::array<int, 2U> &y);

} // namespace coder

#endif
// End of code generation (colon.h)
