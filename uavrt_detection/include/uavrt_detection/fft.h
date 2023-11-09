//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// fft.h
//
// Code generation for function 'fft'
//

#ifndef FFT_H
#define FFT_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void fft(const ::coder::array<creal32_T, 2U> &x, double varargin_1,
         ::coder::array<creal32_T, 2U> &y);

void fft(const ::coder::array<creal_T, 2U> &x, ::coder::array<creal_T, 2U> &y);

void fft(const ::coder::array<creal_T, 3U> &x, double varargin_1,
         ::coder::array<creal_T, 3U> &y);

} // namespace coder

#endif
// End of code generation (fft.h)
