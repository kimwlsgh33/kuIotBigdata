#ifndef DATE_H

#define DATE_H
// structure declaration in header
// struct date {
//   int year;
//   int month;
//   int day;
// };

// typedef struct date Date;
typedef struct {
  int year;
  int month;
  int day;
} Date;

// int printDate1(struct date d);
// int printDate2(const struct date *pd);
int printDate1(Date d);
int printDate2(const Date *pd);

#endif

// unsigned int length;
//
// typedef unsigned int size_t;
// size_t length;
