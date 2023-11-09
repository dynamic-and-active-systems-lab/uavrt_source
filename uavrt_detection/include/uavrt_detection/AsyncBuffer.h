//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// AsyncBuffer.h
//
// Code generation for function 'AsyncBuffer'
//

#ifndef ASYNCBUFFER_H
#define ASYNCBUFFER_H

// Include files
#include "AsyncBuffercgHelper.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
namespace dsp {
class AsyncBuffer {
public:
  void reset();
  void write(const ::coder::array<creal32_T, 1U> &in);
  void read(double numRows, ::coder::array<creal32_T, 1U> &out);
  void read(double numRows, double overlap, ::coder::array<creal32_T, 1U> &out);
  void release();
  void matlabCodegenDestructor();
  ~AsyncBuffer();
  AsyncBuffer();
  bool matlabCodegenIsDeleted;
  internal::AsyncBuffercgHelper pBuffer;
};

class b_AsyncBuffer {
public:
  void write(const ::coder::array<double, 1U> &in);
  void read(double numRows, ::coder::array<double, 1U> &out);
  void read(double numRows, double overlap, ::coder::array<double, 1U> &out);
  void release();
  void reset();
  void matlabCodegenDestructor();
  ~b_AsyncBuffer();
  b_AsyncBuffer();
  bool matlabCodegenIsDeleted;
  internal::b_AsyncBuffercgHelper pBuffer;
};

class c_AsyncBuffer {
public:
  void write();
  void read();
  void reset();
  void write(const ::coder::array<creal32_T, 1U> &in);
  void read(::coder::array<creal32_T, 1U> &out);
  void release();
  void matlabCodegenDestructor();
  ~c_AsyncBuffer();
  c_AsyncBuffer();
  bool matlabCodegenIsDeleted;
  internal::c_AsyncBuffercgHelper pBuffer;
};

} // namespace dsp
} // namespace coder

#endif
// End of code generation (AsyncBuffer.h)
