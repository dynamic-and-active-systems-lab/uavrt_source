//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// ros2publisher.cpp
//
// Code generation for function 'ros2publisher'
//

// Include files
#include "ros2publisher.h"
#include "ros2node.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_types.h"
#include "uavrt_interfaces_PulseStruct.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "mlros2_node.h"
#include "mlros2_pub.h"
#include "mlros2_qos.h"
#include "rmw/qos_profiles.h"
#include "rmw/types.h"
#include <cstddef>

// Function Definitions
namespace coder {
ros2publisher *ros2publisher::init(const ros2node &node)
{
  static const char b_cv[8]{'k', 'e', 'e', 'p', 'l', 'a', 's', 't'};
  static const char b_cv1[8]{'v', 'o', 'l', 'a', 't', 'i', 'l', 'e'};
  static const char b_cv2[8]{'r', 'e', 'l', 'i', 'a', 'b', 'l', 'e'};
  static const char x2[8]{'r', 'e', 'l', 'i', 'a', 'b', 'l', 'e'};
  static const char resolvedTopic[6]{'/', 'p', 'u', 'l', 's', 'e'};
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  ros2publisher *obj;
  uavrt_interfaces_PulseStruct_T r;
  double qosDepth;
  int k;
  char qosReliability[8];
  bool exitg1;
  bool p;
  obj = this;
  for (k = 0; k < 6; k++) {
    obj->TopicName[k] = resolvedTopic[k];
  }
  for (k = 0; k < 8; k++) {
    obj->History[k] = b_cv[k];
  }
  obj->Depth = 1.0;
  for (k = 0; k < 8; k++) {
    obj->Reliability[k] = x2[k];
  }
  for (k = 0; k < 8; k++) {
    obj->Durability[k] = b_cv1[k];
  }
  qos_profile = rmw_qos_profile_default;
  qosDepth = obj->Depth;
  for (k = 0; k < 8; k++) {
    qosReliability[k] = obj->Reliability[k];
  }
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  for (k = 0; k < 8; k++) {
    char c;
    c = qosReliability[k];
    if ((c >= 'A') && (c <= 'Z')) {
      c = static_cast<char>(static_cast<unsigned int>(c) + 32U);
      qosReliability[k] = c;
    }
  }
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 8)) {
    if (qosReliability[k] != b_cv2[k]) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (p) {
    reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  } else {
    reliability = RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT;
  }
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)qosDepth, durability,
                 reliability);
  uavrt_interfaces_PulseStruct(r);
  obj->PublisherHelper =
      std::unique_ptr<MATLABROS2Publisher<uavrt_interfaces::msg::Pulse,
                                          uavrt_interfaces_PulseStruct_T>>(
          new MATLABROS2Publisher<uavrt_interfaces::msg::Pulse,
                                  uavrt_interfaces_PulseStruct_T>{}); //();
  MATLABROS2Publisher_createPublisher(obj->PublisherHelper, node.NodeHandle,
                                      &obj->TopicName[0], 6.0, qos_profile);
  return obj;
}

} // namespace coder

// End of code generation (ros2publisher.cpp)
