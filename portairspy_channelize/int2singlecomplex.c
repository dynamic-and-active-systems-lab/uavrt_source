/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * int2singlecomplex.c
 *
 * Code generation for function 'int2singlecomplex'
 *
 */

/* Include files */
#include "int2singlecomplex.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include <math.h>

/* Function Declarations */
static unsigned long mul_u64_sat(unsigned long a);

static void mul_wide_u64(unsigned long in0, unsigned long *ptrOutBitsHi,
                         unsigned long *ptrOutBitsLo);

/* Function Definitions */
static unsigned long mul_u64_sat(unsigned long a)
{
  unsigned long result;
  unsigned long u64_chi;
  mul_wide_u64(a, &u64_chi, &result);
  if (u64_chi) {
    result = MAX_uint64_T;
  }
  return result;
}

static void mul_wide_u64(unsigned long in0, unsigned long *ptrOutBitsHi,
                         unsigned long *ptrOutBitsLo)
{
  unsigned long carry;
  unsigned long outBitsLo;
  unsigned long productHiLo;
  unsigned long productLoLo;
  productHiLo = (in0 >> 32UL) * 10000000UL;
  productLoLo = (in0 & 4294967295UL) * 10000000UL;
  carry = 0UL;
  outBitsLo = productLoLo + (productHiLo << 32UL);
  if (outBitsLo < productLoLo) {
    carry = 1UL;
  }
  *ptrOutBitsHi = carry + (productHiLo >> 32UL);
  *ptrOutBitsLo = outBitsLo;
}

creal32_T int2singlecomplex(unsigned long intIn)
{
  creal32_T singleComplex;
  unsigned long n1;
  int ex_t;
  /* int2singlecomplex Converts an integer value to a complex single precision
   */
  /* number with a portion of the integer digits in the real and imaginary */
  /* parts of the output. The input integer is split at the 7th digit. The top
   */
  /* digits are then held in the real part of the output, while the lower 7 */
  /* digits are held in the imaginary part of the output.  */
  /*  */
  /* A single precision number has a maximum integer */
  /* values of flintmax('single') = 16777216. To avoid overrunning the */
  /* available digits, the input integer is split at digit 7. */
  /*  */
  /* The max value for each output part would be:  16777216 + 1i * 16777216 */
  /* To avoid overflow, the complex part  */
  /* containing the lower digits only use          16777216 + 1i *  xxxxxxx */
  /* the first 7 digits available */
  /*  */
  /* Based on this standard, the maximum value that can be transmitted is  */
  /*    167772169999999 = 1.6777e14; */
  /*  */
  /* INPUTS: */
  /*    intIN           Matrix of integer values. If decimal values are */
  /*                    transmitted, they will be rounded by this program. */
  /*                    Maximum input value is 167772169999999. Inputs */
  /*                    exceedign this value will result in an error.  */
  /* OUTPUTS: */
  /*    singleComplex   Matrix of size of input with first 7 digits of input  */
  /*                    held in the imaginary part and the remaining upper  */
  /*                    digits held in the real part.  */
  /*  */
  /* -------------------------------------------------------------------------
   */
  /* Author:    Michael Shafer */
  /* Date:      2022-08-19 */
  /* -------------------------------------------------------------------------
   */
  frexp(1.0E-7, &ex_t);
  if (intIn == 0UL) {
    n1 = 0UL;
  } else {
    unsigned long n0;
    unsigned long temp0;
    unsigned long temp1;
    n1 = intIn >> 32;
    n0 = intIn & 4294967295UL;
    temp0 = n0 * 1759218UL;
    temp1 = n1 * 2596056904UL;
    n1 = ((n1 * 1759218UL + (temp0 >> 32)) + (temp1 >> 32)) +
         ((((temp0 & 4294967295UL) + ((n0 * 2596056904UL) >> 32)) +
           (temp1 & 4294967295UL)) >>
          32);
    n1 = (n1 >> 12) + (n1 >> 11 & 1UL);
  }
  singleComplex.re = (float)n1;
  n1 = intIn - mul_u64_sat(n1);
  if (n1 > intIn) {
    n1 = 0UL;
  }
  singleComplex.im = (float)n1;
  return singleComplex;
}

/* End of code generation (int2singlecomplex.c) */
