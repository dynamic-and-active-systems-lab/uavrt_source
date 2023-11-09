//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// dec2hex.cpp
//
// Code generation for function 'dec2hex'
//

// Include files
#include "dec2hex.h"
#include "dec2bin.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"

// Function Definitions
namespace coder {
void b_dec2hex(const unsigned char d[4], char s[8])
{
  char b[32];
  for (int k{0}; k < 4; k++) {
    char b_cv[8];
    unsigned char v;
    decToBinScalar(d[k], b_cv);
    for (int i{0}; i < 8; i++) {
      b[k + (i << 2)] = b_cv[i];
    }
    v = (b[k + 12] == '1');
    if (b[k + 8] == '1') {
      v = static_cast<unsigned char>(v + 2);
    }
    if (b[k + 4] == '1') {
      v = static_cast<unsigned char>(v + 4);
    }
    if (b[k] == '1') {
      v = static_cast<unsigned char>(v + 8);
    }
    if (v > 9) {
      s[k] = static_cast<char>(v + 55);
    } else {
      s[k] = static_cast<char>(v + 48);
    }
    v = (b[k + 28] == '1');
    if (b[k + 24] == '1') {
      v = static_cast<unsigned char>(v + 2);
    }
    if (b[k + 20] == '1') {
      v = static_cast<unsigned char>(v + 4);
    }
    if (b[k + 16] == '1') {
      v = static_cast<unsigned char>(v + 8);
    }
    if (v > 9) {
      s[k + 4] = static_cast<char>(v + 55);
    } else {
      s[k + 4] = static_cast<char>(v + 48);
    }
  }
}

void c_dec2hex(const unsigned char d[8], char s[16])
{
  char b[64];
  for (int k{0}; k < 8; k++) {
    char b_cv[8];
    unsigned char v;
    decToBinScalar(d[k], b_cv);
    for (int i{0}; i < 8; i++) {
      b[k + (i << 3)] = b_cv[i];
    }
    v = (b[k + 24] == '1');
    if (b[k + 16] == '1') {
      v = static_cast<unsigned char>(v + 2);
    }
    if (b[k + 8] == '1') {
      v = static_cast<unsigned char>(v + 4);
    }
    if (b[k] == '1') {
      v = static_cast<unsigned char>(v + 8);
    }
    if (v > 9) {
      s[k] = static_cast<char>(v + 55);
    } else {
      s[k] = static_cast<char>(v + 48);
    }
    v = (b[k + 56] == '1');
    if (b[k + 48] == '1') {
      v = static_cast<unsigned char>(v + 2);
    }
    if (b[k + 40] == '1') {
      v = static_cast<unsigned char>(v + 4);
    }
    if (b[k + 32] == '1') {
      v = static_cast<unsigned char>(v + 8);
    }
    if (v > 9) {
      s[k + 8] = static_cast<char>(v + 55);
    } else {
      s[k + 8] = static_cast<char>(v + 48);
    }
  }
}

void dec2hex(const unsigned char d[2], char s[4])
{
  char b[16];
  for (int k{0}; k < 2; k++) {
    char b_cv[8];
    unsigned char v;
    decToBinScalar(d[k], b_cv);
    for (int i{0}; i < 8; i++) {
      b[k + (i << 1)] = b_cv[i];
    }
    v = (b[k + 6] == '1');
    if (b[k + 4] == '1') {
      v = static_cast<unsigned char>(v + 2);
    }
    if (b[k + 2] == '1') {
      v = static_cast<unsigned char>(v + 4);
    }
    if (b[k] == '1') {
      v = static_cast<unsigned char>(v + 8);
    }
    if (v > 9) {
      s[k] = static_cast<char>(v + 55);
    } else {
      s[k] = static_cast<char>(v + 48);
    }
    v = (b[k + 14] == '1');
    if (b[k + 12] == '1') {
      v = static_cast<unsigned char>(v + 2);
    }
    if (b[k + 10] == '1') {
      v = static_cast<unsigned char>(v + 4);
    }
    if (b[k + 8] == '1') {
      v = static_cast<unsigned char>(v + 8);
    }
    if (v > 9) {
      s[k + 2] = static_cast<char>(v + 55);
    } else {
      s[k + 2] = static_cast<char>(v + 48);
    }
  }
}

void dec2hex(unsigned char d, char s[2])
{
  char b[8];
  unsigned char v;
  decToBinScalar(d, b);
  v = (b[3] == '1');
  if (b[2] == '1') {
    v = static_cast<unsigned char>(v + 2);
  }
  if (b[1] == '1') {
    v = static_cast<unsigned char>(v + 4);
  }
  if (b[0] == '1') {
    v = static_cast<unsigned char>(v + 8);
  }
  if (v > 9) {
    s[0] = static_cast<char>(v + 55);
  } else {
    s[0] = static_cast<char>(v + 48);
  }
  v = (b[7] == '1');
  if (b[6] == '1') {
    v = static_cast<unsigned char>(v + 2);
  }
  if (b[5] == '1') {
    v = static_cast<unsigned char>(v + 4);
  }
  if (b[4] == '1') {
    v = static_cast<unsigned char>(v + 8);
  }
  if (v > 9) {
    s[1] = static_cast<char>(v + 55);
  } else {
    s[1] = static_cast<char>(v + 48);
  }
}

} // namespace coder

// End of code generation (dec2hex.cpp)
