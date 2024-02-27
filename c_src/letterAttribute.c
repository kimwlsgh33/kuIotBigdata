#include <stdio.h>
// macro constant should be uppercase in consensous
// macro must not be ended with semicolon (;)
// #define BOLD 0x01 // 0000 0001
// #define ITALIC 0x02 // 0000 0010
// #define SHADOW 0x04 // 0000 0100
// #define UL 0x08     // 0000 1000
#define BOLD 0x01
#define ITALIC (0x01 << 1)
#define SHADOW (0x01 << 2)
#define UL (0x01 << 3)

int main(void) {
  unsigned char attr;
  // ^ : karrot? - XOR in C
  // there is no exponential
  attr = attr ^ attr; // 0000 0000

  // attr = attr | 0x00000001;
  // attr = attr & 0xFE;           // 0xFE : 1111 1110 : ~0000 0001 : ~BOLD
  // attr = attr | (ITALIC + SHADOW); // (0x01 << 1 + 0x01 << 2) : (0x01 << 0x02 << 2) : 0001 0000 : 0x10
  // attr = attr & ~BOLD;             // 0x10 & ~0x01 : 0001 0000
  attr = attr | BOLD;              // 0000 0001
  attr = attr | (ITALIC + SHADOW); // 0000 0111
  attr = attr & ~BOLD;             // 0000 0110

  // explicit type casting is good habit
  // printf("attr: 0x%08x\n", (int)attr);
  printf("attr: 0x%02x\n", (int)attr);
  return 0;
}
