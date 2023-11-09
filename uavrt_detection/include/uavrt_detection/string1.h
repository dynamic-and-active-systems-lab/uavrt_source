//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// string1.h
//
// Code generation for function 'string1'
//

#ifndef STRING1_H
#define STRING1_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
class rtString {
public:
  void init();
  char Value[25];
};

class b_rtString {
public:
  bool eq() const;
  bool b_eq() const;
  bool c_eq() const;
  bool d_eq() const;
  void init();
  array<char, 2U> Value;
};

} // namespace coder

#endif
// End of code generation (string1.h)
