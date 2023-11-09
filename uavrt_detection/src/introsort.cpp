//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// introsort.cpp
//
// Code generation for function 'introsort'
//

// Include files
#include "introsort.h"
#include "anonymous_function.h"
#include "heapsort.h"
#include "insertionsort.h"
#include "nextpow2.h"
#include "rt_nonfinite.h"
#include "stack1.h"
#include "uavrt_detection_internal_types.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include <sstream>
#include <stdexcept>
#include <string>

// Variable Definitions
static rtRunTimeErrorInfo sc_emlrtRTEI{
    62,           // lineNo
    39,           // colNo
    "stack/push", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/shared/coder/coder/lib/+coder/"
    "+internal/stack.m" // pName
};

static rtDoubleCheckInfo v_emlrtDCI{
    48,            // lineNo
    48,            // colNo
    "stack/stack", // fName
    "/Applications/MATLAB_R2023a.app/toolbox/shared/coder/coder/lib/+coder/"
    "+internal/stack.m", // pName
    4                    // checkKind
};

// Function Declarations
static void vc_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

// Function Definitions
static void vc_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Cannot push onto a fixed-size stack which is at capacity.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

namespace coder {
namespace internal {
void introsort(::coder::array<int, 1U> &x, int xend,
               const c_anonymous_function &cmp)
{
  stack st;
  struct_T frame;
  int xmid;
  if (xend > 1) {
    if (xend <= 32) {
      insertionsort(x, 1, xend, cmp);
    } else {
      int MAXDEPTH;
      int b_i;
      int i;
      MAXDEPTH = (nextpow2(xend) - 1) << 1;
      frame.xstart = 1;
      frame.xend = xend;
      frame.depth = 0;
      i = MAXDEPTH << 1;
      if (i < 0) {
        rtNonNegativeError(static_cast<double>(i), v_emlrtDCI);
      }
      st.d.set_size(i);
      for (b_i = 0; b_i < i; b_i++) {
        st.d[b_i] = frame;
      }
      if (i <= 0) {
        vc_rtErrorWithMessageID(sc_emlrtRTEI.fName, sc_emlrtRTEI.lineNo);
      }
      st.d[0] = frame;
      st.n = 1;
      while (st.n > 0) {
        int frame_tmp_tmp;
        frame_tmp_tmp = st.n - 1;
        frame = st.d[st.n - 1];
        st.n--;
        b_i = frame.xend - frame.xstart;
        if (b_i + 1 <= 32) {
          insertionsort(x, frame.xstart, frame.xend, cmp);
        } else if (frame.depth == MAXDEPTH) {
          b_heapsort(x, frame.xstart, frame.xend, cmp);
        } else {
          int pivot;
          int t;
          xmid = (frame.xstart + b_i / 2) - 1;
          b_i = x[frame.xstart - 1];
          if (cmp.workspace.x[x[xmid] - 1] < cmp.workspace.x[b_i - 1]) {
            x[frame.xstart - 1] = x[xmid];
            x[xmid] = b_i;
          }
          b_i = x[frame.xstart - 1];
          i = x[frame.xend - 1];
          if (cmp.workspace.x[i - 1] < cmp.workspace.x[b_i - 1]) {
            x[frame.xstart - 1] = i;
            x[frame.xend - 1] = b_i;
          }
          b_i = x[frame.xend - 1];
          if (cmp.workspace.x[b_i - 1] < cmp.workspace.x[x[xmid] - 1]) {
            t = x[xmid];
            x[xmid] = b_i;
            x[frame.xend - 1] = t;
          }
          pivot = x[xmid];
          x[xmid] = x[frame.xend - 2];
          x[frame.xend - 2] = pivot;
          i = frame.xstart - 1;
          xmid = frame.xend - 2;
          int exitg1;
          do {
            exitg1 = 0;
            i++;
            int exitg2;
            do {
              exitg2 = 0;
              b_i = cmp.workspace.x[pivot - 1];
              if (cmp.workspace.x[x[i] - 1] < b_i) {
                i++;
              } else {
                exitg2 = 1;
              }
            } while (exitg2 == 0);
            for (xmid--; b_i < cmp.workspace.x[x[xmid] - 1]; xmid--) {
            }
            if (i + 1 >= xmid + 1) {
              exitg1 = 1;
            } else {
              t = x[i];
              x[i] = x[xmid];
              x[xmid] = t;
            }
          } while (exitg1 == 0);
          x[frame.xend - 2] = x[i];
          x[i] = pivot;
          if (i + 2 < frame.xend) {
            if (frame_tmp_tmp >= st.d.size(0)) {
              vc_rtErrorWithMessageID(sc_emlrtRTEI.fName, sc_emlrtRTEI.lineNo);
            }
            st.d[frame_tmp_tmp].xstart = i + 2;
            st.d[frame_tmp_tmp].xend = frame.xend;
            st.d[frame_tmp_tmp].depth = frame.depth + 1;
            st.n = frame_tmp_tmp + 1;
          }
          if (frame.xstart < i + 1) {
            if (st.n >= st.d.size(0)) {
              vc_rtErrorWithMessageID(sc_emlrtRTEI.fName, sc_emlrtRTEI.lineNo);
            }
            st.d[st.n].xstart = frame.xstart;
            st.d[st.n].xend = i + 1;
            st.d[st.n].depth = frame.depth + 1;
            st.n++;
          }
        }
      }
    }
  }
}

void introsort(::coder::array<int, 1U> &x, int xend,
               const anonymous_function &cmp)
{
  stack st;
  struct_T frame;
  if (xend > 1) {
    if (xend <= 32) {
      insertionsort(x, 1, xend, cmp);
    } else {
      int MAXDEPTH;
      int b_i;
      int i;
      MAXDEPTH = (nextpow2(xend) - 1) << 1;
      frame.xstart = 1;
      frame.xend = xend;
      frame.depth = 0;
      i = MAXDEPTH << 1;
      if (i < 0) {
        rtNonNegativeError(static_cast<double>(i), v_emlrtDCI);
      }
      st.d.set_size(i);
      for (b_i = 0; b_i < i; b_i++) {
        st.d[b_i] = frame;
      }
      if (i <= 0) {
        vc_rtErrorWithMessageID(sc_emlrtRTEI.fName, sc_emlrtRTEI.lineNo);
      }
      st.d[0] = frame;
      st.n = 1;
      while (st.n > 0) {
        int frame_tmp_tmp;
        frame_tmp_tmp = st.n - 1;
        frame = st.d[st.n - 1];
        st.n--;
        b_i = frame.xend - frame.xstart;
        if (b_i + 1 <= 32) {
          insertionsort(x, frame.xstart, frame.xend, cmp);
        } else if (frame.depth == MAXDEPTH) {
          b_heapsort(x, frame.xstart, frame.xend, cmp);
        } else {
          int j;
          int pivot;
          int t;
          int xmid;
          bool varargout_1;
          xmid = (frame.xstart + b_i / 2) - 1;
          b_i = cmp.workspace.a[x[xmid] - 1];
          i = x[frame.xstart - 1];
          j = cmp.workspace.a[i - 1];
          if (b_i < j) {
            varargout_1 = true;
          } else if (b_i == j) {
            varargout_1 =
                (cmp.workspace.b[x[xmid] - 1] < cmp.workspace.b[i - 1]);
          } else {
            varargout_1 = false;
          }
          if (varargout_1) {
            x[frame.xstart - 1] = x[xmid];
            x[xmid] = i;
          }
          b_i = x[frame.xend - 1];
          i = cmp.workspace.a[b_i - 1];
          j = x[frame.xstart - 1];
          t = cmp.workspace.a[j - 1];
          if (i < t) {
            varargout_1 = true;
          } else if (i == t) {
            varargout_1 = (cmp.workspace.b[b_i - 1] < cmp.workspace.b[j - 1]);
          } else {
            varargout_1 = false;
          }
          if (varargout_1) {
            x[frame.xstart - 1] = b_i;
            x[frame.xend - 1] = j;
          }
          b_i = x[frame.xend - 1];
          i = cmp.workspace.a[b_i - 1];
          j = cmp.workspace.a[x[xmid] - 1];
          if (i < j) {
            varargout_1 = true;
          } else if (i == j) {
            varargout_1 =
                (cmp.workspace.b[b_i - 1] < cmp.workspace.b[x[xmid] - 1]);
          } else {
            varargout_1 = false;
          }
          if (varargout_1) {
            t = x[xmid];
            x[xmid] = b_i;
            x[frame.xend - 1] = t;
          }
          pivot = x[xmid] - 1;
          x[xmid] = x[frame.xend - 2];
          x[frame.xend - 2] = pivot + 1;
          i = frame.xstart - 1;
          j = frame.xend - 2;
          int exitg1;
          do {
            int exitg2;
            exitg1 = 0;
            i++;
            do {
              exitg2 = 0;
              b_i = cmp.workspace.a[x[i] - 1];
              if (b_i < cmp.workspace.a[pivot]) {
                varargout_1 = true;
              } else if (b_i == cmp.workspace.a[pivot]) {
                varargout_1 =
                    (cmp.workspace.b[x[i] - 1] < cmp.workspace.b[pivot]);
              } else {
                varargout_1 = false;
              }
              if (varargout_1) {
                i++;
              } else {
                exitg2 = 1;
              }
            } while (exitg2 == 0);
            j--;
            do {
              exitg2 = 0;
              b_i = cmp.workspace.a[x[j] - 1];
              if (cmp.workspace.a[pivot] < b_i) {
                varargout_1 = true;
              } else if (cmp.workspace.a[pivot] == b_i) {
                varargout_1 =
                    (cmp.workspace.b[pivot] < cmp.workspace.b[x[j] - 1]);
              } else {
                varargout_1 = false;
              }
              if (varargout_1) {
                j--;
              } else {
                exitg2 = 1;
              }
            } while (exitg2 == 0);
            if (i + 1 >= j + 1) {
              exitg1 = 1;
            } else {
              t = x[i];
              x[i] = x[j];
              x[j] = t;
            }
          } while (exitg1 == 0);
          x[frame.xend - 2] = x[i];
          x[i] = pivot + 1;
          if (i + 2 < frame.xend) {
            if (frame_tmp_tmp >= st.d.size(0)) {
              vc_rtErrorWithMessageID(sc_emlrtRTEI.fName, sc_emlrtRTEI.lineNo);
            }
            st.d[frame_tmp_tmp].xstart = i + 2;
            st.d[frame_tmp_tmp].xend = frame.xend;
            st.d[frame_tmp_tmp].depth = frame.depth + 1;
            st.n = frame_tmp_tmp + 1;
          }
          if (frame.xstart < i + 1) {
            if (st.n >= st.d.size(0)) {
              vc_rtErrorWithMessageID(sc_emlrtRTEI.fName, sc_emlrtRTEI.lineNo);
            }
            st.d[st.n].xstart = frame.xstart;
            st.d[st.n].xend = i + 1;
            st.d[st.n].depth = frame.depth + 1;
            st.n++;
          }
        }
      }
    }
  }
}

} // namespace internal
} // namespace coder

// End of code generation (introsort.cpp)
