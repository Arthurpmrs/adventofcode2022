def compute_result(choices_map: dict, oponent_pick: str, player_option: str) -> int:
    choices = list(choices_map.keys())
    
    if player_option == "Y":
        # Draw
        match_result = choices_map[oponent_pick] + 3
    elif player_option == "Z":
        # Win
        if oponent_pick == choices[-1]:
            match_result = choices_map[choices[0]] + 6
        else:
            match_result = choices_map[oponent_pick] + 1 + 6
    else:
        # Lose
        if oponent_pick == choices[0]:
            match_result = choices_map[choices[-1]] + 0
        else:
            match_result = choices_map[oponent_pick] - 1 + 0

    return match_result

def main():
    total_points = 0
    choices_map = {"A": 1, "B": 2, "C": 3}
    with open("input.txt") as file:
        for line in file:
            line = line.strip("\n").replace(" ", "")
            total_points += compute_result(choices_map, *line)

    print(f"Total of points: {total_points}")


if __name__ == "__main__":
    main()