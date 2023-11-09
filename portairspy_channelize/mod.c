/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mod.c
 *
 * Code generation for function 'mod'
 *
 */

/* Include files */
#include "mod.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
double b_mod(double x)
{
  double r;
  if (rtIsNaN(x) || rtIsInf(x)) {
    r = rtNaN;
  } else if (x == 0.0) {
    r = 0.0;
  } else {
    r = fmod(x, 1.0);
    if (r == 0.0) {
      r = 0.0;
    } else if (x < 0.0) {
      r++;
    }
  }
  return r;
}

/* End of code generation (mod.c) */
