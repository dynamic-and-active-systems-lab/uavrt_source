/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * udpsendercellforcoder.h
 *
 * Code generation for function 'udpsendercellforcoder'
 *
 */

#ifndef UDPSENDERCELLFORCODER_H
#define UDPSENDERCELLFORCODER_H

/* Include files */
#include "airspy_channelize_internal_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
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
    cell_10 *retUDPCell);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (udpsendercellforcoder.h) */
