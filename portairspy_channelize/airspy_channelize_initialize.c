/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * airspy_channelize_initialize.c
 *
 * Code generation for function 'airspy_channelize_initialize'
 *
 */

/* Include files */
#include "airspy_channelize_initialize.h"
#include "CoderTimeAPI.h"
#include "airspy_channelize_data.h"
#include "rt_nonfinite.h"
#include "timeKeeper.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "omp.h"

/* Function Definitions */
void airspy_channelize_initialize(void)
{
  omp_init_nest_lock(&airspy_channelize_nestLockGlobal);
  savedTime_not_empty_init();
  freq_not_empty_init();
  isInitialized_airspy_channelize = true;
}

/* End of code generation (airspy_channelize_initialize.c) */
