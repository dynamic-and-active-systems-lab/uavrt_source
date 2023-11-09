/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * AsyncBuffer.c
 *
 * Code generation for function 'AsyncBuffer'
 *
 */

/* Include files */
#include "AsyncBuffer.h"
#include "AsyncBuffercgHelper.h"
#include "airspy_channelize_emxutil.h"
#include "airspy_channelize_internal_types.h"
#include "airspy_channelize_types.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"

/* Function Definitions */
void AsyncBuffer_read(dsp_AsyncBuffer *obj)
{
  emxArray_creal32_T *out;
  int numRows;
  int q1;
  int qY;
  numRows = obj->pBuffer.WritePointer;
  q1 = obj->pBuffer.ReadPointer;
  if ((numRows >= 0) && (q1 < numRows - MAX_int32_T)) {
    numRows = MAX_int32_T;
  } else if ((numRows < 0) && (q1 > numRows - MIN_int32_T)) {
    numRows = MIN_int32_T;
  } else {
    numRows -= q1;
  }
  if (numRows < -2147483647) {
    numRows = MIN_int32_T;
  } else {
    numRows--;
  }
  q1 = obj->pBuffer.ReadPointer;
  if (q1 < -2147278847) {
    qY = MAX_int32_T;
  } else {
    qY = 204800 - q1;
  }
  q1 = obj->pBuffer.WritePointer;
  if ((qY < 0) && (q1 < MIN_int32_T - qY)) {
    qY = MIN_int32_T;
  } else if ((qY > 0) && (q1 > MAX_int32_T - qY)) {
    qY = MAX_int32_T;
  } else {
    qY += q1;
  }
  emxInit_creal32_T(&out, 1);
  if (obj->pBuffer.ReadPointer >= obj->pBuffer.WritePointer) {
    if (obj->pBuffer.ReadPointer == obj->pBuffer.WritePointer) {
      numRows = 204800;
    } else {
      numRows = qY;
    }
  }
  AsyncBuffercgHelper_read(&obj->pBuffer, numRows, out, &qY);
  emxFree_creal32_T(&out);
}

void AsyncBuffer_release(dsp_AsyncBuffer *obj)
{
  if (obj->pBuffer.isInitialized == 1) {
    obj->pBuffer.isInitialized = 2;
    if (obj->pBuffer.isSetupComplete) {
      obj->pBuffer.ReadPointer = 1;
      obj->pBuffer.WritePointer = 2;
      obj->pBuffer.CumulativeOverrun = 0;
      obj->pBuffer.CumulativeUnderrun = 0;
      obj->pBuffer.c_AsyncBuffercgHelper_isInitial = false;
      obj->pBuffer.NumChannels = -1;
    }
  }
}

void AsyncBuffer_write(dsp_AsyncBuffer *obj)
{
  c_dsp_internal_AsyncBuffercgHel *b_obj;
  emxArray_int32_T *bc;
  emxArray_int32_T *r;
  int i;
  int k;
  int n;
  int overrun;
  int qY;
  int rPtr;
  int wPtr;
  int *bc_data;
  int *r1;
  boolean_T exitg1;
  b_obj = &obj->pBuffer;
  if (obj->pBuffer.isInitialized != 1) {
    cell_wrap_8 varSizes;
    obj->pBuffer.isSetupComplete = false;
    obj->pBuffer.isInitialized = 1;
    for (k = 0; k < 8; k++) {
      varSizes.f1[k] = 1U;
    }
    obj->pBuffer.inputVarSize[0] = varSizes;
    obj->pBuffer.NumChannels = 1;
    obj->pBuffer.c_AsyncBuffercgHelper_isInitial = true;
    for (i = 0; i < 204801; i++) {
      obj->pBuffer.Cache[i].re = 0.0F;
      obj->pBuffer.Cache[i].im = 0.0F;
    }
    obj->pBuffer.isSetupComplete = true;
    obj->pBuffer.ReadPointer = 1;
    obj->pBuffer.WritePointer = 2;
    obj->pBuffer.CumulativeOverrun = 0;
    obj->pBuffer.CumulativeUnderrun = 0;
    for (i = 0; i < 204801; i++) {
      obj->pBuffer.Cache[i].re = 0.0F;
      obj->pBuffer.Cache[i].im = 0.0F;
    }
  }
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 8)) {
    if (b_obj->inputVarSize[0].f1[k] != 1U) {
      for (k = 0; k < 8; k++) {
        b_obj->inputVarSize[0].f1[k] = 1U;
      }
      exitg1 = true;
    } else {
      k++;
    }
  }
  b_obj = &obj->pBuffer;
  wPtr = obj->pBuffer.WritePointer;
  rPtr = obj->pBuffer.ReadPointer;
  overrun = 0;
  if (wPtr > 2147483646) {
    qY = MAX_int32_T;
  } else {
    qY = wPtr + 1;
  }
  emxInit_int32_T(&bc, 2);
  if (qY - 1 < wPtr) {
    n = 0;
  } else {
    n = qY - wPtr;
  }
  k = bc->size[0] * bc->size[1];
  bc->size[0] = 1;
  bc->size[1] = n;
  emxEnsureCapacity_int32_T(bc, k);
  bc_data = bc->data;
  if (n > 0) {
    bc_data[0] = wPtr;
    i = wPtr;
    for (k = 2; k <= n; k++) {
      i++;
      bc_data[k - 1] = i;
    }
  }
  if ((wPtr <= rPtr) && (rPtr <= qY - 1)) {
    if ((qY - 1 >= 0) && (rPtr < qY + MIN_int32_T)) {
      i = MAX_int32_T;
    } else if ((qY - 1 < 0) && (rPtr > qY + MAX_int32_T)) {
      i = MIN_int32_T;
    } else {
      i = (qY - rPtr) - 1;
    }
    if (i > 2147483646) {
      overrun = MAX_int32_T;
    } else {
      overrun = i + 1;
    }
  }
  emxInit_int32_T(&r, 1);
  k = r->size[0];
  r->size[0] = bc->size[1];
  emxEnsureCapacity_int32_T(r, k);
  r1 = r->data;
  i = bc->size[1];
  for (k = 0; k < i; k++) {
    r1[k] = bc_data[k];
  }
  emxFree_int32_T(&bc);
  i = r->size[0];
  for (k = 0; k < i; k++) {
    b_obj->Cache[r1[k] - 1].re = 1.0F;
    b_obj->Cache[r1[k] - 1].im = 1.0F;
  }
  emxFree_int32_T(&r);
  if (qY > 204801) {
    wPtr = 1;
  } else {
    wPtr = qY;
  }
  if (overrun != 0) {
    rPtr = wPtr;
  }
  i = obj->pBuffer.CumulativeOverrun;
  if ((i < 0) && (overrun < MIN_int32_T - i)) {
    qY = MIN_int32_T;
  } else if ((i > 0) && (overrun > MAX_int32_T - i)) {
    qY = MAX_int32_T;
  } else {
    qY = i + overrun;
  }
  obj->pBuffer.CumulativeOverrun = qY;
  obj->pBuffer.WritePointer = wPtr;
  obj->pBuffer.ReadPointer = rPtr;
}

void b_AsyncBuffer_read(dsp_AsyncBuffer *obj, emxArray_creal32_T *out)
{
  emxArray_creal32_T *b_out;
  creal32_T *b_out_data;
  creal32_T *out_data;
  int c;
  int i;
  int loop_ub;
  int underrun;
  int wPtr;
  emxInit_creal32_T(&b_out, 1);
  wPtr = obj->pBuffer.WritePointer;
  d_AsyncBuffercgHelper_ReadSampl(&obj->pBuffer, b_out, &underrun, &c);
  out_data = b_out->data;
  i = out->size[0];
  out->size[0] = b_out->size[0];
  emxEnsureCapacity_creal32_T(out, i);
  b_out_data = out->data;
  loop_ub = b_out->size[0];
  for (i = 0; i < loop_ub; i++) {
    b_out_data[i] = out_data[i];
  }
  emxFree_creal32_T(&b_out);
  loop_ub = obj->pBuffer.CumulativeUnderrun;
  if ((loop_ub < 0) && (underrun < MIN_int32_T - loop_ub)) {
    loop_ub = MIN_int32_T;
  } else if ((loop_ub > 0) && (underrun > MAX_int32_T - loop_ub)) {
    loop_ub = MAX_int32_T;
  } else {
    loop_ub += underrun;
  }
  obj->pBuffer.CumulativeUnderrun = loop_ub;
  if (wPtr < -2147483647) {
    loop_ub = MIN_int32_T;
  } else {
    loop_ub = wPtr - 1;
  }
  if (underrun != 0) {
    obj->pBuffer.ReadPointer = loop_ub;
  } else {
    obj->pBuffer.ReadPointer = c;
  }
}

void b_AsyncBuffer_write(dsp_AsyncBuffer *obj, const creal32_T in_data[],
                         int in_size)
{
  c_dsp_internal_AsyncBuffercgHel *b_obj;
  int i;
  short inSize[8];
  boolean_T exitg1;
  b_obj = &obj->pBuffer;
  if (obj->pBuffer.isInitialized != 1) {
    cell_wrap_8 varSizes;
    obj->pBuffer.isSetupComplete = false;
    obj->pBuffer.isInitialized = 1;
    varSizes.f1[0] = (unsigned int)in_size;
    varSizes.f1[1] = 1U;
    for (i = 0; i < 6; i++) {
      varSizes.f1[i + 2] = 1U;
    }
    obj->pBuffer.inputVarSize[0] = varSizes;
    obj->pBuffer.NumChannels = 1;
    obj->pBuffer.c_AsyncBuffercgHelper_isInitial = true;
    for (i = 0; i < 204801; i++) {
      obj->pBuffer.Cache[i].re = 0.0F;
      obj->pBuffer.Cache[i].im = 0.0F;
    }
    obj->pBuffer.isSetupComplete = true;
    obj->pBuffer.ReadPointer = 1;
    obj->pBuffer.WritePointer = 2;
    obj->pBuffer.CumulativeOverrun = 0;
    obj->pBuffer.CumulativeUnderrun = 0;
    for (i = 0; i < 204801; i++) {
      obj->pBuffer.Cache[i].re = 0.0F;
      obj->pBuffer.Cache[i].im = 0.0F;
    }
  }
  inSize[0] = (short)in_size;
  inSize[1] = 1;
  for (i = 0; i < 6; i++) {
    inSize[i + 2] = 1;
  }
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 8)) {
    if (b_obj->inputVarSize[0].f1[i] != (unsigned int)inSize[i]) {
      for (i = 0; i < 8; i++) {
        b_obj->inputVarSize[0].f1[i] = (unsigned int)inSize[i];
      }
      exitg1 = true;
    } else {
      i++;
    }
  }
  AsyncBuffercgHelper_stepImpl(&obj->pBuffer, in_data, in_size);
}

/* End of code generation (AsyncBuffer.c) */
