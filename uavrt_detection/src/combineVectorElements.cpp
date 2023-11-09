//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// combineVectorElements.cpp
//
// Code generation for function 'combineVectorElements'
//

// Include files
#include "combineVectorElements.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace coder {
double combineVectorElements(const ::coder::array<double, 1U> &x)
{
  double y;
  if (x.size(0) == 0) {
    y = 0.0;
  } else {
    int firstBlockLength;
    int lastBlockLength;
    int nblocks;
    if (x.size(0) <= 1024) {
      firstBlockLength = x.size(0);
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = static_cast<int>(static_cast<unsigned int>(x.size(0)) >> 10);
      lastBlockLength = x.size(0) - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    y = x[0];
    for (int k{2}; k <= firstBlockLength; k++) {
      y += x[k - 1];
    }
    for (int ib{2}; ib <= nblocks; ib++) {
      double bsum;
      int hi;
      firstBlockLength = (ib - 1) << 10;
      bsum = x[firstBlockLength];
      if (ib == nblocks) {
        hi = lastBlockLength;
      } else {
        hi = 1024;
      }
      for (int k{2}; k <= hi; k++) {
        bsum += x[(firstBlockLength + k) - 1];
      }
      y += bsum;
    }
  }
  return y;
}

double combineVectorElements(const ::coder::array<double, 1U> &x, int &counts)
{
  double y;
  if (x.size(0) == 0) {
    y = 0.0;
    counts = 0;
  } else {
    double bsum;
    int firstBlockLength;
    int lastBlockLength;
    int nblocks;
    if (x.size(0) <= 1024) {
      firstBlockLength = x.size(0);
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = static_cast<int>(static_cast<unsigned int>(x.size(0)) >> 10);
      lastBlockLength = x.size(0) - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    if (std::isnan(x[0])) {
      y = 0.0;
      counts = 0;
    } else {
      y = x[0];
      counts = 1;
    }
    for (int k{2}; k <= firstBlockLength; k++) {
      bsum = x[k - 1];
      if (!std::isnan(bsum)) {
        y += bsum;
        counts++;
      }
    }
    for (int ib{2}; ib <= nblocks; ib++) {
      int hi;
      firstBlockLength = (ib - 1) << 10;
      if (std::isnan(x[firstBlockLength])) {
        bsum = 0.0;
      } else {
        bsum = x[firstBlockLength];
        counts++;
      }
      if (ib == nblocks) {
        hi = lastBlockLength;
      } else {
        hi = 1024;
      }
      for (int k{2}; k <= hi; k++) {
        int xoffset;
        xoffset = (firstBlockLength + k) - 1;
        if (!std::isnan(x[xoffset])) {
          bsum += x[xoffset];
          counts++;
        }
      }
      y += bsum;
    }
  }
  return y;
}

} // namespace coder

// End of code generation (combineVectorElements.cpp)
