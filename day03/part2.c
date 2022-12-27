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

int get_unique_items(int rucksack[], int original_size, int unique_items_rucksack[]) {
    for (int i = 0; i < MAX_LINE; i++) {
        unique_items_rucksack[i] = 0;
    }
    int append_index = 0;
    for (int i = 0; i < original_size; i++) {
        int is_contained = 0;
        for (int j = 0; j < MAX_LINE; j++) {
            if (rucksack[i] == unique_items_rucksack[j]) {
                is_contained = 1;   
            }
        }
        if (!is_contained) {
            unique_items_rucksack[append_index] = rucksack[i];
            append_index++;
        }
    }
    int i = 0;
    printf("Unique rucksack 1: ");
    while (unique_items_rucksack[i] != 0) 
    {
        printf("%d, ", unique_items_rucksack[i]);
        i++;
    }
    printf("\n");
    printf("pratical size: %d\n", i);
    return i;
}
int get_common_items_sum(int rucksacks[3][MAX_LINE], int sizes[]) {
    int uniques_sum = 0;
    int unique_items_rucksack[MAX_LINE];
    int unique_items_rucksack_size = get_unique_items(rucksacks[0], sizes[0], unique_items_rucksack);
    int presences[unique_items_rucksack_size][2];
    for (int n = 0; n < unique_items_rucksack_size; n++) {
        for (int m = 0; m < 2; m++) {
            presences[n][m] = 0;
        }
    }

    for (int i = 0; i < unique_items_rucksack_size; i++) {        
        for (int j = 1; j < 3; j++) {
            for (int k = 0; k < sizes[j]; k++) {
                if (rucksacks[j][k] == unique_items_rucksack[i]) {
                    presences[i][j - 1] = 1;
                    break;
                }
            }
        }
    }

    for (int n = 0; n < unique_items_rucksack_size; n++) {
        int truthful_sum = 0;
        for (int m = 0; m < 2; m++) {
            printf("%d ", presences[n][m]);
            truthful_sum += presences[n][m];
        }
        printf("(Index: %d | Value: %d | sum: %d)\n", n, unique_items_rucksack[n], truthful_sum);
        if (truthful_sum == 2) {
            uniques_sum += unique_items_rucksack[n];
        }
    }
    printf("group sum: %d\n", uniques_sum);
    return uniques_sum;
}


int evaluate_group(char* group_rucksacks[]) {
    int mapped_group_rucksacks[3][MAX_LINE];
    int sizes[3];

    for (int i = 0; i < 3; i++) {
        printf("\n");
        printf("Rucksack %d: %s", i + 1, group_rucksacks[i]);
        printf("\n");
        
        int rucksack_size = get_str_len(group_rucksacks[i]);
        map_to_number(group_rucksacks[i], rucksack_size, mapped_group_rucksacks[i]);
        sizes[i] = rucksack_size;
    }  
    for (int i = 0; i < 3; i++) {
        printf("Elfo %d: ", i + 1);
        for (int j = 0; j < sizes[i]; j++) {
            printf("%d, ", mapped_group_rucksacks[i][j]);
        }
        printf("\n");
    }
    return get_common_items_sum(mapped_group_rucksacks, sizes);
}


int main() {
    int keep_going = 1;
    char rucksack[MAX_LINE];
    int total_sum = 0;

    int group_count = 0;
    char *group_rucksacks[3];

    while (keep_going)
    {
        if (fgets(rucksack, MAX_LINE, stdin))
        {
            if (group_count >= 3) {
                total_sum += evaluate_group(group_rucksacks);
                group_count = 0;
                group_rucksacks[group_count] = strndup(rucksack, MAX_LINE);
                group_count++;
            } else {
                group_rucksacks[group_count] = strndup(rucksack, MAX_LINE);
                group_count++;
            }
        }
        else
        {
            total_sum += evaluate_group(group_rucksacks);
            keep_going = 0;
        }
    }
    printf("Soma total: %d", total_sum);
}