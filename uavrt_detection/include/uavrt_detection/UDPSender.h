//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// UDPSender.h
//
// Code generation for function 'UDPSender'
//

#ifndef UDPSENDER_H
#define UDPSENDER_H

// Include files
#include "rtwtypes.h"
#include "uavrt_detection_internal_types.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
namespace dspcodegen {
class UDPSender {
public:
  void step(const unsigned char varargin_1[53]);
  void matlabCodegenDestructor();
  ~UDPSender();
  UDPSender();
  bool matlabCodegenIsDeleted;
  int isInitialized;
  dsp_UDPSender_0 cSFunObject;

private:
  bool isSetupComplete;
};

} // namespace dspcodegen
} // namespace coder

#endif
// End of code generation (UDPSender.h)
