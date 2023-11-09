//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// validator_check_size.h
//
// Code generation for function 'validator_check_size'
//

#ifndef VALIDATOR_CHECK_SIZE_H
#define VALIDATOR_CHECK_SIZE_H

// Include files
#include "rtwtypes.h"
#include "uavrt_detection_internal_types.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
bool b_validator_check_size(const ::coder::array<bool, 1U> &in);

void validator_check_size(const ::coder::array<double, 2U> &in,
                          ::coder::array<double, 2U> &out);

void validator_check_size(const ::coder::array<c_struct_T, 2U> &in,
                          ::coder::array<c_struct_T, 2U> &out);

} // namespace internal
} // namespace coder

#endif
// End of code generation (validator_check_size.h)
