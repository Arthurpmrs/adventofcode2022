def main():
    with open("input.txt") as file:
        sums = []
        s = 0
        for line in file:
            if line == "\n":
                sums.append(s)
                s = 0
            else:
                s += int(line.replace("\n", ""))

    greater_3 = sorted(sums, reverse=True)[:3]
    print(f"Max calories count: {greater_3}")
    print(f"Max calories sum: {sum(greater_3)}")
    print(f"Num of elves: {len(sums)}")


if __name__ == "__main__":
    main()
