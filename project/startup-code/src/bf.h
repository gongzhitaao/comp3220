#ifndef BF_H_
#define BF_H_

#pragma once

#include <cstdint>
#include <string>
#include <sstream>

typedef std::basic_stringstream<uint8_t> bytestream;

class BF
{
 public:
  static const int MEM_SIZE = 30000;

  BF();

  /**
   * Workhorse of BrainFuck interpreter.
   *
   * @param src A BrainFuck program source
   * @param is The input byte stream
   * @param os The output byte stream
   * @return true if the source code is valid
   */
  bool interpret(const std::string &src, bytestream &is, bytestream &os);

  /**
   * Reset the interpreter state.
   *
   * 1. fill array with 0
   * 2. set pointer to 0
   */
  void reset();

  int ptr() const { return ptr_; }

 private:
  uint8_t mem_[MEM_SIZE];
  int ptr_;
};

#endif /* BF_H_ */
