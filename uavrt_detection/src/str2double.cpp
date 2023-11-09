//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// str2double.cpp
//
// Code generation for function 'str2double'
//

// Include files
#include "str2double.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include <cstdio>

// Function Declarations
namespace coder {
namespace internal {
static bool b_copysign(::coder::array<char, 2U> &s1, int &idx,
                       const ::coder::array<char, 2U> &s, int &k, int n,
                       bool &success);

static bool copydigits(::coder::array<char, 2U> &s1, int &idx,
                       const ::coder::array<char, 2U> &s, int &k, int n,
                       bool allowpoint);

static bool copyexponent(::coder::array<char, 2U> &s1, int &idx,
                         const ::coder::array<char, 2U> &s, int &k, int n);

static bool isUnitImag(const ::coder::array<char, 2U> &s, int k, int n);

static bool readNonFinite(const ::coder::array<char, 2U> &s, int &k, int n,
                          double &fv);

static bool readfloat(::coder::array<char, 2U> &s1, int &idx,
                      const ::coder::array<char, 2U> &s, int &k, int n,
                      bool &b_finite, double &nfv, bool &foundsign,
                      bool &success);

} // namespace internal
} // namespace coder

// Function Definitions
namespace coder {
namespace internal {
static bool b_copysign(::coder::array<char, 2U> &s1, int &idx,
                       const ::coder::array<char, 2U> &s, int &k, int n,
                       bool &success)
{
  bool exitg1;
  bool foundsign;
  bool isneg;
  isneg = false;
  foundsign = false;
  exitg1 = false;
  while ((!exitg1) && (k <= n)) {
    char c;
    c = s[k - 1];
    if (c == '-') {
      isneg = !isneg;
      foundsign = true;
      k++;
    } else if (c == ',') {
      k++;
    } else if (c == '+') {
      foundsign = true;
      k++;
    } else {
      if (static_cast<unsigned char>(c) > 127) {
        yc_rtErrorWithMessageID(j_emlrtRTEI.fName, j_emlrtRTEI.lineNo);
      }
      if (!bv[static_cast<unsigned char>(c) & 127]) {
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  success = (k <= n);
  if (success && isneg) {
    if ((idx >= 2) && (s1[idx - 2] == '-')) {
      s1[idx - 2] = ' ';
    } else {
      s1[idx - 1] = '-';
      idx++;
    }
  }
  return foundsign;
}

static bool copydigits(::coder::array<char, 2U> &s1, int &idx,
                       const ::coder::array<char, 2U> &s, int &k, int n,
                       bool allowpoint)
{
  bool exitg1;
  bool haspoint;
  bool success;
  success = (k <= n);
  haspoint = false;
  exitg1 = false;
  while ((!exitg1) && (success && (k <= n))) {
    char c;
    c = s[k - 1];
    if ((c >= '0') && (c <= '9')) {
      s1[idx - 1] = c;
      idx++;
      k++;
    } else if (c == '.') {
      if (allowpoint && (!haspoint)) {
        success = true;
      } else {
        success = false;
      }
      if (success) {
        s1[idx - 1] = '.';
        idx++;
        haspoint = true;
      }
      k++;
    } else if (c == ',') {
      k++;
    } else {
      exitg1 = true;
    }
  }
  return success;
}

static bool copyexponent(::coder::array<char, 2U> &s1, int &idx,
                         const ::coder::array<char, 2U> &s, int &k, int n)
{
  bool success;
  success = true;
  if (k <= n) {
    char c;
    c = s[k - 1];
    if ((c == 'E') || (c == 'e')) {
      int kexp;
      bool b_success;
      s1[idx - 1] = 'e';
      idx++;
      k++;
      while ((k <= n) && (s[k - 1] == ',')) {
        k++;
      }
      if (k <= n) {
        c = s[k - 1];
        if (c == '-') {
          s1[idx - 1] = '-';
          idx++;
          k++;
        } else if (c == '+') {
          k++;
        }
      }
      kexp = k;
      b_success = copydigits(s1, idx, s, k, n, false);
      if ((!b_success) || (k <= kexp)) {
        success = false;
      }
    }
  }
  return success;
}

static bool isUnitImag(const ::coder::array<char, 2U> &s, int k, int n)
{
  bool p;
  p = false;
  if (k <= n) {
    char c_idx_0;
    c_idx_0 = s[k - 1];
    if (c_idx_0 == 'j') {
      p = true;
    } else if (c_idx_0 == 'i') {
      if (k >= n - 1) {
        p = true;
      } else {
        int b_k;
        char c_idx_1;
        char c_idx_2;
        b_k = k;
        c_idx_0 = '\x00';
        while ((b_k <= n) && (s[b_k - 1] == ',')) {
          b_k++;
        }
        if (b_k <= n) {
          c_idx_0 = s[b_k - 1];
        }
        b_k++;
        c_idx_1 = '\x00';
        while ((b_k <= n) && (s[b_k - 1] == ',')) {
          b_k++;
        }
        if (b_k <= n) {
          c_idx_1 = s[b_k - 1];
        }
        b_k++;
        c_idx_2 = '\x00';
        while ((b_k <= n) && (s[b_k - 1] == ',')) {
          b_k++;
        }
        if (b_k <= n) {
          c_idx_2 = s[b_k - 1];
        }
        if ((((c_idx_0 != 'I') && (c_idx_0 != 'i')) ||
             ((c_idx_1 != 'N') && (c_idx_1 != 'n')) ||
             ((c_idx_2 != 'F') && (c_idx_2 != 'f'))) &&
            (((c_idx_0 != 'N') && (c_idx_0 != 'n')) ||
             ((c_idx_1 != 'A') && (c_idx_1 != 'a')) ||
             ((c_idx_2 != 'N') && (c_idx_2 != 'n')))) {
          p = true;
        }
      }
    }
  }
  return p;
}

static bool readNonFinite(const ::coder::array<char, 2U> &s, int &k, int n,
                          double &fv)
{
  int ksaved;
  char c_idx_0;
  char c_idx_1;
  char c_idx_2;
  bool b_finite;
  ksaved = k;
  c_idx_0 = '\x00';
  while ((k <= n) && (s[k - 1] == ',')) {
    k++;
  }
  if (k <= n) {
    c_idx_0 = s[k - 1];
  }
  k++;
  c_idx_1 = '\x00';
  while ((k <= n) && (s[k - 1] == ',')) {
    k++;
  }
  if (k <= n) {
    c_idx_1 = s[k - 1];
  }
  k++;
  c_idx_2 = '\x00';
  while ((k <= n) && (s[k - 1] == ',')) {
    k++;
  }
  if (k <= n) {
    c_idx_2 = s[k - 1];
  }
  k++;
  if (((c_idx_0 == 'I') || (c_idx_0 == 'i')) &&
      ((c_idx_1 == 'N') || (c_idx_1 == 'n')) &&
      ((c_idx_2 == 'F') || (c_idx_2 == 'f'))) {
    b_finite = false;
    fv = rtInf;
  } else if (((c_idx_0 == 'N') || (c_idx_0 == 'n')) &&
             ((c_idx_1 == 'A') || (c_idx_1 == 'a')) &&
             ((c_idx_2 == 'N') || (c_idx_2 == 'n'))) {
    b_finite = false;
    fv = rtNaN;
  } else {
    b_finite = true;
    fv = 0.0;
    k = ksaved;
  }
  return b_finite;
}

static bool readfloat(::coder::array<char, 2U> &s1, int &idx,
                      const ::coder::array<char, 2U> &s, int &k, int n,
                      bool &b_finite, double &nfv, bool &foundsign,
                      bool &success)
{
  int b_idx;
  bool isimag;
  isimag = false;
  b_finite = true;
  nfv = 0.0;
  b_idx = idx;
  foundsign = b_copysign(s1, b_idx, s, k, n, success);
  idx = b_idx;
  if (success) {
    char c;
    if (isUnitImag(s, k, n)) {
      bool exitg4;
      isimag = true;
      k++;
      exitg4 = false;
      while ((!exitg4) && (k <= n)) {
        c = s[k - 1];
        if (static_cast<unsigned char>(c) > 127) {
          yc_rtErrorWithMessageID(j_emlrtRTEI.fName, j_emlrtRTEI.lineNo);
        }
        if (bv[static_cast<unsigned char>(c) & 127] || (c == '\x00') ||
            (c == ',')) {
          k++;
        } else {
          exitg4 = true;
        }
      }
      if ((k <= n) && (s[k - 1] == '*')) {
        k++;
        b_copysign(s1, b_idx, s, k, n, success);
        idx = b_idx;
        if (success) {
          if (isUnitImag(s, k, n)) {
            success = false;
          } else {
            b_finite = readNonFinite(s, k, n, nfv);
            if (b_finite) {
              success = copydigits(s1, idx, s, k, n, true);
              if (success) {
                success = copyexponent(s1, idx, s, k, n);
              }
            } else if ((b_idx >= 2) && (s1[b_idx - 2] == '-')) {
              idx = b_idx - 1;
              s1[b_idx - 2] = ' ';
              nfv = -nfv;
            }
            exitg4 = false;
            while ((!exitg4) && (k <= n)) {
              c = s[k - 1];
              if (static_cast<unsigned char>(c) > 127) {
                yc_rtErrorWithMessageID(j_emlrtRTEI.fName, j_emlrtRTEI.lineNo);
              }
              if (bv[static_cast<unsigned char>(c) & 127] || (c == '\x00') ||
                  (c == ',')) {
                k++;
              } else {
                exitg4 = true;
              }
            }
            if ((k <= n) && (s[k - 1] == '*')) {
              k++;
              exitg4 = false;
              while ((!exitg4) && (k <= n)) {
                c = s[k - 1];
                if (static_cast<unsigned char>(c) > 127) {
                  yc_rtErrorWithMessageID(j_emlrtRTEI.fName,
                                          j_emlrtRTEI.lineNo);
                }
                if (bv[static_cast<unsigned char>(c) & 127] || (c == '\x00') ||
                    (c == ',')) {
                  k++;
                } else {
                  exitg4 = true;
                }
              }
            }
            if (k <= n) {
              c = s[k - 1];
              if ((c == 'i') || (c == 'j')) {
                k++;
              }
            }
          }
          int exitg3;
          do {
            exitg3 = 0;
            if (k <= n) {
              c = s[k - 1];
              if (static_cast<unsigned char>(c) > 127) {
                yc_rtErrorWithMessageID(j_emlrtRTEI.fName, j_emlrtRTEI.lineNo);
              }
              if (bv[static_cast<unsigned char>(c) & 127] || (c == '\x00') ||
                  (c == ',')) {
                k++;
              } else {
                exitg3 = 1;
              }
            } else {
              exitg3 = 2;
            }
          } while (exitg3 == 0);
        }
      } else {
        s1[b_idx - 1] = '1';
        idx = b_idx + 1;
      }
    } else {
      bool exitg4;
      b_finite = readNonFinite(s, k, n, nfv);
      if (b_finite) {
        success = copydigits(s1, idx, s, k, n, true);
        if (success) {
          success = copyexponent(s1, idx, s, k, n);
        }
      } else if ((b_idx >= 2) && (s1[b_idx - 2] == '-')) {
        idx = b_idx - 1;
        s1[b_idx - 2] = ' ';
        nfv = -nfv;
      }
      exitg4 = false;
      while ((!exitg4) && (k <= n)) {
        c = s[k - 1];
        if (static_cast<unsigned char>(c) > 127) {
          yc_rtErrorWithMessageID(j_emlrtRTEI.fName, j_emlrtRTEI.lineNo);
        }
        if (bv[static_cast<unsigned char>(c) & 127] || (c == '\x00') ||
            (c == ',')) {
          k++;
        } else {
          exitg4 = true;
        }
      }
      if ((k <= n) && (s[k - 1] == '*')) {
        k++;
        exitg4 = false;
        while ((!exitg4) && (k <= n)) {
          c = s[k - 1];
          if (static_cast<unsigned char>(c) > 127) {
            yc_rtErrorWithMessageID(j_emlrtRTEI.fName, j_emlrtRTEI.lineNo);
          }
          if (bv[static_cast<unsigned char>(c) & 127] || (c == '\x00') ||
              (c == ',')) {
            k++;
          } else {
            exitg4 = true;
          }
        }
      }
      if (k <= n) {
        c = s[k - 1];
        if ((c == 'i') || (c == 'j')) {
          k++;
          isimag = true;
        }
      }
    }
    int exitg2;
    do {
      exitg2 = 0;
      if (k <= n) {
        c = s[k - 1];
        if (static_cast<unsigned char>(c) > 127) {
          yc_rtErrorWithMessageID(j_emlrtRTEI.fName, j_emlrtRTEI.lineNo);
        }
        if (bv[static_cast<unsigned char>(c) & 127] || (c == '\x00') ||
            (c == ',')) {
          k++;
        } else {
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);
  }
  return isimag;
}

creal_T str2double(const ::coder::array<char, 2U> &s)
{
  static rtDoubleCheckInfo w_emlrtDCI{
      31,           // lineNo
      27,           // colNo
      "str2double", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/"
      "str2double.m", // pName
      4               // checkKind
  };
  array<char, 2U> s1;
  creal_T x;
  double scanned1;
  double scanned2;
  bool a__1;
  bool foundsign;
  bool isfinite1;
  bool isfinite2;
  bool success;
  x.re = rtNaN;
  x.im = 0.0;
  if (s.size(1) >= 1) {
    int i;
    int idx;
    int k;
    int ntoread;
    bool exitg1;
    bool isimag1;
    if (s.size(1) + 2 < 0) {
      rtNonNegativeError(static_cast<double>(s.size(1) + 2), w_emlrtDCI);
    }
    if (s.size(1) + 2 > 2147483646) {
      check_forloop_overflow_error();
    }
    ntoread = 0;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k + 1 <= s.size(1))) {
      i = static_cast<unsigned char>(s[k]);
      if (i > 127) {
        yc_rtErrorWithMessageID(j_emlrtRTEI.fName, j_emlrtRTEI.lineNo);
      }
      if (bv[i] || (s[k] == '\x00')) {
        k++;
      } else {
        exitg1 = true;
      }
    }
    s1.set_size(1, s.size(1) + 2);
    idx = s.size(1) + 2;
    for (i = 0; i < idx; i++) {
      s1[i] = '\x00';
    }
    idx = 1;
    k++;
    isimag1 =
        readfloat(s1, idx, s, k, s.size(1), isfinite1, scanned1, a__1, success);
    if (isfinite1) {
      ntoread = 1;
    }
    if (success && (k <= s.size(1))) {
      s1[idx - 1] = ' ';
      idx++;
      a__1 = readfloat(s1, idx, s, k, s.size(1), isfinite2, scanned2, foundsign,
                       success);
      if (isfinite2) {
        ntoread++;
      }
      if (success && (k > s.size(1)) && (isimag1 ^ a__1) && foundsign) {
        success = true;
      } else {
        success = false;
      }
    } else {
      scanned2 = 0.0;
    }
    if (success) {
      s1[idx - 1] = '\x00';
      if (ntoread == 2) {
        idx = std::sscanf(&s1[0], "%lf %lf", &scanned1, &scanned2);
        if (idx != 2) {
          scanned1 = rtNaN;
          scanned2 = rtNaN;
        }
      } else if (ntoread == 1) {
        double b_scanned1;
        idx = std::sscanf(&s1[0], "%lf", &b_scanned1);
        if (idx != 1) {
          b_scanned1 = rtNaN;
        }
        if (isfinite1) {
          scanned1 = b_scanned1;
        } else {
          scanned2 = b_scanned1;
        }
      }
      if (isimag1) {
        x.re = scanned2;
        x.im = scanned1;
      } else {
        x.re = scanned1;
        x.im = scanned2;
      }
    }
  }
  return x;
}

} // namespace internal
} // namespace coder

// End of code generation (str2double.cpp)
