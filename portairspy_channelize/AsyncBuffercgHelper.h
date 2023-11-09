/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * AsyncBuffercgHelper.h
 *
 * Code generation for function 'AsyncBuffercgHelper'
 *
 */

#ifndef ASYNCBUFFERCGHELPER_H
#define ASYNCBUFFERCGHELPER_H

/* Include files */
#include "airspy_channelize_internal_types.h"
#include "airspy_channelize_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void AsyncBuffercgHelper_read(c_dsp_internal_AsyncBuffercgHel *obj, int numRows,
                              emxArray_creal32_T *out, int *underrun);

int AsyncBuffercgHelper_stepImpl(c_dsp_internal_AsyncBuffercgHel *obj,
                                 const creal32_T in_data[], int in_size);

void d_AsyncBuffercgHelper_ReadSampl(const c_dsp_internal_AsyncBuffercgHel *obj,
                                     emxArray_creal32_T *out, int *underrun,
                                     int *c);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (AsyncBuffercgHelper.h) */
