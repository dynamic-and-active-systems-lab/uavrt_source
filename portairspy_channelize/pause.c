/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pause.c
 *
 * Code generation for function 'pause'
 *
 */

/* Include files */
#include "pause.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_posix_time.h"

/* Function Definitions */
void pause(void)
{
  coderTimespec b_timespec;
  b_timespec.tv_sec = 0.0;
  b_timespec.tv_nsec = 2.5E+8;
  coderTimeSleep(&b_timespec);
}

/* End of code generation (pause.c) */
