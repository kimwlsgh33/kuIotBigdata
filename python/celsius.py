def min():
    while True:
        try:
            celsius = input("input only a number")
            celsius = float(celsius)
            break
        except ValueError:
            print("input only a number")
            continue
    fahrenheit = (float(celsius) * 9 / 5) + 32

    print(f"celsius: {celsius:3.02f}, fahrenheit: {fahrenheit:3.02f}")
    # print(f"celsius: %, fahrenheit: %" % {celsius, fahrenheit})


if __name__ == "__main__":
    min()
