def min():
    for looper in [1, 2, 3, 4, 5]:
        print("hello", looper, end=" ")
        print("world")

    # for i in range(100):
    #     print("hello", i, end=" ")

    for i in range(0, 100, 2):
        print("hello", i, end=" ")

    print()

    for i in "abcdefg":
        print(i)


if __name__ == "__main__":
    min()
