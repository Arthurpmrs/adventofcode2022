def map_to_number(rucksack: str) -> list:
    alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    char_map = {}
    for i, letter in enumerate(alphabet):
        char_map.update({letter: i + 1})


    return [char_map[item] for item in rucksack]


def main():
    total_sum = 0
    with open("input.txt") as file:
        for line in file:
            rucksack = line.strip("\n")
            mapped_rucksack = map_to_number(rucksack)

            rucksack_size = len(mapped_rucksack)
            compartment_size = int(rucksack_size / 2)
            
            compartment1_unique_items = set(mapped_rucksack[:compartment_size])
            compartment2_unique_items = set(mapped_rucksack[compartment_size:])
            intersection = compartment1_unique_items.intersection(compartment2_unique_items)
            total_sum += sum(intersection)

    print(f"Soma total é: {total_sum}")


if __name__ == "__main__":
    main()