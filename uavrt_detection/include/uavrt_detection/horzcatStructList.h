//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// horzcatStructList.h
//
// Code generation for function 'horzcatStructList'
//

#ifndef HORZCATSTRUCTLIST_H
#define HORZCATSTRUCTLIST_H

// Include files
#include "rtwtypes.h"
#include "uavrt_detection_internal_types.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
void b_horzcatStructList(const ::coder::array<c_struct_T, 1U> &structure,
                         ::coder::array<double, 2U> &result);

void b_horzcatStructList(const ::coder::array<c_struct_T, 2U> &structure,
                         ::coder::array<double, 2U> &result);

void c_horzcatStructList(const ::coder::array<c_struct_T, 2U> &structure,
                         ::coder::array<bool, 2U> &result);

void d_horzcatStructList(const ::coder::array<c_struct_T, 1U> &structure,
                         ::coder::array<double, 2U> &result);

void d_horzcatStructList(const ::coder::array<c_struct_T, 2U> &structure,
                         ::coder::array<double, 2U> &result);

void horzcatStructList(const ::coder::array<c_struct_T, 2U> &structure,
                       ::coder::array<bool, 2U> &result);

} // namespace internal
} // namespace coder

#endif
// End of code generation (horzcatStructList.h)
