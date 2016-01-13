#ifndef COMPLEX_H_
#define COMPLEX_H_

#pragma once

namespace ppl {

class Complex {
 public:
  Complex(double real = 0.0, double imag = 0.0);

  double real() const { return real_; }
  double imag() const { return imag_; }
  void set_real(double real) { real_ = real; }
  void set_imag(double imag) { imag_ = imag; }

  Complex& operator += (const Complex& c);
  Complex& operator -= (const Complex& c);
  Complex& operator *= (const Complex& c);
  Complex& operator /= (const Complex& c);

 private:
  double real_, imag_;
};

Complex operator + (const Complex& a, const Complex& b);
Complex operator - (const Complex& a, const Complex& b);
Complex operator - (const Complex& a);
Complex operator * (const Complex& a, const Complex& b);
Complex operator / (const Complex& a, const Complex& b);

bool operator == (const Complex& a, const Complex& b);
}  // namespace ppl

#endif /* COMPLEX_H_ */
