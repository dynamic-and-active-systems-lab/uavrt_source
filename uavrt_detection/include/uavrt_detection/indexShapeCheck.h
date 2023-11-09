//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// indexShapeCheck.h
//
// Code generation for function 'indexShapeCheck'
//

#ifndef INDEXSHAPECHECK_H
#define INDEXSHAPECHECK_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
void b_indexShapeCheck(const int matrixSize[2], const int indexSize[2]);

void indexShapeCheck(const int matrixSize[2], const int indexSize[2]);

void indexShapeCheck(const double matrixSize[2], const double indexSize[2]);

void indexShapeCheck(int matrixSize, const int indexSize[2]);

} // namespace internal
} // namespace coder

#endif
// End of code generation (indexShapeCheck.h)
