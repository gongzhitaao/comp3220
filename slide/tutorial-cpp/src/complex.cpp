#include "complex.h"

namespace ppl {

Complex::Complex(double real, double imag)
    : real_(real), imag_(imag)
{ }

Complex& Complex::operator+=(const Complex& c)
{
  this->real_ += c.real_;
  imag_ += c.imag_;

  return *this;
}

Complex& Complex::operator-=(const Complex& c)
{
  // TODO
}

Complex& Complex::operator*=(const Complex& c)
{
  // TODO
}

Complex& Complex::operator/=(const Complex& c)
{
  // TODO
}

Complex operator+(const Complex& a, const Complex& b)
{
  return {a.real() + b.real(), a.imag() + b.imag()};
}

Complex operator-(const Complex& a, const Complex& b)
{
  // TODO
}

Complex operator-(const Complex& a)
{
  // TODO
}

Complex operator*(const Complex& a, const Complex& b)
{
  // TODO
}

Complex operator/(const Complex& a, const Complex& b)
{
  // TODO
}

bool operator==(const Complex& a, const Complex& b)
{
  // TODO
}

}  // namespace ppl
