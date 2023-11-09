//
// Prerelease License - for engineering feedback and testing purposes
// only. Not for sale.
//
// strcmp.cpp
//
// Code generation for function 'strcmp'
//

// Include files
#include "strcmp.h"
#include "rt_nonfinite.h"
#include "string1.h"
#include "uavrt_detection_data.h"
#include "DAHostLib_Network.h"
#include "DAHostLib_rtw.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
namespace internal {
bool ab_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[5]{'f', 'a', 'l', 's', 'e'};
  bool b_bool;
  b_bool = false;
  if (a.size(1) == 5) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 5) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool b_strcmp(const b_rtString &a)
{
  static const char b_cv[16]{'f', 'r', 'e', 'q', 'A', 'l', 'l', 'N',
                             'e', 'v', 'e', 'r', 'L', 'o', 'c', 'k'};
  bool b_bool;
  b_bool = false;
  if (a.Value.size(1) == 16) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 16) {
        if (a.Value[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool b_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[3]{'r', 'u', 'n'};
  bool b_bool;
  b_bool = false;
  if (a.size(1) == 3) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 3) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool bb_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[15]{'s', 't', 'a', 'r', 't', 'I', 'n', 'R',
                             'u', 'n', 'S', 't', 'a', 't', 'e'};
  bool b_bool;
  b_bool = false;
  if (a.size(1) == 15) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 15) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool c_strcmp(const b_rtString &a)
{
  bool b_bool;
  b_bool = false;
  if (a.Value.size(1) == 18) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 18) {
        if (a.Value[kstr] != cv5[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool c_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[4]{'i', 'd', 'l', 'e'};
  bool b_bool;
  b_bool = false;
  if (a.size(1) == 4) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 4) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool cb_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[6]{'s', 'e', 'a', 'r', 'c', 'h'};
  bool b_bool;
  b_bool = false;
  if (a.size(1) == 6) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 6) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool d_strcmp(const ::coder::array<char, 2U> &a)
{
  bool b_bool;
  b_bool = false;
  if (a.size(1) == 12) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 12) {
        if (a[kstr] != cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool db_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[7]{'c', 'o', 'n', 'f', 'i', 'r', 'm'};
  bool b_bool;
  b_bool = false;
  if (a.size(1) == 7) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 7) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool e_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[4]{'t', 'e', 's', 't'};
  bool b_bool;
  b_bool = false;
  if (a.size(1) == 4) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 4) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool eb_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[5]{'t', 'r', 'a', 'c', 'k'};
  bool b_bool;
  b_bool = false;
  if (a.size(1) == 5) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 5) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool f_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[4]{'k', 'i', 'l', 'l'};
  bool b_bool;
  b_bool = false;
  if (a.size(1) == 4) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 4) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool fb_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[5]{'n', 'a', 'i', 'v', 'e'};
  bool b_bool;
  b_bool = false;
  if (a.size(1) == 5) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 5) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool g_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[2]{'I', 'D'};
  bool b_bool;
  b_bool = false;
  if (a.size(1) == 2) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 2) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool gb_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[8]{'i', 'n', 'f', 'o', 'r', 'm', 'e', 'd'};
  bool b_bool;
  b_bool = false;
  if (a.size(1) == 8) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 8) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool h_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[20]{'c', 'h', 'a', 'n', 'n', 'e', 'l', 'C', 'e', 'n',
                             't', 'e', 'r', 'F', 'r', 'e', 'q', 'M', 'H', 'z'};
  bool b_bool;
  b_bool = false;
  if (a.size(1) == 20) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 20) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool i_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[6]{'i', 'p', 'D', 'a', 't', 'a'};
  bool b_bool;
  b_bool = false;
  if (a.size(1) == 6) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 6) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool j_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[8]{'p', 'o', 'r', 't', 'D', 'a', 't', 'a'};
  bool b_bool;
  b_bool = false;
  if (a.size(1) == 8) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 8) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool k_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[7]{'i', 'p', 'C', 'n', 't', 'r', 'l'};
  bool b_bool;
  b_bool = false;
  if (a.size(1) == 7) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 7) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool l_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[9]{'p', 'o', 'r', 't', 'C', 'n', 't', 'r', 'l'};
  bool b_bool;
  b_bool = false;
  if (a.size(1) == 9) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 9) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool m_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[2]{'F', 's'};
  bool b_bool;
  b_bool = false;
  if (a.size(1) == 2) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 2) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool n_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[10]{'t', 'a', 'g', 'F', 'r', 'e', 'q', 'M', 'H', 'z'};
  bool b_bool;
  b_bool = false;
  if (a.size(1) == 10) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 10) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool o_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[2]{'t', 'p'};
  bool b_bool;
  b_bool = false;
  if (a.size(1) == 2) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 2) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool p_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[3]{'t', 'i', 'p'};
  bool b_bool;
  b_bool = false;
  if (a.size(1) == 3) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 3) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool q_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[4]{'t', 'i', 'p', 'u'};
  bool b_bool;
  b_bool = false;
  if (a.size(1) == 4) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 4) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool r_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[4]{'t', 'i', 'p', 'j'};
  bool b_bool;
  b_bool = false;
  if (a.size(1) == 4) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 4) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool s_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[6]{'o', 'p', 'M', 'o', 'd', 'e'};
  bool b_bool;
  b_bool = false;
  if (a.size(1) == 6) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 6) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool t_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[10]{'e', 'x', 'c', 'l', 'd', 'F', 'r', 'e', 'q', 's'};
  bool b_bool;
  b_bool = false;
  if (a.size(1) == 10) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 10) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool u_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[14]{'f', 'a', 'l', 's', 'e', 'A', 'l',
                             'a', 'r', 'm', 'P', 'r', 'o', 'b'};
  bool b_bool;
  b_bool = false;
  if (a.size(1) == 14) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 14) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool v_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[14]{'d', 'a', 't', 'a', 'R', 'e', 'c',
                             'o', 'r', 'd', 'P', 'a', 't', 'h'};
  bool b_bool;
  b_bool = false;
  if (a.size(1) == 14) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 14) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool w_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[18]{'p', 'r', 'o', 'c', 'e', 's', 's', 'e', 'd',
                             'O', 'u', 'p', 'u', 't', 'P', 'a', 't', 'h'};
  bool b_bool;
  b_bool = false;
  if (a.size(1) == 18) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 18) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool x_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[10]{'r', 'o', 's', '2', 'e', 'n', 'a', 'b', 'l', 'e'};
  bool b_bool;
  b_bool = false;
  if (a.size(1) == 10) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 10) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

bool y_strcmp(const ::coder::array<char, 2U> &a)
{
  static const char b_cv[4]{'t', 'r', 'u', 'e'};
  bool b_bool;
  b_bool = false;
  if (a.size(1) == 4) {
    int kstr;
    kstr = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (kstr < 4) {
        if (a[kstr] != b_cv[kstr]) {
          exitg1 = 1;
        } else {
          kstr++;
        }
      } else {
        b_bool = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
  return b_bool;
}

} // namespace internal
} // namespace coder

// End of code generation (strcmp.cpp)
