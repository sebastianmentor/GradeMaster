#include <stdbool.h>
#include "grade.h"

char convert_grade(int points)
{
    if(!valid_grade(points))
    {
        return '\0';
    }

    return 'A';
}

bool valid_grade(int points)
{
    if(points < MIN_POINTS || points > MAX_POINTS)
    {
        return false;
    }
    return true;

}