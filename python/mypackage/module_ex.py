# import fah_converter
import random
import time
import urllib

from fah_converter import convert_c_to_f as con  # import specific function


def main():
    celsius = float(input("Input celsius : "))
    # fah = fah_converter.convert_c_to_f(celsius)
    fah = con(celsius)
    print(f"celsius : {celsius}")
    print(f"fahrenheit : {fah}")
    print(random.randint(1, 100))
    print(random.random() * 100)
    # print(time)
    print(urllib.request.urlopen("https://www.google.com").read())


if __name__ == "__main__":
    main()
