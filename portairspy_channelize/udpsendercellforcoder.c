/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * udpsendercellforcoder.c
 *
 * Code generation for function 'udpsendercellforcoder'
 *
 */

/* Include files */
#include "udpsendercellforcoder.h"
#include "airspy_channelize_internal_types.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"

/* Function Definitions */
void udpsendercellforcoder(
    b_dspcodegen_UDPSender *iobj_0, b_dspcodegen_UDPSender *iobj_1,
    b_dspcodegen_UDPSender *iobj_2, b_dspcodegen_UDPSender *iobj_3,
    b_dspcodegen_UDPSender *iobj_4, b_dspcodegen_UDPSender *iobj_5,
    b_dspcodegen_UDPSender *iobj_6, b_dspcodegen_UDPSender *iobj_7,
    b_dspcodegen_UDPSender *iobj_8, b_dspcodegen_UDPSender *iobj_9,
    b_dspcodegen_UDPSender *iobj_10, b_dspcodegen_UDPSender *iobj_11,
    b_dspcodegen_UDPSender *iobj_12, b_dspcodegen_UDPSender *iobj_13,
    b_dspcodegen_UDPSender *iobj_14, b_dspcodegen_UDPSender *iobj_15,
    b_dspcodegen_UDPSender *iobj_16, b_dspcodegen_UDPSender *iobj_17,
    b_dspcodegen_UDPSender *iobj_18, b_dspcodegen_UDPSender *iobj_19,
    b_dspcodegen_UDPSender *iobj_20, b_dspcodegen_UDPSender *iobj_21,
    b_dspcodegen_UDPSender *iobj_22, b_dspcodegen_UDPSender *iobj_23,
    b_dspcodegen_UDPSender *iobj_24, b_dspcodegen_UDPSender *iobj_25,
    b_dspcodegen_UDPSender *iobj_26, b_dspcodegen_UDPSender *iobj_27,
    b_dspcodegen_UDPSender *iobj_28, b_dspcodegen_UDPSender *iobj_29,
    b_dspcodegen_UDPSender *iobj_30, b_dspcodegen_UDPSender *iobj_31,
    b_dspcodegen_UDPSender *iobj_32, b_dspcodegen_UDPSender *iobj_33,
    b_dspcodegen_UDPSender *iobj_34, b_dspcodegen_UDPSender *iobj_35,
    b_dspcodegen_UDPSender *iobj_36, b_dspcodegen_UDPSender *iobj_37,
    b_dspcodegen_UDPSender *iobj_38, b_dspcodegen_UDPSender *iobj_39,
    b_dspcodegen_UDPSender *iobj_40, b_dspcodegen_UDPSender *iobj_41,
    b_dspcodegen_UDPSender *iobj_42, b_dspcodegen_UDPSender *iobj_43,
    b_dspcodegen_UDPSender *iobj_44, b_dspcodegen_UDPSender *iobj_45,
    b_dspcodegen_UDPSender *iobj_46, b_dspcodegen_UDPSender *iobj_47,
    b_dspcodegen_UDPSender *iobj_48, b_dspcodegen_UDPSender *iobj_49,
    b_dspcodegen_UDPSender *iobj_50, b_dspcodegen_UDPSender *iobj_51,
    b_dspcodegen_UDPSender *iobj_52, b_dspcodegen_UDPSender *iobj_53,
    b_dspcodegen_UDPSender *iobj_54, b_dspcodegen_UDPSender *iobj_55,
    b_dspcodegen_UDPSender *iobj_56, b_dspcodegen_UDPSender *iobj_57,
    b_dspcodegen_UDPSender *iobj_58, b_dspcodegen_UDPSender *iobj_59,
    b_dspcodegen_UDPSender *iobj_60, b_dspcodegen_UDPSender *iobj_61,
    b_dspcodegen_UDPSender *iobj_62, b_dspcodegen_UDPSender *iobj_63,
    b_dspcodegen_UDPSender *iobj_64, b_dspcodegen_UDPSender *iobj_65,
    b_dspcodegen_UDPSender *iobj_66, b_dspcodegen_UDPSender *iobj_67,
    b_dspcodegen_UDPSender *iobj_68, b_dspcodegen_UDPSender *iobj_69,
    b_dspcodegen_UDPSender *iobj_70, b_dspcodegen_UDPSender *iobj_71,
    b_dspcodegen_UDPSender *iobj_72, b_dspcodegen_UDPSender *iobj_73,
    b_dspcodegen_UDPSender *iobj_74, b_dspcodegen_UDPSender *iobj_75,
    b_dspcodegen_UDPSender *iobj_76, b_dspcodegen_UDPSender *iobj_77,
    b_dspcodegen_UDPSender *iobj_78, b_dspcodegen_UDPSender *iobj_79,
    b_dspcodegen_UDPSender *iobj_80, b_dspcodegen_UDPSender *iobj_81,
    b_dspcodegen_UDPSender *iobj_82, b_dspcodegen_UDPSender *iobj_83,
    b_dspcodegen_UDPSender *iobj_84, b_dspcodegen_UDPSender *iobj_85,
    b_dspcodegen_UDPSender *iobj_86, b_dspcodegen_UDPSender *iobj_87,
    b_dspcodegen_UDPSender *iobj_88, b_dspcodegen_UDPSender *iobj_89,
    b_dspcodegen_UDPSender *iobj_90, b_dspcodegen_UDPSender *iobj_91,
    b_dspcodegen_UDPSender *iobj_92, b_dspcodegen_UDPSender *iobj_93,
    b_dspcodegen_UDPSender *iobj_94, b_dspcodegen_UDPSender *iobj_95,
    b_dspcodegen_UDPSender *iobj_96, b_dspcodegen_UDPSender *iobj_97,
    b_dspcodegen_UDPSender *iobj_98, b_dspcodegen_UDPSender *iobj_99,
    b_dspcodegen_UDPSender *iobj_100, b_dspcodegen_UDPSender *iobj_101,
    b_dspcodegen_UDPSender *iobj_102, b_dspcodegen_UDPSender *iobj_103,
    b_dspcodegen_UDPSender *iobj_104, b_dspcodegen_UDPSender *iobj_105,
    b_dspcodegen_UDPSender *iobj_106, b_dspcodegen_UDPSender *iobj_107,
    b_dspcodegen_UDPSender *iobj_108, b_dspcodegen_UDPSender *iobj_109,
    b_dspcodegen_UDPSender *iobj_110, b_dspcodegen_UDPSender *iobj_111,
    b_dspcodegen_UDPSender *iobj_112, b_dspcodegen_UDPSender *iobj_113,
    b_dspcodegen_UDPSender *iobj_114, b_dspcodegen_UDPSender *iobj_115,
    b_dspcodegen_UDPSender *iobj_116, b_dspcodegen_UDPSender *iobj_117,
    b_dspcodegen_UDPSender *iobj_118, b_dspcodegen_UDPSender *iobj_119,
    b_dspcodegen_UDPSender *iobj_120, b_dspcodegen_UDPSender *iobj_121,
    b_dspcodegen_UDPSender *iobj_122, b_dspcodegen_UDPSender *iobj_123,
    b_dspcodegen_UDPSender *iobj_124, b_dspcodegen_UDPSender *iobj_125,
    b_dspcodegen_UDPSender *iobj_126, b_dspcodegen_UDPSender *iobj_127,
    b_dspcodegen_UDPSender *iobj_128, b_dspcodegen_UDPSender *iobj_129,
    b_dspcodegen_UDPSender *iobj_130, b_dspcodegen_UDPSender *iobj_131,
    b_dspcodegen_UDPSender *iobj_132, b_dspcodegen_UDPSender *iobj_133,
    b_dspcodegen_UDPSender *iobj_134, b_dspcodegen_UDPSender *iobj_135,
    b_dspcodegen_UDPSender *iobj_136, b_dspcodegen_UDPSender *iobj_137,
    b_dspcodegen_UDPSender *iobj_138, b_dspcodegen_UDPSender *iobj_139,
    b_dspcodegen_UDPSender *iobj_140, b_dspcodegen_UDPSender *iobj_141,
    b_dspcodegen_UDPSender *iobj_142, b_dspcodegen_UDPSender *iobj_143,
    b_dspcodegen_UDPSender *iobj_144, b_dspcodegen_UDPSender *iobj_145,
    b_dspcodegen_UDPSender *iobj_146, b_dspcodegen_UDPSender *iobj_147,
    b_dspcodegen_UDPSender *iobj_148, b_dspcodegen_UDPSender *iobj_149,
    b_dspcodegen_UDPSender *iobj_150, b_dspcodegen_UDPSender *iobj_151,
    b_dspcodegen_UDPSender *iobj_152, b_dspcodegen_UDPSender *iobj_153,
    b_dspcodegen_UDPSender *iobj_154, b_dspcodegen_UDPSender *iobj_155,
    dspcodegen_UDPSender *iobj_156, dspcodegen_UDPSender *iobj_157,
    dspcodegen_UDPSender *iobj_158, dspcodegen_UDPSender *iobj_159,
    dspcodegen_UDPSender *iobj_160, dspcodegen_UDPSender *iobj_161,
    dspcodegen_UDPSender *iobj_162, dspcodegen_UDPSender *iobj_163,
    dspcodegen_UDPSender *iobj_164, dspcodegen_UDPSender *iobj_165,
    dspcodegen_UDPSender *iobj_166, dspcodegen_UDPSender *iobj_167,
    dspcodegen_UDPSender *iobj_168, dspcodegen_UDPSender *iobj_169,
    dspcodegen_UDPSender *iobj_170, dspcodegen_UDPSender *iobj_171,
    dspcodegen_UDPSender *iobj_172, dspcodegen_UDPSender *iobj_173,
    dspcodegen_UDPSender *iobj_174, dspcodegen_UDPSender *iobj_175,
    dspcodegen_UDPSender *iobj_176, dspcodegen_UDPSender *iobj_177,
    dspcodegen_UDPSender *iobj_178, dspcodegen_UDPSender *iobj_179,
    dspcodegen_UDPSender *iobj_180, dspcodegen_UDPSender *iobj_181,
    dspcodegen_UDPSender *iobj_182, dspcodegen_UDPSender *iobj_183,
    dspcodegen_UDPSender *iobj_184, dspcodegen_UDPSender *iobj_185,
    dspcodegen_UDPSender *iobj_186, dspcodegen_UDPSender *iobj_187,
    dspcodegen_UDPSender *iobj_188, dspcodegen_UDPSender *iobj_189,
    dspcodegen_UDPSender *iobj_190, dspcodegen_UDPSender *iobj_191,
    dspcodegen_UDPSender *iobj_192, dspcodegen_UDPSender *iobj_193,
    dspcodegen_UDPSender *iobj_194, dspcodegen_UDPSender *iobj_195,
    dspcodegen_UDPSender *iobj_196, dspcodegen_UDPSender *iobj_197,
    dspcodegen_UDPSender *iobj_198, dspcodegen_UDPSender *iobj_199,
    dspcodegen_UDPSender *iobj_200, dspcodegen_UDPSender *iobj_201,
    dspcodegen_UDPSender *iobj_202, dspcodegen_UDPSender *iobj_203,
    dspcodegen_UDPSender *iobj_204, dspcodegen_UDPSender *iobj_205,
    dspcodegen_UDPSender *iobj_206, dspcodegen_UDPSender *iobj_207,
    dspcodegen_UDPSender *iobj_208, dspcodegen_UDPSender *iobj_209,
    dspcodegen_UDPSender *iobj_210, dspcodegen_UDPSender *iobj_211,
    dspcodegen_UDPSender *iobj_212, dspcodegen_UDPSender *iobj_213,
    dspcodegen_UDPSender *iobj_214, dspcodegen_UDPSender *iobj_215,
    dspcodegen_UDPSender *iobj_216, dspcodegen_UDPSender *iobj_217,
    dspcodegen_UDPSender *iobj_218, dspcodegen_UDPSender *iobj_219,
    dspcodegen_UDPSender *iobj_220, dspcodegen_UDPSender *iobj_221,
    dspcodegen_UDPSender *iobj_222, dspcodegen_UDPSender *iobj_223,
    dspcodegen_UDPSender *iobj_224, dspcodegen_UDPSender *iobj_225,
    dspcodegen_UDPSender *iobj_226, dspcodegen_UDPSender *iobj_227,
    dspcodegen_UDPSender *iobj_228, dspcodegen_UDPSender *iobj_229,
    dspcodegen_UDPSender *iobj_230, dspcodegen_UDPSender *iobj_231,
    dspcodegen_UDPSender *iobj_232, dspcodegen_UDPSender *iobj_233,
    dspcodegen_UDPSender *iobj_234, dspcodegen_UDPSender *iobj_235,
    dspcodegen_UDPSender *iobj_236, dspcodegen_UDPSender *iobj_237,
    dspcodegen_UDPSender *iobj_238, dspcodegen_UDPSender *iobj_239,
    dspcodegen_UDPSender *iobj_240, dspcodegen_UDPSender *iobj_241,
    dspcodegen_UDPSender *iobj_242, dspcodegen_UDPSender *iobj_243,
    dspcodegen_UDPSender *iobj_244, dspcodegen_UDPSender *iobj_245,
    dspcodegen_UDPSender *iobj_246, dspcodegen_UDPSender *iobj_247,
    dspcodegen_UDPSender *iobj_248, dspcodegen_UDPSender *iobj_249,
    dspcodegen_UDPSender *iobj_250, dspcodegen_UDPSender *iobj_251,
    dspcodegen_UDPSender *iobj_252, dspcodegen_UDPSender *iobj_253,
    dspcodegen_UDPSender *iobj_254, dspcodegen_UDPSender *iobj_255,
    cell_10 *retUDPCell)
{
  /* UDPSENDERCELLFORCODER Generates a cell array of dsp.UDPSend objects in a */
  /*  way that is compatible with Matlab Coder.  */
  /*    This function receives a remote IP address and a column vector of */
  /*    remote IP ports. The function generates a cell arrray with UDPSender */
  /*    objects from the Matlab DSP Toolbox in a way that is compatible with */
  /*    the cell array restrictions present in Matlab Coder. The function */
  /*    generates 256 sender objects and then truncates the cell array to */
  /*    output the same size cell array as the size of the remoteIPPortIn */
  /*    argument. No more that 256 ports can be requested.  */
  /*  */
  /* INPUTS: */
  /*    remoteIPAddressIn  String containg the remote IP address to send data */
  /*                       to. i.e. '127.0.0.1' or 'localhost' */
  /*    remoteIPPortIn     [1xn] vector of port numbers. Must have no more than
   */
  /*                       256 elements */
  /*    sendBufferSizeIn   Size of the buffer for each of the UDP Senders.  */
  /*  */
  /* OUTPUTS: */
  /*    retUDPCell         [1xn] cell array containing the UDP sender objects.
   */
  /*  */
  /* Author: Michael W. Shafer */
  /* Date:   2021-11-24 */
  /* -------------------------------------------------------------------------
   */
  iobj_255->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_255->cSFunObject.P0_Port = 20000;
  iobj_255->matlabCodegenIsDeleted = false;
  iobj_254->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_254->cSFunObject.P0_Port = 20001;
  iobj_254->matlabCodegenIsDeleted = false;
  iobj_253->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_253->cSFunObject.P0_Port = 20002;
  iobj_253->matlabCodegenIsDeleted = false;
  iobj_252->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_252->cSFunObject.P0_Port = 20003;
  iobj_252->matlabCodegenIsDeleted = false;
  iobj_251->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_251->cSFunObject.P0_Port = 20004;
  iobj_251->matlabCodegenIsDeleted = false;
  iobj_250->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_250->cSFunObject.P0_Port = 20005;
  iobj_250->matlabCodegenIsDeleted = false;
  iobj_249->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_249->cSFunObject.P0_Port = 20006;
  iobj_249->matlabCodegenIsDeleted = false;
  iobj_248->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_248->cSFunObject.P0_Port = 20007;
  iobj_248->matlabCodegenIsDeleted = false;
  iobj_247->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_247->cSFunObject.P0_Port = 20008;
  iobj_247->matlabCodegenIsDeleted = false;
  iobj_246->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_246->cSFunObject.P0_Port = 20009;
  iobj_246->matlabCodegenIsDeleted = false;
  iobj_245->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_245->cSFunObject.P0_Port = 20010;
  iobj_245->matlabCodegenIsDeleted = false;
  iobj_244->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_244->cSFunObject.P0_Port = 20011;
  iobj_244->matlabCodegenIsDeleted = false;
  iobj_243->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_243->cSFunObject.P0_Port = 20012;
  iobj_243->matlabCodegenIsDeleted = false;
  iobj_242->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_242->cSFunObject.P0_Port = 20013;
  iobj_242->matlabCodegenIsDeleted = false;
  iobj_241->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_241->cSFunObject.P0_Port = 20014;
  iobj_241->matlabCodegenIsDeleted = false;
  iobj_240->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_240->cSFunObject.P0_Port = 20015;
  iobj_240->matlabCodegenIsDeleted = false;
  iobj_239->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_239->cSFunObject.P0_Port = 20016;
  iobj_239->matlabCodegenIsDeleted = false;
  iobj_238->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_238->cSFunObject.P0_Port = 20017;
  iobj_238->matlabCodegenIsDeleted = false;
  iobj_237->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_237->cSFunObject.P0_Port = 20018;
  iobj_237->matlabCodegenIsDeleted = false;
  iobj_236->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_236->cSFunObject.P0_Port = 20019;
  iobj_236->matlabCodegenIsDeleted = false;
  iobj_235->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_235->cSFunObject.P0_Port = 20020;
  iobj_235->matlabCodegenIsDeleted = false;
  iobj_234->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_234->cSFunObject.P0_Port = 20021;
  iobj_234->matlabCodegenIsDeleted = false;
  iobj_233->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_233->cSFunObject.P0_Port = 20022;
  iobj_233->matlabCodegenIsDeleted = false;
  iobj_232->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_232->cSFunObject.P0_Port = 20023;
  iobj_232->matlabCodegenIsDeleted = false;
  iobj_231->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_231->cSFunObject.P0_Port = 20024;
  iobj_231->matlabCodegenIsDeleted = false;
  iobj_230->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_230->cSFunObject.P0_Port = 20025;
  iobj_230->matlabCodegenIsDeleted = false;
  iobj_229->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_229->cSFunObject.P0_Port = 20026;
  iobj_229->matlabCodegenIsDeleted = false;
  iobj_228->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_228->cSFunObject.P0_Port = 20027;
  iobj_228->matlabCodegenIsDeleted = false;
  iobj_227->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_227->cSFunObject.P0_Port = 20028;
  iobj_227->matlabCodegenIsDeleted = false;
  iobj_226->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_226->cSFunObject.P0_Port = 20029;
  iobj_226->matlabCodegenIsDeleted = false;
  iobj_225->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_225->cSFunObject.P0_Port = 20030;
  iobj_225->matlabCodegenIsDeleted = false;
  iobj_224->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_224->cSFunObject.P0_Port = 20031;
  iobj_224->matlabCodegenIsDeleted = false;
  iobj_223->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_223->cSFunObject.P0_Port = 20032;
  iobj_223->matlabCodegenIsDeleted = false;
  iobj_222->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_222->cSFunObject.P0_Port = 20033;
  iobj_222->matlabCodegenIsDeleted = false;
  iobj_221->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_221->cSFunObject.P0_Port = 20034;
  iobj_221->matlabCodegenIsDeleted = false;
  iobj_220->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_220->cSFunObject.P0_Port = 20035;
  iobj_220->matlabCodegenIsDeleted = false;
  iobj_219->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_219->cSFunObject.P0_Port = 20036;
  iobj_219->matlabCodegenIsDeleted = false;
  iobj_218->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_218->cSFunObject.P0_Port = 20037;
  iobj_218->matlabCodegenIsDeleted = false;
  iobj_217->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_217->cSFunObject.P0_Port = 20038;
  iobj_217->matlabCodegenIsDeleted = false;
  iobj_216->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_216->cSFunObject.P0_Port = 20039;
  iobj_216->matlabCodegenIsDeleted = false;
  iobj_215->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_215->cSFunObject.P0_Port = 20040;
  iobj_215->matlabCodegenIsDeleted = false;
  iobj_214->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_214->cSFunObject.P0_Port = 20041;
  iobj_214->matlabCodegenIsDeleted = false;
  iobj_213->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_213->cSFunObject.P0_Port = 20042;
  iobj_213->matlabCodegenIsDeleted = false;
  iobj_212->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_212->cSFunObject.P0_Port = 20043;
  iobj_212->matlabCodegenIsDeleted = false;
  iobj_211->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_211->cSFunObject.P0_Port = 20044;
  iobj_211->matlabCodegenIsDeleted = false;
  iobj_210->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_210->cSFunObject.P0_Port = 20045;
  iobj_210->matlabCodegenIsDeleted = false;
  iobj_209->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_209->cSFunObject.P0_Port = 20046;
  iobj_209->matlabCodegenIsDeleted = false;
  iobj_208->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_208->cSFunObject.P0_Port = 20047;
  iobj_208->matlabCodegenIsDeleted = false;
  iobj_207->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_207->cSFunObject.P0_Port = 20048;
  iobj_207->matlabCodegenIsDeleted = false;
  iobj_206->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_206->cSFunObject.P0_Port = 20049;
  iobj_206->matlabCodegenIsDeleted = false;
  iobj_205->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_205->cSFunObject.P0_Port = 20050;
  iobj_205->matlabCodegenIsDeleted = false;
  iobj_204->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_204->cSFunObject.P0_Port = 20051;
  iobj_204->matlabCodegenIsDeleted = false;
  iobj_203->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_203->cSFunObject.P0_Port = 20052;
  iobj_203->matlabCodegenIsDeleted = false;
  iobj_202->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_202->cSFunObject.P0_Port = 20053;
  iobj_202->matlabCodegenIsDeleted = false;
  iobj_201->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_201->cSFunObject.P0_Port = 20054;
  iobj_201->matlabCodegenIsDeleted = false;
  iobj_200->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_200->cSFunObject.P0_Port = 20055;
  iobj_200->matlabCodegenIsDeleted = false;
  iobj_199->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_199->cSFunObject.P0_Port = 20056;
  iobj_199->matlabCodegenIsDeleted = false;
  iobj_198->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_198->cSFunObject.P0_Port = 20057;
  iobj_198->matlabCodegenIsDeleted = false;
  iobj_197->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_197->cSFunObject.P0_Port = 20058;
  iobj_197->matlabCodegenIsDeleted = false;
  iobj_196->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_196->cSFunObject.P0_Port = 20059;
  iobj_196->matlabCodegenIsDeleted = false;
  iobj_195->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_195->cSFunObject.P0_Port = 20060;
  iobj_195->matlabCodegenIsDeleted = false;
  iobj_194->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_194->cSFunObject.P0_Port = 20061;
  iobj_194->matlabCodegenIsDeleted = false;
  iobj_193->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_193->cSFunObject.P0_Port = 20062;
  iobj_193->matlabCodegenIsDeleted = false;
  iobj_192->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_192->cSFunObject.P0_Port = 20063;
  iobj_192->matlabCodegenIsDeleted = false;
  iobj_191->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_191->cSFunObject.P0_Port = 20064;
  iobj_191->matlabCodegenIsDeleted = false;
  iobj_190->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_190->cSFunObject.P0_Port = 20065;
  iobj_190->matlabCodegenIsDeleted = false;
  iobj_189->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_189->cSFunObject.P0_Port = 20066;
  iobj_189->matlabCodegenIsDeleted = false;
  iobj_188->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_188->cSFunObject.P0_Port = 20067;
  iobj_188->matlabCodegenIsDeleted = false;
  iobj_187->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_187->cSFunObject.P0_Port = 20068;
  iobj_187->matlabCodegenIsDeleted = false;
  iobj_186->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_186->cSFunObject.P0_Port = 20069;
  iobj_186->matlabCodegenIsDeleted = false;
  iobj_185->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_185->cSFunObject.P0_Port = 20070;
  iobj_185->matlabCodegenIsDeleted = false;
  iobj_184->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_184->cSFunObject.P0_Port = 20071;
  iobj_184->matlabCodegenIsDeleted = false;
  iobj_183->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_183->cSFunObject.P0_Port = 20072;
  iobj_183->matlabCodegenIsDeleted = false;
  iobj_182->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_182->cSFunObject.P0_Port = 20073;
  iobj_182->matlabCodegenIsDeleted = false;
  iobj_181->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_181->cSFunObject.P0_Port = 20074;
  iobj_181->matlabCodegenIsDeleted = false;
  iobj_180->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_180->cSFunObject.P0_Port = 20075;
  iobj_180->matlabCodegenIsDeleted = false;
  iobj_179->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_179->cSFunObject.P0_Port = 20076;
  iobj_179->matlabCodegenIsDeleted = false;
  iobj_178->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_178->cSFunObject.P0_Port = 20077;
  iobj_178->matlabCodegenIsDeleted = false;
  iobj_177->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_177->cSFunObject.P0_Port = 20078;
  iobj_177->matlabCodegenIsDeleted = false;
  iobj_176->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_176->cSFunObject.P0_Port = 20079;
  iobj_176->matlabCodegenIsDeleted = false;
  iobj_175->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_175->cSFunObject.P0_Port = 20080;
  iobj_175->matlabCodegenIsDeleted = false;
  iobj_174->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_174->cSFunObject.P0_Port = 20081;
  iobj_174->matlabCodegenIsDeleted = false;
  iobj_173->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_173->cSFunObject.P0_Port = 20082;
  iobj_173->matlabCodegenIsDeleted = false;
  iobj_172->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_172->cSFunObject.P0_Port = 20083;
  iobj_172->matlabCodegenIsDeleted = false;
  iobj_171->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_171->cSFunObject.P0_Port = 20084;
  iobj_171->matlabCodegenIsDeleted = false;
  iobj_170->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_170->cSFunObject.P0_Port = 20085;
  iobj_170->matlabCodegenIsDeleted = false;
  iobj_169->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_169->cSFunObject.P0_Port = 20086;
  iobj_169->matlabCodegenIsDeleted = false;
  iobj_168->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_168->cSFunObject.P0_Port = 20087;
  iobj_168->matlabCodegenIsDeleted = false;
  iobj_167->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_167->cSFunObject.P0_Port = 20088;
  iobj_167->matlabCodegenIsDeleted = false;
  iobj_166->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_166->cSFunObject.P0_Port = 20089;
  iobj_166->matlabCodegenIsDeleted = false;
  iobj_165->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_165->cSFunObject.P0_Port = 20090;
  iobj_165->matlabCodegenIsDeleted = false;
  iobj_164->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_164->cSFunObject.P0_Port = 20091;
  iobj_164->matlabCodegenIsDeleted = false;
  iobj_163->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_163->cSFunObject.P0_Port = 20092;
  iobj_163->matlabCodegenIsDeleted = false;
  iobj_162->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_162->cSFunObject.P0_Port = 20093;
  iobj_162->matlabCodegenIsDeleted = false;
  iobj_161->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_161->cSFunObject.P0_Port = 20094;
  iobj_161->matlabCodegenIsDeleted = false;
  iobj_160->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_160->cSFunObject.P0_Port = 20095;
  iobj_160->matlabCodegenIsDeleted = false;
  iobj_159->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_159->cSFunObject.P0_Port = 20096;
  iobj_159->matlabCodegenIsDeleted = false;
  iobj_158->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_158->cSFunObject.P0_Port = 20097;
  iobj_158->matlabCodegenIsDeleted = false;
  iobj_157->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_157->cSFunObject.P0_Port = 20098;
  iobj_157->matlabCodegenIsDeleted = false;
  iobj_156->isInitialized = 0;
  /* System object Constructor function: dsp.UDPSender */
  iobj_156->cSFunObject.P0_Port = 20099;
  iobj_156->matlabCodegenIsDeleted = false;
  iobj_155->isInitialized = 0;
  iobj_155->matlabCodegenIsDeleted = false;
  iobj_154->isInitialized = 0;
  iobj_154->matlabCodegenIsDeleted = false;
  iobj_153->isInitialized = 0;
  iobj_153->matlabCodegenIsDeleted = false;
  iobj_152->isInitialized = 0;
  iobj_152->matlabCodegenIsDeleted = false;
  iobj_151->isInitialized = 0;
  iobj_151->matlabCodegenIsDeleted = false;
  iobj_150->isInitialized = 0;
  iobj_150->matlabCodegenIsDeleted = false;
  iobj_149->isInitialized = 0;
  iobj_149->matlabCodegenIsDeleted = false;
  iobj_148->isInitialized = 0;
  iobj_148->matlabCodegenIsDeleted = false;
  iobj_147->isInitialized = 0;
  iobj_147->matlabCodegenIsDeleted = false;
  iobj_146->isInitialized = 0;
  iobj_146->matlabCodegenIsDeleted = false;
  iobj_145->isInitialized = 0;
  iobj_145->matlabCodegenIsDeleted = false;
  iobj_144->isInitialized = 0;
  iobj_144->matlabCodegenIsDeleted = false;
  iobj_143->isInitialized = 0;
  iobj_143->matlabCodegenIsDeleted = false;
  iobj_142->isInitialized = 0;
  iobj_142->matlabCodegenIsDeleted = false;
  iobj_141->isInitialized = 0;
  iobj_141->matlabCodegenIsDeleted = false;
  iobj_140->isInitialized = 0;
  iobj_140->matlabCodegenIsDeleted = false;
  iobj_139->isInitialized = 0;
  iobj_139->matlabCodegenIsDeleted = false;
  iobj_138->isInitialized = 0;
  iobj_138->matlabCodegenIsDeleted = false;
  iobj_137->isInitialized = 0;
  iobj_137->matlabCodegenIsDeleted = false;
  iobj_136->isInitialized = 0;
  iobj_136->matlabCodegenIsDeleted = false;
  iobj_135->isInitialized = 0;
  iobj_135->matlabCodegenIsDeleted = false;
  iobj_134->isInitialized = 0;
  iobj_134->matlabCodegenIsDeleted = false;
  iobj_133->isInitialized = 0;
  iobj_133->matlabCodegenIsDeleted = false;
  iobj_132->isInitialized = 0;
  iobj_132->matlabCodegenIsDeleted = false;
  iobj_131->isInitialized = 0;
  iobj_131->matlabCodegenIsDeleted = false;
  iobj_130->isInitialized = 0;
  iobj_130->matlabCodegenIsDeleted = false;
  iobj_129->isInitialized = 0;
  iobj_129->matlabCodegenIsDeleted = false;
  iobj_128->isInitialized = 0;
  iobj_128->matlabCodegenIsDeleted = false;
  iobj_127->isInitialized = 0;
  iobj_127->matlabCodegenIsDeleted = false;
  iobj_126->isInitialized = 0;
  iobj_126->matlabCodegenIsDeleted = false;
  iobj_125->isInitialized = 0;
  iobj_125->matlabCodegenIsDeleted = false;
  iobj_124->isInitialized = 0;
  iobj_124->matlabCodegenIsDeleted = false;
  iobj_123->isInitialized = 0;
  iobj_123->matlabCodegenIsDeleted = false;
  iobj_122->isInitialized = 0;
  iobj_122->matlabCodegenIsDeleted = false;
  iobj_121->isInitialized = 0;
  iobj_121->matlabCodegenIsDeleted = false;
  iobj_120->isInitialized = 0;
  iobj_120->matlabCodegenIsDeleted = false;
  iobj_119->isInitialized = 0;
  iobj_119->matlabCodegenIsDeleted = false;
  iobj_118->isInitialized = 0;
  iobj_118->matlabCodegenIsDeleted = false;
  iobj_117->isInitialized = 0;
  iobj_117->matlabCodegenIsDeleted = false;
  iobj_116->isInitialized = 0;
  iobj_116->matlabCodegenIsDeleted = false;
  iobj_115->isInitialized = 0;
  iobj_115->matlabCodegenIsDeleted = false;
  iobj_114->isInitialized = 0;
  iobj_114->matlabCodegenIsDeleted = false;
  iobj_113->isInitialized = 0;
  iobj_113->matlabCodegenIsDeleted = false;
  iobj_112->isInitialized = 0;
  iobj_112->matlabCodegenIsDeleted = false;
  iobj_111->isInitialized = 0;
  iobj_111->matlabCodegenIsDeleted = false;
  iobj_110->isInitialized = 0;
  iobj_110->matlabCodegenIsDeleted = false;
  iobj_109->isInitialized = 0;
  iobj_109->matlabCodegenIsDeleted = false;
  iobj_108->isInitialized = 0;
  iobj_108->matlabCodegenIsDeleted = false;
  iobj_107->isInitialized = 0;
  iobj_107->matlabCodegenIsDeleted = false;
  iobj_106->isInitialized = 0;
  iobj_106->matlabCodegenIsDeleted = false;
  iobj_105->isInitialized = 0;
  iobj_105->matlabCodegenIsDeleted = false;
  iobj_104->isInitialized = 0;
  iobj_104->matlabCodegenIsDeleted = false;
  iobj_103->isInitialized = 0;
  iobj_103->matlabCodegenIsDeleted = false;
  iobj_102->isInitialized = 0;
  iobj_102->matlabCodegenIsDeleted = false;
  iobj_101->isInitialized = 0;
  iobj_101->matlabCodegenIsDeleted = false;
  iobj_100->isInitialized = 0;
  iobj_100->matlabCodegenIsDeleted = false;
  iobj_99->isInitialized = 0;
  iobj_99->matlabCodegenIsDeleted = false;
  iobj_98->isInitialized = 0;
  iobj_98->matlabCodegenIsDeleted = false;
  iobj_97->isInitialized = 0;
  iobj_97->matlabCodegenIsDeleted = false;
  iobj_96->isInitialized = 0;
  iobj_96->matlabCodegenIsDeleted = false;
  iobj_95->isInitialized = 0;
  iobj_95->matlabCodegenIsDeleted = false;
  iobj_94->isInitialized = 0;
  iobj_94->matlabCodegenIsDeleted = false;
  iobj_93->isInitialized = 0;
  iobj_93->matlabCodegenIsDeleted = false;
  iobj_92->isInitialized = 0;
  iobj_92->matlabCodegenIsDeleted = false;
  iobj_91->isInitialized = 0;
  iobj_91->matlabCodegenIsDeleted = false;
  iobj_90->isInitialized = 0;
  iobj_90->matlabCodegenIsDeleted = false;
  iobj_89->isInitialized = 0;
  iobj_89->matlabCodegenIsDeleted = false;
  iobj_88->isInitialized = 0;
  iobj_88->matlabCodegenIsDeleted = false;
  iobj_87->isInitialized = 0;
  iobj_87->matlabCodegenIsDeleted = false;
  iobj_86->isInitialized = 0;
  iobj_86->matlabCodegenIsDeleted = false;
  iobj_85->isInitialized = 0;
  iobj_85->matlabCodegenIsDeleted = false;
  iobj_84->isInitialized = 0;
  iobj_84->matlabCodegenIsDeleted = false;
  iobj_83->isInitialized = 0;
  iobj_83->matlabCodegenIsDeleted = false;
  iobj_82->isInitialized = 0;
  iobj_82->matlabCodegenIsDeleted = false;
  iobj_81->isInitialized = 0;
  iobj_81->matlabCodegenIsDeleted = false;
  iobj_80->isInitialized = 0;
  iobj_80->matlabCodegenIsDeleted = false;
  iobj_79->isInitialized = 0;
  iobj_79->matlabCodegenIsDeleted = false;
  iobj_78->isInitialized = 0;
  iobj_78->matlabCodegenIsDeleted = false;
  iobj_77->isInitialized = 0;
  iobj_77->matlabCodegenIsDeleted = false;
  iobj_76->isInitialized = 0;
  iobj_76->matlabCodegenIsDeleted = false;
  iobj_75->isInitialized = 0;
  iobj_75->matlabCodegenIsDeleted = false;
  iobj_74->isInitialized = 0;
  iobj_74->matlabCodegenIsDeleted = false;
  iobj_73->isInitialized = 0;
  iobj_73->matlabCodegenIsDeleted = false;
  iobj_72->isInitialized = 0;
  iobj_72->matlabCodegenIsDeleted = false;
  iobj_71->isInitialized = 0;
  iobj_71->matlabCodegenIsDeleted = false;
  iobj_70->isInitialized = 0;
  iobj_70->matlabCodegenIsDeleted = false;
  iobj_69->isInitialized = 0;
  iobj_69->matlabCodegenIsDeleted = false;
  iobj_68->isInitialized = 0;
  iobj_68->matlabCodegenIsDeleted = false;
  iobj_67->isInitialized = 0;
  iobj_67->matlabCodegenIsDeleted = false;
  iobj_66->isInitialized = 0;
  iobj_66->matlabCodegenIsDeleted = false;
  iobj_65->isInitialized = 0;
  iobj_65->matlabCodegenIsDeleted = false;
  iobj_64->isInitialized = 0;
  iobj_64->matlabCodegenIsDeleted = false;
  iobj_63->isInitialized = 0;
  iobj_63->matlabCodegenIsDeleted = false;
  iobj_62->isInitialized = 0;
  iobj_62->matlabCodegenIsDeleted = false;
  iobj_61->isInitialized = 0;
  iobj_61->matlabCodegenIsDeleted = false;
  iobj_60->isInitialized = 0;
  iobj_60->matlabCodegenIsDeleted = false;
  iobj_59->isInitialized = 0;
  iobj_59->matlabCodegenIsDeleted = false;
  iobj_58->isInitialized = 0;
  iobj_58->matlabCodegenIsDeleted = false;
  iobj_57->isInitialized = 0;
  iobj_57->matlabCodegenIsDeleted = false;
  iobj_56->isInitialized = 0;
  iobj_56->matlabCodegenIsDeleted = false;
  iobj_55->isInitialized = 0;
  iobj_55->matlabCodegenIsDeleted = false;
  iobj_54->isInitialized = 0;
  iobj_54->matlabCodegenIsDeleted = false;
  iobj_53->isInitialized = 0;
  iobj_53->matlabCodegenIsDeleted = false;
  iobj_52->isInitialized = 0;
  iobj_52->matlabCodegenIsDeleted = false;
  iobj_51->isInitialized = 0;
  iobj_51->matlabCodegenIsDeleted = false;
  iobj_50->isInitialized = 0;
  iobj_50->matlabCodegenIsDeleted = false;
  iobj_49->isInitialized = 0;
  iobj_49->matlabCodegenIsDeleted = false;
  iobj_48->isInitialized = 0;
  iobj_48->matlabCodegenIsDeleted = false;
  iobj_47->isInitialized = 0;
  iobj_47->matlabCodegenIsDeleted = false;
  iobj_46->isInitialized = 0;
  iobj_46->matlabCodegenIsDeleted = false;
  iobj_45->isInitialized = 0;
  iobj_45->matlabCodegenIsDeleted = false;
  iobj_44->isInitialized = 0;
  iobj_44->matlabCodegenIsDeleted = false;
  iobj_43->isInitialized = 0;
  iobj_43->matlabCodegenIsDeleted = false;
  iobj_42->isInitialized = 0;
  iobj_42->matlabCodegenIsDeleted = false;
  iobj_41->isInitialized = 0;
  iobj_41->matlabCodegenIsDeleted = false;
  iobj_40->isInitialized = 0;
  iobj_40->matlabCodegenIsDeleted = false;
  iobj_39->isInitialized = 0;
  iobj_39->matlabCodegenIsDeleted = false;
  iobj_38->isInitialized = 0;
  iobj_38->matlabCodegenIsDeleted = false;
  iobj_37->isInitialized = 0;
  iobj_37->matlabCodegenIsDeleted = false;
  iobj_36->isInitialized = 0;
  iobj_36->matlabCodegenIsDeleted = false;
  iobj_35->isInitialized = 0;
  iobj_35->matlabCodegenIsDeleted = false;
  iobj_34->isInitialized = 0;
  iobj_34->matlabCodegenIsDeleted = false;
  iobj_33->isInitialized = 0;
  iobj_33->matlabCodegenIsDeleted = false;
  iobj_32->isInitialized = 0;
  iobj_32->matlabCodegenIsDeleted = false;
  iobj_31->isInitialized = 0;
  iobj_31->matlabCodegenIsDeleted = false;
  iobj_30->isInitialized = 0;
  iobj_30->matlabCodegenIsDeleted = false;
  iobj_29->isInitialized = 0;
  iobj_29->matlabCodegenIsDeleted = false;
  iobj_28->isInitialized = 0;
  iobj_28->matlabCodegenIsDeleted = false;
  iobj_27->isInitialized = 0;
  iobj_27->matlabCodegenIsDeleted = false;
  iobj_26->isInitialized = 0;
  iobj_26->matlabCodegenIsDeleted = false;
  iobj_25->isInitialized = 0;
  iobj_25->matlabCodegenIsDeleted = false;
  iobj_24->isInitialized = 0;
  iobj_24->matlabCodegenIsDeleted = false;
  iobj_23->isInitialized = 0;
  iobj_23->matlabCodegenIsDeleted = false;
  iobj_22->isInitialized = 0;
  iobj_22->matlabCodegenIsDeleted = false;
  iobj_21->isInitialized = 0;
  iobj_21->matlabCodegenIsDeleted = false;
  iobj_20->isInitialized = 0;
  iobj_20->matlabCodegenIsDeleted = false;
  iobj_19->isInitialized = 0;
  iobj_19->matlabCodegenIsDeleted = false;
  iobj_18->isInitialized = 0;
  iobj_18->matlabCodegenIsDeleted = false;
  iobj_17->isInitialized = 0;
  iobj_17->matlabCodegenIsDeleted = false;
  iobj_16->isInitialized = 0;
  iobj_16->matlabCodegenIsDeleted = false;
  iobj_15->isInitialized = 0;
  iobj_15->matlabCodegenIsDeleted = false;
  iobj_14->isInitialized = 0;
  iobj_14->matlabCodegenIsDeleted = false;
  iobj_13->isInitialized = 0;
  iobj_13->matlabCodegenIsDeleted = false;
  iobj_12->isInitialized = 0;
  iobj_12->matlabCodegenIsDeleted = false;
  iobj_11->isInitialized = 0;
  iobj_11->matlabCodegenIsDeleted = false;
  iobj_10->isInitialized = 0;
  iobj_10->matlabCodegenIsDeleted = false;
  iobj_9->isInitialized = 0;
  iobj_9->matlabCodegenIsDeleted = false;
  iobj_8->isInitialized = 0;
  iobj_8->matlabCodegenIsDeleted = false;
  iobj_7->isInitialized = 0;
  iobj_7->matlabCodegenIsDeleted = false;
  iobj_6->isInitialized = 0;
  iobj_6->matlabCodegenIsDeleted = false;
  iobj_5->isInitialized = 0;
  iobj_5->matlabCodegenIsDeleted = false;
  iobj_4->isInitialized = 0;
  iobj_4->matlabCodegenIsDeleted = false;
  iobj_3->isInitialized = 0;
  iobj_3->matlabCodegenIsDeleted = false;
  iobj_2->isInitialized = 0;
  iobj_2->matlabCodegenIsDeleted = false;
  iobj_1->isInitialized = 0;
  iobj_1->matlabCodegenIsDeleted = false;
  iobj_0->isInitialized = 0;
  iobj_0->matlabCodegenIsDeleted = false;
  /*     */
  /* udpsCellAll = { udps1   ; udps2   ; udps3   ;udps4   }; */
  /* Coder doesn't support curly braces or this would be coded as */
  /* udpsCellAll(1:numOfPorts) */
  retUDPCell->f1 = iobj_255;
  retUDPCell->f2 = iobj_254;
  retUDPCell->f3 = iobj_253;
  retUDPCell->f4 = iobj_252;
  retUDPCell->f5 = iobj_251;
  retUDPCell->f6 = iobj_250;
  retUDPCell->f7 = iobj_249;
  retUDPCell->f8 = iobj_248;
  retUDPCell->f9 = iobj_247;
  retUDPCell->f10 = iobj_246;
  retUDPCell->f11 = iobj_245;
  retUDPCell->f12 = iobj_244;
  retUDPCell->f13 = iobj_243;
  retUDPCell->f14 = iobj_242;
  retUDPCell->f15 = iobj_241;
  retUDPCell->f16 = iobj_240;
  retUDPCell->f17 = iobj_239;
  retUDPCell->f18 = iobj_238;
  retUDPCell->f19 = iobj_237;
  retUDPCell->f20 = iobj_236;
  retUDPCell->f21 = iobj_235;
  retUDPCell->f22 = iobj_234;
  retUDPCell->f23 = iobj_233;
  retUDPCell->f24 = iobj_232;
  retUDPCell->f25 = iobj_231;
  retUDPCell->f26 = iobj_230;
  retUDPCell->f27 = iobj_229;
  retUDPCell->f28 = iobj_228;
  retUDPCell->f29 = iobj_227;
  retUDPCell->f30 = iobj_226;
  retUDPCell->f31 = iobj_225;
  retUDPCell->f32 = iobj_224;
  retUDPCell->f33 = iobj_223;
  retUDPCell->f34 = iobj_222;
  retUDPCell->f35 = iobj_221;
  retUDPCell->f36 = iobj_220;
  retUDPCell->f37 = iobj_219;
  retUDPCell->f38 = iobj_218;
  retUDPCell->f39 = iobj_217;
  retUDPCell->f40 = iobj_216;
  retUDPCell->f41 = iobj_215;
  retUDPCell->f42 = iobj_214;
  retUDPCell->f43 = iobj_213;
  retUDPCell->f44 = iobj_212;
  retUDPCell->f45 = iobj_211;
  retUDPCell->f46 = iobj_210;
  retUDPCell->f47 = iobj_209;
  retUDPCell->f48 = iobj_208;
  retUDPCell->f49 = iobj_207;
  retUDPCell->f50 = iobj_206;
  retUDPCell->f51 = iobj_205;
  retUDPCell->f52 = iobj_204;
  retUDPCell->f53 = iobj_203;
  retUDPCell->f54 = iobj_202;
  retUDPCell->f55 = iobj_201;
  retUDPCell->f56 = iobj_200;
  retUDPCell->f57 = iobj_199;
  retUDPCell->f58 = iobj_198;
  retUDPCell->f59 = iobj_197;
  retUDPCell->f60 = iobj_196;
  retUDPCell->f61 = iobj_195;
  retUDPCell->f62 = iobj_194;
  retUDPCell->f63 = iobj_193;
  retUDPCell->f64 = iobj_192;
  retUDPCell->f65 = iobj_191;
  retUDPCell->f66 = iobj_190;
  retUDPCell->f67 = iobj_189;
  retUDPCell->f68 = iobj_188;
  retUDPCell->f69 = iobj_187;
  retUDPCell->f70 = iobj_186;
  retUDPCell->f71 = iobj_185;
  retUDPCell->f72 = iobj_184;
  retUDPCell->f73 = iobj_183;
  retUDPCell->f74 = iobj_182;
  retUDPCell->f75 = iobj_181;
  retUDPCell->f76 = iobj_180;
  retUDPCell->f77 = iobj_179;
  retUDPCell->f78 = iobj_178;
  retUDPCell->f79 = iobj_177;
  retUDPCell->f80 = iobj_176;
  retUDPCell->f81 = iobj_175;
  retUDPCell->f82 = iobj_174;
  retUDPCell->f83 = iobj_173;
  retUDPCell->f84 = iobj_172;
  retUDPCell->f85 = iobj_171;
  retUDPCell->f86 = iobj_170;
  retUDPCell->f87 = iobj_169;
  retUDPCell->f88 = iobj_168;
  retUDPCell->f89 = iobj_167;
  retUDPCell->f90 = iobj_166;
  retUDPCell->f91 = iobj_165;
  retUDPCell->f92 = iobj_164;
  retUDPCell->f93 = iobj_163;
  retUDPCell->f94 = iobj_162;
  retUDPCell->f95 = iobj_161;
  retUDPCell->f96 = iobj_160;
  retUDPCell->f97 = iobj_159;
  retUDPCell->f98 = iobj_158;
  retUDPCell->f99 = iobj_157;
  retUDPCell->f100 = iobj_156;
  retUDPCell->f101 = iobj_155;
  retUDPCell->f102 = iobj_154;
  retUDPCell->f103 = iobj_153;
  retUDPCell->f104 = iobj_152;
  retUDPCell->f105 = iobj_151;
  retUDPCell->f106 = iobj_150;
  retUDPCell->f107 = iobj_149;
  retUDPCell->f108 = iobj_148;
  retUDPCell->f109 = iobj_147;
  retUDPCell->f110 = iobj_146;
  retUDPCell->f111 = iobj_145;
  retUDPCell->f112 = iobj_144;
  retUDPCell->f113 = iobj_143;
  retUDPCell->f114 = iobj_142;
  retUDPCell->f115 = iobj_141;
  retUDPCell->f116 = iobj_140;
  retUDPCell->f117 = iobj_139;
  retUDPCell->f118 = iobj_138;
  retUDPCell->f119 = iobj_137;
  retUDPCell->f120 = iobj_136;
  retUDPCell->f121 = iobj_135;
  retUDPCell->f122 = iobj_134;
  retUDPCell->f123 = iobj_133;
  retUDPCell->f124 = iobj_132;
  retUDPCell->f125 = iobj_131;
  retUDPCell->f126 = iobj_130;
  retUDPCell->f127 = iobj_129;
  retUDPCell->f128 = iobj_128;
  retUDPCell->f129 = iobj_127;
  retUDPCell->f130 = iobj_126;
  retUDPCell->f131 = iobj_125;
  retUDPCell->f132 = iobj_124;
  retUDPCell->f133 = iobj_123;
  retUDPCell->f134 = iobj_122;
  retUDPCell->f135 = iobj_121;
  retUDPCell->f136 = iobj_120;
  retUDPCell->f137 = iobj_119;
  retUDPCell->f138 = iobj_118;
  retUDPCell->f139 = iobj_117;
  retUDPCell->f140 = iobj_116;
  retUDPCell->f141 = iobj_115;
  retUDPCell->f142 = iobj_114;
  retUDPCell->f143 = iobj_113;
  retUDPCell->f144 = iobj_112;
  retUDPCell->f145 = iobj_111;
  retUDPCell->f146 = iobj_110;
  retUDPCell->f147 = iobj_109;
  retUDPCell->f148 = iobj_108;
  retUDPCell->f149 = iobj_107;
  retUDPCell->f150 = iobj_106;
  retUDPCell->f151 = iobj_105;
  retUDPCell->f152 = iobj_104;
  retUDPCell->f153 = iobj_103;
  retUDPCell->f154 = iobj_102;
  retUDPCell->f155 = iobj_101;
  retUDPCell->f156 = iobj_100;
  retUDPCell->f157 = iobj_99;
  retUDPCell->f158 = iobj_98;
  retUDPCell->f159 = iobj_97;
  retUDPCell->f160 = iobj_96;
  retUDPCell->f161 = iobj_95;
  retUDPCell->f162 = iobj_94;
  retUDPCell->f163 = iobj_93;
  retUDPCell->f164 = iobj_92;
  retUDPCell->f165 = iobj_91;
  retUDPCell->f166 = iobj_90;
  retUDPCell->f167 = iobj_89;
  retUDPCell->f168 = iobj_88;
  retUDPCell->f169 = iobj_87;
  retUDPCell->f170 = iobj_86;
  retUDPCell->f171 = iobj_85;
  retUDPCell->f172 = iobj_84;
  retUDPCell->f173 = iobj_83;
  retUDPCell->f174 = iobj_82;
  retUDPCell->f175 = iobj_81;
  retUDPCell->f176 = iobj_80;
  retUDPCell->f177 = iobj_79;
  retUDPCell->f178 = iobj_78;
  retUDPCell->f179 = iobj_77;
  retUDPCell->f180 = iobj_76;
  retUDPCell->f181 = iobj_75;
  retUDPCell->f182 = iobj_74;
  retUDPCell->f183 = iobj_73;
  retUDPCell->f184 = iobj_72;
  retUDPCell->f185 = iobj_71;
  retUDPCell->f186 = iobj_70;
  retUDPCell->f187 = iobj_69;
  retUDPCell->f188 = iobj_68;
  retUDPCell->f189 = iobj_67;
  retUDPCell->f190 = iobj_66;
  retUDPCell->f191 = iobj_65;
  retUDPCell->f192 = iobj_64;
  retUDPCell->f193 = iobj_63;
  retUDPCell->f194 = iobj_62;
  retUDPCell->f195 = iobj_61;
  retUDPCell->f196 = iobj_60;
  retUDPCell->f197 = iobj_59;
  retUDPCell->f198 = iobj_58;
  retUDPCell->f199 = iobj_57;
  retUDPCell->f200 = iobj_56;
  retUDPCell->f201 = iobj_55;
  retUDPCell->f202 = iobj_54;
  retUDPCell->f203 = iobj_53;
  retUDPCell->f204 = iobj_52;
  retUDPCell->f205 = iobj_51;
  retUDPCell->f206 = iobj_50;
  retUDPCell->f207 = iobj_49;
  retUDPCell->f208 = iobj_48;
  retUDPCell->f209 = iobj_47;
  retUDPCell->f210 = iobj_46;
  retUDPCell->f211 = iobj_45;
  retUDPCell->f212 = iobj_44;
  retUDPCell->f213 = iobj_43;
  retUDPCell->f214 = iobj_42;
  retUDPCell->f215 = iobj_41;
  retUDPCell->f216 = iobj_40;
  retUDPCell->f217 = iobj_39;
  retUDPCell->f218 = iobj_38;
  retUDPCell->f219 = iobj_37;
  retUDPCell->f220 = iobj_36;
  retUDPCell->f221 = iobj_35;
  retUDPCell->f222 = iobj_34;
  retUDPCell->f223 = iobj_33;
  retUDPCell->f224 = iobj_32;
  retUDPCell->f225 = iobj_31;
  retUDPCell->f226 = iobj_30;
  retUDPCell->f227 = iobj_29;
  retUDPCell->f228 = iobj_28;
  retUDPCell->f229 = iobj_27;
  retUDPCell->f230 = iobj_26;
  retUDPCell->f231 = iobj_25;
  retUDPCell->f232 = iobj_24;
  retUDPCell->f233 = iobj_23;
  retUDPCell->f234 = iobj_22;
  retUDPCell->f235 = iobj_21;
  retUDPCell->f236 = iobj_20;
  retUDPCell->f237 = iobj_19;
  retUDPCell->f238 = iobj_18;
  retUDPCell->f239 = iobj_17;
  retUDPCell->f240 = iobj_16;
  retUDPCell->f241 = iobj_15;
  retUDPCell->f242 = iobj_14;
  retUDPCell->f243 = iobj_13;
  retUDPCell->f244 = iobj_12;
  retUDPCell->f245 = iobj_11;
  retUDPCell->f246 = iobj_10;
  retUDPCell->f247 = iobj_9;
  retUDPCell->f248 = iobj_8;
  retUDPCell->f249 = iobj_7;
  retUDPCell->f250 = iobj_6;
  retUDPCell->f251 = iobj_5;
  retUDPCell->f252 = iobj_4;
  retUDPCell->f253 = iobj_3;
  retUDPCell->f254 = iobj_2;
  retUDPCell->f255 = iobj_1;
  retUDPCell->f256 = iobj_0;
}

/* End of code generation (udpsendercellforcoder.c) */
