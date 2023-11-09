//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// wfmstft.h
//
// Code generation for function 'wfmstft'
//

#ifndef WFMSTFT_H
#define WFMSTFT_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
class wfmstft {
public:
  void updatepsd();
  coder::array<creal_T, 2U> S;
  coder::array<double, 1U> f;
  coder::array<double, 1U> t;
  coder::array<double, 1U> psd;
  double dt;
  double T;
  coder::array<double, 1U> wind;
};

#endif
// End of code generation (wfmstft.h)
