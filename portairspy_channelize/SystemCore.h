/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SystemCore.h
 *
 * Code generation for function 'SystemCore'
 *
 */

#ifndef SYSTEMCORE_H
#define SYSTEMCORE_H

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
void SystemCore_release(b_dspcodegen_UDPReceiver *obj);

void SystemCore_setup(b_dspcodegen_UDPReceiver *obj);

void SystemCore_step(dspcodegen_UDPSender *obj);

void b_SystemCore_release(dspcodegen_UDPReceiver *obj);

void b_SystemCore_setup(dspcodegen_UDPReceiver *obj);

void b_SystemCore_step(dspcodegen_UDPReceiver *obj,
                       creal32_T varargout_1_data[], int varargout_1_size[2]);

void c_SystemCore_step(dsp_Channelizer *obj,
                       const emxArray_creal32_T *varargin_1,
                       emxArray_creal32_T *varargout_1);

void d_SystemCore_step(b_dspcodegen_UDPReceiver *obj,
                       signed char varargout_1_data[], int varargout_1_size[2]);

void e_SystemCore_step(dspcodegen_UDPSender *obj,
                       const creal32_T varargin_1_data[]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (SystemCore.h) */
