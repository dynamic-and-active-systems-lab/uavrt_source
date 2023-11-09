//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// pulseOut.cpp
//
// Code generation for function 'pulseOut'
//

// Include files
#include "pulseOut.h"
#include "dec2hex.h"
#include "mod.h"
#include "rt_nonfinite.h"
#include "string1.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include "coder_fileops.h"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstring>
#include <sstream>
#include <stdexcept>
#include <string>

// Function Declarations
static void nc_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void oc_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void pc_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void qc_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
static void nc_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Hexadecimal text must consist of characters 0-9 and A-F.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

static void oc_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Hexadecimal text has too many digits for specified or implied "
               "type suffix.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

static void pc_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Use of type suffix in hexadecimal text requires the use of 0x "
               "prefix.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

static void qc_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "To generate code remove \'{0}\' function or set "
               "\'DynamicMemoryAllocation\' configuration option to either "
               "\'AllVariableSizeArra"
               "ys\' or \'Threshold\'.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

void pulseOut::b_init()
{
  static rtDoubleCheckInfo
      w_emlrtDCI{
          12,       // lineNo
          20,       // colNo
          "blanks", // fName
          "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/strfun/"
          "blanks.m", // pName
          4           // checkKind
      };
  static rtRunTimeErrorInfo vc_emlrtRTEI{
      27,                           // lineNo
      13,                           // colNo
      "CoderFileOperationsAPI/pwd", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/"
      "CoderFileOperationsAPI.m" // pName
  };
  coder::array<char, 2U> wdTemp;
  int fileNameMax;
  // PULSEOUT Construct an instance of this class
  //    Detailed explanation goes here
  //
  // INPUTS:
  //    detectorPulse   1x1     pulse object instance (Not pulseOut
  //                            object)
  //    tagID           1x1     tag ID number from 0-65536
  //    detectorDir     1x1     string of the directory where
  //                            detector that found the pulse is
  //                            running
  //    channelCenterFreq 1x1   Center frequency of channel where
  //                            pulse was found in MHz
  //    groundInd       1x1     Index of pulse in its group
  //    groupSNR        1x1     SNR of the pulse group to which
  //                            this pulse belongs
  //    poseVect        7x1     Vetor of pose information (optional
  //                            input) with position in [x, y, x,
  //                            quat_x, quat_y, quat_z, quat_w]
  //
  // OUTPUTS:
  //    pulseOut object instance
  //
  // Build and empty object
  tag_id = 2U;
  fileNameMax = coderGetLenghtOfCwd() + 1;
  if (fileNameMax < 0) {
    rtNonNegativeError(static_cast<double>(fileNameMax), w_emlrtDCI);
  }
  wdTemp.set_size(1, fileNameMax);
  fileNameMax = coderGetCurrentDirectory(&wdTemp[0], fileNameMax);
  if (fileNameMax == -1) {
    qc_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
  }
  if (fileNameMax < 1) {
    fileNameMax = 0;
  }
  detector_dir.Value.set_size(1, fileNameMax);
  for (int i{0}; i < fileNameMax; i++) {
    detector_dir.Value[i] = wdTemp[i];
  }
  frequency = 0.0;
  start_time_sec = 0;
  start_time_nanosec = 0U;
  end_time_sec = 0;
  end_time_nanosec = 0U;
  predict_next_start_sec = 0;
  predict_next_start_nanosec = 0U;
  predict_next_end_sec = 0;
  predict_next_end_nanosec = 0U;
  snr = 0.0;
  stft_score = 0.0;
  group_ind = 0U;
  group_snr = 0.0;
  detection_status = false;
  confirmed_status = false;
}

void pulseOut::formatForTunnelMsg(unsigned char mavlinkTunnelMsgUint8[53]) const
{
  static rtRunTimeErrorInfo ad_emlrtRTEI{
      121,              // lineNo
      31,               // colNo
      "parseNumString", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/strfun/private/"
      "toDec.m" // pName
  };
  static rtRunTimeErrorInfo vc_emlrtRTEI{
      109,              // lineNo
      31,               // colNo
      "parseNumString", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/strfun/private/"
      "toDec.m" // pName
  };
  static rtRunTimeErrorInfo wc_emlrtRTEI{
      245,          // lineNo
      23,           // colNo
      "convertHex", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/strfun/private/"
      "toDec.m" // pName
  };
  static rtRunTimeErrorInfo xc_emlrtRTEI{
      154,                // lineNo
      9,                  // colNo
      "assertValidNbits", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/strfun/private/"
      "toDec.m" // pName
  };
  static rtRunTimeErrorInfo yc_emlrtRTEI{
      243,          // lineNo
      23,           // colNo
      "convertHex", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/strfun/private/"
      "toDec.m" // pName
  };
  double c_x[53];
  int b_mavlinkTunnelMsgHex_tmp;
  int i;
  int idx;
  int mavlinkTunnelMsgHex_tmp;
  int nbits;
  unsigned short b_x;
  char mavlinkTunnelMsgHex[106];
  char b_cv5[16];
  char cv10[16];
  char cv11[16];
  char b_cv4[8];
  char cv6[8];
  char cv7[8];
  char cv8[8];
  char cv9[8];
  unsigned char e_y[8];
  unsigned char j_y[8];
  unsigned char k_y[8];
  char b_cv2[4];
  char cv12[4];
  unsigned char d_y[4];
  unsigned char f_y[4];
  unsigned char g_y[4];
  unsigned char h_y[4];
  unsigned char i_y[4];
  char b_cv[2];
  char b_cv1[2];
  char b_cv3[2];
  unsigned char c_y[2];
  char cv13[2];
  char cv14[2];
  unsigned char l_y[2];
  unsigned char b_y;
  unsigned char m_y;
  unsigned char n_y;
  unsigned char o_y;
  unsigned char x;
  unsigned char y;
  // FORMATFORTUNNELMSG prepares the uint8 formatted Tunnel message
  // for transmission as a mavlink message.
  //
  // INPUTS:
  //    obj         1x1     pulseOut object to be formatted
  //    target_system_in        1x1     scalar 0-255
  //    target_component_in     1x1     scalar 0-255
  //    payload_type            1x1     scalar 0-65535
  //
  // OUTPUTS:
  //    mavlinkTunnelMsgUint8  nx1 output vector of uint8s
  // Build PulsePose Mavlink Tunnel Message Payload
  // Typecast maintains little-endian, in line
  // with the mavlink serialization standard:
  // https://mavlink.io/en/guide/serialization.html
  x = MAX_uint8_T;
  std::copy(&x, &x + 1U, &y);
  // uint8
  x = 0U;
  std::copy(&x, &x + 1U, &b_y);
  // uint8
  b_x = 0U;
  std::memcpy((void *)&c_y[0], (void *)&b_x,
              (unsigned int)((size_t)2 * sizeof(unsigned char)));
  // uint16
  std::memcpy((void *)&d_y[0], (void *)&tag_id,
              (unsigned int)((size_t)4 * sizeof(unsigned char)));
  // uint32
  std::memcpy((void *)&e_y[0], (void *)&frequency,
              (unsigned int)((size_t)8 * sizeof(unsigned char)));
  // uint32
  std::memcpy((void *)&f_y[0], (void *)&start_time_sec,
              (unsigned int)((size_t)4 * sizeof(unsigned char)));
  // int32
  std::memcpy((void *)&g_y[0], (void *)&start_time_nanosec,
              (unsigned int)((size_t)4 * sizeof(unsigned char)));
  // uint32
  std::memcpy((void *)&h_y[0], (void *)&predict_next_start_sec,
              (unsigned int)((size_t)4 * sizeof(unsigned char)));
  // int32
  std::memcpy((void *)&i_y[0], (void *)&predict_next_start_nanosec,
              (unsigned int)((size_t)4 * sizeof(unsigned char)));
  // uint32
  std::memcpy((void *)&j_y[0], (void *)&snr,
              (unsigned int)((size_t)8 * sizeof(unsigned char)));
  // double
  std::memcpy((void *)&k_y[0], (void *)&stft_score,
              (unsigned int)((size_t)8 * sizeof(unsigned char)));
  // double
  std::memcpy((void *)&l_y[0], (void *)&group_ind,
              (unsigned int)((size_t)2 * sizeof(unsigned char)));
  // uint16
  x = detection_status;
  std::copy(&x, &x + 1U, &m_y);
  // uint8
  x = confirmed_status;
  std::copy(&x, &x + 1U, &n_y);
  // uint8
  x = 48U;
  std::copy(&x, &x + 1U, &o_y);
  coder::dec2hex(y, b_cv);
  coder::dec2hex(b_y, b_cv1);
  coder::dec2hex(c_y, b_cv2);
  coder::dec2hex(o_y, b_cv3);
  coder::b_dec2hex(d_y, b_cv4);
  coder::c_dec2hex(e_y, b_cv5);
  coder::b_dec2hex(f_y, cv6);
  coder::b_dec2hex(g_y, cv7);
  coder::b_dec2hex(h_y, cv8);
  coder::b_dec2hex(i_y, cv9);
  coder::c_dec2hex(j_y, cv10);
  coder::c_dec2hex(k_y, cv11);
  coder::dec2hex(l_y, cv12);
  coder::dec2hex(m_y, cv13);
  coder::dec2hex(n_y, cv14);
  for (i = 0; i < 2; i++) {
    mavlinkTunnelMsgHex[53 * i] = b_cv[i];
    mavlinkTunnelMsgHex[53 * i + 1] = b_cv1[i];
    idx = i << 1;
    mavlinkTunnelMsgHex[53 * i + 2] = b_cv2[idx];
    mavlinkTunnelMsgHex[53 * i + 3] = b_cv2[idx + 1];
    mavlinkTunnelMsgHex[53 * i + 4] = b_cv3[i];
    mavlinkTunnelMsgHex_tmp = i << 2;
    mavlinkTunnelMsgHex[53 * i + 5] = b_cv4[mavlinkTunnelMsgHex_tmp];
    mavlinkTunnelMsgHex[53 * i + 6] = b_cv4[mavlinkTunnelMsgHex_tmp + 1];
    mavlinkTunnelMsgHex[53 * i + 7] = b_cv4[mavlinkTunnelMsgHex_tmp + 2];
    mavlinkTunnelMsgHex[53 * i + 8] = b_cv4[mavlinkTunnelMsgHex_tmp + 3];
    for (nbits = 0; nbits < 8; nbits++) {
      mavlinkTunnelMsgHex[(nbits + 53 * i) + 9] = b_cv5[nbits + (i << 3)];
    }
    mavlinkTunnelMsgHex[53 * i + 17] = cv6[mavlinkTunnelMsgHex_tmp];
    mavlinkTunnelMsgHex[53 * i + 21] = cv7[mavlinkTunnelMsgHex_tmp];
    mavlinkTunnelMsgHex[53 * i + 25] = cv8[mavlinkTunnelMsgHex_tmp];
    mavlinkTunnelMsgHex[53 * i + 29] = cv9[mavlinkTunnelMsgHex_tmp];
    mavlinkTunnelMsgHex[53 * i + 18] = cv6[mavlinkTunnelMsgHex_tmp + 1];
    mavlinkTunnelMsgHex[53 * i + 22] = cv7[mavlinkTunnelMsgHex_tmp + 1];
    mavlinkTunnelMsgHex[53 * i + 26] = cv8[mavlinkTunnelMsgHex_tmp + 1];
    mavlinkTunnelMsgHex[53 * i + 30] = cv9[mavlinkTunnelMsgHex_tmp + 1];
    mavlinkTunnelMsgHex[53 * i + 19] = cv6[mavlinkTunnelMsgHex_tmp + 2];
    mavlinkTunnelMsgHex[53 * i + 23] = cv7[mavlinkTunnelMsgHex_tmp + 2];
    mavlinkTunnelMsgHex[53 * i + 27] = cv8[mavlinkTunnelMsgHex_tmp + 2];
    mavlinkTunnelMsgHex[53 * i + 31] = cv9[mavlinkTunnelMsgHex_tmp + 2];
    mavlinkTunnelMsgHex[53 * i + 20] = cv6[mavlinkTunnelMsgHex_tmp + 3];
    mavlinkTunnelMsgHex[53 * i + 24] = cv7[mavlinkTunnelMsgHex_tmp + 3];
    mavlinkTunnelMsgHex[53 * i + 28] = cv8[mavlinkTunnelMsgHex_tmp + 3];
    mavlinkTunnelMsgHex[53 * i + 32] = cv9[mavlinkTunnelMsgHex_tmp + 3];
    for (nbits = 0; nbits < 8; nbits++) {
      mavlinkTunnelMsgHex_tmp = nbits + (i << 3);
      b_mavlinkTunnelMsgHex_tmp = nbits + 53 * i;
      mavlinkTunnelMsgHex[b_mavlinkTunnelMsgHex_tmp + 33] =
          cv10[mavlinkTunnelMsgHex_tmp];
      mavlinkTunnelMsgHex[b_mavlinkTunnelMsgHex_tmp + 41] =
          cv11[mavlinkTunnelMsgHex_tmp];
    }
    mavlinkTunnelMsgHex[53 * i + 49] = cv12[idx];
    mavlinkTunnelMsgHex[53 * i + 50] = cv12[idx + 1];
    mavlinkTunnelMsgHex[53 * i + 51] = cv13[i];
    mavlinkTunnelMsgHex[53 * i + 52] = cv14[i];
  }
  for (int k{0}; k < 53; k++) {
    unsigned long a;
    unsigned long p16;
    int b_first;
    char c;
    bool b_signed;
    bool exitg1;
    bool hasPrefix;
    b_signed = false;
    nbits = 64;
    hasPrefix = false;
    b_first = 1;
    i = static_cast<unsigned char>(mavlinkTunnelMsgHex[k]);
    if (i == 0) {
      b_first = 2;
    } else {
      if (i > 127) {
        yc_rtErrorWithMessageID(j_emlrtRTEI.fName, j_emlrtRTEI.lineNo);
      }
      if (bv[i]) {
        b_first = 2;
      }
    }
    if ((mavlinkTunnelMsgHex[k + 53 * (b_first - 1)] == '0') && (b_first < 2)) {
      c = mavlinkTunnelMsgHex[k + 53];
      if ((c == 'x') || (c == 'X')) {
        b_first = 3;
        hasPrefix = true;
      }
    }
    b_mavlinkTunnelMsgHex_tmp = 2;
    exitg1 = false;
    while ((!exitg1) && (b_mavlinkTunnelMsgHex_tmp > b_first)) {
      i = static_cast<unsigned char>(mavlinkTunnelMsgHex[k + 53]);
      if (i == 0) {
        b_mavlinkTunnelMsgHex_tmp = 1;
      } else {
        if (i > 127) {
          yc_rtErrorWithMessageID(j_emlrtRTEI.fName, j_emlrtRTEI.lineNo);
        }
        if (bv[i]) {
          b_mavlinkTunnelMsgHex_tmp = 1;
        } else {
          exitg1 = true;
        }
      }
    }
    if (hasPrefix && (b_first > b_mavlinkTunnelMsgHex_tmp)) {
      hasPrefix = false;
      b_first -= 2;
    }
    idx = b_mavlinkTunnelMsgHex_tmp - 1;
    exitg1 = false;
    while ((!exitg1) && (idx + 1 > b_first)) {
      c = mavlinkTunnelMsgHex[k + 53 * idx];
      if ((c >= '0') && (c <= '9')) {
        idx--;
      } else {
        exitg1 = true;
      }
    }
    c = mavlinkTunnelMsgHex[k + 53 * idx];
    if ((c == 's') || (c == 'S')) {
      b_signed = true;
      if (b_mavlinkTunnelMsgHex_tmp == idx + 2) {
        nbits =
            static_cast<unsigned char>(
                mavlinkTunnelMsgHex[k + 53 * (b_mavlinkTunnelMsgHex_tmp - 1)]) -
            48;
      } else if (b_mavlinkTunnelMsgHex_tmp == idx + 3) {
        nbits = (10 * (static_cast<unsigned char>(
                           mavlinkTunnelMsgHex[k + 53 * (idx + 1)]) -
                       48) +
                 static_cast<unsigned char>(mavlinkTunnelMsgHex[k + 53])) -
                48;
      } else {
        nbits = 0;
      }
      if ((nbits != 8) && (nbits != 16) && (nbits != 32) && (nbits != 64)) {
        nc_rtErrorWithMessageID(xc_emlrtRTEI.fName, xc_emlrtRTEI.lineNo);
      }
      if (!hasPrefix) {
        pc_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
      }
      b_mavlinkTunnelMsgHex_tmp = idx;
    } else if ((c == 'u') || (c == 'U')) {
      if (b_mavlinkTunnelMsgHex_tmp == idx + 2) {
        nbits =
            static_cast<unsigned char>(
                mavlinkTunnelMsgHex[k + 53 * (b_mavlinkTunnelMsgHex_tmp - 1)]) -
            48;
      } else if (b_mavlinkTunnelMsgHex_tmp == idx + 3) {
        nbits = (10 * (static_cast<unsigned char>(
                           mavlinkTunnelMsgHex[k + 53 * (idx + 1)]) -
                       48) +
                 static_cast<unsigned char>(mavlinkTunnelMsgHex[k + 53])) -
                48;
      } else {
        nbits = 0;
      }
      if ((nbits != 8) && (nbits != 16) && (nbits != 32) && (nbits != 64)) {
        nc_rtErrorWithMessageID(xc_emlrtRTEI.fName, xc_emlrtRTEI.lineNo);
      }
      if (!hasPrefix) {
        pc_rtErrorWithMessageID(ad_emlrtRTEI.fName, ad_emlrtRTEI.lineNo);
      }
      b_mavlinkTunnelMsgHex_tmp = idx;
    }
    hasPrefix = true;
    a = 0UL;
    p16 = 1UL;
    for (mavlinkTunnelMsgHex_tmp = b_mavlinkTunnelMsgHex_tmp;
         mavlinkTunnelMsgHex_tmp >= b_first; mavlinkTunnelMsgHex_tmp--) {
      unsigned long sk;
      c = mavlinkTunnelMsgHex[k + 53 * (mavlinkTunnelMsgHex_tmp - 1)];
      if ((c >= '0') && (c <= '9')) {
        sk = static_cast<unsigned long>(c) - 48UL;
      } else if ((c >= 'A') && (c <= 'F')) {
        sk = static_cast<unsigned long>(c) - 55UL;
      } else if ((c >= 'a') && (c <= 'f')) {
        sk = static_cast<unsigned long>(c) - 87UL;
      } else {
        sk = 0UL;
        hasPrefix = false;
      }
      a += sk * p16;
      p16 <<= 4;
    }
    idx = (b_mavlinkTunnelMsgHex_tmp - b_first) + 1;
    if (b_signed) {
      if (nbits == 64) {
        c_x[k] = static_cast<double>(a);
      } else if ((idx << 2 == nbits) &&
                 (mavlinkTunnelMsgHex[k + 53 * (b_first - 1)] >= '8')) {
        c_x[k] = static_cast<double>(a) - static_cast<double>(p16);
      } else {
        c_x[k] = static_cast<double>(a);
      }
    } else {
      c_x[k] = static_cast<double>(a);
    }
    if ((idx <= 0) || (!hasPrefix)) {
      nc_rtErrorWithMessageID(yc_emlrtRTEI.fName, yc_emlrtRTEI.lineNo);
    }
    if ((idx << 2) > nbits) {
      oc_rtErrorWithMessageID(wc_emlrtRTEI.fName, wc_emlrtRTEI.lineNo);
    }
  }
  for (idx = 0; idx < 53; idx++) {
    double d;
    d = std::round(c_x[idx]);
    if (d < 256.0) {
      if (d >= 0.0) {
        x = static_cast<unsigned char>(d);
      } else {
        x = 0U;
      }
    } else if (d >= 256.0) {
      x = MAX_uint8_T;
    } else {
      x = 0U;
    }
    mavlinkTunnelMsgUint8[idx] = x;
  }
}

void pulseOut::init(double detectorPulse_SNR, double detectorPulse_yw,
                    double detectorPulse_t_0, double detectorPulse_t_f,
                    const double detectorPulse_t_next[2],
                    double detectorPulse_fp, bool detectorPulse_det_dec,
                    bool detectorPulse_con_dec, double tagID,
                    const coder::array<char, 2U> &detectorDir,
                    double channelCenterFreq, double groupInd, double groupSNR)
{
  double obj_tmp;
  int i;
  int loop_ub;
  unsigned int u;
  unsigned short u1;
  // PULSEOUT Construct an instance of this class
  //    Detailed explanation goes here
  //
  // INPUTS:
  //    detectorPulse   1x1     pulse object instance (Not pulseOut
  //                            object)
  //    tagID           1x1     tag ID number from 0-65536
  //    detectorDir     1x1     string of the directory where
  //                            detector that found the pulse is
  //                            running
  //    channelCenterFreq 1x1   Center frequency of channel where
  //                            pulse was found in MHz
  //    groundInd       1x1     Index of pulse in its group
  //    groupSNR        1x1     SNR of the pulse group to which
  //                            this pulse belongs
  //    poseVect        7x1     Vetor of pose information (optional
  //                            input) with position in [x, y, x,
  //                            quat_x, quat_y, quat_z, quat_w]
  //
  // OUTPUTS:
  //    pulseOut object instance
  //
  // Inputs were provided
  obj_tmp = std::round(tagID);
  if (obj_tmp < 4.294967296E+9) {
    if (obj_tmp >= 0.0) {
      u = static_cast<unsigned int>(obj_tmp);
    } else {
      u = 0U;
    }
  } else if (obj_tmp >= 4.294967296E+9) {
    u = MAX_uint32_T;
  } else {
    u = 0U;
  }
  tag_id = u;
  detector_dir.Value.set_size(1, detectorDir.size(1));
  loop_ub = detectorDir.size(1);
  for (i = 0; i < loop_ub; i++) {
    detector_dir.Value[i] = detectorDir[i];
  }
  // ID is a string
  frequency = channelCenterFreq + detectorPulse_fp * 1.0E-6;
  obj_tmp = std::floor(detectorPulse_t_0);
  if (obj_tmp < 2.147483648E+9) {
    if (obj_tmp >= -2.147483648E+9) {
      i = static_cast<int>(obj_tmp);
    } else {
      i = MIN_int32_T;
    }
  } else if (obj_tmp >= 2.147483648E+9) {
    i = MAX_int32_T;
  } else {
    i = 0;
  }
  start_time_sec = i;
  obj_tmp = std::round(coder::b_mod(detectorPulse_t_0, obj_tmp) * 1.0E+9);
  if (obj_tmp < 4.294967296E+9) {
    if (obj_tmp >= 0.0) {
      u = static_cast<unsigned int>(obj_tmp);
    } else {
      u = 0U;
    }
  } else if (obj_tmp >= 4.294967296E+9) {
    u = MAX_uint32_T;
  } else {
    u = 0U;
  }
  start_time_nanosec = u;
  obj_tmp = std::floor(detectorPulse_t_f);
  if (obj_tmp < 2.147483648E+9) {
    if (obj_tmp >= -2.147483648E+9) {
      i = static_cast<int>(obj_tmp);
    } else {
      i = MIN_int32_T;
    }
  } else if (obj_tmp >= 2.147483648E+9) {
    i = MAX_int32_T;
  } else {
    i = 0;
  }
  end_time_sec = i;
  obj_tmp = std::round(coder::b_mod(detectorPulse_t_f, obj_tmp) * 1.0E+9);
  if (obj_tmp < 4.294967296E+9) {
    if (obj_tmp >= 0.0) {
      u = static_cast<unsigned int>(obj_tmp);
    } else {
      u = 0U;
    }
  } else if (obj_tmp >= 4.294967296E+9) {
    u = MAX_uint32_T;
  } else {
    u = 0U;
  }
  end_time_nanosec = u;
  obj_tmp = std::floor(detectorPulse_t_next[0]);
  if (obj_tmp < 2.147483648E+9) {
    if (obj_tmp >= -2.147483648E+9) {
      i = static_cast<int>(obj_tmp);
    } else {
      i = MIN_int32_T;
    }
  } else if (obj_tmp >= 2.147483648E+9) {
    i = MAX_int32_T;
  } else {
    i = 0;
  }
  predict_next_start_sec = i;
  obj_tmp = std::round(coder::b_mod(detectorPulse_t_next[0], obj_tmp) * 1.0E+9);
  if (obj_tmp < 4.294967296E+9) {
    if (obj_tmp >= 0.0) {
      u = static_cast<unsigned int>(obj_tmp);
    } else {
      u = 0U;
    }
  } else if (obj_tmp >= 4.294967296E+9) {
    u = MAX_uint32_T;
  } else {
    u = 0U;
  }
  predict_next_start_nanosec = u;
  obj_tmp = std::floor(detectorPulse_t_next[1]);
  if (obj_tmp < 2.147483648E+9) {
    if (obj_tmp >= -2.147483648E+9) {
      i = static_cast<int>(obj_tmp);
    } else {
      i = MIN_int32_T;
    }
  } else if (obj_tmp >= 2.147483648E+9) {
    i = MAX_int32_T;
  } else {
    i = 0;
  }
  predict_next_end_sec = i;
  obj_tmp = std::round(coder::b_mod(detectorPulse_t_next[1],
                                    std::round(detectorPulse_t_next[1])) *
                       1.0E+9);
  if (obj_tmp < 4.294967296E+9) {
    if (obj_tmp >= 0.0) {
      u = static_cast<unsigned int>(obj_tmp);
    } else {
      u = 0U;
    }
  } else if (obj_tmp >= 4.294967296E+9) {
    u = MAX_uint32_T;
  } else {
    u = 0U;
  }
  predict_next_end_nanosec = u;
  snr = detectorPulse_SNR;
  stft_score = detectorPulse_yw;
  obj_tmp = std::round(groupInd);
  if (obj_tmp < 65536.0) {
    if (obj_tmp >= 0.0) {
      u1 = static_cast<unsigned short>(obj_tmp);
    } else {
      u1 = 0U;
    }
  } else if (obj_tmp >= 65536.0) {
    u1 = MAX_uint16_T;
  } else {
    u1 = 0U;
  }
  group_ind = u1;
  group_snr = groupSNR;
  detection_status = detectorPulse_det_dec;
  confirmed_status = detectorPulse_con_dec;
}

// End of code generation (pulseOut.cpp)
