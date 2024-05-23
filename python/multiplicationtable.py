def main():
    user_input = int(input("Which column do you want?"))
    print(f"calculate {user_input} column")
    for i in range(1, 10):
        print(f"{user_input} X {i} = {user_input * i}")


if __name__ == "__main__":
    main()
