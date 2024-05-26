def min():
    i = 1
    while True:
        i += 1
        if i % 2 == 0:
            continue
        print(i)
        if i >= 10:
            break


if __name__ == "__main__":
    min()
