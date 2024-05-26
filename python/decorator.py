import time


def my_decorator(func):
    def wrapper():
        print("code before function call")
        t = time.time()
        func()
        print("function elapse time: ", time.time() - t)
        print("code after function call")

    return wrapper


@my_decorator
def print_hello():
    i = 0
    for _ in range(100000000):
        i += 1
    print("Hello", str(i))


def main():
    print_hello()


if __name__ == "__main__":
    main()
