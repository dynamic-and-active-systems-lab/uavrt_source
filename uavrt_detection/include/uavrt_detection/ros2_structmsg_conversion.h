#ifndef _ROS2_STRUCTMSG_CONVERSION_H_
#define _ROS2_STRUCTMSG_CONVERSION_H_

#include "rclcpp/rclcpp.hpp"
#include <builtin_interfaces/msg/time.hpp>
#include <uavrt_interfaces/msg/pulse.hpp>
#include "uavrt_detection_types.h"
#include "mlros2_msgconvert_utils.h"


void struct2msg(builtin_interfaces::msg::Time& msgPtr, builtin_interfaces_TimeStruct_T const* structPtr);
void msg2struct(builtin_interfaces_TimeStruct_T* structPtr, const builtin_interfaces::msg::Time& msgPtr);

void struct2msg(uavrt_interfaces::msg::Pulse& msgPtr, uavrt_interfaces_PulseStruct_T const* structPtr);
void msg2struct(uavrt_interfaces_PulseStruct_T* structPtr, const uavrt_interfaces::msg::Pulse& msgPtr);


#endif
