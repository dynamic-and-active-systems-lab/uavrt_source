//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// assembleWq.cpp
//
// Code generation for function 'assembleWq'
//

// Include files
#include "assembleWq.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"

// Function Definitions
void plus(coder::array<double, 2U> &in1, const coder::array<double, 2U> &in2)
{
  coder::array<double, 2U> b_in1;
  int aux_0_1;
  int aux_1_1;
  int b_loop_ub;
  int loop_ub;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  int stride_1_1;
  if (in2.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2.size(0);
  }
  if (in2.size(1) == 1) {
    b_loop_ub = in1.size(1);
  } else {
    b_loop_ub = in2.size(1);
  }
  b_in1.set_size(loop_ub, b_loop_ub);
  stride_0_0 = (in1.size(0) != 1);
  stride_0_1 = (in1.size(1) != 1);
  stride_1_0 = (in2.size(0) != 1);
  stride_1_1 = (in2.size(1) != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (int i{0}; i < b_loop_ub; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      b_in1[i1 + b_in1.size(0) * i] =
          in1[i1 * stride_0_0 + in1.size(0) * aux_0_1] +
          in2[i1 * stride_1_0 + in2.size(0) * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  in1.set_size(b_in1.size(0), b_in1.size(1));
  loop_ub = b_in1.size(1);
  for (int i{0}; i < loop_ub; i++) {
    b_loop_ub = b_in1.size(0);
    for (int i1{0}; i1 < b_loop_ub; i1++) {
      in1[i1 + in1.size(0) * i] = b_in1[i1 + b_in1.size(0) * i];
    }
  }
}

// End of code generation (assembleWq.cpp)
