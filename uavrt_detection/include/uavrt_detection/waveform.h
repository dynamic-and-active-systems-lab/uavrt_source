//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// waveform.h
//
// Code generation for function 'waveform'
//

#ifndef WAVEFORM_H
#define WAVEFORM_H

// Include files
#include "pulsestats.h"
#include "rtwtypes.h"
#include "threshold.h"
#include "wfmstft.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct c_struct_T;

// Type Definitions
class waveform {
public:
  void setprioridependentprops(const pulsestats *ps_obj);
  void setweightingmatrix();
  void process(char mode, const coder::array<double, 2U> &excluded_freq_bands);
  void findpulse(const coder::array<char, 2U> &time_searchtype,
                 const coder::array<char, 2U> &freq_searchtype,
                 const coder::array<double, 2U> &excluded_freq_bands_in,
                 coder::array<c_struct_T, 2U> &pl_out,
                 coder::array<bool, 2U> &indiv_msk,
                 coder::array<double, 1U> &peak_ind) const;
  void spectro(wfmstft &iobj_0);
  waveform *init(const creal32_T b_x[1000], double b_Fs, pulsestats *b_ps_pre,
                 const threshold &b_thresh);
  waveform *init(const coder::array<creal32_T, 1U> &b_x, double b_Fs,
                 double b_t_0, pulsestats *b_ps_pre, const threshold &b_thresh,
                 pulsestats &iobj_0, wfmstft &iobj_1);
  pulsestats *ps_pre;
  pulsestats *ps_pos;
  double K;
  threshold thresh;
  coder::array<creal32_T, 2U> x;
  double Fs;
  double l;
  double t_0;
  double t_f;
  double t_nextsegstart[2];
  wfmstft *stft;
  double OLF;
  coder::array<creal_T, 2U> W;
  coder::array<double, 1U> Wf;
  double n_p;
  double n_w;
  double n_ol;
  double n_ws;
  double t_ws;
  double n_ip;
  double N;
  double M;
  double J;
  pulsestats _pobj0;
  wfmstft _pobj1;
};

class b_waveform {
public:
  void spectro(wfmstft &iobj_0);
  b_waveform *init(const creal32_T b_x[1000], double b_Fs, pulsestats *b_ps_pre,
                   pulsestats &iobj_0, wfmstft &iobj_1);
  pulsestats *ps_pre;
  pulsestats *ps_pos;
  double K;
  coder::array<creal32_T, 2U> x;
  double Fs;
  double t_0;
  wfmstft *stft;
  double OLF;
  double n_w;
  double n_ol;
};

#endif
// End of code generation (waveform.h)
