def min():
    colors = [
        "red",
        "green",
        "blue",
        "purple",
        "yellow",
        "black",
    ]
    print(colors)
    # print(colors[0])
    # print(colors[1])
    # print(colors[2])
    for c in colors:
        print(c)
    print(len(colors))
    print(colors[5:8])
    print(colors[5:8:2])
    print(colors[0:11:2])
    # indexing! you can ommit first or last of slices
    print(colors[::2])
    # print(colors[13])

    # list operation
    number = [12, 25, 71, 3.14, 7.8235]
    total_list = colors + number
    colors.extend(number)

    # colors = colors + ["white"]
    print("white" in colors)
    colors.append("white")
    colors = colors * 2
    colors.remove("white")
    colors.remove("white")
    # colors.remove("white")
    print(total_list)
    # del colors # delete object
    del colors[-1]  # delete last index
    print(colors)
    print("white" in colors)

    colors.append(number)  # type: ignore
    print(colors)
    print(number)
    colors.remove(number)  # type: ignore
    print(colors)
    print(number)
    colors.append(number)  # type: ignore
    print(colors)
    del colors[0]
    number.append(123)
    print(colors)
    print(number)


if __name__ == "__main__":
    min()
