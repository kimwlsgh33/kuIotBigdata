# void main(void) {}
def min():
    myage = int(input("Enter your age: "))
    # ! -> not(), && -> and, || -> or
    if not (myage < 30) and myage < 50:
        print("Welcome to the Club.")
    else:
        print("Oh! No. You are not accepted.")

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


# python3 ./condition.py
if __name__ == "__main__":
    min()
