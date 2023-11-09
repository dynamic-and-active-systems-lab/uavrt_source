//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// randn.cpp
//
// Code generation for function 'randn'
//

// Include files
#include "randn.h"
#include "eml_rand_mt19937ar.h"
#include "eml_rand_shr3cong.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace coder {
void complexLike(creal_T r[1000])
{
  if (method == 0U) {
    if (b_method == 4U) {
      for (int k{0}; k < 1000; k++) {
        double b_r;
        double b_t;
        double im;
        double t;
        unsigned int a;
        unsigned int b;
        unsigned int e_state;
        int hi;
        do {
          hi = static_cast<int>(b_state / 127773U);
          a = 16807U * (b_state - static_cast<unsigned int>(hi) * 127773U);
          b = 2836U * static_cast<unsigned int>(hi);
          if (a < b) {
            e_state = ~(b - a) & 2147483647U;
          } else {
            e_state = a - b;
          }
          hi = static_cast<int>(e_state / 127773U);
          a = 16807U * (e_state - static_cast<unsigned int>(hi) * 127773U);
          b = 2836U * static_cast<unsigned int>(hi);
          if (a < b) {
            b_state = ~(b - a) & 2147483647U;
          } else {
            b_state = a - b;
          }
          im = 2.0 * (static_cast<double>(e_state) * 4.6566128752457969E-10) -
               1.0;
          t = 2.0 * (static_cast<double>(b_state) * 4.6566128752457969E-10) -
              1.0;
          t = t * t + im * im;
        } while (!(t <= 1.0));
        do {
          hi = static_cast<int>(b_state / 127773U);
          a = 16807U * (b_state - static_cast<unsigned int>(hi) * 127773U);
          b = 2836U * static_cast<unsigned int>(hi);
          if (a < b) {
            e_state = ~(b - a) & 2147483647U;
          } else {
            e_state = a - b;
          }
          hi = static_cast<int>(e_state / 127773U);
          a = 16807U * (e_state - static_cast<unsigned int>(hi) * 127773U);
          b = 2836U * static_cast<unsigned int>(hi);
          if (a < b) {
            b_state = ~(b - a) & 2147483647U;
          } else {
            b_state = a - b;
          }
          b_r = 2.0 * (static_cast<double>(e_state) * 4.6566128752457969E-10) -
                1.0;
          b_t = 2.0 * (static_cast<double>(b_state) * 4.6566128752457969E-10) -
                1.0;
          b_t = b_t * b_t + b_r * b_r;
        } while (!(b_t <= 1.0));
        t = im * std::sqrt(-2.0 * std::log(t) / t);
        im = b_r * std::sqrt(-2.0 * std::log(b_t) / b_t);
        if (im == 0.0) {
          r[k].re = t / 1.4142135623730951;
          r[k].im = 0.0;
        } else if (t == 0.0) {
          r[k].re = 0.0;
          r[k].im = im / 1.4142135623730951;
        } else {
          r[k].re = t / 1.4142135623730951;
          r[k].im = im / 1.4142135623730951;
        }
      }
    } else if (b_method == 5U) {
      double im;
      double t;
      for (int k{0}; k < 1000; k++) {
        t = eml_rand_shr3cong(c_state);
        im = eml_rand_shr3cong(c_state);
        r[k].re = t;
        r[k].im = im;
      }
      for (int k{0}; k < 1000; k++) {
        t = r[k].re;
        im = r[k].im;
        if (im == 0.0) {
          t /= 1.4142135623730951;
          im = 0.0;
        } else if (t == 0.0) {
          t = 0.0;
          im /= 1.4142135623730951;
        } else {
          t /= 1.4142135623730951;
          im /= 1.4142135623730951;
        }
        r[k].re = t;
        r[k].im = im;
      }
    } else {
      double im;
      double t;
      for (int k{0}; k < 1000; k++) {
        t = eml_rand_mt19937ar(d_state);
        im = eml_rand_mt19937ar(d_state);
        r[k].re = t;
        r[k].im = im;
      }
      for (int k{0}; k < 1000; k++) {
        t = r[k].re;
        im = r[k].im;
        if (im == 0.0) {
          t /= 1.4142135623730951;
          im = 0.0;
        } else if (t == 0.0) {
          t = 0.0;
          im /= 1.4142135623730951;
        } else {
          t /= 1.4142135623730951;
          im /= 1.4142135623730951;
        }
        r[k].re = t;
        r[k].im = im;
      }
    }
  } else if (method == 4U) {
    for (int k{0}; k < 1000; k++) {
      double b_r;
      double b_t;
      double im;
      double t;
      unsigned int a;
      unsigned int b;
      unsigned int e_state;
      unsigned int f_state;
      int hi;
      e_state = state[0];
      do {
        hi = static_cast<int>(e_state / 127773U);
        a = 16807U * (e_state - static_cast<unsigned int>(hi) * 127773U);
        b = 2836U * static_cast<unsigned int>(hi);
        if (a < b) {
          f_state = ~(b - a) & 2147483647U;
        } else {
          f_state = a - b;
        }
        hi = static_cast<int>(f_state / 127773U);
        a = 16807U * (f_state - static_cast<unsigned int>(hi) * 127773U);
        b = 2836U * static_cast<unsigned int>(hi);
        if (a < b) {
          e_state = ~(b - a) & 2147483647U;
        } else {
          e_state = a - b;
        }
        im =
            2.0 * (static_cast<double>(f_state) * 4.6566128752457969E-10) - 1.0;
        t = 2.0 * (static_cast<double>(e_state) * 4.6566128752457969E-10) - 1.0;
        t = t * t + im * im;
      } while (!(t <= 1.0));
      state[0] = e_state;
      do {
        hi = static_cast<int>(e_state / 127773U);
        a = 16807U * (e_state - static_cast<unsigned int>(hi) * 127773U);
        b = 2836U * static_cast<unsigned int>(hi);
        if (a < b) {
          f_state = ~(b - a) & 2147483647U;
        } else {
          f_state = a - b;
        }
        hi = static_cast<int>(f_state / 127773U);
        a = 16807U * (f_state - static_cast<unsigned int>(hi) * 127773U);
        b = 2836U * static_cast<unsigned int>(hi);
        if (a < b) {
          e_state = ~(b - a) & 2147483647U;
        } else {
          e_state = a - b;
        }
        b_r =
            2.0 * (static_cast<double>(f_state) * 4.6566128752457969E-10) - 1.0;
        b_t =
            2.0 * (static_cast<double>(e_state) * 4.6566128752457969E-10) - 1.0;
        b_t = b_t * b_t + b_r * b_r;
      } while (!(b_t <= 1.0));
      state[0] = e_state;
      t = im * std::sqrt(-2.0 * std::log(t) / t);
      im = b_r * std::sqrt(-2.0 * std::log(b_t) / b_t);
      if (im == 0.0) {
        r[k].re = t / 1.4142135623730951;
        r[k].im = 0.0;
      } else if (t == 0.0) {
        r[k].re = 0.0;
        r[k].im = im / 1.4142135623730951;
      } else {
        r[k].re = t / 1.4142135623730951;
        r[k].im = im / 1.4142135623730951;
      }
    }
  } else {
    double im;
    double t;
    for (int k{0}; k < 1000; k++) {
      t = eml_rand_shr3cong(state);
      im = eml_rand_shr3cong(state);
      r[k].re = t;
      r[k].im = im;
    }
    for (int k{0}; k < 1000; k++) {
      t = r[k].re;
      im = r[k].im;
      if (im == 0.0) {
        t /= 1.4142135623730951;
        im = 0.0;
      } else if (t == 0.0) {
        t = 0.0;
        im /= 1.4142135623730951;
      } else {
        t /= 1.4142135623730951;
        im /= 1.4142135623730951;
      }
      r[k].re = t;
      r[k].im = im;
    }
  }
}

void complexLike(double varargin_1, ::coder::array<creal_T, 2U> &r)
{
  static rtDoubleCheckInfo ab_emlrtDCI{
      50,          // lineNo
      42,          // colNo
      "eml_randn", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/randfun/private/"
      "eml_randn.m", // pName
      4              // checkKind
  };
  static rtDoubleCheckInfo w_emlrtDCI{
      33,             // lineNo
      30,             // colNo
      "genRandomNum", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/randfun/private/"
      "eml_rand_mcg16807_stateful.m", // pName
      4                               // checkKind
  };
  static rtDoubleCheckInfo x_emlrtDCI{
      29,                           // lineNo
      34,                           // colNo
      "eml_rand_shr3cong_stateful", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/randfun/private/"
      "eml_rand_shr3cong_stateful.m", // pName
      4                               // checkKind
  };
  static rtDoubleCheckInfo y_emlrtDCI{
      29,                            // lineNo
      34,                            // colNo
      "eml_rand_mt19937ar_stateful", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/randfun/private/"
      "eml_rand_mt19937ar_stateful.m", // pName
      4                                // checkKind
  };
  double t;
  if ((varargin_1 != std::floor(varargin_1)) || std::isinf(varargin_1) ||
      (varargin_1 < -2.147483648E+9) || (varargin_1 > 2.147483647E+9)) {
    c_rtErrorWithMessageID(MIN_int32_T, lb_emlrtRTEI.fName,
                           lb_emlrtRTEI.lineNo);
  }
  if (varargin_1 <= 0.0) {
    t = 0.0;
  } else {
    t = varargin_1;
  }
  if (!(t * 100.0 <= 2.147483647E+9)) {
    l_rtErrorWithMessageID(o_emlrtRTEI.fName, o_emlrtRTEI.lineNo);
  }
  if (method == 0U) {
    if (b_method == 4U) {
      double ai;
      double im;
      unsigned int e_state;
      int hi;
      int loop_ub;
      e_state = b_state;
      if (!(varargin_1 >= 0.0)) {
        rtNonNegativeError(varargin_1, w_emlrtDCI);
      }
      r.set_size(static_cast<int>(varargin_1), 100);
      loop_ub = static_cast<int>(varargin_1) * 100;
      for (int k{0}; k < loop_ub; k++) {
        double b_t;
        unsigned int b;
        unsigned int f_state;
        do {
          hi = static_cast<int>(e_state / 127773U);
          e_state =
              16807U * (e_state - static_cast<unsigned int>(hi) * 127773U);
          b = 2836U * static_cast<unsigned int>(hi);
          if (e_state < b) {
            f_state = ~(b - e_state) & 2147483647U;
          } else {
            f_state = e_state - b;
          }
          hi = static_cast<int>(f_state / 127773U);
          e_state =
              16807U * (f_state - static_cast<unsigned int>(hi) * 127773U);
          b = 2836U * static_cast<unsigned int>(hi);
          if (e_state < b) {
            e_state = ~(b - e_state) & 2147483647U;
          } else {
            e_state -= b;
          }
          im = 2.0 * (static_cast<double>(f_state) * 4.6566128752457969E-10) -
               1.0;
          t = 2.0 * (static_cast<double>(e_state) * 4.6566128752457969E-10) -
              1.0;
          t = t * t + im * im;
        } while (!(t <= 1.0));
        do {
          hi = static_cast<int>(e_state / 127773U);
          e_state =
              16807U * (e_state - static_cast<unsigned int>(hi) * 127773U);
          b = 2836U * static_cast<unsigned int>(hi);
          if (e_state < b) {
            f_state = ~(b - e_state) & 2147483647U;
          } else {
            f_state = e_state - b;
          }
          hi = static_cast<int>(f_state / 127773U);
          e_state =
              16807U * (f_state - static_cast<unsigned int>(hi) * 127773U);
          b = 2836U * static_cast<unsigned int>(hi);
          if (e_state < b) {
            e_state = ~(b - e_state) & 2147483647U;
          } else {
            e_state -= b;
          }
          ai = 2.0 * (static_cast<double>(f_state) * 4.6566128752457969E-10) -
               1.0;
          b_t = 2.0 * (static_cast<double>(e_state) * 4.6566128752457969E-10) -
                1.0;
          b_t = b_t * b_t + ai * ai;
        } while (!(b_t <= 1.0));
        r[k].re = im * std::sqrt(-2.0 * std::log(t) / t);
        r[k].im = ai * std::sqrt(-2.0 * std::log(b_t) / b_t);
      }
      r.set_size(r.size(0), 100);
      for (hi = 0; hi < loop_ub; hi++) {
        im = r[hi].re;
        ai = r[hi].im;
        if (ai == 0.0) {
          t = im / 1.4142135623730951;
          im = 0.0;
        } else if (im == 0.0) {
          t = 0.0;
          im = ai / 1.4142135623730951;
        } else {
          t = im / 1.4142135623730951;
          im = ai / 1.4142135623730951;
        }
        r[hi].re = t;
        r[hi].im = im;
      }
      b_state = e_state;
    } else if (b_method == 5U) {
      double im;
      int loop_ub;
      if (!(varargin_1 >= 0.0)) {
        rtNonNegativeError(varargin_1, x_emlrtDCI);
      }
      r.set_size(static_cast<int>(varargin_1), 100);
      loop_ub = static_cast<int>(varargin_1) * 100;
      for (int k{0}; k < loop_ub; k++) {
        t = eml_rand_shr3cong(c_state);
        im = eml_rand_shr3cong(c_state);
        r[k].re = t;
        r[k].im = im;
      }
      r.set_size(r.size(0), 100);
      for (int hi{0}; hi < loop_ub; hi++) {
        double ai;
        im = r[hi].re;
        ai = r[hi].im;
        if (ai == 0.0) {
          t = im / 1.4142135623730951;
          im = 0.0;
        } else if (im == 0.0) {
          t = 0.0;
          im = ai / 1.4142135623730951;
        } else {
          t = im / 1.4142135623730951;
          im = ai / 1.4142135623730951;
        }
        r[hi].re = t;
        r[hi].im = im;
      }
    } else {
      double im;
      int loop_ub;
      if (!(varargin_1 >= 0.0)) {
        rtNonNegativeError(varargin_1, y_emlrtDCI);
      }
      r.set_size(static_cast<int>(varargin_1), 100);
      loop_ub = static_cast<int>(varargin_1) * 100;
      for (int k{0}; k < loop_ub; k++) {
        t = eml_rand_mt19937ar(d_state);
        im = eml_rand_mt19937ar(d_state);
        r[k].re = t;
        r[k].im = im;
      }
      r.set_size(r.size(0), 100);
      for (int hi{0}; hi < loop_ub; hi++) {
        double ai;
        im = r[hi].re;
        ai = r[hi].im;
        if (ai == 0.0) {
          t = im / 1.4142135623730951;
          im = 0.0;
        } else if (im == 0.0) {
          t = 0.0;
          im = ai / 1.4142135623730951;
        } else {
          t = im / 1.4142135623730951;
          im = ai / 1.4142135623730951;
        }
        r[hi].re = t;
        r[hi].im = im;
      }
    }
  } else {
    if (!(varargin_1 >= 0.0)) {
      rtNonNegativeError(varargin_1, ab_emlrtDCI);
    }
    r.set_size(static_cast<int>(varargin_1), 100);
    if (method == 4U) {
      double ai;
      double im;
      int hi;
      int loop_ub;
      loop_ub = static_cast<int>(varargin_1) * 100;
      for (int k{0}; k < loop_ub; k++) {
        double b_t;
        unsigned int b;
        unsigned int e_state;
        unsigned int f_state;
        e_state = state[0];
        do {
          hi = static_cast<int>(e_state / 127773U);
          e_state =
              16807U * (e_state - static_cast<unsigned int>(hi) * 127773U);
          b = 2836U * static_cast<unsigned int>(hi);
          if (e_state < b) {
            f_state = ~(b - e_state) & 2147483647U;
          } else {
            f_state = e_state - b;
          }
          hi = static_cast<int>(f_state / 127773U);
          e_state =
              16807U * (f_state - static_cast<unsigned int>(hi) * 127773U);
          b = 2836U * static_cast<unsigned int>(hi);
          if (e_state < b) {
            e_state = ~(b - e_state) & 2147483647U;
          } else {
            e_state -= b;
          }
          im = 2.0 * (static_cast<double>(f_state) * 4.6566128752457969E-10) -
               1.0;
          t = 2.0 * (static_cast<double>(e_state) * 4.6566128752457969E-10) -
              1.0;
          t = t * t + im * im;
        } while (!(t <= 1.0));
        state[0] = e_state;
        do {
          hi = static_cast<int>(e_state / 127773U);
          e_state =
              16807U * (e_state - static_cast<unsigned int>(hi) * 127773U);
          b = 2836U * static_cast<unsigned int>(hi);
          if (e_state < b) {
            f_state = ~(b - e_state) & 2147483647U;
          } else {
            f_state = e_state - b;
          }
          hi = static_cast<int>(f_state / 127773U);
          e_state =
              16807U * (f_state - static_cast<unsigned int>(hi) * 127773U);
          b = 2836U * static_cast<unsigned int>(hi);
          if (e_state < b) {
            e_state = ~(b - e_state) & 2147483647U;
          } else {
            e_state -= b;
          }
          ai = 2.0 * (static_cast<double>(f_state) * 4.6566128752457969E-10) -
               1.0;
          b_t = 2.0 * (static_cast<double>(e_state) * 4.6566128752457969E-10) -
                1.0;
          b_t = b_t * b_t + ai * ai;
        } while (!(b_t <= 1.0));
        state[0] = e_state;
        r[k].re = im * std::sqrt(-2.0 * std::log(t) / t);
        r[k].im = ai * std::sqrt(-2.0 * std::log(b_t) / b_t);
      }
      r.set_size(r.size(0), 100);
      for (hi = 0; hi < loop_ub; hi++) {
        im = r[hi].re;
        ai = r[hi].im;
        if (ai == 0.0) {
          t = im / 1.4142135623730951;
          im = 0.0;
        } else if (im == 0.0) {
          t = 0.0;
          im = ai / 1.4142135623730951;
        } else {
          t = im / 1.4142135623730951;
          im = ai / 1.4142135623730951;
        }
        r[hi].re = t;
        r[hi].im = im;
      }
    } else {
      double im;
      int loop_ub;
      loop_ub = static_cast<int>(varargin_1) * 100;
      for (int k{0}; k < loop_ub; k++) {
        t = eml_rand_shr3cong(state);
        im = eml_rand_shr3cong(state);
        r[k].re = t;
        r[k].im = im;
      }
      r.set_size(r.size(0), 100);
      for (int hi{0}; hi < loop_ub; hi++) {
        double ai;
        im = r[hi].re;
        ai = r[hi].im;
        if (ai == 0.0) {
          t = im / 1.4142135623730951;
          im = 0.0;
        } else if (im == 0.0) {
          t = 0.0;
          im = ai / 1.4142135623730951;
        } else {
          t = im / 1.4142135623730951;
          im = ai / 1.4142135623730951;
        }
        r[hi].re = t;
        r[hi].im = im;
      }
    }
  }
}

void randn(double r[1000])
{
  if (method == 0U) {
    if (b_method == 4U) {
      for (int k{0}; k < 1000; k++) {
        double b_r;
        double t;
        unsigned int a;
        unsigned int b;
        int hi;
        do {
          unsigned int e_state;
          hi = static_cast<int>(b_state / 127773U);
          a = 16807U * (b_state - static_cast<unsigned int>(hi) * 127773U);
          b = 2836U * static_cast<unsigned int>(hi);
          if (a < b) {
            e_state = ~(b - a) & 2147483647U;
          } else {
            e_state = a - b;
          }
          hi = static_cast<int>(e_state / 127773U);
          a = 16807U * (e_state - static_cast<unsigned int>(hi) * 127773U);
          b = 2836U * static_cast<unsigned int>(hi);
          if (a < b) {
            b_state = ~(b - a) & 2147483647U;
          } else {
            b_state = a - b;
          }
          b_r = 2.0 * (static_cast<double>(e_state) * 4.6566128752457969E-10) -
                1.0;
          t = 2.0 * (static_cast<double>(b_state) * 4.6566128752457969E-10) -
              1.0;
          t = t * t + b_r * b_r;
        } while (!(t <= 1.0));
        r[k] = b_r * std::sqrt(-2.0 * std::log(t) / t);
      }
    } else if (b_method == 5U) {
      for (int k{0}; k < 1000; k++) {
        r[k] = eml_rand_shr3cong(c_state);
      }
    } else {
      for (int k{0}; k < 1000; k++) {
        r[k] = eml_rand_mt19937ar(d_state);
      }
    }
  } else if (method == 4U) {
    for (int k{0}; k < 1000; k++) {
      double b_r;
      double t;
      unsigned int e_state;
      e_state = state[0];
      unsigned int a;
      unsigned int b;
      int hi;
      do {
        unsigned int f_state;
        hi = static_cast<int>(e_state / 127773U);
        a = 16807U * (e_state - static_cast<unsigned int>(hi) * 127773U);
        b = 2836U * static_cast<unsigned int>(hi);
        if (a < b) {
          f_state = ~(b - a) & 2147483647U;
        } else {
          f_state = a - b;
        }
        hi = static_cast<int>(f_state / 127773U);
        a = 16807U * (f_state - static_cast<unsigned int>(hi) * 127773U);
        b = 2836U * static_cast<unsigned int>(hi);
        if (a < b) {
          e_state = ~(b - a) & 2147483647U;
        } else {
          e_state = a - b;
        }
        b_r =
            2.0 * (static_cast<double>(f_state) * 4.6566128752457969E-10) - 1.0;
        t = 2.0 * (static_cast<double>(e_state) * 4.6566128752457969E-10) - 1.0;
        t = t * t + b_r * b_r;
      } while (!(t <= 1.0));
      r[k] = b_r * std::sqrt(-2.0 * std::log(t) / t);
      state[0] = e_state;
    }
  } else {
    for (int k{0}; k < 1000; k++) {
      r[k] = eml_rand_shr3cong(state);
    }
  }
}

void randn(double varargin_1, ::coder::array<double, 2U> &r)
{
  static rtDoubleCheckInfo ab_emlrtDCI{
      37,                           // lineNo
      34,                           // colNo
      "eml_rand_shr3cong_stateful", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/randfun/private/"
      "eml_rand_shr3cong_stateful.m", // pName
      4                               // checkKind
  };
  static rtDoubleCheckInfo w_emlrtDCI{
      68,          // lineNo
      42,          // colNo
      "eml_randn", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/randfun/private/"
      "eml_randn.m", // pName
      4              // checkKind
  };
  static rtDoubleCheckInfo x_emlrtDCI{
      37,                            // lineNo
      34,                            // colNo
      "eml_rand_mt19937ar_stateful", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/randfun/private/"
      "eml_rand_mt19937ar_stateful.m", // pName
      4                                // checkKind
  };
  static rtDoubleCheckInfo y_emlrtDCI{
      41,             // lineNo
      30,             // colNo
      "genRandomNum", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/randfun/private/"
      "eml_rand_mcg16807_stateful.m", // pName
      4                               // checkKind
  };
  if (method == 0U) {
    if (b_method == 4U) {
      unsigned int e_state;
      int i;
      e_state = b_state;
      if (!(varargin_1 >= 0.0)) {
        rtNonNegativeError(varargin_1, y_emlrtDCI);
      }
      r.set_size(static_cast<int>(varargin_1), 100);
      i = static_cast<int>(varargin_1) * 100;
      for (int k{0}; k < i; k++) {
        double b_r;
        double t;
        unsigned int b;
        int hi;
        do {
          unsigned int f_state;
          hi = static_cast<int>(e_state / 127773U);
          e_state =
              16807U * (e_state - static_cast<unsigned int>(hi) * 127773U);
          b = 2836U * static_cast<unsigned int>(hi);
          if (e_state < b) {
            f_state = ~(b - e_state) & 2147483647U;
          } else {
            f_state = e_state - b;
          }
          hi = static_cast<int>(f_state / 127773U);
          e_state =
              16807U * (f_state - static_cast<unsigned int>(hi) * 127773U);
          b = 2836U * static_cast<unsigned int>(hi);
          if (e_state < b) {
            e_state = ~(b - e_state) & 2147483647U;
          } else {
            e_state -= b;
          }
          b_r = 2.0 * (static_cast<double>(f_state) * 4.6566128752457969E-10) -
                1.0;
          t = 2.0 * (static_cast<double>(e_state) * 4.6566128752457969E-10) -
              1.0;
          t = t * t + b_r * b_r;
        } while (!(t <= 1.0));
        r[k] = b_r * std::sqrt(-2.0 * std::log(t) / t);
      }
      b_state = e_state;
    } else if (b_method == 5U) {
      int i;
      if (!(varargin_1 >= 0.0)) {
        rtNonNegativeError(varargin_1, ab_emlrtDCI);
      }
      r.set_size(static_cast<int>(varargin_1), 100);
      i = static_cast<int>(varargin_1) * 100;
      for (int k{0}; k < i; k++) {
        r[k] = eml_rand_shr3cong(c_state);
      }
    } else {
      int i;
      if (!(varargin_1 >= 0.0)) {
        rtNonNegativeError(varargin_1, x_emlrtDCI);
      }
      r.set_size(static_cast<int>(varargin_1), 100);
      i = static_cast<int>(varargin_1) * 100;
      for (int k{0}; k < i; k++) {
        r[k] = eml_rand_mt19937ar(d_state);
      }
    }
  } else {
    if (!(varargin_1 >= 0.0)) {
      rtNonNegativeError(varargin_1, w_emlrtDCI);
    }
    r.set_size(static_cast<int>(varargin_1), 100);
    if (method == 4U) {
      int i;
      i = static_cast<int>(varargin_1) * 100;
      for (int k{0}; k < i; k++) {
        double b_r;
        double t;
        unsigned int e_state;
        e_state = state[0];
        unsigned int b;
        int hi;
        do {
          unsigned int f_state;
          hi = static_cast<int>(e_state / 127773U);
          e_state =
              16807U * (e_state - static_cast<unsigned int>(hi) * 127773U);
          b = 2836U * static_cast<unsigned int>(hi);
          if (e_state < b) {
            f_state = ~(b - e_state) & 2147483647U;
          } else {
            f_state = e_state - b;
          }
          hi = static_cast<int>(f_state / 127773U);
          e_state =
              16807U * (f_state - static_cast<unsigned int>(hi) * 127773U);
          b = 2836U * static_cast<unsigned int>(hi);
          if (e_state < b) {
            e_state = ~(b - e_state) & 2147483647U;
          } else {
            e_state -= b;
          }
          b_r = 2.0 * (static_cast<double>(f_state) * 4.6566128752457969E-10) -
                1.0;
          t = 2.0 * (static_cast<double>(e_state) * 4.6566128752457969E-10) -
              1.0;
          t = t * t + b_r * b_r;
        } while (!(t <= 1.0));
        r[k] = b_r * std::sqrt(-2.0 * std::log(t) / t);
        state[0] = e_state;
      }
    } else {
      int i;
      i = static_cast<int>(varargin_1) * 100;
      for (int k{0}; k < i; k++) {
        r[k] = eml_rand_shr3cong(state);
      }
    }
  }
}

} // namespace coder

// End of code generation (randn.cpp)
