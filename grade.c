#include <stdbool.h>
#include "grade.h"

char convert_to_grade(int points)
{   
    char grade = '\0';

    if(!valid_grade(points))
    {
        return grade;
    }
     
    // regular if works fun but why not complicate it for us ;D

    int map_points = points/10;

    switch(map_points)
    {

        case 10:
            grade = 'A';
            break;
        case 9:
            grade = 'A';
            break;
        case 8:
            grade = 'B';
            break;
        case 7:
            grade = 'C';
            break;
        case 6:
            grade = 'D';
            break;
        case 5:
            grade = 'E';
            break;
        default:
            grade = 'F';
            break;
    }

    return grade;
}

bool valid_grade(int points)
{
    if(points < MIN_POINTS || points > MAX_POINTS)
    {
        return false;
    }
    return true;

}