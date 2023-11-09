//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// string1.cpp
//
// Code generation for function 'string1'
//

// Include files
#include "string1.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_data.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"

// Variable Definitions
static const char cv4[18]{'f', 'r', 'e', 'q', 'S', 'e', 'a', 'r', 'c',
                          'h', 'H', 'a', 'r', 'd', 'L', 'o', 'c', 'k'};

// Function Definitions
namespace coder {
bool b_rtString::b_eq() const
{
  static const char b_cv[17]{'f', 'r', 'e', 'q', 'K', 'n', 'o', 'w', 'n',
                             'H', 'a', 'r', 'd', 'L', 'o', 'c', 'k'};
  bool equal;
  equal = false;
  if (Value.size(1) == 17) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 17) {
        if (b_cv[kstr] != Value[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        equal = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return equal;
}

bool b_rtString::c_eq() const
{
  bool equal;
  equal = false;
  if (Value.size(1) == 18) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 18) {
        if (cv5[kstr] != Value[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        equal = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return equal;
}

bool b_rtString::d_eq() const
{
  static const char b_cv[13]{'f', 'r', 'e', 'q', 'A', 'l', 'l',
                             'N', 'o', 'L', 'o', 'c', 'k'};
  bool equal;
  equal = false;
  if (Value.size(1) == 13) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 13) {
        if (b_cv[kstr] != Value[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        equal = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return equal;
}

bool b_rtString::eq() const
{
  bool equal;
  equal = false;
  if (Value.size(1) == 18) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 18) {
        if (cv4[kstr] != Value[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        equal = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return equal;
}

void rtString::init()
{
  static const char b_cv[25]{'c', 'o', 'n', 'f', 'i', 'g', '/', 'd', 'e',
                             't', 'e', 'c', 't', 'o', 'r', 'C', 'o', 'n',
                             'f', 'i', 'g', '.', 't', 'x', 't'};
  for (int i{0}; i < 25; i++) {
    Value[i] = b_cv[i];
  }
}

void b_rtString::init()
{
  Value.set_size(1, 18);
  for (int i{0}; i < 18; i++) {
    Value[i] = cv4[i];
  }
}

} // namespace coder

// End of code generation (string1.cpp)
