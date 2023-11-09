//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// xzsvdc.cpp
//
// Code generation for function 'xzsvdc'
//

// Include files
#include "xzsvdc.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"
#include "xrotg.h"
#include "xscal.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <string>

// Function Declarations
static void jb_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
static void jb_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "SVD fails to converge";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

namespace coder {
namespace internal {
namespace reflapack {
void xzsvdc(::coder::array<creal_T, 2U> &A, ::coder::array<double, 1U> &S)
{
  static rtDoubleCheckInfo w_emlrtDCI{
      37,       // lineNo
      22,       // colNo
      "xzsvdc", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/"
      "+reflapack/xzsvdc.m", // pName
      4                      // checkKind
  };
  static rtRunTimeErrorInfo vc_emlrtRTEI{
      269,      // lineNo
      13,       // colNo
      "xzsvdc", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/"
      "+reflapack/xzsvdc.m" // pName
  };
  array<creal_T, 1U> e;
  array<creal_T, 1U> s;
  array<creal_T, 1U> work;
  creal_T dc;
  double bi;
  double f;
  double rt;
  double snorm;
  double sqds;
  double test;
  int i;
  int minnp;
  int n;
  int p;
  int qjj;
  int qq;
  n = A.size(0);
  p = A.size(1);
  qjj = A.size(0) + 1;
  qq = A.size(1);
  if (qjj <= qq) {
    qq = qjj;
  }
  qjj = A.size(0);
  minnp = A.size(1);
  if (qjj <= minnp) {
    minnp = qjj;
  }
  if (qq < 0) {
    rtNonNegativeError(static_cast<double>(qq), w_emlrtDCI);
  }
  s.set_size(qq);
  for (i = 0; i < qq; i++) {
    s[i].re = 0.0;
    s[i].im = 0.0;
  }
  e.set_size(A.size(1));
  qq = A.size(1);
  for (i = 0; i < qq; i++) {
    e[i].re = 0.0;
    e[i].im = 0.0;
  }
  work.set_size(A.size(0));
  qq = A.size(0);
  for (i = 0; i < qq; i++) {
    work[i].re = 0.0;
    work[i].im = 0.0;
  }
  if ((A.size(0) != 0) && (A.size(1) != 0)) {
    creal_T t;
    double nrm;
    double re;
    double scale;
    double t_re;
    int ii;
    int iter;
    int nct;
    int nmq;
    int nrt;
    int qp1;
    bool exitg1;
    if (A.size(1) >= 2) {
      qjj = A.size(1) - 2;
    } else {
      qjj = 0;
    }
    nrt = A.size(0);
    if (qjj <= nrt) {
      nrt = qjj;
    }
    qjj = A.size(0) - 1;
    nct = A.size(1);
    if (qjj <= nct) {
      nct = qjj;
    }
    if (nct >= nrt) {
      i = nct;
    } else {
      i = nrt;
    }
    for (int q{0}; q < i; q++) {
      bool apply_transform;
      qp1 = q + 2;
      qq = q + n * q;
      nmq = n - q;
      apply_transform = false;
      if (q + 1 <= nct) {
        nrm = blas::xnrm2(nmq, A, qq + 1);
        if (nrm > 0.0) {
          apply_transform = true;
          rt = A[qq].re;
          test = A[qq].im;
          if ((rt == 0.0) && (test == 0.0)) {
            rt = 0.0;
            s[q].re = nrm;
            s[q].im = 0.0;
          } else {
            sqds = nrm / rt_hypotd_snf(rt, test);
            nrm = sqds * rt;
            rt = sqds * test;
            s[q].re = nrm;
            s[q].im = rt;
          }
          if (rt_hypotd_snf(nrm, rt) >= 1.0020841800044864E-292) {
            if (rt == 0.0) {
              dc.re = 1.0 / nrm;
              dc.im = 0.0;
            } else if (nrm == 0.0) {
              dc.re = 0.0;
              dc.im = -(1.0 / rt);
            } else {
              scale = std::abs(nrm);
              f = std::abs(rt);
              if (scale > f) {
                f = rt / nrm;
                test = nrm + f * rt;
                dc.re = (f * 0.0 + 1.0) / test;
                dc.im = (0.0 - f) / test;
              } else if (f == scale) {
                if (nrm > 0.0) {
                  f = 0.5;
                } else {
                  f = -0.5;
                }
                if (rt > 0.0) {
                  test = 0.5;
                } else {
                  test = -0.5;
                }
                dc.re = (f + 0.0 * test) / scale;
                dc.im = (0.0 * f - test) / scale;
              } else {
                f = nrm / rt;
                test = rt + f * nrm;
                dc.re = f / test;
                dc.im = (f * 0.0 - 1.0) / test;
              }
            }
            blas::xscal(nmq, dc, A, qq + 1);
          } else {
            qjj = qq + nmq;
            if ((qq + 1 <= qjj) && (qjj > 2147483646)) {
              check_forloop_overflow_error();
            }
            for (int k{qq + 1}; k <= qjj; k++) {
              rt = A[k - 1].re;
              nrm = A[k - 1].im;
              test = s[q].re;
              sqds = s[q].im;
              if (sqds == 0.0) {
                if (nrm == 0.0) {
                  re = rt / test;
                  rt = 0.0;
                } else if (rt == 0.0) {
                  re = 0.0;
                  rt = nrm / test;
                } else {
                  re = rt / test;
                  rt = nrm / test;
                }
              } else if (test == 0.0) {
                if (rt == 0.0) {
                  re = nrm / sqds;
                  rt = 0.0;
                } else if (nrm == 0.0) {
                  re = 0.0;
                  rt = -(rt / sqds);
                } else {
                  re = nrm / sqds;
                  rt = -(rt / sqds);
                }
              } else {
                scale = std::abs(test);
                f = std::abs(sqds);
                if (scale > f) {
                  f = sqds / test;
                  test += f * sqds;
                  re = (rt + f * nrm) / test;
                  rt = (nrm - f * rt) / test;
                } else if (f == scale) {
                  if (test > 0.0) {
                    f = 0.5;
                  } else {
                    f = -0.5;
                  }
                  if (sqds > 0.0) {
                    test = 0.5;
                  } else {
                    test = -0.5;
                  }
                  re = (rt * f + nrm * test) / scale;
                  rt = (nrm * f - rt * test) / scale;
                } else {
                  f = test / sqds;
                  test = sqds + f * test;
                  re = (f * rt + nrm) / test;
                  rt = (f * nrm - rt) / test;
                }
              }
              A[k - 1].re = re;
              A[k - 1].im = rt;
            }
          }
          A[qq].re = A[qq].re + 1.0;
          s[q].re = -s[q].re;
          s[q].im = -s[q].im;
        } else {
          s[q].re = 0.0;
          s[q].im = 0.0;
        }
      }
      if ((q + 2 <= p) && (p > 2147483646)) {
        check_forloop_overflow_error();
      }
      for (iter = qp1; iter <= p; iter++) {
        qjj = q + n * (iter - 1);
        if (apply_transform) {
          t = blas::xdotc(nmq, A, qq + 1, A, qjj + 1);
          test = A[q + A.size(0) * q].re;
          sqds = A[q + A.size(0) * q].im;
          if (sqds == 0.0) {
            if (t.im == 0.0) {
              t_re = t.re / test;
              test = 0.0;
            } else if (t.re == 0.0) {
              t_re = 0.0;
              test = t.im / test;
            } else {
              t_re = t.re / test;
              test = t.im / test;
            }
          } else if (test == 0.0) {
            if (t.re == 0.0) {
              t_re = t.im / sqds;
              test = 0.0;
            } else if (t.im == 0.0) {
              t_re = 0.0;
              test = -(t.re / sqds);
            } else {
              t_re = t.im / sqds;
              test = -(t.re / sqds);
            }
          } else {
            scale = std::abs(test);
            f = std::abs(sqds);
            if (scale > f) {
              f = sqds / test;
              test += f * sqds;
              t_re = (t.re + f * t.im) / test;
              test = (t.im - f * t.re) / test;
            } else if (f == scale) {
              if (test > 0.0) {
                f = 0.5;
              } else {
                f = -0.5;
              }
              if (sqds > 0.0) {
                test = 0.5;
              } else {
                test = -0.5;
              }
              t_re = (t.re * f + t.im * test) / scale;
              test = (t.im * f - t.re * test) / scale;
            } else {
              f = test / sqds;
              test = sqds + f * test;
              t_re = (f * t.re + t.im) / test;
              test = (f * t.im - t.re) / test;
            }
          }
          t.re = -t_re;
          t.im = -test;
          blas::xaxpy(nmq, t, qq + 1, A, qjj + 1);
        }
        e[iter - 1].re = A[qjj].re;
        e[iter - 1].im = -A[qjj].im;
      }
      if (q + 1 <= nrt) {
        qq = p - q;
        nrm = blas::xnrm2(qq - 1, e, q + 2);
        if (nrm == 0.0) {
          e[q].re = 0.0;
          e[q].im = 0.0;
        } else {
          test = e[q + 1].re;
          sqds = e[q + 1].im;
          if ((test == 0.0) && (sqds == 0.0)) {
            e[q].re = nrm;
            e[q].im = 0.0;
          } else {
            rt = nrm / rt_hypotd_snf(test, sqds);
            e[q].re = rt * test;
            e[q].im = rt * sqds;
          }
          t = e[q];
          if (rt_hypotd_snf(e[q].re, e[q].im) >= 1.0020841800044864E-292) {
            test = e[q].re;
            sqds = e[q].im;
            if (sqds == 0.0) {
              t.re = 1.0 / test;
              t.im = 0.0;
            } else if (test == 0.0) {
              t.re = 0.0;
              t.im = -(1.0 / sqds);
            } else {
              scale = std::abs(test);
              f = std::abs(sqds);
              if (scale > f) {
                f = sqds / test;
                test += f * sqds;
                t.re = (f * 0.0 + 1.0) / test;
                t.im = (0.0 - f) / test;
              } else if (f == scale) {
                if (test > 0.0) {
                  f = 0.5;
                } else {
                  f = -0.5;
                }
                if (sqds > 0.0) {
                  test = 0.5;
                } else {
                  test = -0.5;
                }
                t.re = (f + 0.0 * test) / scale;
                t.im = (0.0 * f - test) / scale;
              } else {
                f = test / sqds;
                test = sqds + f * test;
                t.re = f / test;
                t.im = (f * 0.0 - 1.0) / test;
              }
            }
            blas::xscal(qq - 1, t, e, q + 2);
          } else {
            qjj = q + qq;
            if ((q + 2 <= qjj) && (qjj > 2147483646)) {
              check_forloop_overflow_error();
            }
            for (int k{qp1}; k <= qjj; k++) {
              rt = e[k - 1].re;
              nrm = e[k - 1].im;
              if (t.im == 0.0) {
                if (nrm == 0.0) {
                  re = rt / t.re;
                  rt = 0.0;
                } else if (rt == 0.0) {
                  re = 0.0;
                  rt = nrm / t.re;
                } else {
                  re = rt / t.re;
                  rt = nrm / t.re;
                }
              } else if (t.re == 0.0) {
                if (rt == 0.0) {
                  re = nrm / t.im;
                  rt = 0.0;
                } else if (nrm == 0.0) {
                  re = 0.0;
                  rt = -(rt / t.im);
                } else {
                  re = nrm / t.im;
                  rt = -(rt / t.im);
                }
              } else {
                scale = std::abs(t.re);
                f = std::abs(t.im);
                if (scale > f) {
                  f = t.im / t.re;
                  test = t.re + f * t.im;
                  re = (rt + f * nrm) / test;
                  rt = (nrm - f * rt) / test;
                } else if (f == scale) {
                  if (t.re > 0.0) {
                    f = 0.5;
                  } else {
                    f = -0.5;
                  }
                  if (t.im > 0.0) {
                    test = 0.5;
                  } else {
                    test = -0.5;
                  }
                  re = (rt * f + nrm * test) / scale;
                  rt = (nrm * f - rt * test) / scale;
                } else {
                  f = t.re / t.im;
                  test = t.im + f * t.re;
                  re = (f * rt + nrm) / test;
                  rt = (f * nrm - rt) / test;
                }
              }
              e[k - 1].re = re;
              e[k - 1].im = rt;
            }
          }
          e[q + 1].re = e[q + 1].re + 1.0;
          e[q].re = -e[q].re;
          if (q + 2 <= n) {
            if ((q + 2 <= n) && (n > 2147483646)) {
              check_forloop_overflow_error();
            }
            for (ii = qp1; ii <= n; ii++) {
              work[ii - 1].re = 0.0;
              work[ii - 1].im = 0.0;
            }
            for (iter = qp1; iter <= p; iter++) {
              blas::xaxpy(nmq - 1, e[iter - 1], A, (q + n * (iter - 1)) + 2,
                          work, q + 2);
            }
            if (qp1 <= p) {
              snorm = e[q + 1].re;
              bi = e[q + 1].im;
            }
            for (iter = qp1; iter <= p; iter++) {
              rt = -e[iter - 1].re;
              nrm = -e[iter - 1].im;
              if (bi == 0.0) {
                if (nrm == 0.0) {
                  sqds = rt / snorm;
                  rt = 0.0;
                } else if (rt == 0.0) {
                  sqds = 0.0;
                  rt = nrm / snorm;
                } else {
                  sqds = rt / snorm;
                  rt = nrm / snorm;
                }
              } else if (snorm == 0.0) {
                if (rt == 0.0) {
                  sqds = nrm / bi;
                  rt = 0.0;
                } else if (nrm == 0.0) {
                  sqds = 0.0;
                  rt = -(rt / bi);
                } else {
                  sqds = nrm / bi;
                  rt = -(rt / bi);
                }
              } else {
                scale = std::abs(snorm);
                f = std::abs(bi);
                if (scale > f) {
                  f = bi / snorm;
                  test = snorm + f * bi;
                  sqds = (rt + f * nrm) / test;
                  rt = (nrm - f * rt) / test;
                } else if (f == scale) {
                  if (snorm > 0.0) {
                    f = 0.5;
                  } else {
                    f = -0.5;
                  }
                  if (bi > 0.0) {
                    test = 0.5;
                  } else {
                    test = -0.5;
                  }
                  sqds = (rt * f + nrm * test) / scale;
                  rt = (nrm * f - rt * test) / scale;
                } else {
                  f = snorm / bi;
                  test = bi + f * snorm;
                  sqds = (f * rt + nrm) / test;
                  rt = (f * nrm - rt) / test;
                }
              }
              t.re = sqds;
              t.im = -rt;
              blas::xaxpy(nmq - 1, t, work, q + 2, A, (q + n * (iter - 1)) + 2);
            }
          }
        }
      }
    }
    qjj = A.size(1);
    n = A.size(0) + 1;
    if (qjj <= n) {
      n = qjj;
    }
    if (nct < A.size(1)) {
      s[nct] = A[nct + A.size(0) * nct];
    }
    if (A.size(0) < n) {
      s[n - 1].re = 0.0;
      s[n - 1].im = 0.0;
    }
    if (nrt + 1 < n) {
      e[nrt] = A[nrt + A.size(0) * (n - 1)];
    }
    e[n - 1].re = 0.0;
    e[n - 1].im = 0.0;
    if (n > 2147483646) {
      check_forloop_overflow_error();
    }
    for (int q{0}; q < n; q++) {
      rt = s[q].re;
      test = s[q].im;
      if ((rt != 0.0) || (test != 0.0)) {
        rt = rt_hypotd_snf(rt, test);
        t = s[q];
        s[q].re = rt;
        s[q].im = 0.0;
        if (q + 1 < n) {
          if (t.im == 0.0) {
            t_re = t.re / rt;
            test = 0.0;
          } else if (t.re == 0.0) {
            t_re = 0.0;
            test = t.im / rt;
          } else {
            t_re = t.re / rt;
            test = t.im / rt;
          }
          rt = e[q].re;
          nrm = e[q].im;
          if (test == 0.0) {
            if (nrm == 0.0) {
              re = rt / t_re;
              rt = 0.0;
            } else if (rt == 0.0) {
              re = 0.0;
              rt = nrm / t_re;
            } else {
              re = rt / t_re;
              rt = nrm / t_re;
            }
          } else if (t_re == 0.0) {
            if (rt == 0.0) {
              re = nrm / test;
              rt = 0.0;
            } else if (nrm == 0.0) {
              re = 0.0;
              rt = -(rt / test);
            } else {
              re = nrm / test;
              rt = -(rt / test);
            }
          } else {
            scale = std::abs(t_re);
            f = std::abs(test);
            if (scale > f) {
              f = test / t_re;
              test = t_re + f * test;
              re = (rt + f * nrm) / test;
              rt = (nrm - f * rt) / test;
            } else if (f == scale) {
              if (t_re > 0.0) {
                f = 0.5;
              } else {
                f = -0.5;
              }
              if (test > 0.0) {
                test = 0.5;
              } else {
                test = -0.5;
              }
              re = (rt * f + nrm * test) / scale;
              rt = (nrm * f - rt * test) / scale;
            } else {
              f = t_re / test;
              test += f * t_re;
              re = (f * rt + nrm) / test;
              rt = (f * nrm - rt) / test;
            }
          }
          e[q].re = re;
          e[q].im = rt;
        }
      }
      if (q + 1 < n) {
        rt = e[q].re;
        test = e[q].im;
        if ((rt != 0.0) || (test != 0.0)) {
          rt = rt_hypotd_snf(rt, test);
          t = e[q];
          e[q].re = rt;
          e[q].im = 0.0;
          if (t.im == 0.0) {
            nrm = rt / t.re;
            rt = 0.0;
          } else if (t.re == 0.0) {
            if (rt == 0.0) {
              nrm = 0.0 / t.im;
              rt = 0.0;
            } else {
              nrm = 0.0;
              rt = -(rt / t.im);
            }
          } else {
            scale = std::abs(t.re);
            f = std::abs(t.im);
            if (scale > f) {
              f = t.im / t.re;
              test = t.re + f * t.im;
              nrm = (rt + f * 0.0) / test;
              rt = (0.0 - f * rt) / test;
            } else if (f == scale) {
              if (t.re > 0.0) {
                f = 0.5;
              } else {
                f = -0.5;
              }
              if (t.im > 0.0) {
                test = 0.5;
              } else {
                test = -0.5;
              }
              nrm = (rt * f + 0.0 * test) / scale;
              rt = (0.0 * f - rt * test) / scale;
            } else {
              f = t.re / t.im;
              test = t.im + f * t.re;
              nrm = f * rt / test;
              rt = (f * 0.0 - rt) / test;
            }
          }
          sqds = s[q + 1].re;
          test = s[q + 1].im;
          s[q + 1].re = sqds * nrm - test * rt;
          s[q + 1].im = sqds * rt + test * nrm;
        }
      }
    }
    nrt = n;
    iter = 0;
    snorm = 0.0;
    for (ii = 0; ii < n; ii++) {
      snorm =
          std::fmax(snorm, std::fmax(std::abs(s[ii].re), std::abs(e[ii].re)));
    }
    exitg1 = false;
    while ((!exitg1) && (n > 0)) {
      if (iter >= 75) {
        jb_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
      } else {
        bool exitg2;
        nmq = n - 1;
        ii = n - 1;
        exitg2 = false;
        while (!(exitg2 || (ii == 0))) {
          rt = std::abs(e[ii - 1].re);
          if ((rt <= 2.2204460492503131E-16 *
                         (std::abs(s[ii - 1].re) + std::abs(s[ii].re))) ||
              (rt <= 1.0020841800044864E-292) ||
              ((iter > 20) && (rt <= 2.2204460492503131E-16 * snorm))) {
            e[ii - 1].re = 0.0;
            e[ii - 1].im = 0.0;
            exitg2 = true;
          } else {
            ii--;
          }
        }
        if (ii == n - 1) {
          qq = 4;
        } else {
          qjj = n;
          qq = n;
          exitg2 = false;
          while ((!exitg2) && (qq >= ii)) {
            qjj = qq;
            if (qq == ii) {
              exitg2 = true;
            } else {
              test = 0.0;
              if (qq < n) {
                test = std::abs(e[qq - 1].re);
              }
              if (qq > ii + 1) {
                test += std::abs(e[qq - 2].re);
              }
              rt = std::abs(s[qq - 1].re);
              if ((rt <= 2.2204460492503131E-16 * test) ||
                  (rt <= 1.0020841800044864E-292)) {
                s[qq - 1].re = 0.0;
                s[qq - 1].im = 0.0;
                exitg2 = true;
              } else {
                qq--;
              }
            }
          }
          if (qjj == ii) {
            qq = 3;
          } else if (qjj == n) {
            qq = 1;
          } else {
            qq = 2;
            ii = qjj;
          }
        }
        switch (qq) {
        case 1:
          f = e[n - 2].re;
          e[n - 2].re = 0.0;
          e[n - 2].im = 0.0;
          for (int k{nmq}; k >= ii + 1; k--) {
            rt = s[k - 1].re;
            nrm = blas::xrotg(rt, f, sqds);
            s[k - 1].re = rt;
            s[k - 1].im = 0.0;
            if (k > ii + 1) {
              test = e[k - 2].re;
              f = -sqds * test;
              e[k - 2].re = nrm * test;
              e[k - 2].im = nrm * e[k - 2].im;
            }
          }
          break;
        case 2:
          f = e[ii - 1].re;
          e[ii - 1].re = 0.0;
          e[ii - 1].im = 0.0;
          for (int k{ii + 1}; k <= n; k++) {
            rt = s[k - 1].re;
            nrm = blas::xrotg(rt, f, sqds);
            s[k - 1].re = rt;
            s[k - 1].im = 0.0;
            test = e[k - 1].re;
            f = -sqds * test;
            e[k - 1].re = nrm * test;
            e[k - 1].im = nrm * e[k - 1].im;
          }
          break;
        case 3:
          rt = s[n - 1].re;
          test = s[n - 2].re;
          sqds = e[n - 2].re;
          nrm = s[ii].re;
          t_re = e[ii].re;
          scale = std::fmax(
              std::fmax(std::fmax(std::fmax(std::abs(rt), std::abs(test)),
                                  std::abs(sqds)),
                        std::abs(nrm)),
              std::abs(t_re));
          f = rt / scale;
          rt = test / scale;
          test = sqds / scale;
          sqds = nrm / scale;
          nrm = ((rt + f) * (rt - f) + test * test) / 2.0;
          test *= f;
          test *= test;
          if ((nrm != 0.0) || (test != 0.0)) {
            rt = nrm * nrm + test;
            if (rt < 0.0) {
              m_rtErrorWithMessageID("sqrt", yb_emlrtRTEI.fName,
                                     yb_emlrtRTEI.lineNo);
            }
            rt = std::sqrt(rt);
            if (nrm < 0.0) {
              rt = -rt;
            }
            rt = test / (nrm + rt);
          } else {
            rt = 0.0;
          }
          f = (sqds + f) * (sqds - f) + rt;
          rt = sqds * (t_re / scale);
          for (int k{ii + 1}; k <= nmq; k++) {
            nrm = blas::xrotg(f, rt, sqds);
            if (k > ii + 1) {
              e[k - 2].re = f;
              e[k - 2].im = 0.0;
            }
            rt = e[k - 1].re;
            test = s[k - 1].re;
            f = nrm * test + sqds * rt;
            e[k - 1].re = nrm * rt - sqds * test;
            e[k - 1].im = nrm * e[k - 1].im - sqds * s[k - 1].im;
            rt = s[k].re;
            test = sqds * rt;
            re = nrm * rt;
            rt = nrm * s[k].im;
            nrm = blas::xrotg(f, test, sqds);
            s[k - 1].re = f;
            s[k - 1].im = 0.0;
            test = e[k - 1].re;
            f = nrm * test + sqds * re;
            re = -sqds * test + nrm * re;
            rt = -sqds * e[k - 1].im + nrm * rt;
            s[k].re = re;
            s[k].im = rt;
            test = e[k].re;
            rt = sqds * test;
            e[k].re = nrm * test;
            e[k].im = nrm * e[k].im;
          }
          e[n - 2].re = f;
          e[n - 2].im = 0.0;
          iter++;
          break;
        default:
          if (s[ii].re < 0.0) {
            s[ii].re = -s[ii].re;
            s[ii].im = 0.0;
          }
          qp1 = ii + 1;
          while ((ii + 1 < nrt) && (s[ii].re < s[qp1].re)) {
            rt = s[ii].re;
            s[ii].re = s[qp1].re;
            s[ii].im = 0.0;
            s[qp1].re = rt;
            s[qp1].im = 0.0;
            ii = qp1;
            qp1++;
          }
          iter = 0;
          n--;
          break;
        }
      }
    }
  }
  S.set_size(minnp);
  if (minnp > 2147483646) {
    check_forloop_overflow_error();
  }
  for (int k{0}; k < minnp; k++) {
    S[k] = s[k].re;
  }
}

} // namespace reflapack
} // namespace internal
} // namespace coder

// End of code generation (xzsvdc.cpp)
