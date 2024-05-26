def main():
    result = [i for i in range(50)]
    print(result)

    result = [i for i in range(50) if i % 2 == 0]
    print(result)

    result = [i if i % 2 == 0 else None for i in range(50)]
    print(result)

    # nested
    result = [i + j for i in range(2) for j in range(3)]
    print(result)
    result = [[i + j for i in range(2)] for j in range(3)]
    print(result)
    result = [[i + j] for i in range(2) for j in range(3)]
    print(result)


if __name__ == "__main__":
    main()
