//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// uavrt_detection_internal_types.h
//
// Code generation for function 'uavrt_detection'
//

#ifndef UAVRT_DETECTION_INTERNAL_TYPES_H
#define UAVRT_DETECTION_INTERNAL_TYPES_H

// Include files
#include "rtwtypes.h"
#include "uavrt_detection_types.h"
#include "coder_array.h"

// Type Definitions
struct struct_T {
  int xstart;
  int xend;
  int depth;
};

struct b_struct_T {
  double mu;
  double sigma;
  double pf;
};

struct dsp_UDPSender_0 {
  int S0_isInitialized;
  double W0_NetworkLib[137];
  int P0_Port;
};

struct cell_wrap_2 {
  unsigned int f1[8];
};

struct c_struct_T {
  double A;
  double P;
  double SNR;
  double yw;
  double t_0;
  double t_f;
  double t_next[2];
  double fp;
  double fstart;
  double fend;
  coder::array<char, 2U> mode;
  bool det_dec;
  bool con_dec;
};

struct d_struct_T {
  coder::array<int, 1U> a;
  coder::array<int, 1U> b;
};

struct e_struct_T {
  coder::array<int, 1U> x;
};

struct f_struct_T {
  double sb;
};

#endif
// End of code generation (uavrt_detection_internal_types.h)
