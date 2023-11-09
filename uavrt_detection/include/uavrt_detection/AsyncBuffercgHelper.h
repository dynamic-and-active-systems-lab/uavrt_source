//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// AsyncBuffercgHelper.h
//
// Code generation for function 'AsyncBuffercgHelper'
//

#ifndef ASYNCBUFFERCGHELPER_H
#define ASYNCBUFFERCGHELPER_H

// Include files
#include "rtwtypes.h"
#include "uavrt_detection_internal_types.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
namespace dsp {
namespace internal {
class AsyncBuffercgHelper {
public:
  void matlabCodegenDestructor();
  ~AsyncBuffercgHelper();
  AsyncBuffercgHelper();
  bool matlabCodegenIsDeleted;
  int isInitialized;
  bool isSetupComplete;
  cell_wrap_2 inputVarSize[1];
  int NumChannels;
  creal32_T Cache[5800321];
  int CumulativeOverrun;
  int CumulativeUnderrun;
  int ReadPointer;
  int WritePointer;
  bool AsyncBuffercgHelper_isInitialized;
};

class b_AsyncBuffercgHelper {
public:
  void matlabCodegenDestructor();
  ~b_AsyncBuffercgHelper();
  b_AsyncBuffercgHelper();
  bool matlabCodegenIsDeleted;
  int isInitialized;
  bool isSetupComplete;
  cell_wrap_2 inputVarSize[1];
  int NumChannels;
  double Cache[5800321];
  int CumulativeOverrun;
  int CumulativeUnderrun;
  int ReadPointer;
  int WritePointer;
  bool AsyncBuffercgHelper_isInitialized;
};

class c_AsyncBuffercgHelper {
public:
  int read(int numRows, ::coder::array<creal32_T, 1U> &out);
  void matlabCodegenDestructor();
  ~c_AsyncBuffercgHelper();
  c_AsyncBuffercgHelper();
  bool matlabCodegenIsDeleted;
  int isInitialized;
  bool isSetupComplete;
  cell_wrap_2 inputVarSize[1];
  int NumChannels;
  creal32_T Cache[600651];
  int CumulativeOverrun;
  int CumulativeUnderrun;
  int ReadPointer;
  int WritePointer;
  bool AsyncBuffercgHelper_isInitialized;
};

} // namespace internal
} // namespace dsp
} // namespace coder

#endif
// End of code generation (AsyncBuffercgHelper.h)
