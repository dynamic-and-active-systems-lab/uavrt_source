/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Channelizer.c
 *
 * Code generation for function 'Channelizer'
 *
 */

/* Include files */
#include "Channelizer.h"
#include "FFTImplementationCallback.h"
#include "airspy_channelize_emxutil.h"
#include "airspy_channelize_types.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include <string.h>

/* Function Definitions */
void c_Channelizer_firpolyphase_chan(const emxArray_creal32_T *x,
                                     const creal32_T v[200], creal32_T z[2400],
                                     const float p[2400], emxArray_creal32_T *y)
{
  static creal32_T b_z[2200];
  emxArray_creal32_T *b_v;
  emxArray_creal32_T *c_v;
  emxArray_creal32_T *r;
  const creal32_T *x_data;
  creal32_T *v_data;
  creal32_T *y_data;
  float b_p_re;
  float b_p_re_tmp;
  float c_p_re_tmp;
  float p_im;
  float p_re;
  int i;
  int mm;
  int nn;
  int p_re_tmp;
  int vidx;
  x_data = x->data;
  emxInit_creal32_T(&b_v, 2);
  i = b_v->size[0] * b_v->size[1];
  b_v->size[0] = 1024;
  b_v->size[1] = 200;
  emxEnsureCapacity_creal32_T(b_v, i);
  y_data = b_v->data;
  for (i = 0; i < 200; i++) {
    y_data[1024 * i] = v[i];
    for (vidx = 0; vidx < 1023; vidx++) {
      p_re_tmp = (vidx + 1024 * i) + 1;
      y_data[p_re_tmp].re = 0.0F;
      y_data[p_re_tmp].im = 0.0F;
    }
  }
  z[0] = x_data[0];
  for (mm = 0; mm < 200; mm++) {
    p_re = 0.0F;
    p_im = 0.0F;
    for (i = 0; i < 12; i++) {
      p_re_tmp = mm + 200 * i;
      b_p_re = p[p_re_tmp];
      b_p_re_tmp = z[p_re_tmp].im;
      c_p_re_tmp = z[p_re_tmp].re;
      p_re += b_p_re * c_p_re_tmp - 0.0F * b_p_re_tmp;
      p_im += b_p_re * b_p_re_tmp + 0.0F * c_p_re_tmp;
    }
    if (mm + 1 == 1) {
      p_re_tmp = 0;
    } else {
      p_re_tmp = 200 - mm;
    }
    y_data[1024 * p_re_tmp].re = p_re;
    if (mm + 1 == 1) {
      p_re_tmp = 0;
    } else {
      p_re_tmp = 200 - mm;
    }
    y_data[1024 * p_re_tmp].im = p_im;
  }
  vidx = 1;
  for (nn = 0; nn <= 204599; nn += 200) {
    memcpy(&b_z[0], &z[0], 2200U * sizeof(creal32_T));
    memcpy(&z[200], &b_z[0], 2200U * sizeof(creal32_T));
    for (i = 0; i < 200; i++) {
      z[i] = x_data[(nn - i) + 200];
    }
    for (mm = 0; mm < 200; mm++) {
      p_re = 0.0F;
      p_im = 0.0F;
      for (i = 0; i < 12; i++) {
        p_re_tmp = mm + 200 * i;
        b_p_re = p[p_re_tmp];
        b_p_re_tmp = z[p_re_tmp].im;
        c_p_re_tmp = z[p_re_tmp].re;
        p_re += b_p_re * c_p_re_tmp - 0.0F * b_p_re_tmp;
        p_im += b_p_re * b_p_re_tmp + 0.0F * c_p_re_tmp;
      }
      if (mm + 1 == 1) {
        p_re_tmp = 0;
      } else {
        p_re_tmp = 200 - mm;
      }
      y_data[vidx + 1024 * p_re_tmp].re = p_re;
      if (mm + 1 == 1) {
        p_re_tmp = 0;
      } else {
        p_re_tmp = 200 - mm;
      }
      y_data[vidx + 1024 * p_re_tmp].im = p_im;
    }
    vidx++;
  }
  memcpy(&b_z[0], &z[0], 2200U * sizeof(creal32_T));
  memcpy(&z[200], &b_z[0], 2200U * sizeof(creal32_T));
  for (i = 0; i < 199; i++) {
    z[i + 1] = x_data[204799 - i];
  }
  emxInit_creal32_T(&c_v, 2);
  i = c_v->size[0] * c_v->size[1];
  c_v->size[0] = 200;
  c_v->size[1] = 1024;
  emxEnsureCapacity_creal32_T(c_v, i);
  v_data = c_v->data;
  for (i = 0; i < 1024; i++) {
    for (vidx = 0; vidx < 200; vidx++) {
      v_data[vidx + 200 * i] = y_data[i + 1024 * vidx];
    }
  }
  emxFree_creal32_T(&b_v);
  emxInit_creal32_T(&r, 2);
  d_FFTImplementationCallback_dob(c_v, r);
  v_data = r->data;
  i = y->size[0] * y->size[1];
  y->size[0] = 1024;
  y->size[1] = 200;
  emxEnsureCapacity_creal32_T(y, i);
  y_data = y->data;
  emxFree_creal32_T(&c_v);
  for (i = 0; i < 200; i++) {
    for (vidx = 0; vidx < 1024; vidx++) {
      y_data[vidx + 1024 * i] = v_data[i + 200 * vidx];
    }
  }
  emxFree_creal32_T(&r);
}

/* End of code generation (Channelizer.c) */
