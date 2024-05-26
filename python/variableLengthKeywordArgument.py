# dictionary : map structure in other languages
def kwargs_test(**kwargs):
    print(kwargs)
    print(type(kwargs))
    print(f"first element: {kwargs['first']}")
    print(f"second element: {kwargs['second']}")
    print(f"third element: {kwargs['third']}")
    # extract key and value from dictionary
    for key, value in kwargs.items():
        print(f"Key : {key} : Value : {value}")


def kwargs_test2(*args, **kwargs):
    print(args)
    print(kwargs)


def main():
    kwargs_test(first=3, second=4, third=5)
    kwargs_test2(1, 3.14, a=2, b=3, c=4)


if __name__ == "__main__":
    main()
