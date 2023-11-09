//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// uavrt_detection_types.h
//
// Code generation for function 'uavrt_detection'
//

#ifndef UAVRT_DETECTION_TYPES_H
#define UAVRT_DETECTION_TYPES_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"

// Type Definitions
struct builtin_interfaces_TimeStruct_T {
  char MessageType[23];
  int sec;
  unsigned int nanosec;
};

struct rtRunTimeErrorInfo {
  int lineNo;
  int colNo;
  const char *fName;
  const char *pName;
};

struct rtEqualityCheckInfo {
  int nDims;
  int lineNo;
  int colNo;
  const char *fName;
  const char *pName;
};

struct rtBoundsCheckInfo {
  int iFirst;
  int iLast;
  int lineNo;
  int colNo;
  const char *aName;
  const char *fName;
  const char *pName;
  int checkKind;
};

struct rtDoubleCheckInfo {
  int lineNo;
  int colNo;
  const char *fName;
  const char *pName;
  int checkKind;
};

struct dsp_UDPReceiver_2 {
  int S0_isInitialized;
  double W0_NetworkLib[137];
  int P0_Port;
  coder::array<creal32_T, 2U> O0_Y0;
};

struct dsp_UDPReceiver_4 {
  int S0_isInitialized;
  double W0_NetworkLib[137];
  int P0_Port;
  coder::array<signed char, 2U> O0_Y0;
};

struct uavrt_interfaces_PulseStruct_T {
  char MessageType[22];
  coder::array<char, 2U> detector_dir;
  unsigned int tag_id;
  double frequency;
  builtin_interfaces_TimeStruct_T start_time;
  builtin_interfaces_TimeStruct_T end_time;
  builtin_interfaces_TimeStruct_T predict_next_start;
  builtin_interfaces_TimeStruct_T predict_next_end;
  double snr;
  double stft_score;
  unsigned short group_ind;
  double group_snr;
  bool detection_status;
  bool confirmed_status;
};

#endif
// End of code generation (uavrt_detection_types.h)
