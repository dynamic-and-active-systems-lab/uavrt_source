//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// channelreceiver.cpp
//
// Code generation for function 'channelreceiver'
//

// Include files
#include "channelreceiver.h"
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
void channelreceiver(double localIPPort, bool resetUDP,
                     coder::array<creal32_T, 2U> &dataReceived)
{
  int i;
  int loop_ub;
  int samplesRead;
  char *sErr;
  // CHANNELRECEIVER receives channelized data from the channelizer function
  // via the specified local IP port from the specified remote IP.
  //
  // This function is defined to interact with airspyhf_channelizer which
  // outputs 1024 samples of IQ with a timestamp for a total of 1025 complex
  // single precision values. The remoteIP port is not tunable and is only used
  // on the first call to setup the dsp.UDPReceiver object. Changing it on
  // subsequent calls will do nothing to change the receiver. The local IP port
  // is tunable however. This funtion uses persistant variables and must be
  // cleared if subsequent calls are needed to change the remote IP. For
  // example call
  //
  //    mydata = channelreceiver('127.0.0.1',12345);
  //    mynewerdata = channelreceiver('127.0.0.1',12345);
  //    mynewerdatafromdifferentport = channelreceiver('127.0.0.1',54321);
  //    clear channelreceiver
  //    datafromnewip = channelreceiver('127.0.0.2',12345);
  //
  // INPUTS:
  //    remoteIP    A string of the remote IP address from which to accept data
  //                Example: '127.0.0.1' - local machine
  //                         '0.0.0.0'   - receive from any remote IP
  //                         '127.0.0.7' - receive from some other IP on the
  //                                       network
  //    localIPPort     Scalar value of the port on which to receive the data.
  //    resetUDP        Logic to reset the persistant udp object
  //    releaseSysObj   Logical to release the dsp.UDPReceiver system object
  //
  // OUTPUTS:
  //    dataReceived    A vector of received  complex single precision values.
  //                    Maximum length is 1025
  //
  // Author:    Michael W. Shafer
  // Date:      2022-02-14
  // --------------------------------------------------------------------------
  // Reset to clear the buffer of stale data.
  if (!udpRx_not_empty) {
    udpRx.isInitialized = 0;
    // System object Constructor function: dsp.UDPReceiver
    udpRx.cSFunObject.P0_Port = 25000;
    udpRx.LocalIPPort = 25000.0;
    udpRx.matlabCodegenIsDeleted = false;
    udpRx_not_empty = true;
    // %127.0.0.1',... %Accept all
    // %2^16 = 65536, 2^18
  }
  if (resetUDP && (udpRx.isInitialized == 2)) {
    rtErrorWithMessageID("reset", b_emlrtRTEI.fName, b_emlrtRTEI.lineNo);
  }
  if (udpRx.LocalIPPort != localIPPort) {
    double d;
    if (udpRx.isInitialized == 1) {
      udpRx.isInitialized = 2;
      if (udpRx.isSetupComplete) {
        // System object Destructor function: dsp.UDPReceiver
        // System object Terminate function: dsp.UDPReceiver
        sErr = GetErrorBuffer(&udpRx.cSFunObject.W0_NetworkLib[0U]);
        LibTerminate(&udpRx.cSFunObject.W0_NetworkLib[0U]);
        if (*sErr != 0) {
          PrintError(sErr);
        }
        LibDestroy(&udpRx.cSFunObject.W0_NetworkLib[0U], 0);
        DestroyUDPInterface(&udpRx.cSFunObject.W0_NetworkLib[0U]);
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
    udpRx.cSFunObject.P0_Port = i;
    udpRx.LocalIPPort = localIPPort;
  }
  if (udpRx.isInitialized == 2) {
    rtErrorWithMessageID("step", ob_emlrtRTEI.fName, ob_emlrtRTEI.lineNo);
  }
  if (udpRx.isInitialized != 1) {
    udpRx.isSetupComplete = false;
    if (udpRx.isInitialized != 0) {
      d_rtErrorWithMessageID("setup", pb_emlrtRTEI.fName, pb_emlrtRTEI.lineNo);
    }
    udpRx.isInitialized = 1;
    // System object Start function: dsp.UDPReceiver
    sErr = GetErrorBuffer(&udpRx.cSFunObject.W0_NetworkLib[0U]);
    CreateUDPInterface(&udpRx.cSFunObject.W0_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&udpRx.cSFunObject.W0_NetworkLib[0U], 0, "0.0.0.0",
                        udpRx.cSFunObject.P0_Port, "127.0.0.1", -1, 262144, 4,
                        0);
    }
    if (*sErr == 0) {
      LibStart(&udpRx.cSFunObject.W0_NetworkLib[0U]);
    }
    if (*sErr != 0) {
      DestroyUDPInterface(&udpRx.cSFunObject.W0_NetworkLib[0U]);
      if (*sErr != 0) {
        PrintError(sErr);
      }
    }
    udpRx.isSetupComplete = true;
  }
  // System object Outputs function: dsp.UDPReceiver
  sErr = GetErrorBuffer(&udpRx.cSFunObject.W0_NetworkLib[0U]);
  udpRx.cSFunObject.O0_Y0.set_size(1025, 1);
  samplesRead = 1025;
  samplesRead <<= 1;
  LibOutputs_Network(&udpRx.cSFunObject.W0_NetworkLib[0U],
                     &(udpRx.cSFunObject.O0_Y0.data())[0U], &samplesRead);
  if (*sErr != 0) {
    PrintError(sErr);
  }
  udpRx.cSFunObject.O0_Y0.set_size(samplesRead >> 1, 1);
  dataReceived.set_size(udpRx.cSFunObject.O0_Y0.size(0),
                        udpRx.cSFunObject.O0_Y0.size(1));
  loop_ub = udpRx.cSFunObject.O0_Y0.size(0) * udpRx.cSFunObject.O0_Y0.size(1);
  for (i = 0; i < loop_ub; i++) {
    dataReceived[i] = udpRx.cSFunObject.O0_Y0[i];
  }
}

void channelreceiver_free()
{
  char *sErr;
  if (!udpRx.matlabCodegenIsDeleted) {
    udpRx.matlabCodegenIsDeleted = true;
    if (udpRx.isInitialized == 1) {
      udpRx.isInitialized = 2;
      if (udpRx.isSetupComplete) {
        // System object Destructor function: dsp.UDPReceiver
        // System object Terminate function: dsp.UDPReceiver
        sErr = GetErrorBuffer(&udpRx.cSFunObject.W0_NetworkLib[0U]);
        LibTerminate(&udpRx.cSFunObject.W0_NetworkLib[0U]);
        if (*sErr != 0) {
          PrintError(sErr);
        }
        LibDestroy(&udpRx.cSFunObject.W0_NetworkLib[0U], 0);
        DestroyUDPInterface(&udpRx.cSFunObject.W0_NetworkLib[0U]);
      }
    }
  }
}

void channelreceiver_init()
{
  udpRx_not_empty = false;
  udpRx.matlabCodegenIsDeleted = true;
}

// End of code generation (channelreceiver.cpp)
