#ifndef SCORE_H
#define SCORE_H

#include <stdio.h>
typedef struct {
  char *name[21]; // string
  int kor;
  int eng;
  int math;
  int sum;
  double avg;
  int rank;
} Student;

void addRank(Student *students, int size);
void sortByRank(Student *students, int size);
void printStudents(Student *students, int size);

void addRank2(Student *pStudents[], int size);
void sortByRank2(Student *pStudents[], int size);
// void scanStudents(Student *students[], int size);
// void printStudents2(Student *pStudents[], int size);
void scanStudents(Student *students[], int size, FILE *fin);
void printStudents2(Student *pStudents[], int size, FILE *fout);

#endif
