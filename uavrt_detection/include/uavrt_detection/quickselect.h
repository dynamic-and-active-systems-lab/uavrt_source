//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// quickselect.h
//
// Code generation for function 'quickselect'
//

#ifndef QUICKSELECT_H
#define QUICKSELECT_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
double quickselect(::coder::array<double, 1U> &v, int n, int vlen, int &nfirst,
                   int &nlast);

}
} // namespace coder

#endif
// End of code generation (quickselect.h)
