//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// uavrt_detection.cpp
//
// Code generation for function 'uavrt_detection'
//

// Include files
#include "uavrt_detection.h"
#include "AsyncBuffer.h"
#include "AsyncBuffercgHelper.h"
#include "DetectorConfig.h"
#include "UDPReceiver.h"
#include "UDPSender.h"
#include "all.h"
#include "channelreceiver.h"
#include "combineVectorElements.h"
#include "controlreceiver.h"
#include "datetime.h"
#include "diff.h"
#include "eml_int_forloop_overflow_check.h"
#include "feof.h"
#include "fgetl.h"
#include "fileManager.h"
#include "find.h"
#include "fseek.h"
#include "ftell.h"
#include "fwrite.h"
#include "horzcatStructList.h"
#include "ifWhileCond.h"
#include "indexShapeCheck.h"
#include "lower.h"
#include "makepulsestruc.h"
#include "mod.h"
#include "pause.h"
#include "pulseOut.h"
#include "pulsestats.h"
#include "ref.h"
#include "ros2node.h"
#include "ros2publisher.h"
#include "rt_nonfinite.h"
#include "str2double.h"
#include "str2matrix.h"
#include "strcmp.h"
#include "string1.h"
#include "strtok.h"
#include "threshold.h"
#include "tic.h"
#include "toc.h"
#include "uavrt_detection_data.h"
#include "uavrt_detection_initialize.h"
#include "uavrt_detection_internal_types.h"
#include "uavrt_detection_rtwutil.h"
#include "uavrt_detection_types.h"
#include "uavrt_interfaces_PulseStruct.h"
#include "validate_print_arguments.h"
#include "validator_check_size.h"
#include "waveform.h"
#include "waveformcopy.h"
#include "wfmstft.h"
#include "wgn.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"
#include "mlros2_pub.h"
#include "stdio.h"
#include "time.h"
#include "unistd.h"
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <stdexcept>
#include <string>

// Function Declarations
static void b_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum);

static void b_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void c_rtErrorWithMessageID(const char *aFcnName, int aLineNum);

static void checkcommand(const coder::array<signed char, 2U> &cmdReceived,
                         coder::array<char, 2U> &currentState);

static void
interleaveComplexVector(const coder::array<creal32_T, 1U> &complexDataIn,
                        coder::array<float, 1U> &interleaveDataOut);

static void rtDimSizeEqError(const int aDim2, const rtEqualityCheckInfo &aInfo);

static float rt_hypotf_snf(float u0, float u1);

static void
updatebufferreadvariables(const coder::b_captured_var &Config,
                          const coder::c_captured_var &stftOverlapFraction,
                          coder::c_captured_var &overlapSamples,
                          coder::c_captured_var &sampsForKPulses,
                          const pulsestats *ps_input);

static void updateconfig(coder::b_captured_var &Config,
                         const coder::captured_var &configPath);

// Function Definitions
static void b_rtErrorWithMessageID(const char *r, const char *aFcnName,
                                   int aLineNum)
{
  std::stringstream outStream;
  ((outStream << "Value must be less than ") << r) << ".";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

static void b_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Value must be positive.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

static void c_rtErrorWithMessageID(const char *aFcnName, int aLineNum)
{
  std::stringstream outStream;
  outStream << "Value must be nonnegative.";
  outStream << "\n";
  ((((outStream << "Error in ") << aFcnName) << " (line ") << aLineNum) << ")";
  throw std::runtime_error(outStream.str());
}

static void checkcommand(const coder::array<signed char, 2U> &cmdReceived,
                         coder::array<char, 2U> &currentState)
{
  coder::array<bool, 2U> b_cmdReceived;
  // This function is designed to check the incoming command and decide what to
  // do based on the received command and the current state
  if ((cmdReceived.size(0) != 0) && (cmdReceived.size(1) != 0)) {
    int b;
    int k;
    int loop_ub_tmp;
    bool exitg1;
    bool y;
    b_cmdReceived.set_size(cmdReceived.size(0), cmdReceived.size(1));
    loop_ub_tmp = cmdReceived.size(0) * cmdReceived.size(1);
    for (b = 0; b < loop_ub_tmp; b++) {
      b_cmdReceived[b] = (cmdReceived[b] == -1);
    }
    y = ((b_cmdReceived.size(0) != 0) && (b_cmdReceived.size(1) != 0));
    if (y) {
      b = b_cmdReceived.size(0) * b_cmdReceived.size(1);
      if (b > 2147483646) {
        coder::check_forloop_overflow_error();
      }
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= b - 1)) {
        if (!b_cmdReceived[k]) {
          y = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (y) {
      std::printf("Received kill command. \n");
      std::fflush(stdout);
      currentState.set_size(1, 4);
      currentState[0] = 'k';
      currentState[1] = 'i';
      currentState[2] = 'l';
      currentState[3] = 'l';
    } else {
      b_cmdReceived.set_size(cmdReceived.size(0), cmdReceived.size(1));
      for (b = 0; b < loop_ub_tmp; b++) {
        b_cmdReceived[b] = (cmdReceived[b] == 0);
      }
      y = ((b_cmdReceived.size(0) != 0) && (b_cmdReceived.size(1) != 0));
      if (y) {
        b = b_cmdReceived.size(0) * b_cmdReceived.size(1);
        if (b > 2147483646) {
          coder::check_forloop_overflow_error();
        }
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k <= b - 1)) {
          if (!b_cmdReceived[k]) {
            y = false;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }
      if (y) {
        std::printf("Received idle command. \n");
        std::fflush(stdout);
        currentState.set_size(1, 4);
        currentState[0] = 'i';
        currentState[1] = 'd';
        currentState[2] = 'l';
        currentState[3] = 'e';
      } else {
        b_cmdReceived.set_size(cmdReceived.size(0), cmdReceived.size(1));
        for (b = 0; b < loop_ub_tmp; b++) {
          b_cmdReceived[b] = (cmdReceived[b] == 1);
        }
        y = ((b_cmdReceived.size(0) != 0) && (b_cmdReceived.size(1) != 0));
        if (y) {
          b = b_cmdReceived.size(0) * b_cmdReceived.size(1);
          if (b > 2147483646) {
            coder::check_forloop_overflow_error();
          }
          k = 0;
          exitg1 = false;
          while ((!exitg1) && (k <= b - 1)) {
            if (!b_cmdReceived[k]) {
              y = false;
              exitg1 = true;
            } else {
              k++;
            }
          }
        }
        if (y) {
          std::printf("Received run command. \n");
          std::fflush(stdout);
          currentState.set_size(1, 3);
          currentState[0] = 'r';
          currentState[1] = 'u';
          currentState[2] = 'n';
        } else {
          b_cmdReceived.set_size(cmdReceived.size(0), cmdReceived.size(1));
          for (b = 0; b < loop_ub_tmp; b++) {
            b_cmdReceived[b] = (cmdReceived[b] == 2);
          }
          y = ((b_cmdReceived.size(0) != 0) && (b_cmdReceived.size(1) != 0));
          if (y) {
            b = b_cmdReceived.size(0) * b_cmdReceived.size(1);
            if (b > 2147483646) {
              coder::check_forloop_overflow_error();
            }
            k = 0;
            exitg1 = false;
            while ((!exitg1) && (k <= b - 1)) {
              if (!b_cmdReceived[k]) {
                y = false;
                exitg1 = true;
              } else {
                k++;
              }
            }
          }
          if (y) {
            std::printf("Received update config command. \n");
            std::fflush(stdout);
            currentState.set_size(1, 12);
            for (b = 0; b < 12; b++) {
              currentState[b] = cv[b];
            }
          } else {
            b_cmdReceived.set_size(cmdReceived.size(0), cmdReceived.size(1));
            for (b = 0; b < loop_ub_tmp; b++) {
              b_cmdReceived[b] = (cmdReceived[b] == 3);
            }
            y = ((b_cmdReceived.size(0) != 0) && (b_cmdReceived.size(1) != 0));
            if (y) {
              b = b_cmdReceived.size(0) * b_cmdReceived.size(1);
              if (b > 2147483646) {
                coder::check_forloop_overflow_error();
              }
              k = 0;
              exitg1 = false;
              while ((!exitg1) && (k <= b - 1)) {
                if (!b_cmdReceived[k]) {
                  y = false;
                  exitg1 = true;
                } else {
                  k++;
                }
              }
            }
            if (y) {
              std::printf("Received test command. \n");
              std::fflush(stdout);
              currentState.set_size(1, 4);
              currentState[0] = 't';
              currentState[1] = 'e';
              currentState[2] = 's';
              currentState[3] = 't';
            } else {
              // Invalid command. Continue with current state.
            }
          }
        }
      }
    }
  } else {
    // Nothing received. Continue with current state.
  }
}

static void
interleaveComplexVector(const coder::array<creal32_T, 1U> &complexDataIn,
                        coder::array<float, 1U> &interleaveDataOut)
{
  coder::array<float, 2U> dataMatrix;
  coder::array<float, 1U> varargin_1;
  coder::array<float, 1U> varargin_2;
  int loop_ub;
  // This function takes a vector of complex values, and interleaves
  // the real and complex parts to generate a output vector of 2x the
  // number of elements as the number of rows of the input.
  // Enforce column vector
  varargin_1.set_size(complexDataIn.size(0));
  loop_ub = complexDataIn.size(0);
  varargin_2.set_size(complexDataIn.size(0));
  for (int i{0}; i < loop_ub; i++) {
    varargin_1[i] = complexDataIn[i].re;
    varargin_2[i] = complexDataIn[i].im;
  }
  if (varargin_2.size(0) != varargin_1.size(0)) {
    db_rtErrorWithMessageID(rb_emlrtRTEI.fName, rb_emlrtRTEI.lineNo);
  }
  dataMatrix.set_size(2, varargin_1.size(0));
  loop_ub = varargin_1.size(0);
  for (int i{0}; i < loop_ub; i++) {
    dataMatrix[2 * i] = varargin_1[i];
    dataMatrix[2 * i + 1] = varargin_2[i];
  }
  loop_ub = dataMatrix.size(1) << 1;
  interleaveDataOut.set_size(loop_ub);
  for (int i{0}; i < loop_ub; i++) {
    interleaveDataOut[i] = dataMatrix[i];
  }
  // Interleave
}

static void rtDimSizeEqError(const int aDim2, const rtEqualityCheckInfo &aInfo)
{
  std::stringstream outStream;
  ((((((outStream << "Size mismatch error on dimension ") << aInfo.nDims)
      << ": expected ")
     << 1)
    << ", but actual size is ")
   << aDim2)
      << ".";
  outStream << "\n";
  ((((outStream << "Error in ") << aInfo.fName) << " (line ") << aInfo.lineNo)
      << ")";
  throw std::runtime_error(outStream.str());
}

static float rt_hypotf_snf(float u0, float u1)
{
  float a;
  float b;
  float y;
  a = std::abs(u0);
  b = std::abs(u1);
  if (a < b) {
    a /= b;
    y = b * std::sqrt(a * a + 1.0F);
  } else if (a > b) {
    b /= a;
    y = a * std::sqrt(b * b + 1.0F);
  } else if (std::isnan(b)) {
    y = rtNaNF;
  } else {
    y = a * 1.41421354F;
  }
  return y;
}

static void
updatebufferreadvariables(const coder::b_captured_var &Config,
                          const coder::c_captured_var &stftOverlapFraction,
                          coder::c_captured_var &overlapSamples,
                          coder::c_captured_var &sampsForKPulses,
                          const pulsestats *ps_input)
{
  b_waveform X0;
  pulsestats lobj_2;
  double J;
  double M;
  double N;
  double a__2;
  double n_ol;
  unsigned int u;
  unsigned int u1;
  unsigned int u2;
  // This function updates the buffer reading variables as needed by
  // the priori information about the pulse statistics. The segment
  // lengths depend on the interpulse duration and uncertainty
  // parameters.
  // persistent X0
  // if isempty(X0)
  // Build an empty waveform just so that we can calculate number
  // of overlapSamples. This is needed for buffer operations
  // X0 = waveform([], Config.Fs, 0, pulsestats, stftOverlapFraction);
  // WAVEFORM Constructs an instance of this class
  // INPUTS:
  //    x       1xn     Vector of samples
  //    Fs      1x1     Sample frequency (Hz)
  //    t_0     1x1     Time stamp of first element (s)
  // 	ps_pre  1x1     Pulse stats object from previous data (priori)
  //    OLF     1x1     Overlap fraction as decimal (0.5 = 50%
  //                    overlap)
  // OUTPUTS:
  //    obj             The waveform object
  //             %%
  // Flatten input to row
  // Data vector
  // Elements in the data
  X0.Fs = Config.contents.Fs;
  // Sample rate
  // Time stamp of first element
  // Time stamp of last element
  // This is the time when next
  // segment should start to
  // ensure sufficient overlap.
  // Will need to be updated
  // elsewhere.
  // Overlap Fraction for STFT
  // Unknown number of pulses.
  // WFMSTFT Constructs and returns an instance of this class
  //
  // An waveform object must be passed to this construction method
  // so that the constructor has access to the data vector, desired
  // overlap fraction, and priori pulse data, which is used to
  // develop the window sizes.
  // INPUTS:
  //    waveform_obj   A single waveform object with prior
  //                   dependent properties set.
  // OUTPUTS:
  //    obj             A wfmstft object
  //             %%
  //
  // The following are variable sized properties. To tell coder
  // that they may vary setup as a local variable size variable
  // first, then set.
  // Instructions on
  // https://www.mathworks.com/help/simulink/ug/how-working-with-matlab-classes-is-different-for-code-generation.html
  // maxFs*maxpulsewidth
  // Now actually assign them
  // Unknown values but set types
  // Copy over ps_
  // COPY Creates an exact copy of the pulse stats object as a separate object
  lobj_2.b_init(ps_input->t_p, ps_input->t_ip, ps_input->t_ipu, ps_input->t_ipj,
                ps_input->fp, ps_input->fstart, ps_input->fend, ps_input->tmplt,
                ps_input->mode, ps_input->pl, ps_input->clst, ps_input->cmsk,
                ps_input->cpki);
  // ,...
  // obj.thresh);
  // Current stats are same as previous during construction
  // obj.ps_pos = pulsestats();%TESTING FOR CODER - NEEDS TO BE REVERTED BACK TO
  // LAST LINE obj.TimeCorr = TemporalCorrelator(10, 0, 0);%Generate a
  // temporalcorrelator object so coder knows the type of the object
  // SETPRIORIDEPENDENTVARS updates the properties in the
  // waveform that are dependent on properties in a pulsestats
  // object.
  //
  // INPUTS:
  //    obj     waveform object
  //    ps_obj  a pulse stats object
  // OUTPUTS:
  //    None (This method modifies the waveform object properties)
  //
  //             %%
  // WHAT WAS DONE BY THIS METHOD IS NOW DONE BY A METHOD OF THE
  // PULSESTATS CLASS.
  //          function [] = update_posteriori(obj,pulselist)
  //              %UPDATE_POSTERIORI updates the posteriori pulse statistics of
  //              %this waveform object using the new pulse list (input) and the
  //              %apriori stats. The pulse contained in the waveform's ps_pos
  //              %property is not used directly so that the caller can decide
  //              %which pulses on which to focus the posteriori.
  //
  //              t_found    = [pulselist(:).t_0]';
  //              freq_found = mean([pulselist(:).fp],'omitnan');
  //
  //              %Create a vector of bandwidths from the pulselist
  //              bw_found =
  //              2*(mean([pulselist.fend],'omitnan')-mean([pulselist.fstart],'omitnan'));
  //              if isempty(bw_found)
  //                  bw_found = 100;
  //                  if coder.target('MATLAB')
  //                      warning(['UAV-R: No bandwidth could be calculated
  //                      ',...
  //                           'from the start and stop frequencies of the ',...
  //                           'identified pulses. A bandwidth of 100 Hz ',...
  //                           'will be used for continued informed search.'])
  //                  end
  //              end
  //
  //              %Here is where we update the stats. These methods of updates
  //              %could be improved in the future.
  //              %obj.ps_pre.t_p; %tp doesn't change. We assume it is
  //              stationary
  //
  //              if numel(pulselist)==1% Happens if K=1
  //                  %We only have one pulse to reference, so we need to check
  //                  %the prior pulse too.
  //                  if ~isempty(obj.ps_pre.pl) &&
  //                  ~isnan(obj.ps_pre.pl(end).t_0)
  //                      recent_tip = pulselist.t_0-obj.ps_pre.pl(end).t_0;
  //                      %There could be a case where the last segment and this
  //                      %segement identified the same pulse. In this case
  //                      %recent_tip will be very small. In this case, we just
  //                      %say we learned nothing about t_ip in this segment.
  //                      if recent_tip < obj.ps_pre.t_ipu + obj.ps_pre.t_ipJ
  //                          recent_tip = NaN;
  //                      end
  //                  else
  //                      %No new information because we don't know the last
  //                      %pulse time
  //                      recent_tip = NaN;
  //                  end
  //              else
  //                  recent_tip = diff(t_found);
  //              end
  //              %Do a check here to make sure the new tip isn't a huge change.
  //              %This could potentially happen if we are in the K = 1 case and
  //              %the block getting processed contained two pulses, with the
  //              %latter pulse getting identified/detected. The lines above
  //              %would look back to the last identified pulse and it might be
  //              %2*tip back in time, producing a very large recenttip values.
  //              %If something like this happens, we ignore it so it doesn't
  //              %affect our new tip estimates.
  //              if recent_tip > 1.5*obj.ps_pre.t_ip & recent_tip <
  //              0.5*obj.ps_pre.t_ip
  //                  recent_tip = NaN;
  //              end
  //
  //              %Only update time parameters if we are in tracking mode. If we
  //              %aren't, we may have identified somethign that isn't a pulse
  //              if strcmp(obj.ps_pos.mode,'T') || strcmp(obj.ps_pre.mode,'T')
  //                  obj.ps_pos.t_ip  =
  //                  mean([recent_tip;obj.ps_pre.t_ip],'omitnan');
  //                  obj.ps_pos.t_ipu = obj.ps_pre.t_ipu; %Don't update this
  //                  because it can get too
  //                  narrow.%mean([3*std(diff(t_found));obj.ps_pre.t_ipu]);
  //                  obj.ps_pos.t_ipj = obj.ps_pre.t_ipj;
  //              end
  //              fp_pos           =
  //              freq_found;%nanmean([freq_found;obj.ps_pre.fp]);%Previous fc
  //              may be nan if unknown obj.ps_pos.fp    = fp_pos;
  //              obj.ps_pos.fstart = fp_pos-bw_found/2;
  //              obj.ps_pos.fend   = fp_pos+bw_found/2;
  //
  //              obj.ps_pos.psdHist = obj.stft.psd
  //          end
  // GETPRIORIDEPENDENTVARS returns the properties in the
  // waveform that are dependent on prior pulse data estimates. It
  // depends on the waveform properties list Fs etc, as well as
  // pulse stats like t_ip, etc.
  // INPUTS:  ps_obj  1x1 pulse stats object
  // OUTPUTS:  pulse stats object
  // Samples per pulse
  // Number of elements in STFT window
  // Number of elements overlap in STFT window
  // Number of elements in each step of STFT
  // Time of each step of STFT
  // Samples per pulse
  // Number of elements in STFT window
  // Number of elements overlap in STFT window
  // Number of elements in each step of STFT
  // Time of each step of STFT
  // Samples of interpulse duration
  // Baseline interpulse duration in units of STFT windows
  // Interpulse duration deviation from baselines in units of STFT windows
  // Amount of deviation from the PRI means to search
  //              if K ~= 1
  //                  samplesforKpulses = n_ws*(K*(N+M)-2*M)+n_ol;
  //              else
  //                  samplesforKpulses = n_ws*(N+M+J+1)+n_ol;
  //              end
  // See 2022-07-11 for updates to samples def
  // obj.t_nextsegstart  = obj.t_0+(samplesforKpulses)/obj.Fs; %Don't need the
  // overlap here since the next segment starts at samplesforKpulses+n_ol-n_ol
  // from current sample Don't need the overlap here since the next segment
  // starts at samplesforKpulses+n_ol-n_ol from current sample
  //              if isempty(obj.TimeCorr)
  //                  obj.TimeCorr = TemporalCorrelator(N, M, J);
  //              else
  //                  obj.TimeCorr.update(N, M, J);
  //              end
  // end
  // X0.ps_pre = ps_pre;
  // SETPRIORIDEPENDENTVARS updates the properties in the
  // waveform that are dependent on properties in a pulsestats
  // object.
  //
  // INPUTS:
  //    obj     waveform object
  //    ps_obj  a pulse stats object
  // OUTPUTS:
  //    None (This method modifies the waveform object properties)
  //
  //             %%
  // WHAT WAS DONE BY THIS METHOD IS NOW DONE BY A METHOD OF THE
  // PULSESTATS CLASS.
  //          function [] = update_posteriori(obj,pulselist)
  //              %UPDATE_POSTERIORI updates the posteriori pulse statistics of
  //              %this waveform object using the new pulse list (input) and the
  //              %apriori stats. The pulse contained in the waveform's ps_pos
  //              %property is not used directly so that the caller can decide
  //              %which pulses on which to focus the posteriori.
  //
  //              t_found    = [pulselist(:).t_0]';
  //              freq_found = mean([pulselist(:).fp],'omitnan');
  //
  //              %Create a vector of bandwidths from the pulselist
  //              bw_found =
  //              2*(mean([pulselist.fend],'omitnan')-mean([pulselist.fstart],'omitnan'));
  //              if isempty(bw_found)
  //                  bw_found = 100;
  //                  if coder.target('MATLAB')
  //                      warning(['UAV-R: No bandwidth could be calculated
  //                      ',...
  //                           'from the start and stop frequencies of the ',...
  //                           'identified pulses. A bandwidth of 100 Hz ',...
  //                           'will be used for continued informed search.'])
  //                  end
  //              end
  //
  //              %Here is where we update the stats. These methods of updates
  //              %could be improved in the future.
  //              %obj.ps_pre.t_p; %tp doesn't change. We assume it is
  //              stationary
  //
  //              if numel(pulselist)==1% Happens if K=1
  //                  %We only have one pulse to reference, so we need to check
  //                  %the prior pulse too.
  //                  if ~isempty(obj.ps_pre.pl) &&
  //                  ~isnan(obj.ps_pre.pl(end).t_0)
  //                      recent_tip = pulselist.t_0-obj.ps_pre.pl(end).t_0;
  //                      %There could be a case where the last segment and this
  //                      %segement identified the same pulse. In this case
  //                      %recent_tip will be very small. In this case, we just
  //                      %say we learned nothing about t_ip in this segment.
  //                      if recent_tip < obj.ps_pre.t_ipu + obj.ps_pre.t_ipJ
  //                          recent_tip = NaN;
  //                      end
  //                  else
  //                      %No new information because we don't know the last
  //                      %pulse time
  //                      recent_tip = NaN;
  //                  end
  //              else
  //                  recent_tip = diff(t_found);
  //              end
  //              %Do a check here to make sure the new tip isn't a huge change.
  //              %This could potentially happen if we are in the K = 1 case and
  //              %the block getting processed contained two pulses, with the
  //              %latter pulse getting identified/detected. The lines above
  //              %would look back to the last identified pulse and it might be
  //              %2*tip back in time, producing a very large recenttip values.
  //              %If something like this happens, we ignore it so it doesn't
  //              %affect our new tip estimates.
  //              if recent_tip > 1.5*obj.ps_pre.t_ip & recent_tip <
  //              0.5*obj.ps_pre.t_ip
  //                  recent_tip = NaN;
  //              end
  //
  //              %Only update time parameters if we are in tracking mode. If we
  //              %aren't, we may have identified somethign that isn't a pulse
  //              if strcmp(obj.ps_pos.mode,'T') || strcmp(obj.ps_pre.mode,'T')
  //                  obj.ps_pos.t_ip  =
  //                  mean([recent_tip;obj.ps_pre.t_ip],'omitnan');
  //                  obj.ps_pos.t_ipu = obj.ps_pre.t_ipu; %Don't update this
  //                  because it can get too
  //                  narrow.%mean([3*std(diff(t_found));obj.ps_pre.t_ipu]);
  //                  obj.ps_pos.t_ipj = obj.ps_pre.t_ipj;
  //              end
  //              fp_pos           =
  //              freq_found;%nanmean([freq_found;obj.ps_pre.fp]);%Previous fc
  //              may be nan if unknown obj.ps_pos.fp    = fp_pos;
  //              obj.ps_pos.fstart = fp_pos-bw_found/2;
  //              obj.ps_pos.fend   = fp_pos+bw_found/2;
  //
  //              obj.ps_pos.psdHist = obj.stft.psd
  //          end
  // GETPRIORIDEPENDENTVARS returns the properties in the
  // waveform that are dependent on prior pulse data estimates. It
  // depends on the waveform properties list Fs etc, as well as
  // pulse stats like t_ip, etc.
  // INPUTS:  ps_obj  1x1 pulse stats object
  // OUTPUTS:  pulse stats object
  // Samples per pulse
  // Number of elements in STFT window
  // Number of elements overlap in STFT window
  // Number of elements in each step of STFT
  // Time of each step of STFT
  // Samples per pulse
  // Number of elements in STFT window
  // Number of elements overlap in STFT window
  // Number of elements in each step of STFT
  // Time of each step of STFT
  // Samples of interpulse duration
  // Baseline interpulse duration in units of STFT windows
  // Interpulse duration deviation from baselines in units of STFT windows
  // Amount of deviation from the PRI means to search
  //              if K ~= 1
  //                  samplesforKpulses = n_ws*(K*(N+M)-2*M)+n_ol;
  //              else
  //                  samplesforKpulses = n_ws*(N+M+J+1)+n_ol;
  //              end
  // See 2022-07-11 for updates to samples def
  // obj.t_nextsegstart  = obj.t_0+(samplesforKpulses)/obj.Fs; %Don't need the
  // overlap here since the next segment starts at samplesforKpulses+n_ol-n_ol
  // from current sample Don't need the overlap here since the next segment
  // starts at samplesforKpulses+n_ol-n_ol from current sample
  //              if isempty(obj.TimeCorr)
  //                  obj.TimeCorr = TemporalCorrelator(N, M, J);
  //              else
  //                  obj.TimeCorr.update(N, M, J);
  //              end
  // WHAT WAS DONE BY THIS METHOD IS NOW DONE BY A METHOD OF THE
  // PULSESTATS CLASS.
  //          function [] = update_posteriori(obj,pulselist)
  //              %UPDATE_POSTERIORI updates the posteriori pulse statistics of
  //              %this waveform object using the new pulse list (input) and the
  //              %apriori stats. The pulse contained in the waveform's ps_pos
  //              %property is not used directly so that the caller can decide
  //              %which pulses on which to focus the posteriori.
  //
  //              t_found    = [pulselist(:).t_0]';
  //              freq_found = mean([pulselist(:).fp],'omitnan');
  //
  //              %Create a vector of bandwidths from the pulselist
  //              bw_found =
  //              2*(mean([pulselist.fend],'omitnan')-mean([pulselist.fstart],'omitnan'));
  //              if isempty(bw_found)
  //                  bw_found = 100;
  //                  if coder.target('MATLAB')
  //                      warning(['UAV-R: No bandwidth could be calculated
  //                      ',...
  //                           'from the start and stop frequencies of the ',...
  //                           'identified pulses. A bandwidth of 100 Hz ',...
  //                           'will be used for continued informed search.'])
  //                  end
  //              end
  //
  //              %Here is where we update the stats. These methods of updates
  //              %could be improved in the future.
  //              %obj.ps_pre.t_p; %tp doesn't change. We assume it is
  //              stationary
  //
  //              if numel(pulselist)==1% Happens if K=1
  //                  %We only have one pulse to reference, so we need to check
  //                  %the prior pulse too.
  //                  if ~isempty(obj.ps_pre.pl) &&
  //                  ~isnan(obj.ps_pre.pl(end).t_0)
  //                      recent_tip = pulselist.t_0-obj.ps_pre.pl(end).t_0;
  //                      %There could be a case where the last segment and this
  //                      %segement identified the same pulse. In this case
  //                      %recent_tip will be very small. In this case, we just
  //                      %say we learned nothing about t_ip in this segment.
  //                      if recent_tip < obj.ps_pre.t_ipu + obj.ps_pre.t_ipJ
  //                          recent_tip = NaN;
  //                      end
  //                  else
  //                      %No new information because we don't know the last
  //                      %pulse time
  //                      recent_tip = NaN;
  //                  end
  //              else
  //                  recent_tip = diff(t_found);
  //              end
  //              %Do a check here to make sure the new tip isn't a huge change.
  //              %This could potentially happen if we are in the K = 1 case and
  //              %the block getting processed contained two pulses, with the
  //              %latter pulse getting identified/detected. The lines above
  //              %would look back to the last identified pulse and it might be
  //              %2*tip back in time, producing a very large recenttip values.
  //              %If something like this happens, we ignore it so it doesn't
  //              %affect our new tip estimates.
  //              if recent_tip > 1.5*obj.ps_pre.t_ip & recent_tip <
  //              0.5*obj.ps_pre.t_ip
  //                  recent_tip = NaN;
  //              end
  //
  //              %Only update time parameters if we are in tracking mode. If we
  //              %aren't, we may have identified somethign that isn't a pulse
  //              if strcmp(obj.ps_pos.mode,'T') || strcmp(obj.ps_pre.mode,'T')
  //                  obj.ps_pos.t_ip  =
  //                  mean([recent_tip;obj.ps_pre.t_ip],'omitnan');
  //                  obj.ps_pos.t_ipu = obj.ps_pre.t_ipu; %Don't update this
  //                  because it can get too
  //                  narrow.%mean([3*std(diff(t_found));obj.ps_pre.t_ipu]);
  //                  obj.ps_pos.t_ipj = obj.ps_pre.t_ipj;
  //              end
  //              fp_pos           =
  //              freq_found;%nanmean([freq_found;obj.ps_pre.fp]);%Previous fc
  //              may be nan if unknown obj.ps_pos.fp    = fp_pos;
  //              obj.ps_pos.fstart = fp_pos-bw_found/2;
  //              obj.ps_pos.fend   = fp_pos+bw_found/2;
  //
  //              obj.ps_pos.psdHist = obj.stft.psd
  //          end
  // GETPRIORIDEPENDENTVARS returns the properties in the
  // waveform that are dependent on prior pulse data estimates. It
  // depends on the waveform properties list Fs etc, as well as
  // pulse stats like t_ip, etc.
  // INPUTS:  ps_obj  1x1 pulse stats object
  // OUTPUTS:  pulse stats object
  a__2 = std::ceil(ps_input->t_p * X0.Fs);
  // Samples per pulse
  // Number of elements in STFT window
  n_ol = std::floor(stftOverlapFraction.contents * a__2);
  // Number of elements overlap in STFT window
  a__2 -= n_ol;
  // Number of elements in each step of STFT
  // Time of each step of STFT
  N = std::floor(std::ceil(ps_input->t_ip * X0.Fs) / a__2);
  M = std::ceil(std::ceil(ps_input->t_ipu * X0.Fs) / a__2);
  J = std::ceil(std::ceil(ps_input->t_ipj * X0.Fs) / a__2);
  //          overlapWindows  = 2*Config.K*M+1;
  //          overlapSamples	= n_ws*overlapWindows;
  //          %sampsForKPulses = Config.K*n_ws*(N+M+1+1);
  //          sampsForKPulses = n_ws*(Config.K*(N+M)+1+1);
  overlapSamples.contents = a__2 * (2.0 * (Config.contents.K * M + J));
  //          if Config.K~=1
  //              sampsForKPulses = n_ws*(Config.K*(N+M)-2*M)+n_ol;
  //          else
  //              sampsForKPulses = n_ws*(N+M+J)+n_ol;
  //          end
  // See 2022-07-11 for updates to samples def
  sampsForKPulses.contents =
      a__2 * ((Config.contents.K * (N + M) + J) + 1.0) + n_ol;
  if (N < 4.294967296E+9) {
    if (N >= 0.0) {
      u = static_cast<unsigned int>(N);
    } else {
      u = 0U;
    }
  } else if (N >= 4.294967296E+9) {
    u = MAX_uint32_T;
  } else {
    u = 0U;
  }
  if (M < 4.294967296E+9) {
    if (M >= 0.0) {
      u1 = static_cast<unsigned int>(M);
    } else {
      u1 = 0U;
    }
  } else if (M >= 4.294967296E+9) {
    u1 = MAX_uint32_T;
  } else {
    u1 = 0U;
  }
  if (J < 4.294967296E+9) {
    if (J >= 0.0) {
      u2 = static_cast<unsigned int>(J);
    } else {
      u2 = 0U;
    }
  } else if (J >= 4.294967296E+9) {
    u2 = MAX_uint32_T;
  } else {
    u2 = 0U;
  }
  std::printf("Updating buffer read vars|| N: %u, M: %u, J: %u,\n", u, u1, u2);
  std::fflush(stdout);
  a__2 = std::round(sampsForKPulses.contents);
  if (a__2 < 4.294967296E+9) {
    if (a__2 >= 0.0) {
      u = static_cast<unsigned int>(a__2);
    } else {
      u = 0U;
    }
  } else if (a__2 >= 4.294967296E+9) {
    u = MAX_uint32_T;
  } else {
    u = 0U;
  }
  a__2 = std::round(overlapSamples.contents);
  if (a__2 < 4.294967296E+9) {
    if (a__2 >= 0.0) {
      u1 = static_cast<unsigned int>(a__2);
    } else {
      u1 = 0U;
    }
  } else if (a__2 >= 4.294967296E+9) {
    u1 = MAX_uint32_T;
  } else {
    u1 = 0U;
  }
  std::printf(
      "Updating buffer read vars|| sampForKPulses: %u,  overlapSamples: %u,\n",
      u, u1);
  std::fflush(stdout);
}

static void updateconfig(coder::b_captured_var &Config,
                         const coder::captured_var &configPath)
{
  static rtBoundsCheckInfo cb_emlrtBCI{
      -1,                           // iFirst
      -1,                           // iLast
      137,                          // lineNo
      28,                           // colNo
      "rawLine",                    // aName
      "DetectorConfig/setFromFile", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "DetectorConfig.m", // pName
      0                   // checkKind
  };
  static rtBoundsCheckInfo db_emlrtBCI{
      -1,                           // iFirst
      -1,                           // iLast
      168,                          // lineNo
      31,                           // colNo
      "sepByte",                    // aName
      "DetectorConfig/setFromFile", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "DetectorConfig.m", // pName
      0                   // checkKind
  };
  static rtBoundsCheckInfo eb_emlrtBCI{
      -1,                           // iFirst
      -1,                           // iLast
      172,                          // lineNo
      28,                           // colNo
      "lineStr",                    // aName
      "DetectorConfig/setFromFile", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "DetectorConfig.m", // pName
      0                   // checkKind
  };
  static rtBoundsCheckInfo fb_emlrtBCI{
      -1,                           // iFirst
      -1,                           // iLast
      175,                          // lineNo
      55,                           // colNo
      "tabLocs",                    // aName
      "DetectorConfig/setFromFile", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "DetectorConfig.m", // pName
      0                   // checkKind
  };
  static rtBoundsCheckInfo gb_emlrtBCI{
      -1,                           // iFirst
      -1,                           // iLast
      176,                          // lineNo
      63,                           // colNo
      "colonLocation",              // aName
      "DetectorConfig/setFromFile", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "DetectorConfig.m", // pName
      0                   // checkKind
  };
  static rtBoundsCheckInfo hb_emlrtBCI{
      -1,                           // iFirst
      -1,                           // iLast
      221,                          // lineNo
      69,                           // colNo
      "sepByte",                    // aName
      "DetectorConfig/setFromFile", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "DetectorConfig.m", // pName
      0                   // checkKind
  };
  static rtBoundsCheckInfo ib_emlrtBCI{
      -1,                           // iFirst
      -1,                           // iLast
      177,                          // lineNo
      47,                           // colNo
      "lineStr",                    // aName
      "DetectorConfig/setFromFile", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "DetectorConfig.m", // pName
      0                   // checkKind
  };
  static rtBoundsCheckInfo jb_emlrtBCI{
      -1,                           // iFirst
      -1,                           // iLast
      177,                          // lineNo
      74,                           // colNo
      "lineStr",                    // aName
      "DetectorConfig/setFromFile", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "DetectorConfig.m", // pName
      0                   // checkKind
  };
  static rtBoundsCheckInfo kb_emlrtBCI{
      -1,                           // iFirst
      -1,                           // iLast
      176,                          // lineNo
      47,                           // colNo
      "lineStr",                    // aName
      "DetectorConfig/setFromFile", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "DetectorConfig.m", // pName
      0                   // checkKind
  };
  static rtBoundsCheckInfo lb_emlrtBCI{
      -1,                           // iFirst
      -1,                           // iLast
      176,                          // lineNo
      49,                           // colNo
      "lineStr",                    // aName
      "DetectorConfig/setFromFile", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "DetectorConfig.m", // pName
      0                   // checkKind
  };
  static rtBoundsCheckInfo mb_emlrtBCI{
      -1,                           // iFirst
      -1,                           // iLast
      223,                          // lineNo
      69,                           // colNo
      "sepByte",                    // aName
      "DetectorConfig/setFromFile", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "DetectorConfig.m", // pName
      0                   // checkKind
  };
  static rtDoubleCheckInfo
      w_emlrtDCI{
          93,               // lineNo
          34,               // colNo
          "eml_trim_array", // fName
          "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/strfun/"
          "strfind.m", // pName
          4            // checkKind
      };
  static rtRunTimeErrorInfo vc_emlrtRTEI{
      12,               // lineNo
      23,               // colNo
      "mustBePositive", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/validators/"
      "mustBePositive.m" // pName
  };
  static rtRunTimeErrorInfo wc_emlrtRTEI{
      11,                  // lineNo
      24,                  // colNo
      "mustBeNonnegative", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/validators/"
      "mustBeNonnegative.m" // pName
  };
  static rtRunTimeErrorInfo xc_emlrtRTEI{
      18,                     // lineNo
      5,                      // colNo
      "binaryRelopValidator", // fName
      "/Applications/MATLAB_R2023a.app/toolbox/eml/lib/matlab/validators/"
      "private/binaryRelopValidator.m" // pName
  };
  DetectorConfig r;
  coder::rtString filePath;
  coder::array<creal_T, 2U> r1;
  coder::array<double, 2U> sepByte;
  coder::array<double, 2U> val;
  coder::array<int, 2U> colonLocation;
  coder::array<int, 2U> ii;
  coder::array<int, 2U> matches;
  coder::array<unsigned int, 2U> tabLocs;
  coder::array<char, 2U> configType;
  coder::array<char, 2U> configValStr;
  coder::array<char, 2U> lineStr;
  coder::array<bool, 2U> b_lineStr;
  coder::array<bool, 1U> boolOut;
  double configNum;
  double d;
  int i;
  signed char fileid;
  bool done;
  // Add code here to update the variables within the function that are
  // part of the configuration file. Will first need to load the correct
  // file and
  //
  r.init();
  filePath = configPath.contents;
  // fillFromFile Replaces the properties of the instance passed to
  // it with the values specified in the configuration file passed
  // to the function. If multiple entries exist in the config file,
  // use the 'entry' argument to specify which entry to use (1-n).
  // If entry is not specified, the method will use the last entry
  // in the config file.
  //
  // INPUTS:
  //    filePath        String of full path to config file,
  //                    including the file name and extension
  //
  //    entry           Scalar number (1-n) of which entry to use.
  //                    Method will use the last entry if entry is
  //                    not provided. Alternatively, enter -1 to
  //                    use last entry.
  //
  // OUTPUTS:
  //    none (method modifies the properties of the instance)
  //
  fileid = coder::internal::cfopen(filePath.Value);
  if (fileid == -1) {
    char varargin_1[26];
    for (i = 0; i < 25; i++) {
      varargin_1[i] = filePath.Value[i];
    }
    varargin_1[25] = '\x00';
    std::printf("UAV-RT: Error opening configurationfile file with error. "
                "Attempted to find config file at the location %s:\n",
                &varargin_1[0]);
    std::fflush(stdout);
  }
  configNum = 0.0;
  done = false;
  // coder.varsize('sepLine')
  sepByte.set_size(1, 1);
  sepByte[0] = 0.0;
  // First figure out where the separator lines are
  while (!done) {
    // currByte = ftell(fid);
    coder::fgetl(static_cast<double>(fileid), lineStr);
    if (lineStr.size(1) < 1) {
      rtDynamicBoundsError(1, 1, lineStr.size(1), cb_emlrtBCI);
    }
    if (lineStr[0] == '#') {
      // && lineNum~=1
      if (configNum == 0.0) {
        sepByte.set_size(1, 1);
        d = coder::b_ftell(static_cast<double>(fileid));
        sepByte[0] = d;
      } else {
        // sepByte(configNum) = ftell(fid);
        d = coder::b_ftell(static_cast<double>(fileid));
        i = sepByte.size(1);
        sepByte.set_size(1, sepByte.size(1) + 1);
        sepByte[i] = d;
        // Modified for Coder compatibility
      }
      configNum++;
    }
    done = (coder::b_feof(static_cast<double>(fileid)) == 1.0);
  }
  // sepByte(configNum) = ftell(fid);
  d = coder::b_ftell(static_cast<double>(fileid));
  i = sepByte.size(1);
  sepByte.set_size(1, sepByte.size(1) + 1);
  sepByte[i] = d;
  // Modified for Coder compatibility
  // Jump to the line for the entry requested
  if ((static_cast<int>(configNum) < 1) ||
      (static_cast<int>(configNum) > sepByte.size(1))) {
    rtDynamicBoundsError(static_cast<int>(configNum), 1, sepByte.size(1),
                         db_emlrtBCI);
  }
  coder::b_fseek(static_cast<double>(fileid),
                 sepByte[static_cast<int>(configNum) - 1]);
  done = false;
  int exitg1;
  do {
    exitg1 = 0;
    if (!done) {
      coder::fgetl(static_cast<double>(fileid), lineStr);
      if (lineStr.size(1) < 1) {
        rtDynamicBoundsError(1, 1, lineStr.size(1), eb_emlrtBCI);
      }
      if (lineStr[0] != '#') {
        int b_i;
        int match_idx;
        int text_len;
        b_lineStr.set_size(1, lineStr.size(1));
        text_len = lineStr.size(1);
        for (i = 0; i < text_len; i++) {
          b_lineStr[i] = (lineStr[i] == ':');
        }
        coder::eml_find(b_lineStr, ii);
        colonLocation.set_size(1, ii.size(1));
        text_len = ii.size(1);
        for (i = 0; i < text_len; i++) {
          colonLocation[i] = ii[i];
        }
        // note regexp is not supported for code generation
        if (lineStr.size(1) == 0) {
          tabLocs.set_size(1, 0);
        } else {
          text_len = lineStr.size(1);
          matches.set_size(1, lineStr.size(1));
          match_idx = 0;
          if (lineStr.size(1) > 2147483646) {
            coder::check_forloop_overflow_error();
          }
          for (i = 0; i < text_len; i++) {
            if (lineStr[i] == '\t') {
              matches[match_idx] = i + 1;
              match_idx++;
            }
          }
          if (match_idx < 0) {
            rtNonNegativeError(static_cast<double>(match_idx), w_emlrtDCI);
          }
          ii.set_size(1, match_idx);
          if (match_idx > 2147483646) {
            coder::check_forloop_overflow_error();
          }
          for (i = 0; i < match_idx; i++) {
            ii[i] = matches[i];
          }
          tabLocs.set_size(1, ii.size(1));
          text_len = ii.size(1);
          for (i = 0; i < text_len; i++) {
            tabLocs[i] = static_cast<unsigned int>(ii[i]);
          }
        }
        // Thanks to
        // https://www.mathworks.com/matlabcentral/answers/529668-how-do-i-detect-a-tab-character-in-a-line-of-text-read-by-fgetl
        if (tabLocs.size(1) < 1) {
          rtDynamicBoundsError(1, 1, tabLocs.size(1), fb_emlrtBCI);
        }
        // note regexp is not supported for code generation
        if (colonLocation.size(1) < 1) {
          rtDynamicBoundsError(1, 1, colonLocation.size(1), gb_emlrtBCI);
        }
        if (static_cast<double>(colonLocation[0]) - 1.0 < 1.0) {
          text_len = 0;
        } else {
          if (lineStr.size(1) < 1) {
            rtDynamicBoundsError(1, 1, lineStr.size(1), kb_emlrtBCI);
          }
          text_len = colonLocation[0] - 1;
          if ((text_len < 1) || (text_len > lineStr.size(1))) {
            rtDynamicBoundsError(text_len, 1, lineStr.size(1), lb_emlrtBCI);
          }
        }
        configType.set_size(1, text_len);
        for (i = 0; i < text_len; i++) {
          configType[i] = lineStr[i];
        }
        if (tabLocs[0] + 1U > static_cast<unsigned int>(lineStr.size(1))) {
          i = 0;
          b_i = 0;
        } else {
          i = static_cast<int>(tabLocs[0] + 1U);
          if ((i < 1) || (i > lineStr.size(1))) {
            rtDynamicBoundsError(i, 1, lineStr.size(1), ib_emlrtBCI);
          }
          i--;
          if (lineStr.size(1) < 1) {
            rtDynamicBoundsError(lineStr.size(1), 1, lineStr.size(1),
                                 jb_emlrtBCI);
          }
          b_i = lineStr.size(1);
        }
        match_idx = b_i - i;
        configValStr.set_size(1, match_idx);
        for (b_i = 0; b_i < match_idx; b_i++) {
          configValStr[b_i] = lineStr[i + b_i];
        }
        if (coder::internal::g_strcmp(configType)) {
          creal_T x;
          unsigned int in_tmp;
          unsigned int u;
          x = coder::internal::str2double(configValStr);
          d = std::round(x.re);
          if (d < 4.294967296E+9) {
            if (d >= 0.0) {
              in_tmp = static_cast<unsigned int>(d);
              u = in_tmp;
            } else {
              in_tmp = 0U;
              u = 0U;
            }
          } else if (d >= 4.294967296E+9) {
            in_tmp = MAX_uint32_T;
            u = MAX_uint32_T;
          } else {
            in_tmp = 0U;
            u = 0U;
          }
          r.ID = in_tmp;
          if (u <= 0U) {
            b_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
          }
        } else if (coder::internal::h_strcmp(configType)) {
          creal_T x;
          x = coder::internal::str2double(configValStr);
          if (!(x.re >= 0.0)) {
            c_rtErrorWithMessageID(wc_emlrtRTEI.fName, wc_emlrtRTEI.lineNo);
          }
          r.channelCenterFreqMHz = x.re;
        } else if (!coder::internal::i_strcmp(configType)) {
          if (coder::internal::j_strcmp(configType)) {
            creal_T x;
            unsigned short b_in_tmp;
            unsigned short u1;
            x = coder::internal::str2double(configValStr);
            d = std::round(x.re);
            if (d < 65536.0) {
              if (d >= 0.0) {
                b_in_tmp = static_cast<unsigned short>(d);
                u1 = b_in_tmp;
              } else {
                b_in_tmp = 0U;
                u1 = 0U;
              }
            } else if (d >= 65536.0) {
              b_in_tmp = MAX_uint16_T;
              u1 = MAX_uint16_T;
            } else {
              b_in_tmp = 0U;
              u1 = 0U;
            }
            r.portData = b_in_tmp;
            if (u1 <= 0) {
              b_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
            }
          } else if (!coder::internal::k_strcmp(configType)) {
            if (coder::internal::l_strcmp(configType)) {
              creal_T x;
              unsigned short b_in_tmp;
              unsigned short u1;
              x = coder::internal::str2double(configValStr);
              d = std::round(x.re);
              if (d < 65536.0) {
                if (d >= 0.0) {
                  b_in_tmp = static_cast<unsigned short>(d);
                  u1 = b_in_tmp;
                } else {
                  b_in_tmp = 0U;
                  u1 = 0U;
                }
              } else if (d >= 65536.0) {
                b_in_tmp = MAX_uint16_T;
                u1 = MAX_uint16_T;
              } else {
                b_in_tmp = 0U;
                u1 = 0U;
              }
              r.portCntrl = b_in_tmp;
              if (u1 <= 0) {
                b_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
              }
            } else if (coder::internal::m_strcmp(configType)) {
              creal_T x;
              x = coder::internal::str2double(configValStr);
              if (!(x.re > 0.0)) {
                b_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
              }
              r.Fs = x.re;
            } else if (coder::internal::n_strcmp(configType)) {
              creal_T x;
              x = coder::internal::str2double(configValStr);
              r.tagFreqMHz = x.re;
            } else if (coder::internal::o_strcmp(configType)) {
              creal_T x;
              x = coder::internal::str2double(configValStr);
              if (!(x.re > 0.0)) {
                b_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
              }
              r.tp = x.re;
            } else if (coder::internal::p_strcmp(configType)) {
              creal_T x;
              x = coder::internal::str2double(configValStr);
              if (!(x.re > 0.0)) {
                b_rtErrorWithMessageID(vc_emlrtRTEI.fName, vc_emlrtRTEI.lineNo);
              }
              r.tip = x.re;
            } else if (coder::internal::q_strcmp(configType)) {
              creal_T x;
              x = coder::internal::str2double(configValStr);
              if (!(x.re >= 0.0)) {
                c_rtErrorWithMessageID(wc_emlrtRTEI.fName, wc_emlrtRTEI.lineNo);
              }
              r.tipu = x.re;
            } else if (coder::internal::r_strcmp(configType)) {
              creal_T x;
              x = coder::internal::str2double(configValStr);
              if (!(x.re >= 0.0)) {
                c_rtErrorWithMessageID(wc_emlrtRTEI.fName, wc_emlrtRTEI.lineNo);
              }
              r.tipj = x.re;
            } else {
              bool b_bool;
              b_bool = false;
              if ((text_len == 1) && (lineStr[0] == 'K')) {
                b_bool = true;
              }
              if (b_bool) {
                creal_T x;
                unsigned char c_in_tmp;
                unsigned char u2;
                x = coder::internal::str2double(configValStr);
                d = std::round(x.re);
                if (d < 256.0) {
                  if (d >= 0.0) {
                    c_in_tmp = static_cast<unsigned char>(d);
                    u2 = c_in_tmp;
                  } else {
                    c_in_tmp = 0U;
                    u2 = 0U;
                  }
                } else if (d >= 256.0) {
                  c_in_tmp = MAX_uint8_T;
                  u2 = MAX_uint8_T;
                } else {
                  c_in_tmp = 0U;
                  u2 = 0U;
                }
                r.K = c_in_tmp;
                if (u2 <= 0) {
                  b_rtErrorWithMessageID(vc_emlrtRTEI.fName,
                                         vc_emlrtRTEI.lineNo);
                }
              } else if (coder::internal::s_strcmp(configType)) {
                r.opMode.Value.set_size(1, match_idx);
                for (b_i = 0; b_i < match_idx; b_i++) {
                  r.opMode.Value[b_i] = lineStr[i + b_i];
                }
              } else if (coder::internal::t_strcmp(configType)) {
                str2matrix(configValStr, r1);
                val.set_size(r1.size(0), r1.size(1));
                text_len = r1.size(0) * r1.size(1);
                for (i = 0; i < text_len; i++) {
                  val[i] = r1[i].re;
                }
                coder::internal::validator_check_size(val, r.excldFreqs);
              } else if (coder::internal::u_strcmp(configType)) {
                creal_T x;
                x = coder::internal::str2double(configValStr);
                if (!(x.re > 0.0)) {
                  b_rtErrorWithMessageID(vc_emlrtRTEI.fName,
                                         vc_emlrtRTEI.lineNo);
                }
                if (!(x.re < 1.0)) {
                  b_rtErrorWithMessageID("1", xc_emlrtRTEI.fName,
                                         xc_emlrtRTEI.lineNo);
                }
                r.falseAlarmProb = x.re;
              } else if (coder::internal::v_strcmp(configType)) {
                r.dataRecordPath.Value.set_size(1, match_idx);
                for (b_i = 0; b_i < match_idx; b_i++) {
                  r.dataRecordPath.Value[b_i] = lineStr[i + b_i];
                }
              } else if (!coder::internal::w_strcmp(configType)) {
                if (coder::internal::x_strcmp(configType)) {
                  // STR2BOOL Converts a string in to a boolean.
                  //    This function converts a string to a boolean output.
                  //    Valid input strings are '1', '0', 'true', or 'false'.
                  //    The input is case insensitive. If input is invalid, the
                  //    function returns an empty false of size 0x1.
                  //
                  // INPUTS:
                  //    stringIn    string of '1', '0', 'true', or 'false', case
                  //    insensitive.
                  //
                  // OUTPUTS:
                  //    boolOut     boolean
                  //
                  // Author: Michael W. Shafer
                  // Date:   2022-06-21
                  // --------------------------------------------------------------------------
                  lineStr.set_size(1, configValStr.size(1));
                  text_len = configValStr.size(0) * configValStr.size(1) - 1;
                  for (i = 0; i <= text_len; i++) {
                    lineStr[i] = configValStr[i];
                  }
                  coder::lower(lineStr, configValStr);
                  b_bool = false;
                  if ((configValStr.size(1) == 1) && (configValStr[0] == '1')) {
                    b_bool = true;
                  }
                  if (b_bool) {
                    boolOut.set_size(1);
                    boolOut[0] = true;
                  } else {
                    b_bool = false;
                    if ((configValStr.size(1) == 1) &&
                        (configValStr[0] == '0')) {
                      b_bool = true;
                    }
                    if (b_bool) {
                      boolOut.set_size(1);
                      boolOut[0] = false;
                    } else if (coder::internal::y_strcmp(configValStr)) {
                      boolOut.set_size(1);
                      boolOut[0] = true;
                    } else if (coder::internal::ab_strcmp(configValStr)) {
                      boolOut.set_size(1);
                      boolOut[0] = false;
                    } else {
                      boolOut.set_size(0);
                    }
                  }
                  coder::internal::b_validator_check_size(boolOut);
                } else if (coder::internal::bb_strcmp(configType)) {
                  // STR2BOOL Converts a string in to a boolean.
                  //    This function converts a string to a boolean output.
                  //    Valid input strings are '1', '0', 'true', or 'false'.
                  //    The input is case insensitive. If input is invalid, the
                  //    function returns an empty false of size 0x1.
                  //
                  // INPUTS:
                  //    stringIn    string of '1', '0', 'true', or 'false', case
                  //    insensitive.
                  //
                  // OUTPUTS:
                  //    boolOut     boolean
                  //
                  // Author: Michael W. Shafer
                  // Date:   2022-06-21
                  // --------------------------------------------------------------------------
                  lineStr.set_size(1, configValStr.size(1));
                  text_len = configValStr.size(0) * configValStr.size(1) - 1;
                  for (i = 0; i <= text_len; i++) {
                    lineStr[i] = configValStr[i];
                  }
                  coder::lower(lineStr, configValStr);
                  b_bool = false;
                  if ((configValStr.size(1) == 1) && (configValStr[0] == '1')) {
                    b_bool = true;
                  }
                  if (b_bool) {
                    boolOut.set_size(1);
                    boolOut[0] = true;
                  } else {
                    b_bool = false;
                    if ((configValStr.size(1) == 1) &&
                        (configValStr[0] == '0')) {
                      b_bool = true;
                    }
                    if (b_bool) {
                      boolOut.set_size(1);
                      boolOut[0] = false;
                    } else if (coder::internal::y_strcmp(configValStr)) {
                      boolOut.set_size(1);
                      boolOut[0] = true;
                    } else if (coder::internal::ab_strcmp(configValStr)) {
                      boolOut.set_size(1);
                      boolOut[0] = false;
                    } else {
                      boolOut.set_size(0);
                    }
                  }
                  r.startInRunState =
                      coder::internal::b_validator_check_size(boolOut);
                }
              }
            }
          }
        }
        // Stop when we have finished reading this entry.
        if (coder::b_feof(static_cast<double>(fileid)) == 1.0) {
          done = true;
        } else {
          if ((static_cast<int>(static_cast<unsigned int>(configNum) + 1U) <
               1) ||
              (static_cast<int>(static_cast<unsigned int>(configNum) + 1U) >
               sepByte.size(1))) {
            rtDynamicBoundsError(
                static_cast<int>(static_cast<unsigned int>(configNum) + 1U), 1,
                sepByte.size(1), hb_emlrtBCI);
          }
          if (coder::b_ftell(static_cast<double>(fileid)) ==
              sepByte[static_cast<int>(static_cast<unsigned int>(configNum))]) {
            done = true;
          }
        }
      } else if (coder::b_feof(static_cast<double>(fileid)) == 1.0) {
        done = true;
      } else {
        if ((static_cast<int>(static_cast<unsigned int>(configNum) + 1U) < 1) ||
            (static_cast<int>(static_cast<unsigned int>(configNum) + 1U) >
             sepByte.size(1))) {
          rtDynamicBoundsError(
              static_cast<int>(static_cast<unsigned int>(configNum) + 1U), 1,
              sepByte.size(1), mb_emlrtBCI);
        }
        if (coder::b_ftell(static_cast<double>(fileid)) ==
            sepByte[static_cast<int>(static_cast<unsigned int>(configNum))]) {
          done = true;
        }
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  coder::internal::cfclose(static_cast<double>(fileid));
  Config.contents = r;
  // Do we update the tip and tipu or use the ones that were adapted from
  // the previous detections? Probably just use the file. The supervisor
  // will have access to the detected pulses and can update these values if
  // it sees fit.
}

void uavrt_detection()
{
  static coder::dsp::AsyncBuffer asyncDataBuff;
  static coder::dsp::b_AsyncBuffer asyncTimeBuff;
  static coder::dsp::c_AsyncBuffer asyncWriteBuff;
  static rtBoundsCheckInfo cb_emlrtBCI{
      -1,                // iFirst
      -1,                // iLast
      415,               // lineNo
      82,                // colNo
      "timeVector",      // aName
      "uavrt_detection", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "uavrt_detection.m", // pName
      0                    // checkKind
  };
  static rtBoundsCheckInfo db_emlrtBCI{
      -1,                // iFirst
      -1,                // iLast
      431,               // lineNo
      32,                // colNo
      "t",               // aName
      "uavrt_detection", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "uavrt_detection.m", // pName
      0                    // checkKind
  };
  static rtBoundsCheckInfo eb_emlrtBCI{
      -1,                // iFirst
      -1,                // iLast
      593,               // lineNo
      61,                // colNo
      "X.ps_pos.pl",     // aName
      "uavrt_detection", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "uavrt_detection.m", // pName
      0                    // checkKind
  };
  static rtBoundsCheckInfo fb_emlrtBCI{
      -1,                // iFirst
      -1,                // iLast
      598,               // lineNo
      79,                // colNo
      "ps_pre_struc.pl", // aName
      "uavrt_detection", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "uavrt_detection.m", // pName
      0                    // checkKind
  };
  static rtBoundsCheckInfo gb_emlrtBCI{
      -1,                // iFirst
      -1,                // iLast
      604,               // lineNo
      50,                // colNo
      "pulsesToSkip",    // aName
      "uavrt_detection", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "uavrt_detection.m", // pName
      0                    // checkKind
  };
  static rtBoundsCheckInfo hb_emlrtBCI{
      -1,                // iFirst
      -1,                // iLast
      666,               // lineNo
      70,                // colNo
      "X.ps_pos.pl",     // aName
      "uavrt_detection", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "uavrt_detection.m", // pName
      0                    // checkKind
  };
  static rtBoundsCheckInfo ib_emlrtBCI{
      -1,                // iFirst
      -1,                // iLast
      667,               // lineNo
      50,                // colNo
      "pulsesToSkip",    // aName
      "uavrt_detection", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "uavrt_detection.m", // pName
      0                    // checkKind
  };
  static rtDoubleCheckInfo w_emlrtDCI{
      301,               // lineNo
      50,                // colNo
      "uavrt_detection", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "uavrt_detection.m", // pName
      4                    // checkKind
  };
  static rtDoubleCheckInfo x_emlrtDCI{
      301,               // lineNo
      50,                // colNo
      "uavrt_detection", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "uavrt_detection.m", // pName
      1                    // checkKind
  };
  static rtEqualityCheckInfo h_emlrtECI{
      2,                 // nDims
      936,               // lineNo
      13,                // colNo
      "uavrt_detection", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "uavrt_detection.m" // pName
  };
  static rtEqualityCheckInfo i_emlrtECI{
      2,                 // nDims
      824,               // lineNo
      17,                // colNo
      "uavrt_detection", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "uavrt_detection.m" // pName
  };
  static rtEqualityCheckInfo j_emlrtECI{
      2,                 // nDims
      801,               // lineNo
      13,                // colNo
      "uavrt_detection", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "uavrt_detection.m" // pName
  };
  static rtEqualityCheckInfo k_emlrtECI{
      1,                 // nDims
      244,               // lineNo
      14,                // colNo
      "uavrt_detection", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "uavrt_detection.m" // pName
  };
  static rtEqualityCheckInfo l_emlrtECI{
      2,                 // nDims
      244,               // lineNo
      14,                // colNo
      "uavrt_detection", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "uavrt_detection.m" // pName
  };
  static rtEqualityCheckInfo m_emlrtECI{
      1,                 // nDims
      253,               // lineNo
      22,                // colNo
      "uavrt_detection", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "uavrt_detection.m" // pName
  };
  static rtEqualityCheckInfo n_emlrtECI{
      2,                 // nDims
      253,               // lineNo
      22,                // colNo
      "uavrt_detection", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "uavrt_detection.m" // pName
  };
  static rtEqualityCheckInfo o_emlrtECI{
      2,                 // nDims
      778,               // lineNo
      17,                // colNo
      "uavrt_detection", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "uavrt_detection.m" // pName
  };
  static rtEqualityCheckInfo p_emlrtECI{
      -1,                // nDims
      301,               // lineNo
      37,                // colNo
      "uavrt_detection", // fName
      "/Users/mshafer/Desktop/PLAYGROUND/CODE_TOEPLITZ/uavrt_detection/"
      "uavrt_detection.m" // pName
  };
  static const char b_cv[31]{'c', 'u', 'r', 'r', 'e', 'n', 't', '_',
                             'w', 'o', 'r', 'k', 'i', 'n', 'g', '_',
                             'd', 'i', 'r', 'e', 'c', 't', 'o', 'r',
                             'y', '_', 'e', 'r', 'r', 'o', 'r'};
  static const char b_cv1[9]{'u', 'n', 's', 'p', 'a', 'w', 'n', 'e', 'd'};
  char *nullVal;
  char *retVal;
  b_waveform X;
  coder::b_captured_var Config;
  coder::c_captured_var overlapSamples;
  coder::c_captured_var sampsForKPulses;
  coder::c_captured_var stftOverlapFraction;
  coder::captured_var configPath;
  coder::datetime b_this;
  coder::dspcodegen::UDPSender udpPulseOut;
  coder::ros2node node;
  coder::ros2publisher pulsePub;
  pulseOut currPulseOut;
  pulsestats lobj_14[4];
  pulsestats lobj_24[2];
  pulsestats lobj_17;
  pulsestats lobj_19;
  pulsestats lobj_20;
  pulsestats lobj_21;
  pulsestats *pulseStatsPriori;
  threshold obj;
  waveform b_X;
  waveform lobj_15;
  waveform lobj_23;
  waveform *Xhold;
  wfmstft lobj_22[3];
  wfmstft lobj_13;
  wfmstft lobj_16;
  wfmstft lobj_18;
  coder::array<c_struct_T, 2U> c_X;
  coder::array<c_struct_T, 2U> ps_pre_struc_clst;
  coder::array<c_struct_T, 2U> ps_pre_struc_pl;
  coder::array<c_struct_T, 1U> d_X;
  coder::array<creal32_T, 2U> dataReceived;
  coder::array<creal32_T, 2U> iqDataToWrite;
  coder::array<creal32_T, 1U> b_dataReceived;
  coder::array<creal32_T, 1U> b_iqDataToWrite;
  coder::array<creal32_T, 1U> c_iqDataToWrite;
  coder::array<creal32_T, 1U> dataWriterBuffData;
  coder::array<double, 2U> groupSNRList;
  coder::array<double, 2U> ps_pre_struc_cpki;
  coder::array<double, 1U> b_groupSNRList;
  coder::array<double, 1U> t;
  coder::array<double, 1U> timeVector;
  coder::array<float, 1U> b_dataWriterBuffData;
  coder::array<float, 1U> r1;
  coder::array<int, 2U> r2;
  coder::array<signed char, 2U> cmdReceived;
  coder::array<char, 2U> currDir;
  coder::array<char, 2U> e_state;
  coder::array<char, 2U> previousState;
  coder::array<char, 2U> ps_pre_struc_mode;
  coder::array<char, 2U> varargin_1;
  coder::array<bool, 2U> ps_pre_struc_cmsk;
  coder::array<bool, 2U> pulsesToSkip;
  coder::array<bool, 2U> r3;
  coder::array<bool, 1U> b_pulsesConfirmed;
  coder::array<bool, 1U> pulsesConfirmed;
  c_struct_T expl_temp;
  c_struct_T r;
  uavrt_interfaces_PulseStruct_T pulseMsg;
  creal_T dcv[1000];
  creal32_T exampleData[1000];
  double ps_pre_struc_tmplt[2];
  double dataWriterSamples;
  double expectedNextTimeStamp;
  double framesReceived;
  double idleTic;
  double previousPulseTime;
  double ps_pre_struc_fend;
  double ps_pre_struc_fp;
  double ps_pre_struc_fstart;
  double ps_pre_struc_t_ip;
  double ps_pre_struc_t_ipj;
  double ps_pre_struc_t_ipu;
  double ps_pre_struc_t_p;
  double segmentsProcessed;
  double startTime;
  double t10_SNR;
  double t10_fend;
  double t10_fp;
  double t10_fstart;
  double t10_t_0;
  double t10_t_f;
  double t10_yw;
  double timeDiff;
  double timeStamp;
  double tocAtLastCommandCheck;
  double trackedCount;
  int i;
  int loop_ub;
  int nx;
  char untokenizedDir[200];
  signed char fileid;
  char suggestedMode;
  bool cleanBuffer;
  bool configUpdatedFlag;
  bool fLock;
  bool resetBuffersFlag;
  bool resetUdp;
  bool staleDataFlag;
  bool t10_con_dec;
  bool t10_det_dec;
  if (!isInitialized_uavrt_detection) {
    uavrt_detection_initialize();
  }
  // UNTITLED Summary of this function goes here
  //    Detailed explanation goes here
  // Needed for usleep function in generated code
  //  coder.cinclude('stdlib.h')%needed for system call to kill the channelizer
  configPath.contents.init();
  // Must exist in the same directory as the execution of this executable
  Config.contents.init();
  // Build empty config object
  updateconfig(Config, configPath);
  // Update (fill) the configuration
  configUpdatedFlag = true;
  //  %Get current working directory
  //  if coder.target('MATLAB')
  //      currDir = pwd;
  //  else
  //      %Solution from
  //      https://www.mathworks.com/matlabcentral/answers/1843008-using-coder-ceval-to-getcwd
  //      coder.cinclude('unistd.h');
  //      bufferTemplate = repmat('c', 1, 200);
  //      untokenizedDir = coder.nullcopy(bufferTemplate);
  //      coder.ceval('getcwd', coder.ref(untokenizedDir), 200);
  //      currDir = strtok(untokenizedDir, char(0));
  //  end
  // Attempts at catching a failed getcwd() call
  //  Get current working directory
  nullVal = nullptr;
  retVal = getcwd(&untokenizedDir[0], 200.0);
  if (retVal == nullVal) {
    //  Do some error handling here
    currDir.set_size(1, 31);
    for (i = 0; i < 31; i++) {
      currDir[i] = b_cv[i];
    }
  } else {
    coder::b_strtok(untokenizedDir, currDir);
  }
  varargin_1.set_size(1, currDir.size(1) + 1);
  loop_ub = currDir.size(1);
  for (i = 0; i < loop_ub; i++) {
    varargin_1[i] = currDir[i];
  }
  varargin_1[currDir.size(1)] = '\x00';
  std::printf("Curr Directory is: %s\n", &varargin_1[0]);
  std::fflush(stdout);
  //  ROS2 Setup
  // Config.ros2enable; %Hard coded switch so that can be ROS2 can be turned off
  // for testing/debugging
  std::printf("Preparing ROS2 Node and Messages...");
  std::fflush(stdout);
  node.init();
  pulsePub.init(node);
  uavrt_interfaces_PulseStruct(pulseMsg);
  // pulseMsg = ros2message("uavrt_interfaces/Pulse");
  std::printf("complete.\n");
  std::fflush(stdout);
  r.A = makepulsestruc(r.t_next, r.mode, r.P, r.SNR, r.yw, r.t_0, r.t_f, r.fp,
                       r.fstart, r.fend, r.det_dec, r.con_dec);
  timeDiff = makepulsestruc(expl_temp.t_next, expl_temp.mode, timeStamp,
                            t10_SNR, t10_yw, t10_t_0, t10_t_f, t10_fp,
                            t10_fstart, t10_fend, t10_det_dec, t10_con_dec);
  expl_temp.con_dec = t10_con_dec;
  expl_temp.det_dec = t10_det_dec;
  expl_temp.fend = t10_fend;
  expl_temp.fstart = t10_fstart;
  expl_temp.fp = t10_fp;
  expl_temp.t_f = t10_t_f;
  expl_temp.t_0 = t10_t_0;
  expl_temp.yw = t10_yw;
  expl_temp.SNR = t10_SNR;
  expl_temp.P = timeStamp;
  expl_temp.A = timeDiff;
  pulseStatsPriori =
      lobj_24[1].init(Config.contents.tp, Config.contents.tip,
                      Config.contents.tipu, Config.contents.tipj, r, expl_temp);
  //  % tp, tip, tipu
  //  % tipj, fp, fstart, fend, tmplt, mode
  //   % pl ,clst
  //  cmsk ,cpki)
  stftOverlapFraction.contents = 0.5;
  // Initialize and then set these variable needed for buffer reads
  overlapSamples.contents = 0.0;
  sampsForKPulses.contents = 0.0;
  updatebufferreadvariables(Config, stftOverlapFraction, overlapSamples,
                            sampsForKPulses, pulseStatsPriori);
  // 1024 plus a time stamp.
  std::printf("Startup set 1 complete. \n");
  std::fflush(stdout);
  //  Prepare data writing buffer
  //  Calculating the max size that would ever be needed for the buffer
  //  maxK    = 6;
  //  maxFs   = 912000/2;
  //  maxtp   = 0.04;
  //  maxtip  = 2;
  //  maxtipu = 0.1;
  //  maxpulseStatsPriori = pulsestats(maxtp,maxtip,maxtipu,[],[],[],[1
  //  1],pulse); Xmax = waveform([], maxFs, 0, maxpulseStatsPriori,
  //  stftOverlapFraction);
  //  [~,~,~,maxn_ws,~,~,maxN,maxM] = Xmax.getprioridependentprops(Xmax.ps_pre);
  //  sampsForMaxPulses = maxK*maxn_ws*(maxN+maxM+1+1);
  asyncDataBuff.pBuffer.NumChannels = -1;
  asyncDataBuff.pBuffer.isInitialized = 0;
  asyncDataBuff.pBuffer.matlabCodegenIsDeleted = false;
  asyncDataBuff.matlabCodegenIsDeleted = false;
  asyncTimeBuff.pBuffer.NumChannels = -1;
  asyncTimeBuff.pBuffer.isInitialized = 0;
  asyncTimeBuff.pBuffer.matlabCodegenIsDeleted = false;
  asyncTimeBuff.matlabCodegenIsDeleted = false;
  std::printf("Startup set 2 complete. \n");
  std::fflush(stdout);
  // Write interval in seconds. 2.5*60*4000*32/8 should work out the 2.4Mb of
  // data at 4ksps.
  dataWriterSamples = std::ceil(10.0 / (1024.0 / Config.contents.Fs)) * 1025.0;
  asyncWriteBuff.pBuffer.NumChannels = -1;
  asyncWriteBuff.pBuffer.isInitialized = 0;
  asyncWriteBuff.pBuffer.matlabCodegenIsDeleted = false;
  asyncWriteBuff.matlabCodegenIsDeleted = false;
  // 600650 is the result of the nominal settings of ceil(150/(1024/4000)*1025.
  asyncWriteBuff.write();
  // Write to give Code the type. Read to remove data.
  asyncWriteBuff.read();
  fileid = coder::internal::cfopen(Config.contents.dataRecordPath.Value);
  // dataWriterFileID    = fopen('output/data.bin','w');
  if (fileid == -1) {
    std::printf(
        "UAV-RT: Error opening/creating data record file with error:\n");
    std::fflush(stdout);
  }
  std::printf("Startup set 3 complete. \n");
  std::fflush(stdout);
  // pulseWriterFileID    =
  // fopen(cat(2,char(Config.processedOuputPath),'PULSE_LOG.txt'),'w');
  // pulseWriterFileID    = fopen('pulse_log','w');
  //  pulseWriterFileID    = fopen('/config/data2.bin','w');
  //  if dataWriterFileID == -1
  //      fprintf("UAV-RT: Error opening/creating pulse record file with
  //      error:\n")
  //  end
  //
  std::printf("Startup set 4 complete. \n");
  std::fflush(stdout);
  // Define a pulsestats structure that isn't an object.
  // This is needed for the loop, as Matlab coder has problems seeing
  // that the pulsestats handle object is set for all execution paths.
  // Holding all these properties in a structure rather than the
  // pulsestats object addressed this problem.
  // Needed to let coder know that some of these will be varying in size
  // https://www.mathworks.com/help/simulink/ug/how-working-with-matlab-classes-is-different-for-code-generation.html
  ps_pre_struc_mode.set_size(1, 1);
  ps_pre_struc_mode[0] = 'D';
  // dims 0 if fixed, 1 if variable
  r.A = makepulsestruc(r.t_next, r.mode, r.P, r.SNR, r.yw, r.t_0, r.t_f, r.fp,
                       r.fstart, r.fend, r.det_dec, r.con_dec);
  ps_pre_struc_pl.set_size(1, 1);
  ps_pre_struc_pl[0] = r;
  r.A = makepulsestruc(r.t_next, r.mode, r.P, r.SNR, r.yw, r.t_0, r.t_f, r.fp,
                       r.fstart, r.fend, r.det_dec, r.con_dec);
  ps_pre_struc_clst.set_size(1, 1);
  ps_pre_struc_clst[0] = r;
  ps_pre_struc_cmsk.set_size(1, 1);
  ps_pre_struc_cmsk[0] = false;
  std::printf("Startup set 5 complete. \n");
  std::fflush(stdout);
  ps_pre_struc_t_p = 0.0;
  ps_pre_struc_t_ip = 0.0;
  ps_pre_struc_t_ipu = 0.0;
  ps_pre_struc_t_ipj = 0.0;
  ps_pre_struc_fp = 0.0;
  ps_pre_struc_fstart = 0.0;
  ps_pre_struc_fend = 0.0;
  ps_pre_struc_tmplt[0] = 1.0;
  ps_pre_struc_tmplt[1] = 1.0;
  ps_pre_struc_cpki.set_size(1, 1);
  ps_pre_struc_cpki[0] = rtNaN;
  //  pulseOut.tag_id                     = uint32(0);%ID is a string
  //  pulseOut.detector_dir               = currDir;%ID is a string
  //  pulseOut.frequency                  = 0;
  //  pulseOut.start_time.sec             =  int32(0);
  //  pulseOut.start_time.nanosec         = uint32(0);
  //  pulseOut.end_time.sec               =  int32(0);
  //  pulseOut.end_time.nanosec           = uint32(0);
  //  pulseOut.predict_next_start.sec     =  int32(0);
  //  pulseOut.predict_next_start.nanosec = uint32(0);
  //  pulseOut.predict_next_end.sec       =  int32(0);
  //  pulseOut.predict_next_end.nanosec   = uint32(0);
  //  pulseOut.snr                        = 0;
  //  pulseOut.stft_score                 = 0;
  //  pulseOut.group_ind                  = uint16(0);
  //  pulseOut.group_snr                  = double(0);
  //  pulseOut.detection_status           = false;
  //  pulseOut.confirmed_status           = false;
  udpPulseOut.isInitialized = 0;
  // System object Constructor function: dsp.UDPSender
  udpPulseOut.cSFunObject.P0_Port = 50000;
  udpPulseOut.matlabCodegenIsDeleted = false;
  std::printf("Startup set 6 complete. \n");
  std::fflush(stdout);
  //  Preallocate X and Xhold so that coder knows the data types.
  coder::wgn(dcv);
  for (i = 0; i < 1000; i++) {
    exampleData[i].re = static_cast<float>(dcv[i].re);
    exampleData[i].im = static_cast<float>(dcv[i].im);
  }
  // UNTITLED2 Construct an instance of this class
  //    Detailed explanation goes here
  obj.pf = Config.contents.falseAlarmProb;
  obj.evMuParam = 0.0;
  obj.evSigmaParam = 0.0;
  obj.threshVecFine.set_size(1);
  obj.threshVecFine[0] = 0.0;
  Xhold = lobj_23.init(exampleData, Config.contents.Fs, pulseStatsPriori, obj);
  // UNTITLED2 Construct an instance of this class
  //    Detailed explanation goes here
  X.init(exampleData, Config.contents.Fs, pulseStatsPriori, lobj_24[0],
         lobj_22[0]);
  Xhold->spectro(lobj_22[1]);
  X.spectro(lobj_22[2]);
  std::printf("Startup set 7 complete. \n");
  std::fflush(stdout);
  // Initialize loop variables
  resetBuffersFlag = true;
  framesReceived = 0.0;
  segmentsProcessed = 0.0;
  previousState.set_size(1, 9);
  for (i = 0; i < 9; i++) {
    previousState[i] = b_cv1[i];
  }
  suggestedMode = 'S';
  fLock = false;
  resetUdp = true;
  staleDataFlag = true;
  // Force buffer  flush on start
  idleTic = 1.0;
  cleanBuffer = true;
  trackedCount = 0.0;
  b_this.init();
  startTime = std::round(b_this.data.re / 1000.0 * 1.0E+6) / 1.0E+6;
  // sysClockElapsedTime = 0;
  tocAtLastCommandCheck = 0.0;
  previousPulseTime = 0.0;
  iqDataToWrite.set_size(0, 0);
  if (Config.contents.startInRunState) {
    e_state.set_size(1, 3);
    e_state[0] = 'r';
    e_state[1] = 'u';
    e_state[2] = 'n';
  } else {
    e_state.set_size(1, 4);
    e_state[0] = 'i';
    e_state[1] = 'd';
    e_state[2] = 'l';
    e_state[3] = 'e';
  }
  std::printf("Startup set 8 complete. Starting processing... \n");
  std::fflush(stdout);
  expectedNextTimeStamp = 0.0;
  int exitg1;
  do {
    exitg1 = 0;
    // i <= maxInd
    if (coder::internal::b_strcmp(e_state)) {
      nx = 0;
    } else if (coder::internal::c_strcmp(e_state)) {
      nx = 1;
    } else if (coder::internal::d_strcmp(e_state)) {
      nx = 2;
    } else if (coder::internal::e_strcmp(e_state)) {
      nx = 3;
    } else if (coder::internal::f_strcmp(e_state)) {
      nx = 4;
    } else {
      nx = -1;
    }
    switch (nx) {
    case 0: {
      if (resetBuffersFlag) {
        asyncDataBuff.reset();
        asyncTimeBuff.reset();
        asyncWriteBuff.reset();
        resetBuffersFlag = false;
        cleanBuffer = true;
      }
      //             %% Get data
      channelreceiver(Config.contents.portData, resetUdp, dataReceived);
      if (dataReceived.size(0) > 1025) {
        rtDimSizeGeqError(1025, dataReceived.size(0), k_emlrtECI);
      }
      if (dataReceived.size(1) != 1) {
        rtDimSizeEqError(dataReceived.size(1), l_emlrtECI);
      }
      b_dataReceived.set_size(dataReceived.size(0));
      loop_ub = dataReceived.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_dataReceived[i] = dataReceived[i];
      }
      resetUdp = false;
      //             %% Flush UDP buffer if data in the buffer is stale.
      if (staleDataFlag) {
        std::printf("********STALE DATA FLAG: %u *********\n", 1U);
        std::fflush(stdout);
        while (b_dataReceived.size(0) != 0) {
          std::printf("********CLEARING UDP DATA BUFFER*********\n");
          std::fflush(stdout);
          channelreceiver(Config.contents.portData, false, dataReceived);
          if (dataReceived.size(0) > 1025) {
            rtDimSizeGeqError(1025, dataReceived.size(0), m_emlrtECI);
          }
          if (dataReceived.size(1) != 1) {
            rtDimSizeEqError(dataReceived.size(1), n_emlrtECI);
          }
          b_dataReceived.set_size(dataReceived.size(0));
          loop_ub = dataReceived.size(0);
          for (i = 0; i < loop_ub; i++) {
            b_dataReceived[i] = dataReceived[i];
          }
        }
        staleDataFlag = false;
        std::printf("********RESETTING TIMES*********\n");
        std::fflush(stdout);
        // startTime = round(posixtime(datetime('now'))*1000000)/1000000;
        framesReceived = 0.0;
        b_this.init();
        startTime = std::round(b_this.data.re / 1000.0 * 1.0E+6) / 1.0E+6;
        coder::tic();
      }
      //             %% Wait for new data if none ready, else put data in
      //             buffers
      if (b_dataReceived.size(0) == 0) {
        // pauseTimeSec = (packetLength-1)/2*1/Config.Fs;
        coder::pause(0.0001);
      } else {
        int iv[2];
        int b_currDir;
        int nPulseList;
        unsigned int timeStampNanoSec;
        unsigned int timeStampSec;
        // timeStamp      = 10^-3*singlecomplex2int(dataReceived(1)); % OLD TIME
        // STAMP METHOD
        std::memcpy((void *)&timeStampSec, (void *)&b_dataReceived[0].re,
                    (unsigned int)((size_t)1 * sizeof(unsigned int)));
        std::memcpy((void *)&timeStampNanoSec, (void *)&b_dataReceived[0].im,
                    (unsigned int)((size_t)1 * sizeof(unsigned int)));
        timeStamp = static_cast<double>(timeStampSec) +
                    1.0E-9 * static_cast<double>(timeStampNanoSec);
        //  OLD TIME STAMP METHOD
        if (b_dataReceived.size(0) < 2) {
          i = 0;
          nx = 0;
        } else {
          i = 1;
          nx = b_dataReceived.size(0);
        }
        iv[0] = 1;
        loop_ub = nx - i;
        iv[1] = loop_ub;
        coder::internal::indexShapeCheck(b_dataReceived.size(0), iv);
        //  OLD TIME STAMP METHOD
        // timeVector     = timeStamp+1/Config.Fs*(0:(numel(iqData)-1)).';% OLD
        // TIME STAMP METHOD
        if (framesReceived == 0.0) {
          iqDataToWrite.set_size(loop_ub, 1);
          for (nx = 0; nx < loop_ub; nx++) {
            iqDataToWrite[nx] = b_dataReceived[i + nx];
          }
          // dataFirstTimeStamp = timeStamp;
        } else {
          double validatedHoleFilling[3];
          timeDiff = timeStamp - expectedNextTimeStamp;
          coder::internal::validate_print_arguments(
              timeStamp, expectedNextTimeStamp, timeDiff, validatedHoleFilling);
          std::printf("Current Received Time Stamp: %f \t Expected Time Stamp: "
                      "%f \t Diff: %f \n",
                      validatedHoleFilling[0], validatedHoleFilling[1],
                      validatedHoleFilling[2]);
          std::fflush(stdout);
          t10_SNR = Config.contents.tp / 2.0;
          if (std::abs(timeDiff) < t10_SNR) {
            iqDataToWrite.set_size(loop_ub, 1);
            for (nx = 0; nx < loop_ub; nx++) {
              iqDataToWrite[nx] = b_dataReceived[i + nx];
            }
          } else if ((timeDiff >= t10_SNR) &&
                     (timeDiff < Config.contents.tip)) {
            unsigned long u;
            // missed samples but not a whole lot
            timeDiff = std::round(timeDiff * Config.contents.Fs);
            if (timeDiff < 1.8446744073709552E+19) {
              if (timeDiff >= 0.0) {
                u = static_cast<unsigned long>(timeDiff);
              } else {
                u = 0UL;
              }
            } else if (timeDiff >= 1.8446744073709552E+19) {
              u = MAX_uint64_T;
            } else {
              u = 0UL;
            }
            std::printf(
                "Missing samples detected. Filling with zeros for %lu samples.",
                u);
            std::fflush(stdout);
            if (!(timeDiff >= 0.0)) {
              rtNonNegativeError(timeDiff, w_emlrtDCI);
            }
            if (timeDiff != static_cast<int>(timeDiff)) {
              rtIntegerError(timeDiff, x_emlrtDCI);
            }
            b_currDir = static_cast<int>(timeDiff);
            dataWriterBuffData.set_size(static_cast<int>(timeDiff));
            for (nPulseList = 0; nPulseList < b_currDir; nPulseList++) {
              dataWriterBuffData[nPulseList].re = 0.0F;
              dataWriterBuffData[nPulseList].im = 0.0F;
            }
            if (static_cast<int>(timeDiff) != dataWriterBuffData.size(0)) {
              rtSizeEq1DError(static_cast<int>(timeDiff),
                              dataWriterBuffData.size(0), p_emlrtECI);
            }
            b_iqDataToWrite.set_size((static_cast<int>(timeDiff) + nx) - i);
            for (nx = 0; nx < b_currDir; nx++) {
              b_iqDataToWrite[nx] = dataWriterBuffData[nx];
            }
            for (nx = 0; nx < loop_ub; nx++) {
              b_iqDataToWrite[nx + static_cast<int>(timeDiff)] =
                  b_dataReceived[i + nx];
            }
            iqDataToWrite.set_size(b_iqDataToWrite.size(0), 1);
            b_currDir = b_iqDataToWrite.size(0);
            for (i = 0; i < b_currDir; i++) {
              iqDataToWrite[i] = b_iqDataToWrite[i];
            }
          } else if (((timeDiff >= t10_SNR) &&
                      (timeDiff >= Config.contents.tip)) ||
                     (timeDiff < -Config.contents.tp / 2.0)) {
            //  %missed a lot of samples. Reset buffers
            // predictions is ahead of recently received packet. Shouldn't ever
            // happen. If it is, reset the incoming data
            staleDataFlag = true;
            resetBuffersFlag = true;
            suggestedMode = 'S';
            iqDataToWrite.set_size(0, 1);
          }
        }
        nx = iqDataToWrite.size(0) * iqDataToWrite.size(1);
        if (nx - 1 < 0) {
          r2.set_size(1, 0);
        } else {
          r2.set_size(1, nx);
          for (i = 0; i < nx; i++) {
            r2[i] = i;
          }
        }
        timeDiff = 1.0 / Config.contents.Fs;
        timeVector.set_size(r2.size(1));
        b_currDir = r2.size(1);
        for (i = 0; i < b_currDir; i++) {
          timeVector[i] = timeStamp + timeDiff * static_cast<double>(r2[i]);
        }
        expectedNextTimeStamp =
            timeStamp + timeDiff * (static_cast<double>(loop_ub - 1) + 1.0);
        framesReceived++;
        //                 % Parse the incoming data and sample count.
        //                 % and fill in any missing data with zeros.
        //                  framesReceived = framesReceived + 1;
        //
        //                  iqData           = dataReceived(1:end-1);
        //
        //                  nReceived        = uint64(numel(iqData));
        //
        //                  currSampleCount  = nextSampleCount + nReceived;
        //                  %This is the number of samples transmitted by the
        //                  %upstream process (ideal if none are dropped)
        //                  %If this is the first packet, calculate the offset
        //                  %sample count since the upstream processess may have
        //                  %started a while ago and its sample count may not be
        //                  zero if framesReceived == 1
        //                      startTime =
        //                      round(posixtime(datetime('now'))*1000000)/1000000;
        //                      sampleOffset = rawIdealSampleCount - nReceived;
        //                      %To estimate the timestamp of the sample before
        //                      the %first one in this first frame we go back in
        //                      time %from the start time. lastTimeStamp =
        //                      startTime - (double(nReceived) + 1) *
        //                      1/Config.Fs;
        //                  end
        //
        //                  idealSampleCount = rawIdealSampleCount -
        //                  sampleOffset;
        //
        //                  missingSamples  = idealSampleCount -
        //                  currSampleCount;
        //
        //                  if missingSamples > 0
        //
        //                      zerosFill = single(zeros(missingSamples, 1)) +
        //                      ...
        //                                      1i*single(zeros(missingSamples,
        //                                      1));
        //
        //                      iqDataToWrite = [zerosFill(:); iqData];
        //
        //                      nextSampleCount = nextSampleCount + nReceived +
        //                      missingSamples;
        //
        //                      fprintf('Missing samples detected. Filling with
        //                      zeros for %u samples.',missingSamples);
        //
        //                  elseif missingSamples < 0
        //
        //                      error('UAV-RT: Number of samples transmitted to
        //                      the detector is less than that expected by the
        //                      detector. Upstream processes (channelizer) may
        //                      be transmitting more than 1024 IQ data samples
        //                      per packet. This is not supported by this
        //                      detetor.')
        //
        //                  else
        //
        //                      iqDataToWrite = iqData;
        //
        //                      nextSampleCount = nextSampleCount + nReceived;
        //
        //                  end
        //
        //  fprintf('nReceived: %u \t currSampleCount: %u \t idealSampleCount:
        //  %u \t rawIdealSampleCount: %u \t missingSamples: %u numel(iqData):
        //  %u numel(iqDataToWrite): %u nextSampleCount: %u \t\n',nReceived,
        //  currSampleCount, idealSampleCount, rawIdealSampleCount,
        //  missingSamples, uint64(numel(iqData)), uint64(numel(iqDataToWrite)),
        //  nextSampleCount)
        //
        //                  timeVector = lastTimeStamp + ...
        //                               (1 : numel(iqDataToWrite)).' *
        //                               1/Config.Fs;
        //                  lastTimeStamp = timeVector(end);
        // Write out data and time.
        c_iqDataToWrite = iqDataToWrite.reshape(nx);
        asyncDataBuff.write(c_iqDataToWrite);
        asyncTimeBuff.write(timeVector);
        asyncWriteBuff.write(b_dataReceived);
        //  OLD TIME STAMP METHOD
        // asyncWriteBuff.write([dataReceived;
        // int2singlecomplex(timeAtPacketReceive*10^3)]);
        if ((asyncWriteBuff.pBuffer.WritePointer >= 0) &&
            (asyncWriteBuff.pBuffer.ReadPointer <
             asyncWriteBuff.pBuffer.WritePointer - MAX_int32_T)) {
          nx = MAX_int32_T;
        } else if ((asyncWriteBuff.pBuffer.WritePointer < 0) &&
                   (asyncWriteBuff.pBuffer.ReadPointer >
                    asyncWriteBuff.pBuffer.WritePointer - MIN_int32_T)) {
          nx = MIN_int32_T;
        } else {
          nx = asyncWriteBuff.pBuffer.WritePointer -
               asyncWriteBuff.pBuffer.ReadPointer;
        }
        if (nx < -2147483647) {
          nx = MIN_int32_T;
        } else {
          nx--;
        }
        if (asyncWriteBuff.pBuffer.ReadPointer < -2146882997) {
          b_currDir = MAX_int32_T;
        } else {
          b_currDir = 600650 - asyncWriteBuff.pBuffer.ReadPointer;
        }
        if ((b_currDir < 0) &&
            (asyncWriteBuff.pBuffer.WritePointer < MIN_int32_T - b_currDir)) {
          b_currDir = MIN_int32_T;
        } else if ((b_currDir > 0) && (asyncWriteBuff.pBuffer.WritePointer >
                                       MAX_int32_T - b_currDir)) {
          b_currDir = MAX_int32_T;
        } else {
          b_currDir += asyncWriteBuff.pBuffer.WritePointer;
        }
        if (asyncWriteBuff.pBuffer.ReadPointer <
            asyncWriteBuff.pBuffer.WritePointer) {
          b_currDir = nx;
        } else if (asyncWriteBuff.pBuffer.ReadPointer ==
                   asyncWriteBuff.pBuffer.WritePointer) {
          b_currDir = 600650;
        }
        if (b_currDir == dataWriterSamples) {
          asyncWriteBuff.read(dataWriterBuffData);
          if (fileid != -1) {
            interleaveComplexVector(dataWriterBuffData, r1);
            coder::b_fwrite(static_cast<double>(fileid), r1);
          }
        }
        // end
        //                 %% Process data if there is enough in the buffers
        t10_det_dec = ((asyncDataBuff.pBuffer.WritePointer >= 0) &&
                       (asyncDataBuff.pBuffer.ReadPointer <
                        asyncDataBuff.pBuffer.WritePointer - MAX_int32_T));
        if (t10_det_dec) {
          nx = MAX_int32_T;
        } else if ((asyncDataBuff.pBuffer.WritePointer < 0) &&
                   (asyncDataBuff.pBuffer.ReadPointer >
                    asyncDataBuff.pBuffer.WritePointer - MIN_int32_T)) {
          nx = MIN_int32_T;
        } else {
          nx = asyncDataBuff.pBuffer.WritePointer -
               asyncDataBuff.pBuffer.ReadPointer;
        }
        if (nx < -2147483647) {
          nx = MIN_int32_T;
        } else {
          nx--;
        }
        if (asyncDataBuff.pBuffer.ReadPointer < -2141683327) {
          b_currDir = MAX_int32_T;
        } else {
          b_currDir = 5800320 - asyncDataBuff.pBuffer.ReadPointer;
        }
        if ((b_currDir < 0) &&
            (asyncDataBuff.pBuffer.WritePointer < MIN_int32_T - b_currDir)) {
          b_currDir = MIN_int32_T;
        } else if ((b_currDir > 0) && (asyncDataBuff.pBuffer.WritePointer >
                                       MAX_int32_T - b_currDir)) {
          b_currDir = MAX_int32_T;
        } else {
          b_currDir += asyncDataBuff.pBuffer.WritePointer;
        }
        if (asyncDataBuff.pBuffer.ReadPointer <
            asyncDataBuff.pBuffer.WritePointer) {
          b_currDir = nx;
        } else if (asyncDataBuff.pBuffer.ReadPointer ==
                   asyncDataBuff.pBuffer.WritePointer) {
          b_currDir = 5800320;
        }
        if (b_currDir >= sampsForKPulses.contents + overlapSamples.contents) {
          double processingStartToc;
          t10_SNR = std::round(sampsForKPulses.contents);
          if (t10_SNR < 4.294967296E+9) {
            if (t10_SNR >= 0.0) {
              timeStampSec = static_cast<unsigned int>(t10_SNR);
            } else {
              timeStampSec = 0U;
            }
          } else if (t10_SNR >= 4.294967296E+9) {
            timeStampSec = MAX_uint32_T;
          } else {
            timeStampSec = 0U;
          }
          t10_SNR = std::round(overlapSamples.contents);
          if (t10_SNR < 4.294967296E+9) {
            if (t10_SNR >= 0.0) {
              timeStampNanoSec = static_cast<unsigned int>(t10_SNR);
            } else {
              timeStampNanoSec = 0U;
            }
          } else if (t10_SNR >= 4.294967296E+9) {
            timeStampNanoSec = MAX_uint32_T;
          } else {
            timeStampNanoSec = 0U;
          }
          std::printf(
              "Buffer Full|| sampsForKPulses: %u, overlapSamples: %u,\n",
              timeStampSec, timeStampNanoSec);
          std::fflush(stdout);
          if (t10_det_dec) {
            nx = MAX_int32_T;
          } else if ((asyncDataBuff.pBuffer.WritePointer < 0) &&
                     (asyncDataBuff.pBuffer.ReadPointer >
                      asyncDataBuff.pBuffer.WritePointer - MIN_int32_T)) {
            nx = MIN_int32_T;
          } else {
            nx = asyncDataBuff.pBuffer.WritePointer -
                 asyncDataBuff.pBuffer.ReadPointer;
          }
          if (nx < -2147483647) {
            nx = MIN_int32_T;
          } else {
            nx--;
          }
          if (asyncDataBuff.pBuffer.ReadPointer < -2141683327) {
            b_currDir = MAX_int32_T;
          } else {
            b_currDir = 5800320 - asyncDataBuff.pBuffer.ReadPointer;
          }
          if ((b_currDir < 0) &&
              (asyncDataBuff.pBuffer.WritePointer < MIN_int32_T - b_currDir)) {
            b_currDir = MIN_int32_T;
          } else if ((b_currDir > 0) && (asyncDataBuff.pBuffer.WritePointer >
                                         MAX_int32_T - b_currDir)) {
            b_currDir = MAX_int32_T;
          } else {
            b_currDir += asyncDataBuff.pBuffer.WritePointer;
          }
          if (asyncDataBuff.pBuffer.ReadPointer <
              asyncDataBuff.pBuffer.WritePointer) {
            b_currDir = nx;
          } else if (asyncDataBuff.pBuffer.ReadPointer ==
                     asyncDataBuff.pBuffer.WritePointer) {
            b_currDir = 5800320;
          }
          std::printf("Running...Buffer full with %d samples. Processing. \n",
                      b_currDir);
          std::fflush(stdout);
          processingStartToc = coder::toc();
          if (cleanBuffer) {
            // Overlap reads back into the buffer, but there
            // isn't anything back there on the first segment.
            // Using an overlap will fill the output with
            // overlapSamples of zeros at beginning
            // of x if you specify overlap here. Don't want that
            // so specify zero overlap for first read after
            // cleaning buffer
            asyncDataBuff.read(sampsForKPulses.contents, dataWriterBuffData);
            asyncTimeBuff.read(sampsForKPulses.contents, t);
            cleanBuffer = false;
          } else {
            asyncDataBuff.read(sampsForKPulses.contents,
                               overlapSamples.contents, dataWriterBuffData);
            asyncTimeBuff.read(sampsForKPulses.contents,
                               overlapSamples.contents, t);
          }
          if (timeVector.size(0) < 1) {
            rtDynamicBoundsError(timeVector.size(0), 1, timeVector.size(0),
                                 cb_emlrtBCI);
          }
          b_this.init();
          std::printf(
              "Sample elapsed seconds: %f \t Posix elapsed seconds: %f \n",
              timeVector[timeVector.size(0) - 1] - startTime,
              std::round(b_this.data.re / 1000.0 * 1.0E+6) / 1.0E+6 -
                  startTime);
          std::fflush(stdout);
          nx = dataWriterBuffData.size(0);
          b_dataWriterBuffData.set_size(dataWriterBuffData.size(0));
          if (dataWriterBuffData.size(0) > 2147483646) {
            coder::check_forloop_overflow_error();
          }
          for (b_currDir = 0; b_currDir < nx; b_currDir++) {
            b_dataWriterBuffData[b_currDir] =
                rt_hypotf_snf(dataWriterBuffData[b_currDir].re,
                              dataWriterBuffData[b_currDir].im);
          }
          // Check the timestamps in the buffer for gaps larger
          // than the max interpulse uncertainty. If there are
          // enough dropped packets such that the time is shifted
          // by more than the interpulse uncertainty, then the
          // detection will likely fail or produces bad results. In
          // this case. Skip the processing and clear the buffer.
          coder::diff(t, timeVector);
          loop_ub = timeVector.size(0);
          for (i = 0; i < loop_ub; i++) {
            timeVector[i] = timeVector[i] - timeDiff;
          }
          timeDiff = coder::combineVectorElements(timeVector);
          if ((Config.contents.K > 1.0) &&
              (timeDiff > Config.contents.tipu + Config.contents.tipj)) {
            std::printf("Significant time differences found in timestamp "
                        "record. Skipping processing and clearing buffers.\n");
            std::fflush(stdout);
            resetBuffersFlag = true;
            staleDataFlag = true;
          } else {
            unsigned int b_validatedHoleFilling[3];
            int pulseCount;
            unsigned int varargin_3;
            char mode;
            if (t.size(0) < 1) {
              rtDynamicBoundsError(1, 1, t.size(0), db_emlrtBCI);
            }
            std::printf("Running...Building priori and waveform. \n");
            std::fflush(stdout);
            // Set the priori info
            if (configUpdatedFlag) {
              // Initialize states for operational modes
              if (Config.contents.opMode.eq()) {
                nx = 0;
              } else if (Config.contents.opMode.b_eq()) {
                nx = 1;
              } else if (Config.contents.opMode.c_eq()) {
                nx = 2;
              } else if (Config.contents.opMode.d_eq()) {
                nx = 3;
              } else {
                nx = -1;
              }
              switch (nx) {
              case 0:
                fLock = false;
                break;
              case 1:
                fLock = true;
                break;
              case 2:
                fLock = false;
                break;
              case 3:
                fLock = false;
                break;
              default:
                fLock = false;
                break;
              }
              r.A = makepulsestruc(r.t_next, r.mode, r.P, r.SNR, r.yw, r.t_0,
                                   r.t_f, r.fp, r.fstart, r.fend, r.det_dec,
                                   r.con_dec);
              timeDiff = makepulsestruc(expl_temp.t_next, expl_temp.mode,
                                        timeStamp, t10_SNR, t10_yw, t10_t_0,
                                        t10_t_f, t10_fp, t10_fstart, t10_fend,
                                        t10_det_dec, t10_con_dec);
              expl_temp.con_dec = t10_con_dec;
              expl_temp.det_dec = t10_det_dec;
              expl_temp.fend = t10_fend;
              expl_temp.fstart = t10_fstart;
              expl_temp.fp = t10_fp;
              expl_temp.t_f = t10_t_f;
              expl_temp.t_0 = t10_t_0;
              expl_temp.yw = t10_yw;
              expl_temp.SNR = t10_SNR;
              expl_temp.P = timeStamp;
              expl_temp.A = timeDiff;
              pulseStatsPriori = lobj_17.init(
                  Config.contents.tp, Config.contents.tip, Config.contents.tipu,
                  Config.contents.tipj,
                  1.0E-5 * std::abs(Config.contents.tagFreqMHz -
                                    Config.contents.channelCenterFreqMHz),
                  r, expl_temp);
              configUpdatedFlag = false;
            } else {
              pulseStatsPriori = lobj_20.c_init(
                  ps_pre_struc_t_p, ps_pre_struc_t_ip, ps_pre_struc_t_ipu,
                  ps_pre_struc_t_ipj, ps_pre_struc_fp, ps_pre_struc_fstart,
                  ps_pre_struc_fend, ps_pre_struc_tmplt, ps_pre_struc_mode,
                  ps_pre_struc_pl, ps_pre_struc_clst, ps_pre_struc_cmsk,
                  ps_pre_struc_cpki);
            }
            //                         %% PRIMARY PROCESSING BLOCK
            // Prep waveform for processing/detection
            // UNTITLED2 Construct an instance of this class
            //    Detailed explanation goes here
            obj.pf = Config.contents.falseAlarmProb;
            obj.evMuParam = 0.0;
            obj.evSigmaParam = 0.0;
            obj.threshVecFine.set_size(1);
            obj.threshVecFine[0] = 0.0;
            b_X.init(dataWriterBuffData, Config.contents.Fs, t[0],
                     pulseStatsPriori, obj, lobj_19, lobj_18);
            b_X.K = Config.contents.K;
            t10_SNR = std::round(b_X.N);
            if (t10_SNR < 4.294967296E+9) {
              if (t10_SNR >= 0.0) {
                timeStampSec = static_cast<unsigned int>(t10_SNR);
              } else {
                timeStampSec = 0U;
              }
            } else if (t10_SNR >= 4.294967296E+9) {
              timeStampSec = MAX_uint32_T;
            } else {
              timeStampSec = 0U;
            }
            t10_SNR = std::round(b_X.M);
            if (t10_SNR < 4.294967296E+9) {
              if (t10_SNR >= 0.0) {
                timeStampNanoSec = static_cast<unsigned int>(t10_SNR);
              } else {
                timeStampNanoSec = 0U;
              }
            } else if (t10_SNR >= 4.294967296E+9) {
              timeStampNanoSec = MAX_uint32_T;
            } else {
              timeStampNanoSec = 0U;
            }
            t10_SNR = std::round(b_X.J);
            if (t10_SNR < 4.294967296E+9) {
              if (t10_SNR >= 0.0) {
                varargin_3 = static_cast<unsigned int>(t10_SNR);
              } else {
                varargin_3 = 0U;
              }
            } else if (t10_SNR >= 4.294967296E+9) {
              varargin_3 = MAX_uint32_T;
            } else {
              varargin_3 = 0U;
            }
            coder::internal::validate_print_arguments(
                timeStampSec, timeStampNanoSec, varargin_3,
                b_validatedHoleFilling);
            std::printf("Current interpulse params || N: %u, M: %u, J: %u,\n",
                        b_validatedHoleFilling[0], b_validatedHoleFilling[1],
                        b_validatedHoleFilling[2]);
            std::fflush(stdout);
            b_X.setprioridependentprops(b_X.ps_pre);
            timeStampSec = static_cast<unsigned int>(b_X.x.size(1));
            std::printf("Samples in waveform: %u \n", timeStampSec);
            std::fflush(stdout);
            timeDiff = coder::toc();
            std::printf("Computing STFT...");
            std::fflush(stdout);
            b_X.spectro(lobj_16);
            timeDiff = coder::toc() - timeDiff;
            std::printf("complete. Elapsed time: %f seconds \n", timeDiff);
            std::fflush(stdout);
            std::printf("Building weighting matrix ...");
            std::fflush(stdout);
            timeDiff = coder::toc();
            b_X.setweightingmatrix();
            timeDiff = coder::toc() - timeDiff;
            std::printf("complete. Elapsed time: %f seconds \n", timeDiff);
            std::fflush(stdout);
            if (suggestedMode == 'S') {
              nx = 0;
            } else if (suggestedMode == 'C') {
              nx = 1;
            } else if (suggestedMode == 'T') {
              nx = 2;
            } else {
              nx = -1;
            }
            switch (nx) {
            case 0:
              if (fLock) {
                mode = 'I';
              } else {
                mode = 'D';
              }
              break;
            case 1:
              mode = 'C';
              break;
            case 2:
              mode = 'T';
              trackedCount++;
              break;
            default:
              std::printf("UAV-RT: Unsupported mode requested. Defaulting to "
                          "Discovery (D) mode.");
              std::fflush(stdout);
              mode = 'D';
              break;
            }
            if (coder::internal::b_strcmp(Config.contents.opMode)) {
              mode = 'D';
            }
            timeDiff = coder::toc();
            if (segmentsProcessed == 0.0) {
              std::printf("Building thresholds  ...");
              std::fflush(stdout);
              obj = b_X.thresh;
              obj.makenewthreshold(b_X);
              b_X.thresh = obj;
            } else {
              std::printf("Setting thresholds from previous waveform  ...");
              std::fflush(stdout);
              obj = b_X.thresh;
              obj.setthreshold(b_X, Xhold);
              b_X.thresh = obj;
            }
            timeDiff = coder::toc() - timeDiff;
            std::printf("complete. Elapsed time: %f seconds \n", timeDiff);
            std::fflush(stdout);
            timeStampSec = static_cast<unsigned int>(b_X.stft->S.size(1));
            std::printf("Time windows in S: %u \n", timeStampSec);
            std::fflush(stdout);
            timeDiff = coder::toc();
            std::printf("Finding pulses...");
            std::fflush(stdout);
            b_X.process(mode, Config.contents.excldFreqs);
            timeDiff = coder::toc() - timeDiff;
            std::printf("complete. Elapsed time: %f seconds \n", timeDiff);
            std::fflush(stdout);
            timeDiff = coder::toc() - processingStartToc;
            std::printf("TOTAL PULSE PROCESSING TIME: %f seconds \n", timeDiff);
            std::fflush(stdout);
            //                         %% PREP FOR NEXT LOOP
            // Latch/Release the frequency lock and setup the
            // suggested mode
            suggestedMode = b_X.ps_pos->mode;
            c_X.set_size(1, b_X.ps_pos->pl.size(1));
            loop_ub = b_X.ps_pos->pl.size(0) * b_X.ps_pos->pl.size(1) - 1;
            for (i = 0; i <= loop_ub; i++) {
              c_X[i] = b_X.ps_pos->pl[i];
            }
            coder::internal::c_horzcatStructList(c_X, ps_pre_struc_cmsk);
            coder::all(ps_pre_struc_cmsk, pulsesConfirmed);
            if (coder::internal::ifWhileCond(pulsesConfirmed)) {
              // Check if all were confirmed
              fLock = true;
            }
            // We only ever release if we are in softlock mode and
            // only do so in that case if we are no longer confirming
            // pulses.
            if (coder::internal::c_strcmp(Config.contents.opMode)) {
              b_pulsesConfirmed.set_size(pulsesConfirmed.size(0));
              loop_ub = pulsesConfirmed.size(0);
              for (i = 0; i < loop_ub; i++) {
                b_pulsesConfirmed[i] = !pulsesConfirmed[i];
              }
              if (coder::internal::ifWhileCond(b_pulsesConfirmed)) {
                fLock = false;
              }
            }
            // Decide when/how the priori is updated for the next
            // segment's processing.
            if (coder::internal::ifWhileCond(pulsesConfirmed) &&
                ((mode == 'C') || (mode == 'T'))) {
              c_X.set_size(1, b_X.ps_pos->pl.size(1));
              loop_ub = b_X.ps_pos->pl.size(0) * b_X.ps_pos->pl.size(1) - 1;
              for (i = 0; i <= loop_ub; i++) {
                c_X[i] = b_X.ps_pos->pl[i];
              }
              b_X.ps_pos->updateposteriori(b_X.ps_pre, c_X);
              if (trackedCount > 5.0) {
                trackedCount = 0.0;
                c_X.set_size(1, b_X.ps_pos->pl.size(1));
                loop_ub = b_X.ps_pos->pl.size(0) * b_X.ps_pos->pl.size(1) - 1;
                for (i = 0; i <= loop_ub; i++) {
                  c_X[i] = b_X.ps_pos->pl[i];
                }
                b_X.ps_pos->b_updateposteriori(b_X.ps_pre, c_X);
              }
            }
            // Check lagging processing
            if ((segmentsProcessed != 0.0) && (Config.contents.K > 1.0) &&
                (timeDiff >
                 0.9 * sampsForKPulses.contents / Config.contents.Fs)) {
              // Config.K = Config.K - 1;
              t10_SNR = std::round(Config.contents.K - 1.0);
              if (t10_SNR < 4.294967296E+9) {
                timeStampSec = static_cast<unsigned int>(t10_SNR);
              } else {
                timeStampSec = MAX_uint32_T;
              }
              std::printf("WARNING!!! PROCESSING TIME TOOK LONGER THAN "
                          "WAVEFORM LENGTH. STREAMING NOT POSSIBLE. TRY "
                          "REDUCING NUMBER OF PULSES CONSIDERED BY"
                          " 1 TO K = %u \n",
                          timeStampSec);
              std::fflush(stdout);
              std::printf("Resetting all internal data buffers and udp buffers "
                          "to clear potential stale data. \n");
              std::fflush(stdout);
              resetBuffersFlag = true;
              staleDataFlag = true;
              suggestedMode = 'S';
            }
            segmentsProcessed++;
            // tic
            timeDiff = coder::toc();
            // Prepare priori for next segment
            std::printf("Updating priori...\n");
            std::fflush(stdout);
            ps_pre_struc_t_p = b_X.ps_pos->t_p;
            ps_pre_struc_t_ip = b_X.ps_pos->t_ip;
            ps_pre_struc_t_ipu = b_X.ps_pos->t_ipu;
            ps_pre_struc_t_ipj = b_X.ps_pos->t_ipj;
            ps_pre_struc_fp = b_X.ps_pos->fp;
            ps_pre_struc_fstart = b_X.ps_pos->fstart;
            ps_pre_struc_fend = b_X.ps_pos->fend;
            ps_pre_struc_tmplt[0] = b_X.ps_pos->tmplt[0];
            ps_pre_struc_tmplt[1] = b_X.ps_pos->tmplt[1];
            ps_pre_struc_mode.set_size(1, 1);
            ps_pre_struc_mode[0] = b_X.ps_pos->mode;
            ps_pre_struc_pl.set_size(1, b_X.ps_pos->pl.size(1));
            loop_ub = b_X.ps_pos->pl.size(1);
            for (i = 0; i < loop_ub; i++) {
              ps_pre_struc_pl[i] = b_X.ps_pos->pl[i];
            }
            ps_pre_struc_clst.set_size(b_X.ps_pos->clst.size(0),
                                       b_X.ps_pos->clst.size(1));
            loop_ub = b_X.ps_pos->clst.size(0) * b_X.ps_pos->clst.size(1);
            for (i = 0; i < loop_ub; i++) {
              ps_pre_struc_clst[i] = b_X.ps_pos->clst[i];
            }
            ps_pre_struc_cmsk.set_size(b_X.ps_pos->cmsk.size(0),
                                       b_X.ps_pos->cmsk.size(1));
            loop_ub = b_X.ps_pos->cmsk.size(0) * b_X.ps_pos->cmsk.size(1);
            for (i = 0; i < loop_ub; i++) {
              ps_pre_struc_cmsk[i] = b_X.ps_pos->cmsk[i];
            }
            ps_pre_struc_cpki.set_size(b_X.ps_pos->cpki.size(0),
                                       b_X.ps_pos->cpki.size(1));
            loop_ub = b_X.ps_pos->cpki.size(0) * b_X.ps_pos->cpki.size(1);
            for (i = 0; i < loop_ub; i++) {
              ps_pre_struc_cpki[i] = b_X.ps_pos->cpki[i];
            }
            updatebufferreadvariables(Config, stftOverlapFraction,
                                      overlapSamples, sampsForKPulses,
                                      b_X.ps_pos);
            timeDiff = coder::toc() - timeDiff;
            std::printf("complete. Elapsed time: %f seconds \n", timeDiff);
            std::fflush(stdout);
            // Deal with detected pulses
            // Xhold{mod(segmentsProcessed,maxSegments)} = X;%Keep a maxSegments
            // running record of waveforms for debugging in Matlab Xstruct =
            // obj2structrecursive(); Xhold = X;
            Xhold = waveformcopy(b_X, lobj_13, lobj_14[0], lobj_15);
            nPulseList = b_X.ps_pos->pl.size(1);
            pulsesToSkip.set_size(1, nPulseList);
            for (i = 0; i < nPulseList; i++) {
              pulsesToSkip[i] = false;
            }
            // Report pulses and check for repeat detections
            groupSNRList.set_size(b_X.ps_pos->cpki.size(0),
                                  b_X.ps_pos->cpki.size(1));
            loop_ub = b_X.ps_pos->cpki.size(0) * b_X.ps_pos->cpki.size(1);
            for (i = 0; i < loop_ub; i++) {
              groupSNRList[i] = b_X.ps_pos->cpki[i];
            }
            r3.set_size(groupSNRList.size(0), groupSNRList.size(1));
            loop_ub = groupSNRList.size(0) * groupSNRList.size(1);
            for (i = 0; i < loop_ub; i++) {
              r3[i] = !std::isnan(groupSNRList[i]);
            }
            if (coder::internal::b_ifWhileCond(r3)) {
              for (int j{0}; j < nPulseList; j++) {
                i = b_X.ps_pos->pl.size(1);
                if (j + 1 > i) {
                  rtDynamicBoundsError(j + 1, 1, i, eb_emlrtBCI);
                }
                timeDiff = b_X.ps_pos->pl[j].t_0;
                if (j + 1 > ps_pre_struc_pl.size(1)) {
                  rtDynamicBoundsError(j + 1, 1, ps_pre_struc_pl.size(1),
                                       fb_emlrtBCI);
                }
                std::printf(
                    "Pulse at %f Hz detected. SNR: %f \n \t Confirmation "
                    "status: %u \n\t Interpulse time    : %f \n",
                    Config.contents.channelCenterFreqMHz +
                        ps_pre_struc_pl[j].fp * 1.0E-6,
                    ps_pre_struc_pl[j].SNR,
                    static_cast<unsigned int>(ps_pre_struc_pl[j].con_dec),
                    timeDiff - previousPulseTime);
                std::fflush(stdout);
                if (timeDiff - previousPulseTime < 0.1 * b_X.ps_pre->t_ip) {
                  // Overlap occasionally will redetect the same pulse
                  std::printf("(\t ^---This likely a repeat of a previously "
                              "detected pulse. Will not be transmitted. \n");
                  std::fflush(stdout);
                  if (j + 1 > pulsesToSkip.size(1)) {
                    rtDynamicBoundsError(j + 1, 1, pulsesToSkip.size(1),
                                         gb_emlrtBCI);
                  }
                  pulsesToSkip[j] = true;
                } else {
                  previousPulseTime = timeDiff;
                }
              }
            } else {
              std::printf("No pulses detected \n");
              std::fflush(stdout);
            }
            pulseCount = 0;
            groupSNRList.set_size(b_X.ps_pos->cpki.size(0),
                                  b_X.ps_pos->cpki.size(1));
            loop_ub = b_X.ps_pos->cpki.size(0) * b_X.ps_pos->cpki.size(1);
            for (i = 0; i < loop_ub; i++) {
              groupSNRList[i] = b_X.ps_pos->cpki[i];
            }
            r3.set_size(groupSNRList.size(0), groupSNRList.size(1));
            loop_ub = groupSNRList.size(0) * groupSNRList.size(1);
            for (i = 0; i < loop_ub; i++) {
              r3[i] = !std::isnan(groupSNRList[i]);
            }
            if (coder::internal::b_ifWhileCond(r3)) {
              std::printf("Transmitting ROS2 pulse messages");
              std::fflush(stdout);
              for (int j{0}; j < nPulseList; j++) {
                c_struct_T b_expl_temp;
                //  %% Build out pulseOut structure parameters for sending
                //  pulseOut.tag_id                     = uint32(Config.ID);
                //  pulseOut.detector_dir               = currDir;%ID is a
                //  string pulseOut.frequency                  =
                //  Config.channelCenterFreqMHz + (X.ps_pos.pl(j).fp)*1e-6;
                //      t_0     = X.ps_pos.pl(j).t_0;
                //      t_f     = X.ps_pos.pl(j).t_f;
                //      t_nxt_0 = X.ps_pos.pl(j).t_next(1);
                //      t_nxt_f = X.ps_pos.pl(j).t_next(2);
                //  pulseOut.start_time.sec             = int32(floor(t_0));
                //  pulseOut.start_time.nanosec         =
                //  uint32(mod(t_0,floor(t_0))*1e9); pulseOut.end_time.sec =
                //  int32(floor(t_f)); pulseOut.end_time.nanosec           =
                //  uint32(mod(t_f,floor(t_f))*1e9);
                //  pulseOut.predict_next_start.sec     = int32(floor(t_nxt_0));
                //  pulseOut.predict_next_start.nanosec =
                //  uint32(mod(t_nxt_0,floor(t_nxt_0))*1e9);
                //  pulseOut.predict_next_end.sec       = int32(floor(t_nxt_f));
                //  pulseOut.predict_next_end.nanosec   =
                //  uint32(mod(t_nxt_f,round(t_nxt_f))*1e9); pulseOut.snr =
                //  X.ps_pos.pl(j).SNR; pulseOut.stft_score                 =
                //  real(X.ps_pos.pl(j).yw); pulseOut.group_ind = uint16(j);
                //  groupSNRList = 10.^([X.ps_pos.pl(:).SNR]/10);%Average SNR in
                //  dB groupSNRMeanLinear                  =
                //  mean(groupSNRList,'all'); if groupSNRMeanLinear<0
                //      groupSNRMeanDB                  = -Inf;
                //  else
                //      groupSNRMeanDB                  =
                //      10*log10(groupSNRMeanLinear);
                //  end
                //  %10log10 can produce complex results and group_snr required
                //  a real value. Otherwise coder will %generate type errors
                //  pulseOut.group_snr          =
                //  double(groupSNRMeanDB);%10*log10(mean(10.^([X.ps_pos.clst(X.ps_pos.cpki(j),:).SNR]/10)));%Average
                //  SNR in dB pulseOut.detection_status   =
                //  X.ps_pos.pl(j).det_dec; pulseOut.confirmed_status   =
                //  X.ps_pos.pl(j).con_dec;
                b_currDir = b_X.ps_pos->pl.size(1);
                d_X.set_size(b_currDir);
                loop_ub = b_currDir - 1;
                for (i = 0; i <= loop_ub; i++) {
                  d_X[i] = b_X.ps_pos->pl[i];
                }
                coder::internal::d_horzcatStructList(d_X, groupSNRList);
                nx = groupSNRList.size(0) * groupSNRList.size(1);
                for (i = 0; i < nx; i++) {
                  timeDiff = groupSNRList[i] / 10.0;
                  groupSNRList[i] = rt_powd_snf(10.0, timeDiff);
                }
                // Average SNR in dB
                b_groupSNRList = groupSNRList.reshape(nx);
                timeDiff = coder::combineVectorElements(b_groupSNRList) /
                           static_cast<double>(nx);
                // 10log10 can produce complex results and group_snr required a
                // real value. Otherwise coder will generate type errors
                // 10*log10(mean(10.^([X.ps_pos.clst(X.ps_pos.cpki(j),:).SNR]/10)));%Average
                // SNR in dB
                //  Publish pulses to UDP
                i = b_X.ps_pos->pl.size(1);
                if (j + 1 > i) {
                  rtDynamicBoundsError(j + 1, 1, i, hb_emlrtBCI);
                }
                b_expl_temp = b_X.ps_pos->pl[j];
                if (timeDiff < 0.0) {
                  timeDiff = rtMinusInf;
                } else {
                  timeDiff = 10.0 * std::log10(timeDiff);
                }
                currPulseOut.init(b_expl_temp.SNR, b_expl_temp.yw,
                                  b_expl_temp.t_0, b_expl_temp.t_f,
                                  b_expl_temp.t_next, b_expl_temp.fp,
                                  b_expl_temp.det_dec, b_expl_temp.con_dec,
                                  Config.contents.ID, currDir,
                                  Config.contents.channelCenterFreqMHz,
                                  static_cast<double>(j) + 1.0, timeDiff);
                if (j + 1 > pulsesToSkip.size(1)) {
                  rtDynamicBoundsError(j + 1, 1, pulsesToSkip.size(1),
                                       ib_emlrtBCI);
                }
                if (!pulsesToSkip[j]) {
                  unsigned char mavlinkTunnelMsg[53];
                  currPulseOut.formatForTunnelMsg(mavlinkTunnelMsg);
                  // tunnelPulse = formatPulseForTunnel(255, 0, 0, pulseOut);
                  udpPulseOut.step(mavlinkTunnelMsg);
                  //                                     %% Package and send
                  //                                     ROS2 pulse message
                  pulseMsg.detector_dir.set_size(
                      1, currPulseOut.detector_dir.Value.size(1));
                  loop_ub = currPulseOut.detector_dir.Value.size(1);
                  for (i = 0; i < loop_ub; i++) {
                    pulseMsg.detector_dir[i] =
                        currPulseOut.detector_dir.Value[i];
                  }
                  pulseMsg.tag_id = currPulseOut.tag_id;
                  pulseMsg.frequency = currPulseOut.frequency;
                  pulseMsg.start_time.sec = currPulseOut.start_time_sec;
                  pulseMsg.start_time.nanosec = currPulseOut.start_time_nanosec;
                  pulseMsg.end_time.sec = currPulseOut.end_time_sec;
                  pulseMsg.end_time.nanosec = currPulseOut.end_time_nanosec;
                  pulseMsg.predict_next_start.sec =
                      currPulseOut.predict_next_start_sec;
                  pulseMsg.predict_next_start.nanosec =
                      currPulseOut.predict_next_start_nanosec;
                  pulseMsg.predict_next_end.sec =
                      currPulseOut.predict_next_end_sec;
                  pulseMsg.predict_next_end.nanosec =
                      currPulseOut.predict_next_end_nanosec;
                  pulseMsg.snr = currPulseOut.snr;
                  pulseMsg.stft_score = currPulseOut.stft_score;
                  pulseMsg.group_ind = currPulseOut.group_ind;
                  pulseMsg.group_snr = currPulseOut.group_snr;
                  pulseMsg.detection_status = currPulseOut.detection_status;
                  pulseMsg.confirmed_status = currPulseOut.confirmed_status;
                  MATLABROS2Publisher_publish(pulsePub.PublisherHelper,
                                              &pulseMsg);
                  pulseCount++;
                }
                //  %s pulseMsg.detector_dir
                //  %s pulseMsg.tag_id
                //  %.6f pulseMsg.frequency
                //  %d pulseMsg.start_time.sec
                //  %u pulseMsg.start_time.nanosec
                //  %d pulseMsg.end_time.sec
                //  %u pulseMsg.end_time.nanosec
                //  %d pulseMsg.predict_next_start.sec
                //  %u pulseMsg.predict_next_start.nanosec
                //  %d pulseMsg.predict_next_end.sec
                //  %u pulseMsg.predict_next_end.nanosec
                //  %.2f pulseMsg.snr
                //  %.3e pulseMsg.dft_real
                //  %.3e pulseMsg.dft_imag
                //  %u pulseMsg.group_ind
                //  %.2e pulseMsg.group_snr
                //  logicalStr = {'0','1'}
                //  %u logicalStr{int8(pulseMsg.detection_status)+1}
                //  %u logicalStr{int8(pulseMsg.confirmed_status)+1}
                //
                //                                          logicalStr =
                //                                          {'0','1'};
                //                                          formatSpecPulseMsg =
                //                                          ['%.6f',',','%d',',','%u','%d',',','%u',',','%d',',','%u',',','%d',',','%u',',',...
                //                                                                '%.2f',',','%.3e',',','%.3e',',','%u',',','%.2e',',','%c',',','%c','\n'];
                //
                //                                          fprintf(pulseWriterFileID,formatSpecPulseMsg,...
                //                                              pulseMsg.frequency,...
                //                                              pulseMsg.start_time.sec,...
                //                                              pulseMsg.start_time.nanosec,...
                //                                              pulseMsg.end_time.sec,...
                //                                              pulseMsg.end_time.nanosec,...
                //                                              pulseMsg.predict_next_start.sec,...
                //                                              pulseMsg.predict_next_start.nanosec,...
                //                                              pulseMsg.predict_next_end.sec,...
                //                                              pulseMsg.predict_next_end.nanosec,...
                //                                              pulseMsg.snr,...
                //                                              pulseMsg.dft_real,...
                //                                              pulseMsg.dft_imag,...
                //                                              pulseMsg.group_ind,...
                //                                              pulseMsg.group_snr,...
                //                                              logicalStr{int8(pulseMsg.detection_status)+1},...
                //                                              logicalStr{int8(pulseMsg.confirmed_status)+1});
                std::printf(".");
                std::fflush(stdout);
                //                                     end
              }
              std::printf("complete. Transmitted %u pulse(s).\n",
                          static_cast<unsigned int>(pulseCount));
              std::fflush(stdout);
            } else {
              std::printf("\n");
              std::fflush(stdout);
            }
            varargin_1.set_size(1, 2);
            varargin_1[0] = ps_pre_struc_mode[0];
            varargin_1[1] = '\x00';
            std::printf("Current Mode: %s\n", &varargin_1[0]);
            std::fflush(stdout);
            std::printf("====================================\n");
            std::fflush(stdout);
          }
          b_this.init();
          timeDiff = coder::toc();
          std::printf("tocElapsed - clockElapsed = %0.6f  **************** \n",
                      timeDiff - (std::round(b_this.data.re / 1000.0 * 1.0E+6) /
                                      1.0E+6 -
                                  startTime));
          std::fflush(stdout);
          timeDiff = coder::toc() - processingStartToc;
          std::printf("TOTAL SEGMENT PROCESSING TIME: %f seconds \n", timeDiff);
          std::fflush(stdout);
          //  packetTimeSec = (packetLength-1)*1/Config.Fs;
          //  segmentTimeSec  = 1/Config.Fs * sampsForKPulses;
          //  sleepTime = segmentTimeSec  - packetTimeSec -  totalLoopTime;
          //  if sleepTime < 0
          //      fprintf('WARNING: CALCULATED SLEEP TIME IS NEGATIVE MEANING
          //      THAT I AM NOT KEEPING UP WITH THE INCOMING DATA RATE \n');
          //  else
          //      % if isdeployed
          //      %     coder.ceval('usleep',uint32(sleepTime * 1e6));
          //      % else
          //      %     pause(sleepTime);
          //      % end
          //  end
        }
      }
      if (coder::toc() >= tocAtLastCommandCheck + 1.0) {
        // no faster than every 1 s check for new commands
        tocAtLastCommandCheck = coder::toc();
        controlreceiver(Config.contents.portCntrl, cmdReceived);
        previousState.set_size(1, e_state.size(1));
        loop_ub = e_state.size(1);
        varargin_1.set_size(1, e_state.size(1));
        for (i = 0; i < loop_ub; i++) {
          previousState[i] = e_state[i];
          varargin_1[i] = e_state[i];
        }
        checkcommand(cmdReceived, varargin_1);
        if (varargin_1.size(1) > 64) {
          rtDimSizeGeqError(64, varargin_1.size(1), o_emlrtECI);
        }
        e_state.set_size(1, varargin_1.size(1));
        loop_ub = varargin_1.size(1);
        for (i = 0; i < loop_ub; i++) {
          e_state[i] = varargin_1[i];
        }
      }
    } break;
    case 1:
      if (coder::b_mod(idleTic) == 0.0) {
        std::printf("Waiting in idle state...\n");
        std::fflush(stdout);
        idleTic = 1.0;
      }
      idleTic++;
      asyncWriteBuff.read(dataWriterBuffData);
      if (fileid != -1) {
        interleaveComplexVector(dataWriterBuffData, r1);
        coder::b_fwrite(static_cast<double>(fileid), r1);
      }
      asyncDataBuff.reset();
      asyncTimeBuff.reset();
      asyncWriteBuff.reset();
      coder::pause(0.25);
      // Wait a bit so to throttle idle execution
      staleDataFlag = true;
      resetUdp = true;
      controlreceiver(Config.contents.portCntrl, cmdReceived);
      previousState.set_size(1, e_state.size(1));
      loop_ub = e_state.size(1);
      varargin_1.set_size(1, e_state.size(1));
      for (i = 0; i < loop_ub; i++) {
        previousState[i] = e_state[i];
        varargin_1[i] = e_state[i];
      }
      checkcommand(cmdReceived, varargin_1);
      if (varargin_1.size(1) > 64) {
        rtDimSizeGeqError(64, varargin_1.size(1), j_emlrtECI);
      }
      e_state.set_size(1, varargin_1.size(1));
      loop_ub = varargin_1.size(1);
      for (i = 0; i < loop_ub; i++) {
        e_state[i] = varargin_1[i];
      }
      break;
    case 2:
      // Write all remaining data in buffer before clearing
      asyncWriteBuff.read(dataWriterBuffData);
      if (fileid != -1) {
        interleaveComplexVector(dataWriterBuffData, r1);
        coder::b_fwrite(static_cast<double>(fileid), r1);
      }
      updateconfig(Config, configPath);
      configUpdatedFlag = true;
      // Reset all the buffers and setup the buffer read variables
      asyncDataBuff.reset();
      asyncTimeBuff.reset();
      asyncWriteBuff.reset();
      // This sets up a standarized pulsestats object based on the config
      // passed to it.
      r.A = makepulsestruc(r.t_next, r.mode, r.P, r.SNR, r.yw, r.t_0, r.t_f,
                           r.fp, r.fstart, r.fend, r.det_dec, r.con_dec);
      timeDiff = makepulsestruc(expl_temp.t_next, expl_temp.mode, timeStamp,
                                t10_SNR, t10_yw, t10_t_0, t10_t_f, t10_fp,
                                t10_fstart, t10_fend, t10_det_dec, t10_con_dec);
      expl_temp.con_dec = t10_con_dec;
      expl_temp.det_dec = t10_det_dec;
      expl_temp.fend = t10_fend;
      expl_temp.fstart = t10_fstart;
      expl_temp.fp = t10_fp;
      expl_temp.t_f = t10_t_f;
      expl_temp.t_0 = t10_t_0;
      expl_temp.yw = t10_yw;
      expl_temp.SNR = t10_SNR;
      expl_temp.P = timeStamp;
      expl_temp.A = timeDiff;
      pulseStatsPriori =
          lobj_21.init(Config.contents.tp, Config.contents.tip,
                       Config.contents.tipu, Config.contents.tipj,
                       1.0E-5 * std::abs(Config.contents.tagFreqMHz -
                                         Config.contents.channelCenterFreqMHz),
                       r, expl_temp);
      updatebufferreadvariables(Config, stftOverlapFraction, overlapSamples,
                                sampsForKPulses, pulseStatsPriori);
      // Check control and update states
      staleDataFlag = true;
      resetUdp = true;
      controlreceiver(Config.contents.portCntrl, cmdReceived);
      if ((cmdReceived.size(0) != 0) && (cmdReceived.size(1) != 0)) {
        previousState.set_size(1, e_state.size(1));
        loop_ub = e_state.size(1);
        varargin_1.set_size(1, e_state.size(1));
        for (i = 0; i < loop_ub; i++) {
          previousState[i] = e_state[i];
          varargin_1[i] = e_state[i];
        }
        checkcommand(cmdReceived, varargin_1);
        if (varargin_1.size(1) > 64) {
          rtDimSizeGeqError(64, varargin_1.size(1), i_emlrtECI);
        }
        e_state.set_size(1, varargin_1.size(1));
        loop_ub = varargin_1.size(1);
        for (i = 0; i < loop_ub; i++) {
          e_state[i] = varargin_1[i];
        }
      } else {
        // On no command after config update, default to previous state
        e_state.set_size(1, previousState.size(1));
        loop_ub = previousState.size(1);
        for (i = 0; i < loop_ub; i++) {
          e_state[i] = previousState[i];
        }
        previousState.set_size(1, 12);
        for (i = 0; i < 12; i++) {
          previousState[i] = cv[i];
        }
      }
      break;
    case 3: {
      if (coder::b_mod(idleTic) == 0.0) {
        unsigned char mavlinkTunnelMsg[53];
        std::printf("In test mode. Publishing one test pulse per second.\n");
        std::fflush(stdout);
        idleTic = 1.0;
        //  pulseOut.tag_id                     = uint32(Config.ID);
        //  pulseOut.detector_dir               = currDir;%ID is a string
        //  pulseOut.frequency                  = Config.tagFreqMHz;
        //  t_0     = posixtime(datetime('now'));
        //  t_f     = 0;
        //  t_nxt_0 = 1;
        //  t_nxt_f = 2;
        //  pulseOut.start_time.sec             = int32(floor(t_0));
        //  pulseOut.start_time.nanosec         =
        //  uint32(mod(t_0,floor(t_0))*1e9); pulseOut.end_time.sec =
        //  int32(floor(t_f)); pulseOut.end_time.nanosec           =
        //  uint32(mod(t_f,floor(t_f))*1e9); pulseOut.predict_next_start.sec =
        //  int32(floor(t_nxt_0)); pulseOut.predict_next_start.nanosec =
        //  uint32(mod(t_nxt_0,floor(t_nxt_0))*1e9);
        //  pulseOut.predict_next_end.sec       = int32(floor(t_nxt_f));
        //  pulseOut.predict_next_end.nanosec   =
        //  uint32(mod(t_nxt_f,round(t_nxt_f))*1e9); pulseOut.snr = 1;
        //  pulseOut.stft_score                 = 1;
        //  pulseOut.group_ind                  = uint16(1);
        //  pulseOut.group_snr          = 1;
        //  pulseOut.detection_status   = false;
        //  pulseOut.confirmed_status   = true;
        //                 %% Publish pulses to UDP
        currPulseOut.b_init();
        currPulseOut.formatForTunnelMsg(mavlinkTunnelMsg);
        // tunnelPulse = formatPulseForTunnel(255, 0, 0, pulseOut);
        udpPulseOut.step(mavlinkTunnelMsg);
      }
      idleTic++;
      asyncDataBuff.reset();
      asyncTimeBuff.reset();
      asyncWriteBuff.reset();
      coder::pause(0.25);
      // Wait a bit so to throttle idle execution
      staleDataFlag = true;
      resetUdp = true;
      controlreceiver(Config.contents.portCntrl, cmdReceived);
      previousState.set_size(1, e_state.size(1));
      loop_ub = e_state.size(1);
      varargin_1.set_size(1, e_state.size(1));
      for (i = 0; i < loop_ub; i++) {
        previousState[i] = e_state[i];
        varargin_1[i] = e_state[i];
      }
      checkcommand(cmdReceived, varargin_1);
      if (varargin_1.size(1) > 64) {
        rtDimSizeGeqError(64, varargin_1.size(1), h_emlrtECI);
      }
      e_state.set_size(1, varargin_1.size(1));
      loop_ub = varargin_1.size(1);
      for (i = 0; i < loop_ub; i++) {
        e_state[i] = varargin_1[i];
      }
    } break;
    case 4:
      exitg1 = 1;
      break;
    default:
      // Should never get to this case, but jump to idle if we get
      // here.
      previousState.set_size(1, e_state.size(1));
      loop_ub = e_state.size(1);
      for (i = 0; i < loop_ub; i++) {
        previousState[i] = e_state[i];
      }
      e_state.set_size(1, 4);
      e_state[0] = 'i';
      e_state[1] = 'd';
      e_state[2] = 'l';
      e_state[3] = 'e';
      break;
    }
  } while (exitg1 == 0);
  // Send command to release the udp system objects
  // CONTROLRECEIVER receives control signal data from the
  // via the specified local IP port from the specified remote IP.
  //
  // This function is defined to receive integer control commands and pass
  // those receive integers as output. The remoteIP port is not tunable and is
  // only used on the first call to setup the dsp.UDPReceiver object. Changing
  // it on ubsequent calls will do nothing to change the receiver. The local
  // IP port is tuneable however. This funtion uses persistant variables and
  // must be cleared if subsequent calls are needed to change the remote IP.
  // For example call
  //
  //    mycntrl = controlreceiver('127.0.0.1',12345);
  //    mynewercntrl = controlreceiver('127.0.0.1',12345);
  //    mynewercntrlfromdifferentport = controlreceiver('127.0.0.1',54321);
  //    clear channelreceiver
  //    cntrlfromnewip = controlreceiver('127.0.0.2',12345);
  //
  // INPUTS:
  //    remoteIP    A string of the remote IP address from which to accept
  //                messages
  //                Example: '127.0.0.1' - local machine
  //                         '0.0.0.0'   - receive from any remote IP
  //                         '127.0.0.7' - receive from some other IP on the
  //                                       network
  //    localIPPort     Scalar value of the port on which to receive the
  //                    message.
  //    releaseSysObj   Logical to release the dsp.UDPReceiver system object
  //
  // OUTPUTS:
  //    dataReceived    The received real scalar command message passed.
  //                    Received messages are int8.
  //                    Maximum length is 1025
  //
  // Author:    Michael W. Shafer
  // Date:      2022-02-16
  // --------------------------------------------------------------------------
  // Reset to clear the buffer of stale data.
  if (!b_udpRx_not_empty) {
    b_udpRx.isInitialized = 0;
    // System object Constructor function: dsp.UDPReceiver
    b_udpRx.cSFunObject.P0_Port = 25000;
    b_udpRx.LocalIPPort = 25000.0;
    b_udpRx.matlabCodegenIsDeleted = false;
    b_udpRx_not_empty = true;
    // %127.0.0.1',... %Accept all
    // %2^16 = 65536, 2^18
  }
  b_udpRx.release();
  // CHANNELRECEIVER receives channelized data from the channelizer function
  // via the specified local IP port from the specified remote IP.
  //
  // This function is defined to interact with airspyhf_channelizer which
  // outputs 1024 samples of IQ with a timestamp for a total of 1025 complex
  // single precision values. The remoteIP port is not tunable and is only used
  // on the first call to setup the dsp.UDPReceiver object. Changing it on
  // subsequent calls will do nothing to change the receiver. The local IP port
  // is tunable however. This funtion uses persistant variables and must be
  // cleared if subsequent calls are needed to change the remote IP. For
  // example call
  //
  //    mydata = channelreceiver('127.0.0.1',12345);
  //    mynewerdata = channelreceiver('127.0.0.1',12345);
  //    mynewerdatafromdifferentport = channelreceiver('127.0.0.1',54321);
  //    clear channelreceiver
  //    datafromnewip = channelreceiver('127.0.0.2',12345);
  //
  // INPUTS:
  //    remoteIP    A string of the remote IP address from which to accept data
  //                Example: '127.0.0.1' - local machine
  //                         '0.0.0.0'   - receive from any remote IP
  //                         '127.0.0.7' - receive from some other IP on the
  //                                       network
  //    localIPPort     Scalar value of the port on which to receive the data.
  //    resetUDP        Logic to reset the persistant udp object
  //    releaseSysObj   Logical to release the dsp.UDPReceiver system object
  //
  // OUTPUTS:
  //    dataReceived    A vector of received  complex single precision values.
  //                    Maximum length is 1025
  //
  // Author:    Michael W. Shafer
  // Date:      2022-02-14
  // --------------------------------------------------------------------------
  // Reset to clear the buffer of stale data.
  if (!udpRx_not_empty) {
    udpRx.isInitialized = 0;
    // System object Constructor function: dsp.UDPReceiver
    udpRx.cSFunObject.P0_Port = 25000;
    udpRx.LocalIPPort = 25000.0;
    udpRx.matlabCodegenIsDeleted = false;
    udpRx_not_empty = true;
    // %127.0.0.1',... %Accept all
    // %2^16 = 65536, 2^18
  }
  if (udpRx.isInitialized == 2) {
    rtErrorWithMessageID("reset", b_emlrtRTEI.fName, b_emlrtRTEI.lineNo);
  }
  udpRx.release();
  asyncWriteBuff.read(dataWriterBuffData);
  if (fileid != -1) {
    interleaveComplexVector(dataWriterBuffData, r1);
    coder::b_fwrite(static_cast<double>(fileid), r1);
  }
  asyncDataBuff.reset();
  asyncTimeBuff.reset();
  asyncWriteBuff.reset();
  asyncDataBuff.release();
  asyncTimeBuff.release();
  asyncWriteBuff.release();
  nx = coder::internal::cfclose(static_cast<double>(fileid));
  if (nx == -1) {
    rtErrorWithMessageID(emlrtRTEI.fName, emlrtRTEI.lineNo);
  }
  //              fCloseStatusPulseWriter = fclose(pulseWriterFileID);
  //              if fCloseStatusPulseWriter == -1
  //                  error('UAV-RT: Error closing pulse record file. ')
  //              end
  // release(writer);
  udpPulseOut.matlabCodegenDestructor();
  asyncWriteBuff.matlabCodegenDestructor();
  asyncWriteBuff.pBuffer.matlabCodegenDestructor();
  asyncTimeBuff.matlabCodegenDestructor();
  asyncTimeBuff.pBuffer.matlabCodegenDestructor();
  asyncDataBuff.matlabCodegenDestructor();
  asyncDataBuff.pBuffer.matlabCodegenDestructor();
}

// End of code generation (uavrt_detection.cpp)
