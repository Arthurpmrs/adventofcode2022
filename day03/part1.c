#include <stdio.h>
#include <string.h>
#define MAX_LINE 100

int get_str_len(char line[]) {
    int size = 0;
    for (int i = 0; i < MAX_LINE; i++) {
        if (line[i] == '\0' || line[i] == '\n') {
            break;
        }
        size++;
    }
    return size;
}

void bubble_sort(int arr[], int size)
{
    for (int i = 0; i < (size - 1); i++)
    {
        for (int j = 0; j < (size -1 - i); j++)
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

int map_to_number(char compartment[], int size, int mapped_compartment[]) {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int associated_numbers[52];

    for (int i = 0; i < 52; i++) {
        associated_numbers[i] = i + 1;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 52; j++) {
            if (compartment[i] == alphabet[j]) {
                mapped_compartment[i] = associated_numbers[j];
            }
        }
    }
}

int get_intersection_sum(int mapped_compartment1[], int mapped_compartment2[], int compartment_size) {
    int sum_of_repeated_items = 0;
    bubble_sort(mapped_compartment1, compartment_size);
    bubble_sort(mapped_compartment2, compartment_size);
    
    int keep_going = 1;
    int i = 0;
    int j = 0;
    while (keep_going){
        if (mapped_compartment1[i] < mapped_compartment2[j]) {
            i++;
        } else if (mapped_compartment1[i] > mapped_compartment2[j]){
            j++;
        } else {
            sum_of_repeated_items += mapped_compartment1[i];
            while (mapped_compartment1[i] == mapped_compartment1[i + 1] || i < compartment_size){
                i++;
            }
            while (mapped_compartment2[j] == mapped_compartment1[j + 1] || j < compartment_size){
                j++;
            }
        }
        if (i >= compartment_size || j >= compartment_size) {
            keep_going = 0;
        }
    }
    return sum_of_repeated_items;
}

int main() {
    int keep_going = 1;
    char rucksack[MAX_LINE];
    int total_sum = 0;

    while (keep_going)
    {
        if (fgets(rucksack, MAX_LINE, stdin))
        {
            int rucksack_size = get_str_len(rucksack);
            int compartment_size = rucksack_size / 2;
            char compartment1[compartment_size];
            char compartment2[compartment_size];
            int mapped_compartment1[compartment_size];
            int mapped_compartment2[compartment_size];

            for (int i = 0; i < compartment_size; i++){
                compartment1[i] = rucksack[i];
            }
            for (int i = 0; i < compartment_size; i++) {
                compartment2[i] = rucksack[compartment_size + i];
            }
            map_to_number(compartment1, compartment_size, mapped_compartment1);
            map_to_number(compartment2, compartment_size, mapped_compartment2);
            total_sum += get_intersection_sum(mapped_compartment1, mapped_compartment2, compartment_size);
        }
        else
        {
            keep_going = 0;
        }
    }
    printf("Soma total: %d", total_sum);
}