//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// uavrt_detection_initialize.cpp
//
// Code generation for function 'uavrt_detection_initialize'
//

// Include files
#include "uavrt_detection_initialize.h"
#include "CoderTimeAPI.h"
#include "channelreceiver.h"
#include "controlreceiver.h"
#include "eml_rand.h"
#include "eml_rand_mcg16807_stateful.h"
#include "eml_rand_mt19937ar_stateful.h"
#include "eml_rand_shr3cong_stateful.h"
#include "eml_randn.h"
#include "fileManager.h"
#include "pause.h"
#include "rt_nonfinite.h"
#include "timeKeeper.h"
#include "uavrt_detection_data.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"

// Function Definitions
void uavrt_detection_initialize()
{
  savedTime_not_empty_init();
  freq_not_empty_init();
  channelreceiver_init();
  controlreceiver_init();
  filedata_init();
  eml_randn_init();
  eml_rand_init();
  eml_rand_mcg16807_stateful_init();
  eml_rand_shr3cong_stateful_init();
  eml_rand_mt19937ar_stateful_init();
  cpause_init();
  isInitialized_uavrt_detection = true;
}

// End of code generation (uavrt_detection_initialize.cpp)
