//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// DetectorConfig.cpp
//
// Code generation for function 'DetectorConfig'
//

// Include files
#include "DetectorConfig.h"
#include "rt_nonfinite.h"
#include "string1.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"

// Function Definitions
void DetectorConfig::init()
{
  ID = 1.0;
  channelCenterFreqMHz = 150.0;
  portData = 1.0;
  portCntrl = 1.0;
  Fs = 192000.0;
  tagFreqMHz = 150.0;
  tp = 0.02;
  tip = 1.0;
  tipu = 0.0;
  tipj = 0.0;
  K = 1.0;
  opMode.init();
  excldFreqs.set_size(1, 2);
  excldFreqs[0] = rtInf;
  excldFreqs[1] = rtMinusInf;
  falseAlarmProb = 0.01;
  dataRecordPath.Value.set_size(1, 0);
  startInRunState = false;
}

// End of code generation (DetectorConfig.cpp)
