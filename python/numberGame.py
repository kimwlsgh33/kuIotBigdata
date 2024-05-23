import random


def min():
    guess_number = random.randint(1, 10)
    user_input = int(input("Guess a number!: "))
    while user_input != guess_number:
        print("It's too big") if user_input > guess_number else print("It's too small")
        user_input = int(input("It's not.. retry: "))
    else:
        print("It's correct!")


if __name__ == "__main__":
    min()
