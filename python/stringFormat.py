def main():
    a, b, c = 1, 2, 3

    print("first: %d second: %d third: %d" % (a, b, c))

    # fstring - string interpolation
    print(f"first: {a} second: {b}, third: {c}")
    print(f"first: {a:<6.2f} second: {b}, third: {c}")
    print(f"first: {a + 10:<6.2f} second: {b}, third: {c}")

    print("first: {} second: {} third: {}".format(a, b, c))

    print("first: {2:.2f} second: {1:.3f} third: {0:.4f}".format(a, b, c))

    print("first: {2:6.2f} second: {1:6.3f} third: {0:6.4f}".format(a, b, c))

    print("first: {2:-6.2f} second: {1:-6.3f} third: {0:-6.4f}".format(a, b, c))


if __name__ == "__main__":
    main()
