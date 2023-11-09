//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// incohsumtoeplitz.h
//
// Code generation for function 'incohsumtoeplitz'
//

#ifndef INCOHSUMTOEPLITZ_H
#define INCOHSUMTOEPLITZ_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
class sparse;

}

// Function Declarations
void incohsumtoeplitz(const coder::array<bool, 1U> &Fb,
                      const coder::array<creal_T, 2U> &Wfherm,
                      const coder::array<creal_T, 2U> &S,
                      const coder::array<double, 1U> &Tb,
                      const coder::sparse &Wq,
                      coder::array<double, 2U> &Sscores,
                      coder::array<double, 2U> &Scols);

#endif
// End of code generation (incohsumtoeplitz.h)
