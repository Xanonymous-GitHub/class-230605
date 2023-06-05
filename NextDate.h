#include <stdio.h>

#define INVALID -1
#define NORMALYEAR 0
#define LEAPYEAR 1
#define BIGMONTH 0
#define SMALLMONTH 1
#define FEBUARY 2

#define BIGMONTHMAX 31
#define SMALLMONTHMAX 30
#define NORMALFEBUARYMAX 28
#define LEAPFEBUARYMAX 29

typedef struct _Date {
    int year;
    int month;
    int day;
} Date;

Date *NextDate(Date *);
Date *NewDateInstance(int year, int month, int day);
void ShowDate(Date *);
bool checkDate(Date *a, int true_year, int true_mouth, int true_day);
