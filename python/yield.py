def yield_example():
    print("yield function is called.")
    # return "test"
    yield "test"

    print("a yield position")
    yield "test2"

    print("b yield position")
    yield "test3"


def main():
    print("main function is called.")
    yield_object = yield_example()
    next(yield_object)

    print("a position passed.")

    next(yield_object)
    print("b position passed.")

    print(next(yield_object))
    print("main function is ended.")

    for i in yield_example():
        print(i)


if __name__ == "__main__":
    main()
