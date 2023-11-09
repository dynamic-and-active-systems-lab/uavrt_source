#include "ros2_structmsg_conversion.h"


// Conversions between builtin_interfaces_TimeStruct_T and builtin_interfaces::msg::Time

void struct2msg(builtin_interfaces::msg::Time& msgPtr, builtin_interfaces_TimeStruct_T const* structPtr)
{
  const std::string rosMessageType("builtin_interfaces/Time");

  msgPtr.nanosec =  structPtr->nanosec;
  msgPtr.sec =  structPtr->sec;
}

void msg2struct(builtin_interfaces_TimeStruct_T* structPtr, const builtin_interfaces::msg::Time& msgPtr)
{
  const std::string rosMessageType("builtin_interfaces/Time");

  structPtr->nanosec =  msgPtr.nanosec;
  structPtr->sec =  msgPtr.sec;
}


// Conversions between uavrt_interfaces_PulseStruct_T and uavrt_interfaces::msg::Pulse

void struct2msg(uavrt_interfaces::msg::Pulse& msgPtr, uavrt_interfaces_PulseStruct_T const* structPtr)
{
  const std::string rosMessageType("uavrt_interfaces/Pulse");

  msgPtr.confirmed_status =  structPtr->confirmed_status;
  msgPtr.detection_status =  structPtr->detection_status;
  convertFromStructPrimitiveArray(msgPtr.detector_dir, structPtr->detector_dir);
  struct2msg(msgPtr.end_time, &structPtr->end_time);
  msgPtr.frequency =  structPtr->frequency;
  msgPtr.group_ind =  structPtr->group_ind;
  msgPtr.group_snr =  structPtr->group_snr;
  struct2msg(msgPtr.predict_next_end, &structPtr->predict_next_end);
  struct2msg(msgPtr.predict_next_start, &structPtr->predict_next_start);
  msgPtr.snr =  structPtr->snr;
  struct2msg(msgPtr.start_time, &structPtr->start_time);
  msgPtr.stft_score =  structPtr->stft_score;
  msgPtr.tag_id =  structPtr->tag_id;
}

void msg2struct(uavrt_interfaces_PulseStruct_T* structPtr, const uavrt_interfaces::msg::Pulse& msgPtr)
{
  const std::string rosMessageType("uavrt_interfaces/Pulse");

  structPtr->confirmed_status =  msgPtr.confirmed_status;
  structPtr->detection_status =  msgPtr.detection_status;
  convertToStructPrimitiveArray(structPtr->detector_dir, msgPtr.detector_dir);
  msg2struct(&structPtr->end_time, msgPtr.end_time);
  structPtr->frequency =  msgPtr.frequency;
  structPtr->group_ind =  msgPtr.group_ind;
  structPtr->group_snr =  msgPtr.group_snr;
  msg2struct(&structPtr->predict_next_end, msgPtr.predict_next_end);
  msg2struct(&structPtr->predict_next_start, msgPtr.predict_next_start);
  structPtr->snr =  msgPtr.snr;
  msg2struct(&structPtr->start_time, msgPtr.start_time);
  structPtr->stft_score =  msgPtr.stft_score;
  structPtr->tag_id =  msgPtr.tag_id;
}

