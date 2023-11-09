//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// AsyncBuffer.cpp
//
// Code generation for function 'AsyncBuffer'
//

// Include files
#include "AsyncBuffer.h"
#include "AsyncBuffercgHelper.h"
#include "colon.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_internal_types.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>
#include <sstream>
#include <stdexcept>
#include <string>

// Variable Definitions
static rtRunTimeErrorInfo p_emlrtRTEI{
    101,                                      // lineNo
    13,                                       // colNo
    "AsyncBuffercgHelper/validateInputsImpl", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/dsp/dsp/+dsp/+internal/"
    "AsyncBuffercgHelper.m" // pName
};

static rtRunTimeErrorInfo q_emlrtRTEI{
    1,                                   // lineNo
    1,                                   // colNo
    "SystemCore/isInputSizeMutableImpl", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/shared/system/coder/+matlab/"
    "+system/+coder/SystemCore.p" // pName
};

static rtBoundsCheckInfo b_emlrtBCI{
    1,                           // iFirst
    600651,                      // iLast
    227,                         // lineNo
    23,                          // colNo
    "",                          // aName
    "AsyncBuffercgHelper/write", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/dsp/dsp/+dsp/+internal/"
    "AsyncBuffercgHelper.m", // pName
    3                        // checkKind
};

static rtRunTimeErrorInfo s_emlrtRTEI{
    103,                  // lineNo
    17,                   // colNo
    "AsyncBuffercg/read", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/dsp/dsp/+dsp/+internal/"
    "AsyncBuffercg.m" // pName
};

static rtRunTimeErrorInfo qb_emlrtRTEI{
    93,                                       // lineNo
    13,                                       // colNo
    "AsyncBuffercgHelper/validateInputsImpl", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/dsp/dsp/+dsp/+internal/"
    "AsyncBuffercgHelper.m" // pName
};

static rtEqualityCheckInfo e_emlrtECI{
    -1,                          // nDims
    227,                         // lineNo
    13,                          // colNo
    "AsyncBuffercgHelper/write", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/dsp/dsp/+dsp/+internal/"
    "AsyncBuffercgHelper.m" // pName
};

static rtBoundsCheckInfo v_emlrtBCI{
    1,                           // iFirst
    5800321,                     // iLast
    227,                         // lineNo
    23,                          // colNo
    "",                          // aName
    "AsyncBuffercgHelper/write", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/dsp/dsp/+dsp/+internal/"
    "AsyncBuffercgHelper.m", // pName
    3                        // checkKind
};

static rtBoundsCheckInfo w_emlrtBCI{
    1,                                           // iFirst
    5800321,                                     // iLast
    457,                                         // lineNo
    29,                                          // colNo
    "",                                          // aName
    "AsyncBuffercgHelper/ReadSamplesFromBuffer", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/dsp/dsp/+dsp/+internal/"
    "AsyncBuffercgHelper.m", // pName
    0                        // checkKind
};

static rtEqualityCheckInfo f_emlrtECI{
    -1,                                          // nDims
    469,                                         // lineNo
    21,                                          // colNo
    "AsyncBuffercgHelper/ReadSamplesFromBuffer", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/dsp/dsp/+dsp/+internal/"
    "AsyncBuffercgHelper.m" // pName
};

static rtBoundsCheckInfo x_emlrtBCI{
    -1,                                          // iFirst
    -1,                                          // iLast
    469,                                         // lineNo
    33,                                          // colNo
    "",                                          // aName
    "AsyncBuffercgHelper/ReadSamplesFromBuffer", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/dsp/dsp/+dsp/+internal/"
    "AsyncBuffercgHelper.m", // pName
    0                        // checkKind
};

static rtBoundsCheckInfo y_emlrtBCI{
    -1,                                          // iFirst
    -1,                                          // iLast
    469,                                         // lineNo
    25,                                          // colNo
    "",                                          // aName
    "AsyncBuffercgHelper/ReadSamplesFromBuffer", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/dsp/dsp/+dsp/+internal/"
    "AsyncBuffercgHelper.m", // pName
    0                        // checkKind
};

static rtDoubleCheckInfo q_emlrtDCI{
    470,                                         // lineNo
    31,                                          // colNo
    "AsyncBuffercgHelper/ReadSamplesFromBuffer", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/dsp/dsp/+dsp/+internal/"
    "AsyncBuffercgHelper.m", // pName
    4                        // checkKind
};

static rtRunTimeErrorInfo sb_emlrtRTEI{
    109,                  // lineNo
    17,                   // colNo
    "AsyncBuffercg/read", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/dsp/dsp/+dsp/+internal/"
    "AsyncBuffercg.m" // pName
};

static rtDoubleCheckInfo r_emlrtDCI{
    467,                                         // lineNo
    21,                                          // colNo
    "AsyncBuffercgHelper/ReadSamplesFromBuffer", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/dsp/dsp/+dsp/+internal/"
    "AsyncBuffercgHelper.m", // pName
    4                        // checkKind
};

// Function Declarations
static void cb_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void fb_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void n_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void o_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
static void cb_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Invalid number of input rows. Specify an input with number of "
               "rows less than or equal to the buffer capacity.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

static void fb_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Invalid overlap requested. Specify overlap as less than or "
               "equal to the requested number of rows.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

static void n_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Changing the number of channels (number of columns) of the "
               "input signal is not supported.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

static void o_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Invalid number of rows requested. Specify the number of rows "
               "to read as less than or equal to the buffer capacity.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

namespace coder {
namespace dsp {
AsyncBuffer::AsyncBuffer()
{
  matlabCodegenIsDeleted = true;
}

b_AsyncBuffer::b_AsyncBuffer()
{
  matlabCodegenIsDeleted = true;
}

c_AsyncBuffer::c_AsyncBuffer()
{
  matlabCodegenIsDeleted = true;
}

AsyncBuffer::~AsyncBuffer()
{
  matlabCodegenDestructor();
}

b_AsyncBuffer::~b_AsyncBuffer()
{
  matlabCodegenDestructor();
}

c_AsyncBuffer::~c_AsyncBuffer()
{
  matlabCodegenDestructor();
}

void AsyncBuffer::matlabCodegenDestructor()
{
  if (!matlabCodegenIsDeleted) {
    matlabCodegenIsDeleted = true;
  }
}

void b_AsyncBuffer::matlabCodegenDestructor()
{
  if (!matlabCodegenIsDeleted) {
    matlabCodegenIsDeleted = true;
  }
}

void c_AsyncBuffer::matlabCodegenDestructor()
{
  if (!matlabCodegenIsDeleted) {
    matlabCodegenIsDeleted = true;
  }
}

void c_AsyncBuffer::read()
{
  array<creal32_T, 1U> out;
  int numRows;
  int q0_tmp;
  int qY;
  q0_tmp = pBuffer.WritePointer;
  numRows = pBuffer.ReadPointer;
  if ((q0_tmp >= 0) && (numRows < q0_tmp - MAX_int32_T)) {
    qY = MAX_int32_T;
  } else if ((q0_tmp < 0) && (numRows > q0_tmp - MIN_int32_T)) {
    qY = MIN_int32_T;
  } else {
    qY = q0_tmp - numRows;
  }
  if (qY < -2147483647) {
    qY = MIN_int32_T;
  } else {
    qY--;
  }
  if (numRows < -2146882997) {
    numRows = MAX_int32_T;
  } else {
    numRows = 600650 - numRows;
  }
  if ((numRows < 0) && (q0_tmp < MIN_int32_T - numRows)) {
    numRows = MIN_int32_T;
  } else if ((numRows > 0) && (q0_tmp > MAX_int32_T - numRows)) {
    numRows = MAX_int32_T;
  } else {
    numRows += q0_tmp;
  }
  if (pBuffer.ReadPointer < pBuffer.WritePointer) {
    numRows = qY;
  } else if (pBuffer.ReadPointer == pBuffer.WritePointer) {
    numRows = 600650;
  }
  if (numRows < 0) {
    e_rtErrorWithMessageID("number of rows", t_emlrtRTEI.fName,
                           t_emlrtRTEI.lineNo);
  }
  if (numRows > 600650) {
    o_rtErrorWithMessageID(s_emlrtRTEI.fName, s_emlrtRTEI.lineNo);
  }
  pBuffer.read(numRows, out);
}

void c_AsyncBuffer::read(::coder::array<creal32_T, 1U> &out)
{
  int numRows;
  int q0_tmp;
  int qY;
  q0_tmp = pBuffer.WritePointer;
  numRows = pBuffer.ReadPointer;
  if ((q0_tmp >= 0) && (numRows < q0_tmp - MAX_int32_T)) {
    qY = MAX_int32_T;
  } else if ((q0_tmp < 0) && (numRows > q0_tmp - MIN_int32_T)) {
    qY = MIN_int32_T;
  } else {
    qY = q0_tmp - numRows;
  }
  if (qY < -2147483647) {
    qY = MIN_int32_T;
  } else {
    qY--;
  }
  if (numRows < -2146882997) {
    numRows = MAX_int32_T;
  } else {
    numRows = 600650 - numRows;
  }
  if ((numRows < 0) && (q0_tmp < MIN_int32_T - numRows)) {
    numRows = MIN_int32_T;
  } else if ((numRows > 0) && (q0_tmp > MAX_int32_T - numRows)) {
    numRows = MAX_int32_T;
  } else {
    numRows += q0_tmp;
  }
  if (pBuffer.ReadPointer < pBuffer.WritePointer) {
    numRows = qY;
  } else if (pBuffer.ReadPointer == pBuffer.WritePointer) {
    numRows = 600650;
  }
  if (numRows < 0) {
    e_rtErrorWithMessageID("number of rows", t_emlrtRTEI.fName,
                           t_emlrtRTEI.lineNo);
  }
  if (numRows > 600650) {
    o_rtErrorWithMessageID(s_emlrtRTEI.fName, s_emlrtRTEI.lineNo);
  }
  pBuffer.read(numRows, out);
}

void AsyncBuffer::read(double numRows, ::coder::array<creal32_T, 1U> &out)
{
  array<int, 2U> b_y;
  array<int, 2U> readIdx;
  array<int, 2U> y;
  double d;
  int c;
  int k;
  int numRowsCast;
  int rPtr;
  int underrun;
  int wPtr_tmp;
  int yk;
  d = std::round(numRows);
  if (d < 2.147483648E+9) {
    if (d >= -2.147483648E+9) {
      numRowsCast = static_cast<int>(d);
    } else {
      numRowsCast = MIN_int32_T;
    }
  } else if (d >= 2.147483648E+9) {
    numRowsCast = MAX_int32_T;
  } else {
    numRowsCast = 0;
  }
  if (numRows < 0.0) {
    e_rtErrorWithMessageID("number of rows", t_emlrtRTEI.fName,
                           t_emlrtRTEI.lineNo);
  }
  if (std::isinf(numRows) || std::isnan(numRows)) {
    i_rtErrorWithMessageID("number of rows", bb_emlrtRTEI.fName,
                           bb_emlrtRTEI.lineNo);
  }
  if (!(std::floor(numRows) == numRows)) {
    j_rtErrorWithMessageID("number of rows", db_emlrtRTEI.fName,
                           db_emlrtRTEI.lineNo);
  }
  if (numRows > 5.80032E+6) {
    o_rtErrorWithMessageID(s_emlrtRTEI.fName, s_emlrtRTEI.lineNo);
  }
  if (!pBuffer.AsyncBuffercgHelper_isInitialized) {
    p_rtErrorWithMessageID(v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
  }
  wPtr_tmp = pBuffer.WritePointer;
  underrun = 0;
  yk = pBuffer.ReadPointer;
  if (yk > 2147483646) {
    rPtr = MAX_int32_T;
  } else {
    rPtr = yk + 1;
  }
  if (rPtr > 5800321) {
    rPtr = 1;
  }
  if ((wPtr_tmp < 1) || (wPtr_tmp > 5800321) || (rPtr < 1) ||
      (numRowsCast > 5800321)) {
    rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
  }
  c = (rPtr + numRowsCast) - 1;
  if (c > 5800321) {
    c -= 5800321;
    c_eml_integer_colon_dispatcher(rPtr, y);
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
      underrun = (c - wPtr_tmp) + 5800322;
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
    b = ((readIdx[k] < 1) || (readIdx[k] > 5800321));
    if (b) {
      rtDynamicBoundsError(readIdx[k], 1, 5800321, w_emlrtBCI);
    }
    out[k].re = pBuffer.Cache[readIdx[k] - 1].re;
    out[k].im = pBuffer.Cache[readIdx[k] - 1].im;
  }
  if (underrun != 0) {
    if ((numRowsCast >= 0) && (underrun < numRowsCast - MAX_int32_T)) {
      yk = MAX_int32_T;
    } else if ((numRowsCast < 0) && (underrun > numRowsCast - MIN_int32_T)) {
      yk = MIN_int32_T;
    } else {
      yk = numRowsCast - underrun;
    }
    if (yk + 1 > numRowsCast) {
      yk = 0;
      k = 0;
    } else {
      if ((yk + 1 < 1) || (yk + 1 > readIdx.size(1))) {
        rtDynamicBoundsError(yk + 1, 1, readIdx.size(1), d_emlrtBCI);
      }
      if ((numRowsCast < 1) || (numRowsCast > readIdx.size(1))) {
        rtDynamicBoundsError(numRowsCast, 1, readIdx.size(1), c_emlrtBCI);
      }
      k = numRowsCast;
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
  if (out.size(0) != numRowsCast) {
    h_rtErrorWithMessageID(u_emlrtRTEI.fName, u_emlrtRTEI.lineNo);
  }
  yk = pBuffer.CumulativeUnderrun;
  if ((yk < 0) && (underrun < MIN_int32_T - yk)) {
    yk = MIN_int32_T;
  } else if ((yk > 0) && (underrun > MAX_int32_T - yk)) {
    yk = MAX_int32_T;
  } else {
    yk += underrun;
  }
  pBuffer.CumulativeUnderrun = yk;
  if (underrun != 0) {
    pBuffer.ReadPointer = wPtr_tmp - 1;
  } else {
    pBuffer.ReadPointer = c;
  }
}

void b_AsyncBuffer::read(double numRows, ::coder::array<double, 1U> &out)
{
  array<int, 2U> b_y;
  array<int, 2U> readIdx;
  array<int, 2U> y;
  double d;
  int c;
  int k;
  int numRowsCast;
  int rPtr;
  int underrun;
  int wPtr_tmp;
  int yk;
  d = std::round(numRows);
  if (d < 2.147483648E+9) {
    if (d >= -2.147483648E+9) {
      numRowsCast = static_cast<int>(d);
    } else {
      numRowsCast = MIN_int32_T;
    }
  } else if (d >= 2.147483648E+9) {
    numRowsCast = MAX_int32_T;
  } else {
    numRowsCast = 0;
  }
  if (numRows < 0.0) {
    e_rtErrorWithMessageID("number of rows", t_emlrtRTEI.fName,
                           t_emlrtRTEI.lineNo);
  }
  if (std::isinf(numRows) || std::isnan(numRows)) {
    i_rtErrorWithMessageID("number of rows", bb_emlrtRTEI.fName,
                           bb_emlrtRTEI.lineNo);
  }
  if (!(std::floor(numRows) == numRows)) {
    j_rtErrorWithMessageID("number of rows", db_emlrtRTEI.fName,
                           db_emlrtRTEI.lineNo);
  }
  if (numRows > 5.80032E+6) {
    o_rtErrorWithMessageID(s_emlrtRTEI.fName, s_emlrtRTEI.lineNo);
  }
  if (!pBuffer.AsyncBuffercgHelper_isInitialized) {
    p_rtErrorWithMessageID(v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
  }
  wPtr_tmp = pBuffer.WritePointer;
  underrun = 0;
  yk = pBuffer.ReadPointer;
  if (yk > 2147483646) {
    rPtr = MAX_int32_T;
  } else {
    rPtr = yk + 1;
  }
  if (rPtr > 5800321) {
    rPtr = 1;
  }
  if ((wPtr_tmp < 1) || (wPtr_tmp > 5800321) || (rPtr < 1) ||
      (numRowsCast > 5800321)) {
    rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
  }
  c = (rPtr + numRowsCast) - 1;
  if (c > 5800321) {
    c -= 5800321;
    c_eml_integer_colon_dispatcher(rPtr, y);
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
      underrun = (c - wPtr_tmp) + 5800322;
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
    if ((readIdx[k] < 1) || (readIdx[k] > 5800321)) {
      rtDynamicBoundsError(readIdx[k], 1, 5800321, w_emlrtBCI);
    }
    out[k] = pBuffer.Cache[readIdx[k] - 1];
  }
  if (underrun != 0) {
    if ((numRowsCast >= 0) && (underrun < numRowsCast - MAX_int32_T)) {
      yk = MAX_int32_T;
    } else if ((numRowsCast < 0) && (underrun > numRowsCast - MIN_int32_T)) {
      yk = MIN_int32_T;
    } else {
      yk = numRowsCast - underrun;
    }
    if (yk + 1 > numRowsCast) {
      yk = 0;
      k = 0;
    } else {
      if ((yk + 1 < 1) || (yk + 1 > readIdx.size(1))) {
        rtDynamicBoundsError(yk + 1, 1, readIdx.size(1), d_emlrtBCI);
      }
      if ((numRowsCast < 1) || (numRowsCast > readIdx.size(1))) {
        rtDynamicBoundsError(numRowsCast, 1, readIdx.size(1), c_emlrtBCI);
      }
      k = numRowsCast;
    }
    if (underrun < 0) {
      rtNonNegativeError(static_cast<double>(underrun), emlrtDCI);
    }
    k -= yk;
    rtSubAssignSizeCheck(&k, 1, &underrun, 1, b_emlrtECI);
    for (k = 0; k < underrun; k++) {
      out[yk + k] = 0.0;
    }
  }
  if (out.size(0) != numRowsCast) {
    h_rtErrorWithMessageID(u_emlrtRTEI.fName, u_emlrtRTEI.lineNo);
  }
  yk = pBuffer.CumulativeUnderrun;
  if ((yk < 0) && (underrun < MIN_int32_T - yk)) {
    yk = MIN_int32_T;
  } else if ((yk > 0) && (underrun > MAX_int32_T - yk)) {
    yk = MAX_int32_T;
  } else {
    yk += underrun;
  }
  pBuffer.CumulativeUnderrun = yk;
  if (underrun != 0) {
    pBuffer.ReadPointer = wPtr_tmp - 1;
  } else {
    pBuffer.ReadPointer = c;
  }
}

void AsyncBuffer::read(double numRows, double overlap,
                       ::coder::array<creal32_T, 1U> &out)
{
  array<int, 2U> b_y;
  array<int, 2U> readIdx;
  array<int, 2U> y;
  double d;
  int c;
  int i;
  int numRowsCast;
  int overlapCast;
  int overlapUnderrun;
  int q0;
  int qY;
  int rPtr;
  int underrun;
  int wPtr_tmp;
  d = std::round(numRows);
  if (d < 2.147483648E+9) {
    if (d >= -2.147483648E+9) {
      numRowsCast = static_cast<int>(d);
    } else {
      numRowsCast = MIN_int32_T;
    }
  } else if (d >= 2.147483648E+9) {
    numRowsCast = MAX_int32_T;
  } else {
    numRowsCast = 0;
  }
  if (numRows < 0.0) {
    e_rtErrorWithMessageID("number of rows", t_emlrtRTEI.fName,
                           t_emlrtRTEI.lineNo);
  }
  if (std::isinf(numRows) || std::isnan(numRows)) {
    i_rtErrorWithMessageID("number of rows", bb_emlrtRTEI.fName,
                           bb_emlrtRTEI.lineNo);
  }
  if (!(std::floor(numRows) == numRows)) {
    j_rtErrorWithMessageID("number of rows", db_emlrtRTEI.fName,
                           db_emlrtRTEI.lineNo);
  }
  if (numRows > 5.80032E+6) {
    o_rtErrorWithMessageID(s_emlrtRTEI.fName, s_emlrtRTEI.lineNo);
  }
  if (overlap < 0.0) {
    e_rtErrorWithMessageID("overlap", t_emlrtRTEI.fName, t_emlrtRTEI.lineNo);
  }
  if (std::isinf(overlap) || std::isnan(overlap)) {
    i_rtErrorWithMessageID("overlap", bb_emlrtRTEI.fName, bb_emlrtRTEI.lineNo);
  }
  if (!(std::floor(overlap) == overlap)) {
    j_rtErrorWithMessageID("overlap", db_emlrtRTEI.fName, db_emlrtRTEI.lineNo);
  }
  if (overlap > numRows) {
    fb_rtErrorWithMessageID(sb_emlrtRTEI.fName, sb_emlrtRTEI.lineNo);
  }
  overlapCast = static_cast<int>(overlap);
  if (!pBuffer.AsyncBuffercgHelper_isInitialized) {
    p_rtErrorWithMessageID(v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
  }
  wPtr_tmp = pBuffer.WritePointer;
  underrun = 0;
  overlapUnderrun = 0;
  q0 = pBuffer.ReadPointer;
  if (q0 > 2147483646) {
    rPtr = MAX_int32_T;
  } else {
    rPtr = q0 + 1;
  }
  if (rPtr > 5800321) {
    rPtr = 1;
  }
  if ((wPtr_tmp < 1) || (wPtr_tmp > 5800321) || (rPtr < 1) ||
      (numRowsCast > 5800321)) {
    rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
  }
  if (overlapCast == 0) {
    c = (rPtr + numRowsCast) - 1;
    if (c > 5800321) {
      c -= 5800321;
      c_eml_integer_colon_dispatcher(rPtr, y);
      b_eml_integer_colon_dispatcher(c, b_y);
      readIdx.set_size(1, y.size(1) + b_y.size(1));
      q0 = y.size(1);
      for (i = 0; i < q0; i++) {
        readIdx[i] = y[i];
      }
      q0 = b_y.size(1);
      for (i = 0; i < q0; i++) {
        readIdx[i + y.size(1)] = b_y[i];
      }
      if (rPtr <= wPtr_tmp) {
        underrun = (c - wPtr_tmp) + 5800322;
      } else if (wPtr_tmp <= c) {
        underrun = (c - wPtr_tmp) + 1;
      }
    } else {
      eml_integer_colon_dispatcher(rPtr, c, readIdx);
      if ((rPtr <= wPtr_tmp) && (wPtr_tmp <= c)) {
        underrun = (c - wPtr_tmp) + 1;
      }
    }
  } else {
    overlapCast = rPtr - overlapCast;
    if ((overlapCast < 0) && (numRowsCast < MIN_int32_T - overlapCast)) {
      qY = MIN_int32_T;
    } else if ((overlapCast > 0) && (numRowsCast > MAX_int32_T - overlapCast)) {
      qY = MAX_int32_T;
    } else {
      qY = overlapCast + numRowsCast;
    }
    if (qY < -2147483647) {
      qY = MIN_int32_T;
    } else {
      qY--;
    }
    c = qY;
    if (overlapCast < 1) {
      c_eml_integer_colon_dispatcher(overlapCast + 5800321, y);
      b_eml_integer_colon_dispatcher(qY, b_y);
      readIdx.set_size(1, y.size(1) + b_y.size(1));
      q0 = y.size(1);
      for (i = 0; i < q0; i++) {
        readIdx[i] = y[i];
      }
      q0 = b_y.size(1);
      for (i = 0; i < q0; i++) {
        readIdx[i + y.size(1)] = b_y[i];
      }
      if ((rPtr <= wPtr_tmp) && (wPtr_tmp <= qY)) {
        underrun = (qY - wPtr_tmp) + 1;
      } else if (wPtr_tmp < rPtr) {
        overlapUnderrun = (wPtr_tmp - overlapCast) + 1;
      } else if (wPtr_tmp > overlapCast + 5800321) {
        overlapUnderrun = (wPtr_tmp - overlapCast) - 5800320;
      }
    } else if (qY > 5800321) {
      c = qY - 5800321;
      c_eml_integer_colon_dispatcher(overlapCast, y);
      b_eml_integer_colon_dispatcher(qY - 5800321, b_y);
      readIdx.set_size(1, y.size(1) + b_y.size(1));
      q0 = y.size(1);
      for (i = 0; i < q0; i++) {
        readIdx[i] = y[i];
      }
      q0 = b_y.size(1);
      for (i = 0; i < q0; i++) {
        readIdx[i + y.size(1)] = b_y[i];
      }
      if (rPtr <= wPtr_tmp) {
        underrun = (qY - wPtr_tmp) + 1;
      } else if (wPtr_tmp <= qY - 5800321) {
        underrun = (qY - wPtr_tmp) - 5800320;
      } else if ((overlapCast < wPtr_tmp) && (wPtr_tmp < rPtr)) {
        overlapUnderrun = (wPtr_tmp - overlapCast) + 1;
      }
    } else {
      eml_integer_colon_dispatcher(overlapCast, qY, readIdx);
      if ((rPtr <= wPtr_tmp) && (wPtr_tmp <= qY)) {
        underrun = (qY - wPtr_tmp) + 1;
      } else if ((overlapCast <= wPtr_tmp) && (wPtr_tmp < rPtr)) {
        overlapUnderrun = (wPtr_tmp - overlapCast) + 1;
      }
    }
  }
  out.set_size(readIdx.size(1));
  q0 = readIdx.size(1);
  for (i = 0; i < q0; i++) {
    bool b;
    b = ((readIdx[i] < 1) || (readIdx[i] > 5800321));
    if (b) {
      rtDynamicBoundsError(readIdx[i], 1, 5800321, w_emlrtBCI);
    }
    out[i].re = pBuffer.Cache[readIdx[i] - 1].re;
    out[i].im = pBuffer.Cache[readIdx[i] - 1].im;
  }
  if (underrun != 0) {
    if ((numRowsCast >= 0) && (underrun < numRowsCast - MAX_int32_T)) {
      qY = MAX_int32_T;
    } else if ((numRowsCast < 0) && (underrun > numRowsCast - MIN_int32_T)) {
      qY = MIN_int32_T;
    } else {
      qY = numRowsCast - underrun;
    }
    if (qY + 1 > numRowsCast) {
      qY = 0;
      i = 0;
    } else {
      if ((qY + 1 < 1) || (qY + 1 > readIdx.size(1))) {
        rtDynamicBoundsError(qY + 1, 1, readIdx.size(1), d_emlrtBCI);
      }
      if ((numRowsCast < 1) || (numRowsCast > readIdx.size(1))) {
        rtDynamicBoundsError(numRowsCast, 1, readIdx.size(1), c_emlrtBCI);
      }
      i = numRowsCast;
    }
    if (underrun < 0) {
      rtNonNegativeError(static_cast<double>(underrun), emlrtDCI);
    }
    i -= qY;
    rtSubAssignSizeCheck(&i, 1, &underrun, 1, b_emlrtECI);
    for (i = 0; i < underrun; i++) {
      overlapCast = qY + i;
      out[overlapCast].re = 0.0F;
      out[overlapCast].im = 0.0F;
    }
  } else if (overlapUnderrun != 0) {
    if (overlapUnderrun == numRowsCast) {
      if (overlapUnderrun < 0) {
        rtNonNegativeError(static_cast<double>(overlapUnderrun), r_emlrtDCI);
      }
      out.set_size(overlapUnderrun);
      for (i = 0; i < overlapUnderrun; i++) {
        out[i].re = 0.0F;
        out[i].im = 0.0F;
      }
    } else {
      if (overlapUnderrun < 1) {
        i = 0;
      } else {
        if (readIdx.size(1) < 1) {
          rtDynamicBoundsError(1, 1, readIdx.size(1), y_emlrtBCI);
        }
        if (overlapUnderrun > readIdx.size(1)) {
          rtDynamicBoundsError(overlapUnderrun, 1, readIdx.size(1), x_emlrtBCI);
        }
        i = overlapUnderrun;
      }
      if (overlapUnderrun < 0) {
        rtNonNegativeError(static_cast<double>(overlapUnderrun), q_emlrtDCI);
      }
      rtSubAssignSizeCheck(&i, 1, &overlapUnderrun, 1, f_emlrtECI);
      for (i = 0; i < overlapUnderrun; i++) {
        out[i].re = 0.0F;
        out[i].im = 0.0F;
      }
    }
  }
  if (out.size(0) != numRowsCast) {
    h_rtErrorWithMessageID(u_emlrtRTEI.fName, u_emlrtRTEI.lineNo);
  }
  q0 = pBuffer.CumulativeUnderrun;
  if ((q0 < 0) && (underrun < MIN_int32_T - q0)) {
    qY = MIN_int32_T;
  } else if ((q0 > 0) && (underrun > MAX_int32_T - q0)) {
    qY = MAX_int32_T;
  } else {
    qY = q0 + underrun;
  }
  pBuffer.CumulativeUnderrun = qY;
  if (underrun != 0) {
    pBuffer.ReadPointer = wPtr_tmp - 1;
  } else {
    pBuffer.ReadPointer = c;
  }
}

void b_AsyncBuffer::read(double numRows, double overlap,
                         ::coder::array<double, 1U> &out)
{
  array<int, 2U> b_y;
  array<int, 2U> readIdx;
  array<int, 2U> y;
  double d;
  int c;
  int i;
  int loop_ub;
  int numRowsCast;
  int overlapCast;
  int overlapUnderrun;
  int q0;
  int rPtr;
  int underrun;
  int wPtr_tmp;
  d = std::round(numRows);
  if (d < 2.147483648E+9) {
    if (d >= -2.147483648E+9) {
      numRowsCast = static_cast<int>(d);
    } else {
      numRowsCast = MIN_int32_T;
    }
  } else if (d >= 2.147483648E+9) {
    numRowsCast = MAX_int32_T;
  } else {
    numRowsCast = 0;
  }
  if (numRows < 0.0) {
    e_rtErrorWithMessageID("number of rows", t_emlrtRTEI.fName,
                           t_emlrtRTEI.lineNo);
  }
  if (std::isinf(numRows) || std::isnan(numRows)) {
    i_rtErrorWithMessageID("number of rows", bb_emlrtRTEI.fName,
                           bb_emlrtRTEI.lineNo);
  }
  if (!(std::floor(numRows) == numRows)) {
    j_rtErrorWithMessageID("number of rows", db_emlrtRTEI.fName,
                           db_emlrtRTEI.lineNo);
  }
  if (numRows > 5.80032E+6) {
    o_rtErrorWithMessageID(s_emlrtRTEI.fName, s_emlrtRTEI.lineNo);
  }
  if (overlap < 0.0) {
    e_rtErrorWithMessageID("overlap", t_emlrtRTEI.fName, t_emlrtRTEI.lineNo);
  }
  if (std::isinf(overlap) || std::isnan(overlap)) {
    i_rtErrorWithMessageID("overlap", bb_emlrtRTEI.fName, bb_emlrtRTEI.lineNo);
  }
  if (!(std::floor(overlap) == overlap)) {
    j_rtErrorWithMessageID("overlap", db_emlrtRTEI.fName, db_emlrtRTEI.lineNo);
  }
  if (overlap > numRows) {
    fb_rtErrorWithMessageID(sb_emlrtRTEI.fName, sb_emlrtRTEI.lineNo);
  }
  overlapCast = static_cast<int>(overlap);
  if (!pBuffer.AsyncBuffercgHelper_isInitialized) {
    p_rtErrorWithMessageID(v_emlrtRTEI.fName, v_emlrtRTEI.lineNo);
  }
  wPtr_tmp = pBuffer.WritePointer;
  underrun = 0;
  overlapUnderrun = 0;
  q0 = pBuffer.ReadPointer;
  if (q0 > 2147483646) {
    rPtr = MAX_int32_T;
  } else {
    rPtr = q0 + 1;
  }
  if (rPtr > 5800321) {
    rPtr = 1;
  }
  if ((wPtr_tmp < 1) || (wPtr_tmp > 5800321) || (rPtr < 1) ||
      (numRowsCast > 5800321)) {
    rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
  }
  if (overlapCast == 0) {
    c = (rPtr + numRowsCast) - 1;
    if (c > 5800321) {
      c -= 5800321;
      c_eml_integer_colon_dispatcher(rPtr, y);
      b_eml_integer_colon_dispatcher(c, b_y);
      readIdx.set_size(1, y.size(1) + b_y.size(1));
      loop_ub = y.size(1);
      for (i = 0; i < loop_ub; i++) {
        readIdx[i] = y[i];
      }
      loop_ub = b_y.size(1);
      for (i = 0; i < loop_ub; i++) {
        readIdx[i + y.size(1)] = b_y[i];
      }
      if (rPtr <= wPtr_tmp) {
        underrun = (c - wPtr_tmp) + 5800322;
      } else if (wPtr_tmp <= c) {
        underrun = (c - wPtr_tmp) + 1;
      }
    } else {
      eml_integer_colon_dispatcher(rPtr, c, readIdx);
      if ((rPtr <= wPtr_tmp) && (wPtr_tmp <= c)) {
        underrun = (c - wPtr_tmp) + 1;
      }
    }
  } else {
    overlapCast = rPtr - overlapCast;
    if ((overlapCast < 0) && (numRowsCast < MIN_int32_T - overlapCast)) {
      q0 = MIN_int32_T;
    } else if ((overlapCast > 0) && (numRowsCast > MAX_int32_T - overlapCast)) {
      q0 = MAX_int32_T;
    } else {
      q0 = overlapCast + numRowsCast;
    }
    if (q0 < -2147483647) {
      q0 = MIN_int32_T;
    } else {
      q0--;
    }
    c = q0;
    if (overlapCast < 1) {
      c_eml_integer_colon_dispatcher(overlapCast + 5800321, y);
      b_eml_integer_colon_dispatcher(q0, b_y);
      readIdx.set_size(1, y.size(1) + b_y.size(1));
      loop_ub = y.size(1);
      for (i = 0; i < loop_ub; i++) {
        readIdx[i] = y[i];
      }
      loop_ub = b_y.size(1);
      for (i = 0; i < loop_ub; i++) {
        readIdx[i + y.size(1)] = b_y[i];
      }
      if ((rPtr <= wPtr_tmp) && (wPtr_tmp <= q0)) {
        underrun = (q0 - wPtr_tmp) + 1;
      } else if (wPtr_tmp < rPtr) {
        overlapUnderrun = (wPtr_tmp - overlapCast) + 1;
      } else if (wPtr_tmp > overlapCast + 5800321) {
        overlapUnderrun = (wPtr_tmp - overlapCast) - 5800320;
      }
    } else if (q0 > 5800321) {
      c = q0 - 5800321;
      c_eml_integer_colon_dispatcher(overlapCast, y);
      b_eml_integer_colon_dispatcher(q0 - 5800321, b_y);
      readIdx.set_size(1, y.size(1) + b_y.size(1));
      loop_ub = y.size(1);
      for (i = 0; i < loop_ub; i++) {
        readIdx[i] = y[i];
      }
      loop_ub = b_y.size(1);
      for (i = 0; i < loop_ub; i++) {
        readIdx[i + y.size(1)] = b_y[i];
      }
      if (rPtr <= wPtr_tmp) {
        underrun = (q0 - wPtr_tmp) + 1;
      } else if (wPtr_tmp <= q0 - 5800321) {
        underrun = (q0 - wPtr_tmp) - 5800320;
      } else if ((overlapCast < wPtr_tmp) && (wPtr_tmp < rPtr)) {
        overlapUnderrun = (wPtr_tmp - overlapCast) + 1;
      }
    } else {
      eml_integer_colon_dispatcher(overlapCast, q0, readIdx);
      if ((rPtr <= wPtr_tmp) && (wPtr_tmp <= q0)) {
        underrun = (q0 - wPtr_tmp) + 1;
      } else if ((overlapCast <= wPtr_tmp) && (wPtr_tmp < rPtr)) {
        overlapUnderrun = (wPtr_tmp - overlapCast) + 1;
      }
    }
  }
  out.set_size(readIdx.size(1));
  loop_ub = readIdx.size(1);
  for (i = 0; i < loop_ub; i++) {
    if ((readIdx[i] < 1) || (readIdx[i] > 5800321)) {
      rtDynamicBoundsError(readIdx[i], 1, 5800321, w_emlrtBCI);
    }
    out[i] = pBuffer.Cache[readIdx[i] - 1];
  }
  if (underrun != 0) {
    if ((numRowsCast >= 0) && (underrun < numRowsCast - MAX_int32_T)) {
      q0 = MAX_int32_T;
    } else if ((numRowsCast < 0) && (underrun > numRowsCast - MIN_int32_T)) {
      q0 = MIN_int32_T;
    } else {
      q0 = numRowsCast - underrun;
    }
    if (q0 + 1 > numRowsCast) {
      q0 = 0;
      i = 0;
    } else {
      if ((q0 + 1 < 1) || (q0 + 1 > readIdx.size(1))) {
        rtDynamicBoundsError(q0 + 1, 1, readIdx.size(1), d_emlrtBCI);
      }
      if ((numRowsCast < 1) || (numRowsCast > readIdx.size(1))) {
        rtDynamicBoundsError(numRowsCast, 1, readIdx.size(1), c_emlrtBCI);
      }
      i = numRowsCast;
    }
    if (underrun < 0) {
      rtNonNegativeError(static_cast<double>(underrun), emlrtDCI);
    }
    i -= q0;
    rtSubAssignSizeCheck(&i, 1, &underrun, 1, b_emlrtECI);
    for (i = 0; i < underrun; i++) {
      out[q0 + i] = 0.0;
    }
  } else if (overlapUnderrun != 0) {
    if (overlapUnderrun == numRowsCast) {
      if (overlapUnderrun < 0) {
        rtNonNegativeError(static_cast<double>(overlapUnderrun), r_emlrtDCI);
      }
      out.set_size(overlapUnderrun);
      for (i = 0; i < overlapUnderrun; i++) {
        out[i] = 0.0;
      }
    } else {
      if (overlapUnderrun < 1) {
        i = 0;
      } else {
        if (readIdx.size(1) < 1) {
          rtDynamicBoundsError(1, 1, readIdx.size(1), y_emlrtBCI);
        }
        if (overlapUnderrun > readIdx.size(1)) {
          rtDynamicBoundsError(overlapUnderrun, 1, readIdx.size(1), x_emlrtBCI);
        }
        i = overlapUnderrun;
      }
      if (overlapUnderrun < 0) {
        rtNonNegativeError(static_cast<double>(overlapUnderrun), q_emlrtDCI);
      }
      rtSubAssignSizeCheck(&i, 1, &overlapUnderrun, 1, f_emlrtECI);
      for (i = 0; i < overlapUnderrun; i++) {
        out[i] = 0.0;
      }
    }
  }
  if (out.size(0) != numRowsCast) {
    h_rtErrorWithMessageID(u_emlrtRTEI.fName, u_emlrtRTEI.lineNo);
  }
  q0 = pBuffer.CumulativeUnderrun;
  if ((q0 < 0) && (underrun < MIN_int32_T - q0)) {
    q0 = MIN_int32_T;
  } else if ((q0 > 0) && (underrun > MAX_int32_T - q0)) {
    q0 = MAX_int32_T;
  } else {
    q0 += underrun;
  }
  pBuffer.CumulativeUnderrun = q0;
  if (underrun != 0) {
    pBuffer.ReadPointer = wPtr_tmp - 1;
  } else {
    pBuffer.ReadPointer = c;
  }
}

void AsyncBuffer::release()
{
  if (pBuffer.isInitialized == 1) {
    pBuffer.isInitialized = 2;
    if (pBuffer.isSetupComplete) {
      pBuffer.ReadPointer = 1;
      pBuffer.WritePointer = 2;
      pBuffer.CumulativeOverrun = 0;
      pBuffer.CumulativeUnderrun = 0;
      pBuffer.AsyncBuffercgHelper_isInitialized = false;
      pBuffer.NumChannels = -1;
    }
  }
}

void b_AsyncBuffer::release()
{
  if (pBuffer.isInitialized == 1) {
    pBuffer.isInitialized = 2;
    if (pBuffer.isSetupComplete) {
      pBuffer.ReadPointer = 1;
      pBuffer.WritePointer = 2;
      pBuffer.CumulativeOverrun = 0;
      pBuffer.CumulativeUnderrun = 0;
      pBuffer.AsyncBuffercgHelper_isInitialized = false;
      pBuffer.NumChannels = -1;
    }
  }
}

void c_AsyncBuffer::release()
{
  if (pBuffer.isInitialized == 1) {
    pBuffer.isInitialized = 2;
    if (pBuffer.isSetupComplete) {
      pBuffer.ReadPointer = 1;
      pBuffer.WritePointer = 2;
      pBuffer.CumulativeOverrun = 0;
      pBuffer.CumulativeUnderrun = 0;
      pBuffer.AsyncBuffercgHelper_isInitialized = false;
      pBuffer.NumChannels = -1;
    }
  }
}

void AsyncBuffer::reset()
{
  if (pBuffer.isInitialized == 2) {
    rtErrorWithMessageID("reset", q_emlrtRTEI.fName, q_emlrtRTEI.lineNo);
  }
  if (pBuffer.isInitialized == 1) {
    pBuffer.ReadPointer = 1;
    pBuffer.WritePointer = 2;
    pBuffer.CumulativeOverrun = 0;
    pBuffer.CumulativeUnderrun = 0;
    std::memset(&pBuffer.Cache[0], 0, 5800321U * sizeof(creal32_T));
  }
}

void b_AsyncBuffer::reset()
{
  if (pBuffer.isInitialized == 2) {
    rtErrorWithMessageID("reset", b_emlrtRTEI.fName, b_emlrtRTEI.lineNo);
  }
  if (pBuffer.isInitialized == 1) {
    pBuffer.ReadPointer = 1;
    pBuffer.WritePointer = 2;
    pBuffer.CumulativeOverrun = 0;
    pBuffer.CumulativeUnderrun = 0;
    std::memset(&pBuffer.Cache[0], 0, 5800321U * sizeof(double));
  }
}

void c_AsyncBuffer::reset()
{
  if (pBuffer.isInitialized == 2) {
    rtErrorWithMessageID("reset", b_emlrtRTEI.fName, b_emlrtRTEI.lineNo);
  }
  if (pBuffer.isInitialized == 1) {
    pBuffer.ReadPointer = 1;
    pBuffer.WritePointer = 2;
    pBuffer.CumulativeOverrun = 0;
    pBuffer.CumulativeUnderrun = 0;
    std::memset(&pBuffer.Cache[0], 0, 600651U * sizeof(creal32_T));
  }
}

void c_AsyncBuffer::write()
{
  internal::c_AsyncBuffercgHelper *obj;
  array<int, 2U> bc;
  array<int, 1U> r;
  int i;
  int rPtr;
  int varargout_1;
  int wPtr;
  bool anyInputSizeChanged;
  bool exitg1;
  obj = &pBuffer;
  if (pBuffer.isInitialized == 2) {
    rtErrorWithMessageID("step", q_emlrtRTEI.fName, q_emlrtRTEI.lineNo);
  }
  if (pBuffer.isInitialized != 1) {
    cell_wrap_2 varSizes;
    pBuffer.isSetupComplete = false;
    if (pBuffer.isInitialized != 0) {
      d_rtErrorWithMessageID("setup", q_emlrtRTEI.fName, q_emlrtRTEI.lineNo);
    }
    pBuffer.isInitialized = 1;
    for (int b_i{0}; b_i < 8; b_i++) {
      varSizes.f1[b_i] = 1U;
    }
    pBuffer.inputVarSize[0] = varSizes;
    if ((pBuffer.NumChannels != -1) && (pBuffer.NumChannels != 1)) {
      n_rtErrorWithMessageID(p_emlrtRTEI.fName, p_emlrtRTEI.lineNo);
    }
    pBuffer.NumChannels = 1;
    pBuffer.AsyncBuffercgHelper_isInitialized = true;
    for (i = 0; i < 600651; i++) {
      pBuffer.Cache[i].re = 0.0F;
      pBuffer.Cache[i].im = 0.0F;
    }
    pBuffer.isSetupComplete = true;
    pBuffer.ReadPointer = 1;
    pBuffer.WritePointer = 2;
    pBuffer.CumulativeOverrun = 0;
    pBuffer.CumulativeUnderrun = 0;
    for (i = 0; i < 600651; i++) {
      pBuffer.Cache[i].re = 0.0F;
      pBuffer.Cache[i].im = 0.0F;
    }
  }
  anyInputSizeChanged = false;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 8)) {
    if (obj->inputVarSize[0].f1[i] != 1U) {
      anyInputSizeChanged = true;
      for (int b_i{0}; b_i < 8; b_i++) {
        obj->inputVarSize[0].f1[b_i] = 1U;
      }
      exitg1 = true;
    } else {
      i++;
    }
  }
  if (anyInputSizeChanged && (pBuffer.NumChannels != -1) &&
      (pBuffer.NumChannels != 1)) {
    n_rtErrorWithMessageID(p_emlrtRTEI.fName, p_emlrtRTEI.lineNo);
  }
  wPtr = pBuffer.WritePointer;
  rPtr = pBuffer.ReadPointer;
  varargout_1 = 0;
  if ((wPtr < 1) || (wPtr > 600651)) {
    rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
  }
  eml_integer_colon_dispatcher(wPtr, wPtr, bc);
  if ((wPtr <= rPtr) && (rPtr <= wPtr)) {
    varargout_1 = (wPtr - rPtr) + 1;
  }
  r.set_size(bc.size(1));
  i = bc.size(1);
  for (int b_i{0}; b_i < i; b_i++) {
    if ((bc[b_i] < 1) || (bc[b_i] > 600651)) {
      rtDynamicBoundsError(bc[b_i], 1, 600651, b_emlrtBCI);
    }
    r[b_i] = bc[b_i];
  }
  i = r.size(0);
  for (int b_i{0}; b_i < i; b_i++) {
    pBuffer.Cache[r[b_i] - 1].re = 1.0F;
    pBuffer.Cache[r[b_i] - 1].im = 1.0F;
  }
  if (wPtr + 1 > 600651) {
    wPtr = 1;
  } else {
    wPtr++;
  }
  if (varargout_1 != 0) {
    rPtr = wPtr;
  }
  i = pBuffer.CumulativeOverrun;
  if ((i < 0) && (varargout_1 < MIN_int32_T - i)) {
    i = MIN_int32_T;
  } else if ((i > 0) && (varargout_1 > MAX_int32_T - i)) {
    i = MAX_int32_T;
  } else {
    i += varargout_1;
  }
  pBuffer.CumulativeOverrun = i;
  pBuffer.WritePointer = wPtr;
  pBuffer.ReadPointer = rPtr;
}

void AsyncBuffer::write(const ::coder::array<creal32_T, 1U> &in)
{
  internal::AsyncBuffercgHelper *obj;
  array<int, 2U> b_y;
  array<int, 2U> bc;
  array<int, 2U> y;
  array<int, 1U> r;
  unsigned int inSize[8];
  int b_qY;
  int c;
  int i;
  int k;
  int qY;
  int rPtr;
  int wPtr;
  int yk;
  bool anyInputSizeChanged;
  bool exitg1;
  obj = &pBuffer;
  if (pBuffer.isInitialized == 2) {
    rtErrorWithMessageID("step", ob_emlrtRTEI.fName, ob_emlrtRTEI.lineNo);
  }
  if (pBuffer.isInitialized != 1) {
    cell_wrap_2 varSizes;
    pBuffer.isSetupComplete = false;
    if (pBuffer.isInitialized != 0) {
      d_rtErrorWithMessageID("setup", pb_emlrtRTEI.fName, pb_emlrtRTEI.lineNo);
    }
    pBuffer.isInitialized = 1;
    varSizes.f1[0] = static_cast<unsigned int>(in.size(0));
    varSizes.f1[1] = 1U;
    for (yk = 0; yk < 6; yk++) {
      varSizes.f1[yk + 2] = 1U;
    }
    pBuffer.inputVarSize[0] = varSizes;
    if (in.size(0) > 5800320) {
      cb_rtErrorWithMessageID(qb_emlrtRTEI.fName, qb_emlrtRTEI.lineNo);
    }
    if ((pBuffer.NumChannels != -1) && (pBuffer.NumChannels != 1)) {
      n_rtErrorWithMessageID(p_emlrtRTEI.fName, p_emlrtRTEI.lineNo);
    }
    pBuffer.NumChannels = 1;
    pBuffer.AsyncBuffercgHelper_isInitialized = true;
    for (i = 0; i < 5800321; i++) {
      pBuffer.Cache[i].re = 0.0F;
      pBuffer.Cache[i].im = 0.0F;
    }
    pBuffer.isSetupComplete = true;
    pBuffer.ReadPointer = 1;
    pBuffer.WritePointer = 2;
    pBuffer.CumulativeOverrun = 0;
    pBuffer.CumulativeUnderrun = 0;
    for (i = 0; i < 5800321; i++) {
      pBuffer.Cache[i].re = 0.0F;
      pBuffer.Cache[i].im = 0.0F;
    }
  }
  anyInputSizeChanged = false;
  inSize[0] = static_cast<unsigned int>(in.size(0));
  inSize[1] = 1U;
  for (yk = 0; yk < 6; yk++) {
    inSize[yk + 2] = 1U;
  }
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 8)) {
    if (obj->inputVarSize[0].f1[k] != inSize[k]) {
      anyInputSizeChanged = true;
      for (yk = 0; yk < 8; yk++) {
        obj->inputVarSize[0].f1[yk] = inSize[yk];
      }
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (anyInputSizeChanged) {
    if (in.size(0) > 5800320) {
      cb_rtErrorWithMessageID(qb_emlrtRTEI.fName, qb_emlrtRTEI.lineNo);
    }
    if ((pBuffer.NumChannels != -1) && (pBuffer.NumChannels != 1)) {
      n_rtErrorWithMessageID(p_emlrtRTEI.fName, p_emlrtRTEI.lineNo);
    }
  }
  wPtr = pBuffer.WritePointer;
  rPtr = pBuffer.ReadPointer;
  qY = 0;
  if ((wPtr < 1) || (wPtr > 5800321)) {
    rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
  }
  if (in.size(0) > MAX_int32_T - wPtr) {
    b_qY = MAX_int32_T;
  } else {
    b_qY = wPtr + in.size(0);
  }
  c = b_qY - 1;
  if (b_qY - 1 > 5800321) {
    c = b_qY - 5800322;
    c_eml_integer_colon_dispatcher(wPtr, y);
    if (b_qY - 5800322 < 1) {
      i = 0;
    } else {
      i = b_qY - 5800322;
    }
    b_y.set_size(1, i);
    if (i > 0) {
      b_y[0] = 1;
      yk = 1;
      if (i > 2147483646) {
        check_forloop_overflow_error();
      }
      for (k = 2; k <= i; k++) {
        yk++;
        b_y[k - 1] = yk;
      }
    }
    bc.set_size(1, y.size(1) + b_y.size(1));
    i = y.size(1);
    for (yk = 0; yk < i; yk++) {
      bc[yk] = y[yk];
    }
    i = b_y.size(1);
    for (yk = 0; yk < i; yk++) {
      bc[yk + y.size(1)] = b_y[yk];
    }
    if (wPtr <= rPtr) {
      qY = b_qY - rPtr;
    } else if (rPtr <= b_qY - 5800322) {
      if (rPtr < b_qY + 2141683327) {
        b_qY = MAX_int32_T;
      } else {
        b_qY = (b_qY - rPtr) - 5800322;
      }
      if (b_qY > 2147483646) {
        qY = MAX_int32_T;
      } else {
        qY = b_qY + 1;
      }
    }
  } else {
    eml_integer_colon_dispatcher(wPtr, b_qY - 1, bc);
    if ((wPtr <= rPtr) && (rPtr <= b_qY - 1)) {
      qY = b_qY - rPtr;
    }
  }
  r.set_size(bc.size(1));
  i = bc.size(1);
  for (yk = 0; yk < i; yk++) {
    if ((bc[yk] < 1) || (bc[yk] > 5800321)) {
      rtDynamicBoundsError(bc[yk], 1, 5800321, v_emlrtBCI);
    }
    r[yk] = bc[yk] - 1;
  }
  rtSubAssignSizeCheck(r.size(), 1,
                       ((::coder::array<creal32_T, 1U> *)&in)->size(), 1,
                       e_emlrtECI);
  i = in.size(0);
  for (yk = 0; yk < i; yk++) {
    pBuffer.Cache[r[yk]] = in[yk];
  }
  if (c + 1 > 5800321) {
    wPtr = 1;
  } else {
    wPtr = c + 1;
  }
  if (qY != 0) {
    rPtr = wPtr;
  }
  i = pBuffer.CumulativeOverrun;
  if ((i < 0) && (qY < MIN_int32_T - i)) {
    b_qY = MIN_int32_T;
  } else if ((i > 0) && (qY > MAX_int32_T - i)) {
    b_qY = MAX_int32_T;
  } else {
    b_qY = i + qY;
  }
  pBuffer.CumulativeOverrun = b_qY;
  pBuffer.WritePointer = wPtr;
  pBuffer.ReadPointer = rPtr;
}

void b_AsyncBuffer::write(const ::coder::array<double, 1U> &in)
{
  internal::b_AsyncBuffercgHelper *obj;
  array<int, 2U> b_y;
  array<int, 2U> bc;
  array<int, 2U> y;
  array<int, 1U> r;
  unsigned int inSize[8];
  int b_qY;
  int c;
  int i;
  int k;
  int qY;
  int rPtr;
  int wPtr;
  int yk;
  bool anyInputSizeChanged;
  bool exitg1;
  obj = &pBuffer;
  if (pBuffer.isInitialized == 2) {
    rtErrorWithMessageID("step", ob_emlrtRTEI.fName, ob_emlrtRTEI.lineNo);
  }
  if (pBuffer.isInitialized != 1) {
    cell_wrap_2 varSizes;
    pBuffer.isSetupComplete = false;
    if (pBuffer.isInitialized != 0) {
      d_rtErrorWithMessageID("setup", pb_emlrtRTEI.fName, pb_emlrtRTEI.lineNo);
    }
    pBuffer.isInitialized = 1;
    varSizes.f1[0] = static_cast<unsigned int>(in.size(0));
    varSizes.f1[1] = 1U;
    for (yk = 0; yk < 6; yk++) {
      varSizes.f1[yk + 2] = 1U;
    }
    pBuffer.inputVarSize[0] = varSizes;
    if (in.size(0) > 5800320) {
      cb_rtErrorWithMessageID(qb_emlrtRTEI.fName, qb_emlrtRTEI.lineNo);
    }
    if ((pBuffer.NumChannels != -1) && (pBuffer.NumChannels != 1)) {
      n_rtErrorWithMessageID(p_emlrtRTEI.fName, p_emlrtRTEI.lineNo);
    }
    pBuffer.NumChannels = 1;
    pBuffer.AsyncBuffercgHelper_isInitialized = true;
    for (i = 0; i < 5800321; i++) {
      pBuffer.Cache[i] = 0.0;
    }
    pBuffer.isSetupComplete = true;
    pBuffer.ReadPointer = 1;
    pBuffer.WritePointer = 2;
    pBuffer.CumulativeOverrun = 0;
    pBuffer.CumulativeUnderrun = 0;
    for (i = 0; i < 5800321; i++) {
      pBuffer.Cache[i] = 0.0;
    }
  }
  anyInputSizeChanged = false;
  inSize[0] = static_cast<unsigned int>(in.size(0));
  inSize[1] = 1U;
  for (yk = 0; yk < 6; yk++) {
    inSize[yk + 2] = 1U;
  }
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 8)) {
    if (obj->inputVarSize[0].f1[k] != inSize[k]) {
      anyInputSizeChanged = true;
      for (yk = 0; yk < 8; yk++) {
        obj->inputVarSize[0].f1[yk] = inSize[yk];
      }
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (anyInputSizeChanged) {
    if (in.size(0) > 5800320) {
      cb_rtErrorWithMessageID(qb_emlrtRTEI.fName, qb_emlrtRTEI.lineNo);
    }
    if ((pBuffer.NumChannels != -1) && (pBuffer.NumChannels != 1)) {
      n_rtErrorWithMessageID(p_emlrtRTEI.fName, p_emlrtRTEI.lineNo);
    }
  }
  wPtr = pBuffer.WritePointer;
  rPtr = pBuffer.ReadPointer;
  qY = 0;
  if ((wPtr < 1) || (wPtr > 5800321)) {
    rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
  }
  if (in.size(0) > MAX_int32_T - wPtr) {
    b_qY = MAX_int32_T;
  } else {
    b_qY = wPtr + in.size(0);
  }
  c = b_qY - 1;
  if (b_qY - 1 > 5800321) {
    c = b_qY - 5800322;
    c_eml_integer_colon_dispatcher(wPtr, y);
    if (b_qY - 5800322 < 1) {
      i = 0;
    } else {
      i = b_qY - 5800322;
    }
    b_y.set_size(1, i);
    if (i > 0) {
      b_y[0] = 1;
      yk = 1;
      if (i > 2147483646) {
        check_forloop_overflow_error();
      }
      for (k = 2; k <= i; k++) {
        yk++;
        b_y[k - 1] = yk;
      }
    }
    bc.set_size(1, y.size(1) + b_y.size(1));
    i = y.size(1);
    for (yk = 0; yk < i; yk++) {
      bc[yk] = y[yk];
    }
    i = b_y.size(1);
    for (yk = 0; yk < i; yk++) {
      bc[yk + y.size(1)] = b_y[yk];
    }
    if (wPtr <= rPtr) {
      qY = b_qY - rPtr;
    } else if (rPtr <= b_qY - 5800322) {
      if (rPtr < b_qY + 2141683327) {
        b_qY = MAX_int32_T;
      } else {
        b_qY = (b_qY - rPtr) - 5800322;
      }
      if (b_qY > 2147483646) {
        qY = MAX_int32_T;
      } else {
        qY = b_qY + 1;
      }
    }
  } else {
    eml_integer_colon_dispatcher(wPtr, b_qY - 1, bc);
    if ((wPtr <= rPtr) && (rPtr <= b_qY - 1)) {
      qY = b_qY - rPtr;
    }
  }
  r.set_size(bc.size(1));
  i = bc.size(1);
  for (yk = 0; yk < i; yk++) {
    if ((bc[yk] < 1) || (bc[yk] > 5800321)) {
      rtDynamicBoundsError(bc[yk], 1, 5800321, v_emlrtBCI);
    }
    r[yk] = bc[yk] - 1;
  }
  rtSubAssignSizeCheck(r.size(), 1, ((::coder::array<double, 1U> *)&in)->size(),
                       1, e_emlrtECI);
  i = in.size(0);
  for (yk = 0; yk < i; yk++) {
    pBuffer.Cache[r[yk]] = in[yk];
  }
  if (c + 1 > 5800321) {
    wPtr = 1;
  } else {
    wPtr = c + 1;
  }
  if (qY != 0) {
    rPtr = wPtr;
  }
  i = pBuffer.CumulativeOverrun;
  if ((i < 0) && (qY < MIN_int32_T - i)) {
    b_qY = MIN_int32_T;
  } else if ((i > 0) && (qY > MAX_int32_T - i)) {
    b_qY = MAX_int32_T;
  } else {
    b_qY = i + qY;
  }
  pBuffer.CumulativeOverrun = b_qY;
  pBuffer.WritePointer = wPtr;
  pBuffer.ReadPointer = rPtr;
}

void c_AsyncBuffer::write(const ::coder::array<creal32_T, 1U> &in)
{
  internal::c_AsyncBuffercgHelper *obj;
  array<int, 2U> b_y;
  array<int, 2U> bc;
  array<int, 2U> y;
  array<int, 1U> r;
  unsigned int inSize[8];
  int b_qY;
  int c;
  int i;
  int k;
  int qY;
  int rPtr;
  int wPtr;
  int yk;
  bool anyInputSizeChanged;
  bool exitg1;
  obj = &pBuffer;
  if (pBuffer.isInitialized == 2) {
    rtErrorWithMessageID("step", ob_emlrtRTEI.fName, ob_emlrtRTEI.lineNo);
  }
  if (pBuffer.isInitialized != 1) {
    cell_wrap_2 varSizes;
    pBuffer.isSetupComplete = false;
    if (pBuffer.isInitialized != 0) {
      d_rtErrorWithMessageID("setup", pb_emlrtRTEI.fName, pb_emlrtRTEI.lineNo);
    }
    pBuffer.isInitialized = 1;
    varSizes.f1[0] = static_cast<unsigned int>(in.size(0));
    varSizes.f1[1] = 1U;
    for (yk = 0; yk < 6; yk++) {
      varSizes.f1[yk + 2] = 1U;
    }
    pBuffer.inputVarSize[0] = varSizes;
    if (in.size(0) > 600650) {
      cb_rtErrorWithMessageID(qb_emlrtRTEI.fName, qb_emlrtRTEI.lineNo);
    }
    if ((pBuffer.NumChannels != -1) && (pBuffer.NumChannels != 1)) {
      n_rtErrorWithMessageID(p_emlrtRTEI.fName, p_emlrtRTEI.lineNo);
    }
    pBuffer.NumChannels = 1;
    pBuffer.AsyncBuffercgHelper_isInitialized = true;
    for (i = 0; i < 600651; i++) {
      pBuffer.Cache[i].re = 0.0F;
      pBuffer.Cache[i].im = 0.0F;
    }
    pBuffer.isSetupComplete = true;
    pBuffer.ReadPointer = 1;
    pBuffer.WritePointer = 2;
    pBuffer.CumulativeOverrun = 0;
    pBuffer.CumulativeUnderrun = 0;
    for (i = 0; i < 600651; i++) {
      pBuffer.Cache[i].re = 0.0F;
      pBuffer.Cache[i].im = 0.0F;
    }
  }
  anyInputSizeChanged = false;
  inSize[0] = static_cast<unsigned int>(in.size(0));
  inSize[1] = 1U;
  for (yk = 0; yk < 6; yk++) {
    inSize[yk + 2] = 1U;
  }
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 8)) {
    if (obj->inputVarSize[0].f1[k] != inSize[k]) {
      anyInputSizeChanged = true;
      for (yk = 0; yk < 8; yk++) {
        obj->inputVarSize[0].f1[yk] = inSize[yk];
      }
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (anyInputSizeChanged) {
    if (in.size(0) > 600650) {
      cb_rtErrorWithMessageID(qb_emlrtRTEI.fName, qb_emlrtRTEI.lineNo);
    }
    if ((pBuffer.NumChannels != -1) && (pBuffer.NumChannels != 1)) {
      n_rtErrorWithMessageID(p_emlrtRTEI.fName, p_emlrtRTEI.lineNo);
    }
  }
  wPtr = pBuffer.WritePointer;
  rPtr = pBuffer.ReadPointer;
  qY = 0;
  if ((wPtr < 1) || (wPtr > 600651)) {
    rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
  }
  if (in.size(0) > MAX_int32_T - wPtr) {
    b_qY = MAX_int32_T;
  } else {
    b_qY = wPtr + in.size(0);
  }
  c = b_qY - 1;
  if (b_qY - 1 > 600651) {
    c = b_qY - 600652;
    eml_integer_colon_dispatcher(wPtr, y);
    if (b_qY - 600652 < 1) {
      i = 0;
    } else {
      i = b_qY - 600652;
    }
    b_y.set_size(1, i);
    if (i > 0) {
      b_y[0] = 1;
      yk = 1;
      if (i > 2147483646) {
        check_forloop_overflow_error();
      }
      for (k = 2; k <= i; k++) {
        yk++;
        b_y[k - 1] = yk;
      }
    }
    bc.set_size(1, y.size(1) + b_y.size(1));
    i = y.size(1);
    for (yk = 0; yk < i; yk++) {
      bc[yk] = y[yk];
    }
    i = b_y.size(1);
    for (yk = 0; yk < i; yk++) {
      bc[yk + y.size(1)] = b_y[yk];
    }
    if (wPtr <= rPtr) {
      qY = b_qY - rPtr;
    } else if (rPtr <= b_qY - 600652) {
      if (rPtr < b_qY + 2146882997) {
        b_qY = MAX_int32_T;
      } else {
        b_qY = (b_qY - rPtr) - 600652;
      }
      if (b_qY > 2147483646) {
        qY = MAX_int32_T;
      } else {
        qY = b_qY + 1;
      }
    }
  } else {
    eml_integer_colon_dispatcher(wPtr, b_qY - 1, bc);
    if ((wPtr <= rPtr) && (rPtr <= b_qY - 1)) {
      qY = b_qY - rPtr;
    }
  }
  r.set_size(bc.size(1));
  i = bc.size(1);
  for (yk = 0; yk < i; yk++) {
    if ((bc[yk] < 1) || (bc[yk] > 600651)) {
      rtDynamicBoundsError(bc[yk], 1, 600651, b_emlrtBCI);
    }
    r[yk] = bc[yk] - 1;
  }
  rtSubAssignSizeCheck(r.size(), 1,
                       ((::coder::array<creal32_T, 1U> *)&in)->size(), 1,
                       e_emlrtECI);
  i = in.size(0);
  for (yk = 0; yk < i; yk++) {
    pBuffer.Cache[r[yk]] = in[yk];
  }
  if (c + 1 > 600651) {
    wPtr = 1;
  } else {
    wPtr = c + 1;
  }
  if (qY != 0) {
    rPtr = wPtr;
  }
  i = pBuffer.CumulativeOverrun;
  if ((i < 0) && (qY < MIN_int32_T - i)) {
    b_qY = MIN_int32_T;
  } else if ((i > 0) && (qY > MAX_int32_T - i)) {
    b_qY = MAX_int32_T;
  } else {
    b_qY = i + qY;
  }
  pBuffer.CumulativeOverrun = b_qY;
  pBuffer.WritePointer = wPtr;
  pBuffer.ReadPointer = rPtr;
}

} // namespace dsp
} // namespace coder

// End of code generation (AsyncBuffer.cpp)
