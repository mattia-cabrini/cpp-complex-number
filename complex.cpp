#include "complex.hpp"

#include <iostream>
#include <cmath>

complex::complex(basic_complex_type re, basic_complex_type im) : re(re), im(im) {}
complex::complex() : re(0), im(0) {}

complex complex::operator+(const complex& oth) const {
  return complex(this->re + oth.re, this->im + oth.im);
}

complex complex::operator-(const complex& oth) const {
  return complex(this->re - oth.re, this->im - oth.im);
}

complex complex::operator-() const {
  return complex(-this->re, -this->im);
}

complex complex::operator/(const basic_complex_type& oth) const {
  return complex(this->re / oth, this->im / oth);
}

complex complex::operator/(const complex& oth) const {
  basic_complex_type mod2 = oth.re * oth.re + oth.im * oth.im;
  return (*this * !oth) / mod2;
}

  complex complex::operator*(const basic_complex_type& oth) const {
  return complex(this->re * oth, this->im * oth);
}

complex complex::operator*(const complex& oth) const {
  complex N;
  N.re = this->re * oth.re - this->im * oth.im;
  N.im = this->re * oth.im - this->im * oth.re;
  return N;
}

complex operator!(const complex& oth) {
  return complex(oth.re, -oth.im);
}

basic_complex_type complex::magnitude() {
  return sqrt(this->re * this->re + this->im * this->im);
}

basic_complex_type complex::phase() {
  basic_complex_type phase = atan(this->im / this->re);

  if ( this->re < 0 ) {
    phase += 2*asin(1.0);
  }

  return phase;
}

// parallel of two impedance
complex complex::operator||(const complex& oth) const {
  return (*this * oth) / (*this + oth);
}

complex complex::Y() const {
  return complex(1, 0) / *this;
}

std::ostream& operator<<(std::ostream& stream, const complex& N) {
  stream << N.re;

  if ( N.im < 0 ) {
    stream << " - j" << std::abs(N.im);
  } else {
    stream << " + j" << std::abs(N.im);
  }

  return stream;
}

std::istream& operator>>(std::istream& stream, complex& N) {
  stream >> N.re;
  stream >> N.im;

  return stream;
}
