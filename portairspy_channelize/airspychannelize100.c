/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * airspychannelize100.c
 *
 * Code generation for function 'airspychannelize100'
 *
 */

/* Include files */
#include "airspychannelize100.h"
#include "AsyncBuffer.h"
#include "SystemCore.h"
#include "airspy_channelize_emxutil.h"
#include "airspy_channelize_internal_types.h"
#include "airspy_channelize_types.h"
#include "datetime.h"
#include "handle.h"
#include "mod.h"
#include "pause.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "tic.h"
#include "toc.h"
#include "udpsendercellforcoder.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "time.h"
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

/* Function Declarations */
static void checkcommand(const signed char cmdReceived_data[],
                         const int cmdReceived_size[2],
                         char currentState_data[], int currentState_size[2]);

static double rt_roundd_snf(double u);

/* Function Definitions */
static void checkcommand(const signed char cmdReceived_data[],
                         const int cmdReceived_size[2],
                         char currentState_data[], int currentState_size[2])
{
  int i;
  /* This function is designed to check the incoming command and decide what to
   */
  /* do based on the received command and the current state */
  if ((cmdReceived_size[0] != 0) && (cmdReceived_size[1] != 0)) {
    int loop_ub;
    int x_size_idx_0;
    boolean_T x_data[1024];
    boolean_T exitg1;
    boolean_T y;
    x_size_idx_0 = cmdReceived_size[0];
    loop_ub = cmdReceived_size[0];
    for (i = 0; i < loop_ub; i++) {
      x_data[i] = (cmdReceived_data[i] == -1);
    }
    y = true;
    loop_ub = 0;
    exitg1 = false;
    while ((!exitg1) && (loop_ub <= x_size_idx_0 - 1)) {
      if (!x_data[loop_ub]) {
        y = false;
        exitg1 = true;
      } else {
        loop_ub++;
      }
    }
    if (y) {
      printf("Channelizer: Kill command received.\n");
      fflush(stdout);
      currentState_size[0] = 1;
      currentState_size[1] = 4;
      currentState_data[0] = 'k';
      currentState_data[1] = 'i';
      currentState_data[2] = 'l';
      currentState_data[3] = 'l';
    } else {
      x_size_idx_0 = cmdReceived_size[0];
      loop_ub = cmdReceived_size[0];
      for (i = 0; i < loop_ub; i++) {
        x_data[i] = (cmdReceived_data[i] == 0);
      }
      y = true;
      loop_ub = 0;
      exitg1 = false;
      while ((!exitg1) && (loop_ub <= x_size_idx_0 - 1)) {
        if (!x_data[loop_ub]) {
          y = false;
          exitg1 = true;
        } else {
          loop_ub++;
        }
      }
      if (y) {
        printf("Channelizer: Idle command received.\n");
        fflush(stdout);
        currentState_size[0] = 1;
        currentState_size[1] = 4;
        currentState_data[0] = 'i';
        currentState_data[1] = 'd';
        currentState_data[2] = 'l';
        currentState_data[3] = 'e';
      } else {
        x_size_idx_0 = cmdReceived_size[0];
        loop_ub = cmdReceived_size[0];
        for (i = 0; i < loop_ub; i++) {
          x_data[i] = (cmdReceived_data[i] == 1);
        }
        y = true;
        loop_ub = 0;
        exitg1 = false;
        while ((!exitg1) && (loop_ub <= x_size_idx_0 - 1)) {
          if (!x_data[loop_ub]) {
            y = false;
            exitg1 = true;
          } else {
            loop_ub++;
          }
        }
        if (y) {
          printf("Channelizer: Run command received.\n");
          fflush(stdout);
          currentState_size[0] = 1;
          currentState_size[1] = 3;
          currentState_data[0] = 'r';
          currentState_data[1] = 'u';
          currentState_data[2] = 'n';
        } else {
          /* Invalid command. Continue with current state. */
        }
      }
    }
  } else {
    /* Nothing received. Continue with current state. */
  }
}

static double rt_roundd_snf(double u)
{
  double y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }
  return y;
}

void airspychannelize100(double rawSampleRate)
{
  static dsp_AsyncBuffer dataBufferFIFO;
  static dspcodegen_UDPReceiver udpReceive;
  static creal32_T dataReceived_data[4096];
  b_dspcodegen_UDPReceiver udpCommand;
  b_dspcodegen_UDPSender lobj_10;
  b_dspcodegen_UDPSender lobj_100;
  b_dspcodegen_UDPSender lobj_101;
  b_dspcodegen_UDPSender lobj_102;
  b_dspcodegen_UDPSender lobj_103;
  b_dspcodegen_UDPSender lobj_104;
  b_dspcodegen_UDPSender lobj_105;
  b_dspcodegen_UDPSender lobj_106;
  b_dspcodegen_UDPSender lobj_107;
  b_dspcodegen_UDPSender lobj_108;
  b_dspcodegen_UDPSender lobj_109;
  b_dspcodegen_UDPSender lobj_11;
  b_dspcodegen_UDPSender lobj_110;
  b_dspcodegen_UDPSender lobj_111;
  b_dspcodegen_UDPSender lobj_112;
  b_dspcodegen_UDPSender lobj_113;
  b_dspcodegen_UDPSender lobj_114;
  b_dspcodegen_UDPSender lobj_115;
  b_dspcodegen_UDPSender lobj_116;
  b_dspcodegen_UDPSender lobj_117;
  b_dspcodegen_UDPSender lobj_118;
  b_dspcodegen_UDPSender lobj_119;
  b_dspcodegen_UDPSender lobj_12;
  b_dspcodegen_UDPSender lobj_120;
  b_dspcodegen_UDPSender lobj_121;
  b_dspcodegen_UDPSender lobj_122;
  b_dspcodegen_UDPSender lobj_123;
  b_dspcodegen_UDPSender lobj_124;
  b_dspcodegen_UDPSender lobj_125;
  b_dspcodegen_UDPSender lobj_126;
  b_dspcodegen_UDPSender lobj_127;
  b_dspcodegen_UDPSender lobj_128;
  b_dspcodegen_UDPSender lobj_129;
  b_dspcodegen_UDPSender lobj_13;
  b_dspcodegen_UDPSender lobj_130;
  b_dspcodegen_UDPSender lobj_131;
  b_dspcodegen_UDPSender lobj_132;
  b_dspcodegen_UDPSender lobj_133;
  b_dspcodegen_UDPSender lobj_134;
  b_dspcodegen_UDPSender lobj_135;
  b_dspcodegen_UDPSender lobj_136;
  b_dspcodegen_UDPSender lobj_137;
  b_dspcodegen_UDPSender lobj_138;
  b_dspcodegen_UDPSender lobj_139;
  b_dspcodegen_UDPSender lobj_14;
  b_dspcodegen_UDPSender lobj_140;
  b_dspcodegen_UDPSender lobj_141;
  b_dspcodegen_UDPSender lobj_142;
  b_dspcodegen_UDPSender lobj_143;
  b_dspcodegen_UDPSender lobj_144;
  b_dspcodegen_UDPSender lobj_145;
  b_dspcodegen_UDPSender lobj_146;
  b_dspcodegen_UDPSender lobj_147;
  b_dspcodegen_UDPSender lobj_148;
  b_dspcodegen_UDPSender lobj_149;
  b_dspcodegen_UDPSender lobj_15;
  b_dspcodegen_UDPSender lobj_150;
  b_dspcodegen_UDPSender lobj_151;
  b_dspcodegen_UDPSender lobj_152;
  b_dspcodegen_UDPSender lobj_153;
  b_dspcodegen_UDPSender lobj_154;
  b_dspcodegen_UDPSender lobj_155;
  b_dspcodegen_UDPSender lobj_156;
  b_dspcodegen_UDPSender lobj_157;
  b_dspcodegen_UDPSender lobj_158;
  b_dspcodegen_UDPSender lobj_159;
  b_dspcodegen_UDPSender lobj_16;
  b_dspcodegen_UDPSender lobj_17;
  b_dspcodegen_UDPSender lobj_18;
  b_dspcodegen_UDPSender lobj_19;
  b_dspcodegen_UDPSender lobj_20;
  b_dspcodegen_UDPSender lobj_21;
  b_dspcodegen_UDPSender lobj_22;
  b_dspcodegen_UDPSender lobj_23;
  b_dspcodegen_UDPSender lobj_24;
  b_dspcodegen_UDPSender lobj_25;
  b_dspcodegen_UDPSender lobj_26;
  b_dspcodegen_UDPSender lobj_27;
  b_dspcodegen_UDPSender lobj_28;
  b_dspcodegen_UDPSender lobj_29;
  b_dspcodegen_UDPSender lobj_30;
  b_dspcodegen_UDPSender lobj_31;
  b_dspcodegen_UDPSender lobj_32;
  b_dspcodegen_UDPSender lobj_33;
  b_dspcodegen_UDPSender lobj_34;
  b_dspcodegen_UDPSender lobj_35;
  b_dspcodegen_UDPSender lobj_36;
  b_dspcodegen_UDPSender lobj_37;
  b_dspcodegen_UDPSender lobj_38;
  b_dspcodegen_UDPSender lobj_39;
  b_dspcodegen_UDPSender lobj_4;
  b_dspcodegen_UDPSender lobj_40;
  b_dspcodegen_UDPSender lobj_41;
  b_dspcodegen_UDPSender lobj_42;
  b_dspcodegen_UDPSender lobj_43;
  b_dspcodegen_UDPSender lobj_44;
  b_dspcodegen_UDPSender lobj_45;
  b_dspcodegen_UDPSender lobj_46;
  b_dspcodegen_UDPSender lobj_47;
  b_dspcodegen_UDPSender lobj_48;
  b_dspcodegen_UDPSender lobj_49;
  b_dspcodegen_UDPSender lobj_5;
  b_dspcodegen_UDPSender lobj_50;
  b_dspcodegen_UDPSender lobj_51;
  b_dspcodegen_UDPSender lobj_52;
  b_dspcodegen_UDPSender lobj_53;
  b_dspcodegen_UDPSender lobj_54;
  b_dspcodegen_UDPSender lobj_55;
  b_dspcodegen_UDPSender lobj_56;
  b_dspcodegen_UDPSender lobj_57;
  b_dspcodegen_UDPSender lobj_58;
  b_dspcodegen_UDPSender lobj_59;
  b_dspcodegen_UDPSender lobj_6;
  b_dspcodegen_UDPSender lobj_60;
  b_dspcodegen_UDPSender lobj_61;
  b_dspcodegen_UDPSender lobj_62;
  b_dspcodegen_UDPSender lobj_63;
  b_dspcodegen_UDPSender lobj_64;
  b_dspcodegen_UDPSender lobj_65;
  b_dspcodegen_UDPSender lobj_66;
  b_dspcodegen_UDPSender lobj_67;
  b_dspcodegen_UDPSender lobj_68;
  b_dspcodegen_UDPSender lobj_69;
  b_dspcodegen_UDPSender lobj_7;
  b_dspcodegen_UDPSender lobj_70;
  b_dspcodegen_UDPSender lobj_71;
  b_dspcodegen_UDPSender lobj_72;
  b_dspcodegen_UDPSender lobj_73;
  b_dspcodegen_UDPSender lobj_74;
  b_dspcodegen_UDPSender lobj_75;
  b_dspcodegen_UDPSender lobj_76;
  b_dspcodegen_UDPSender lobj_77;
  b_dspcodegen_UDPSender lobj_78;
  b_dspcodegen_UDPSender lobj_79;
  b_dspcodegen_UDPSender lobj_8;
  b_dspcodegen_UDPSender lobj_80;
  b_dspcodegen_UDPSender lobj_81;
  b_dspcodegen_UDPSender lobj_82;
  b_dspcodegen_UDPSender lobj_83;
  b_dspcodegen_UDPSender lobj_84;
  b_dspcodegen_UDPSender lobj_85;
  b_dspcodegen_UDPSender lobj_86;
  b_dspcodegen_UDPSender lobj_87;
  b_dspcodegen_UDPSender lobj_88;
  b_dspcodegen_UDPSender lobj_89;
  b_dspcodegen_UDPSender lobj_9;
  b_dspcodegen_UDPSender lobj_90;
  b_dspcodegen_UDPSender lobj_91;
  b_dspcodegen_UDPSender lobj_92;
  b_dspcodegen_UDPSender lobj_93;
  b_dspcodegen_UDPSender lobj_94;
  b_dspcodegen_UDPSender lobj_95;
  b_dspcodegen_UDPSender lobj_96;
  b_dspcodegen_UDPSender lobj_97;
  b_dspcodegen_UDPSender lobj_98;
  b_dspcodegen_UDPSender lobj_99;
  cell_10 expl_temp;
  dsp_Channelizer channelizer;
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
  dspcodegen_UDPSender *udps_f1;
  dspcodegen_UDPSender *udps_f10;
  dspcodegen_UDPSender *udps_f100;
  dspcodegen_UDPSender *udps_f11;
  dspcodegen_UDPSender *udps_f12;
  dspcodegen_UDPSender *udps_f13;
  dspcodegen_UDPSender *udps_f14;
  dspcodegen_UDPSender *udps_f15;
  dspcodegen_UDPSender *udps_f16;
  dspcodegen_UDPSender *udps_f17;
  dspcodegen_UDPSender *udps_f18;
  dspcodegen_UDPSender *udps_f19;
  dspcodegen_UDPSender *udps_f2;
  dspcodegen_UDPSender *udps_f20;
  dspcodegen_UDPSender *udps_f21;
  dspcodegen_UDPSender *udps_f22;
  dspcodegen_UDPSender *udps_f23;
  dspcodegen_UDPSender *udps_f24;
  dspcodegen_UDPSender *udps_f25;
  dspcodegen_UDPSender *udps_f26;
  dspcodegen_UDPSender *udps_f27;
  dspcodegen_UDPSender *udps_f28;
  dspcodegen_UDPSender *udps_f29;
  dspcodegen_UDPSender *udps_f3;
  dspcodegen_UDPSender *udps_f30;
  dspcodegen_UDPSender *udps_f31;
  dspcodegen_UDPSender *udps_f32;
  dspcodegen_UDPSender *udps_f33;
  dspcodegen_UDPSender *udps_f34;
  dspcodegen_UDPSender *udps_f35;
  dspcodegen_UDPSender *udps_f36;
  dspcodegen_UDPSender *udps_f37;
  dspcodegen_UDPSender *udps_f38;
  dspcodegen_UDPSender *udps_f39;
  dspcodegen_UDPSender *udps_f4;
  dspcodegen_UDPSender *udps_f40;
  dspcodegen_UDPSender *udps_f41;
  dspcodegen_UDPSender *udps_f42;
  dspcodegen_UDPSender *udps_f43;
  dspcodegen_UDPSender *udps_f44;
  dspcodegen_UDPSender *udps_f45;
  dspcodegen_UDPSender *udps_f46;
  dspcodegen_UDPSender *udps_f47;
  dspcodegen_UDPSender *udps_f48;
  dspcodegen_UDPSender *udps_f49;
  dspcodegen_UDPSender *udps_f5;
  dspcodegen_UDPSender *udps_f50;
  dspcodegen_UDPSender *udps_f51;
  dspcodegen_UDPSender *udps_f52;
  dspcodegen_UDPSender *udps_f53;
  dspcodegen_UDPSender *udps_f54;
  dspcodegen_UDPSender *udps_f55;
  dspcodegen_UDPSender *udps_f56;
  dspcodegen_UDPSender *udps_f57;
  dspcodegen_UDPSender *udps_f58;
  dspcodegen_UDPSender *udps_f59;
  dspcodegen_UDPSender *udps_f6;
  dspcodegen_UDPSender *udps_f60;
  dspcodegen_UDPSender *udps_f61;
  dspcodegen_UDPSender *udps_f62;
  dspcodegen_UDPSender *udps_f63;
  dspcodegen_UDPSender *udps_f64;
  dspcodegen_UDPSender *udps_f65;
  dspcodegen_UDPSender *udps_f66;
  dspcodegen_UDPSender *udps_f67;
  dspcodegen_UDPSender *udps_f68;
  dspcodegen_UDPSender *udps_f69;
  dspcodegen_UDPSender *udps_f7;
  dspcodegen_UDPSender *udps_f70;
  dspcodegen_UDPSender *udps_f71;
  dspcodegen_UDPSender *udps_f72;
  dspcodegen_UDPSender *udps_f73;
  dspcodegen_UDPSender *udps_f74;
  dspcodegen_UDPSender *udps_f75;
  dspcodegen_UDPSender *udps_f76;
  dspcodegen_UDPSender *udps_f77;
  dspcodegen_UDPSender *udps_f78;
  dspcodegen_UDPSender *udps_f79;
  dspcodegen_UDPSender *udps_f8;
  dspcodegen_UDPSender *udps_f80;
  dspcodegen_UDPSender *udps_f81;
  dspcodegen_UDPSender *udps_f82;
  dspcodegen_UDPSender *udps_f83;
  dspcodegen_UDPSender *udps_f84;
  dspcodegen_UDPSender *udps_f85;
  dspcodegen_UDPSender *udps_f86;
  dspcodegen_UDPSender *udps_f87;
  dspcodegen_UDPSender *udps_f88;
  dspcodegen_UDPSender *udps_f89;
  dspcodegen_UDPSender *udps_f9;
  dspcodegen_UDPSender *udps_f90;
  dspcodegen_UDPSender *udps_f91;
  dspcodegen_UDPSender *udps_f92;
  dspcodegen_UDPSender *udps_f93;
  dspcodegen_UDPSender *udps_f94;
  dspcodegen_UDPSender *udps_f95;
  dspcodegen_UDPSender *udps_f96;
  dspcodegen_UDPSender *udps_f97;
  dspcodegen_UDPSender *udps_f98;
  dspcodegen_UDPSender *udps_f99;
  emxArray_creal32_T *varargin_1;
  emxArray_creal32_T *y;
  creal32_T *y_data;
  double expectedTimeBetweenFlushes;
  double loopStartToc;
  double outputSampleRate;
  double sampBasedElapsedTime;
  double startTimeStamp;
  double tocBasedElapseTime;
  double tocStart;
  double writeTime;
  unsigned long sampsTransmitted;
  unsigned long totalSampsReceived;
  int state_size[2];
  int b_index;
  signed char cmdReceived_data[1024];
  char state_data[4];
  char state_tmp_data[4];
  boolean_T clearBufferFlag;
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
  /* AIRSPYFHCHANNELIZE100 receives complex (IQ) data over a UDP connection from
   */
  /* an SDR (single precision), channelizes it, and servers it  */
  /* up over 100 diferent UDP ports. */
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
  /* [912 768 456 384 256 192]*1000; */
  outputSampleRate = rawSampleRate / 100.0;
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
  /* %Based nextpow2(2*bytesPerBufferAtFlush)  %2^18,...%2^16 = 65536, 2^18 */
  /* %1024,...%128 on a Mac and 2048 on Linux */
  b_SystemCore_setup(&udpReceive);
  /*  SETUP UDP OUTPUT OBJECTS */
  printf("Channelizer: Setting up output channel UDP ports...\n");
  fflush(stdout);
  /*  Must be a multiple of 128 */
  /* Adding 1 for the time stamp items on the front of each message.  */
  dataBufferFIFO.pBuffer.NumChannels = -1;
  dataBufferFIFO.pBuffer.isInitialized = 0;
  dataBufferFIFO.pBuffer.matlabCodegenIsDeleted = false;
  dataBufferFIFO.matlabCodegenIsDeleted = false;
  expectedTimeBetweenFlushes = 102400.0 / rawSampleRate;
  AsyncBuffer_write(&dataBufferFIFO);
  /* Write a single value so the number of channels is specified for coder.
   * Specify complex single for airspy data */
  AsyncBuffer_read(&dataBufferFIFO);
  /* Read out that single sample to empty the buffer. */
  udpsendercellforcoder(
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
  udps_f2 = expl_temp.f2;
  udps_f3 = expl_temp.f3;
  udps_f4 = expl_temp.f4;
  udps_f5 = expl_temp.f5;
  udps_f6 = expl_temp.f6;
  udps_f7 = expl_temp.f7;
  udps_f8 = expl_temp.f8;
  udps_f9 = expl_temp.f9;
  udps_f10 = expl_temp.f10;
  udps_f11 = expl_temp.f11;
  udps_f12 = expl_temp.f12;
  udps_f13 = expl_temp.f13;
  udps_f14 = expl_temp.f14;
  udps_f15 = expl_temp.f15;
  udps_f16 = expl_temp.f16;
  udps_f17 = expl_temp.f17;
  udps_f18 = expl_temp.f18;
  udps_f19 = expl_temp.f19;
  udps_f20 = expl_temp.f20;
  udps_f21 = expl_temp.f21;
  udps_f22 = expl_temp.f22;
  udps_f23 = expl_temp.f23;
  udps_f24 = expl_temp.f24;
  udps_f25 = expl_temp.f25;
  udps_f26 = expl_temp.f26;
  udps_f27 = expl_temp.f27;
  udps_f28 = expl_temp.f28;
  udps_f29 = expl_temp.f29;
  udps_f30 = expl_temp.f30;
  udps_f31 = expl_temp.f31;
  udps_f32 = expl_temp.f32;
  udps_f33 = expl_temp.f33;
  udps_f34 = expl_temp.f34;
  udps_f35 = expl_temp.f35;
  udps_f36 = expl_temp.f36;
  udps_f37 = expl_temp.f37;
  udps_f38 = expl_temp.f38;
  udps_f39 = expl_temp.f39;
  udps_f40 = expl_temp.f40;
  udps_f41 = expl_temp.f41;
  udps_f42 = expl_temp.f42;
  udps_f43 = expl_temp.f43;
  udps_f44 = expl_temp.f44;
  udps_f45 = expl_temp.f45;
  udps_f46 = expl_temp.f46;
  udps_f47 = expl_temp.f47;
  udps_f48 = expl_temp.f48;
  udps_f49 = expl_temp.f49;
  udps_f50 = expl_temp.f50;
  udps_f51 = expl_temp.f51;
  udps_f52 = expl_temp.f52;
  udps_f53 = expl_temp.f53;
  udps_f54 = expl_temp.f54;
  udps_f55 = expl_temp.f55;
  udps_f56 = expl_temp.f56;
  udps_f57 = expl_temp.f57;
  udps_f58 = expl_temp.f58;
  udps_f59 = expl_temp.f59;
  udps_f60 = expl_temp.f60;
  udps_f61 = expl_temp.f61;
  udps_f62 = expl_temp.f62;
  udps_f63 = expl_temp.f63;
  udps_f64 = expl_temp.f64;
  udps_f65 = expl_temp.f65;
  udps_f66 = expl_temp.f66;
  udps_f67 = expl_temp.f67;
  udps_f68 = expl_temp.f68;
  udps_f69 = expl_temp.f69;
  udps_f70 = expl_temp.f70;
  udps_f71 = expl_temp.f71;
  udps_f72 = expl_temp.f72;
  udps_f73 = expl_temp.f73;
  udps_f74 = expl_temp.f74;
  udps_f75 = expl_temp.f75;
  udps_f76 = expl_temp.f76;
  udps_f77 = expl_temp.f77;
  udps_f78 = expl_temp.f78;
  udps_f79 = expl_temp.f79;
  udps_f80 = expl_temp.f80;
  udps_f81 = expl_temp.f81;
  udps_f82 = expl_temp.f82;
  udps_f83 = expl_temp.f83;
  udps_f84 = expl_temp.f84;
  udps_f85 = expl_temp.f85;
  udps_f86 = expl_temp.f86;
  udps_f87 = expl_temp.f87;
  udps_f88 = expl_temp.f88;
  udps_f89 = expl_temp.f89;
  udps_f90 = expl_temp.f90;
  udps_f91 = expl_temp.f91;
  udps_f92 = expl_temp.f92;
  udps_f93 = expl_temp.f93;
  udps_f94 = expl_temp.f94;
  udps_f95 = expl_temp.f95;
  udps_f96 = expl_temp.f96;
  udps_f97 = expl_temp.f97;
  udps_f98 = expl_temp.f98;
  udps_f99 = expl_temp.f99;
  udps_f100 = expl_temp.f100;
  channelizer.numChannels = -1;
  channelizer.isInitialized = 0;
  channelizer.matlabCodegenIsDeleted = false;
  totalSampsReceived = 0UL;
  sampsTransmitted = 0UL;
  /* Make initial call to udps. First call is very slow and can cause missed */
  /* samples if left within the while loop */
  SystemCore_step(expl_temp.f1);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f2);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f3);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f4);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f5);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f6);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f7);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f8);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f9);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f10);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f11);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f12);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f13);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f14);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f15);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f16);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f17);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f18);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f19);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f20);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f21);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f22);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f23);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f24);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f25);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f26);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f27);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f28);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f29);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f30);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f31);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f32);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f33);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f34);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f35);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f36);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f37);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f38);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f39);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f40);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f41);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f42);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f43);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f44);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f45);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f46);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f47);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f48);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f49);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f50);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f51);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f52);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f53);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f54);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f55);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f56);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f57);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f58);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f59);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f60);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f61);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f62);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f63);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f64);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f65);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f66);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f67);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f68);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f69);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f70);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f71);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f72);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f73);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f74);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f75);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f76);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f77);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f78);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f79);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f80);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f81);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f82);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f83);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f84);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f85);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f86);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f87);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f88);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f89);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f90);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f91);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f92);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f93);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f94);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f95);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f96);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f97);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f98);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f99);
  /* Add one for blank time stamp */
  SystemCore_step(expl_temp.f100);
  /* Add one for blank time stamp */
  state_tmp_data[0] = 'r';
  state_tmp_data[1] = 'u';
  state_tmp_data[2] = 'n';
  state_size[0] = 1;
  state_size[1] = 3;
  for (b_index = 0; b_index < 3; b_index++) {
    state_data[b_index] = state_tmp_data[b_index];
  }
  printf("Channelizer: Setup complete. Awaiting commands ###...\n");
  fflush(stdout);
  writeTime = 0.0;
  tocStart = 0.0;
  startTimeStamp = 0.0;
  clearBufferFlag = true;
  tocBasedElapseTime = 0.0;
  sampBasedElapsedTime = 0.0;
  tic();
  loopStartToc = toc();
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
      double previousToc;
      double timeDiff;
      unsigned long qY;
      int dataReceived_size[2];
      if (clearBufferFlag) {
        printf("Resetting data buffer\n");
        fflush(stdout);
        b_SystemCore_step(&udpReceive, dataReceived_data, dataReceived_size);
        while ((dataReceived_size[0] != 0) && (dataReceived_size[1] != 0)) {
          printf("********CLEARING UDP DATA BUFFER*********\n");
          fflush(stdout);
          b_SystemCore_step(&udpReceive, dataReceived_data, dataReceived_size);
        }
        totalSampsReceived = 0UL;
        sampsTransmitted = 0UL;
        clearBufferFlag = false;
      }
      /* Read the data buffer until empty */
      b_SystemCore_step(&udpReceive, dataReceived_data, dataReceived_size);
      while ((dataReceived_size[0] != 0) && (dataReceived_size[1] != 0)) {
        if (totalSampsReceived == 0UL) {
          creal_T this_data;
          previousToc =
              (double)(unsigned long)dataReceived_size[0] / rawSampleRate;
          this_data = datetime_datetime();
          startTimeStamp = this_data.re / 1000.0 - previousToc;
          tocStart = toc() - previousToc;
        }
        qY = totalSampsReceived + dataReceived_size[0];
        if (qY < totalSampsReceived) {
          qY = MAX_uint64_T;
        }
        totalSampsReceived = qY;
        sampBasedElapsedTime = (double)qY / rawSampleRate;
        tocBasedElapseTime = toc() - tocStart;
        previousToc = toc();
        b_AsyncBuffer_write(&dataBufferFIFO, dataReceived_data,
                            dataReceived_size[0]);
        /* Call with (:) to help coder realize it is a single channel */
        writeTime = (writeTime + toc()) - previousToc;
        b_SystemCore_step(&udpReceive, dataReceived_data, dataReceived_size);
      }
      /*             %% Reset if a big time offset developes */
      timeDiff = tocBasedElapseTime - sampBasedElapsedTime;
      /* fprintf('Current diff b/t toc and samp time: %f s \n', timeDiff) */
      if (fabs(timeDiff) > 0.1) {
        if (dataBufferFIFO.pBuffer.isInitialized == 1) {
          dataBufferFIFO.pBuffer.ReadPointer = 1;
          dataBufferFIFO.pBuffer.WritePointer = 2;
          dataBufferFIFO.pBuffer.CumulativeOverrun = 0;
          dataBufferFIFO.pBuffer.CumulativeUnderrun = 0;
          memset(&dataBufferFIFO.pBuffer.Cache[0], 0,
                 204801U * sizeof(creal32_T));
        }
        clearBufferFlag = true;
      }
      /*   */
      /*                  if resetTimeStampFlag */
      /*                      fprintf('Resetting start time \n') */
      /*                      startTimeStamp = posixtime(datetime('now')) -
       * timeDurOfPacket; */
      /*                      tocStart       = toc - timeDurOfPacket; */
      /*                      frameIndex     = 1;  */
      /*                      resetTimeStampFlag = false; */
      /*                  end */
      /*   */
      /*                  %fprintf('%d, ',int32(sampsReceived)) */
      /*   */
      /*                  %Check for delayed or paused incoming data and reset
       * start */
      /*                  %times if delay is detected */
      /*                  sampBasedElapsedTime = double(totalSampsReceived) * 1
       * / rawSampleRate; */
      /*                  tocBasedElapseTime   = toc - tocStart; */
      /*   */
      /*                  tocSampTimeDiff = tocBasedElapseTime -
       * sampBasedElapsedTime; */
      /*  fprintf('Current diff b/t toc and samp time: %f s
       * \n',tocBasedElapseTime - sampBasedElapsedTime) */
      /*                  %fprintf('%f \n',tocBasedElapseTime -
       * sampBasedElapsedTime) */
      /*                  if abs(tocSampTimeDiff) > 0.1 %20 ms */
      /*                      fprintf('************************************\n')
       */
      /*                      fprintf('Major deviation from sample time and
       * system clock time detected. Resetting data buffer and start time.\n')
       */
      /*                      fprintf('************************************\n')
       */
      /*                      dataBufferFIFO.reset(); %Will dump data and avoid
       * the flush step below */
      /*                      clearBufferFlag    = true; */
      /*                      resetTimeStampFlag = true; */
      /*                      dataReceived = udpReceive(); */
      /*   */
      /*                      while ~isempty(dataReceived) */
      /*                          fprintf('********CLEARING UDP DATA
       * BUFFER*********\n'); */
      /*                          dataReceivedHold = dataReceived; */
      /*                          [dataReceived]  = udpReceive(); */
      /*                      end */
      /*                      pause(1) */
      /*                  else */
      /*  Used to keep a running estimated of the expected frame */
      /* size to help identifiy subsize frames received. */
      /* if sampsReceived < expectedFrameSize */
      /*     disp('Subpacket received') */
      /* end */
      /* if sampsReceived~=expectedFrameSize */
      /*     expectedFrameSize = round(mean([sampsReceived,
       * expectedFrameSize])); */
      /* end */
      /*  previousToc = toc; */
      /*                      write(dataBufferFIFO, dataReceived(:));%Call with
       * (:) to help coder realize it is a single channel */
      /*                      writeTime = writeTime + toc - previousToc; */
      /*                      frameIndex = frameIndex+1; */
      /* end */
      /*                 %% Process the data buffer */
      int exitg2;
      do {
        int b_qY;
        exitg2 = 0;
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
        if (dataBufferFIFO.pBuffer.ReadPointer < -2147278847) {
          b_qY = MAX_int32_T;
        } else {
          b_qY = 204800 - dataBufferFIFO.pBuffer.ReadPointer;
        }
        if ((b_qY < 0) &&
            (dataBufferFIFO.pBuffer.WritePointer < MIN_int32_T - b_qY)) {
          b_qY = MIN_int32_T;
        } else if ((b_qY > 0) &&
                   (dataBufferFIFO.pBuffer.WritePointer > MAX_int32_T - b_qY)) {
          b_qY = MAX_int32_T;
        } else {
          b_qY += dataBufferFIFO.pBuffer.WritePointer;
        }
        if (dataBufferFIFO.pBuffer.ReadPointer <
            dataBufferFIFO.pBuffer.WritePointer) {
          b_qY = b_index;
        } else if (dataBufferFIFO.pBuffer.ReadPointer ==
                   dataBufferFIFO.pBuffer.WritePointer) {
          b_qY = 204800;
        }
        if (b_qY >= 102400) {
          creal32_T bufferTimeStamp4Sending_data[1025];
          double channelizeTime;
          double sendTime;
          double validatedHoleFilling_idx_0;
          float b_y;
          float c_y;
          unsigned int u;
          unsigned int u1;
          printf("\n");
          fflush(stdout);
          /* fprintf('Current diff b/t toc and samp time: %f s
           * \n',tocBasedElapseTime - sampBasedElapsedTime) */
          validatedHoleFilling_idx_0 = writeTime;
          writeTime = 0.0;
          /* fprintf('Channelizer: Running - Buffer filled with %u samples.
           * Flushing to channels. Currently receiving: %i samples per
           * packet.\n',uint32(samplesAtFlush),int32(expectedFrameSize)) */
          printf("Channelizer: Running - Buffer filled with %u samples. "
                 "Flushing to channels.\n",
                 102400U);
          fflush(stdout);
          /* fprintf('Actual time between buffer flushes: %6.6f.  Expected:
           * %6.6f. \n', toc, expectedTimeBetweenFlushes) */
          previousToc = toc();
          b_AsyncBuffer_read(&dataBufferFIFO, varargin_1);
          c_SystemCore_step(&channelizer, varargin_1, y);
          y_data = y->data;
          channelizeTime = toc() - previousToc;
          /* time2Channelize = toc; */
          /* bufferTimeStamp = round(10^3*(startTimeStamp +
           * double(sampsTransmitted) * 1 / outputSampleRate)); */
          /* bufferTimeStamp4Sending = int2singlecomplex(bufferTimeStamp); */
          /* fprintf('bufferTimeStamp4Sending: %f + i %f
           * \n',real(bufferTimeStamp4Sending),imag(bufferTimeStamp4Sending)) */
          printf("Current diff b/t toc and samp time: %f s \n", timeDiff);
          fflush(stdout);
          previousToc =
              startTimeStamp + (double)sampsTransmitted / outputSampleRate;
          sendTime = floor(previousToc);
          if (sendTime < 4.294967296E+9) {
            if (sendTime >= 0.0) {
              u = (unsigned int)sendTime;
            } else {
              u = 0U;
            }
          } else if (sendTime >= 4.294967296E+9) {
            u = MAX_uint32_T;
          } else {
            u = 0U;
          }
          sendTime = rt_roundd_snf(b_mod(previousToc) * 1.0E+9);
          if (sendTime < 4.294967296E+9) {
            if (sendTime >= 0.0) {
              u1 = (unsigned int)sendTime;
            } else {
              u1 = 0U;
            }
          } else if (sendTime >= 4.294967296E+9) {
            u1 = MAX_uint32_T;
          } else {
            u1 = 0U;
          }
          memcpy((void *)&b_y, (void *)&u,
                 (unsigned int)((size_t)1 * sizeof(float)));
          memcpy((void *)&c_y, (void *)&u1,
                 (unsigned int)((size_t)1 * sizeof(float)));
          printf("bufferTimeStamp4Sending: %u + i %u \n", u, u1);
          fflush(stdout);
          qY = sampsTransmitted + 1024UL;
          if (sampsTransmitted + 1024UL < sampsTransmitted) {
            qY = MAX_uint64_T;
          }
          sampsTransmitted = qY;
          /* sampsTransmittedComplex = int2singlecomplex(sampsTransmitted); */
          printf("sampsTransmitted (uint64): %lu \n", qY);
          fflush(stdout);
          /* fprintf('sampsTransmitted (as single complex): %f + i%f
           * \n',real(sampsTransmittedComplex),imag(sampsTransmittedComplex)) */
          previousToc = toc();
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index];
          }
          e_SystemCore_step(udps_f1, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 1024];
          }
          e_SystemCore_step(udps_f2, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 2048];
          }
          e_SystemCore_step(udps_f3, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 3072];
          }
          e_SystemCore_step(udps_f4, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 4096];
          }
          e_SystemCore_step(udps_f5, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 5120];
          }
          e_SystemCore_step(udps_f6, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 6144];
          }
          e_SystemCore_step(udps_f7, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 7168];
          }
          e_SystemCore_step(udps_f8, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 8192];
          }
          e_SystemCore_step(udps_f9, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 9216];
          }
          e_SystemCore_step(udps_f10, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 10240];
          }
          e_SystemCore_step(udps_f11, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 11264];
          }
          e_SystemCore_step(udps_f12, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 12288];
          }
          e_SystemCore_step(udps_f13, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 13312];
          }
          e_SystemCore_step(udps_f14, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 14336];
          }
          e_SystemCore_step(udps_f15, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 15360];
          }
          e_SystemCore_step(udps_f16, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 16384];
          }
          e_SystemCore_step(udps_f17, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 17408];
          }
          e_SystemCore_step(udps_f18, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 18432];
          }
          e_SystemCore_step(udps_f19, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 19456];
          }
          e_SystemCore_step(udps_f20, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 20480];
          }
          e_SystemCore_step(udps_f21, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 21504];
          }
          e_SystemCore_step(udps_f22, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 22528];
          }
          e_SystemCore_step(udps_f23, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 23552];
          }
          e_SystemCore_step(udps_f24, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 24576];
          }
          e_SystemCore_step(udps_f25, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 25600];
          }
          e_SystemCore_step(udps_f26, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 26624];
          }
          e_SystemCore_step(udps_f27, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 27648];
          }
          e_SystemCore_step(udps_f28, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 28672];
          }
          e_SystemCore_step(udps_f29, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 29696];
          }
          e_SystemCore_step(udps_f30, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 30720];
          }
          e_SystemCore_step(udps_f31, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 31744];
          }
          e_SystemCore_step(udps_f32, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 32768];
          }
          e_SystemCore_step(udps_f33, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 33792];
          }
          e_SystemCore_step(udps_f34, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 34816];
          }
          e_SystemCore_step(udps_f35, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 35840];
          }
          e_SystemCore_step(udps_f36, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 36864];
          }
          e_SystemCore_step(udps_f37, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 37888];
          }
          e_SystemCore_step(udps_f38, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 38912];
          }
          e_SystemCore_step(udps_f39, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 39936];
          }
          e_SystemCore_step(udps_f40, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 40960];
          }
          e_SystemCore_step(udps_f41, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 41984];
          }
          e_SystemCore_step(udps_f42, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 43008];
          }
          e_SystemCore_step(udps_f43, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 44032];
          }
          e_SystemCore_step(udps_f44, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 45056];
          }
          e_SystemCore_step(udps_f45, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 46080];
          }
          e_SystemCore_step(udps_f46, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 47104];
          }
          e_SystemCore_step(udps_f47, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 48128];
          }
          e_SystemCore_step(udps_f48, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 49152];
          }
          e_SystemCore_step(udps_f49, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 50176];
          }
          e_SystemCore_step(udps_f50, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 51200];
          }
          e_SystemCore_step(udps_f51, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 52224];
          }
          e_SystemCore_step(udps_f52, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 53248];
          }
          e_SystemCore_step(udps_f53, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 54272];
          }
          e_SystemCore_step(udps_f54, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 55296];
          }
          e_SystemCore_step(udps_f55, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 56320];
          }
          e_SystemCore_step(udps_f56, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 57344];
          }
          e_SystemCore_step(udps_f57, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 58368];
          }
          e_SystemCore_step(udps_f58, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 59392];
          }
          e_SystemCore_step(udps_f59, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 60416];
          }
          e_SystemCore_step(udps_f60, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 61440];
          }
          e_SystemCore_step(udps_f61, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 62464];
          }
          e_SystemCore_step(udps_f62, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 63488];
          }
          e_SystemCore_step(udps_f63, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 64512];
          }
          e_SystemCore_step(udps_f64, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 65536];
          }
          e_SystemCore_step(udps_f65, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 66560];
          }
          e_SystemCore_step(udps_f66, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 67584];
          }
          e_SystemCore_step(udps_f67, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 68608];
          }
          e_SystemCore_step(udps_f68, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 69632];
          }
          e_SystemCore_step(udps_f69, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 70656];
          }
          e_SystemCore_step(udps_f70, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 71680];
          }
          e_SystemCore_step(udps_f71, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 72704];
          }
          e_SystemCore_step(udps_f72, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 73728];
          }
          e_SystemCore_step(udps_f73, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 74752];
          }
          e_SystemCore_step(udps_f74, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 75776];
          }
          e_SystemCore_step(udps_f75, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 76800];
          }
          e_SystemCore_step(udps_f76, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 77824];
          }
          e_SystemCore_step(udps_f77, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 78848];
          }
          e_SystemCore_step(udps_f78, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 79872];
          }
          e_SystemCore_step(udps_f79, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 80896];
          }
          e_SystemCore_step(udps_f80, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 81920];
          }
          e_SystemCore_step(udps_f81, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 82944];
          }
          e_SystemCore_step(udps_f82, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 83968];
          }
          e_SystemCore_step(udps_f83, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 84992];
          }
          e_SystemCore_step(udps_f84, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 86016];
          }
          e_SystemCore_step(udps_f85, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 87040];
          }
          e_SystemCore_step(udps_f86, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 88064];
          }
          e_SystemCore_step(udps_f87, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 89088];
          }
          e_SystemCore_step(udps_f88, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 90112];
          }
          e_SystemCore_step(udps_f89, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 91136];
          }
          e_SystemCore_step(udps_f90, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 92160];
          }
          e_SystemCore_step(udps_f91, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 93184];
          }
          e_SystemCore_step(udps_f92, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 94208];
          }
          e_SystemCore_step(udps_f93, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 95232];
          }
          e_SystemCore_step(udps_f94, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 96256];
          }
          e_SystemCore_step(udps_f95, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 97280];
          }
          e_SystemCore_step(udps_f96, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 98304];
          }
          e_SystemCore_step(udps_f97, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] = y_data[b_index + 99328];
          }
          e_SystemCore_step(udps_f98, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] =
                y_data[b_index + 100352];
          }
          e_SystemCore_step(udps_f99, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          /* data = [y(:,1); sampsTransmittedComplex ]; */
          bufferTimeStamp4Sending_data[0].re = b_y;
          bufferTimeStamp4Sending_data[0].im = c_y;
          for (b_index = 0; b_index < 1024; b_index++) {
            bufferTimeStamp4Sending_data[b_index + 1] =
                y_data[b_index + 101376];
          }
          e_SystemCore_step(udps_f100, bufferTimeStamp4Sending_data);
          /* udps{i}(y(:,i)) */
          sendTime = toc() - previousToc;
          /* time2Send = toc - time2Channelize; */
          /* fprintf('Time required to read buffer and channelize: %6.6f \n',
           * time2Channelize) */
          /* fprintf('Time required to send: %6.6f \n', time2Send) */
          previousToc = toc() - loopStartToc;
          printf(
              "Actual time between buffer flushes: %6.6f.  Expected: %6.6f. \n",
              previousToc, expectedTimeBetweenFlushes);
          fflush(stdout);
          printf("Writing to Buffer Time: %6.6f. \n",
                 validatedHoleFilling_idx_0);
          fflush(stdout);
          printf("Buffer Read and Channelize Time: %6.6f. \n", channelizeTime);
          fflush(stdout);
          printf("Sending via UDP Time: %6.6f. \n", sendTime);
          fflush(stdout);
          printf("Total Processing Time: %6.6f. \n", channelizeTime + sendTime);
          fflush(stdout);
          printf("Total Samples Transmitted Samples: %lu. \n", qY);
          fflush(stdout);
          /* Buffer just filled, so give it time to refill minus */
          /* the processing time we currently need */
          loopStartToc = toc();
          /* pause(expectedTimeBetweenFlushes - 4 * readAndProcessingTime); */
          /* pausedTime = toc; */
        } else {
          exitg2 = 1;
        }
      } while (exitg2 == 0);
      /* else */
      /* tic */
      /*  if isdeployed */
      /*      coder.ceval('usleep',uint32(rawFrameTime * 1e6)); */
      /*      %fprintf('Pausing \n') */
      /*  else */
      /*      pause(rawFrameTime);   */
      /*      %fprintf('Pausing \n') */
      /*  end */
      /* pause(rawFrameTime) */
      /* pause(expectedTimeBetweenFlushes) */
      /* fprintf('***********Notice: I just paused for %6.6f \n',toc) */
      /* fprintf('***********Notice: I just paused for \n',toc) */
      /* end */
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
               204801U * sizeof(creal32_T));
      }
      printf("Channelizer: Idle. Waiting for command...\n");
      fflush(stdout);
      pause();
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
  AsyncBuffer_release(&dataBufferFIFO);
  b_SystemCore_release(&udpReceive);
  SystemCore_release(&udpCommand);
  d_handle_matlabCodegenDestructo(&lobj_259);
  d_handle_matlabCodegenDestructo(&lobj_258);
  d_handle_matlabCodegenDestructo(&lobj_257);
  d_handle_matlabCodegenDestructo(&lobj_256);
  d_handle_matlabCodegenDestructo(&lobj_255);
  d_handle_matlabCodegenDestructo(&lobj_254);
  d_handle_matlabCodegenDestructo(&lobj_253);
  d_handle_matlabCodegenDestructo(&lobj_252);
  d_handle_matlabCodegenDestructo(&lobj_251);
  d_handle_matlabCodegenDestructo(&lobj_250);
  d_handle_matlabCodegenDestructo(&lobj_249);
  d_handle_matlabCodegenDestructo(&lobj_248);
  d_handle_matlabCodegenDestructo(&lobj_247);
  d_handle_matlabCodegenDestructo(&lobj_246);
  d_handle_matlabCodegenDestructo(&lobj_245);
  d_handle_matlabCodegenDestructo(&lobj_244);
  d_handle_matlabCodegenDestructo(&lobj_243);
  d_handle_matlabCodegenDestructo(&lobj_242);
  d_handle_matlabCodegenDestructo(&lobj_241);
  d_handle_matlabCodegenDestructo(&lobj_240);
  d_handle_matlabCodegenDestructo(&lobj_239);
  d_handle_matlabCodegenDestructo(&lobj_238);
  d_handle_matlabCodegenDestructo(&lobj_237);
  d_handle_matlabCodegenDestructo(&lobj_236);
  d_handle_matlabCodegenDestructo(&lobj_235);
  d_handle_matlabCodegenDestructo(&lobj_234);
  d_handle_matlabCodegenDestructo(&lobj_233);
  d_handle_matlabCodegenDestructo(&lobj_232);
  d_handle_matlabCodegenDestructo(&lobj_231);
  d_handle_matlabCodegenDestructo(&lobj_230);
  d_handle_matlabCodegenDestructo(&lobj_229);
  d_handle_matlabCodegenDestructo(&lobj_228);
  d_handle_matlabCodegenDestructo(&lobj_227);
  d_handle_matlabCodegenDestructo(&lobj_226);
  d_handle_matlabCodegenDestructo(&lobj_225);
  d_handle_matlabCodegenDestructo(&lobj_224);
  d_handle_matlabCodegenDestructo(&lobj_223);
  d_handle_matlabCodegenDestructo(&lobj_222);
  d_handle_matlabCodegenDestructo(&lobj_221);
  d_handle_matlabCodegenDestructo(&lobj_220);
  d_handle_matlabCodegenDestructo(&lobj_219);
  d_handle_matlabCodegenDestructo(&lobj_218);
  d_handle_matlabCodegenDestructo(&lobj_217);
  d_handle_matlabCodegenDestructo(&lobj_216);
  d_handle_matlabCodegenDestructo(&lobj_215);
  d_handle_matlabCodegenDestructo(&lobj_214);
  d_handle_matlabCodegenDestructo(&lobj_213);
  d_handle_matlabCodegenDestructo(&lobj_212);
  d_handle_matlabCodegenDestructo(&lobj_211);
  d_handle_matlabCodegenDestructo(&lobj_210);
  d_handle_matlabCodegenDestructo(&lobj_209);
  d_handle_matlabCodegenDestructo(&lobj_208);
  d_handle_matlabCodegenDestructo(&lobj_207);
  d_handle_matlabCodegenDestructo(&lobj_206);
  d_handle_matlabCodegenDestructo(&lobj_205);
  d_handle_matlabCodegenDestructo(&lobj_204);
  d_handle_matlabCodegenDestructo(&lobj_203);
  d_handle_matlabCodegenDestructo(&lobj_202);
  d_handle_matlabCodegenDestructo(&lobj_201);
  d_handle_matlabCodegenDestructo(&lobj_200);
  d_handle_matlabCodegenDestructo(&lobj_199);
  d_handle_matlabCodegenDestructo(&lobj_198);
  d_handle_matlabCodegenDestructo(&lobj_197);
  d_handle_matlabCodegenDestructo(&lobj_196);
  d_handle_matlabCodegenDestructo(&lobj_195);
  d_handle_matlabCodegenDestructo(&lobj_194);
  d_handle_matlabCodegenDestructo(&lobj_193);
  d_handle_matlabCodegenDestructo(&lobj_192);
  d_handle_matlabCodegenDestructo(&lobj_191);
  d_handle_matlabCodegenDestructo(&lobj_190);
  d_handle_matlabCodegenDestructo(&lobj_189);
  d_handle_matlabCodegenDestructo(&lobj_188);
  d_handle_matlabCodegenDestructo(&lobj_187);
  d_handle_matlabCodegenDestructo(&lobj_186);
  d_handle_matlabCodegenDestructo(&lobj_185);
  d_handle_matlabCodegenDestructo(&lobj_184);
  d_handle_matlabCodegenDestructo(&lobj_183);
  d_handle_matlabCodegenDestructo(&lobj_182);
  d_handle_matlabCodegenDestructo(&lobj_181);
  d_handle_matlabCodegenDestructo(&lobj_180);
  d_handle_matlabCodegenDestructo(&lobj_179);
  d_handle_matlabCodegenDestructo(&lobj_178);
  d_handle_matlabCodegenDestructo(&lobj_177);
  d_handle_matlabCodegenDestructo(&lobj_176);
  d_handle_matlabCodegenDestructo(&lobj_175);
  d_handle_matlabCodegenDestructo(&lobj_174);
  d_handle_matlabCodegenDestructo(&lobj_173);
  d_handle_matlabCodegenDestructo(&lobj_172);
  d_handle_matlabCodegenDestructo(&lobj_171);
  d_handle_matlabCodegenDestructo(&lobj_170);
  d_handle_matlabCodegenDestructo(&lobj_169);
  d_handle_matlabCodegenDestructo(&lobj_168);
  d_handle_matlabCodegenDestructo(&lobj_167);
  d_handle_matlabCodegenDestructo(&lobj_166);
  d_handle_matlabCodegenDestructo(&lobj_165);
  d_handle_matlabCodegenDestructo(&lobj_164);
  d_handle_matlabCodegenDestructo(&lobj_163);
  d_handle_matlabCodegenDestructo(&lobj_162);
  d_handle_matlabCodegenDestructo(&lobj_161);
  d_handle_matlabCodegenDestructo(&lobj_160);
  if (!lobj_159.matlabCodegenIsDeleted) {
    lobj_159.matlabCodegenIsDeleted = true;
    if (lobj_159.isInitialized == 1) {
      lobj_159.isInitialized = 2;
    }
  }
  if (!lobj_158.matlabCodegenIsDeleted) {
    lobj_158.matlabCodegenIsDeleted = true;
    if (lobj_158.isInitialized == 1) {
      lobj_158.isInitialized = 2;
    }
  }
  if (!lobj_157.matlabCodegenIsDeleted) {
    lobj_157.matlabCodegenIsDeleted = true;
    if (lobj_157.isInitialized == 1) {
      lobj_157.isInitialized = 2;
    }
  }
  if (!lobj_156.matlabCodegenIsDeleted) {
    lobj_156.matlabCodegenIsDeleted = true;
    if (lobj_156.isInitialized == 1) {
      lobj_156.isInitialized = 2;
    }
  }
  if (!lobj_155.matlabCodegenIsDeleted) {
    lobj_155.matlabCodegenIsDeleted = true;
    if (lobj_155.isInitialized == 1) {
      lobj_155.isInitialized = 2;
    }
  }
  if (!lobj_154.matlabCodegenIsDeleted) {
    lobj_154.matlabCodegenIsDeleted = true;
    if (lobj_154.isInitialized == 1) {
      lobj_154.isInitialized = 2;
    }
  }
  if (!lobj_153.matlabCodegenIsDeleted) {
    lobj_153.matlabCodegenIsDeleted = true;
    if (lobj_153.isInitialized == 1) {
      lobj_153.isInitialized = 2;
    }
  }
  if (!lobj_152.matlabCodegenIsDeleted) {
    lobj_152.matlabCodegenIsDeleted = true;
    if (lobj_152.isInitialized == 1) {
      lobj_152.isInitialized = 2;
    }
  }
  if (!lobj_151.matlabCodegenIsDeleted) {
    lobj_151.matlabCodegenIsDeleted = true;
    if (lobj_151.isInitialized == 1) {
      lobj_151.isInitialized = 2;
    }
  }
  if (!lobj_150.matlabCodegenIsDeleted) {
    lobj_150.matlabCodegenIsDeleted = true;
    if (lobj_150.isInitialized == 1) {
      lobj_150.isInitialized = 2;
    }
  }
  if (!lobj_149.matlabCodegenIsDeleted) {
    lobj_149.matlabCodegenIsDeleted = true;
    if (lobj_149.isInitialized == 1) {
      lobj_149.isInitialized = 2;
    }
  }
  if (!lobj_148.matlabCodegenIsDeleted) {
    lobj_148.matlabCodegenIsDeleted = true;
    if (lobj_148.isInitialized == 1) {
      lobj_148.isInitialized = 2;
    }
  }
  if (!lobj_147.matlabCodegenIsDeleted) {
    lobj_147.matlabCodegenIsDeleted = true;
    if (lobj_147.isInitialized == 1) {
      lobj_147.isInitialized = 2;
    }
  }
  if (!lobj_146.matlabCodegenIsDeleted) {
    lobj_146.matlabCodegenIsDeleted = true;
    if (lobj_146.isInitialized == 1) {
      lobj_146.isInitialized = 2;
    }
  }
  if (!lobj_145.matlabCodegenIsDeleted) {
    lobj_145.matlabCodegenIsDeleted = true;
    if (lobj_145.isInitialized == 1) {
      lobj_145.isInitialized = 2;
    }
  }
  if (!lobj_144.matlabCodegenIsDeleted) {
    lobj_144.matlabCodegenIsDeleted = true;
    if (lobj_144.isInitialized == 1) {
      lobj_144.isInitialized = 2;
    }
  }
  if (!lobj_143.matlabCodegenIsDeleted) {
    lobj_143.matlabCodegenIsDeleted = true;
    if (lobj_143.isInitialized == 1) {
      lobj_143.isInitialized = 2;
    }
  }
  if (!lobj_142.matlabCodegenIsDeleted) {
    lobj_142.matlabCodegenIsDeleted = true;
    if (lobj_142.isInitialized == 1) {
      lobj_142.isInitialized = 2;
    }
  }
  if (!lobj_141.matlabCodegenIsDeleted) {
    lobj_141.matlabCodegenIsDeleted = true;
    if (lobj_141.isInitialized == 1) {
      lobj_141.isInitialized = 2;
    }
  }
  if (!lobj_140.matlabCodegenIsDeleted) {
    lobj_140.matlabCodegenIsDeleted = true;
    if (lobj_140.isInitialized == 1) {
      lobj_140.isInitialized = 2;
    }
  }
  if (!lobj_139.matlabCodegenIsDeleted) {
    lobj_139.matlabCodegenIsDeleted = true;
    if (lobj_139.isInitialized == 1) {
      lobj_139.isInitialized = 2;
    }
  }
  if (!lobj_138.matlabCodegenIsDeleted) {
    lobj_138.matlabCodegenIsDeleted = true;
    if (lobj_138.isInitialized == 1) {
      lobj_138.isInitialized = 2;
    }
  }
  if (!lobj_137.matlabCodegenIsDeleted) {
    lobj_137.matlabCodegenIsDeleted = true;
    if (lobj_137.isInitialized == 1) {
      lobj_137.isInitialized = 2;
    }
  }
  if (!lobj_136.matlabCodegenIsDeleted) {
    lobj_136.matlabCodegenIsDeleted = true;
    if (lobj_136.isInitialized == 1) {
      lobj_136.isInitialized = 2;
    }
  }
  if (!lobj_135.matlabCodegenIsDeleted) {
    lobj_135.matlabCodegenIsDeleted = true;
    if (lobj_135.isInitialized == 1) {
      lobj_135.isInitialized = 2;
    }
  }
  if (!lobj_134.matlabCodegenIsDeleted) {
    lobj_134.matlabCodegenIsDeleted = true;
    if (lobj_134.isInitialized == 1) {
      lobj_134.isInitialized = 2;
    }
  }
  if (!lobj_133.matlabCodegenIsDeleted) {
    lobj_133.matlabCodegenIsDeleted = true;
    if (lobj_133.isInitialized == 1) {
      lobj_133.isInitialized = 2;
    }
  }
  if (!lobj_132.matlabCodegenIsDeleted) {
    lobj_132.matlabCodegenIsDeleted = true;
    if (lobj_132.isInitialized == 1) {
      lobj_132.isInitialized = 2;
    }
  }
  if (!lobj_131.matlabCodegenIsDeleted) {
    lobj_131.matlabCodegenIsDeleted = true;
    if (lobj_131.isInitialized == 1) {
      lobj_131.isInitialized = 2;
    }
  }
  if (!lobj_130.matlabCodegenIsDeleted) {
    lobj_130.matlabCodegenIsDeleted = true;
    if (lobj_130.isInitialized == 1) {
      lobj_130.isInitialized = 2;
    }
  }
  if (!lobj_129.matlabCodegenIsDeleted) {
    lobj_129.matlabCodegenIsDeleted = true;
    if (lobj_129.isInitialized == 1) {
      lobj_129.isInitialized = 2;
    }
  }
  if (!lobj_128.matlabCodegenIsDeleted) {
    lobj_128.matlabCodegenIsDeleted = true;
    if (lobj_128.isInitialized == 1) {
      lobj_128.isInitialized = 2;
    }
  }
  if (!lobj_127.matlabCodegenIsDeleted) {
    lobj_127.matlabCodegenIsDeleted = true;
    if (lobj_127.isInitialized == 1) {
      lobj_127.isInitialized = 2;
    }
  }
  if (!lobj_126.matlabCodegenIsDeleted) {
    lobj_126.matlabCodegenIsDeleted = true;
    if (lobj_126.isInitialized == 1) {
      lobj_126.isInitialized = 2;
    }
  }
  if (!lobj_125.matlabCodegenIsDeleted) {
    lobj_125.matlabCodegenIsDeleted = true;
    if (lobj_125.isInitialized == 1) {
      lobj_125.isInitialized = 2;
    }
  }
  if (!lobj_124.matlabCodegenIsDeleted) {
    lobj_124.matlabCodegenIsDeleted = true;
    if (lobj_124.isInitialized == 1) {
      lobj_124.isInitialized = 2;
    }
  }
  if (!lobj_123.matlabCodegenIsDeleted) {
    lobj_123.matlabCodegenIsDeleted = true;
    if (lobj_123.isInitialized == 1) {
      lobj_123.isInitialized = 2;
    }
  }
  if (!lobj_122.matlabCodegenIsDeleted) {
    lobj_122.matlabCodegenIsDeleted = true;
    if (lobj_122.isInitialized == 1) {
      lobj_122.isInitialized = 2;
    }
  }
  if (!lobj_121.matlabCodegenIsDeleted) {
    lobj_121.matlabCodegenIsDeleted = true;
    if (lobj_121.isInitialized == 1) {
      lobj_121.isInitialized = 2;
    }
  }
  if (!lobj_120.matlabCodegenIsDeleted) {
    lobj_120.matlabCodegenIsDeleted = true;
    if (lobj_120.isInitialized == 1) {
      lobj_120.isInitialized = 2;
    }
  }
  if (!lobj_119.matlabCodegenIsDeleted) {
    lobj_119.matlabCodegenIsDeleted = true;
    if (lobj_119.isInitialized == 1) {
      lobj_119.isInitialized = 2;
    }
  }
  if (!lobj_118.matlabCodegenIsDeleted) {
    lobj_118.matlabCodegenIsDeleted = true;
    if (lobj_118.isInitialized == 1) {
      lobj_118.isInitialized = 2;
    }
  }
  if (!lobj_117.matlabCodegenIsDeleted) {
    lobj_117.matlabCodegenIsDeleted = true;
    if (lobj_117.isInitialized == 1) {
      lobj_117.isInitialized = 2;
    }
  }
  if (!lobj_116.matlabCodegenIsDeleted) {
    lobj_116.matlabCodegenIsDeleted = true;
    if (lobj_116.isInitialized == 1) {
      lobj_116.isInitialized = 2;
    }
  }
  if (!lobj_115.matlabCodegenIsDeleted) {
    lobj_115.matlabCodegenIsDeleted = true;
    if (lobj_115.isInitialized == 1) {
      lobj_115.isInitialized = 2;
    }
  }
  if (!lobj_114.matlabCodegenIsDeleted) {
    lobj_114.matlabCodegenIsDeleted = true;
    if (lobj_114.isInitialized == 1) {
      lobj_114.isInitialized = 2;
    }
  }
  if (!lobj_113.matlabCodegenIsDeleted) {
    lobj_113.matlabCodegenIsDeleted = true;
    if (lobj_113.isInitialized == 1) {
      lobj_113.isInitialized = 2;
    }
  }
  if (!lobj_112.matlabCodegenIsDeleted) {
    lobj_112.matlabCodegenIsDeleted = true;
    if (lobj_112.isInitialized == 1) {
      lobj_112.isInitialized = 2;
    }
  }
  if (!lobj_111.matlabCodegenIsDeleted) {
    lobj_111.matlabCodegenIsDeleted = true;
    if (lobj_111.isInitialized == 1) {
      lobj_111.isInitialized = 2;
    }
  }
  if (!lobj_110.matlabCodegenIsDeleted) {
    lobj_110.matlabCodegenIsDeleted = true;
    if (lobj_110.isInitialized == 1) {
      lobj_110.isInitialized = 2;
    }
  }
  if (!lobj_109.matlabCodegenIsDeleted) {
    lobj_109.matlabCodegenIsDeleted = true;
    if (lobj_109.isInitialized == 1) {
      lobj_109.isInitialized = 2;
    }
  }
  if (!lobj_108.matlabCodegenIsDeleted) {
    lobj_108.matlabCodegenIsDeleted = true;
    if (lobj_108.isInitialized == 1) {
      lobj_108.isInitialized = 2;
    }
  }
  if (!lobj_107.matlabCodegenIsDeleted) {
    lobj_107.matlabCodegenIsDeleted = true;
    if (lobj_107.isInitialized == 1) {
      lobj_107.isInitialized = 2;
    }
  }
  if (!lobj_106.matlabCodegenIsDeleted) {
    lobj_106.matlabCodegenIsDeleted = true;
    if (lobj_106.isInitialized == 1) {
      lobj_106.isInitialized = 2;
    }
  }
  if (!lobj_105.matlabCodegenIsDeleted) {
    lobj_105.matlabCodegenIsDeleted = true;
    if (lobj_105.isInitialized == 1) {
      lobj_105.isInitialized = 2;
    }
  }
  if (!lobj_104.matlabCodegenIsDeleted) {
    lobj_104.matlabCodegenIsDeleted = true;
    if (lobj_104.isInitialized == 1) {
      lobj_104.isInitialized = 2;
    }
  }
  if (!lobj_103.matlabCodegenIsDeleted) {
    lobj_103.matlabCodegenIsDeleted = true;
    if (lobj_103.isInitialized == 1) {
      lobj_103.isInitialized = 2;
    }
  }
  if (!lobj_102.matlabCodegenIsDeleted) {
    lobj_102.matlabCodegenIsDeleted = true;
    if (lobj_102.isInitialized == 1) {
      lobj_102.isInitialized = 2;
    }
  }
  if (!lobj_101.matlabCodegenIsDeleted) {
    lobj_101.matlabCodegenIsDeleted = true;
    if (lobj_101.isInitialized == 1) {
      lobj_101.isInitialized = 2;
    }
  }
  if (!lobj_100.matlabCodegenIsDeleted) {
    lobj_100.matlabCodegenIsDeleted = true;
    if (lobj_100.isInitialized == 1) {
      lobj_100.isInitialized = 2;
    }
  }
  if (!lobj_99.matlabCodegenIsDeleted) {
    lobj_99.matlabCodegenIsDeleted = true;
    if (lobj_99.isInitialized == 1) {
      lobj_99.isInitialized = 2;
    }
  }
  if (!lobj_98.matlabCodegenIsDeleted) {
    lobj_98.matlabCodegenIsDeleted = true;
    if (lobj_98.isInitialized == 1) {
      lobj_98.isInitialized = 2;
    }
  }
  if (!lobj_97.matlabCodegenIsDeleted) {
    lobj_97.matlabCodegenIsDeleted = true;
    if (lobj_97.isInitialized == 1) {
      lobj_97.isInitialized = 2;
    }
  }
  if (!lobj_96.matlabCodegenIsDeleted) {
    lobj_96.matlabCodegenIsDeleted = true;
    if (lobj_96.isInitialized == 1) {
      lobj_96.isInitialized = 2;
    }
  }
  if (!lobj_95.matlabCodegenIsDeleted) {
    lobj_95.matlabCodegenIsDeleted = true;
    if (lobj_95.isInitialized == 1) {
      lobj_95.isInitialized = 2;
    }
  }
  if (!lobj_94.matlabCodegenIsDeleted) {
    lobj_94.matlabCodegenIsDeleted = true;
    if (lobj_94.isInitialized == 1) {
      lobj_94.isInitialized = 2;
    }
  }
  if (!lobj_93.matlabCodegenIsDeleted) {
    lobj_93.matlabCodegenIsDeleted = true;
    if (lobj_93.isInitialized == 1) {
      lobj_93.isInitialized = 2;
    }
  }
  if (!lobj_92.matlabCodegenIsDeleted) {
    lobj_92.matlabCodegenIsDeleted = true;
    if (lobj_92.isInitialized == 1) {
      lobj_92.isInitialized = 2;
    }
  }
  if (!lobj_91.matlabCodegenIsDeleted) {
    lobj_91.matlabCodegenIsDeleted = true;
    if (lobj_91.isInitialized == 1) {
      lobj_91.isInitialized = 2;
    }
  }
  if (!lobj_90.matlabCodegenIsDeleted) {
    lobj_90.matlabCodegenIsDeleted = true;
    if (lobj_90.isInitialized == 1) {
      lobj_90.isInitialized = 2;
    }
  }
  if (!lobj_89.matlabCodegenIsDeleted) {
    lobj_89.matlabCodegenIsDeleted = true;
    if (lobj_89.isInitialized == 1) {
      lobj_89.isInitialized = 2;
    }
  }
  if (!lobj_88.matlabCodegenIsDeleted) {
    lobj_88.matlabCodegenIsDeleted = true;
    if (lobj_88.isInitialized == 1) {
      lobj_88.isInitialized = 2;
    }
  }
  if (!lobj_87.matlabCodegenIsDeleted) {
    lobj_87.matlabCodegenIsDeleted = true;
    if (lobj_87.isInitialized == 1) {
      lobj_87.isInitialized = 2;
    }
  }
  if (!lobj_86.matlabCodegenIsDeleted) {
    lobj_86.matlabCodegenIsDeleted = true;
    if (lobj_86.isInitialized == 1) {
      lobj_86.isInitialized = 2;
    }
  }
  if (!lobj_85.matlabCodegenIsDeleted) {
    lobj_85.matlabCodegenIsDeleted = true;
    if (lobj_85.isInitialized == 1) {
      lobj_85.isInitialized = 2;
    }
  }
  if (!lobj_84.matlabCodegenIsDeleted) {
    lobj_84.matlabCodegenIsDeleted = true;
    if (lobj_84.isInitialized == 1) {
      lobj_84.isInitialized = 2;
    }
  }
  if (!lobj_83.matlabCodegenIsDeleted) {
    lobj_83.matlabCodegenIsDeleted = true;
    if (lobj_83.isInitialized == 1) {
      lobj_83.isInitialized = 2;
    }
  }
  if (!lobj_82.matlabCodegenIsDeleted) {
    lobj_82.matlabCodegenIsDeleted = true;
    if (lobj_82.isInitialized == 1) {
      lobj_82.isInitialized = 2;
    }
  }
  if (!lobj_81.matlabCodegenIsDeleted) {
    lobj_81.matlabCodegenIsDeleted = true;
    if (lobj_81.isInitialized == 1) {
      lobj_81.isInitialized = 2;
    }
  }
  if (!lobj_80.matlabCodegenIsDeleted) {
    lobj_80.matlabCodegenIsDeleted = true;
    if (lobj_80.isInitialized == 1) {
      lobj_80.isInitialized = 2;
    }
  }
  if (!lobj_79.matlabCodegenIsDeleted) {
    lobj_79.matlabCodegenIsDeleted = true;
    if (lobj_79.isInitialized == 1) {
      lobj_79.isInitialized = 2;
    }
  }
  if (!lobj_78.matlabCodegenIsDeleted) {
    lobj_78.matlabCodegenIsDeleted = true;
    if (lobj_78.isInitialized == 1) {
      lobj_78.isInitialized = 2;
    }
  }
  if (!lobj_77.matlabCodegenIsDeleted) {
    lobj_77.matlabCodegenIsDeleted = true;
    if (lobj_77.isInitialized == 1) {
      lobj_77.isInitialized = 2;
    }
  }
  if (!lobj_76.matlabCodegenIsDeleted) {
    lobj_76.matlabCodegenIsDeleted = true;
    if (lobj_76.isInitialized == 1) {
      lobj_76.isInitialized = 2;
    }
  }
  if (!lobj_75.matlabCodegenIsDeleted) {
    lobj_75.matlabCodegenIsDeleted = true;
    if (lobj_75.isInitialized == 1) {
      lobj_75.isInitialized = 2;
    }
  }
  if (!lobj_74.matlabCodegenIsDeleted) {
    lobj_74.matlabCodegenIsDeleted = true;
    if (lobj_74.isInitialized == 1) {
      lobj_74.isInitialized = 2;
    }
  }
  if (!lobj_73.matlabCodegenIsDeleted) {
    lobj_73.matlabCodegenIsDeleted = true;
    if (lobj_73.isInitialized == 1) {
      lobj_73.isInitialized = 2;
    }
  }
  if (!lobj_72.matlabCodegenIsDeleted) {
    lobj_72.matlabCodegenIsDeleted = true;
    if (lobj_72.isInitialized == 1) {
      lobj_72.isInitialized = 2;
    }
  }
  if (!lobj_71.matlabCodegenIsDeleted) {
    lobj_71.matlabCodegenIsDeleted = true;
    if (lobj_71.isInitialized == 1) {
      lobj_71.isInitialized = 2;
    }
  }
  if (!lobj_70.matlabCodegenIsDeleted) {
    lobj_70.matlabCodegenIsDeleted = true;
    if (lobj_70.isInitialized == 1) {
      lobj_70.isInitialized = 2;
    }
  }
  if (!lobj_69.matlabCodegenIsDeleted) {
    lobj_69.matlabCodegenIsDeleted = true;
    if (lobj_69.isInitialized == 1) {
      lobj_69.isInitialized = 2;
    }
  }
  if (!lobj_68.matlabCodegenIsDeleted) {
    lobj_68.matlabCodegenIsDeleted = true;
    if (lobj_68.isInitialized == 1) {
      lobj_68.isInitialized = 2;
    }
  }
  if (!lobj_67.matlabCodegenIsDeleted) {
    lobj_67.matlabCodegenIsDeleted = true;
    if (lobj_67.isInitialized == 1) {
      lobj_67.isInitialized = 2;
    }
  }
  if (!lobj_66.matlabCodegenIsDeleted) {
    lobj_66.matlabCodegenIsDeleted = true;
    if (lobj_66.isInitialized == 1) {
      lobj_66.isInitialized = 2;
    }
  }
  if (!lobj_65.matlabCodegenIsDeleted) {
    lobj_65.matlabCodegenIsDeleted = true;
    if (lobj_65.isInitialized == 1) {
      lobj_65.isInitialized = 2;
    }
  }
  if (!lobj_64.matlabCodegenIsDeleted) {
    lobj_64.matlabCodegenIsDeleted = true;
    if (lobj_64.isInitialized == 1) {
      lobj_64.isInitialized = 2;
    }
  }
  if (!lobj_63.matlabCodegenIsDeleted) {
    lobj_63.matlabCodegenIsDeleted = true;
    if (lobj_63.isInitialized == 1) {
      lobj_63.isInitialized = 2;
    }
  }
  if (!lobj_62.matlabCodegenIsDeleted) {
    lobj_62.matlabCodegenIsDeleted = true;
    if (lobj_62.isInitialized == 1) {
      lobj_62.isInitialized = 2;
    }
  }
  if (!lobj_61.matlabCodegenIsDeleted) {
    lobj_61.matlabCodegenIsDeleted = true;
    if (lobj_61.isInitialized == 1) {
      lobj_61.isInitialized = 2;
    }
  }
  if (!lobj_60.matlabCodegenIsDeleted) {
    lobj_60.matlabCodegenIsDeleted = true;
    if (lobj_60.isInitialized == 1) {
      lobj_60.isInitialized = 2;
    }
  }
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
  c_handle_matlabCodegenDestructo(&dataBufferFIFO.pBuffer);
  b_handle_matlabCodegenDestructo(&udpReceive);
  handle_matlabCodegenDestructor(&udpCommand);
}

/* End of code generation (airspychannelize100.c) */
