/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * strcmp.c
 *
 * Code generation for function 'strcmp'
 *
 */

/* Include files */
#include "strcmp.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"

/* Function Definitions */
boolean_T b_strcmp(const char a_data[], const int a_size[2])
{
  static const char cv[3] = {'r', 'u', 'n'};
  boolean_T b_bool;
  b_bool = false;
  if (a_size[1] == 3) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 3) {
        if (a_data[kstr] != cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

boolean_T c_strcmp(const char a_data[], const int a_size[2])
{
  static const char cv[4] = {'i', 'd', 'l', 'e'};
  boolean_T b_bool;
  b_bool = false;
  if (a_size[1] == 4) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 4) {
        if (a_data[kstr] != cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

boolean_T d_strcmp(const char a_data[], const int a_size[2])
{
  static const char cv[4] = {'k', 'i', 'l', 'l'};
  boolean_T b_bool;
  b_bool = false;
  if (a_size[1] == 4) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 4) {
        if (a_data[kstr] != cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

/* End of code generation (strcmp.c) */
