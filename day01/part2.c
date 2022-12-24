#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LINE 10

void bubble_sort(int arr[], int size)
{
    for (int i = 0; i < (size - 1); i++)
    {
        for (int j = 0; j < (size - i); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }
}

int main()
{
    int keep_going = 1;
    int sum = 0;
    char current_value[MAX_LINE];
    int greater_calorie_amounts[] = {0, 0, 0};
    int num_of_elvs = 0;

    while (keep_going)
    {
        if (fgets(current_value, MAX_LINE, stdin))
        {
            if (strcmp(current_value, "\n") == 0 || strcmp(current_value, "\r\n") == 0)
            {
                if (sum > greater_calorie_amounts[0])
                {
                    greater_calorie_amounts[0] = sum;
                    bubble_sort(greater_calorie_amounts, 3);
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
    printf("Max calories count: %d, %d, %d\n", greater_calorie_amounts[0], greater_calorie_amounts[1], greater_calorie_amounts[2]);
    printf("Max calories sum: %d\n", greater_calorie_amounts[0] + greater_calorie_amounts[1] + greater_calorie_amounts[2]);
    printf("Num of elves: %d\n", num_of_elvs);
}