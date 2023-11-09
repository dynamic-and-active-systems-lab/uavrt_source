//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// dec2hex.h
//
// Code generation for function 'dec2hex'
//

#ifndef DEC2HEX_H
#define DEC2HEX_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void b_dec2hex(const unsigned char d[4], char s[8]);

void c_dec2hex(const unsigned char d[8], char s[16]);

void dec2hex(const unsigned char d[2], char s[4]);

void dec2hex(unsigned char d, char s[2]);

} // namespace coder

#endif
// End of code generation (dec2hex.h)
