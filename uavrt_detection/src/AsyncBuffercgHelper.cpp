//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// AsyncBuffercgHelper.cpp
//
// Code generation for function 'AsyncBuffercgHelper'
//

// Include files
#include "AsyncBuffercgHelper.h"
#include "colon.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
namespace dsp {
namespace internal {
AsyncBuffercgHelper::AsyncBuffercgHelper()
{
  matlabCodegenIsDeleted = true;
}

b_AsyncBuffercgHelper::b_AsyncBuffercgHelper()
{
  matlabCodegenIsDeleted = true;
}

c_AsyncBuffercgHelper::c_AsyncBuffercgHelper()
{
  matlabCodegenIsDeleted = true;
}

AsyncBuffercgHelper::~AsyncBuffercgHelper()
{
  matlabCodegenDestructor();
}

b_AsyncBuffercgHelper::~b_AsyncBuffercgHelper()
{
  matlabCodegenDestructor();
}

c_AsyncBuffercgHelper::~c_AsyncBuffercgHelper()
{
  matlabCodegenDestructor();
}

void AsyncBuffercgHelper::matlabCodegenDestructor()
{
  if (!matlabCodegenIsDeleted) {
    matlabCodegenIsDeleted = true;
    if (isInitialized == 1) {
      isInitialized = 2;
      if (isSetupComplete) {
        ReadPointer = 1;
        WritePointer = 2;
        CumulativeOverrun = 0;
        CumulativeUnderrun = 0;
        AsyncBuffercgHelper_isInitialized = false;
        NumChannels = -1;
      }
    }
  }
}

void b_AsyncBuffercgHelper::matlabCodegenDestructor()
{
  if (!matlabCodegenIsDeleted) {
    matlabCodegenIsDeleted = true;
    if (isInitialized == 1) {
      isInitialized = 2;
      if (isSetupComplete) {
        ReadPointer = 1;
        WritePointer = 2;
        CumulativeOverrun = 0;
        CumulativeUnderrun = 0;
        AsyncBuffercgHelper_isInitialized = false;
        NumChannels = -1;
      }
    }
  }
}

void c_AsyncBuffercgHelper::matlabCodegenDestructor()
{
  if (!matlabCodegenIsDeleted) {
    matlabCodegenIsDeleted = true;
    if (isInitialized == 1) {
      isInitialized = 2;
      if (isSetupComplete) {
        ReadPointer = 1;
        WritePointer = 2;
        CumulativeOverrun = 0;
        CumulativeUnderrun = 0;
        AsyncBuffercgHelper_isInitialized = false;
        NumChannels = -1;
      }
    }
  }
}

int c_AsyncBuffercgHelper::read(int numRows, ::coder::array<creal32_T, 1U> &out)
{
  static rtBoundsCheckInfo cb_emlrtBCI{
      1,                                           // iFirst
      600651,                                      // iLast
      457,                                         // lineNo
      29,                                          // colNo
      "",                                          // aName
      "AsyncBuffercgHelper/ReadSamplesFromBuffer", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/dsp/dsp/+dsp/+internal/"
      "AsyncBuffercgHelper.m", // pName
      0                        // checkKind
  };
  array<int, 2U> b_y;
  array<int, 2U> readIdx;
  array<int, 2U> y;
  int c;
  int k;
  int rPtr;
  int underrun;
  int wPtr_tmp;
  int yk;
  if (!AsyncBuffercgHelper_isInitialized) {
    p_rtErrorWithMessageID(v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
  }
  wPtr_tmp = WritePointer;
  underrun = 0;
  yk = ReadPointer;
  if (yk > 2147483646) {
    rPtr = MAX_int32_T;
  } else {
    rPtr = yk + 1;
  }
  if (rPtr > 600651) {
    rPtr = 1;
  }
  if ((wPtr_tmp < 1) || (wPtr_tmp > 600651) || (rPtr < 1) ||
      (numRows > 600651)) {
    rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
  }
  c = (rPtr + numRows) - 1;
  if (c > 600651) {
    c -= 600651;
    eml_integer_colon_dispatcher(rPtr, y);
    b_y.set_size(1, c);
    b_y[0] = 1;
    yk = 1;
    for (k = 2; k <= c; k++) {
      yk++;
      b_y[k - 1] = yk;
    }
    readIdx.set_size(1, y.size(1) + b_y.size(1));
    yk = y.size(1);
    for (k = 0; k < yk; k++) {
      readIdx[k] = y[k];
    }
    yk = b_y.size(1);
    for (k = 0; k < yk; k++) {
      readIdx[k + y.size(1)] = b_y[k];
    }
    if (rPtr <= wPtr_tmp) {
      underrun = (c - wPtr_tmp) + 600652;
    } else if (wPtr_tmp <= c) {
      underrun = (c - wPtr_tmp) + 1;
    }
  } else {
    eml_integer_colon_dispatcher(rPtr, c, readIdx);
    if ((rPtr <= wPtr_tmp) && (wPtr_tmp <= c)) {
      underrun = (c - wPtr_tmp) + 1;
    }
  }
  out.set_size(readIdx.size(1));
  yk = readIdx.size(1);
  for (k = 0; k < yk; k++) {
    bool b;
    b = ((readIdx[k] < 1) || (readIdx[k] > 600651));
    if (b) {
      rtDynamicBoundsError(readIdx[k], 1, 600651, cb_emlrtBCI);
    }
    out[k].re = Cache[readIdx[k] - 1].re;
    out[k].im = Cache[readIdx[k] - 1].im;
  }
  if (underrun != 0) {
    if ((numRows >= 0) && (underrun < numRows - MAX_int32_T)) {
      yk = MAX_int32_T;
    } else if ((numRows < 0) && (underrun > numRows - MIN_int32_T)) {
      yk = MIN_int32_T;
    } else {
      yk = numRows - underrun;
    }
    if (yk + 1 > numRows) {
      yk = 0;
      k = 0;
    } else {
      if ((yk + 1 < 1) || (yk + 1 > readIdx.size(1))) {
        rtDynamicBoundsError(yk + 1, 1, readIdx.size(1), d_emlrtBCI);
      }
      if ((numRows < 1) || (numRows > readIdx.size(1))) {
        rtDynamicBoundsError(numRows, 1, readIdx.size(1), c_emlrtBCI);
      }
      k = numRows;
    }
    if (underrun < 0) {
      rtNonNegativeError(static_cast<double>(underrun), emlrtDCI);
    }
    k -= yk;
    rtSubAssignSizeCheck(&k, 1, &underrun, 1, b_emlrtECI);
    for (k = 0; k < underrun; k++) {
      rPtr = yk + k;
      out[rPtr].re = 0.0F;
      out[rPtr].im = 0.0F;
    }
  }
  if (out.size(0) != numRows) {
    h_rtErrorWithMessageID(u_emlrtRTEI.fName, u_emlrtRTEI.lineNo);
  }
  yk = CumulativeUnderrun;
  if ((yk < 0) && (underrun < MIN_int32_T - yk)) {
    yk = MIN_int32_T;
  } else if ((yk > 0) && (underrun > MAX_int32_T - yk)) {
    yk = MAX_int32_T;
  } else {
    yk += underrun;
  }
  CumulativeUnderrun = yk;
  if (underrun != 0) {
    ReadPointer = wPtr_tmp - 1;
  } else {
    ReadPointer = c;
  }
  return underrun;
}

} // namespace internal
} // namespace dsp
} // namespace coder

// End of code generation (AsyncBuffercgHelper.cpp)
