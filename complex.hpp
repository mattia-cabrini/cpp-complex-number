#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <cmath>
#include <iostream>

#if __cplusplus > 199711L
using basic_complex_type = double;
#else
typedef double basic_complex_type;
#endif

class complex {
public:
  basic_complex_type re;
  basic_complex_type im;

  complex(basic_complex_type re, basic_complex_type im);
  complex();

  complex operator+(const complex& oth) const;
  complex operator-(const complex& oth) const;
  complex operator-() const;
  complex operator/(const basic_complex_type& oth) const;
  complex operator/(const complex& oth) const;
  complex operator*(const basic_complex_type& oth) const;
  complex operator*(const complex& oth) const;
  basic_complex_type magnitude();
  basic_complex_type phase();

  // parallel of two impedance
  complex operator||(const complex& oth) const;

  complex Y() const;
};

complex operator!(const complex& oth);

extern std::ostream& operator<<(std::ostream& stream, const complex& N);
extern std::istream& operator>>(std::istream& stream, complex& N);

#endif // COMPLEX_H_
