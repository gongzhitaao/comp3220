#include <cstdio>
#include <cstdint>
using namespace std;

int main() {
  // How integer is stored in memory?

  union U0 {
    std::int32_t n;
    std::uint8_t c[4];
  };

  U0 u0;
  u0.n = -1;
  for (auto i : u0.c)
    printf("%02x", i);
  printf("\n");

  u0.n = 1;
  for (auto i : u0.c)
    printf("%02x", i);
  printf("\n");

  u0.n = 2;
  for (auto i : u0.c)
    printf("%02x", i);
  printf("\n");
}
