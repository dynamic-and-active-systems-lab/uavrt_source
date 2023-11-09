//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// bigProduct.cpp
//
// Code generation for function 'bigProduct'
//

// Include files
#include "bigProduct.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"

// Function Definitions
namespace coder {
namespace internal {
int b_bigProduct(int a, int b, int &highorderbits)
{
  int highOrderA;
  int highOrderB;
  int lowOrderB;
  int loworderbits;
  int partialResults_idx_0;
  int partialResults_idx_1;
  int partialResults_idx_2;
  int tmp;
  loworderbits = 0;
  highOrderA = a >> 16;
  partialResults_idx_2 = a & 65535;
  highOrderB = b >> 16;
  lowOrderB = b & 65535;
  partialResults_idx_0 = partialResults_idx_2 * lowOrderB;
  tmp = partialResults_idx_2 * highOrderB;
  partialResults_idx_1 = tmp << 16;
  highorderbits = tmp >> 16;
  if (highorderbits <= 0) {
    tmp = highOrderA * lowOrderB;
    partialResults_idx_2 = tmp << 16;
    highorderbits += tmp >> 16;
    if (highorderbits <= 0) {
      highorderbits += highOrderA * highOrderB;
      if (highorderbits <= 0) {
        if (MAX_int32_T - partialResults_idx_0 < 0) {
          loworderbits = partialResults_idx_0 - MAX_int32_T;
          highorderbits++;
        } else {
          loworderbits = partialResults_idx_0;
        }
        if (loworderbits > MAX_int32_T - partialResults_idx_1) {
          loworderbits = (loworderbits + partialResults_idx_1) - MAX_int32_T;
          highorderbits++;
        } else {
          loworderbits += partialResults_idx_1;
        }
        if (loworderbits > MAX_int32_T - partialResults_idx_2) {
          loworderbits = (loworderbits + partialResults_idx_2) - MAX_int32_T;
          highorderbits++;
        } else {
          loworderbits += partialResults_idx_2;
        }
      }
    }
  }
  return loworderbits;
}

int bigProduct(int a, int b, int &highorderbits)
{
  int highOrderA;
  int highOrderB;
  int lowOrderB;
  int loworderbits;
  int partialResults_idx_1;
  int partialResults_idx_2;
  int tmp;
  highOrderA = a >> 16;
  partialResults_idx_2 = a & 65535;
  highOrderB = b >> 16;
  lowOrderB = b & 65535;
  loworderbits = partialResults_idx_2 * lowOrderB;
  tmp = partialResults_idx_2 * highOrderB;
  partialResults_idx_1 = tmp << 16;
  highorderbits = tmp >> 16;
  tmp = highOrderA * lowOrderB;
  partialResults_idx_2 = tmp << 16;
  highorderbits += tmp >> 16;
  highorderbits += highOrderA * highOrderB;
  if (MAX_int32_T - loworderbits < 0) {
    loworderbits -= MAX_int32_T;
    highorderbits++;
  }
  if (loworderbits > MAX_int32_T - partialResults_idx_1) {
    loworderbits = (loworderbits + partialResults_idx_1) - MAX_int32_T;
    highorderbits++;
  } else {
    loworderbits += partialResults_idx_1;
  }
  if (loworderbits > MAX_int32_T - partialResults_idx_2) {
    loworderbits = (loworderbits + partialResults_idx_2) - MAX_int32_T;
    highorderbits++;
  } else {
    loworderbits += partialResults_idx_2;
  }
  return loworderbits;
}

} // namespace internal
} // namespace coder

// End of code generation (bigProduct.cpp)
