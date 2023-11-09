//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// locBsearch.h
//
// Code generation for function 'locBsearch'
//

#ifndef LOCBSEARCH_H
#define LOCBSEARCH_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
int b_sparse_locBsearch(const ::coder::array<int, 1U> &x, int xi, int xstart,
                        int xend, bool &found);

int sparse_locBsearch(const ::coder::array<int, 1U> &x, double xi, int xstart,
                      int xend, bool &found);

} // namespace coder

#endif
// End of code generation (locBsearch.h)
