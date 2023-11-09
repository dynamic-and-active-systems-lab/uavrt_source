//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// buildtimecorrelatormatrix.h
//
// Code generation for function 'buildtimecorrelatormatrix'
//

#ifndef BUILDTIMECORRELATORMATRIX_H
#define BUILDTIMECORRELATORMATRIX_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
class sparse;

}

// Function Declarations
void buildtimecorrelatormatrix(double pri, double priUncert, double priJtr,
                               double reps, coder::sparse &Wq);

#endif
// End of code generation (buildtimecorrelatormatrix.h)
