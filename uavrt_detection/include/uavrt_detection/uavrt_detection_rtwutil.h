//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// uavrt_detection_rtwutil.h
//
// Code generation for function 'uavrt_detection_rtwutil'
//

#ifndef UAVRT_DETECTION_RTWUTIL_H
#define UAVRT_DETECTION_RTWUTIL_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>
#include <string>

// Type Declarations
struct rtEqualityCheckInfo;

struct rtBoundsCheckInfo;

struct rtDoubleCheckInfo;

struct rtRunTimeErrorInfo;

// Function Declarations
extern void ab_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void ad_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void bc_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void c_rtErrorWithMessageID(const int i, const char *aFcnName,
                                   int aLineNum);

extern void cc_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void d_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void d_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

extern void db_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void dc_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern int div_s32(int numerator, int denominator);

extern void e_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

extern void emlrtDimSizeImpxCheckR2021b(const int aDim1, const int aDim2,
                                        const rtEqualityCheckInfo &aInfo);

extern void f_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void g_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

extern void gb_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void h_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void h_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

extern void hc_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void i_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

extern void j_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

extern void j_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void k_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void l_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void lb_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void m_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

extern void mb_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void p_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void qb_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void r_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void rtDimSizeGeqError(const int aDim1, const int aDim2,
                              const rtEqualityCheckInfo &aInfo);

extern void rtDivisionByZeroError(const rtRunTimeErrorInfo &aInfo);

extern void rtDivisionByZeroErrorN();

extern void rtDynamicBoundsError(int aIndexValue, int aLoBound, int aHiBound,
                                 const rtBoundsCheckInfo &aInfo);

extern void rtErrorWithMessageID(const char *r, const char *aFcnName,
                                 int aLineNum);

extern void rtErrorWithMessageID(const std::string r, const int i,
                                 const char *aFcnName, int aLineNum);

extern void rtErrorWithMessageID(const int i, const int i1, const int i2,
                                 const char *aFcnName, int aLineNum);

extern void rtErrorWithMessageID(const int i, const int i1,
                                 const char *aFcnName, int aLineNum);

extern void rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void rtErrorWithMessageID(const char *r, const char *r1,
                                 const char *aFcnName, int aLineNum);

extern std::string rtGenSizeString(const int aNDims, const int *aDims);

extern void rtIntegerError(const double aInteger,
                           const rtDoubleCheckInfo &aInfo);

extern bool rtIsNullOrEmptyString(const char *aString);

extern void rtNonNegativeError(const double aPositive,
                               const rtDoubleCheckInfo &aInfo);

extern void rtSizeEq1DError(const int aDim1, const int aDim2,
                            const rtEqualityCheckInfo &aInfo);

extern void rtSubAssignSizeCheck(const int *aDims1, const int aNDims1,
                                 const int *aDims2, const int aNDims2,
                                 const rtEqualityCheckInfo &aInfo);

extern double rt_hypotd_snf(double u0, double u1);

extern double rt_powd_snf(double u0, double u1);

extern void tc_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void v_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void w_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

extern void yc_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

#endif
// End of code generation (uavrt_detection_rtwutil.h)
