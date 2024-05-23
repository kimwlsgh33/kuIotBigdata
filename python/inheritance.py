class Person:
    def __init__(self, name, age, gender):
        self.name = name
        self.age = age
        self.gender = gender

    def about_me(self):
        print(
            f"저는 {self.gender}이고 이름은 {self.name}이고, 제 나이는 {self.age} 살 입니다."
        )


class Employee(Person):
    def __init__(self, name, age, gender, salary, hire_date):
        # super().__init__(name, age, gender)
        Person.__init__(self, name, age, gender)
        self.salary = salary
        self.hire_date = hire_date

    def do_work(self):
        print("열심히 일을 합니다")

    def about_me(self):
        super().about_me()
        print(f"제 급여는 {self.salary} 이고, 제 입사일은 {self.hire_date}입니다.")


def main():
    me = Person("김진호", 28, "male")
    me.about_me()
    son = Employee("손흥민", 32, "male", 10000, 20240701)
    son.about_me()


if __name__ == "__main__":
    main()
