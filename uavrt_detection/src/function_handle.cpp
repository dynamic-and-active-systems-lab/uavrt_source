//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// function_handle.cpp
//
// Code generation for function 'function_handle'
//

// Include files
#include "function_handle.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "threshold.h"
#include "waveform.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"

// Function Definitions
bool binary_expand_op(const coder::array<double, 1U> &in1, const waveform *in2)
{
  coder::array<bool, 1U> b_in1;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  bool exitg1;
  bool out1;
  if (in2->thresh.threshVecFine.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2->thresh.threshVecFine.size(0);
  }
  b_in1.set_size(loop_ub);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2->thresh.threshVecFine.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    b_in1[i] =
        (in1[i * stride_0_0] > in2->thresh.threshVecFine[i * stride_1_0]);
  }
  out1 = false;
  if (b_in1.size(0) > 2147483646) {
    coder::check_forloop_overflow_error();
  }
  loop_ub = 1;
  exitg1 = false;
  while ((!exitg1) && (loop_ub <= b_in1.size(0))) {
    if (b_in1[loop_ub - 1]) {
      out1 = true;
      exitg1 = true;
    } else {
      loop_ub++;
    }
  }
  return out1;
}

void k_binary_expand_op(const coder::array<bool, 1U> &in1,
                        const coder::array<bool, 1U> &in2)
{
  coder::array<bool, 1U> b_in1;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in2.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2.size(0);
  }
  b_in1.set_size(loop_ub);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  for (int i{0}; i < loop_ub; i++) {
    b_in1[i] = (in1[i * stride_0_0] && in2[i * stride_1_0]);
  }
  if (b_in1.size(0) > 2147483646) {
    coder::check_forloop_overflow_error();
  }
}

// End of code generation (function_handle.cpp)
