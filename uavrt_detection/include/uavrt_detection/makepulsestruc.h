//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// makepulsestruc.h
//
// Code generation for function 'makepulsestruc'
//

#ifndef MAKEPULSESTRUC_H
#define MAKEPULSESTRUC_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct c_struct_T;

// Function Declarations
void b_makepulsestruc(double A, double yw, double SNR, double t_0, double t_f,
                      const double t_next[2], double fp, double fstart,
                      double fend, c_struct_T *thepulse);

double makepulsestruc(double thepulse_t_next[2],
                      coder::array<char, 2U> &thepulse_mode, double &thepulse_P,
                      double &thepulse_SNR, double &thepulse_yw,
                      double &thepulse_t_0, double &thepulse_t_f,
                      double &thepulse_fp, double &thepulse_fstart,
                      double &thepulse_fend, bool &thepulse_det_dec,
                      bool &thepulse_con_dec);

#endif
// End of code generation (makepulsestruc.h)
