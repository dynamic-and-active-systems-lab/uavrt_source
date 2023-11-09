//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// eml_randn.cpp
//
// Code generation for function 'eml_randn'
//

// Include files
#include "eml_randn.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_data.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"

// Function Definitions
void eml_randn_init()
{
  method = 0U;
  state[0] = 362436069U;
  state[1] = 521288629U;
}

// End of code generation (eml_randn.cpp)
