class Cookie:
    number = 0  # Class variable

    def __init__(self, size):
        self.size = size
        Cookie.number += 1

    @classmethod
    def reset(cls):
        cls.number = 0
        print("쿠키개수를 초기화 했습니다")


def main():
    cookie1 = Cookie(10)
    cookie2 = Cookie(20)
    Cookie.reset()

    for _ in range(100):
        Cookie(30)

    print(Cookie.number)


if __name__ == "__main__":
    main()
