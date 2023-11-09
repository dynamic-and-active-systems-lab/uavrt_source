//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// uavrt_interfaces_PulseStruct.cpp
//
// Code generation for function 'uavrt_interfaces_PulseStruct'
//

// Include files
#include "uavrt_interfaces_PulseStruct.h"
#include "builtin_interfaces_TimeStruct.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"

// Function Definitions
void uavrt_interfaces_PulseStruct(uavrt_interfaces_PulseStruct_T &msg)
{
  static const char b_cv[22]{'u', 'a', 'v', 'r', 't', '_', 'i', 'n',
                             't', 'e', 'r', 'f', 'a', 'c', 'e', 's',
                             '/', 'P', 'u', 'l', 's', 'e'};
  //  Message struct definition for uavrt_interfaces/Pulse
  msg.start_time = builtin_interfaces_TimeStruct();
  msg.end_time = builtin_interfaces_TimeStruct();
  msg.predict_next_start = builtin_interfaces_TimeStruct();
  msg.predict_next_end = builtin_interfaces_TimeStruct();
  for (int i{0}; i < 22; i++) {
    msg.MessageType[i] = b_cv[i];
  }
  msg.detector_dir.set_size(1, 0);
  msg.tag_id = 0U;
  msg.frequency = 0.0;
  msg.snr = 0.0;
  msg.stft_score = 0.0;
  msg.group_ind = 0U;
  msg.group_snr = 0.0;
  msg.detection_status = false;
  msg.confirmed_status = false;
  //(&msg);
}

// End of code generation (uavrt_interfaces_PulseStruct.cpp)
