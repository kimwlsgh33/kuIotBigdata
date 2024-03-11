#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // char name[21]; // 한글 10자 (2byte * 10 + "\0")
  // char buf[1024];
  // char *name = buf; // 포인터는 역참조하기전에, 반드시 대상을 가리켜야한다
  char *name = malloc(sizeof(char) * 21);
  
  // input by word (input is separated by whitespace)
  scanf("%20s", name); // last memory need to be "\0"
  // gets() // input by string
  
  printf("%s\n", name); // &name[0] ~ "\0"
  
  free(name);
  return 0;
}
