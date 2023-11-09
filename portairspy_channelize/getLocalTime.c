/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * getLocalTime.c
 *
 * Code generation for function 'getLocalTime'
 *
 */

/* Include files */
#include "getLocalTime.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_posix_time.h"

/* Function Definitions */
void getLocalTime(double *t_tm_nsec, double *t_tm_sec, double *t_tm_min,
                  double *t_tm_hour, double *t_tm_mday, double *t_tm_mon,
                  double *t_tm_year, boolean_T *t_tm_isdst)
{
  coderTm structTm;
  coderLocalTime(&structTm);
  *t_tm_nsec = (double)structTm.tm_nsec;
  *t_tm_sec = structTm.tm_sec;
  *t_tm_min = structTm.tm_min;
  *t_tm_hour = structTm.tm_hour;
  *t_tm_mday = structTm.tm_mday;
  *t_tm_mon = structTm.tm_mon;
  *t_tm_year = structTm.tm_year;
  *t_tm_isdst = (structTm.tm_isdst != 0);
}

/* End of code generation (getLocalTime.c) */
