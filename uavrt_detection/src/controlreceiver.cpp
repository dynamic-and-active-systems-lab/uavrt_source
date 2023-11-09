//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// controlreceiver.cpp
//
// Code generation for function 'controlreceiver'
//

// Include files
#include "controlreceiver.h"
#include "UDPReceiver.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
void controlreceiver(double localIPPort,
                     coder::array<signed char, 2U> &dataReceived)
{
  int i;
  int loop_ub;
  int samplesRead;
  char *sErr;
  // CONTROLRECEIVER receives control signal data from the
  // via the specified local IP port from the specified remote IP.
  //
  // This function is defined to receive integer control commands and pass
  // those receive integers as output. The remoteIP port is not tunable and is
  // only used on the first call to setup the dsp.UDPReceiver object. Changing
  // it on ubsequent calls will do nothing to change the receiver. The local
  // IP port is tuneable however. This funtion uses persistant variables and
  // must be cleared if subsequent calls are needed to change the remote IP.
  // For example call
  //
  //    mycntrl = controlreceiver('127.0.0.1',12345);
  //    mynewercntrl = controlreceiver('127.0.0.1',12345);
  //    mynewercntrlfromdifferentport = controlreceiver('127.0.0.1',54321);
  //    clear channelreceiver
  //    cntrlfromnewip = controlreceiver('127.0.0.2',12345);
  //
  // INPUTS:
  //    remoteIP    A string of the remote IP address from which to accept
  //                messages
  //                Example: '127.0.0.1' - local machine
  //                         '0.0.0.0'   - receive from any remote IP
  //                         '127.0.0.7' - receive from some other IP on the
  //                                       network
  //    localIPPort     Scalar value of the port on which to receive the
  //                    message.
  //    releaseSysObj   Logical to release the dsp.UDPReceiver system object
  //
  // OUTPUTS:
  //    dataReceived    The received real scalar command message passed.
  //                    Received messages are int8.
  //                    Maximum length is 1025
  //
  // Author:    Michael W. Shafer
  // Date:      2022-02-16
  // --------------------------------------------------------------------------
  // Reset to clear the buffer of stale data.
  if (!b_udpRx_not_empty) {
    b_udpRx.isInitialized = 0;
    // System object Constructor function: dsp.UDPReceiver
    b_udpRx.cSFunObject.P0_Port = 25000;
    b_udpRx.LocalIPPort = 25000.0;
    b_udpRx.matlabCodegenIsDeleted = false;
    b_udpRx_not_empty = true;
    // %127.0.0.1',... %Accept all
    // %2^16 = 65536, 2^18
  }
  if (b_udpRx.LocalIPPort != localIPPort) {
    double d;
    if (b_udpRx.isInitialized == 1) {
      b_udpRx.isInitialized = 2;
      if (b_udpRx.isSetupComplete) {
        // System object Destructor function: dsp.UDPReceiver
        // System object Terminate function: dsp.UDPReceiver
        sErr = GetErrorBuffer(&b_udpRx.cSFunObject.W0_NetworkLib[0U]);
        LibTerminate(&b_udpRx.cSFunObject.W0_NetworkLib[0U]);
        if (*sErr != 0) {
          PrintError(sErr);
        }
        LibDestroy(&b_udpRx.cSFunObject.W0_NetworkLib[0U], 0);
        DestroyUDPInterface(&b_udpRx.cSFunObject.W0_NetworkLib[0U]);
      }
    }
    d = std::round(localIPPort);
    if (d < 2.147483648E+9) {
      if (d >= -2.147483648E+9) {
        i = static_cast<int>(d);
      } else {
        i = MIN_int32_T;
      }
    } else if (d >= 2.147483648E+9) {
      i = MAX_int32_T;
    } else {
      i = 0;
    }
    b_udpRx.cSFunObject.P0_Port = i;
    b_udpRx.LocalIPPort = localIPPort;
  }
  if (b_udpRx.isInitialized == 2) {
    rtErrorWithMessageID("step", ob_emlrtRTEI.fName, ob_emlrtRTEI.lineNo);
  }
  if (b_udpRx.isInitialized != 1) {
    b_udpRx.isSetupComplete = false;
    if (b_udpRx.isInitialized != 0) {
      d_rtErrorWithMessageID("setup", pb_emlrtRTEI.fName, pb_emlrtRTEI.lineNo);
    }
    b_udpRx.isInitialized = 1;
    // System object Start function: dsp.UDPReceiver
    sErr = GetErrorBuffer(&b_udpRx.cSFunObject.W0_NetworkLib[0U]);
    CreateUDPInterface(&b_udpRx.cSFunObject.W0_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&b_udpRx.cSFunObject.W0_NetworkLib[0U], 0, "0.0.0.0",
                        b_udpRx.cSFunObject.P0_Port, "127.0.0.1", -1, 64, 1, 0);
    }
    if (*sErr == 0) {
      LibStart(&b_udpRx.cSFunObject.W0_NetworkLib[0U]);
    }
    if (*sErr != 0) {
      DestroyUDPInterface(&b_udpRx.cSFunObject.W0_NetworkLib[0U]);
      if (*sErr != 0) {
        PrintError(sErr);
      }
    }
    b_udpRx.isSetupComplete = true;
  }
  // System object Outputs function: dsp.UDPReceiver
  sErr = GetErrorBuffer(&b_udpRx.cSFunObject.W0_NetworkLib[0U]);
  b_udpRx.cSFunObject.O0_Y0.set_size(1024, 1);
  samplesRead = 1024;
  LibOutputs_Network(&b_udpRx.cSFunObject.W0_NetworkLib[0U],
                     &(b_udpRx.cSFunObject.O0_Y0.data())[0U], &samplesRead);
  if (*sErr != 0) {
    PrintError(sErr);
  }
  b_udpRx.cSFunObject.O0_Y0.set_size(samplesRead, 1);
  dataReceived.set_size(b_udpRx.cSFunObject.O0_Y0.size(0),
                        b_udpRx.cSFunObject.O0_Y0.size(1));
  loop_ub =
      b_udpRx.cSFunObject.O0_Y0.size(0) * b_udpRx.cSFunObject.O0_Y0.size(1);
  for (i = 0; i < loop_ub; i++) {
    dataReceived[i] = b_udpRx.cSFunObject.O0_Y0[i];
  }
}

void controlreceiver_free()
{
  char *sErr;
  if (!b_udpRx.matlabCodegenIsDeleted) {
    b_udpRx.matlabCodegenIsDeleted = true;
    if (b_udpRx.isInitialized == 1) {
      b_udpRx.isInitialized = 2;
      if (b_udpRx.isSetupComplete) {
        // System object Destructor function: dsp.UDPReceiver
        // System object Terminate function: dsp.UDPReceiver
        sErr = GetErrorBuffer(&b_udpRx.cSFunObject.W0_NetworkLib[0U]);
        LibTerminate(&b_udpRx.cSFunObject.W0_NetworkLib[0U]);
        if (*sErr != 0) {
          PrintError(sErr);
        }
        LibDestroy(&b_udpRx.cSFunObject.W0_NetworkLib[0U], 0);
        DestroyUDPInterface(&b_udpRx.cSFunObject.W0_NetworkLib[0U]);
      }
    }
  }
}

void controlreceiver_init()
{
  b_udpRx_not_empty = false;
  b_udpRx.matlabCodegenIsDeleted = true;
}

// End of code generation (controlreceiver.cpp)
