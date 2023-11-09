//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// indexShapeCheck.cpp
//
// Code generation for function 'indexShapeCheck'
//

// Include files
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include <sstream>
#include <stdexcept>
#include <string>

// Variable Definitions
static rtRunTimeErrorInfo kb_emlrtRTEI{
    122,           // lineNo
    5,             // colNo
    "errOrWarnIf", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/"
    "indexShapeCheck.m" // pName
};

// Function Declarations
static void ic_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void jc_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void kc_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void y_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
static void ic_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream
      << "Compile-time size assumption violated. At run-time, a vector indexes "
         "a vector of different orientations, but the compile-time as"
         "sumption is that the matrix is indexed by a matrix of the same size.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

static void jc_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream
      << "Compile-time size assumption violated. At run-time, a matrix logical "
         "indexes a row vector, but the compile-time assumption is lo"
         "gical indexing for the matrix by a matrix of the same size.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

static void kc_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream
      << "Compile-time size assumption violated. At run-time, a row vector "
         "logical indexes a matrix, but the compile-time assumption is lo"
         "gical indexing for the matrix by a matrix of the same size.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

static void y_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream
      << "Compile-time size assumption violated. At run-time, a vector indexes "
         "a scalar, but the compile-time assumption is that the vecto"
         "r is indexed by a vector of the same size.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

namespace coder {
namespace internal {
void b_indexShapeCheck(const int matrixSize[2], const int indexSize[2])
{
  bool nonSingletonDimFound;
  nonSingletonDimFound = (matrixSize[0] != 1);
  if (matrixSize[1] != 1) {
    if (nonSingletonDimFound) {
      nonSingletonDimFound = false;
    } else {
      nonSingletonDimFound = true;
    }
  }
  if (nonSingletonDimFound) {
    nonSingletonDimFound = (matrixSize[0] == 1);
    if (nonSingletonDimFound || (matrixSize[1] != 1)) {
      nonSingletonDimFound = true;
    }
    if (nonSingletonDimFound) {
      kc_rtErrorWithMessageID(kb_emlrtRTEI.fName, kb_emlrtRTEI.lineNo);
    }
  } else {
    nonSingletonDimFound = (indexSize[0] != 1);
    if (indexSize[1] != 1) {
      if (nonSingletonDimFound) {
        nonSingletonDimFound = false;
      } else {
        nonSingletonDimFound = true;
      }
    }
    if (nonSingletonDimFound) {
      nonSingletonDimFound = (indexSize[0] == 1);
      if (nonSingletonDimFound || (indexSize[1] != 1)) {
        nonSingletonDimFound = true;
      }
      if (nonSingletonDimFound) {
        jc_rtErrorWithMessageID(kb_emlrtRTEI.fName, kb_emlrtRTEI.lineNo);
      }
    }
  }
}

void indexShapeCheck(const int matrixSize[2], const int indexSize[2])
{
  bool nonSingletonDimFound;
  nonSingletonDimFound = (matrixSize[0] != 1);
  if (matrixSize[1] != 1) {
    if (nonSingletonDimFound) {
      nonSingletonDimFound = false;
    } else {
      nonSingletonDimFound = true;
    }
  }
  if (nonSingletonDimFound) {
    nonSingletonDimFound = (indexSize[0] != 1);
    if (indexSize[1] != 1) {
      if (nonSingletonDimFound) {
        nonSingletonDimFound = false;
      } else {
        nonSingletonDimFound = true;
      }
    }
    if (nonSingletonDimFound) {
      nonSingletonDimFound = ((matrixSize[0] == 1) != (indexSize[0] == 1));
      if (nonSingletonDimFound ||
          ((matrixSize[1] == 1) != (indexSize[1] == 1))) {
        nonSingletonDimFound = true;
      }
      if (nonSingletonDimFound) {
        ic_rtErrorWithMessageID(kb_emlrtRTEI.fName, kb_emlrtRTEI.lineNo);
      }
    }
  }
}

void indexShapeCheck(const double matrixSize[2], const double indexSize[2])
{
  bool nonSingletonDimFound;
  nonSingletonDimFound = (matrixSize[0] != 1.0);
  if (matrixSize[1] != 1.0) {
    if (nonSingletonDimFound) {
      nonSingletonDimFound = false;
    } else {
      nonSingletonDimFound = true;
    }
  }
  if (nonSingletonDimFound) {
    nonSingletonDimFound = (indexSize[0] != 1.0);
    if (indexSize[1] != 1.0) {
      if (nonSingletonDimFound) {
        nonSingletonDimFound = false;
      } else {
        nonSingletonDimFound = true;
      }
    }
    if (nonSingletonDimFound) {
      nonSingletonDimFound = ((matrixSize[0] == 1.0) != (indexSize[0] == 1.0));
      if (nonSingletonDimFound ||
          ((matrixSize[1] == 1.0) != (indexSize[1] == 1.0))) {
        nonSingletonDimFound = true;
      }
      if (nonSingletonDimFound) {
        ic_rtErrorWithMessageID(kb_emlrtRTEI.fName, kb_emlrtRTEI.lineNo);
      }
    }
  }
}

void indexShapeCheck(int matrixSize, const int indexSize[2])
{
  if ((matrixSize == 1) && (indexSize[1] != 1)) {
    y_rtErrorWithMessageID(kb_emlrtRTEI.fName, kb_emlrtRTEI.lineNo);
  }
}

} // namespace internal
} // namespace coder

// End of code generation (indexShapeCheck.cpp)
