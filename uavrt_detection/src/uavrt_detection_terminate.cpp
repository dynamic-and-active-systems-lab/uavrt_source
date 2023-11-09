//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// uavrt_detection_terminate.cpp
//
// Code generation for function 'uavrt_detection_terminate'
//

// Include files
#include "uavrt_detection_terminate.h"
#include "channelreceiver.h"
#include "controlreceiver.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_data.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"

// Function Definitions
void uavrt_detection_terminate()
{
  controlreceiver_free();
  channelreceiver_free();
  isInitialized_uavrt_detection = false;
}

// End of code generation (uavrt_detection_terminate.cpp)
