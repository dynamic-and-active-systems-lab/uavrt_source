/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * airspychannelize200.c
 *
 * Code generation for function 'airspychannelize200'
 *
 */

/* Include files */
#include "airspychannelize200.h"
#include "AsyncBuffer.h"
#include "SystemCore.h"
#include "airspy_channelize_emxutil.h"
#include "airspy_channelize_internal_types.h"
#include "airspy_channelize_rtwutil.h"
#include "airspy_channelize_types.h"
#include "airspychannelize100.h"
#include "handle.h"
#include "pause.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "tic.h"
#include "toc.h"
#include "udpsendercellforcoder.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include <stdio.h>
#include <string.h>

/* Function Definitions */
void airspychannelize200(double rawSampleRate)
{
  static b_dsp_AsyncBuffer dataBufferFIFO;
  static b_dsp_Channelizer channelizer;
  static b_dspcodegen_UDPReceiver udpCommand;
  static cell_30 expl_temp;
  static dspcodegen_UDPReceiver udpReceive;
  static dspcodegen_UDPSender lobj_60;
  static dspcodegen_UDPSender lobj_61;
  static dspcodegen_UDPSender lobj_62;
  static dspcodegen_UDPSender lobj_63;
  static dspcodegen_UDPSender lobj_64;
  static dspcodegen_UDPSender lobj_65;
  static dspcodegen_UDPSender lobj_66;
  static dspcodegen_UDPSender lobj_67;
  static dspcodegen_UDPSender lobj_68;
  static dspcodegen_UDPSender lobj_69;
  static dspcodegen_UDPSender lobj_70;
  static dspcodegen_UDPSender lobj_71;
  static dspcodegen_UDPSender lobj_72;
  static dspcodegen_UDPSender lobj_73;
  static dspcodegen_UDPSender lobj_74;
  static dspcodegen_UDPSender lobj_75;
  static dspcodegen_UDPSender lobj_76;
  static dspcodegen_UDPSender lobj_77;
  static dspcodegen_UDPSender lobj_78;
  static dspcodegen_UDPSender lobj_79;
  static dspcodegen_UDPSender lobj_80;
  static dspcodegen_UDPSender lobj_81;
  static dspcodegen_UDPSender lobj_82;
  static dspcodegen_UDPSender lobj_83;
  static dspcodegen_UDPSender lobj_84;
  static dspcodegen_UDPSender lobj_85;
  static creal32_T dataReceived_data[4096];
  static creal32_T b_y_data[1024];
  c_dspcodegen_UDPSender lobj_10;
  c_dspcodegen_UDPSender lobj_11;
  c_dspcodegen_UDPSender lobj_12;
  c_dspcodegen_UDPSender lobj_13;
  c_dspcodegen_UDPSender lobj_14;
  c_dspcodegen_UDPSender lobj_15;
  c_dspcodegen_UDPSender lobj_16;
  c_dspcodegen_UDPSender lobj_17;
  c_dspcodegen_UDPSender lobj_18;
  c_dspcodegen_UDPSender lobj_19;
  c_dspcodegen_UDPSender lobj_20;
  c_dspcodegen_UDPSender lobj_21;
  c_dspcodegen_UDPSender lobj_22;
  c_dspcodegen_UDPSender lobj_23;
  c_dspcodegen_UDPSender lobj_24;
  c_dspcodegen_UDPSender lobj_25;
  c_dspcodegen_UDPSender lobj_26;
  c_dspcodegen_UDPSender lobj_27;
  c_dspcodegen_UDPSender lobj_28;
  c_dspcodegen_UDPSender lobj_29;
  c_dspcodegen_UDPSender lobj_30;
  c_dspcodegen_UDPSender lobj_31;
  c_dspcodegen_UDPSender lobj_32;
  c_dspcodegen_UDPSender lobj_33;
  c_dspcodegen_UDPSender lobj_34;
  c_dspcodegen_UDPSender lobj_35;
  c_dspcodegen_UDPSender lobj_36;
  c_dspcodegen_UDPSender lobj_37;
  c_dspcodegen_UDPSender lobj_38;
  c_dspcodegen_UDPSender lobj_39;
  c_dspcodegen_UDPSender lobj_4;
  c_dspcodegen_UDPSender lobj_40;
  c_dspcodegen_UDPSender lobj_41;
  c_dspcodegen_UDPSender lobj_42;
  c_dspcodegen_UDPSender lobj_43;
  c_dspcodegen_UDPSender lobj_44;
  c_dspcodegen_UDPSender lobj_45;
  c_dspcodegen_UDPSender lobj_46;
  c_dspcodegen_UDPSender lobj_47;
  c_dspcodegen_UDPSender lobj_48;
  c_dspcodegen_UDPSender lobj_49;
  c_dspcodegen_UDPSender lobj_5;
  c_dspcodegen_UDPSender lobj_50;
  c_dspcodegen_UDPSender lobj_51;
  c_dspcodegen_UDPSender lobj_52;
  c_dspcodegen_UDPSender lobj_53;
  c_dspcodegen_UDPSender lobj_54;
  c_dspcodegen_UDPSender lobj_55;
  c_dspcodegen_UDPSender lobj_56;
  c_dspcodegen_UDPSender lobj_57;
  c_dspcodegen_UDPSender lobj_58;
  c_dspcodegen_UDPSender lobj_59;
  c_dspcodegen_UDPSender lobj_6;
  c_dspcodegen_UDPSender lobj_7;
  c_dspcodegen_UDPSender lobj_8;
  c_dspcodegen_UDPSender lobj_9;
  dspcodegen_UDPSender lobj_100;
  dspcodegen_UDPSender lobj_101;
  dspcodegen_UDPSender lobj_102;
  dspcodegen_UDPSender lobj_103;
  dspcodegen_UDPSender lobj_104;
  dspcodegen_UDPSender lobj_105;
  dspcodegen_UDPSender lobj_106;
  dspcodegen_UDPSender lobj_107;
  dspcodegen_UDPSender lobj_108;
  dspcodegen_UDPSender lobj_109;
  dspcodegen_UDPSender lobj_110;
  dspcodegen_UDPSender lobj_111;
  dspcodegen_UDPSender lobj_112;
  dspcodegen_UDPSender lobj_113;
  dspcodegen_UDPSender lobj_114;
  dspcodegen_UDPSender lobj_115;
  dspcodegen_UDPSender lobj_116;
  dspcodegen_UDPSender lobj_117;
  dspcodegen_UDPSender lobj_118;
  dspcodegen_UDPSender lobj_119;
  dspcodegen_UDPSender lobj_120;
  dspcodegen_UDPSender lobj_121;
  dspcodegen_UDPSender lobj_122;
  dspcodegen_UDPSender lobj_123;
  dspcodegen_UDPSender lobj_124;
  dspcodegen_UDPSender lobj_125;
  dspcodegen_UDPSender lobj_126;
  dspcodegen_UDPSender lobj_127;
  dspcodegen_UDPSender lobj_128;
  dspcodegen_UDPSender lobj_129;
  dspcodegen_UDPSender lobj_130;
  dspcodegen_UDPSender lobj_131;
  dspcodegen_UDPSender lobj_132;
  dspcodegen_UDPSender lobj_133;
  dspcodegen_UDPSender lobj_134;
  dspcodegen_UDPSender lobj_135;
  dspcodegen_UDPSender lobj_136;
  dspcodegen_UDPSender lobj_137;
  dspcodegen_UDPSender lobj_138;
  dspcodegen_UDPSender lobj_139;
  dspcodegen_UDPSender lobj_140;
  dspcodegen_UDPSender lobj_141;
  dspcodegen_UDPSender lobj_142;
  dspcodegen_UDPSender lobj_143;
  dspcodegen_UDPSender lobj_144;
  dspcodegen_UDPSender lobj_145;
  dspcodegen_UDPSender lobj_146;
  dspcodegen_UDPSender lobj_147;
  dspcodegen_UDPSender lobj_148;
  dspcodegen_UDPSender lobj_149;
  dspcodegen_UDPSender lobj_150;
  dspcodegen_UDPSender lobj_151;
  dspcodegen_UDPSender lobj_152;
  dspcodegen_UDPSender lobj_153;
  dspcodegen_UDPSender lobj_154;
  dspcodegen_UDPSender lobj_155;
  dspcodegen_UDPSender lobj_156;
  dspcodegen_UDPSender lobj_157;
  dspcodegen_UDPSender lobj_158;
  dspcodegen_UDPSender lobj_159;
  dspcodegen_UDPSender lobj_160;
  dspcodegen_UDPSender lobj_161;
  dspcodegen_UDPSender lobj_162;
  dspcodegen_UDPSender lobj_163;
  dspcodegen_UDPSender lobj_164;
  dspcodegen_UDPSender lobj_165;
  dspcodegen_UDPSender lobj_166;
  dspcodegen_UDPSender lobj_167;
  dspcodegen_UDPSender lobj_168;
  dspcodegen_UDPSender lobj_169;
  dspcodegen_UDPSender lobj_170;
  dspcodegen_UDPSender lobj_171;
  dspcodegen_UDPSender lobj_172;
  dspcodegen_UDPSender lobj_173;
  dspcodegen_UDPSender lobj_174;
  dspcodegen_UDPSender lobj_175;
  dspcodegen_UDPSender lobj_176;
  dspcodegen_UDPSender lobj_177;
  dspcodegen_UDPSender lobj_178;
  dspcodegen_UDPSender lobj_179;
  dspcodegen_UDPSender lobj_180;
  dspcodegen_UDPSender lobj_181;
  dspcodegen_UDPSender lobj_182;
  dspcodegen_UDPSender lobj_183;
  dspcodegen_UDPSender lobj_184;
  dspcodegen_UDPSender lobj_185;
  dspcodegen_UDPSender lobj_186;
  dspcodegen_UDPSender lobj_187;
  dspcodegen_UDPSender lobj_188;
  dspcodegen_UDPSender lobj_189;
  dspcodegen_UDPSender lobj_190;
  dspcodegen_UDPSender lobj_191;
  dspcodegen_UDPSender lobj_192;
  dspcodegen_UDPSender lobj_193;
  dspcodegen_UDPSender lobj_194;
  dspcodegen_UDPSender lobj_195;
  dspcodegen_UDPSender lobj_196;
  dspcodegen_UDPSender lobj_197;
  dspcodegen_UDPSender lobj_198;
  dspcodegen_UDPSender lobj_199;
  dspcodegen_UDPSender lobj_200;
  dspcodegen_UDPSender lobj_201;
  dspcodegen_UDPSender lobj_202;
  dspcodegen_UDPSender lobj_203;
  dspcodegen_UDPSender lobj_204;
  dspcodegen_UDPSender lobj_205;
  dspcodegen_UDPSender lobj_206;
  dspcodegen_UDPSender lobj_207;
  dspcodegen_UDPSender lobj_208;
  dspcodegen_UDPSender lobj_209;
  dspcodegen_UDPSender lobj_210;
  dspcodegen_UDPSender lobj_211;
  dspcodegen_UDPSender lobj_212;
  dspcodegen_UDPSender lobj_213;
  dspcodegen_UDPSender lobj_214;
  dspcodegen_UDPSender lobj_215;
  dspcodegen_UDPSender lobj_216;
  dspcodegen_UDPSender lobj_217;
  dspcodegen_UDPSender lobj_218;
  dspcodegen_UDPSender lobj_219;
  dspcodegen_UDPSender lobj_220;
  dspcodegen_UDPSender lobj_221;
  dspcodegen_UDPSender lobj_222;
  dspcodegen_UDPSender lobj_223;
  dspcodegen_UDPSender lobj_224;
  dspcodegen_UDPSender lobj_225;
  dspcodegen_UDPSender lobj_226;
  dspcodegen_UDPSender lobj_227;
  dspcodegen_UDPSender lobj_228;
  dspcodegen_UDPSender lobj_229;
  dspcodegen_UDPSender lobj_230;
  dspcodegen_UDPSender lobj_231;
  dspcodegen_UDPSender lobj_232;
  dspcodegen_UDPSender lobj_233;
  dspcodegen_UDPSender lobj_234;
  dspcodegen_UDPSender lobj_235;
  dspcodegen_UDPSender lobj_236;
  dspcodegen_UDPSender lobj_237;
  dspcodegen_UDPSender lobj_238;
  dspcodegen_UDPSender lobj_239;
  dspcodegen_UDPSender lobj_240;
  dspcodegen_UDPSender lobj_241;
  dspcodegen_UDPSender lobj_242;
  dspcodegen_UDPSender lobj_243;
  dspcodegen_UDPSender lobj_244;
  dspcodegen_UDPSender lobj_245;
  dspcodegen_UDPSender lobj_246;
  dspcodegen_UDPSender lobj_247;
  dspcodegen_UDPSender lobj_248;
  dspcodegen_UDPSender lobj_249;
  dspcodegen_UDPSender lobj_250;
  dspcodegen_UDPSender lobj_251;
  dspcodegen_UDPSender lobj_252;
  dspcodegen_UDPSender lobj_253;
  dspcodegen_UDPSender lobj_254;
  dspcodegen_UDPSender lobj_255;
  dspcodegen_UDPSender lobj_256;
  dspcodegen_UDPSender lobj_257;
  dspcodegen_UDPSender lobj_258;
  dspcodegen_UDPSender lobj_259;
  dspcodegen_UDPSender lobj_86;
  dspcodegen_UDPSender lobj_87;
  dspcodegen_UDPSender lobj_88;
  dspcodegen_UDPSender lobj_89;
  dspcodegen_UDPSender lobj_90;
  dspcodegen_UDPSender lobj_91;
  dspcodegen_UDPSender lobj_92;
  dspcodegen_UDPSender lobj_93;
  dspcodegen_UDPSender lobj_94;
  dspcodegen_UDPSender lobj_95;
  dspcodegen_UDPSender lobj_96;
  dspcodegen_UDPSender lobj_97;
  dspcodegen_UDPSender lobj_98;
  dspcodegen_UDPSender lobj_99;
  dspcodegen_UDPSender *udps_f1;
  emxArray_creal32_T *varargin_1;
  emxArray_creal32_T *y;
  creal32_T *y_data;
  double expectedFrameSize;
  double rawFrameTime;
  int state_size[2];
  int b_index;
  signed char cmdReceived_data[1024];
  char state_data[4];
  char state_tmp_data[4];
  lobj_4.matlabCodegenIsDeleted = true;
  lobj_5.matlabCodegenIsDeleted = true;
  lobj_6.matlabCodegenIsDeleted = true;
  lobj_7.matlabCodegenIsDeleted = true;
  lobj_8.matlabCodegenIsDeleted = true;
  lobj_9.matlabCodegenIsDeleted = true;
  lobj_10.matlabCodegenIsDeleted = true;
  lobj_11.matlabCodegenIsDeleted = true;
  lobj_12.matlabCodegenIsDeleted = true;
  lobj_13.matlabCodegenIsDeleted = true;
  lobj_14.matlabCodegenIsDeleted = true;
  lobj_15.matlabCodegenIsDeleted = true;
  lobj_16.matlabCodegenIsDeleted = true;
  lobj_17.matlabCodegenIsDeleted = true;
  lobj_18.matlabCodegenIsDeleted = true;
  lobj_19.matlabCodegenIsDeleted = true;
  lobj_20.matlabCodegenIsDeleted = true;
  lobj_21.matlabCodegenIsDeleted = true;
  lobj_22.matlabCodegenIsDeleted = true;
  lobj_23.matlabCodegenIsDeleted = true;
  lobj_24.matlabCodegenIsDeleted = true;
  lobj_25.matlabCodegenIsDeleted = true;
  lobj_26.matlabCodegenIsDeleted = true;
  lobj_27.matlabCodegenIsDeleted = true;
  lobj_28.matlabCodegenIsDeleted = true;
  lobj_29.matlabCodegenIsDeleted = true;
  lobj_30.matlabCodegenIsDeleted = true;
  lobj_31.matlabCodegenIsDeleted = true;
  lobj_32.matlabCodegenIsDeleted = true;
  lobj_33.matlabCodegenIsDeleted = true;
  lobj_34.matlabCodegenIsDeleted = true;
  lobj_35.matlabCodegenIsDeleted = true;
  lobj_36.matlabCodegenIsDeleted = true;
  lobj_37.matlabCodegenIsDeleted = true;
  lobj_38.matlabCodegenIsDeleted = true;
  lobj_39.matlabCodegenIsDeleted = true;
  lobj_40.matlabCodegenIsDeleted = true;
  lobj_41.matlabCodegenIsDeleted = true;
  lobj_42.matlabCodegenIsDeleted = true;
  lobj_43.matlabCodegenIsDeleted = true;
  lobj_44.matlabCodegenIsDeleted = true;
  lobj_45.matlabCodegenIsDeleted = true;
  lobj_46.matlabCodegenIsDeleted = true;
  lobj_47.matlabCodegenIsDeleted = true;
  lobj_48.matlabCodegenIsDeleted = true;
  lobj_49.matlabCodegenIsDeleted = true;
  lobj_50.matlabCodegenIsDeleted = true;
  lobj_51.matlabCodegenIsDeleted = true;
  lobj_52.matlabCodegenIsDeleted = true;
  lobj_53.matlabCodegenIsDeleted = true;
  lobj_54.matlabCodegenIsDeleted = true;
  lobj_55.matlabCodegenIsDeleted = true;
  lobj_56.matlabCodegenIsDeleted = true;
  lobj_57.matlabCodegenIsDeleted = true;
  lobj_58.matlabCodegenIsDeleted = true;
  lobj_59.matlabCodegenIsDeleted = true;
  lobj_60.matlabCodegenIsDeleted = true;
  lobj_61.matlabCodegenIsDeleted = true;
  lobj_62.matlabCodegenIsDeleted = true;
  lobj_63.matlabCodegenIsDeleted = true;
  lobj_64.matlabCodegenIsDeleted = true;
  lobj_65.matlabCodegenIsDeleted = true;
  lobj_66.matlabCodegenIsDeleted = true;
  lobj_67.matlabCodegenIsDeleted = true;
  lobj_68.matlabCodegenIsDeleted = true;
  lobj_69.matlabCodegenIsDeleted = true;
  lobj_70.matlabCodegenIsDeleted = true;
  lobj_71.matlabCodegenIsDeleted = true;
  lobj_72.matlabCodegenIsDeleted = true;
  lobj_73.matlabCodegenIsDeleted = true;
  lobj_74.matlabCodegenIsDeleted = true;
  lobj_75.matlabCodegenIsDeleted = true;
  lobj_76.matlabCodegenIsDeleted = true;
  lobj_77.matlabCodegenIsDeleted = true;
  lobj_78.matlabCodegenIsDeleted = true;
  lobj_79.matlabCodegenIsDeleted = true;
  lobj_80.matlabCodegenIsDeleted = true;
  lobj_81.matlabCodegenIsDeleted = true;
  lobj_82.matlabCodegenIsDeleted = true;
  lobj_83.matlabCodegenIsDeleted = true;
  lobj_84.matlabCodegenIsDeleted = true;
  lobj_85.matlabCodegenIsDeleted = true;
  lobj_86.matlabCodegenIsDeleted = true;
  lobj_87.matlabCodegenIsDeleted = true;
  lobj_88.matlabCodegenIsDeleted = true;
  lobj_89.matlabCodegenIsDeleted = true;
  lobj_90.matlabCodegenIsDeleted = true;
  lobj_91.matlabCodegenIsDeleted = true;
  lobj_92.matlabCodegenIsDeleted = true;
  lobj_93.matlabCodegenIsDeleted = true;
  lobj_94.matlabCodegenIsDeleted = true;
  lobj_95.matlabCodegenIsDeleted = true;
  lobj_96.matlabCodegenIsDeleted = true;
  lobj_97.matlabCodegenIsDeleted = true;
  lobj_98.matlabCodegenIsDeleted = true;
  lobj_99.matlabCodegenIsDeleted = true;
  lobj_100.matlabCodegenIsDeleted = true;
  lobj_101.matlabCodegenIsDeleted = true;
  lobj_102.matlabCodegenIsDeleted = true;
  lobj_103.matlabCodegenIsDeleted = true;
  lobj_104.matlabCodegenIsDeleted = true;
  lobj_105.matlabCodegenIsDeleted = true;
  lobj_106.matlabCodegenIsDeleted = true;
  lobj_107.matlabCodegenIsDeleted = true;
  lobj_108.matlabCodegenIsDeleted = true;
  lobj_109.matlabCodegenIsDeleted = true;
  lobj_110.matlabCodegenIsDeleted = true;
  lobj_111.matlabCodegenIsDeleted = true;
  lobj_112.matlabCodegenIsDeleted = true;
  lobj_113.matlabCodegenIsDeleted = true;
  lobj_114.matlabCodegenIsDeleted = true;
  lobj_115.matlabCodegenIsDeleted = true;
  lobj_116.matlabCodegenIsDeleted = true;
  lobj_117.matlabCodegenIsDeleted = true;
  lobj_118.matlabCodegenIsDeleted = true;
  lobj_119.matlabCodegenIsDeleted = true;
  lobj_120.matlabCodegenIsDeleted = true;
  lobj_121.matlabCodegenIsDeleted = true;
  lobj_122.matlabCodegenIsDeleted = true;
  lobj_123.matlabCodegenIsDeleted = true;
  lobj_124.matlabCodegenIsDeleted = true;
  lobj_125.matlabCodegenIsDeleted = true;
  lobj_126.matlabCodegenIsDeleted = true;
  lobj_127.matlabCodegenIsDeleted = true;
  lobj_128.matlabCodegenIsDeleted = true;
  lobj_129.matlabCodegenIsDeleted = true;
  lobj_130.matlabCodegenIsDeleted = true;
  lobj_131.matlabCodegenIsDeleted = true;
  lobj_132.matlabCodegenIsDeleted = true;
  lobj_133.matlabCodegenIsDeleted = true;
  lobj_134.matlabCodegenIsDeleted = true;
  lobj_135.matlabCodegenIsDeleted = true;
  lobj_136.matlabCodegenIsDeleted = true;
  lobj_137.matlabCodegenIsDeleted = true;
  lobj_138.matlabCodegenIsDeleted = true;
  lobj_139.matlabCodegenIsDeleted = true;
  lobj_140.matlabCodegenIsDeleted = true;
  lobj_141.matlabCodegenIsDeleted = true;
  lobj_142.matlabCodegenIsDeleted = true;
  lobj_143.matlabCodegenIsDeleted = true;
  lobj_144.matlabCodegenIsDeleted = true;
  lobj_145.matlabCodegenIsDeleted = true;
  lobj_146.matlabCodegenIsDeleted = true;
  lobj_147.matlabCodegenIsDeleted = true;
  lobj_148.matlabCodegenIsDeleted = true;
  lobj_149.matlabCodegenIsDeleted = true;
  lobj_150.matlabCodegenIsDeleted = true;
  lobj_151.matlabCodegenIsDeleted = true;
  lobj_152.matlabCodegenIsDeleted = true;
  lobj_153.matlabCodegenIsDeleted = true;
  lobj_154.matlabCodegenIsDeleted = true;
  lobj_155.matlabCodegenIsDeleted = true;
  lobj_156.matlabCodegenIsDeleted = true;
  lobj_157.matlabCodegenIsDeleted = true;
  lobj_158.matlabCodegenIsDeleted = true;
  lobj_159.matlabCodegenIsDeleted = true;
  lobj_160.matlabCodegenIsDeleted = true;
  lobj_161.matlabCodegenIsDeleted = true;
  lobj_162.matlabCodegenIsDeleted = true;
  lobj_163.matlabCodegenIsDeleted = true;
  lobj_164.matlabCodegenIsDeleted = true;
  lobj_165.matlabCodegenIsDeleted = true;
  lobj_166.matlabCodegenIsDeleted = true;
  lobj_167.matlabCodegenIsDeleted = true;
  lobj_168.matlabCodegenIsDeleted = true;
  lobj_169.matlabCodegenIsDeleted = true;
  lobj_170.matlabCodegenIsDeleted = true;
  lobj_171.matlabCodegenIsDeleted = true;
  lobj_172.matlabCodegenIsDeleted = true;
  lobj_173.matlabCodegenIsDeleted = true;
  lobj_174.matlabCodegenIsDeleted = true;
  lobj_175.matlabCodegenIsDeleted = true;
  lobj_176.matlabCodegenIsDeleted = true;
  lobj_177.matlabCodegenIsDeleted = true;
  lobj_178.matlabCodegenIsDeleted = true;
  lobj_179.matlabCodegenIsDeleted = true;
  lobj_180.matlabCodegenIsDeleted = true;
  lobj_181.matlabCodegenIsDeleted = true;
  lobj_182.matlabCodegenIsDeleted = true;
  lobj_183.matlabCodegenIsDeleted = true;
  lobj_184.matlabCodegenIsDeleted = true;
  lobj_185.matlabCodegenIsDeleted = true;
  lobj_186.matlabCodegenIsDeleted = true;
  lobj_187.matlabCodegenIsDeleted = true;
  lobj_188.matlabCodegenIsDeleted = true;
  lobj_189.matlabCodegenIsDeleted = true;
  lobj_190.matlabCodegenIsDeleted = true;
  lobj_191.matlabCodegenIsDeleted = true;
  lobj_192.matlabCodegenIsDeleted = true;
  lobj_193.matlabCodegenIsDeleted = true;
  lobj_194.matlabCodegenIsDeleted = true;
  lobj_195.matlabCodegenIsDeleted = true;
  lobj_196.matlabCodegenIsDeleted = true;
  lobj_197.matlabCodegenIsDeleted = true;
  lobj_198.matlabCodegenIsDeleted = true;
  lobj_199.matlabCodegenIsDeleted = true;
  lobj_200.matlabCodegenIsDeleted = true;
  lobj_201.matlabCodegenIsDeleted = true;
  lobj_202.matlabCodegenIsDeleted = true;
  lobj_203.matlabCodegenIsDeleted = true;
  lobj_204.matlabCodegenIsDeleted = true;
  lobj_205.matlabCodegenIsDeleted = true;
  lobj_206.matlabCodegenIsDeleted = true;
  lobj_207.matlabCodegenIsDeleted = true;
  lobj_208.matlabCodegenIsDeleted = true;
  lobj_209.matlabCodegenIsDeleted = true;
  lobj_210.matlabCodegenIsDeleted = true;
  lobj_211.matlabCodegenIsDeleted = true;
  lobj_212.matlabCodegenIsDeleted = true;
  lobj_213.matlabCodegenIsDeleted = true;
  lobj_214.matlabCodegenIsDeleted = true;
  lobj_215.matlabCodegenIsDeleted = true;
  lobj_216.matlabCodegenIsDeleted = true;
  lobj_217.matlabCodegenIsDeleted = true;
  lobj_218.matlabCodegenIsDeleted = true;
  lobj_219.matlabCodegenIsDeleted = true;
  lobj_220.matlabCodegenIsDeleted = true;
  lobj_221.matlabCodegenIsDeleted = true;
  lobj_222.matlabCodegenIsDeleted = true;
  lobj_223.matlabCodegenIsDeleted = true;
  lobj_224.matlabCodegenIsDeleted = true;
  lobj_225.matlabCodegenIsDeleted = true;
  lobj_226.matlabCodegenIsDeleted = true;
  lobj_227.matlabCodegenIsDeleted = true;
  lobj_228.matlabCodegenIsDeleted = true;
  lobj_229.matlabCodegenIsDeleted = true;
  lobj_230.matlabCodegenIsDeleted = true;
  lobj_231.matlabCodegenIsDeleted = true;
  lobj_232.matlabCodegenIsDeleted = true;
  lobj_233.matlabCodegenIsDeleted = true;
  lobj_234.matlabCodegenIsDeleted = true;
  lobj_235.matlabCodegenIsDeleted = true;
  lobj_236.matlabCodegenIsDeleted = true;
  lobj_237.matlabCodegenIsDeleted = true;
  lobj_238.matlabCodegenIsDeleted = true;
  lobj_239.matlabCodegenIsDeleted = true;
  lobj_240.matlabCodegenIsDeleted = true;
  lobj_241.matlabCodegenIsDeleted = true;
  lobj_242.matlabCodegenIsDeleted = true;
  lobj_243.matlabCodegenIsDeleted = true;
  lobj_244.matlabCodegenIsDeleted = true;
  lobj_245.matlabCodegenIsDeleted = true;
  lobj_246.matlabCodegenIsDeleted = true;
  lobj_247.matlabCodegenIsDeleted = true;
  lobj_248.matlabCodegenIsDeleted = true;
  lobj_249.matlabCodegenIsDeleted = true;
  lobj_250.matlabCodegenIsDeleted = true;
  lobj_251.matlabCodegenIsDeleted = true;
  lobj_252.matlabCodegenIsDeleted = true;
  lobj_253.matlabCodegenIsDeleted = true;
  lobj_254.matlabCodegenIsDeleted = true;
  lobj_255.matlabCodegenIsDeleted = true;
  lobj_256.matlabCodegenIsDeleted = true;
  lobj_257.matlabCodegenIsDeleted = true;
  lobj_258.matlabCodegenIsDeleted = true;
  lobj_259.matlabCodegenIsDeleted = true;
  /* AIRSPYFHCHANNELIZE200 receives complex (IQ) data over a UDP connection from
   */
  /* an SDR (single precision), channelizes it, and servers it  */
  /* up over 200 diferent UDP ports. */
  /*    This function is designed specifically to receive incoming data that */
  /*    has been passed to it via an interanl UDP connection. The program
   * expects */
  /*    128 sample frames of 8-byte complex samples (4 real, 4 imaginary) to be
   */
  /*    sent over UDP. The program receives that data and fills a buffer until
   */
  /*    enough samples have been received that 1024 samples will be generated */
  /*    on the output channels at the decimated sample rate.  */
  /*  */
  /*    Once the buffer fills, the data is channelized and */
  /*    served via UDP to corresponding ports. The function opens a command */
  /*    channel so that integers can be passed to enable basic control */
  /*    authority over the program operation, enabling starting of data */
  /*    processing, pausing, and termination of the program. */
  /*  */
  /*    Note that all UDP ports have been hardcoded for this function because */
  /*    they are used within the dsp.udpsender and dsp.udpreceiver system */
  /*    objects. When deploying this code to C via Matlab coder, these system */
  /*    object arguments must be constants, which limits the ability of this */
  /*    function to receive ports as arguments and set them at run time. They */
  /*    must be a constant at compile time. */
  /*  */
  /*    Normal channelization allows for decimation rates and the number of */
  /*    channels to be different. This function holds them equal. Therefore, */
  /*    the decimated rate for each channel is equal to the raw airspy sample */
  /*    rate divided by the number of channels. Additionally, the center */
  /*    frequencies of each channel is therefore */
  /*  */
  /*    Data sent over the UDP output channels are single valued complex */
  /*    frames. Each output frame contains 1024 complex values, or 2048 */
  /*    individual single precision values. Each frame also contains a */
  /*    timestamp encoded into a complex number in the first element of the */
  /*    frame. The received data frame therefore contains 1025 complex values.
   */
  /*    The timestamp on each frame is associate with the time of arrival of */
  /*    the first sample in the frame.  */
  /*  */
  /*    The timestamp is a precision posixtime value in milliseconds. The  */
  /*    timestamp is transmitted as a single precision complex value. The */
  /*    imaginary part of this timestamp contains the first 7 digits of the */
  /*    time in milliseconds. The real part contains the upper digits (>=8) of
   */
  /*    the timestamp. See the help for int2singlecomplex and singlecomplex2int
   */
  /*    for more information on this transmission standard.  */
  /*  */
  /*    PORT LISTING */
  /*        10000       Receive port for airspy data */
  /*                       Complex single precision data */
  /*                       Maximum message size 1024 bytes */
  /*        10001       Receive port for fucntion control commands */
  /*                       Real int8 data */
  /*                       Maximum message size 1024 bytes */
  /*                       Valid inputs are */
  /*                            1   Start data reception/transmission */
  /*                            0   Stop (pause) data reception/transmission */
  /*                                and flush the buffer */
  /*                            -1  Terminate the function */
  /*        20000:20*** Send ports for serving channelized UDP data. The */
  /*                    center frequency of the channel for port 20000 is the */
  /*                    center frequency of the incoming data. Subsequent port
   */
  /*                    correspond to the increasing channel numbers and */
  /*                    frequency, eventually wrapping to negative frequencies
   */
  /*                    above Fs/2. See notes about channel center frequencies
   */
  /*                    below.The max port number is equal to  */
  /*                    20000+numberofchannels-1 */
  /*  */
  /*    INPUTS: */
  /*        rawSampleRate   A single integer sample rate. Valid entries */
  /*                        correspond to those available for the Airspy HF+ */
  /*                        radio: 375 kS/s */
  /*  */
  /*    OUTPUTS: */
  /*        none */
  /*  */
  /* Notes:    */
  /*        ABOUT CHANNEL CENTER FREQUENCIES: */
  /*        Matlab provides the centerFrequencies function that accepts a */
  /*        channelizer object and a sample rate, and then specifies the */
  /*        center frequencies of the associated channel. This list however is
   */
  /*        centered at zero and provides negative frequencies. For example a */
  /*        channelizer with Fs = 48000 and a decimation factor of 3 would */
  /*        report center frequencies [-24000 -12000 0 12000]. If the fvtool is
   */
  /*        used on this channelizer (with the legend turned on) the center */
  /*        frequencies would be [0 12000 -24000 -12000] for filteres 1-4. The
   */
  /*        shifting here reflects a inconsistency in Matlab's channel */
  /*        reporting. The channelizer outputs follow the latter order, and as
   */
  /*        such, so to do the UDP port outputs in this function.  */
  /*        Because the  number of chanels and the decimation are the same,  */
  /*        the frequency of these channels are -Fs/nc*floor(nc/2)<fc<Fs/2,  */
  /*        (where nc is the number of channels), if nc is odd. For even nc */
  /*        -Fs/2 < fc < Fs/2-Fs/nc. In both cases the frequency steps are  */
  /*        Fs/nc. This was determined by using the centerFrequencies.m  */
  /*        function on example channelizer objects. If using the */
  /*        centerFrequencies output the circshift command can be used to get */
  /*        the correct order of channel frequency. For example: */
  /*        circshift(centerFrequencies(channizerObject,48000),ceil(numChannels/2))
   */
  /*  */
  /*        ABOUT INCOMING DATA: */
  /*        An Airspy connected to the machine via USB is received using */
  /*        the airspyhf_rx or airspy_rx executable. Using the program with the
   */
  /*        '-r stdout' option allows the data to be piped to another program */
  /*        with the | character. Netcat can then be use to provide the data to
   */
  /*        this function via UDP. An example commandline input would be */
  /*  */
  /*        /usr/local/bin/airspyhf_rx -f 91.7 -m on -a 912000 -n 9120000 -r */
  /*        stdout -g on -l high -t 0 | netcat -u localhost 10000 */
  /*  */
  /*        Note that this system call must executed after this function is */
  /*        already running or a 'Connection refused' error will occur in */
  /*        terminal. */
  /*        Command signals send via UDP can be entered in the command line as
   */
  /*        follows: */
  /*            Start (send a 1):  */
  /*                echo -e -n '\x01'| netcat -u localhost 10001 */
  /*            Pause (send a 0):  */
  /*                echo -e -n '\x00'| netcat -u localhost 10001 */
  /*            Kill (send a -1):  */
  /*                echo -e -n '\xFF'| netcat -u localhost 10001 */
  /*  */
  /* -------------------------------------------------------------------------
   */
  /* Author:    Michael Shafer */
  /* Date:      2022-01-18 */
  /* -------------------------------------------------------------------------
   */
  printf("Channelizer: Starting up...\n");
  fflush(stdout);
  /* Channelization Settings */
  /* Decimation is currently set to equal nChannels. Must be a factor of
   * rawFrameLength */
  /* UDP Settings */
  /* 10000:10039; */
  /* Incoming Data Variables */
  rawFrameTime = 128.0 / rawSampleRate;
  /* [912 768 456 384 256 192]*1000; */
  printf("Channelizer: Setting up UDP command and data ports...\n");
  fflush(stdout);
  /*  SETUP UDP COMMAND INPUT OBJECT */
  udpCommand.isInitialized = 0;
  /* System object Constructor function: dsp.UDPReceiver */
  udpCommand.cSFunObject.P0_Port = 10001;
  udpCommand.matlabCodegenIsDeleted = false;
  /* %127.0.0.1',...  %Accept all */
  /* %2^16 = 65536, 2^18 */
  SystemCore_setup(&udpCommand);
  /*  SETUP UDP DATA INPUT OBJECT */
  udpReceive.isInitialized = 0;
  /* System object Constructor function: dsp.UDPReceiver */
  udpReceive.cSFunObject.P0_Port = 10000;
  udpReceive.matlabCodegenIsDeleted = false;
  /* %127.0.0.1',... %Accept all */
  /* %2^16 = 65536, 2^18 */
  /* %1024,...%128 on a Mac and 2048 on Linux */
  b_SystemCore_setup(&udpReceive);
  /*  SETUP UDP OUTPUT OBJECTS */
  printf("Channelizer: Setting up output channel UDP ports...\n");
  fflush(stdout);
  /*  Must be a multiple of 128 */
  dataBufferFIFO.pBuffer.NumChannels = -1;
  dataBufferFIFO.pBuffer.isInitialized = 0;
  dataBufferFIFO.pBuffer.matlabCodegenIsDeleted = false;
  dataBufferFIFO.matlabCodegenIsDeleted = false;
  c_AsyncBuffer_write(&dataBufferFIFO);
  /* Write a single value so the number of channels is specified for coder.
   * Specify complex single for airspy data */
  c_AsyncBuffer_read(&dataBufferFIFO);
  /* Read out that single sample to empty the buffer. */
  b_udpsendercellforcoder(
      &lobj_4, &lobj_5, &lobj_6, &lobj_7, &lobj_8, &lobj_9, &lobj_10, &lobj_11,
      &lobj_12, &lobj_13, &lobj_14, &lobj_15, &lobj_16, &lobj_17, &lobj_18,
      &lobj_19, &lobj_20, &lobj_21, &lobj_22, &lobj_23, &lobj_24, &lobj_25,
      &lobj_26, &lobj_27, &lobj_28, &lobj_29, &lobj_30, &lobj_31, &lobj_32,
      &lobj_33, &lobj_34, &lobj_35, &lobj_36, &lobj_37, &lobj_38, &lobj_39,
      &lobj_40, &lobj_41, &lobj_42, &lobj_43, &lobj_44, &lobj_45, &lobj_46,
      &lobj_47, &lobj_48, &lobj_49, &lobj_50, &lobj_51, &lobj_52, &lobj_53,
      &lobj_54, &lobj_55, &lobj_56, &lobj_57, &lobj_58, &lobj_59, &lobj_60,
      &lobj_61, &lobj_62, &lobj_63, &lobj_64, &lobj_65, &lobj_66, &lobj_67,
      &lobj_68, &lobj_69, &lobj_70, &lobj_71, &lobj_72, &lobj_73, &lobj_74,
      &lobj_75, &lobj_76, &lobj_77, &lobj_78, &lobj_79, &lobj_80, &lobj_81,
      &lobj_82, &lobj_83, &lobj_84, &lobj_85, &lobj_86, &lobj_87, &lobj_88,
      &lobj_89, &lobj_90, &lobj_91, &lobj_92, &lobj_93, &lobj_94, &lobj_95,
      &lobj_96, &lobj_97, &lobj_98, &lobj_99, &lobj_100, &lobj_101, &lobj_102,
      &lobj_103, &lobj_104, &lobj_105, &lobj_106, &lobj_107, &lobj_108,
      &lobj_109, &lobj_110, &lobj_111, &lobj_112, &lobj_113, &lobj_114,
      &lobj_115, &lobj_116, &lobj_117, &lobj_118, &lobj_119, &lobj_120,
      &lobj_121, &lobj_122, &lobj_123, &lobj_124, &lobj_125, &lobj_126,
      &lobj_127, &lobj_128, &lobj_129, &lobj_130, &lobj_131, &lobj_132,
      &lobj_133, &lobj_134, &lobj_135, &lobj_136, &lobj_137, &lobj_138,
      &lobj_139, &lobj_140, &lobj_141, &lobj_142, &lobj_143, &lobj_144,
      &lobj_145, &lobj_146, &lobj_147, &lobj_148, &lobj_149, &lobj_150,
      &lobj_151, &lobj_152, &lobj_153, &lobj_154, &lobj_155, &lobj_156,
      &lobj_157, &lobj_158, &lobj_159, &lobj_160, &lobj_161, &lobj_162,
      &lobj_163, &lobj_164, &lobj_165, &lobj_166, &lobj_167, &lobj_168,
      &lobj_169, &lobj_170, &lobj_171, &lobj_172, &lobj_173, &lobj_174,
      &lobj_175, &lobj_176, &lobj_177, &lobj_178, &lobj_179, &lobj_180,
      &lobj_181, &lobj_182, &lobj_183, &lobj_184, &lobj_185, &lobj_186,
      &lobj_187, &lobj_188, &lobj_189, &lobj_190, &lobj_191, &lobj_192,
      &lobj_193, &lobj_194, &lobj_195, &lobj_196, &lobj_197, &lobj_198,
      &lobj_199, &lobj_200, &lobj_201, &lobj_202, &lobj_203, &lobj_204,
      &lobj_205, &lobj_206, &lobj_207, &lobj_208, &lobj_209, &lobj_210,
      &lobj_211, &lobj_212, &lobj_213, &lobj_214, &lobj_215, &lobj_216,
      &lobj_217, &lobj_218, &lobj_219, &lobj_220, &lobj_221, &lobj_222,
      &lobj_223, &lobj_224, &lobj_225, &lobj_226, &lobj_227, &lobj_228,
      &lobj_229, &lobj_230, &lobj_231, &lobj_232, &lobj_233, &lobj_234,
      &lobj_235, &lobj_236, &lobj_237, &lobj_238, &lobj_239, &lobj_240,
      &lobj_241, &lobj_242, &lobj_243, &lobj_244, &lobj_245, &lobj_246,
      &lobj_247, &lobj_248, &lobj_249, &lobj_250, &lobj_251, &lobj_252,
      &lobj_253, &lobj_254, &lobj_255, &lobj_256, &lobj_257, &lobj_258,
      &lobj_259, &expl_temp);
  udps_f1 = expl_temp.f1;
  channelizer.numChannels = -1;
  channelizer.isInitialized = 0;
  channelizer.matlabCodegenIsDeleted = false;
  /* Make initial call to udps. First call is very slow and can cause missed */
  /* samples if left within the while loop */
  SystemCore_step(expl_temp.f1);
  /* Add one for blank time stamp */
  expectedFrameSize = 128.0;
  state_tmp_data[0] = 'r';
  state_tmp_data[1] = 'u';
  state_tmp_data[2] = 'n';
  state_size[0] = 1;
  state_size[1] = 3;
  for (b_index = 0; b_index < 3; b_index++) {
    state_data[b_index] = state_tmp_data[b_index];
  }
  printf("Channelizer: Setup complete. Awaiting commands...\n");
  fflush(stdout);
  tic();
  emxInit_creal32_T(&y, 2);
  emxInit_creal32_T(&varargin_1, 1);
  int exitg1;
  do {
    exitg1 = 0;
    if (b_strcmp(state_data, state_size)) {
      b_index = 0;
    } else if (c_strcmp(state_data, state_size)) {
      b_index = 1;
    } else if (d_strcmp(state_data, state_size)) {
      b_index = 2;
    } else {
      b_index = -1;
    }
    switch (b_index) {
    case 0: {
      int dataReceived_size[2];
      b_SystemCore_step(&udpReceive, dataReceived_data, dataReceived_size);
      if ((dataReceived_size[0] != 0) && (dataReceived_size[1] != 0)) {
        int qY;
        /* Used to keep a running estimated of the expected frame */
        /* size to help identifiy subsize frames received.  */
        if (dataReceived_size[0] != expectedFrameSize) {
          expectedFrameSize = rt_roundd_snf(
              ((double)dataReceived_size[0] + expectedFrameSize) / 2.0);
        }
        d_AsyncBuffer_write(&dataBufferFIFO, dataReceived_data,
                            dataReceived_size[0]);
        /* Call with (:) to help coder realize it is a single channel */
        if ((dataBufferFIFO.pBuffer.WritePointer >= 0) &&
            (dataBufferFIFO.pBuffer.ReadPointer <
             dataBufferFIFO.pBuffer.WritePointer - MAX_int32_T)) {
          b_index = MAX_int32_T;
        } else if ((dataBufferFIFO.pBuffer.WritePointer < 0) &&
                   (dataBufferFIFO.pBuffer.ReadPointer >
                    dataBufferFIFO.pBuffer.WritePointer - MIN_int32_T)) {
          b_index = MIN_int32_T;
        } else {
          b_index = dataBufferFIFO.pBuffer.WritePointer -
                    dataBufferFIFO.pBuffer.ReadPointer;
        }
        if (b_index < -2147483647) {
          b_index = MIN_int32_T;
        } else {
          b_index--;
        }
        if (dataBufferFIFO.pBuffer.ReadPointer < -2147074047) {
          qY = MAX_int32_T;
        } else {
          qY = 409600 - dataBufferFIFO.pBuffer.ReadPointer;
        }
        if ((qY < 0) &&
            (dataBufferFIFO.pBuffer.WritePointer < MIN_int32_T - qY)) {
          qY = MIN_int32_T;
        } else if ((qY > 0) &&
                   (dataBufferFIFO.pBuffer.WritePointer > MAX_int32_T - qY)) {
          qY = MAX_int32_T;
        } else {
          qY += dataBufferFIFO.pBuffer.WritePointer;
        }
        if (dataBufferFIFO.pBuffer.ReadPointer <
            dataBufferFIFO.pBuffer.WritePointer) {
          qY = b_index;
        } else if (dataBufferFIFO.pBuffer.ReadPointer ==
                   dataBufferFIFO.pBuffer.WritePointer) {
          qY = 409600;
        }
        if (qY >= 204800) {
          double validatedHoleFilling_idx_0;
          if (expectedFrameSize < 2.147483648E+9) {
            if (expectedFrameSize >= -2.147483648E+9) {
              b_index = (int)expectedFrameSize;
            } else {
              b_index = MIN_int32_T;
            }
          } else {
            b_index = MAX_int32_T;
          }
          printf(
              "Channelizer: Running - Buffer filled with %u samples. Flushing "
              "to channels. Currently receiving: %i samples per packet.\n",
              204800U, b_index);
          fflush(stdout);
          validatedHoleFilling_idx_0 = toc();
          printf(
              "Actual time between buffer flushes: %6.6f.  Expected: %6.6f. \n",
              validatedHoleFilling_idx_0, 204800.0 / rawSampleRate);
          fflush(stdout);
          tic();
          d_AsyncBuffer_read(&dataBufferFIFO, varargin_1);
          e_SystemCore_step(&channelizer, varargin_1, y);
          y_data = y->data;
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index];
          }
          f_SystemCore_step(udps_f1, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 1024];
          }
          f_SystemCore_step(expl_temp.f2, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 2048];
          }
          f_SystemCore_step(expl_temp.f3, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 3072];
          }
          f_SystemCore_step(expl_temp.f4, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 4096];
          }
          f_SystemCore_step(expl_temp.f5, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 5120];
          }
          f_SystemCore_step(expl_temp.f6, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 6144];
          }
          f_SystemCore_step(expl_temp.f7, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 7168];
          }
          f_SystemCore_step(expl_temp.f8, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 8192];
          }
          f_SystemCore_step(expl_temp.f9, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 9216];
          }
          f_SystemCore_step(expl_temp.f10, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 10240];
          }
          f_SystemCore_step(expl_temp.f11, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 11264];
          }
          f_SystemCore_step(expl_temp.f12, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 12288];
          }
          f_SystemCore_step(expl_temp.f13, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 13312];
          }
          f_SystemCore_step(expl_temp.f14, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 14336];
          }
          f_SystemCore_step(expl_temp.f15, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 15360];
          }
          f_SystemCore_step(expl_temp.f16, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 16384];
          }
          f_SystemCore_step(expl_temp.f17, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 17408];
          }
          f_SystemCore_step(expl_temp.f18, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 18432];
          }
          f_SystemCore_step(expl_temp.f19, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 19456];
          }
          f_SystemCore_step(expl_temp.f20, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 20480];
          }
          f_SystemCore_step(expl_temp.f21, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 21504];
          }
          f_SystemCore_step(expl_temp.f22, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 22528];
          }
          f_SystemCore_step(expl_temp.f23, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 23552];
          }
          f_SystemCore_step(expl_temp.f24, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 24576];
          }
          f_SystemCore_step(expl_temp.f25, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 25600];
          }
          f_SystemCore_step(expl_temp.f26, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 26624];
          }
          f_SystemCore_step(expl_temp.f27, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 27648];
          }
          f_SystemCore_step(expl_temp.f28, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 28672];
          }
          f_SystemCore_step(expl_temp.f29, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 29696];
          }
          f_SystemCore_step(expl_temp.f30, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 30720];
          }
          f_SystemCore_step(expl_temp.f31, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 31744];
          }
          f_SystemCore_step(expl_temp.f32, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 32768];
          }
          f_SystemCore_step(expl_temp.f33, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 33792];
          }
          f_SystemCore_step(expl_temp.f34, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 34816];
          }
          f_SystemCore_step(expl_temp.f35, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 35840];
          }
          f_SystemCore_step(expl_temp.f36, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 36864];
          }
          f_SystemCore_step(expl_temp.f37, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 37888];
          }
          f_SystemCore_step(expl_temp.f38, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 38912];
          }
          f_SystemCore_step(expl_temp.f39, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 39936];
          }
          f_SystemCore_step(expl_temp.f40, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 40960];
          }
          f_SystemCore_step(expl_temp.f41, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 41984];
          }
          f_SystemCore_step(expl_temp.f42, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 43008];
          }
          f_SystemCore_step(expl_temp.f43, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 44032];
          }
          f_SystemCore_step(expl_temp.f44, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 45056];
          }
          f_SystemCore_step(expl_temp.f45, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 46080];
          }
          f_SystemCore_step(expl_temp.f46, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 47104];
          }
          f_SystemCore_step(expl_temp.f47, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 48128];
          }
          f_SystemCore_step(expl_temp.f48, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 49152];
          }
          f_SystemCore_step(expl_temp.f49, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 50176];
          }
          f_SystemCore_step(expl_temp.f50, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 51200];
          }
          f_SystemCore_step(expl_temp.f51, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 52224];
          }
          f_SystemCore_step(expl_temp.f52, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 53248];
          }
          f_SystemCore_step(expl_temp.f53, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 54272];
          }
          f_SystemCore_step(expl_temp.f54, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 55296];
          }
          f_SystemCore_step(expl_temp.f55, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 56320];
          }
          f_SystemCore_step(expl_temp.f56, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 57344];
          }
          f_SystemCore_step(expl_temp.f57, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 58368];
          }
          f_SystemCore_step(expl_temp.f58, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 59392];
          }
          f_SystemCore_step(expl_temp.f59, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 60416];
          }
          f_SystemCore_step(expl_temp.f60, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 61440];
          }
          f_SystemCore_step(expl_temp.f61, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 62464];
          }
          f_SystemCore_step(expl_temp.f62, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 63488];
          }
          f_SystemCore_step(expl_temp.f63, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 64512];
          }
          f_SystemCore_step(expl_temp.f64, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 65536];
          }
          f_SystemCore_step(expl_temp.f65, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 66560];
          }
          f_SystemCore_step(expl_temp.f66, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 67584];
          }
          f_SystemCore_step(expl_temp.f67, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 68608];
          }
          f_SystemCore_step(expl_temp.f68, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 69632];
          }
          f_SystemCore_step(expl_temp.f69, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 70656];
          }
          f_SystemCore_step(expl_temp.f70, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 71680];
          }
          f_SystemCore_step(expl_temp.f71, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 72704];
          }
          f_SystemCore_step(expl_temp.f72, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 73728];
          }
          f_SystemCore_step(expl_temp.f73, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 74752];
          }
          f_SystemCore_step(expl_temp.f74, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 75776];
          }
          f_SystemCore_step(expl_temp.f75, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 76800];
          }
          f_SystemCore_step(expl_temp.f76, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 77824];
          }
          f_SystemCore_step(expl_temp.f77, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 78848];
          }
          f_SystemCore_step(expl_temp.f78, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 79872];
          }
          f_SystemCore_step(expl_temp.f79, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 80896];
          }
          f_SystemCore_step(expl_temp.f80, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 81920];
          }
          f_SystemCore_step(expl_temp.f81, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 82944];
          }
          f_SystemCore_step(expl_temp.f82, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 83968];
          }
          f_SystemCore_step(expl_temp.f83, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 84992];
          }
          f_SystemCore_step(expl_temp.f84, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 86016];
          }
          f_SystemCore_step(expl_temp.f85, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 87040];
          }
          f_SystemCore_step(expl_temp.f86, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 88064];
          }
          f_SystemCore_step(expl_temp.f87, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 89088];
          }
          f_SystemCore_step(expl_temp.f88, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 90112];
          }
          f_SystemCore_step(expl_temp.f89, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 91136];
          }
          f_SystemCore_step(expl_temp.f90, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 92160];
          }
          f_SystemCore_step(expl_temp.f91, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 93184];
          }
          f_SystemCore_step(expl_temp.f92, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 94208];
          }
          f_SystemCore_step(expl_temp.f93, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 95232];
          }
          f_SystemCore_step(expl_temp.f94, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 96256];
          }
          f_SystemCore_step(expl_temp.f95, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 97280];
          }
          f_SystemCore_step(expl_temp.f96, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 98304];
          }
          f_SystemCore_step(expl_temp.f97, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 99328];
          }
          f_SystemCore_step(expl_temp.f98, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 100352];
          }
          f_SystemCore_step(expl_temp.f99, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 101376];
          }
          f_SystemCore_step(expl_temp.f100, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 102400];
          }
          f_SystemCore_step(expl_temp.f101, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 103424];
          }
          f_SystemCore_step(expl_temp.f102, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 104448];
          }
          f_SystemCore_step(expl_temp.f103, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 105472];
          }
          f_SystemCore_step(expl_temp.f104, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 106496];
          }
          f_SystemCore_step(expl_temp.f105, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 107520];
          }
          f_SystemCore_step(expl_temp.f106, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 108544];
          }
          f_SystemCore_step(expl_temp.f107, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 109568];
          }
          f_SystemCore_step(expl_temp.f108, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 110592];
          }
          f_SystemCore_step(expl_temp.f109, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 111616];
          }
          f_SystemCore_step(expl_temp.f110, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 112640];
          }
          f_SystemCore_step(expl_temp.f111, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 113664];
          }
          f_SystemCore_step(expl_temp.f112, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 114688];
          }
          f_SystemCore_step(expl_temp.f113, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 115712];
          }
          f_SystemCore_step(expl_temp.f114, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 116736];
          }
          f_SystemCore_step(expl_temp.f115, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 117760];
          }
          f_SystemCore_step(expl_temp.f116, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 118784];
          }
          f_SystemCore_step(expl_temp.f117, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 119808];
          }
          f_SystemCore_step(expl_temp.f118, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 120832];
          }
          f_SystemCore_step(expl_temp.f119, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 121856];
          }
          f_SystemCore_step(expl_temp.f120, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 122880];
          }
          f_SystemCore_step(expl_temp.f121, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 123904];
          }
          f_SystemCore_step(expl_temp.f122, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 124928];
          }
          f_SystemCore_step(expl_temp.f123, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 125952];
          }
          f_SystemCore_step(expl_temp.f124, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 126976];
          }
          f_SystemCore_step(expl_temp.f125, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 128000];
          }
          f_SystemCore_step(expl_temp.f126, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 129024];
          }
          f_SystemCore_step(expl_temp.f127, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 130048];
          }
          f_SystemCore_step(expl_temp.f128, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 131072];
          }
          f_SystemCore_step(expl_temp.f129, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 132096];
          }
          f_SystemCore_step(expl_temp.f130, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 133120];
          }
          f_SystemCore_step(expl_temp.f131, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 134144];
          }
          f_SystemCore_step(expl_temp.f132, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 135168];
          }
          f_SystemCore_step(expl_temp.f133, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 136192];
          }
          f_SystemCore_step(expl_temp.f134, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 137216];
          }
          f_SystemCore_step(expl_temp.f135, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 138240];
          }
          f_SystemCore_step(expl_temp.f136, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 139264];
          }
          f_SystemCore_step(expl_temp.f137, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 140288];
          }
          f_SystemCore_step(expl_temp.f138, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 141312];
          }
          f_SystemCore_step(expl_temp.f139, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 142336];
          }
          f_SystemCore_step(expl_temp.f140, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 143360];
          }
          f_SystemCore_step(expl_temp.f141, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 144384];
          }
          f_SystemCore_step(expl_temp.f142, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 145408];
          }
          f_SystemCore_step(expl_temp.f143, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 146432];
          }
          f_SystemCore_step(expl_temp.f144, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 147456];
          }
          f_SystemCore_step(expl_temp.f145, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 148480];
          }
          f_SystemCore_step(expl_temp.f146, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 149504];
          }
          f_SystemCore_step(expl_temp.f147, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 150528];
          }
          f_SystemCore_step(expl_temp.f148, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 151552];
          }
          f_SystemCore_step(expl_temp.f149, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 152576];
          }
          f_SystemCore_step(expl_temp.f150, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 153600];
          }
          f_SystemCore_step(expl_temp.f151, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 154624];
          }
          f_SystemCore_step(expl_temp.f152, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 155648];
          }
          f_SystemCore_step(expl_temp.f153, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 156672];
          }
          f_SystemCore_step(expl_temp.f154, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 157696];
          }
          f_SystemCore_step(expl_temp.f155, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 158720];
          }
          f_SystemCore_step(expl_temp.f156, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 159744];
          }
          f_SystemCore_step(expl_temp.f157, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 160768];
          }
          f_SystemCore_step(expl_temp.f158, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 161792];
          }
          f_SystemCore_step(expl_temp.f159, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 162816];
          }
          f_SystemCore_step(expl_temp.f160, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 163840];
          }
          f_SystemCore_step(expl_temp.f161, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 164864];
          }
          f_SystemCore_step(expl_temp.f162, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 165888];
          }
          f_SystemCore_step(expl_temp.f163, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 166912];
          }
          f_SystemCore_step(expl_temp.f164, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 167936];
          }
          f_SystemCore_step(expl_temp.f165, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 168960];
          }
          f_SystemCore_step(expl_temp.f166, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 169984];
          }
          f_SystemCore_step(expl_temp.f167, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 171008];
          }
          f_SystemCore_step(expl_temp.f168, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 172032];
          }
          f_SystemCore_step(expl_temp.f169, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 173056];
          }
          f_SystemCore_step(expl_temp.f170, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 174080];
          }
          f_SystemCore_step(expl_temp.f171, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 175104];
          }
          f_SystemCore_step(expl_temp.f172, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 176128];
          }
          f_SystemCore_step(expl_temp.f173, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 177152];
          }
          f_SystemCore_step(expl_temp.f174, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 178176];
          }
          f_SystemCore_step(expl_temp.f175, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 179200];
          }
          f_SystemCore_step(expl_temp.f176, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 180224];
          }
          f_SystemCore_step(expl_temp.f177, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 181248];
          }
          f_SystemCore_step(expl_temp.f178, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 182272];
          }
          f_SystemCore_step(expl_temp.f179, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 183296];
          }
          f_SystemCore_step(expl_temp.f180, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 184320];
          }
          f_SystemCore_step(expl_temp.f181, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 185344];
          }
          f_SystemCore_step(expl_temp.f182, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 186368];
          }
          f_SystemCore_step(expl_temp.f183, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 187392];
          }
          f_SystemCore_step(expl_temp.f184, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 188416];
          }
          f_SystemCore_step(expl_temp.f185, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 189440];
          }
          f_SystemCore_step(expl_temp.f186, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 190464];
          }
          f_SystemCore_step(expl_temp.f187, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 191488];
          }
          f_SystemCore_step(expl_temp.f188, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 192512];
          }
          f_SystemCore_step(expl_temp.f189, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 193536];
          }
          f_SystemCore_step(expl_temp.f190, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 194560];
          }
          f_SystemCore_step(expl_temp.f191, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 195584];
          }
          f_SystemCore_step(expl_temp.f192, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 196608];
          }
          f_SystemCore_step(expl_temp.f193, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 197632];
          }
          f_SystemCore_step(expl_temp.f194, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 198656];
          }
          f_SystemCore_step(expl_temp.f195, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 199680];
          }
          f_SystemCore_step(expl_temp.f196, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 200704];
          }
          f_SystemCore_step(expl_temp.f197, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 201728];
          }
          f_SystemCore_step(expl_temp.f198, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 202752];
          }
          f_SystemCore_step(expl_temp.f199, b_y_data);
          for (b_index = 0; b_index < 1024; b_index++) {
            b_y_data[b_index] = y_data[b_index + 203776];
          }
          f_SystemCore_step(expl_temp.f200, b_y_data);
          validatedHoleFilling_idx_0 = toc();
          printf("Time required to channelize: %6.6f \n",
                 validatedHoleFilling_idx_0);
          fflush(stdout);
        }
      } else {
        pause(rawFrameTime / 2.0);
      }
      d_SystemCore_step(&udpCommand, cmdReceived_data, dataReceived_size);
      state_size[0] = 1;
      state_size[1] = 3;
      for (b_index = 0; b_index < 3; b_index++) {
        state_data[b_index] = state_tmp_data[b_index];
      }
      checkcommand(cmdReceived_data, dataReceived_size, state_data, state_size);
    } break;
    case 1: {
      int dataReceived_size[2];
      if (dataBufferFIFO.pBuffer.isInitialized == 1) {
        dataBufferFIFO.pBuffer.ReadPointer = 1;
        dataBufferFIFO.pBuffer.WritePointer = 2;
        dataBufferFIFO.pBuffer.CumulativeOverrun = 0;
        dataBufferFIFO.pBuffer.CumulativeUnderrun = 0;
        memset(&dataBufferFIFO.pBuffer.Cache[0], 0,
               409601U * sizeof(creal32_T));
      }
      printf("Channelizer: Idle. Waiting for command...\n");
      fflush(stdout);
      pause(0.25);
      /* Wait a bit so to throttle idle execution */
      d_SystemCore_step(&udpCommand, cmdReceived_data, dataReceived_size);
      state_size[0] = 1;
      state_size[1] = 4;
      state_data[0] = 'i';
      state_data[1] = 'd';
      state_data[2] = 'l';
      state_data[3] = 'e';
      checkcommand(cmdReceived_data, dataReceived_size, state_data, state_size);
    } break;
    case 2:
      exitg1 = 1;
      break;
    default:
      /* Should never get to this case, but jump to idle if we get */
      /* here. */
      state_size[0] = 1;
      state_size[1] = 4;
      state_data[0] = 'i';
      state_data[1] = 'd';
      state_data[2] = 'l';
      state_data[3] = 'e';
      break;
    }
  } while (exitg1 == 0);
  emxFree_creal32_T(&varargin_1);
  emxFree_creal32_T(&y);
  printf("Channelizer: Entering Kill state. Shutting down.\n");
  fflush(stdout);
  b_AsyncBuffer_release(&dataBufferFIFO);
  SystemCore_release(&udpReceive);
  b_SystemCore_release(&udpCommand);
  e_handle_matlabCodegenDestructo(&lobj_259);
  e_handle_matlabCodegenDestructo(&lobj_258);
  e_handle_matlabCodegenDestructo(&lobj_257);
  e_handle_matlabCodegenDestructo(&lobj_256);
  e_handle_matlabCodegenDestructo(&lobj_255);
  e_handle_matlabCodegenDestructo(&lobj_254);
  e_handle_matlabCodegenDestructo(&lobj_253);
  e_handle_matlabCodegenDestructo(&lobj_252);
  e_handle_matlabCodegenDestructo(&lobj_251);
  e_handle_matlabCodegenDestructo(&lobj_250);
  e_handle_matlabCodegenDestructo(&lobj_249);
  e_handle_matlabCodegenDestructo(&lobj_248);
  e_handle_matlabCodegenDestructo(&lobj_247);
  e_handle_matlabCodegenDestructo(&lobj_246);
  e_handle_matlabCodegenDestructo(&lobj_245);
  e_handle_matlabCodegenDestructo(&lobj_244);
  e_handle_matlabCodegenDestructo(&lobj_243);
  e_handle_matlabCodegenDestructo(&lobj_242);
  e_handle_matlabCodegenDestructo(&lobj_241);
  e_handle_matlabCodegenDestructo(&lobj_240);
  e_handle_matlabCodegenDestructo(&lobj_239);
  e_handle_matlabCodegenDestructo(&lobj_238);
  e_handle_matlabCodegenDestructo(&lobj_237);
  e_handle_matlabCodegenDestructo(&lobj_236);
  e_handle_matlabCodegenDestructo(&lobj_235);
  e_handle_matlabCodegenDestructo(&lobj_234);
  e_handle_matlabCodegenDestructo(&lobj_233);
  e_handle_matlabCodegenDestructo(&lobj_232);
  e_handle_matlabCodegenDestructo(&lobj_231);
  e_handle_matlabCodegenDestructo(&lobj_230);
  e_handle_matlabCodegenDestructo(&lobj_229);
  e_handle_matlabCodegenDestructo(&lobj_228);
  e_handle_matlabCodegenDestructo(&lobj_227);
  e_handle_matlabCodegenDestructo(&lobj_226);
  e_handle_matlabCodegenDestructo(&lobj_225);
  e_handle_matlabCodegenDestructo(&lobj_224);
  e_handle_matlabCodegenDestructo(&lobj_223);
  e_handle_matlabCodegenDestructo(&lobj_222);
  e_handle_matlabCodegenDestructo(&lobj_221);
  e_handle_matlabCodegenDestructo(&lobj_220);
  e_handle_matlabCodegenDestructo(&lobj_219);
  e_handle_matlabCodegenDestructo(&lobj_218);
  e_handle_matlabCodegenDestructo(&lobj_217);
  e_handle_matlabCodegenDestructo(&lobj_216);
  e_handle_matlabCodegenDestructo(&lobj_215);
  e_handle_matlabCodegenDestructo(&lobj_214);
  e_handle_matlabCodegenDestructo(&lobj_213);
  e_handle_matlabCodegenDestructo(&lobj_212);
  e_handle_matlabCodegenDestructo(&lobj_211);
  e_handle_matlabCodegenDestructo(&lobj_210);
  e_handle_matlabCodegenDestructo(&lobj_209);
  e_handle_matlabCodegenDestructo(&lobj_208);
  e_handle_matlabCodegenDestructo(&lobj_207);
  e_handle_matlabCodegenDestructo(&lobj_206);
  e_handle_matlabCodegenDestructo(&lobj_205);
  e_handle_matlabCodegenDestructo(&lobj_204);
  e_handle_matlabCodegenDestructo(&lobj_203);
  e_handle_matlabCodegenDestructo(&lobj_202);
  e_handle_matlabCodegenDestructo(&lobj_201);
  e_handle_matlabCodegenDestructo(&lobj_200);
  e_handle_matlabCodegenDestructo(&lobj_199);
  e_handle_matlabCodegenDestructo(&lobj_198);
  e_handle_matlabCodegenDestructo(&lobj_197);
  e_handle_matlabCodegenDestructo(&lobj_196);
  e_handle_matlabCodegenDestructo(&lobj_195);
  e_handle_matlabCodegenDestructo(&lobj_194);
  e_handle_matlabCodegenDestructo(&lobj_193);
  e_handle_matlabCodegenDestructo(&lobj_192);
  e_handle_matlabCodegenDestructo(&lobj_191);
  e_handle_matlabCodegenDestructo(&lobj_190);
  e_handle_matlabCodegenDestructo(&lobj_189);
  e_handle_matlabCodegenDestructo(&lobj_188);
  e_handle_matlabCodegenDestructo(&lobj_187);
  e_handle_matlabCodegenDestructo(&lobj_186);
  e_handle_matlabCodegenDestructo(&lobj_185);
  e_handle_matlabCodegenDestructo(&lobj_184);
  e_handle_matlabCodegenDestructo(&lobj_183);
  e_handle_matlabCodegenDestructo(&lobj_182);
  e_handle_matlabCodegenDestructo(&lobj_181);
  e_handle_matlabCodegenDestructo(&lobj_180);
  e_handle_matlabCodegenDestructo(&lobj_179);
  e_handle_matlabCodegenDestructo(&lobj_178);
  e_handle_matlabCodegenDestructo(&lobj_177);
  e_handle_matlabCodegenDestructo(&lobj_176);
  e_handle_matlabCodegenDestructo(&lobj_175);
  e_handle_matlabCodegenDestructo(&lobj_174);
  e_handle_matlabCodegenDestructo(&lobj_173);
  e_handle_matlabCodegenDestructo(&lobj_172);
  e_handle_matlabCodegenDestructo(&lobj_171);
  e_handle_matlabCodegenDestructo(&lobj_170);
  e_handle_matlabCodegenDestructo(&lobj_169);
  e_handle_matlabCodegenDestructo(&lobj_168);
  e_handle_matlabCodegenDestructo(&lobj_167);
  e_handle_matlabCodegenDestructo(&lobj_166);
  e_handle_matlabCodegenDestructo(&lobj_165);
  e_handle_matlabCodegenDestructo(&lobj_164);
  e_handle_matlabCodegenDestructo(&lobj_163);
  e_handle_matlabCodegenDestructo(&lobj_162);
  e_handle_matlabCodegenDestructo(&lobj_161);
  e_handle_matlabCodegenDestructo(&lobj_160);
  e_handle_matlabCodegenDestructo(&lobj_159);
  e_handle_matlabCodegenDestructo(&lobj_158);
  e_handle_matlabCodegenDestructo(&lobj_157);
  e_handle_matlabCodegenDestructo(&lobj_156);
  e_handle_matlabCodegenDestructo(&lobj_155);
  e_handle_matlabCodegenDestructo(&lobj_154);
  e_handle_matlabCodegenDestructo(&lobj_153);
  e_handle_matlabCodegenDestructo(&lobj_152);
  e_handle_matlabCodegenDestructo(&lobj_151);
  e_handle_matlabCodegenDestructo(&lobj_150);
  e_handle_matlabCodegenDestructo(&lobj_149);
  e_handle_matlabCodegenDestructo(&lobj_148);
  e_handle_matlabCodegenDestructo(&lobj_147);
  e_handle_matlabCodegenDestructo(&lobj_146);
  e_handle_matlabCodegenDestructo(&lobj_145);
  e_handle_matlabCodegenDestructo(&lobj_144);
  e_handle_matlabCodegenDestructo(&lobj_143);
  e_handle_matlabCodegenDestructo(&lobj_142);
  e_handle_matlabCodegenDestructo(&lobj_141);
  e_handle_matlabCodegenDestructo(&lobj_140);
  e_handle_matlabCodegenDestructo(&lobj_139);
  e_handle_matlabCodegenDestructo(&lobj_138);
  e_handle_matlabCodegenDestructo(&lobj_137);
  e_handle_matlabCodegenDestructo(&lobj_136);
  e_handle_matlabCodegenDestructo(&lobj_135);
  e_handle_matlabCodegenDestructo(&lobj_134);
  e_handle_matlabCodegenDestructo(&lobj_133);
  e_handle_matlabCodegenDestructo(&lobj_132);
  e_handle_matlabCodegenDestructo(&lobj_131);
  e_handle_matlabCodegenDestructo(&lobj_130);
  e_handle_matlabCodegenDestructo(&lobj_129);
  e_handle_matlabCodegenDestructo(&lobj_128);
  e_handle_matlabCodegenDestructo(&lobj_127);
  e_handle_matlabCodegenDestructo(&lobj_126);
  e_handle_matlabCodegenDestructo(&lobj_125);
  e_handle_matlabCodegenDestructo(&lobj_124);
  e_handle_matlabCodegenDestructo(&lobj_123);
  e_handle_matlabCodegenDestructo(&lobj_122);
  e_handle_matlabCodegenDestructo(&lobj_121);
  e_handle_matlabCodegenDestructo(&lobj_120);
  e_handle_matlabCodegenDestructo(&lobj_119);
  e_handle_matlabCodegenDestructo(&lobj_118);
  e_handle_matlabCodegenDestructo(&lobj_117);
  e_handle_matlabCodegenDestructo(&lobj_116);
  e_handle_matlabCodegenDestructo(&lobj_115);
  e_handle_matlabCodegenDestructo(&lobj_114);
  e_handle_matlabCodegenDestructo(&lobj_113);
  e_handle_matlabCodegenDestructo(&lobj_112);
  e_handle_matlabCodegenDestructo(&lobj_111);
  e_handle_matlabCodegenDestructo(&lobj_110);
  e_handle_matlabCodegenDestructo(&lobj_109);
  e_handle_matlabCodegenDestructo(&lobj_108);
  e_handle_matlabCodegenDestructo(&lobj_107);
  e_handle_matlabCodegenDestructo(&lobj_106);
  e_handle_matlabCodegenDestructo(&lobj_105);
  e_handle_matlabCodegenDestructo(&lobj_104);
  e_handle_matlabCodegenDestructo(&lobj_103);
  e_handle_matlabCodegenDestructo(&lobj_102);
  e_handle_matlabCodegenDestructo(&lobj_101);
  e_handle_matlabCodegenDestructo(&lobj_100);
  e_handle_matlabCodegenDestructo(&lobj_99);
  e_handle_matlabCodegenDestructo(&lobj_98);
  e_handle_matlabCodegenDestructo(&lobj_97);
  e_handle_matlabCodegenDestructo(&lobj_96);
  e_handle_matlabCodegenDestructo(&lobj_95);
  e_handle_matlabCodegenDestructo(&lobj_94);
  e_handle_matlabCodegenDestructo(&lobj_93);
  e_handle_matlabCodegenDestructo(&lobj_92);
  e_handle_matlabCodegenDestructo(&lobj_91);
  e_handle_matlabCodegenDestructo(&lobj_90);
  e_handle_matlabCodegenDestructo(&lobj_89);
  e_handle_matlabCodegenDestructo(&lobj_88);
  e_handle_matlabCodegenDestructo(&lobj_87);
  e_handle_matlabCodegenDestructo(&lobj_86);
  e_handle_matlabCodegenDestructo(&lobj_85);
  e_handle_matlabCodegenDestructo(&lobj_84);
  e_handle_matlabCodegenDestructo(&lobj_83);
  e_handle_matlabCodegenDestructo(&lobj_82);
  e_handle_matlabCodegenDestructo(&lobj_81);
  e_handle_matlabCodegenDestructo(&lobj_80);
  e_handle_matlabCodegenDestructo(&lobj_79);
  e_handle_matlabCodegenDestructo(&lobj_78);
  e_handle_matlabCodegenDestructo(&lobj_77);
  e_handle_matlabCodegenDestructo(&lobj_76);
  e_handle_matlabCodegenDestructo(&lobj_75);
  e_handle_matlabCodegenDestructo(&lobj_74);
  e_handle_matlabCodegenDestructo(&lobj_73);
  e_handle_matlabCodegenDestructo(&lobj_72);
  e_handle_matlabCodegenDestructo(&lobj_71);
  e_handle_matlabCodegenDestructo(&lobj_70);
  e_handle_matlabCodegenDestructo(&lobj_69);
  e_handle_matlabCodegenDestructo(&lobj_68);
  e_handle_matlabCodegenDestructo(&lobj_67);
  e_handle_matlabCodegenDestructo(&lobj_66);
  e_handle_matlabCodegenDestructo(&lobj_65);
  e_handle_matlabCodegenDestructo(&lobj_64);
  e_handle_matlabCodegenDestructo(&lobj_63);
  e_handle_matlabCodegenDestructo(&lobj_62);
  e_handle_matlabCodegenDestructo(&lobj_61);
  e_handle_matlabCodegenDestructo(&lobj_60);
  if (!lobj_59.matlabCodegenIsDeleted) {
    lobj_59.matlabCodegenIsDeleted = true;
    if (lobj_59.isInitialized == 1) {
      lobj_59.isInitialized = 2;
    }
  }
  if (!lobj_58.matlabCodegenIsDeleted) {
    lobj_58.matlabCodegenIsDeleted = true;
    if (lobj_58.isInitialized == 1) {
      lobj_58.isInitialized = 2;
    }
  }
  if (!lobj_57.matlabCodegenIsDeleted) {
    lobj_57.matlabCodegenIsDeleted = true;
    if (lobj_57.isInitialized == 1) {
      lobj_57.isInitialized = 2;
    }
  }
  if (!lobj_56.matlabCodegenIsDeleted) {
    lobj_56.matlabCodegenIsDeleted = true;
    if (lobj_56.isInitialized == 1) {
      lobj_56.isInitialized = 2;
    }
  }
  if (!lobj_55.matlabCodegenIsDeleted) {
    lobj_55.matlabCodegenIsDeleted = true;
    if (lobj_55.isInitialized == 1) {
      lobj_55.isInitialized = 2;
    }
  }
  if (!lobj_54.matlabCodegenIsDeleted) {
    lobj_54.matlabCodegenIsDeleted = true;
    if (lobj_54.isInitialized == 1) {
      lobj_54.isInitialized = 2;
    }
  }
  if (!lobj_53.matlabCodegenIsDeleted) {
    lobj_53.matlabCodegenIsDeleted = true;
    if (lobj_53.isInitialized == 1) {
      lobj_53.isInitialized = 2;
    }
  }
  if (!lobj_52.matlabCodegenIsDeleted) {
    lobj_52.matlabCodegenIsDeleted = true;
    if (lobj_52.isInitialized == 1) {
      lobj_52.isInitialized = 2;
    }
  }
  if (!lobj_51.matlabCodegenIsDeleted) {
    lobj_51.matlabCodegenIsDeleted = true;
    if (lobj_51.isInitialized == 1) {
      lobj_51.isInitialized = 2;
    }
  }
  if (!lobj_50.matlabCodegenIsDeleted) {
    lobj_50.matlabCodegenIsDeleted = true;
    if (lobj_50.isInitialized == 1) {
      lobj_50.isInitialized = 2;
    }
  }
  if (!lobj_49.matlabCodegenIsDeleted) {
    lobj_49.matlabCodegenIsDeleted = true;
    if (lobj_49.isInitialized == 1) {
      lobj_49.isInitialized = 2;
    }
  }
  if (!lobj_48.matlabCodegenIsDeleted) {
    lobj_48.matlabCodegenIsDeleted = true;
    if (lobj_48.isInitialized == 1) {
      lobj_48.isInitialized = 2;
    }
  }
  if (!lobj_47.matlabCodegenIsDeleted) {
    lobj_47.matlabCodegenIsDeleted = true;
    if (lobj_47.isInitialized == 1) {
      lobj_47.isInitialized = 2;
    }
  }
  if (!lobj_46.matlabCodegenIsDeleted) {
    lobj_46.matlabCodegenIsDeleted = true;
    if (lobj_46.isInitialized == 1) {
      lobj_46.isInitialized = 2;
    }
  }
  if (!lobj_45.matlabCodegenIsDeleted) {
    lobj_45.matlabCodegenIsDeleted = true;
    if (lobj_45.isInitialized == 1) {
      lobj_45.isInitialized = 2;
    }
  }
  if (!lobj_44.matlabCodegenIsDeleted) {
    lobj_44.matlabCodegenIsDeleted = true;
    if (lobj_44.isInitialized == 1) {
      lobj_44.isInitialized = 2;
    }
  }
  if (!lobj_43.matlabCodegenIsDeleted) {
    lobj_43.matlabCodegenIsDeleted = true;
    if (lobj_43.isInitialized == 1) {
      lobj_43.isInitialized = 2;
    }
  }
  if (!lobj_42.matlabCodegenIsDeleted) {
    lobj_42.matlabCodegenIsDeleted = true;
    if (lobj_42.isInitialized == 1) {
      lobj_42.isInitialized = 2;
    }
  }
  if (!lobj_41.matlabCodegenIsDeleted) {
    lobj_41.matlabCodegenIsDeleted = true;
    if (lobj_41.isInitialized == 1) {
      lobj_41.isInitialized = 2;
    }
  }
  if (!lobj_40.matlabCodegenIsDeleted) {
    lobj_40.matlabCodegenIsDeleted = true;
    if (lobj_40.isInitialized == 1) {
      lobj_40.isInitialized = 2;
    }
  }
  if (!lobj_39.matlabCodegenIsDeleted) {
    lobj_39.matlabCodegenIsDeleted = true;
    if (lobj_39.isInitialized == 1) {
      lobj_39.isInitialized = 2;
    }
  }
  if (!lobj_38.matlabCodegenIsDeleted) {
    lobj_38.matlabCodegenIsDeleted = true;
    if (lobj_38.isInitialized == 1) {
      lobj_38.isInitialized = 2;
    }
  }
  if (!lobj_37.matlabCodegenIsDeleted) {
    lobj_37.matlabCodegenIsDeleted = true;
    if (lobj_37.isInitialized == 1) {
      lobj_37.isInitialized = 2;
    }
  }
  if (!lobj_36.matlabCodegenIsDeleted) {
    lobj_36.matlabCodegenIsDeleted = true;
    if (lobj_36.isInitialized == 1) {
      lobj_36.isInitialized = 2;
    }
  }
  if (!lobj_35.matlabCodegenIsDeleted) {
    lobj_35.matlabCodegenIsDeleted = true;
    if (lobj_35.isInitialized == 1) {
      lobj_35.isInitialized = 2;
    }
  }
  if (!lobj_34.matlabCodegenIsDeleted) {
    lobj_34.matlabCodegenIsDeleted = true;
    if (lobj_34.isInitialized == 1) {
      lobj_34.isInitialized = 2;
    }
  }
  if (!lobj_33.matlabCodegenIsDeleted) {
    lobj_33.matlabCodegenIsDeleted = true;
    if (lobj_33.isInitialized == 1) {
      lobj_33.isInitialized = 2;
    }
  }
  if (!lobj_32.matlabCodegenIsDeleted) {
    lobj_32.matlabCodegenIsDeleted = true;
    if (lobj_32.isInitialized == 1) {
      lobj_32.isInitialized = 2;
    }
  }
  if (!lobj_31.matlabCodegenIsDeleted) {
    lobj_31.matlabCodegenIsDeleted = true;
    if (lobj_31.isInitialized == 1) {
      lobj_31.isInitialized = 2;
    }
  }
  if (!lobj_30.matlabCodegenIsDeleted) {
    lobj_30.matlabCodegenIsDeleted = true;
    if (lobj_30.isInitialized == 1) {
      lobj_30.isInitialized = 2;
    }
  }
  if (!lobj_29.matlabCodegenIsDeleted) {
    lobj_29.matlabCodegenIsDeleted = true;
    if (lobj_29.isInitialized == 1) {
      lobj_29.isInitialized = 2;
    }
  }
  if (!lobj_28.matlabCodegenIsDeleted) {
    lobj_28.matlabCodegenIsDeleted = true;
    if (lobj_28.isInitialized == 1) {
      lobj_28.isInitialized = 2;
    }
  }
  if (!lobj_27.matlabCodegenIsDeleted) {
    lobj_27.matlabCodegenIsDeleted = true;
    if (lobj_27.isInitialized == 1) {
      lobj_27.isInitialized = 2;
    }
  }
  if (!lobj_26.matlabCodegenIsDeleted) {
    lobj_26.matlabCodegenIsDeleted = true;
    if (lobj_26.isInitialized == 1) {
      lobj_26.isInitialized = 2;
    }
  }
  if (!lobj_25.matlabCodegenIsDeleted) {
    lobj_25.matlabCodegenIsDeleted = true;
    if (lobj_25.isInitialized == 1) {
      lobj_25.isInitialized = 2;
    }
  }
  if (!lobj_24.matlabCodegenIsDeleted) {
    lobj_24.matlabCodegenIsDeleted = true;
    if (lobj_24.isInitialized == 1) {
      lobj_24.isInitialized = 2;
    }
  }
  if (!lobj_23.matlabCodegenIsDeleted) {
    lobj_23.matlabCodegenIsDeleted = true;
    if (lobj_23.isInitialized == 1) {
      lobj_23.isInitialized = 2;
    }
  }
  if (!lobj_22.matlabCodegenIsDeleted) {
    lobj_22.matlabCodegenIsDeleted = true;
    if (lobj_22.isInitialized == 1) {
      lobj_22.isInitialized = 2;
    }
  }
  if (!lobj_21.matlabCodegenIsDeleted) {
    lobj_21.matlabCodegenIsDeleted = true;
    if (lobj_21.isInitialized == 1) {
      lobj_21.isInitialized = 2;
    }
  }
  if (!lobj_20.matlabCodegenIsDeleted) {
    lobj_20.matlabCodegenIsDeleted = true;
    if (lobj_20.isInitialized == 1) {
      lobj_20.isInitialized = 2;
    }
  }
  if (!lobj_19.matlabCodegenIsDeleted) {
    lobj_19.matlabCodegenIsDeleted = true;
    if (lobj_19.isInitialized == 1) {
      lobj_19.isInitialized = 2;
    }
  }
  if (!lobj_18.matlabCodegenIsDeleted) {
    lobj_18.matlabCodegenIsDeleted = true;
    if (lobj_18.isInitialized == 1) {
      lobj_18.isInitialized = 2;
    }
  }
  if (!lobj_17.matlabCodegenIsDeleted) {
    lobj_17.matlabCodegenIsDeleted = true;
    if (lobj_17.isInitialized == 1) {
      lobj_17.isInitialized = 2;
    }
  }
  if (!lobj_16.matlabCodegenIsDeleted) {
    lobj_16.matlabCodegenIsDeleted = true;
    if (lobj_16.isInitialized == 1) {
      lobj_16.isInitialized = 2;
    }
  }
  if (!lobj_15.matlabCodegenIsDeleted) {
    lobj_15.matlabCodegenIsDeleted = true;
    if (lobj_15.isInitialized == 1) {
      lobj_15.isInitialized = 2;
    }
  }
  if (!lobj_14.matlabCodegenIsDeleted) {
    lobj_14.matlabCodegenIsDeleted = true;
    if (lobj_14.isInitialized == 1) {
      lobj_14.isInitialized = 2;
    }
  }
  if (!lobj_13.matlabCodegenIsDeleted) {
    lobj_13.matlabCodegenIsDeleted = true;
    if (lobj_13.isInitialized == 1) {
      lobj_13.isInitialized = 2;
    }
  }
  if (!lobj_12.matlabCodegenIsDeleted) {
    lobj_12.matlabCodegenIsDeleted = true;
    if (lobj_12.isInitialized == 1) {
      lobj_12.isInitialized = 2;
    }
  }
  if (!lobj_11.matlabCodegenIsDeleted) {
    lobj_11.matlabCodegenIsDeleted = true;
    if (lobj_11.isInitialized == 1) {
      lobj_11.isInitialized = 2;
    }
  }
  if (!lobj_10.matlabCodegenIsDeleted) {
    lobj_10.matlabCodegenIsDeleted = true;
    if (lobj_10.isInitialized == 1) {
      lobj_10.isInitialized = 2;
    }
  }
  if (!lobj_9.matlabCodegenIsDeleted) {
    lobj_9.matlabCodegenIsDeleted = true;
    if (lobj_9.isInitialized == 1) {
      lobj_9.isInitialized = 2;
    }
  }
  if (!lobj_8.matlabCodegenIsDeleted) {
    lobj_8.matlabCodegenIsDeleted = true;
    if (lobj_8.isInitialized == 1) {
      lobj_8.isInitialized = 2;
    }
  }
  if (!lobj_7.matlabCodegenIsDeleted) {
    lobj_7.matlabCodegenIsDeleted = true;
    if (lobj_7.isInitialized == 1) {
      lobj_7.isInitialized = 2;
    }
  }
  if (!lobj_6.matlabCodegenIsDeleted) {
    lobj_6.matlabCodegenIsDeleted = true;
    if (lobj_6.isInitialized == 1) {
      lobj_6.isInitialized = 2;
    }
  }
  if (!lobj_5.matlabCodegenIsDeleted) {
    lobj_5.matlabCodegenIsDeleted = true;
    if (lobj_5.isInitialized == 1) {
      lobj_5.isInitialized = 2;
    }
  }
  if (!lobj_4.matlabCodegenIsDeleted) {
    lobj_4.matlabCodegenIsDeleted = true;
    if (lobj_4.isInitialized == 1) {
      lobj_4.isInitialized = 2;
    }
  }
  if (!dataBufferFIFO.matlabCodegenIsDeleted) {
    dataBufferFIFO.matlabCodegenIsDeleted = true;
  }
  d_handle_matlabCodegenDestructo(&dataBufferFIFO.pBuffer);
  b_handle_matlabCodegenDestructo(&udpReceive);
  handle_matlabCodegenDestructor(&udpCommand);
}

/* End of code generation (airspychannelize200.c) */
