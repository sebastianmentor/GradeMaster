#ifndef GRADE_H
#define GRADE_H

#include <stdbool.h>

#define MIN_POINTS 0
#define MAX_POINTS 100

char convert_to_grade(int points);
bool valid_grade(int points);

#endif