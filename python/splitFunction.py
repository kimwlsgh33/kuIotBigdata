def main():
    items = "zero one two three".split()
    print(items)
    example = "python,jquery,javascript,rust,go,cpp".split(",")
    print(example)

    colors = ["red", "blue", "green", "yello"]
    result = "".join(colors)
    print(result)
    result = ", ".join(colors)
    print(result)


if __name__ == "__main__":
    main()
