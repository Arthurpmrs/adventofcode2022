#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LINE 10

int main()
{

    int keep_going = 1;
    int sum = 0;
    char current_value[MAX_LINE];
    int greater_calorie_amount = 0;
    int num_of_elvs = 0;
    // int elven_id = 1;
    // int most_calories_elven_id;

    while (keep_going)
    {
        if (fgets(current_value, MAX_LINE, stdin))
        {
            if (strcmp(current_value, "\n") == 0 || strcmp(current_value, "\r\n") == 0)
            {
                printf("sum: %d\n", sum);
                if (sum > greater_calorie_amount)
                {
                    greater_calorie_amount = sum;
                }
                sum = 0;
                num_of_elvs++;
            }
            else
            {
                sum += atoi(current_value);
            }
        }
        else
        {
            keep_going = 0;
        }
    }
    printf("Max calories count: %d\n", greater_calorie_amount);
    printf("Num of elves: %d\n", num_of_elvs);
}