/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * handle.h
 *
 * Code generation for function 'handle'
 *
 */

#ifndef HANDLE_H
#define HANDLE_H

/* Include files */
#include "airspy_channelize_internal_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void b_handle_matlabCodegenDestructo(dspcodegen_UDPReceiver *obj);

void c_handle_matlabCodegenDestructo(c_dsp_internal_AsyncBuffercgHel *obj);

void d_handle_matlabCodegenDestructo(dspcodegen_UDPSender *obj);

void handle_matlabCodegenDestructor(b_dspcodegen_UDPReceiver *obj);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (handle.h) */
