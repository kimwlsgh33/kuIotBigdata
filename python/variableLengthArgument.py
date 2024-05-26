# *args: packed arguments => (3, 4, 5)
def asterisk_test(a, b, *abc):
    print(a)
    print(b)
    # print(args)
    for i in abc:
        print(i)
    return a + b + sum(abc)


def asterisk_test2(a, b, *args):
    x, y, *z = args
    return x, y, z


def main():
    print(asterisk_test(1, 2, 3, 4, 5))
    print(asterisk_test2(1, 2, 3, 4, 5, 6))


if __name__ == "__main__":
    main()
