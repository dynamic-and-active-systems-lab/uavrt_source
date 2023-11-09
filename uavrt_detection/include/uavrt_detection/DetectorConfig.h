//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// DetectorConfig.h
//
// Code generation for function 'DetectorConfig'
//

#ifndef DETECTORCONFIG_H
#define DETECTORCONFIG_H

// Include files
#include "rtwtypes.h"
#include "string1.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
class DetectorConfig {
public:
  void init();
  double ID;
  double channelCenterFreqMHz;
  double portData;
  double portCntrl;
  double Fs;
  double tagFreqMHz;
  double tp;
  double tip;
  double tipu;
  double tipj;
  double K;
  coder::b_rtString opMode;
  coder::array<double, 2U> excldFreqs;
  double falseAlarmProb;
  coder::b_rtString dataRecordPath;
  bool startInRunState;
};

#endif
// End of code generation (DetectorConfig.h)
