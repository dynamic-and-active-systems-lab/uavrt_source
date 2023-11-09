/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * airspy_channelize_data.c
 *
 * Code generation for function 'airspy_channelize_data'
 *
 */

/* Include files */
#include "airspy_channelize_data.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"

/* Variable Definitions */
double freq;

boolean_T freq_not_empty;

omp_nest_lock_t airspy_channelize_nestLockGlobal;

boolean_T isInitialized_airspy_channelize = false;

/* End of code generation (airspy_channelize_data.c) */
