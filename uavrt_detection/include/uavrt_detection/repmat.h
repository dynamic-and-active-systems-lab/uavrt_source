//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// repmat.h
//
// Code generation for function 'repmat'
//

#ifndef REPMAT_H
#define REPMAT_H

// Include files
#include "rtwtypes.h"
#include "uavrt_detection_internal_types.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void repmat(const c_struct_T &a, double varargin_1, double varargin_2,
            ::coder::array<c_struct_T, 2U> &b);

void repmat(const ::coder::array<double, 2U> &a, double varargin_1,
            ::coder::array<double, 2U> &b);

void repmat(const ::coder::array<double, 1U> &a, double varargin_2,
            ::coder::array<double, 2U> &b);

} // namespace coder

#endif
// End of code generation (repmat.h)
