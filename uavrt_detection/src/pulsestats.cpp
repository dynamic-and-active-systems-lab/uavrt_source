//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// pulsestats.cpp
//
// Code generation for function 'pulsestats'
//

// Include files
#include "pulsestats.h"
#include "combineVectorElements.h"
#include "diff.h"
#include "eml_int_forloop_overflow_check.h"
#include "horzcatStructList.h"
#include "rt_nonfinite.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_internal_types.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "validator_check_size.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include <cmath>

// Variable Definitions
static rtEqualityCheckInfo emlrtECI{
    2,                       // nDims
    148,                     // lineNo
    17,                      // colNo
    "pulsestats/pulsestats", // fName
    "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
    "pulsestats.m" // pName
};

static rtEqualityCheckInfo g_emlrtECI{
    2,                             // nDims
    264,                           // lineNo
    21,                            // colNo
    "pulsestats/updateposteriori", // fName
    "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
    "pulsestats.m" // pName
};

static rtBoundsCheckInfo ab_emlrtBCI{
    -1,                            // iFirst
    -1,                            // iLast
    245,                           // lineNo
    64,                            // colNo
    "ps_pre.pl",                   // aName
    "pulsestats/updateposteriori", // fName
    "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
    "pulsestats.m", // pName
    0               // checkKind
};

// Function Definitions
pulsestats *pulsestats::b_init(double tp, double tip, double tipu, double tipj,
                               double b_fp, double b_fstart, double b_fend,
                               const double b_tmplt[2], char b_mode,
                               const coder::array<c_struct_T, 2U> &b_pl,
                               const coder::array<c_struct_T, 2U> &b_clst,
                               const coder::array<bool, 2U> &b_cmsk,
                               const coder::array<double, 2U> &b_cpki)
{
  pulsestats *obj;
  coder::array<c_struct_T, 2U> val;
  int loop_ub;
  obj = this;
  // PULSESTATS Constructs an instance of this class
  //
  // INPUTS:
  //    tp      1x1     Duration of pulse (second)
  //    tip     1x1     Inter-pulse time (seconds)
  //    tipu    1x1     Inter-pulse time uncertainty (seconds)
  //    tipj    1x1     Inter-pulse time jitter (deviations from means)
  //    (seconds) fp      1x1     Pulses' center frequency (Hz) (if known)
  //    fstart  1x1     Lower frequency bound pulses' center frequency (Hz) (if
  //    known) fend    1x1     Upper frequency bound pulses' center frequency
  //    (Hz) (if known) tmplt   1xn     Pulse template. See properies for
  //                    definition. Usually set to [1 1] for
  //                    square pulse.
  //    pl      px1     Vector of pulse objects in waveform (if
  //                    known). If unknown enter a blank pulse made
  //                    from the contstructor "pulse";
  //  Note: Unknown inputs should be set to NaN.
  //
  // OUTPUTS:
  //    pulsestats object
  //
  //             %%
  if (std::isnan(tp) || std::isnan(tip) || std::isnan(tipu) ||
      std::isnan(tipj)) {
    rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
  }
  obj->t_p = tp;
  obj->t_ip = tip;
  obj->t_ipu = tipu;
  obj->t_ipj = tipj;
  obj->fp = b_fp;
  obj->fstart = b_fstart;
  obj->fend = b_fend;
  obj->tmplt[0] = b_tmplt[0];
  obj->tmplt[1] = b_tmplt[1];
  obj->mode = b_mode;
  // The following are variable sized properties. To tell coder
  // that they may vary setup as a local variable size variable
  // first, then set.
  // Instructions on
  // https://www.mathworks.com/help/simulink/ug/how-working-with-matlab-classes-is-different-for-code-generation.html
  // localMode = mode;
  // coder.varsize('localMode',[1 inf],[0 1]); %dims 0 if fixed, 1 if variable
  if (b_cpki.size(1) > 1) {
    rtDimSizeGeqError(1, b_cpki.size(1), emlrtECI);
  }
  // Tell coder these are variable size.
  // Now actually assign them
  coder::internal::validator_check_size(b_pl, val);
  obj->pl.set_size(1, val.size(1));
  loop_ub = val.size(1);
  for (int i{0}; i < loop_ub; i++) {
    obj->pl[i] = val[i];
  }
  obj->clst.set_size(b_clst.size(0), b_clst.size(1));
  loop_ub = b_clst.size(0) * b_clst.size(1);
  for (int i{0}; i < loop_ub; i++) {
    obj->clst[i] = b_clst[i];
  }
  obj->cmsk.set_size(b_cmsk.size(0), b_cmsk.size(1));
  loop_ub = b_cmsk.size(0) * b_cmsk.size(1);
  for (int i{0}; i < loop_ub; i++) {
    obj->cmsk[i] = b_cmsk[i];
  }
  obj->cpki.set_size(b_cpki.size(0), b_cpki.size(1));
  loop_ub = b_cpki.size(0) * b_cpki.size(1);
  for (int i{0}; i < loop_ub; i++) {
    obj->cpki[i] = b_cpki[i];
  }
  return obj;
}

void pulsestats::b_updateposteriori(
    const pulsestats *ps_pre, const coder::array<c_struct_T, 2U> &pulselist)
{
  coder::array<double, 2U> b_pulselist;
  coder::array<double, 2U> b_varargin_1;
  coder::array<double, 2U> varargin_1;
  coder::array<double, 1U> d_varargin_1;
  coder::array<bool, 2U> c_varargin_1;
  //              %UPDATEPOSTERIORI updates the posteriori pulse statistics
  //              object using the new pulse list (input), prior pulse stats
  //              and the waveforms power spectral density vector. This
  //              methods is typically going to be called on a posteriori pulse
  //              stats object after a waveform has been processed and a set
  //              of candidate pulses found. This method uses those pulses and
  //              the prior information about the pulses to update the
  //              posteriori pulse stats.
  //
  //              The pulse contained in the waveform's ps_pos
  //              property is not used directly so that the caller can decide
  //              which pulses on which to focus the posteriori updates
  //
  //  updateType    What parts of the pulsestats to update. Valid
  //                options are 'time', 'freq', 'timeandfreq'. The
  //                'time' option will only update the interpulse
  //                time statistics. The 'freq' option will only
  //                update the frequency stats. The 'timeandfreq'
  //                option will update both.
  //
  if (pulselist.size(1) != 0) {
    double x_tmp;
    int i;
    int input_sizes_idx_0;
    int loop_ub;
    int loop_ub_tmp;
    bool exitg1;
    bool y;
    coder::internal::d_horzcatStructList(pulselist, varargin_1);
    //  pulselist(:).t_0]'
    coder::internal::b_horzcatStructList(pulselist, b_pulselist);
    // pulselist(:).fp
    // Create a vector of bandwidths from the pulselist
    // fEnds   = [pulselist.fend];
    // fStarts = [pulselist.fstart];
    // bw_found = 2*(mean(fEnds,'all','omitnan')-mean(fStarts,'all','omitnan'));
    // if isempty(bw_found)
    //     bw_found = 100;
    //     if coder.target('MATLAB')
    //        warning(['UAV-R: No bandwidth could be calculated ',...
    //             'from the start and stop frequencies of the ',...
    //             'identified pulses. A bandwidth of 100 Hz ',...
    //             'will be used for continued informed search.'])
    //     end
    // end
    // Fix the bandwidth in the priori to +/- 100 Hz.
    // Here is where we update the stats. These methods of updates
    // could be improved in the future.
    // wfm.ps_pre.t_p; %tp doesn't change. We assume it is stationary
    if (pulselist.size(1) == 1) {
      bool guard1{false};
      //  Happens if K=1
      // We only have one pulse to reference, so we need to check
      // the prior pulse too.
      guard1 = false;
      if (ps_pre->pl.size(1) != 0) {
        i = ps_pre->pl.size(1);
        loop_ub_tmp = ps_pre->pl.size(1);
        if ((loop_ub_tmp < 1) || (loop_ub_tmp > i)) {
          rtDynamicBoundsError(loop_ub_tmp, 1, i, ab_emlrtBCI);
        }
        x_tmp = ps_pre->pl[loop_ub_tmp - 1].t_0;
        if (!std::isnan(x_tmp)) {
          varargin_1.set_size(1, 1);
          varargin_1[0] = pulselist[0].t_0 - x_tmp;
          // recent_tip =
          // pulselist.t_0-ps_pre.pl(end).t_0;%Conflicts with
          // Coder. Needed the (1) callout
          // There could be a case where the last segment and this
          // segement identified the same pulse. In this case
          // recent_tip will be very small. In this case, we just
          // say we learned nothing about t_ip in this segment.
          c_varargin_1.set_size(1, 1);
          c_varargin_1[0] = (varargin_1[0] < ps_pre->t_ipu + ps_pre->t_ipj);
          y = ((c_varargin_1.size(0) != 0) && (c_varargin_1.size(1) != 0));
          if (y) {
            input_sizes_idx_0 = c_varargin_1.size(0) * c_varargin_1.size(1);
            if (input_sizes_idx_0 > 2147483646) {
              coder::check_forloop_overflow_error();
            }
            loop_ub = 0;
            exitg1 = false;
            while ((!exitg1) && (loop_ub <= input_sizes_idx_0 - 1)) {
              if (!c_varargin_1[loop_ub]) {
                y = false;
                exitg1 = true;
              } else {
                loop_ub++;
              }
            }
          }
          if (y) {
            varargin_1.set_size(1, 1);
            varargin_1[0] = rtNaN;
          }
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard1) {
        // No new information because we don't know the last
        // pulse time
        varargin_1.set_size(1, 1);
        varargin_1[0] = rtNaN;
      }
    } else {
      b_varargin_1.set_size(varargin_1.size(1), varargin_1.size(0));
      input_sizes_idx_0 = varargin_1.size(0);
      for (i = 0; i < input_sizes_idx_0; i++) {
        loop_ub = varargin_1.size(1);
        for (loop_ub_tmp = 0; loop_ub_tmp < loop_ub; loop_ub_tmp++) {
          b_varargin_1[loop_ub_tmp + b_varargin_1.size(0) * i] =
              varargin_1[i + varargin_1.size(0) * loop_ub_tmp];
        }
      }
      coder::diff(b_varargin_1, varargin_1);
      if (varargin_1.size(1) > 1) {
        rtDimSizeGeqError(1, varargin_1.size(1), g_emlrtECI);
      }
    }
    // Do a check here to make sure the new tip isn't a huge change.
    // This could potentially happen if we are in the K = 1 case and
    // the block getting processed contained two pulses, with the
    // latter pulse getting identified/detected. The lines above
    // would look back to the last identified pulse and it might be
    // 2*tip back in time, producing a very large recenttip values.
    // If something like this happens, we ignore it so it doesn't
    // affect our new tip estimates.
    x_tmp = 1.5 * ps_pre->t_ip;
    c_varargin_1.set_size(varargin_1.size(0), varargin_1.size(1));
    loop_ub_tmp = varargin_1.size(0) * varargin_1.size(1);
    for (i = 0; i < loop_ub_tmp; i++) {
      c_varargin_1[i] = (varargin_1[i] > x_tmp);
    }
    y = ((c_varargin_1.size(0) != 0) && (c_varargin_1.size(1) != 0));
    if (y) {
      input_sizes_idx_0 = c_varargin_1.size(0) * c_varargin_1.size(1);
      if (input_sizes_idx_0 > 2147483646) {
        coder::check_forloop_overflow_error();
      }
      loop_ub = 0;
      exitg1 = false;
      while ((!exitg1) && (loop_ub <= input_sizes_idx_0 - 1)) {
        if (!c_varargin_1[loop_ub]) {
          y = false;
          exitg1 = true;
        } else {
          loop_ub++;
        }
      }
    }
    if (y) {
      x_tmp = 0.5 * ps_pre->t_ip;
      c_varargin_1.set_size(varargin_1.size(0), varargin_1.size(1));
      for (i = 0; i < loop_ub_tmp; i++) {
        c_varargin_1[i] = (varargin_1[i] < x_tmp);
      }
      y = ((c_varargin_1.size(0) != 0) && (c_varargin_1.size(1) != 0));
      if (y) {
        input_sizes_idx_0 = c_varargin_1.size(0) * c_varargin_1.size(1);
        if (input_sizes_idx_0 > 2147483646) {
          coder::check_forloop_overflow_error();
        }
        loop_ub = 0;
        exitg1 = false;
        while ((!exitg1) && (loop_ub <= input_sizes_idx_0 - 1)) {
          if (!c_varargin_1[loop_ub]) {
            y = false;
            exitg1 = true;
          } else {
            loop_ub++;
          }
        }
      }
      if (y) {
        varargin_1.set_size(1, 1);
        varargin_1[0] = rtNaN;
      }
    }
    //                  %Only update time parameters if we are in tracking mode.
    //                  If we %aren't, we may have identified somethign that
    //                  isn't a pulse if strcmp(obj.mode,'T') ||
    //                  strcmp(ps_pre.mode,'T')
    //                      obj.t_ip  =
    //                      mean([recent_tip;ps_pre.t_ip],'omitnan'); obj.t_ipu
    //                      = ps_pre.t_ipu; %Don't update this because it can
    //                      get too
    //                      narrow.%mean([3*std(diff(t_found));wfm.ps_pre.t_ipu]);
    //                      obj.t_ipj = ps_pre.t_ipj;
    //                  end
    //                  fp_pos     =
    //                  freq_found;%nanmean([freq_found;wfm.ps_pre.fp]);%Previous
    //                  fc may be nan if unknown obj.fp     = fp_pos; obj.fstart
    //                  = fp_pos-bw_found/2; obj.fend   = fp_pos+bw_found/2;
    if ((varargin_1.size(0) != 0) && (varargin_1.size(1) != 0)) {
      input_sizes_idx_0 = varargin_1.size(0);
    } else {
      input_sizes_idx_0 = 0;
    }
    d_varargin_1.set_size(input_sizes_idx_0 + 1);
    for (i = 0; i < input_sizes_idx_0; i++) {
      d_varargin_1[i] = varargin_1[i];
    }
    d_varargin_1[input_sizes_idx_0] = ps_pre->t_ip;
    x_tmp = coder::combineVectorElements(d_varargin_1, input_sizes_idx_0);
    t_ip = x_tmp / static_cast<double>(input_sizes_idx_0);
    t_ipu = ps_pre->t_ipu;
    // Don't update this because it can get too
    // narrow.%mean([3*std(diff(t_found));wfm.ps_pre.t_ipu]);
    t_ipj = ps_pre->t_ipj;
  }
}

pulsestats *pulsestats::c_init(double tp, double tip, double tipu, double tipj,
                               double b_fp, double b_fstart, double b_fend,
                               const double b_tmplt[2],
                               const coder::array<char, 2U> &b_mode,
                               const coder::array<c_struct_T, 2U> &b_pl,
                               const coder::array<c_struct_T, 2U> &b_clst,
                               const coder::array<bool, 2U> &b_cmsk,
                               const coder::array<double, 2U> &b_cpki)
{
  pulsestats *obj;
  coder::array<c_struct_T, 2U> val;
  int loop_ub;
  char out;
  obj = this;
  // PULSESTATS Constructs an instance of this class
  //
  // INPUTS:
  //    tp      1x1     Duration of pulse (second)
  //    tip     1x1     Inter-pulse time (seconds)
  //    tipu    1x1     Inter-pulse time uncertainty (seconds)
  //    tipj    1x1     Inter-pulse time jitter (deviations from means)
  //    (seconds) fp      1x1     Pulses' center frequency (Hz) (if known)
  //    fstart  1x1     Lower frequency bound pulses' center frequency (Hz) (if
  //    known) fend    1x1     Upper frequency bound pulses' center frequency
  //    (Hz) (if known) tmplt   1xn     Pulse template. See properies for
  //                    definition. Usually set to [1 1] for
  //                    square pulse.
  //    pl      px1     Vector of pulse objects in waveform (if
  //                    known). If unknown enter a blank pulse made
  //                    from the contstructor "pulse";
  //  Note: Unknown inputs should be set to NaN.
  //
  // OUTPUTS:
  //    pulsestats object
  //
  //             %%
  if (std::isnan(tp) || std::isnan(tip) || std::isnan(tipu) ||
      std::isnan(tipj)) {
    rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
  }
  obj->t_p = tp;
  obj->t_ip = tip;
  obj->t_ipu = tipu;
  obj->t_ipj = tipj;
  obj->fp = b_fp;
  obj->fstart = b_fstart;
  obj->fend = b_fend;
  obj->tmplt[0] = b_tmplt[0];
  obj->tmplt[1] = b_tmplt[1];
  if (b_mode.size(1) != 1) {
    rtErrorWithMessageID(b_mode.size(1), 1, 2, k_emlrtRTEI.fName,
                         k_emlrtRTEI.lineNo);
  } else {
    out = b_mode[0];
  }
  obj->mode = out;
  // The following are variable sized properties. To tell coder
  // that they may vary setup as a local variable size variable
  // first, then set.
  // Instructions on
  // https://www.mathworks.com/help/simulink/ug/how-working-with-matlab-classes-is-different-for-code-generation.html
  // localMode = mode;
  // coder.varsize('localMode',[1 inf],[0 1]); %dims 0 if fixed, 1 if variable
  if (b_cpki.size(1) > 1) {
    rtDimSizeGeqError(1, b_cpki.size(1), emlrtECI);
  }
  // Tell coder these are variable size.
  // Now actually assign them
  coder::internal::validator_check_size(b_pl, val);
  obj->pl.set_size(1, val.size(1));
  loop_ub = val.size(1);
  for (int i{0}; i < loop_ub; i++) {
    obj->pl[i] = val[i];
  }
  obj->clst.set_size(b_clst.size(0), b_clst.size(1));
  loop_ub = b_clst.size(0) * b_clst.size(1);
  for (int i{0}; i < loop_ub; i++) {
    obj->clst[i] = b_clst[i];
  }
  obj->cmsk.set_size(b_cmsk.size(0), b_cmsk.size(1));
  loop_ub = b_cmsk.size(0) * b_cmsk.size(1);
  for (int i{0}; i < loop_ub; i++) {
    obj->cmsk[i] = b_cmsk[i];
  }
  obj->cpki.set_size(b_cpki.size(0), b_cpki.size(1));
  loop_ub = b_cpki.size(0) * b_cpki.size(1);
  for (int i{0}; i < loop_ub; i++) {
    obj->cpki[i] = b_cpki[i];
  }
  return obj;
}

pulsestats *pulsestats::init(double tp, double tip, double tipu, double tipj,
                             const c_struct_T &b_pl, const c_struct_T &b_clst)
{
  pulsestats *obj;
  coder::array<c_struct_T, 2U> c_pl;
  coder::array<c_struct_T, 2U> val;
  int loop_ub;
  obj = this;
  // PULSESTATS Constructs an instance of this class
  //
  // INPUTS:
  //    tp      1x1     Duration of pulse (second)
  //    tip     1x1     Inter-pulse time (seconds)
  //    tipu    1x1     Inter-pulse time uncertainty (seconds)
  //    tipj    1x1     Inter-pulse time jitter (deviations from means)
  //    (seconds) fp      1x1     Pulses' center frequency (Hz) (if known)
  //    fstart  1x1     Lower frequency bound pulses' center frequency (Hz) (if
  //    known) fend    1x1     Upper frequency bound pulses' center frequency
  //    (Hz) (if known) tmplt   1xn     Pulse template. See properies for
  //                    definition. Usually set to [1 1] for
  //                    square pulse.
  //    pl      px1     Vector of pulse objects in waveform (if
  //                    known). If unknown enter a blank pulse made
  //                    from the contstructor "pulse";
  //  Note: Unknown inputs should be set to NaN.
  //
  // OUTPUTS:
  //    pulsestats object
  //
  //             %%
  if (std::isnan(tp) || std::isnan(tip) || std::isnan(tipu) ||
      std::isnan(tipj)) {
    rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
  }
  obj->t_p = tp;
  obj->t_ip = tip;
  obj->t_ipu = tipu;
  obj->t_ipj = tipj;
  obj->fp = 0.0;
  obj->fstart = 0.0;
  obj->fend = 0.0;
  obj->tmplt[0] = 1.0;
  obj->tmplt[1] = 1.0;
  obj->mode = 'D';
  // The following are variable sized properties. To tell coder
  // that they may vary setup as a local variable size variable
  // first, then set.
  // Instructions on
  // https://www.mathworks.com/help/simulink/ug/how-working-with-matlab-classes-is-different-for-code-generation.html
  // localMode = mode;
  // coder.varsize('localMode',[1 inf],[0 1]); %dims 0 if fixed, 1 if variable
  // Tell coder these are variable size.
  // Now actually assign them
  c_pl.set_size(1, 1);
  c_pl[0] = b_pl;
  coder::internal::validator_check_size(c_pl, val);
  obj->pl.set_size(1, val.size(1));
  loop_ub = val.size(1);
  for (int i{0}; i < loop_ub; i++) {
    obj->pl[i] = val[i];
  }
  obj->clst.set_size(1, 1);
  obj->clst[0] = b_clst;
  obj->cmsk.set_size(0, 0);
  obj->cpki.set_size(0, 0);
  return obj;
}

pulsestats *pulsestats::init(double tp, double tip, double tipu, double tipj,
                             double b_fp, const c_struct_T &b_pl,
                             const c_struct_T &b_clst)
{
  pulsestats *obj;
  coder::array<c_struct_T, 2U> c_pl;
  coder::array<c_struct_T, 2U> val;
  int loop_ub;
  obj = this;
  // PULSESTATS Constructs an instance of this class
  //
  // INPUTS:
  //    tp      1x1     Duration of pulse (second)
  //    tip     1x1     Inter-pulse time (seconds)
  //    tipu    1x1     Inter-pulse time uncertainty (seconds)
  //    tipj    1x1     Inter-pulse time jitter (deviations from means)
  //    (seconds) fp      1x1     Pulses' center frequency (Hz) (if known)
  //    fstart  1x1     Lower frequency bound pulses' center frequency (Hz) (if
  //    known) fend    1x1     Upper frequency bound pulses' center frequency
  //    (Hz) (if known) tmplt   1xn     Pulse template. See properies for
  //                    definition. Usually set to [1 1] for
  //                    square pulse.
  //    pl      px1     Vector of pulse objects in waveform (if
  //                    known). If unknown enter a blank pulse made
  //                    from the contstructor "pulse";
  //  Note: Unknown inputs should be set to NaN.
  //
  // OUTPUTS:
  //    pulsestats object
  //
  //             %%
  if (std::isnan(tp) || std::isnan(tip) || std::isnan(tipu) ||
      std::isnan(tipj)) {
    rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
  }
  obj->t_p = tp;
  obj->t_ip = tip;
  obj->t_ipu = tipu;
  obj->t_ipj = tipj;
  obj->fp = b_fp;
  obj->fstart = 0.0;
  obj->fend = 0.0;
  obj->tmplt[0] = 1.0;
  obj->tmplt[1] = 1.0;
  obj->mode = 'D';
  // The following are variable sized properties. To tell coder
  // that they may vary setup as a local variable size variable
  // first, then set.
  // Instructions on
  // https://www.mathworks.com/help/simulink/ug/how-working-with-matlab-classes-is-different-for-code-generation.html
  // localMode = mode;
  // coder.varsize('localMode',[1 inf],[0 1]); %dims 0 if fixed, 1 if variable
  // Tell coder these are variable size.
  // Now actually assign them
  c_pl.set_size(1, 1);
  c_pl[0] = b_pl;
  coder::internal::validator_check_size(c_pl, val);
  obj->pl.set_size(1, val.size(1));
  loop_ub = val.size(1);
  for (int i{0}; i < loop_ub; i++) {
    obj->pl[i] = val[i];
  }
  obj->clst.set_size(1, 1);
  obj->clst[0] = b_clst;
  obj->cmsk.set_size(1, 1);
  obj->cmsk[0] = false;
  obj->cpki.set_size(1, 1);
  obj->cpki[0] = rtNaN;
  return obj;
}

void pulsestats::updateposteriori(const pulsestats *ps_pre,
                                  const coder::array<c_struct_T, 2U> &pulselist)
{
  static rtBoundsCheckInfo cb_emlrtBCI{
      -1,                            // iFirst
      -1,                            // iLast
      246,                           // lineNo
      25,                            // colNo
      "ps_pre.pl",                   // aName
      "pulsestats/updateposteriori", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "pulsestats.m", // pName
      0               // checkKind
  };
  coder::array<double, 2U> b_varargin_1;
  coder::array<double, 2U> varargin_1;
  coder::array<double, 1U> d_varargin_1;
  coder::array<bool, 2U> e_varargin_1;
  //              %UPDATEPOSTERIORI updates the posteriori pulse statistics
  //              object using the new pulse list (input), prior pulse stats
  //              and the waveforms power spectral density vector. This
  //              methods is typically going to be called on a posteriori pulse
  //              stats object after a waveform has been processed and a set
  //              of candidate pulses found. This method uses those pulses and
  //              the prior information about the pulses to update the
  //              posteriori pulse stats.
  //
  //              The pulse contained in the waveform's ps_pos
  //              property is not used directly so that the caller can decide
  //              which pulses on which to focus the posteriori updates
  //
  //  updateType    What parts of the pulsestats to update. Valid
  //                options are 'time', 'freq', 'timeandfreq'. The
  //                'time' option will only update the interpulse
  //                time statistics. The 'freq' option will only
  //                update the frequency stats. The 'timeandfreq'
  //                option will update both.
  //
  if (pulselist.size(1) != 0) {
    double d;
    double freq_found;
    int c_varargin_1;
    int i;
    int loop_ub;
    int loop_ub_tmp;
    bool exitg1;
    bool y;
    coder::internal::d_horzcatStructList(pulselist, varargin_1);
    //  pulselist(:).t_0]'
    coder::internal::b_horzcatStructList(pulselist, b_varargin_1);
    c_varargin_1 = b_varargin_1.size(0) * b_varargin_1.size(1);
    d_varargin_1 = b_varargin_1.reshape(c_varargin_1);
    freq_found = coder::combineVectorElements(d_varargin_1, c_varargin_1);
    freq_found /= static_cast<double>(c_varargin_1);
    // pulselist(:).fp
    // Create a vector of bandwidths from the pulselist
    // fEnds   = [pulselist.fend];
    // fStarts = [pulselist.fstart];
    // bw_found = 2*(mean(fEnds,'all','omitnan')-mean(fStarts,'all','omitnan'));
    // if isempty(bw_found)
    //     bw_found = 100;
    //     if coder.target('MATLAB')
    //        warning(['UAV-R: No bandwidth could be calculated ',...
    //             'from the start and stop frequencies of the ',...
    //             'identified pulses. A bandwidth of 100 Hz ',...
    //             'will be used for continued informed search.'])
    //     end
    // end
    // Fix the bandwidth in the priori to +/- 100 Hz.
    // Here is where we update the stats. These methods of updates
    // could be improved in the future.
    // wfm.ps_pre.t_p; %tp doesn't change. We assume it is stationary
    if (pulselist.size(1) == 1) {
      bool guard1{false};
      //  Happens if K=1
      // We only have one pulse to reference, so we need to check
      // the prior pulse too.
      guard1 = false;
      if (ps_pre->pl.size(1) != 0) {
        i = ps_pre->pl.size(1);
        loop_ub_tmp = ps_pre->pl.size(1);
        if ((loop_ub_tmp < 1) || (loop_ub_tmp > i)) {
          rtDynamicBoundsError(loop_ub_tmp, 1, i, ab_emlrtBCI);
        }
        if (!std::isnan(ps_pre->pl[loop_ub_tmp - 1].t_0)) {
          varargin_1.set_size(1, 1);
          i = ps_pre->pl.size(1);
          loop_ub_tmp = ps_pre->pl.size(1);
          if ((loop_ub_tmp < 1) || (loop_ub_tmp > i)) {
            rtDynamicBoundsError(loop_ub_tmp, 1, i, cb_emlrtBCI);
          }
          varargin_1[0] = pulselist[0].t_0 - ps_pre->pl[loop_ub_tmp - 1].t_0;
          // recent_tip =
          // pulselist.t_0-ps_pre.pl(end).t_0;%Conflicts with
          // Coder. Needed the (1) callout
          // There could be a case where the last segment and this
          // segement identified the same pulse. In this case
          // recent_tip will be very small. In this case, we just
          // say we learned nothing about t_ip in this segment.
          e_varargin_1.set_size(1, 1);
          e_varargin_1[0] = (varargin_1[0] < ps_pre->t_ipu + ps_pre->t_ipj);
          y = ((e_varargin_1.size(0) != 0) && (e_varargin_1.size(1) != 0));
          if (y) {
            c_varargin_1 = e_varargin_1.size(0) * e_varargin_1.size(1);
            if (c_varargin_1 > 2147483646) {
              coder::check_forloop_overflow_error();
            }
            loop_ub = 0;
            exitg1 = false;
            while ((!exitg1) && (loop_ub <= c_varargin_1 - 1)) {
              if (!e_varargin_1[loop_ub]) {
                y = false;
                exitg1 = true;
              } else {
                loop_ub++;
              }
            }
          }
          if (y) {
            varargin_1.set_size(1, 1);
            varargin_1[0] = rtNaN;
          }
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard1) {
        // No new information because we don't know the last
        // pulse time
        varargin_1.set_size(1, 1);
        varargin_1[0] = rtNaN;
      }
    } else {
      b_varargin_1.set_size(varargin_1.size(1), varargin_1.size(0));
      c_varargin_1 = varargin_1.size(0);
      for (i = 0; i < c_varargin_1; i++) {
        loop_ub = varargin_1.size(1);
        for (loop_ub_tmp = 0; loop_ub_tmp < loop_ub; loop_ub_tmp++) {
          b_varargin_1[loop_ub_tmp + b_varargin_1.size(0) * i] =
              varargin_1[i + varargin_1.size(0) * loop_ub_tmp];
        }
      }
      coder::diff(b_varargin_1, varargin_1);
      if (varargin_1.size(1) > 1) {
        rtDimSizeGeqError(1, varargin_1.size(1), g_emlrtECI);
      }
    }
    // Do a check here to make sure the new tip isn't a huge change.
    // This could potentially happen if we are in the K = 1 case and
    // the block getting processed contained two pulses, with the
    // latter pulse getting identified/detected. The lines above
    // would look back to the last identified pulse and it might be
    // 2*tip back in time, producing a very large recenttip values.
    // If something like this happens, we ignore it so it doesn't
    // affect our new tip estimates.
    d = 1.5 * ps_pre->t_ip;
    e_varargin_1.set_size(varargin_1.size(0), varargin_1.size(1));
    loop_ub_tmp = varargin_1.size(0) * varargin_1.size(1);
    for (i = 0; i < loop_ub_tmp; i++) {
      e_varargin_1[i] = (varargin_1[i] > d);
    }
    y = ((e_varargin_1.size(0) != 0) && (e_varargin_1.size(1) != 0));
    if (y) {
      c_varargin_1 = e_varargin_1.size(0) * e_varargin_1.size(1);
      if (c_varargin_1 > 2147483646) {
        coder::check_forloop_overflow_error();
      }
      loop_ub = 0;
      exitg1 = false;
      while ((!exitg1) && (loop_ub <= c_varargin_1 - 1)) {
        if (!e_varargin_1[loop_ub]) {
          y = false;
          exitg1 = true;
        } else {
          loop_ub++;
        }
      }
    }
    if (y) {
      d = 0.5 * ps_pre->t_ip;
      e_varargin_1.set_size(varargin_1.size(0), varargin_1.size(1));
      for (i = 0; i < loop_ub_tmp; i++) {
        e_varargin_1[i] = (varargin_1[i] < d);
      }
      y = ((e_varargin_1.size(0) != 0) && (e_varargin_1.size(1) != 0));
      if (y) {
        c_varargin_1 = e_varargin_1.size(0) * e_varargin_1.size(1);
        if (c_varargin_1 > 2147483646) {
          coder::check_forloop_overflow_error();
        }
      }
    } else {
      //                  %Only update time parameters if we are in tracking
      //                  mode. If we %aren't, we may have identified somethign
      //                  that isn't a pulse if strcmp(obj.mode,'T') ||
      //                  strcmp(ps_pre.mode,'T')
      //                      obj.t_ip  =
      //                      mean([recent_tip;ps_pre.t_ip],'omitnan');
      //                      obj.t_ipu = ps_pre.t_ipu; %Don't update this
      //                      because it can get too
      //                      narrow.%mean([3*std(diff(t_found));wfm.ps_pre.t_ipu]);
      //                      obj.t_ipj = ps_pre.t_ipj;
      //                  end
      //                  fp_pos     =
      //                  freq_found;%nanmean([freq_found;wfm.ps_pre.fp]);%Previous
      //                  fc may be nan if unknown obj.fp     = fp_pos;
      //                  obj.fstart = fp_pos-bw_found/2;
      //                  obj.fend   = fp_pos+bw_found/2;
    }
    // nanmean([freq_found;wfm.ps_pre.fp]);%Previous fc may be nan if unknown
    fp = freq_found;
    fstart = freq_found - 100.0;
    fend = freq_found + 100.0;
  }
}

// End of code generation (pulsestats.cpp)
