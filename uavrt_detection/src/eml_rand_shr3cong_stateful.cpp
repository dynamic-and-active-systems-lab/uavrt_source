//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// eml_rand_shr3cong_stateful.cpp
//
// Code generation for function 'eml_rand_shr3cong_stateful'
//

// Include files
#include "eml_rand_shr3cong_stateful.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_data.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"

// Function Definitions
void eml_rand_shr3cong_stateful_init()
{
  c_state[0] = 362436069U;
  c_state[1] = 521288629U;
}

// End of code generation (eml_rand_shr3cong_stateful.cpp)
