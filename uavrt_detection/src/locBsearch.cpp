//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// locBsearch.cpp
//
// Code generation for function 'locBsearch'
//

// Include files
#include "locBsearch.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
int b_sparse_locBsearch(const ::coder::array<int, 1U> &x, int xi, int xstart,
                        int xend, bool &found)
{
  int n;
  if (xstart < xend) {
    if (xi < x[xstart - 1]) {
      n = xstart - 1;
      found = false;
    } else {
      int high_i;
      int low_ip1;
      high_i = xend;
      n = xstart;
      low_ip1 = xstart;
      while (high_i > low_ip1 + 1) {
        int mid_i;
        mid_i = (n >> 1) + (high_i >> 1);
        if (((n & 1) == 1) && ((high_i & 1) == 1)) {
          mid_i++;
        }
        if (xi >= x[mid_i - 1]) {
          n = mid_i;
          low_ip1 = mid_i;
        } else {
          high_i = mid_i;
        }
      }
      found = (x[n - 1] == xi);
    }
  } else if (xstart == xend) {
    n = xstart - 1;
    found = false;
  } else {
    n = 0;
    found = false;
  }
  return n;
}

int sparse_locBsearch(const ::coder::array<int, 1U> &x, double xi, int xstart,
                      int xend, bool &found)
{
  int n;
  if (xstart < xend) {
    if (xi < x[xstart - 1]) {
      n = xstart - 1;
      found = false;
    } else {
      int high_i;
      int low_ip1;
      high_i = xend;
      n = xstart;
      low_ip1 = xstart;
      while (high_i > low_ip1 + 1) {
        int mid_i;
        mid_i = (n >> 1) + (high_i >> 1);
        if (((n & 1) == 1) && ((high_i & 1) == 1)) {
          mid_i++;
        }
        if (xi >= x[mid_i - 1]) {
          n = mid_i;
          low_ip1 = mid_i;
        } else {
          high_i = mid_i;
        }
      }
      found = (x[n - 1] == xi);
    }
  } else if (xstart == xend) {
    n = xstart - 1;
    found = false;
  } else {
    n = 0;
    found = false;
  }
  return n;
}

} // namespace coder

// End of code generation (locBsearch.cpp)
