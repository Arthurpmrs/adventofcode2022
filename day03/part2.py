def map_to_number(rucksack: str) -> list:
    alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    char_map = {}
    for i, letter in enumerate(alphabet):
        char_map.update({letter: i + 1})


    return [char_map[item] for item in rucksack]

def evaluate_group(rucksacks: list) -> int:
    sets = []
    for rucksack in rucksacks:
        s = set(rucksack)
        sets.append(s)

    intersection = sets[0].intersection(*sets[1:])
    return sum(intersection)

def main():
    total_sum = 0
    with open("input.txt") as file:
        group = []
        for count, line in enumerate(file):
            rucksack = line.strip("\n")
            mapped_rucksack = map_to_number(rucksack)
            group.append(mapped_rucksack)
            
            if (count + 1) % 3 == 0:
                total_sum += evaluate_group(group)
                group = []

    print(f"Soma total é: {total_sum}")


if __name__ == "__main__":
    main()