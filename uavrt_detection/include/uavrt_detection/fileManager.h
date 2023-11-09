//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// fileManager.h
//
// Code generation for function 'fileManager'
//

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdio>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
int cfclose(double fid);

signed char cfopen(const ::coder::array<char, 2U> &cfilename);

signed char cfopen(const char cfilename[25]);

std::FILE *getfilestar(double fid, bool &autoflush);

} // namespace internal
} // namespace coder
void filedata_init();

#endif
// End of code generation (fileManager.h)
