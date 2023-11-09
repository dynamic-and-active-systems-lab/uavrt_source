//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// ros2publisher.h
//
// Code generation for function 'ros2publisher'
//

#ifndef ROS2PUBLISHER_H
#define ROS2PUBLISHER_H

// Include files
#include "rtwtypes.h"
#include "mlros2_pub.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
class ros2node;

}

// Type Definitions
namespace coder {
class ros2publisher {
public:
  ros2publisher *init(const ros2node &node);
  char TopicName[6];
  char History[8];
  double Depth;
  char Reliability[8];
  char Durability[8];
  std::unique_ptr<MATLABROS2Publisher<uavrt_interfaces::msg::Pulse,
                                      uavrt_interfaces_PulseStruct_T>>
      PublisherHelper;
};

} // namespace coder

#endif
// End of code generation (ros2publisher.h)
