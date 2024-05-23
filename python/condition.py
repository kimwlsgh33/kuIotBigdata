# void main(void) {}
def min():
    # myage = int(input("Enter your age: "))
    # ! -> not(), && -> and, || -> or
    # if not (myage < 30) and myage < 50:
    #     print("Welcome to the Club.")
    # else:
    #     print("Oh! No. You are not accepted.")

    score = int(input("Enter your score: "))
    if score >= 90:
        grade = "A"
    elif score >= 80:
        grade = "B"
    elif score >= 70:
        grade = "C"
    elif score >= 60:
        grade = "D"
    else:
        grade = "F"

    print(f"score: {score}")

    # uppercase boolean
    if True:
        print("True")  #
    if False:
        print("False")
    if 0:
        print("False")
    if 1:
        print("True")  #
    if 2:
        print("True")  #
    if 0.0:
        print("False")
    if 0.0001:
        print("True")  #
    if "":
        print("False")
    if "abc":
        print("True")  #
    if None:
        print("False")
    if []:
        print("False")
    if [1, 2, 3]:
        print("True")  #

    # triple
    x = 5
    y = 3
    if x > y:
        print("x > y")
    else:
        print("x <= y")

    print("x > y") if x > y else print("x <= y")


# python3 ./condition.py
if __name__ == "__main__":
    min()
