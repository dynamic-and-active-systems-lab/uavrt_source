/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * airspy_channelize_types.h
 *
 * Code generation for function 'airspy_channelize'
 *
 */

#ifndef AIRSPY_CHANNELIZE_TYPES_H
#define AIRSPY_CHANNELIZE_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_emxArray_creal32_T
#define typedef_emxArray_creal32_T
typedef struct {
  creal32_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_creal32_T;
#endif /* typedef_emxArray_creal32_T */

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T
struct emxArray_int32_T {
  int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_int32_T */
#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T
typedef struct emxArray_int32_T emxArray_int32_T;
#endif /* typedef_emxArray_int32_T */

#endif
/* End of code generation (airspy_channelize_types.h) */
