//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// function_handle.h
//
// Code generation for function 'function_handle'
//

#ifndef FUNCTION_HANDLE_H
#define FUNCTION_HANDLE_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
class waveform;

// Function Declarations
bool binary_expand_op(const coder::array<double, 1U> &in1, const waveform *in2);

void k_binary_expand_op(const coder::array<bool, 1U> &in1,
                        const coder::array<bool, 1U> &in2);

#endif
// End of code generation (function_handle.h)
