// void swap(int, int);
void swap(int *, int *);

int main(void) {
  int a = 10, b = 20;

  // swap(a, b);
  swap(&a, &b);

  return 0;
}

// void swap(int param_a, int param_b) {
//   int tmp = param_a;
//   param_a = param_b;
//   param_b = tmp;
// }

void swap(int *ptr_a, int *ptr_b) {
  int tmp = *ptr_a;
  *ptr_a = *ptr_b;
  *ptr_b = tmp;
}
