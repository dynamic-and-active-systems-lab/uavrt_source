//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// fileManager.cpp
//
// Code generation for function 'fileManager'
//

// Include files
#include "fileManager.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include <cstdio>
#include <sstream>
#include <stdexcept>
#include <string>

// Variable Definitions
static std::FILE *eml_openfiles[20];

static bool eml_autoflush[20];

static rtRunTimeErrorInfo e_emlrtRTEI{
    147,           // lineNo
    5,             // colNo
    "getfilestar", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/"
    "fileManager.m" // pName
};

static rtRunTimeErrorInfo f_emlrtRTEI{
    293,                     // lineNo
    1,                       // colNo
    "cast_and_validate_fid", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/"
    "fileManager.m" // pName
};

static rtRunTimeErrorInfo g_emlrtRTEI{
    297,                     // lineNo
    1,                       // colNo
    "cast_and_validate_fid", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/"
    "fileManager.m" // pName
};

static rtRunTimeErrorInfo pc_emlrtRTEI{
    111,      // lineNo
    5,        // colNo
    "cfopen", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/"
    "fileManager.m" // pName
};

// Function Declarations
static void cd_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

namespace coder {
namespace internal {
static signed char filedata();

}
} // namespace coder
static void g_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
static void cd_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  ((outStream << "For code generation, maximum number of open files is ") << 20)
      << ".";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

namespace coder {
namespace internal {
static signed char filedata()
{
  int k;
  signed char f;
  bool exitg1;
  f = 0;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 20)) {
    if (eml_openfiles[k] == nullptr) {
      f = static_cast<signed char>(k + 1);
      exitg1 = true;
    } else {
      k++;
    }
  }
  return f;
}

} // namespace internal
} // namespace coder
static void g_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Invalid file identifier.  Use fopen to generate a valid file "
               "identifier.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

namespace coder {
namespace internal {
int cfclose(double fid)
{
  static rtRunTimeErrorInfo vc_emlrtRTEI{
      168,                 // lineNo
      5,                   // colNo
      "conditionalAssert", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/"
      "fileManager.m" // pName
  };
  std::FILE *f;
  std::FILE *f_tmp;
  int cst;
  int st;
  signed char fileid;
  st = -1;
  if ((fid < 0.0) || (fid > 22.0)) {
    d_rtErrorWithMessageID(f_emlrtRTEI.fName, f_emlrtRTEI.lineNo);
  }
  fileid = static_cast<signed char>(fid);
  if (fid != static_cast<signed char>(fid)) {
    d_rtErrorWithMessageID(g_emlrtRTEI.fName, g_emlrtRTEI.lineNo);
  }
  if (static_cast<int>(fid) != static_cast<signed char>(fid)) {
    fileid = -1;
  }
  if (fileid < 0) {
    d_rtErrorWithMessageID(f_emlrtRTEI.fName, f_emlrtRTEI.lineNo);
  }
  if (fileid >= 3) {
    f_tmp = eml_openfiles[fileid - 3];
    f = f_tmp;
    if (f_tmp == nullptr) {
      g_rtErrorWithMessageID(e_emlrtRTEI.fName, e_emlrtRTEI.lineNo);
    }
  } else if (fileid == 0) {
    f = stdin;
  } else if (fileid == 1) {
    f = stdout;
  } else {
    f = stderr;
  }
  if ((!(f != nullptr)) || (fileid < 3)) {
    d_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
  }
  cst = std::fclose(f);
  if (cst == 0) {
    st = 0;
    eml_openfiles[fileid - 3] = nullptr;
    eml_autoflush[fileid - 3] = true;
  }
  return st;
}

signed char cfopen(const ::coder::array<char, 2U> &cfilename)
{
  std::FILE *filestar;
  array<char, 2U> ccfilename;
  signed char fileid;
  signed char j;
  fileid = -1;
  j = filedata();
  if (j < 1) {
    cd_rtErrorWithMessageID(pc_emlrtRTEI.fName, pc_emlrtRTEI.lineNo);
  } else {
    int i;
    int loop_ub;
    ccfilename.set_size(1, cfilename.size(1) + 1);
    loop_ub = cfilename.size(1);
    for (i = 0; i < loop_ub; i++) {
      ccfilename[i] = cfilename[i];
    }
    ccfilename[cfilename.size(1)] = '\x00';
    filestar = std::fopen(&ccfilename[0], "wb");
    if (filestar != nullptr) {
      eml_openfiles[j - 1] = filestar;
      eml_autoflush[j - 1] = true;
      i = j + 2;
      if (j + 2 > 127) {
        i = 127;
      }
      fileid = static_cast<signed char>(i);
    }
  }
  return fileid;
}

signed char cfopen(const char cfilename[25])
{
  std::FILE *filestar;
  signed char fileid;
  signed char j;
  fileid = -1;
  j = filedata();
  if (j < 1) {
    cd_rtErrorWithMessageID(pc_emlrtRTEI.fName, pc_emlrtRTEI.lineNo);
  } else {
    int i;
    char ccfilename[26];
    for (i = 0; i < 25; i++) {
      ccfilename[i] = cfilename[i];
    }
    ccfilename[25] = '\x00';
    filestar = std::fopen(&ccfilename[0], "rb");
    if (filestar != nullptr) {
      eml_openfiles[j - 1] = filestar;
      eml_autoflush[j - 1] = true;
      i = j + 2;
      if (j + 2 > 127) {
        i = 127;
      }
      fileid = static_cast<signed char>(i);
    }
  }
  return fileid;
}

std::FILE *getfilestar(double fid, bool &autoflush)
{
  std::FILE *filestar;
  std::FILE *filestar_tmp;
  signed char fileid;
  if ((fid < 0.0) || (fid > 22.0)) {
    d_rtErrorWithMessageID(f_emlrtRTEI.fName, f_emlrtRTEI.lineNo);
  }
  fileid = static_cast<signed char>(fid);
  if (fid != static_cast<signed char>(fid)) {
    d_rtErrorWithMessageID(g_emlrtRTEI.fName, g_emlrtRTEI.lineNo);
  }
  if (static_cast<int>(fid) != static_cast<signed char>(fid)) {
    fileid = -1;
  }
  if (fileid >= 3) {
    autoflush = eml_autoflush[fileid - 3];
    filestar_tmp = eml_openfiles[fileid - 3];
    filestar = filestar_tmp;
    if (filestar_tmp == nullptr) {
      g_rtErrorWithMessageID(e_emlrtRTEI.fName, e_emlrtRTEI.lineNo);
    }
  } else if (fileid == 0) {
    filestar = stdin;
    autoflush = true;
  } else if (fileid == 1) {
    filestar = stdout;
    autoflush = true;
  } else if (fileid == 2) {
    filestar = stderr;
    autoflush = true;
  } else {
    filestar = nullptr;
    autoflush = true;
  }
  return filestar;
}

} // namespace internal
} // namespace coder
void filedata_init()
{
  for (int i{0}; i < 20; i++) {
    eml_autoflush[i] = false;
  }
  for (int i{0}; i < 20; i++) {
    eml_openfiles[i] = nullptr;
  }
}

// End of code generation (fileManager.cpp)
