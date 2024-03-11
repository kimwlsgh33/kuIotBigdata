#include "score.h"

void scanStudents(Student *pStudents[], int size, FILE *fin) {
  for (int i = 0; i < size; ++i) {
    fscanf(fin, "%s %d %d %d", 
          &pStudents[i]->name, 
          &pStudents[i]->kor,
          &pStudents[i]->eng,
          &pStudents[i]->math
          );
    pStudents[i]->sum = pStudents[i]->kor + pStudents[i]->eng + pStudents[i]->math;
    pStudents[i]->avg = (double)pStudents[i]->sum / 3;
    pStudents[i]->rank = 1;
  }
}

void addRank(Student *students, int size) {
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      if (students[i].sum < students[j].sum) {
        ++students[i].rank;
      }
    }
  }
}

void sortByRank(Student *students, int size) {
  for (int i = 0; i < size; ++i) {
    for (int j = i + 1; j < size; ++j) {
      if (students[i].rank > students[j].rank) {
        Student tmp = students[i];
        students[i] = students[j];
        students[j] = tmp;
      }
    }
  }
}

void printStudents(Student *students, int size) {
  fprintf(stdout, "------------------------------------------------\n");
  fprintf(stdout, "%-20s %3s %3s %3s %3s %6s %4s\n", "name", "kor", "eng", "mat", "sum", "avg", "rank");
  fprintf(stdout, "------------------------------------------------\n");
  for (int i = 0; i < 10; ++i) {
    fprintf(stdout, "%-20s %3d %3d %3d %3d %6.2f %3d\n",
           students[i].name,
           students[i].kor,
           students[i].eng,
           students[i].math,
           students[i].sum,
           students[i].avg,
           students[i].rank
           );
  }
}

void addRank2(Student *pStudents[], int size) {
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      if (pStudents[i]->sum < pStudents[j]->sum) {
        ++pStudents[i]->rank;
      }
    }
  }
}

void sortByRank2(Student *pStudents[], int size) {
  for (int i = 0; i < size; ++i) {
    for (int j = i + 1; j < size; ++j) {
      if (pStudents[i]->rank > pStudents[j]->rank) {
        Student* tmp = pStudents[i];
        pStudents[i] = pStudents[j];
        pStudents[j] = tmp;
      }
    }
  }
}

void printStudents2(Student *pStudents[], int size, FILE *fout) {
  fprintf(fout, "------------------------------------------------\n");
  fprintf(fout, "%-20s %3s %3s %3s %3s %6s %4s\n", "name", "kor", "eng", "mat", "sum", "avg", "rank");
  fprintf(fout, "------------------------------------------------\n");
  for (int i = 0; i < 10; ++i) {
    fprintf(fout, "%-20s %3d %3d %3d %3d %6.2f %3d\n",
           pStudents[i]->name,
           pStudents[i]->kor,
           pStudents[i]->eng,
           pStudents[i]->math,
           pStudents[i]->sum,
           pStudents[i]->avg,
           pStudents[i]->rank
           );
  }
}
