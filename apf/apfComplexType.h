#ifndef CXX_COMPLEX
#include <complex.h>
typedef double _Complex double_complex;
#else
  #include <complex>
  using double_complex = std::complex<double>;
#endif
