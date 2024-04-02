#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void strgrd(char *src, unsigned int size);
int is0Str(const char *src);

enum Err { NONE, ATOIFAILED, NOTSEP, NOTOP };

int main(void) {
  unsigned char size = 16;
  char str[size], buf[size];
  int num1 = 0, num2 = 0;
  char op = '\0';
  int result = 0;
  unsigned char idx, err;

  while (1) {
    // printf("NONE: %d\n", NONE);
    printf("? ");
    // using regular expression
    // scanf("%[^\n]s", str);
    fgets(str, size, stdin);
    strgrd(str, size);
    // 피연산자와 연산자를 구분해서 변수에 저장
    if (strcmp(str, "quit") == 10) {
      printf("Bye\n");
      return 0;
    }

    // [0, sizeof(str) / sizeof(str[0]))
    for (idx = 0, err = NONE; idx < size; ++idx) {
      if (str[idx] == ' ') {
        strcpy(buf, str);
        buf[idx] = '\0';
        num1 = atoi(buf);

        // checking atoi convert status
        if (!is0Str(buf) && num1 == 0) {
          err = ATOIFAILED;
          break;
        } else if (str[idx + 2] != ' ') {
          err = NOTOP;
          break;
        }

        op = str[idx + 1];

        num2 = atoi(buf + idx + 3);
        break;
      }
    }

    if (idx == size) {
      err = NOTSEP;
    }

    idx = 0;

    if (err) {
      switch (err) {
      case ATOIFAILED:
        printf("failed to convert string to integer.\n");
        break;
      case NOTSEP:
        printf("you should separate each operands by ' '.\n");
        break;
      case NOTOP:
        printf("you should write operater as a single character.\n");
        break;
      default:
        printf("unknown error\n");
      }

      continue;
      printf("back to top.\n");
    }

    switch (op) {
    case '+':
      printf("%d + %d = %d\n", num1, num2, num1 + num2);
      break;
    case '-':
      printf("%d - %d = %d\n", num1, num2, num1 - num2);
      break;
    case '*':
      printf("%d * %d = %d\n", num1, num2, num1 * num2);
      break;
    case '/':
      printf("%d / %d = %d\n", num1, num2, num1 / num2);
      break;
    case '%':
      printf("%d %% %d = %d\n", num1, num2, num1 % num2);
      break;
    default:
      printf("there is no operator %c", op);
      break;
    }
  }

  return 0;
}

void strgrd(char *src, unsigned int size) { src[size - 1] = '\0'; }

int is0Str(const char *src) {
  if (src[1] == '\0' && src[0] == '0')
    return 1;

  return 0;
}
