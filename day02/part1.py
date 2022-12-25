def get_rules_dict(choices_map: dict) -> dict:
    choices = list(choices_map.keys())
    rules = {}
    for i in range(len(choices) - 1):
        rules.update({
            choices[i] + choices[i + 1]: choices_map[choices[i + 1]] + 6,
            choices[i + 1] + choices[i]: choices_map[choices[i]] + 0,
            choices[i] + choices[i]: choices_map[choices[i]] + 3,
        })
    rules.update({
        choices[-1] + choices[0]: choices_map[choices[0]] + 6,
        choices[0] + choices[-1]: choices_map[choices[-1]] + 0,
        choices[-1] + choices[-1]: choices_map[choices[-1]] + 3
    })
    return rules



def main():
    total_points = 0
    choices_map = {"A": 1, "B": 2, "C": 3}
    rules = get_rules_dict(choices_map)
    with open("input.txt") as file:
        for line in file:
            line = line.strip("\n").replace("Y", "B").replace("X", "A").replace("Z", "C").replace(" ", "")
            total_points += rules[line]

    print(f"Total of points: {total_points}")


if __name__ == "__main__":
    main()