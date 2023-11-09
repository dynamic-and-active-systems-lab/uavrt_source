//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// UDPReceiver.cpp
//
// Code generation for function 'UDPReceiver'
//

// Include files
#include "UDPReceiver.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"

// Function Definitions
namespace coder {
namespace dspcodegen {
UDPReceiver::UDPReceiver() = default;

UDPReceiver::~UDPReceiver() = default;

b_UDPReceiver::b_UDPReceiver() = default;

b_UDPReceiver::~b_UDPReceiver() = default;

void b_UDPReceiver::release()
{
  char *sErr;
  if (isInitialized == 1) {
    isInitialized = 2;
    if (isSetupComplete) {
      // System object Destructor function: dsp.UDPReceiver
      // System object Terminate function: dsp.UDPReceiver
      sErr = GetErrorBuffer(&cSFunObject.W0_NetworkLib[0U]);
      LibTerminate(&cSFunObject.W0_NetworkLib[0U]);
      if (*sErr != 0) {
        PrintError(sErr);
      }
      LibDestroy(&cSFunObject.W0_NetworkLib[0U], 0);
      DestroyUDPInterface(&cSFunObject.W0_NetworkLib[0U]);
    }
  }
}

void UDPReceiver::release()
{
  char *sErr;
  if (isInitialized == 1) {
    isInitialized = 2;
    if (isSetupComplete) {
      // System object Destructor function: dsp.UDPReceiver
      // System object Terminate function: dsp.UDPReceiver
      sErr = GetErrorBuffer(&cSFunObject.W0_NetworkLib[0U]);
      LibTerminate(&cSFunObject.W0_NetworkLib[0U]);
      if (*sErr != 0) {
        PrintError(sErr);
      }
      LibDestroy(&cSFunObject.W0_NetworkLib[0U], 0);
      DestroyUDPInterface(&cSFunObject.W0_NetworkLib[0U]);
    }
  }
}

} // namespace dspcodegen
} // namespace coder

// End of code generation (UDPReceiver.cpp)
