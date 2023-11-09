//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// sparse.h
//
// Code generation for function 'sparse'
//

#ifndef SPARSE_H
#define SPARSE_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
class sparse;

class d_sparse;

class g_sparse;

} // namespace coder

// Function Declarations
namespace coder {
void i_sparse(const ::coder::array<double, 1U> &varargin_1, g_sparse &y);

void i_sparse(const ::coder::array<double, 1U> &varargin_1,
              const ::coder::array<double, 1U> &varargin_2,
              const ::coder::array<double, 1U> &varargin_3, sparse &y);

void j_sparse(const ::coder::array<bool, 2U> &varargin_1, d_sparse &y);

} // namespace coder

#endif
// End of code generation (sparse.h)
