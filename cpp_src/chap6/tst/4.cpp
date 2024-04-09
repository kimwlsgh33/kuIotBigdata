class MyVector {
  int *mem;
  int size;

public:
  MyVector();
  MyVector(int n = 100, int val = 0);
  ~MyVector() { delete[] mem; }
};

// MyVector::MyVector() {
//   mem = new int[100];
//   size = 100;
//   for (int i = 0; i < size; ++i)
//     mem[i] = 0;
// }

MyVector::MyVector(int n, int val) {
  mem = new int[n];
  size = n;
  for (int i = 0; i < size; ++i)
    mem[i] = val;
}
