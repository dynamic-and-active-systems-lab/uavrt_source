//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// uavrt_detection_data.cpp
//
// Code generation for function 'uavrt_detection_data'
//

// Include files
#include "uavrt_detection_data.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"

// Variable Definitions
unsigned int method;

unsigned int state[2];

unsigned int b_method;

unsigned int b_state;

unsigned int c_state[2];

unsigned int d_state[625];

double freq;

bool freq_not_empty;

coder::dspcodegen::UDPReceiver udpRx;

bool udpRx_not_empty;

coder::dspcodegen::b_UDPReceiver b_udpRx;

bool b_udpRx_not_empty;

rtRunTimeErrorInfo emlrtRTEI{
    24,      // lineNo
    9,       // colNo
    "error", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/lang/error.m" // pName
};

rtRunTimeErrorInfo b_emlrtRTEI{
    1,                  // lineNo
    1,                  // colNo
    "SystemCore/reset", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/shared/system/coder/+matlab/"
    "+system/+coder/SystemCore.p" // pName
};

rtRunTimeErrorInfo c_emlrtRTEI{
    86,            // lineNo
    5,             // colNo
    "getFileStar", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/iofun/fseek.m" // pName
};

rtRunTimeErrorInfo d_emlrtRTEI{
    24,     // lineNo
    13,     // colNo
    "feof", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/iofun/feof.m" // pName
};

rtRunTimeErrorInfo j_emlrtRTEI{
    15,                      // lineNo
    9,                       // colNo
    "assertSupportedString", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/"
    "assertSupportedString.m" // pName
};

rtRunTimeErrorInfo k_emlrtRTEI{
    158,               // lineNo
    31,                // colNo
    "expandOrReshape", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/"
    "validator_check_size.m" // pName
};

rtRunTimeErrorInfo m_emlrtRTEI{
    74,                  // lineNo
    13,                  // colNo
    "reshapeSizeChecks", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" // pName
};

rtRunTimeErrorInfo n_emlrtRTEI{
    81,                  // lineNo
    23,                  // colNo
    "reshapeSizeChecks", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" // pName
};

rtRunTimeErrorInfo o_emlrtRTEI{
    64,                   // lineNo
    15,                   // colNo
    "assertValidSizeArg", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/"
    "assertValidSizeArg.m" // pName
};

rtRunTimeErrorInfo r_emlrtRTEI{
    419,               // lineNo
    15,                // colNo
    "assert_pmaxsize", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/ops/colon.m" // pName
};

rtRunTimeErrorInfo t_emlrtRTEI{
    14,                    // lineNo
    37,                    // colNo
    "validatenonnegative", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatenonnegative.m" // pName
};

rtRunTimeErrorInfo u_emlrtRTEI{
    473,                                         // lineNo
    13,                                          // colNo
    "AsyncBuffercgHelper/ReadSamplesFromBuffer", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/dsp/dsp/+dsp/+internal/"
    "AsyncBuffercgHelper.m" // pName
};

rtEqualityCheckInfo b_emlrtECI{
    -1,                                          // nDims
    462,                                         // lineNo
    17,                                          // colNo
    "AsyncBuffercgHelper/ReadSamplesFromBuffer", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/dsp/dsp/+dsp/+internal/"
    "AsyncBuffercgHelper.m" // pName
};

rtBoundsCheckInfo c_emlrtBCI{
    -1,                                          // iFirst
    -1,                                          // iLast
    462,                                         // lineNo
    50,                                          // colNo
    "",                                          // aName
    "AsyncBuffercgHelper/ReadSamplesFromBuffer", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/dsp/dsp/+dsp/+internal/"
    "AsyncBuffercgHelper.m", // pName
    0                        // checkKind
};

rtBoundsCheckInfo d_emlrtBCI{
    -1,                                          // iFirst
    -1,                                          // iLast
    462,                                         // lineNo
    21,                                          // colNo
    "",                                          // aName
    "AsyncBuffercgHelper/ReadSamplesFromBuffer", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/dsp/dsp/+dsp/+internal/"
    "AsyncBuffercgHelper.m", // pName
    0                        // checkKind
};

rtDoubleCheckInfo emlrtDCI{
    463,                                         // lineNo
    27,                                          // colNo
    "AsyncBuffercgHelper/ReadSamplesFromBuffer", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/dsp/dsp/+dsp/+internal/"
    "AsyncBuffercgHelper.m", // pName
    4                        // checkKind
};

rtRunTimeErrorInfo v_emlrtRTEI{
    324,                        // lineNo
    13,                         // colNo
    "AsyncBuffercgHelper/read", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/dsp/dsp/+dsp/+internal/"
    "AsyncBuffercgHelper.m" // pName
};

rtRunTimeErrorInfo x_emlrtRTEI{
    53,       // lineNo
    15,       // colNo
    "bsxfun", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/bsxfun.m" // pName
};

rtRunTimeErrorInfo y_emlrtRTEI{
    13,                 // lineNo
    37,                 // colNo
    "validatenonempty", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatenonempty.m" // pName
};

rtRunTimeErrorInfo ab_emlrtRTEI{
    14,               // lineNo
    37,               // colNo
    "validatenonnan", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatenonnan.m" // pName
};

rtRunTimeErrorInfo bb_emlrtRTEI{
    14,               // lineNo
    37,               // colNo
    "validatefinite", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validatefinite.m" // pName
};

rtBoundsCheckInfo n_emlrtBCI{
    -1,           // iFirst
    -1,           // iLast
    16,           // lineNo
    13,           // colNo
    "",           // aName
    "centerfreq", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/+signal/+internal/"
    "+spectral/centerfreq.m", // pName
    0                         // checkKind
};

rtDoubleCheckInfo j_emlrtDCI{
    16,           // lineNo
    13,           // colNo
    "centerfreq", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/+signal/+internal/"
    "+spectral/centerfreq.m", // pName
    1                         // checkKind
};

rtBoundsCheckInfo o_emlrtBCI{
    -1,           // iFirst
    -1,           // iLast
    13,           // lineNo
    13,           // colNo
    "",           // aName
    "centerfreq", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/+signal/+internal/"
    "+spectral/centerfreq.m", // pName
    0                         // checkKind
};

rtDoubleCheckInfo k_emlrtDCI{
    13,           // lineNo
    13,           // colNo
    "centerfreq", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/signal/signal/+signal/+internal/"
    "+spectral/centerfreq.m", // pName
    1                         // checkKind
};

rtRunTimeErrorInfo db_emlrtRTEI{
    13,                // lineNo
    37,                // colNo
    "validateinteger", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/+valattr/"
    "validateinteger.m" // pName
};

rtDoubleCheckInfo l_emlrtDCI{
    799,                                            // lineNo
    45,                                             // colNo
    "FFTImplementationCallback/make_twiddle_table", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/shared/coder/coder/lib/+coder/"
    "+internal/FFTImplementationCallback.m", // pName
    4                                        // checkKind
};

rtDoubleCheckInfo m_emlrtDCI{
    774,                                              // lineNo
    47,                                               // colNo
    "FFTImplementationCallback/make_1q_cosine_table", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/shared/coder/coder/lib/+coder/"
    "+internal/FFTImplementationCallback.m", // pName
    4                                        // checkKind
};

rtDoubleCheckInfo o_emlrtDCI{
    33,                     // lineNo
    28,                     // colNo
    "bluestein_setup_impl", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/"
    "bluesteinSetup.m", // pName
    4                   // checkKind
};

rtRunTimeErrorInfo jb_emlrtRTEI{
    13,               // lineNo
    13,               // colNo
    "toLogicalCheck", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/"
    "toLogicalCheck.m" // pName
};

rtDoubleCheckInfo p_emlrtDCI{
    31,       // lineNo
    14,       // colNo
    "repmat", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/repmat.m", // pName
    4 // checkKind
};

rtRunTimeErrorInfo lb_emlrtRTEI{
    58,                   // lineNo
    23,                   // colNo
    "assertValidSizeArg", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/"
    "assertValidSizeArg.m" // pName
};

rtRunTimeErrorInfo mb_emlrtRTEI{
    13,                     // lineNo
    27,                     // colNo
    "assertCompatibleDims", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/shared/coder/coder/lib/+coder/"
    "+internal/assertCompatibleDims.m" // pName
};

rtRunTimeErrorInfo nb_emlrtRTEI{
    159,                    // lineNo
    13,                     // colNo
    "coderTimeCheckStatus", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/shared/coder/coder/lib/+coder/"
    "+internal/+time/CoderTimeAPI.m" // pName
};

rtRunTimeErrorInfo ob_emlrtRTEI{
    1,                 // lineNo
    1,                 // colNo
    "SystemCore/step", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/shared/system/coder/+matlab/"
    "+system/+coder/SystemCore.p" // pName
};

rtRunTimeErrorInfo pb_emlrtRTEI{
    1,                  // lineNo
    1,                  // colNo
    "SystemCore/setup", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/shared/system/coder/+matlab/"
    "+system/+coder/SystemCore.p" // pName
};

rtRunTimeErrorInfo rb_emlrtRTEI{
    288,                   // lineNo
    27,                    // colNo
    "check_non_axis_size", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/cat.m" // pName
};

rtRunTimeErrorInfo vb_emlrtRTEI{
    79,                  // lineNo
    23,                  // colNo
    "reshapeSizeChecks", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" // pName
};

rtRunTimeErrorInfo yb_emlrtRTEI{
    13,     // lineNo
    9,      // colNo
    "sqrt", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elfun/sqrt.m" // pName
};

rtRunTimeErrorInfo bc_emlrtRTEI{
    134,             // lineNo
    27,              // colNo
    "unaryMinOrMax", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/"
    "unaryMinOrMax.m" // pName
};

rtRunTimeErrorInfo ec_emlrtRTEI{
    133,                   // lineNo
    23,                    // colNo
    "dynamic_size_checks", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/ops/"
    "eml_mtimes_helper.m" // pName
};

rtRunTimeErrorInfo fc_emlrtRTEI{
    138,                   // lineNo
    23,                    // colNo
    "dynamic_size_checks", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/ops/"
    "eml_mtimes_helper.m" // pName
};

rtRunTimeErrorInfo gc_emlrtRTEI{
    42,            // lineNo
    19,            // colNo
    "eml_sub2ind", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/sub2ind.m" // pName
};

rtRunTimeErrorInfo hc_emlrtRTEI{
    32,            // lineNo
    23,            // colNo
    "eml_sub2ind", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/sub2ind.m" // pName
};

rtDoubleCheckInfo t_emlrtDCI{
    1501,                  // lineNo
    44,                    // colNo
    "sparse/nullcopyLike", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/shared/coder/coder/+coder/"
    "+internal/@sparse/sparse.m", // pName
    4                             // checkKind
};

rtRunTimeErrorInfo ic_emlrtRTEI{
    40,                   // lineNo
    15,                   // colNo
    "ind2sub_indexClass", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/ind2sub.m" // pName
};

rtRunTimeErrorInfo jc_emlrtRTEI{
    12,                                   // lineNo
    27,                                   // colNo
    "sparse/sparse_validateNumericIndex", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/shared/coder/coder/+coder/"
    "+internal/@sparse/private/validateNumericIndex.m" // pName
};

rtRunTimeErrorInfo kc_emlrtRTEI{
    1632,              // lineNo
    31,                // colNo
    "assertValidSize", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/shared/coder/coder/+coder/"
    "+internal/@sparse/sparse.m" // pName
};

rtRunTimeErrorInfo nc_emlrtRTEI{
    11,                                   // lineNo
    27,                                   // colNo
    "sparse/sparse_validateNumericIndex", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/shared/coder/coder/+coder/"
    "+internal/@sparse/private/validateNumericIndex.m" // pName
};

rtRunTimeErrorInfo
    qc_emlrtRTEI{
        38,          // lineNo
        48,          // colNo
        "circshift", // fName
        "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/elmat/"
        "circshift.m" // pName
    };

rtRunTimeErrorInfo rc_emlrtRTEI{
    57,               // lineNo
    27,               // colNo
    "assertValidDim", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/shared/coder/coder/lib/+coder/"
    "+internal/assertValidDim.m" // pName
};

const char cv[12]{'u', 'p', 'd', 'a', 't', 'e', 'c', 'o', 'n', 'f', 'i', 'g'};

const bool bv[128]{
    false, false, false, false, false, false, false, false, false, true,  true,
    true,  true,  true,  false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, true,  true,  true,  true,  true,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false};

const char cv1[128]{
    '\x00', '\x01', '\x02', '\x03', '\x04', '\x05', '\x06', '\a',   '\b',
    '\t',   '\n',   '\v',   '\f',   '\r',   '\x0e', '\x0f', '\x10', '\x11',
    '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19', '\x1a',
    '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ',    '!',    '\"',   '#',
    '$',    '%',    '&',    '\'',   '(',    ')',    '*',    '+',    ',',
    '-',    '.',    '/',    '0',    '1',    '2',    '3',    '4',    '5',
    '6',    '7',    '8',    '9',    ':',    ';',    '<',    '=',    '>',
    '?',    '@',    'a',    'b',    'c',    'd',    'e',    'f',    'g',
    'h',    'i',    'j',    'k',    'l',    'm',    'n',    'o',    'p',
    'q',    'r',    's',    't',    'u',    'v',    'w',    'x',    'y',
    'z',    '[',    '\\',   ']',    '^',    '_',    '`',    'a',    'b',
    'c',    'd',    'e',    'f',    'g',    'h',    'i',    'j',    'k',
    'l',    'm',    'n',    'o',    'p',    'q',    'r',    's',    't',
    'u',    'v',    'w',    'x',    'y',    'z',    '{',    '|',    '}',
    '~',    '\x7f'};

const char cv2[22]{'c', 'o', 'd', 'e', 'r', 'I', 'n', 'i', 't', 'T', 'i',
                   'm', 'e', 'F', 'u', 'n', 'c', 't', 'i', 'o', 'n', 's'};

const char cv3[30]{'c', 'o', 'd', 'e', 'r', 'T', 'i', 'm', 'e', 'C',
                   'l', 'o', 'c', 'k', 'G', 'e', 't', 't', 'i', 'm',
                   'e', 'M', 'o', 'n', 'o', 't', 'o', 'n', 'i', 'c'};

const char cv5[18]{'f', 'r', 'e', 'q', 'S', 'e', 'a', 'r', 'c',
                   'h', 'S', 'o', 'f', 't', 'L', 'o', 'c', 'k'};

rtRunTimeErrorInfo uc_emlrtRTEI{
    41,    // lineNo
    9,     // colNo
    "rem", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/eml/eml/+coder/+internal/+scalar/"
    "rem.m" // pName
};

bool isInitialized_uavrt_detection{false};

// End of code generation (uavrt_detection_data.cpp)
