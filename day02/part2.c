#include <stdio.h>
#include <string.h>
#define MAX_LINE 5

int standardize_input(char pick) {
    if (pick == 'A') {
        // Rock
        return 1;
    }
    if (pick == 'B') {
        // Paper
        return 2;
    }
    if (pick == 'C'){
        // Scisors
        return 3;
    }
}

int compute_match_point(char line[]) {
    int oponent_pick = standardize_input(line[0]);
    int player_option = line[2];
    int match_result;

    if (player_option == 'Y') {
        // Draw
        match_result = oponent_pick + 3;
    } else if (player_option == 'Z') {
        // Win
        if (oponent_pick == 3) {
            match_result = 1 + 6;
        } else {
            match_result = (oponent_pick + 1) + 6;
        }
    } else {
        // Lose
        if (oponent_pick == 1) {
            match_result = 3 + 0;
        } else {
            match_result = (oponent_pick - 1) + 0;
        }
    }

    return match_result;    
}

int main() {
    int keep_going = 1;
    char line[MAX_LINE];
    int total_score = 0;

    while (keep_going)
    {
        if (fgets(line, MAX_LINE, stdin))
        {
            total_score += compute_match_point(line);
        }
        else
        {
            keep_going = 0;
        }
    }
    printf("Total score: %d points", total_score);
}