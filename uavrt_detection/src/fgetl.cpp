//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// fgetl.cpp
//
// Code generation for function 'fgetl'
//

// Include files
#include "fgetl.h"
#include "eml_int_forloop_overflow_check.h"
#include "fileManager.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdio>
#include <sstream>
#include <stdexcept>
#include <string>

// Function Declarations
static void e_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void rtErrorWithMessageID(const int i, const char *aFcnName,
                                 int aLineNum);

// Function Definitions
static void e_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream
      << "File has nothing left to read. To avoid this error, call \'feof\' to "
         "check if you have reached the end of the file before using "
         "\'fgets\' or \'fgetl\'.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

static void rtErrorWithMessageID(const int i, const char *aFcnName,
                                 int aLineNum)
{
  std::stringstream outStream;
  ((outStream << "Read illegal non-ASCII character with integer value ") << i)
      << ". For code generation, all characters must have value less than 128.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

namespace coder {
void fgetl(double fileID, ::coder::array<char, 2U> &out)
{
  static rtRunTimeErrorInfo ad_emlrtRTEI{
      145,      // lineNo
      17,       // colNo
      "cFgets", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/iofun/fgets.m" // pName
  };
  static rtRunTimeErrorInfo vc_emlrtRTEI{
      253,           // lineNo
      5,             // colNo
      "getFileStar", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/iofun/fgets.m" // pName
  };
  static rtRunTimeErrorInfo wc_emlrtRTEI{
      106,      // lineNo
      9,        // colNo
      "cFgets", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/iofun/fgets.m" // pName
  };
  static rtRunTimeErrorInfo xc_emlrtRTEI{
      72,      // lineNo
      9,       // colNo
      "fread", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/iofun/fread.m" // pName
  };
  static rtRunTimeErrorInfo yc_emlrtRTEI{
      124,      // lineNo
      17,       // colNo
      "cFgets", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/iofun/fgets.m" // pName
  };
  std::FILE *b_filestar;
  std::FILE *f;
  std::FILE *filestar;
  int b_i;
  int i;
  int i1;
  int i3;
  int reachedEndOfFile;
  bool newLineAfterCarriageReturn;
  f = internal::getfilestar(fileID, newLineAfterCarriageReturn);
  filestar = f;
  if (f == nullptr) {
    d_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
  }
  if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
    filestar = nullptr;
  }
  out.set_size(1, 0);
  if (!(filestar == nullptr)) {
    char *cOut;
    int st;
    int wherefrom;
    int exitg1;
    char ReadBuff[1024];
    bool readNewline;
    do {
      exitg1 = 0;
      cOut = std::fgets(&ReadBuff[0], 1024, filestar);
      readNewline = false;
      f = internal::getfilestar(fileID, newLineAfterCarriageReturn);
      if (f == nullptr) {
        d_rtErrorWithMessageID(d_emlrtRTEI.fName, d_emlrtRTEI.lineNo);
      } else {
        st = std::feof(f);
        reachedEndOfFile = ((int)st != 0);
      }
      if ((cOut == nullptr) && (out.size(1) == 0)) {
        e_rtErrorWithMessageID(wc_emlrtRTEI.fName, wc_emlrtRTEI.lineNo);
      }
      if (cOut == nullptr) {
        exitg1 = 1;
      } else {
        int carriageReturnAt;
        int idx;
        bool fileEndAfterCarriageReturn;
        idx = 0;
        carriageReturnAt = 0;
        if (reachedEndOfFile != 0) {
          bool exitg2;
          i = 0;
          exitg2 = false;
          while ((!exitg2) && (i < 1024)) {
            if (ReadBuff[i] == '\x00') {
              idx = i;
              exitg2 = true;
            } else {
              if (carriageReturnAt == 0) {
                b_i = static_cast<unsigned char>(ReadBuff[i]);
                if (b_i > 127) {
                  rtErrorWithMessageID(b_i, yc_emlrtRTEI.fName,
                                       yc_emlrtRTEI.lineNo);
                }
              }
              if ((carriageReturnAt == 0) && (ReadBuff[i] == '\r')) {
                carriageReturnAt = i + 1;
              }
              i++;
            }
          }
          if (ReadBuff[idx] == '\x00') {
            idx--;
          }
        } else {
          bool exitg2;
          i = 0;
          exitg2 = false;
          while ((!exitg2) && (i < 1025)) {
            if (i + 1 > 1024) {
              idx = 1022;
              exitg2 = true;
            } else if (ReadBuff[i] == '\n') {
              idx = i;
              exitg2 = true;
            } else {
              if (carriageReturnAt == 0) {
                b_i = static_cast<unsigned char>(ReadBuff[i]);
                if (b_i > 127) {
                  rtErrorWithMessageID(b_i, ad_emlrtRTEI.fName,
                                       ad_emlrtRTEI.lineNo);
                }
              }
              if ((carriageReturnAt == 0) && (ReadBuff[i] == '\r')) {
                carriageReturnAt = i + 1;
              }
              i++;
            }
          }
          readNewline = (ReadBuff[idx] == '\n');
        }
        if ((carriageReturnAt > 0) && (carriageReturnAt < 1024)) {
          newLineAfterCarriageReturn = (ReadBuff[carriageReturnAt] == '\n');
          if ((reachedEndOfFile != 0) &&
              (ReadBuff[carriageReturnAt] == '\x00')) {
            fileEndAfterCarriageReturn = true;
          } else {
            fileEndAfterCarriageReturn = false;
          }
        } else {
          newLineAfterCarriageReturn = false;
          fileEndAfterCarriageReturn = false;
        }
        if ((carriageReturnAt == 0) || newLineAfterCarriageReturn ||
            fileEndAfterCarriageReturn) {
          if (idx + 1 < 1) {
            i = 0;
          } else {
            i = idx + 1;
          }
          b_i = out.size(1);
          out.set_size(out.size(0), out.size(1) + i);
          for (int i2{0}; i2 < i; i2++) {
            out[b_i + i2] = ReadBuff[i2];
          }
        } else {
          b_i = out.size(1);
          out.set_size(out.size(0), out.size(1) + carriageReturnAt);
          for (int i2{0}; i2 < carriageReturnAt; i2++) {
            out[b_i + i2] = ReadBuff[i2];
          }
          wherefrom = SEEK_CUR;
          f = internal::getfilestar(fileID, newLineAfterCarriageReturn);
          b_filestar = f;
          if (f == nullptr) {
            d_rtErrorWithMessageID(c_emlrtRTEI.fName, c_emlrtRTEI.lineNo);
          }
          if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
            b_filestar = nullptr;
          }
          if (!(b_filestar == nullptr)) {
            std::fseek(b_filestar, (long int)((carriageReturnAt - idx) - 1),
                       wherefrom);
          }
        }
        if (readNewline || (reachedEndOfFile != 0) || (carriageReturnAt > 0)) {
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
    f = internal::getfilestar(fileID, newLineAfterCarriageReturn);
    if (f == nullptr) {
      d_rtErrorWithMessageID(d_emlrtRTEI.fName, d_emlrtRTEI.lineNo);
    } else {
      st = std::feof(f);
      i1 = ((int)st != 0);
    }
    if (i1 == 0) {
      if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
        f_rtErrorWithMessageID(xc_emlrtRTEI.fName, xc_emlrtRTEI.lineNo);
      }
      f = internal::getfilestar(fileID, newLineAfterCarriageReturn);
      filestar = f;
      if (f == nullptr) {
        d_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
      }
      if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
        filestar = nullptr;
      }
      if (!(filestar == nullptr)) {
        size_t numReadSizeT;
        unsigned char buf;
        numReadSizeT =
            std::fread(&buf, sizeof(unsigned char), (size_t)1, filestar);
        if ((int)numReadSizeT > 2147483646) {
          check_forloop_overflow_error();
        }
      }
      f = internal::getfilestar(fileID, newLineAfterCarriageReturn);
      if (f == nullptr) {
        d_rtErrorWithMessageID(d_emlrtRTEI.fName, d_emlrtRTEI.lineNo);
      } else {
        st = std::feof(f);
        i3 = ((int)st != 0);
      }
      if (i3 == 0) {
        wherefrom = SEEK_CUR;
        f = internal::getfilestar(fileID, newLineAfterCarriageReturn);
        filestar = f;
        if (f == nullptr) {
          d_rtErrorWithMessageID(c_emlrtRTEI.fName, c_emlrtRTEI.lineNo);
        }
        if ((!(fileID != 0.0)) || (!(fileID != 1.0)) || (!(fileID != 2.0))) {
          filestar = nullptr;
        }
        if (!(filestar == nullptr)) {
          std::fseek(filestar, (long int)-1.0, wherefrom);
        }
      }
    }
  }
  if (out.size(1) != 0) {
    char c;
    c = out[out.size(1) - 1];
    if (c == '\n') {
      if ((out.size(1) > 1) && (out[out.size(1) - 2] == '\r')) {
        if (out.size(1) - 2 < 1) {
          i = 0;
        } else {
          i = out.size(1) - 2;
        }
        for (b_i = 0; b_i < i; b_i++) {
          out[b_i] = out[b_i];
        }
        out.set_size(1, i);
      } else {
        if (out.size(1) - 1 < 1) {
          i = 0;
        } else {
          i = out.size(1) - 1;
        }
        for (b_i = 0; b_i < i; b_i++) {
          out[b_i] = out[b_i];
        }
        out.set_size(1, i);
      }
    } else if (c == '\r') {
      if (out.size(1) - 1 < 1) {
        i = 0;
      } else {
        i = out.size(1) - 1;
      }
      for (b_i = 0; b_i < i; b_i++) {
        out[b_i] = out[b_i];
      }
      out.set_size(1, i);
    }
  }
}

} // namespace coder

// End of code generation (fgetl.cpp)
