#include <stdio.h>
#include <string.h>
#define MAX_LINE 5

int standardize_input(char pick) {
    if (pick == 'X' || pick == 'A') {
        // Rock
        return 1;
    }
    if (pick == 'Y' || pick == 'B') {
        // Paper
        return 2;
    }
    if (pick == 'Z' || pick == 'C'){
        // Scisors
        return 3;
    }
}

int compute_round_points(char line[]) {
    int oponent_pick = standardize_input(line[0]);
    int player_pick = standardize_input(line[2]);
    int match_result;

    if (player_pick == oponent_pick) {
        match_result = 3;
    } else {
        if (player_pick == 1 && oponent_pick == 3) {
            match_result = 6;
        } else if (player_pick == 2 && oponent_pick == 1) {
            match_result = 6;
        } else if (player_pick == 3 && oponent_pick == 2) {
            match_result = 6;
        }  else {
            match_result = 0;
        }
    }


    printf("%c x %c = %d\n", line[0], line[2], match_result);
    return match_result + player_pick;
}

int main() {
    int keep_going = 1;
    char line[MAX_LINE];
    int total_score = 0;

    while (keep_going)
    {
        if (fgets(line, MAX_LINE, stdin))
        {
            total_score += compute_round_points(line);
        }
        else
        {
            keep_going = 0;
        }
    }
    printf("Total score: %d points", total_score);
}