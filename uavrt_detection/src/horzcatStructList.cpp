//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// horzcatStructList.cpp
//
// Code generation for function 'horzcatStructList'
//

// Include files
#include "horzcatStructList.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_internal_types.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
namespace internal {
void b_horzcatStructList(const ::coder::array<c_struct_T, 1U> &structure,
                         ::coder::array<double, 2U> &result)
{
  int j;
  int n;
  n = structure.size(0);
  if (structure.size(0) == 0) {
    j = 0;
  } else {
    j = structure.size(0);
  }
  result.set_size(1, j);
  j = 0;
  if (structure.size(0) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int i{0}; i < n; i++) {
    result[result.size(0) * j] = structure[i].t_0;
    j++;
  }
}

void b_horzcatStructList(const ::coder::array<c_struct_T, 2U> &structure,
                         ::coder::array<double, 2U> &result)
{
  int j;
  int n;
  n = structure.size(1);
  if (structure.size(1) == 0) {
    j = 0;
  } else {
    j = structure.size(1);
  }
  result.set_size(1, j);
  j = 0;
  if (structure.size(1) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int i{0}; i < n; i++) {
    result[result.size(0) * j] = structure[i].fp;
    j++;
  }
}

void c_horzcatStructList(const ::coder::array<c_struct_T, 2U> &structure,
                         ::coder::array<bool, 2U> &result)
{
  int j;
  int n;
  n = structure.size(1);
  if (structure.size(1) == 0) {
    j = 0;
  } else {
    j = structure.size(1);
  }
  result.set_size(1, j);
  j = 0;
  if (structure.size(1) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int i{0}; i < n; i++) {
    result[result.size(0) * j] = structure[i].con_dec;
    j++;
  }
}

void d_horzcatStructList(const ::coder::array<c_struct_T, 1U> &structure,
                         ::coder::array<double, 2U> &result)
{
  int j;
  int n;
  n = structure.size(0);
  if (structure.size(0) == 0) {
    j = 0;
  } else {
    j = structure.size(0);
  }
  result.set_size(1, j);
  j = 0;
  if (structure.size(0) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int i{0}; i < n; i++) {
    result[result.size(0) * j] = structure[i].SNR;
    j++;
  }
}

void d_horzcatStructList(const ::coder::array<c_struct_T, 2U> &structure,
                         ::coder::array<double, 2U> &result)
{
  int j;
  int n;
  n = structure.size(1);
  if (structure.size(1) == 0) {
    j = 0;
  } else {
    j = structure.size(1);
  }
  result.set_size(1, j);
  j = 0;
  if (structure.size(1) > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int i{0}; i < n; i++) {
    result[result.size(0) * j] = structure[i].t_0;
    j++;
  }
}

void horzcatStructList(const ::coder::array<c_struct_T, 2U> &structure,
                       ::coder::array<bool, 2U> &result)
{
  static rtDoubleCheckInfo w_emlrtDCI{
      21,                       // lineNo
      77,                       // colNo
      "matlabCodegenAllocLike", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/"
      "matlabCodegenAllocLike.m", // pName
      4                           // checkKind
  };
  int j;
  int n_tmp;
  n_tmp = structure.size(0) * structure.size(1);
  result.set_size(1, result.size(1));
  if (n_tmp == 0) {
    j = 0;
  } else {
    j = n_tmp;
  }
  if (j < 0) {
    rtNonNegativeError(static_cast<double>(j), w_emlrtDCI);
  }
  result.set_size(result.size(0), j);
  j = 0;
  if (n_tmp > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int i{0}; i < n_tmp; i++) {
    result[result.size(0) * j] = structure[i].det_dec;
    j++;
  }
}

} // namespace internal
} // namespace coder

// End of code generation (horzcatStructList.cpp)
