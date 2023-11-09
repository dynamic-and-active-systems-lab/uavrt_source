/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * plus.c
 *
 * Code generation for function 'plus'
 *
 */

/* Include files */
#include "plus.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "rt_nonfinite.h"

/* Function Definitions */
creal_T plus(const creal_T a, double b)
{
  creal_T c;
  double ahi;
  double b_slo;
  double bb;
  double shi;
  double slo;
  int i;
  int trueCount;
  shi = a.re + b;
  bb = shi - a.re;
  slo = (a.re - (shi - bb)) + (b - bb);
  trueCount = 0;
  if (rtIsNaN(slo)) {
    trueCount = 1;
  }
  for (i = 0; i < trueCount; i++) {
    slo = 0.0;
  }
  bb = a.im - a.im;
  b_slo = (a.im - (a.im - bb)) + (0.0 - bb);
  trueCount = 0;
  if (rtIsNaN(b_slo)) {
    trueCount = 1;
  }
  for (i = 0; i < trueCount; i++) {
    b_slo = 0.0;
  }
  ahi = shi;
  if (a.im != 0.0) {
    slo += a.im;
    ahi = shi + slo;
    slo -= ahi - shi;
  }
  if (rtIsNaN(slo)) {
    slo = 0.0;
  }
  bb = ahi;
  if (b_slo != 0.0) {
    slo += b_slo;
    bb = ahi + slo;
    slo -= bb - ahi;
  }
  if (rtIsNaN(slo)) {
    slo = 0.0;
  }
  c.re = bb;
  c.im = slo;
  return c;
}

/* End of code generation (plus.c) */
