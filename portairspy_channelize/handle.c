/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * handle.c
 *
 * Code generation for function 'handle'
 *
 */

/* Include files */
#include "handle.h"
#include "airspy_channelize_internal_types.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"

/* Function Definitions */
void b_handle_matlabCodegenDestructo(dspcodegen_UDPReceiver *obj)
{
  char *sErr;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
      if (obj->isSetupComplete) {
        /* System object Destructor function: dsp.UDPReceiver */
        /* System object Terminate function: dsp.UDPReceiver */
        sErr = GetErrorBuffer(&obj->cSFunObject.W0_NetworkLib[0U]);
        LibTerminate(&obj->cSFunObject.W0_NetworkLib[0U]);
        if (*sErr != 0) {
          PrintError(sErr);
        }
        LibDestroy(&obj->cSFunObject.W0_NetworkLib[0U], 0);
        DestroyUDPInterface(&obj->cSFunObject.W0_NetworkLib[0U]);
      }
    }
  }
}

void c_handle_matlabCodegenDestructo(c_dsp_internal_AsyncBuffercgHel *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
      if (obj->isSetupComplete) {
        obj->ReadPointer = 1;
        obj->WritePointer = 2;
        obj->CumulativeOverrun = 0;
        obj->CumulativeUnderrun = 0;
        obj->c_AsyncBuffercgHelper_isInitial = false;
        obj->NumChannels = -1;
      }
    }
  }
}

void d_handle_matlabCodegenDestructo(dspcodegen_UDPSender *obj)
{
  char *sErr;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
      if (obj->isSetupComplete) {
        /* System object Destructor function: dsp.UDPSender */
        /* System object Terminate function: dsp.UDPSender */
        sErr = GetErrorBuffer(&obj->cSFunObject.W0_NetworkLib[0U]);
        LibTerminate(&obj->cSFunObject.W0_NetworkLib[0U]);
        if (*sErr != 0) {
          PrintError(sErr);
        }
        LibDestroy(&obj->cSFunObject.W0_NetworkLib[0U], 1);
        DestroyUDPInterface(&obj->cSFunObject.W0_NetworkLib[0U]);
      }
    }
  }
}

void handle_matlabCodegenDestructor(b_dspcodegen_UDPReceiver *obj)
{
  char *sErr;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
      if (obj->isSetupComplete) {
        /* System object Destructor function: dsp.UDPReceiver */
        /* System object Terminate function: dsp.UDPReceiver */
        sErr = GetErrorBuffer(&obj->cSFunObject.W0_NetworkLib[0U]);
        LibTerminate(&obj->cSFunObject.W0_NetworkLib[0U]);
        if (*sErr != 0) {
          PrintError(sErr);
        }
        LibDestroy(&obj->cSFunObject.W0_NetworkLib[0U], 0);
        DestroyUDPInterface(&obj->cSFunObject.W0_NetworkLib[0U]);
      }
    }
  }
}

/* End of code generation (handle.c) */
