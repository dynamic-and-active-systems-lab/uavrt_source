//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// FFTImplementationCallback.h
//
// Code generation for function 'FFTImplementationCallback'
//

#ifndef FFTIMPLEMENTATIONCALLBACK_H
#define FFTIMPLEMENTATIONCALLBACK_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
namespace internal {
namespace fft {
class FFTImplementationCallback {
public:
  static void dobluesteinfft(const ::coder::array<creal32_T, 2U> &x, int n2blue,
                             int nfft, const ::coder::array<float, 2U> &costab,
                             const ::coder::array<float, 2U> &sintab,
                             const ::coder::array<float, 2U> &sintabinv,
                             ::coder::array<creal32_T, 2U> &y);
  static void generate_twiddle_tables(int nRows, bool useRadix2,
                                      ::coder::array<double, 2U> &costab,
                                      ::coder::array<double, 2U> &sintab,
                                      ::coder::array<double, 2U> &sintabinv);
  static void r2br_r2dit_trig_impl(const ::coder::array<creal_T, 1U> &x,
                                   int unsigned_nRows,
                                   const ::coder::array<double, 2U> &costab,
                                   const ::coder::array<double, 2U> &sintab,
                                   ::coder::array<creal_T, 1U> &y);
  static void dobluesteinfft(const ::coder::array<creal_T, 3U> &x, int n2blue,
                             int nfft, const ::coder::array<double, 2U> &costab,
                             const ::coder::array<double, 2U> &sintab,
                             const ::coder::array<double, 2U> &sintabinv,
                             ::coder::array<creal_T, 3U> &y);

protected:
  static void r2br_r2dit_trig_impl(const ::coder::array<creal32_T, 1U> &x,
                                   int unsigned_nRows,
                                   const ::coder::array<float, 2U> &costab,
                                   const ::coder::array<float, 2U> &sintab,
                                   ::coder::array<creal32_T, 1U> &y);
};

} // namespace fft
} // namespace internal
} // namespace coder

#endif
// End of code generation (FFTImplementationCallback.h)
