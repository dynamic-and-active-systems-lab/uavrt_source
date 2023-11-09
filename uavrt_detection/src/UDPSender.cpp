//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// UDPSender.cpp
//
// Code generation for function 'UDPSender'
//

// Include files
#include "UDPSender.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_internal_types.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"

// Function Definitions
namespace coder {
namespace dspcodegen {
UDPSender::UDPSender()
{
  matlabCodegenIsDeleted = true;
}

UDPSender::~UDPSender()
{
  matlabCodegenDestructor();
}

void UDPSender::matlabCodegenDestructor()
{
  char *sErr;
  if (!matlabCodegenIsDeleted) {
    matlabCodegenIsDeleted = true;
    if (isInitialized == 1) {
      isInitialized = 2;
      if (isSetupComplete) {
        // System object Destructor function: dsp.UDPSender
        // System object Terminate function: dsp.UDPSender
        sErr = GetErrorBuffer(&cSFunObject.W0_NetworkLib[0U]);
        LibTerminate(&cSFunObject.W0_NetworkLib[0U]);
        if (*sErr != 0) {
          PrintError(sErr);
        }
        LibDestroy(&cSFunObject.W0_NetworkLib[0U], 1);
        DestroyUDPInterface(&cSFunObject.W0_NetworkLib[0U]);
      }
    }
  }
}

void UDPSender::step(const unsigned char varargin_1[53])
{
  unsigned char U0[53];
  char *sErr;
  if (isInitialized == 2) {
    rtErrorWithMessageID("step", ob_emlrtRTEI.fName, ob_emlrtRTEI.lineNo);
  }
  if (isInitialized != 1) {
    isSetupComplete = false;
    if (isInitialized != 0) {
      d_rtErrorWithMessageID("setup", pb_emlrtRTEI.fName, pb_emlrtRTEI.lineNo);
    }
    isInitialized = 1;
    // System object Start function: dsp.UDPSender
    sErr = GetErrorBuffer(&cSFunObject.W0_NetworkLib[0U]);
    CreateUDPInterface(&cSFunObject.W0_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&cSFunObject.W0_NetworkLib[0U], 1, "0.0.0.0", -1,
                        "127.0.0.1", cSFunObject.P0_Port, 8192, 1, 0);
    }
    if (*sErr == 0) {
      LibStart(&cSFunObject.W0_NetworkLib[0U]);
    }
    if (*sErr != 0) {
      DestroyUDPInterface(&cSFunObject.W0_NetworkLib[0U]);
      if (*sErr != 0) {
        PrintError(sErr);
      }
    }
    isSetupComplete = true;
  }
  for (int i{0}; i < 53; i++) {
    U0[i] = varargin_1[i];
  }
  // System object Update function: dsp.UDPSender
  sErr = GetErrorBuffer(&cSFunObject.W0_NetworkLib[0U]);
  LibUpdate_Network(&cSFunObject.W0_NetworkLib[0U], &U0[0U], 53);
  if (*sErr != 0) {
    PrintError(sErr);
  }
}

} // namespace dspcodegen
} // namespace coder

// End of code generation (UDPSender.cpp)
