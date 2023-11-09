//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// circshift.h
//
// Code generation for function 'circshift'
//

#ifndef CIRCSHIFT_H
#define CIRCSHIFT_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void b_circshift(::coder::array<double, 2U> &a);

void c_circshift(::coder::array<double, 2U> &a);

void circshift(::coder::array<creal32_T, 2U> &a, double p);

void circshift(::coder::array<creal_T, 2U> &a, double dim);

void circshift(::coder::array<double, 2U> &a);

void d_circshift(::coder::array<double, 2U> &a);

void e_circshift(::coder::array<double, 2U> &a);

void f_circshift(::coder::array<double, 2U> &a);

void g_circshift(::coder::array<bool, 2U> &a);

} // namespace coder

#endif
// End of code generation (circshift.h)
