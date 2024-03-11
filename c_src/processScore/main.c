#include "score.h"

int main(void) {
  FILE *fin, *fout;

  // fopen("file_name", "mode");
  fin = fopen("../score.dat", "r");
  fout = fopen("score.out", "w");
              
  int size = 10;
  Student students[size];
  Student *pStudents[size];
  for (int i = 0; i < size; ++i) {
    pStudents[i] = &students[i];
  }
  // rank ???
  // addRank(students, 10);
  // sortByRank(students, 10);
  // printStudents(students, 10);

  // scanStudents(pStudents, size);
  scanStudents(pStudents, size, fin);
  addRank2(pStudents, size);
  sortByRank2(pStudents, size);
  // printStudents2(pStudents, size);
  printStudents2(pStudents, size, fout);

  fclose(fin);
  fclose(fout);
  return 0;
}
