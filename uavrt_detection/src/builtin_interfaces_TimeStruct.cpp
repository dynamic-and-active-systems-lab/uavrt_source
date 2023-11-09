//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// builtin_interfaces_TimeStruct.cpp
//
// Code generation for function 'builtin_interfaces_TimeStruct'
//

// Include files
#include "builtin_interfaces_TimeStruct.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"

// Function Definitions
builtin_interfaces_TimeStruct_T builtin_interfaces_TimeStruct()
{
  static const builtin_interfaces_TimeStruct_T b_msg{
      {'b', 'u', 'i', 'l', 't', 'i', 'n', '_', 'i', 'n', 't', 'e',
       'r', 'f', 'a', 'c', 'e', 's', '/', 'T', 'i', 'm', 'e'}, // MessageType
      0,                                                       // sec
      0U                                                       // nanosec
  };
  builtin_interfaces_TimeStruct_T msg;
  msg = b_msg;
  //  Message struct definition for builtin_interfaces/Time
  //(&b_msg);
  return msg;
}

// End of code generation (builtin_interfaces_TimeStruct.cpp)
