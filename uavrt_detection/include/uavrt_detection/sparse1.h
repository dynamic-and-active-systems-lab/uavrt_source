//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// sparse1.h
//
// Code generation for function 'sparse1'
//

#ifndef SPARSE1_H
#define SPARSE1_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
class f_sparse;

class g_sparse;

class c_sparse;

class d_sparse;

class h_sparse;

} // namespace coder

// Type Definitions
namespace coder {
class sparse {
public:
  static void assertValidIndexArg(const ::coder::array<double, 1U> &s,
                                  ::coder::array<int, 1U> &sint);
  void mtimes(const ::coder::array<double, 2U> &a,
              ::coder::array<double, 2U> &c) const;
  static void eyeLike(int ndiag, int b_m, int b_n, sparse &b_I);
  void logical(f_sparse &y) const;
  void parenReference(g_sparse &s) const;
  void parenReference(const ::coder::array<double, 1U> &varargin_2,
                      sparse &s) const;
  void fillIn();
  static void b_realloc(f_sparse *b_this, int numAllocRequested, int ub1,
                        int lb2, int ub2);
  array<double, 1U> d;
  array<int, 1U> colidx;
  array<int, 1U> rowidx;
  int m;
  int n;
  int maxnz;
};

class b_sparse {
public:
  void parenReference(c_sparse &s) const;
  void c_le(d_sparse &s) const;
  void eq(const c_sparse &b, d_sparse &s) const;
  array<double, 1U> d;
  array<int, 1U> colidx;
  array<int, 1U> rowidx;
  int n;
};

class c_sparse {
public:
  array<double, 1U> d;
  array<int, 1U> colidx;
  array<int, 1U> rowidx;
};

class d_sparse {
public:
  void b_not(d_sparse &out) const;
  array<bool, 1U> d;
  array<int, 1U> colidx;
  array<int, 1U> rowidx;
  int n;
};

class e_sparse {
public:
  array<bool, 1U> d;
  array<int, 1U> colidx;
  array<int, 1U> rowidx;
};

class f_sparse {
public:
  void parenReference(const ::coder::array<double, 2U> &varargin_1,
                      d_sparse &s) const;
  void mtimes(const ::coder::array<double, 2U> &b,
              ::coder::array<double, 2U> &c) const;
  void b_mtimes(const ::coder::array<double, 2U> &a,
                ::coder::array<double, 2U> &c) const;
  void parenAssign(const ::coder::array<bool, 1U> &rhs,
                   const ::coder::array<double, 2U> &varargin_1);
  void parenAssign2D(bool rhs, double r, double c);
  void b_parenAssign(const ::coder::array<bool, 2U> &rhs,
                     const ::coder::array<double, 2U> &varargin_1);
  void c_parenAssign(const h_sparse &rhs,
                     const ::coder::array<double, 2U> &varargin_1);
  void c_parenAssign(const ::coder::array<double, 2U> &rhs,
                     const ::coder::array<double, 2U> &varargin_1);
  array<bool, 1U> d;
  array<int, 1U> colidx;
  array<int, 1U> rowidx;
  int m;
  int n;
  int maxnz;
};

class g_sparse {
public:
  void logical(h_sparse &y) const;
  array<double, 1U> d;
  array<int, 1U> colidx;
  array<int, 1U> rowidx;
  int m;
  int maxnz;
};

class h_sparse {
public:
  array<bool, 1U> d;
  array<int, 1U> colidx;
  array<int, 1U> rowidx;
  int m;
};

} // namespace coder

#endif
// End of code generation (sparse1.h)
