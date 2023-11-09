/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Channelizer.h
 *
 * Code generation for function 'Channelizer'
 *
 */

#ifndef CHANNELIZER_H
#define CHANNELIZER_H

/* Include files */
#include "airspy_channelize_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void c_Channelizer_firpolyphase_chan(const emxArray_creal32_T *x,
                                     const creal32_T v[200], creal32_T z[2400],
                                     const float p[2400],
                                     emxArray_creal32_T *y);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (Channelizer.h) */
