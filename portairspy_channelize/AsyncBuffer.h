/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * AsyncBuffer.h
 *
 * Code generation for function 'AsyncBuffer'
 *
 */

#ifndef ASYNCBUFFER_H
#define ASYNCBUFFER_H

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
void AsyncBuffer_read(dsp_AsyncBuffer *obj);

void AsyncBuffer_release(dsp_AsyncBuffer *obj);

void AsyncBuffer_write(dsp_AsyncBuffer *obj);

void b_AsyncBuffer_read(dsp_AsyncBuffer *obj, emxArray_creal32_T *out);

void b_AsyncBuffer_write(dsp_AsyncBuffer *obj, const creal32_T in_data[],
                         int in_size);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (AsyncBuffer.h) */
