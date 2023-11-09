//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// weightingmatrix.cpp
//
// Code generation for function 'weightingmatrix'
//

// Include files
#include "weightingmatrix.h"
#include "fft.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"

// Function Definitions
void binary_expand_op(coder::array<creal_T, 2U> &in1,
                      const coder::array<creal_T, 2U> &in2, int in3,
                      const coder::array<double, 2U> &in4)
{
  coder::array<creal_T, 2U> b_in2;
  int b_loop_ub;
  int in2_idx_0;
  int loop_ub;
  int stride_1_0;
  in2_idx_0 = in2.size(0);
  if (in4.size(0) == 1) {
    loop_ub = in2_idx_0;
  } else {
    loop_ub = in4.size(0);
  }
  b_in2.set_size(loop_ub, in4.size(1));
  in2_idx_0 = (in2_idx_0 != 1);
  stride_1_0 = (in4.size(0) != 1);
  b_loop_ub = in4.size(1);
  for (int i{0}; i < b_loop_ub; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      double d;
      int i2;
      d = in4[i1 * stride_1_0 + in4.size(0) * i];
      i2 = i1 * in2_idx_0;
      b_in2[i1 + b_in2.size(0) * i].re = d * in2[i2 + in2.size(0) * in3].re;
      b_in2[i1 + b_in2.size(0) * i].im = d * in2[i2 + in2.size(0) * in3].im;
    }
  }
  coder::fft(b_in2, in1);
}

// End of code generation (weightingmatrix.cpp)
