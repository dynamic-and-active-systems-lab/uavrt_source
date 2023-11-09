//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// validate_print_arguments.cpp
//
// Code generation for function 'validate_print_arguments'
//

// Include files
#include "validate_print_arguments.h"
#include "rt_nonfinite.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"

// Function Definitions
namespace coder {
namespace internal {
void validate_print_arguments(unsigned int varargin_1, unsigned int varargin_2,
                              unsigned int varargin_3,
                              unsigned int validatedArguments[3])
{
  validatedArguments[0] = varargin_1;
  validatedArguments[1] = varargin_2;
  validatedArguments[2] = varargin_3;
}

void validate_print_arguments(double varargin_1, double varargin_2,
                              double varargin_3, double validatedArguments[3])
{
  validatedArguments[0] = varargin_1;
  validatedArguments[1] = varargin_2;
  validatedArguments[2] = varargin_3;
}

} // namespace internal
} // namespace coder

// End of code generation (validate_print_arguments.cpp)
