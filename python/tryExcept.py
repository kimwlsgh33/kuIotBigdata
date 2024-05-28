class MyError(Exception):
    def __init__(self, value):
        self.value = value

    def __str__(self):
        return str(self.value)


def main():
    for i in range(10):
        try:
            print(10 / i)
            # raise MyError("내가 일으킨 에러다.")
        except ZeroDivisionError as e:
            print(e)
            print("Don't devide by 0!")
        except MyError as e:
            print(e)
        else:
            print("Error doesn't occured")
        finally:
            print("Run")


if __name__ == "__main__":
    main()
