#include <stdio.h>
#include <stdlib.h>
#include "grade.h"


int main(void)
{
    int grade_count = 0;
    int capacity = 1;
    int *student_points = malloc(capacity * sizeof(*student_points));

    if(student_points == NULL)
    {
        printf("Fail memmory allocation! SHUTDOWN!!!\n");
        return 1;
    }

    printf("Welcome to Grade Master!\n");
    printf("Lets grade a student! Start entering grades!\n");

    printf("Enter grades, enter -1 to stop:\n");
    
    int user_input = 0;

    while (scanf("%d", &user_input) == 1 && user_input != -1) 
    {   
        if(!valid_grade(user_input))
        {
            printf("Invalid grade! Please try again!\n");
            continue;
        }

        if (grade_count == capacity) 
        {
            capacity *= 2;
            int *new_student_points = realloc(student_points, capacity * sizeof(*student_points));

            if (new_student_points == NULL) 
            {
                printf("Memmory allocation faild!!!!\n");
                free(student_points);
            return 1;
            }
            student_points = new_student_points;
        }
        
        student_points[grade_count] = user_input;
        grade_count++;
    }

    for(int i = 0; i < grade_count; i++)
    {
        printf("Grade %d has points %d and grades as %c\n", i+1, student_points[i], convert_to_grade(student_points[i]));
    }

    char *students_grade = calloc(grade_count + 1, sizeof(*students_grade));
    if(students_grade == NULL)
    {
        printf("ERROR allocating students_grade char array!\n");
        free(students_grade);
        free(student_points);
        return 1;
    }

    for(int i = 0; i < grade_count; i++)
    {
        students_grade[i] = convert_to_grade(student_points[i]);
    }

    printf("Grades in order is %s\n", students_grade);

    free(students_grade);
    free(student_points);
    return 1;
}