/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * airspy_channelize_terminate.c
 *
 * Code generation for function 'airspy_channelize_terminate'
 *
 */

/* Include files */
#include "airspy_channelize_terminate.h"
#include "airspy_channelize_data.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "omp.h"

/* Function Definitions */
void airspy_channelize_terminate(void)
{
  omp_destroy_nest_lock(&airspy_channelize_nestLockGlobal);
  isInitialized_airspy_channelize = false;
}

/* End of code generation (airspy_channelize_terminate.c) */
