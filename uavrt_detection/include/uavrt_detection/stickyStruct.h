//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// stickyStruct.h
//
// Code generation for function 'stickyStruct'
//

#ifndef STICKYSTRUCT_H
#define STICKYSTRUCT_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
namespace internal {
class stickyStruct {
public:
  double value;
};

class b_stickyStruct {
public:
  stickyStruct next;
};

class c_stickyStruct {
public:
  b_stickyStruct next;
};

class d_stickyStruct {
public:
  c_stickyStruct next;
};

class e_stickyStruct {
public:
  d_stickyStruct next;
};

class f_stickyStruct {
public:
  e_stickyStruct next;
};

class g_stickyStruct {
public:
  f_stickyStruct next;
};

class h_stickyStruct {
public:
  double value;
  g_stickyStruct next;
};

class i_stickyStruct {
public:
  h_stickyStruct next;
};

class j_stickyStruct {
public:
  array<float, 1U> value;
  i_stickyStruct next;
};

} // namespace internal
} // namespace coder

#endif
// End of code generation (stickyStruct.h)
