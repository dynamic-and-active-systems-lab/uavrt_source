//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// UDPReceiver.h
//
// Code generation for function 'UDPReceiver'
//

#ifndef UDPRECEIVER_H
#define UDPRECEIVER_H

// Include files
#include "rtwtypes.h"
#include "uavrt_detection_types.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
namespace dspcodegen {
class UDPReceiver {
public:
  void release();
  UDPReceiver();
  ~UDPReceiver();
  bool matlabCodegenIsDeleted;
  int isInitialized;
  bool isSetupComplete;
  dsp_UDPReceiver_2 cSFunObject;
  double LocalIPPort;
};

class b_UDPReceiver {
public:
  void release();
  b_UDPReceiver();
  ~b_UDPReceiver();
  bool matlabCodegenIsDeleted;
  int isInitialized;
  bool isSetupComplete;
  dsp_UDPReceiver_4 cSFunObject;
  double LocalIPPort;
};

} // namespace dspcodegen
} // namespace coder

#endif
// End of code generation (UDPReceiver.h)
