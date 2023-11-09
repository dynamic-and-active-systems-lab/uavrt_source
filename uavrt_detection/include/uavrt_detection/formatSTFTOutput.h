//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// formatSTFTOutput.h
//
// Code generation for function 'formatSTFTOutput'
//

#ifndef FORMATSTFTOUTPUT_H
#define FORMATSTFTOUTPUT_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace b_signal {
namespace internal {
namespace stft {
void formatSTFTOutput(::coder::array<creal_T, 3U> &S,
                      const ::coder::array<double, 1U> &F,
                      ::coder::array<double, 1U> &Fout);

}
} // namespace internal
} // namespace b_signal
} // namespace coder

#endif
// End of code generation (formatSTFTOutput.h)
