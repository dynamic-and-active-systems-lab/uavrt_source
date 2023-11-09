//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// ros2node.cpp
//
// Code generation for function 'ros2node'
//

// Include files
#include "ros2node.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "mlros2_node.h"

// Function Definitions
namespace coder {
ros2node *ros2node::init()
{
  ros2node *obj;
  obj = this;
  obj->NodeHandle = MATLAB::getGlobalNodeHandle();
  UNUSED_PARAM(obj->NodeHandle);
  return obj;
}

} // namespace coder

// End of code generation (ros2node.cpp)
