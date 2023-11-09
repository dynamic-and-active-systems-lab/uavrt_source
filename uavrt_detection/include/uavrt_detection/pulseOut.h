//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// pulseOut.h
//
// Code generation for function 'pulseOut'
//

#ifndef PULSEOUT_H
#define PULSEOUT_H

// Include files
#include "rtwtypes.h"
#include "string1.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
class pulseOut {
public:
  void init(double detectorPulse_SNR, double detectorPulse_yw,
            double detectorPulse_t_0, double detectorPulse_t_f,
            const double detectorPulse_t_next[2], double detectorPulse_fp,
            bool detectorPulse_det_dec, bool detectorPulse_con_dec,
            double tagID, const coder::array<char, 2U> &detectorDir,
            double channelCenterFreq, double groupInd, double groupSNR);
  void formatForTunnelMsg(unsigned char mavlinkTunnelMsgUint8[53]) const;
  void b_init();
  unsigned int tag_id;
  coder::b_rtString detector_dir;
  double frequency;
  int start_time_sec;
  unsigned int start_time_nanosec;
  int end_time_sec;
  unsigned int end_time_nanosec;
  int predict_next_start_sec;
  unsigned int predict_next_start_nanosec;
  int predict_next_end_sec;
  unsigned int predict_next_end_nanosec;
  double snr;
  double stft_score;
  unsigned short group_ind;
  double group_snr;
  bool detection_status;
  bool confirmed_status;
};

#endif
// End of code generation (pulseOut.h)
