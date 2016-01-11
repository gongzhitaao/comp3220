#include "bf.h"

#include <algorithm>

BF::BF()
{
  reset();
}

void BF::reset()
{
  std::fill(mem_, mem_ + MEM_SIZE, 0);
  ptr_ = 0;
}

bool BF::interpret(const std::string &src, bytestream &is, bytestream &os)
{
  // TODO: Implement this function

  // Example "." operation, read and store a byte to array under p
  is.read(mem_ + ptr_, 1);

  // Example "," operation, print ASCII value in array under p
  os.write(mem_ + ptr_, 1);

  return true;
}
