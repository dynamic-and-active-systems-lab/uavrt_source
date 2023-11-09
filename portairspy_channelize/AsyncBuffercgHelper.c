/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * AsyncBuffercgHelper.c
 *
 * Code generation for function 'AsyncBuffercgHelper'
 *
 */

/* Include files */
#include "AsyncBuffercgHelper.h"
#include "airspy_channelize_emxutil.h"
#include "airspy_channelize_internal_types.h"
#include "airspy_channelize_types.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"

/* Function Declarations */
static void
c_AsyncBuffercgHelper_ReadSampl(const c_dsp_internal_AsyncBuffercgHel *obj,
                                int numRowsCast, emxArray_creal32_T *out,
                                int *underrun, int *c);

/* Function Definitions */
static void
c_AsyncBuffercgHelper_ReadSampl(const c_dsp_internal_AsyncBuffercgHel *obj,
                                int numRowsCast, emxArray_creal32_T *out,
                                int *underrun, int *c)
{
  emxArray_int32_T *readIdx;
  emxArray_int32_T *y;
  creal32_T *out_data;
  int b_c;
  int b_qY;
  int k;
  int n;
  int qY;
  int rPtr;
  int wPtr;
  int yk;
  int *readIdx_data;
  int *y_data;
  rPtr = obj->ReadPointer;
  wPtr = obj->WritePointer;
  qY = 0;
  if (rPtr > 2147483646) {
    rPtr = MAX_int32_T;
  } else {
    rPtr++;
  }
  if (rPtr > 204801) {
    rPtr = 1;
  }
  if ((rPtr < 0) && (numRowsCast < MIN_int32_T - rPtr)) {
    b_qY = MIN_int32_T;
  } else if ((rPtr > 0) && (numRowsCast > MAX_int32_T - rPtr)) {
    b_qY = MAX_int32_T;
  } else {
    b_qY = rPtr + numRowsCast;
  }
  if (b_qY < -2147483647) {
    b_qY = MIN_int32_T;
  } else {
    b_qY--;
  }
  b_c = b_qY;
  emxInit_int32_T(&readIdx, 2);
  if (b_qY > 204801) {
    b_c = b_qY - 204801;
    n = 204802 - rPtr;
    k = readIdx->size[0] * readIdx->size[1];
    readIdx->size[0] = 1;
    readIdx->size[1] = 204802 - rPtr;
    emxEnsureCapacity_int32_T(readIdx, k);
    readIdx_data = readIdx->data;
    readIdx_data[0] = rPtr;
    yk = rPtr;
    for (k = 2; k <= n; k++) {
      yk++;
      readIdx_data[k - 1] = yk;
    }
    emxInit_int32_T(&y, 2);
    k = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = b_qY - 204801;
    emxEnsureCapacity_int32_T(y, k);
    y_data = y->data;
    y_data[0] = 1;
    yk = 1;
    for (k = 2; k <= b_c; k++) {
      yk++;
      y_data[k - 1] = yk;
    }
    k = readIdx->size[1];
    n = readIdx->size[0] * readIdx->size[1];
    readIdx->size[0] = 1;
    readIdx->size[1] += y->size[1];
    emxEnsureCapacity_int32_T(readIdx, n);
    readIdx_data = readIdx->data;
    yk = y->size[1];
    for (n = 0; n < yk; n++) {
      readIdx_data[n + k] = y_data[n];
    }
    emxFree_int32_T(&y);
    if (rPtr <= wPtr) {
      if (wPtr < -2147278846) {
        qY = MAX_int32_T;
      } else {
        qY = 204801 - wPtr;
      }
      if (qY > 2147483646) {
        qY = MAX_int32_T;
      } else {
        qY++;
      }
      if ((qY < 0) && (b_qY - 204801 < MIN_int32_T - qY)) {
        qY = MIN_int32_T;
      } else if ((qY > 0) && (b_qY - 204801 > MAX_int32_T - qY)) {
        qY = MAX_int32_T;
      } else {
        qY = (qY + b_qY) - 204801;
      }
    } else if (wPtr <= b_qY - 204801) {
      if (wPtr < b_qY + 2147278848) {
        b_qY = MAX_int32_T;
      } else {
        b_qY = (b_qY - wPtr) - 204801;
      }
      if (b_qY > 2147483646) {
        qY = MAX_int32_T;
      } else {
        qY = b_qY + 1;
      }
    }
  } else {
    if (b_qY < rPtr) {
      n = 0;
    } else {
      n = (b_qY - rPtr) + 1;
    }
    k = readIdx->size[0] * readIdx->size[1];
    readIdx->size[0] = 1;
    readIdx->size[1] = n;
    emxEnsureCapacity_int32_T(readIdx, k);
    readIdx_data = readIdx->data;
    if (n > 0) {
      readIdx_data[0] = rPtr;
      yk = rPtr;
      for (k = 2; k <= n; k++) {
        yk++;
        readIdx_data[k - 1] = yk;
      }
    }
    if ((rPtr <= wPtr) && (wPtr <= b_qY)) {
      if ((b_qY >= 0) && (wPtr < b_qY - MAX_int32_T)) {
        b_qY = MAX_int32_T;
      } else if ((b_qY < 0) && (wPtr > b_qY - MIN_int32_T)) {
        b_qY = MIN_int32_T;
      } else {
        b_qY -= wPtr;
      }
      if (b_qY > 2147483646) {
        qY = MAX_int32_T;
      } else {
        qY = b_qY + 1;
      }
    }
  }
  k = out->size[0];
  out->size[0] = readIdx->size[1];
  emxEnsureCapacity_creal32_T(out, k);
  out_data = out->data;
  yk = readIdx->size[1];
  for (k = 0; k < yk; k++) {
    out_data[k] = obj->Cache[readIdx_data[k] - 1];
  }
  emxFree_int32_T(&readIdx);
  if (qY != 0) {
    if ((numRowsCast >= 0) && (qY < numRowsCast - MAX_int32_T)) {
      b_qY = MAX_int32_T;
    } else if ((numRowsCast < 0) && (qY > numRowsCast - MIN_int32_T)) {
      b_qY = MIN_int32_T;
    } else {
      b_qY = numRowsCast - qY;
    }
    if (b_qY > 2147483646) {
      b_qY = MAX_int32_T;
    } else {
      b_qY++;
    }
    if (b_qY > numRowsCast) {
      b_qY = 1;
    }
    for (k = 0; k < qY; k++) {
      n = (b_qY + k) - 1;
      out_data[n].re = 0.0F;
      out_data[n].im = 0.0F;
    }
  }
  *underrun = qY;
  *c = b_c;
}

void AsyncBuffercgHelper_read(c_dsp_internal_AsyncBuffercgHel *obj, int numRows,
                              emxArray_creal32_T *out, int *underrun)
{
  emxArray_creal32_T *b_out;
  creal32_T *b_out_data;
  creal32_T *out_data;
  int b_underrun;
  int c;
  int i;
  int loop_ub;
  int wPtr;
  emxInit_creal32_T(&b_out, 1);
  wPtr = obj->WritePointer;
  c_AsyncBuffercgHelper_ReadSampl(obj, numRows, b_out, &b_underrun, &c);
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
  loop_ub = obj->CumulativeUnderrun;
  if ((loop_ub < 0) && (b_underrun < MIN_int32_T - loop_ub)) {
    loop_ub = MIN_int32_T;
  } else if ((loop_ub > 0) && (b_underrun > MAX_int32_T - loop_ub)) {
    loop_ub = MAX_int32_T;
  } else {
    loop_ub += b_underrun;
  }
  obj->CumulativeUnderrun = loop_ub;
  if (wPtr < -2147483647) {
    loop_ub = MIN_int32_T;
  } else {
    loop_ub = wPtr - 1;
  }
  if (b_underrun != 0) {
    obj->ReadPointer = loop_ub;
  } else {
    obj->ReadPointer = c;
  }
  *underrun = b_underrun;
}

int AsyncBuffercgHelper_stepImpl(c_dsp_internal_AsyncBuffercgHel *obj,
                                 const creal32_T in_data[], int in_size)
{
  emxArray_int32_T *bc;
  emxArray_int32_T *r;
  emxArray_int32_T *y;
  int c;
  int k;
  int n;
  int overrun;
  int qY;
  int rPtr;
  int wPtr;
  int yk;
  int *bc_data;
  int *y_data;
  wPtr = obj->WritePointer;
  rPtr = obj->ReadPointer;
  overrun = 0;
  if ((wPtr < 0) && (in_size < MIN_int32_T - wPtr)) {
    qY = MIN_int32_T;
  } else if ((wPtr > 0) && (in_size > MAX_int32_T - wPtr)) {
    qY = MAX_int32_T;
  } else {
    qY = wPtr + in_size;
  }
  if (qY < -2147483647) {
    qY = MIN_int32_T;
  } else {
    qY--;
  }
  c = qY;
  emxInit_int32_T(&bc, 2);
  if (qY > 204801) {
    c = qY - 204801;
    n = 204802 - wPtr;
    k = bc->size[0] * bc->size[1];
    bc->size[0] = 1;
    bc->size[1] = 204802 - wPtr;
    emxEnsureCapacity_int32_T(bc, k);
    bc_data = bc->data;
    bc_data[0] = wPtr;
    yk = wPtr;
    for (k = 2; k <= n; k++) {
      yk++;
      bc_data[k - 1] = yk;
    }
    emxInit_int32_T(&y, 2);
    k = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = qY - 204801;
    emxEnsureCapacity_int32_T(y, k);
    y_data = y->data;
    y_data[0] = 1;
    yk = 1;
    for (k = 2; k <= c; k++) {
      yk++;
      y_data[k - 1] = yk;
    }
    k = bc->size[1];
    n = bc->size[0] * bc->size[1];
    bc->size[0] = 1;
    bc->size[1] += y->size[1];
    emxEnsureCapacity_int32_T(bc, n);
    bc_data = bc->data;
    yk = y->size[1];
    for (n = 0; n < yk; n++) {
      bc_data[n + k] = y_data[n];
    }
    emxFree_int32_T(&y);
    if (wPtr <= rPtr) {
      if (rPtr < -2147278846) {
        yk = MAX_int32_T;
      } else {
        yk = 204801 - rPtr;
      }
      if (yk > 2147483646) {
        yk = MAX_int32_T;
      } else {
        yk++;
      }
      if ((yk < 0) && (qY - 204801 < MIN_int32_T - yk)) {
        overrun = MIN_int32_T;
      } else if ((yk > 0) && (qY - 204801 > MAX_int32_T - yk)) {
        overrun = MAX_int32_T;
      } else {
        overrun = (yk + qY) - 204801;
      }
    } else if (rPtr <= qY - 204801) {
      if (rPtr < qY + 2147278848) {
        qY = MAX_int32_T;
      } else {
        qY = (qY - rPtr) - 204801;
      }
      if (qY > 2147483646) {
        overrun = MAX_int32_T;
      } else {
        overrun = qY + 1;
      }
    }
  } else {
    if (qY < wPtr) {
      n = 0;
    } else {
      n = (qY - wPtr) + 1;
    }
    k = bc->size[0] * bc->size[1];
    bc->size[0] = 1;
    bc->size[1] = n;
    emxEnsureCapacity_int32_T(bc, k);
    bc_data = bc->data;
    if (n > 0) {
      bc_data[0] = wPtr;
      yk = wPtr;
      for (k = 2; k <= n; k++) {
        yk++;
        bc_data[k - 1] = yk;
      }
    }
    if ((wPtr <= rPtr) && (rPtr <= qY)) {
      if ((qY >= 0) && (rPtr < qY - MAX_int32_T)) {
        qY = MAX_int32_T;
      } else if ((qY < 0) && (rPtr > qY - MIN_int32_T)) {
        qY = MIN_int32_T;
      } else {
        qY -= rPtr;
      }
      if (qY > 2147483646) {
        overrun = MAX_int32_T;
      } else {
        overrun = qY + 1;
      }
    }
  }
  emxInit_int32_T(&r, 1);
  k = r->size[0];
  r->size[0] = bc->size[1];
  emxEnsureCapacity_int32_T(r, k);
  y_data = r->data;
  yk = bc->size[1];
  for (k = 0; k < yk; k++) {
    y_data[k] = bc_data[k] - 1;
  }
  emxFree_int32_T(&bc);
  for (k = 0; k < in_size; k++) {
    obj->Cache[y_data[k]] = in_data[k];
  }
  emxFree_int32_T(&r);
  if (c + 1 > 204801) {
    wPtr = 1;
  } else {
    wPtr = c + 1;
  }
  if (overrun != 0) {
    rPtr = wPtr;
  }
  yk = obj->CumulativeOverrun;
  if ((yk < 0) && (overrun < MIN_int32_T - yk)) {
    qY = MIN_int32_T;
  } else if ((yk > 0) && (overrun > MAX_int32_T - yk)) {
    qY = MAX_int32_T;
  } else {
    qY = yk + overrun;
  }
  obj->CumulativeOverrun = qY;
  obj->WritePointer = wPtr;
  obj->ReadPointer = rPtr;
  return overrun;
}

void d_AsyncBuffercgHelper_ReadSampl(const c_dsp_internal_AsyncBuffercgHel *obj,
                                     emxArray_creal32_T *out, int *underrun,
                                     int *c)
{
  emxArray_int32_T *readIdx;
  emxArray_int32_T *y;
  creal32_T *out_data;
  int b_c;
  int k;
  int n;
  int qY;
  int rPtr;
  int wPtr;
  int yk;
  int *readIdx_data;
  int *y_data;
  rPtr = obj->ReadPointer;
  wPtr = obj->WritePointer;
  qY = 0;
  if (rPtr > 2147483646) {
    rPtr = MAX_int32_T;
  } else {
    rPtr++;
  }
  if (rPtr > 204801) {
    rPtr = 1;
  }
  b_c = rPtr + 102399;
  emxInit_int32_T(&readIdx, 2);
  if (rPtr + 102399 > 204801) {
    int c_tmp_tmp;
    c_tmp_tmp = rPtr - 102402;
    b_c = rPtr - 102402;
    n = 204802 - rPtr;
    k = readIdx->size[0] * readIdx->size[1];
    readIdx->size[0] = 1;
    readIdx->size[1] = 204802 - rPtr;
    emxEnsureCapacity_int32_T(readIdx, k);
    readIdx_data = readIdx->data;
    readIdx_data[0] = rPtr;
    yk = rPtr;
    for (k = 2; k <= n; k++) {
      yk++;
      readIdx_data[k - 1] = yk;
    }
    emxInit_int32_T(&y, 2);
    k = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = rPtr - 102402;
    emxEnsureCapacity_int32_T(y, k);
    y_data = y->data;
    y_data[0] = 1;
    yk = 1;
    for (k = 2; k <= c_tmp_tmp; k++) {
      yk++;
      y_data[k - 1] = yk;
    }
    k = readIdx->size[1];
    n = readIdx->size[0] * readIdx->size[1];
    readIdx->size[0] = 1;
    readIdx->size[1] += y->size[1];
    emxEnsureCapacity_int32_T(readIdx, n);
    readIdx_data = readIdx->data;
    yk = y->size[1];
    for (n = 0; n < yk; n++) {
      readIdx_data[n + k] = y_data[n];
    }
    emxFree_int32_T(&y);
    if (rPtr <= wPtr) {
      if (wPtr < -2147278846) {
        qY = MAX_int32_T;
      } else {
        qY = 204801 - wPtr;
      }
      if (qY > 2147483646) {
        qY = MAX_int32_T;
      } else {
        qY++;
      }
      if ((qY < 0) && (rPtr - 102402 < MIN_int32_T - qY)) {
        qY = MIN_int32_T;
      } else if ((qY > 0) && (rPtr - 102402 > MAX_int32_T - qY)) {
        qY = MAX_int32_T;
      } else {
        qY = (qY + rPtr) - 102402;
      }
    } else if (wPtr <= rPtr - 102402) {
      if ((rPtr - 102402 >= 0) && (wPtr < rPtr + 2147381247)) {
        qY = MAX_int32_T;
      } else if ((rPtr - 102402 < 0) && (wPtr > rPtr + 2147381246)) {
        qY = MIN_int32_T;
      } else {
        qY = (rPtr - wPtr) - 102402;
      }
      if (qY > 2147483646) {
        qY = MAX_int32_T;
      } else {
        qY++;
      }
    }
  } else {
    if (rPtr + 102399 < rPtr) {
      n = 0;
    } else {
      n = 102400;
    }
    k = readIdx->size[0] * readIdx->size[1];
    readIdx->size[0] = 1;
    readIdx->size[1] = n;
    emxEnsureCapacity_int32_T(readIdx, k);
    readIdx_data = readIdx->data;
    if (n > 0) {
      readIdx_data[0] = rPtr;
      yk = rPtr;
      for (k = 2; k <= n; k++) {
        yk++;
        readIdx_data[k - 1] = yk;
      }
    }
    if ((rPtr <= wPtr) && (wPtr <= rPtr + 102399)) {
      if ((rPtr + 102399 >= 0) && (wPtr < rPtr - 2147381248)) {
        qY = MAX_int32_T;
      } else if ((rPtr + 102399 < 0) && (wPtr > rPtr - 2147381249)) {
        qY = MIN_int32_T;
      } else {
        qY = (rPtr - wPtr) + 102399;
      }
      if (qY > 2147483646) {
        qY = MAX_int32_T;
      } else {
        qY++;
      }
    }
  }
  k = out->size[0];
  out->size[0] = readIdx->size[1];
  emxEnsureCapacity_creal32_T(out, k);
  out_data = out->data;
  yk = readIdx->size[1];
  for (k = 0; k < yk; k++) {
    out_data[k] = obj->Cache[readIdx_data[k] - 1];
  }
  emxFree_int32_T(&readIdx);
  if (qY != 0) {
    if (qY < -2147381247) {
      yk = MAX_int32_T;
    } else {
      yk = 102400 - qY;
    }
    if (yk > 2147483646) {
      yk = MAX_int32_T;
    } else {
      yk++;
    }
    if (yk > 102400) {
      yk = 1;
    }
    for (k = 0; k < qY; k++) {
      n = (yk + k) - 1;
      out_data[n].re = 0.0F;
      out_data[n].im = 0.0F;
    }
  }
  *underrun = qY;
  *c = b_c;
}

/* End of code generation (AsyncBuffercgHelper.c) */
