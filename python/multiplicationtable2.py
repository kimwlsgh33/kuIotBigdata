def main():
    user_input = 1
    while True:
        try:
            user_input = int(input("Which column do you want?"))
            if not (1 <= user_input <= 9):
                raise ValueError
        except ValueError:
            print("It's wrong number. please input again.")
            continue
        if user_input == 0:
            break
        else:
            print(f"calculate {user_input} column.")
            for i in range(1, 10):
                print(f"{user_input} X {i} = {user_input * i}")

    print("game end")


if __name__ == "__main__":
    main()
