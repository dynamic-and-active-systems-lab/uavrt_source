//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// stft.h
//
// Code generation for function 'stft'
//

#ifndef STFT_H
#define STFT_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void stft(const ::coder::array<creal32_T, 2U> &x, double varargin_1,
          const ::coder::array<double, 1U> &varargin_3, double varargin_5,
          double varargin_7, ::coder::array<creal32_T, 2U> &varargout_1,
          ::coder::array<float, 1U> &varargout_2,
          ::coder::array<float, 1U> &varargout_3);

void stft(const ::coder::array<creal_T, 2U> &x, double varargin_1,
          const ::coder::array<double, 1U> &varargin_3, double varargin_5,
          double varargin_7, ::coder::array<creal_T, 3U> &varargout_1,
          ::coder::array<double, 1U> &varargout_2,
          ::coder::array<double, 1U> &varargout_3);

} // namespace coder

#endif
// End of code generation (stft.h)
