"""
Author name: Jason Berroa
Date: 2024/04/03
Program Name: BerroaJ_Employees.py
Purpose: Create Person/Employee/Programmer classes
"""

#person superclass
class Person:
    # initialize the object
    def __init__(self, first, last, age):
        self.__first = first
        self.__last = last
        self.__age = age
    
    # Setters for all the atributes (mutators)
    def set_first(self,first):
        self.__first = first
    
    def set_last(self,last):
        self.__last = last
    
    def set_age(self,age):
        self.__age = age

    # Getters for the attributes (Accessors)
        
    def get_first(self):
        return self.__first
    
    def get_last(self):
        return self.__last
    
    def get_age(self):
        return self.__age

     # __str__ method
    def __str__(self):
        return f"{self.__first} {self.__last}"


class Employee(Person):
    amnt_of_raise = 1.05
    
    def __init__(self,first,last,age,salary):
        
        # call the superclass __init__ method
        Person.__init__(self,first,last,age)

        # init salary
        self.__salary = salary

    # setter and getter
    def set_salary(self,salary):
            self.__salary = salary
            
    def get_salary(self):
        return self.__salary
    
 

class Programmer(Employee):
    amnt_of_raise = 1.10

    def __init__(self,first,last,age,salary,prog_lang):

        Employee.__init__(self,first,last,age,salary)

        self.__prog_lang = prog_lang

    def set_lang(self,prog_lang):
            self.__prog_lang = prog_lang
            
    def get_lang(self):
        return self.__prog_lang
        

def main():
    # Instantiate objects
    person = Person("John", "Doe", 30)
    employee = Employee("Jane", "Smith", 35, 50000)
    programmer = Programmer("Alice", "Jones", 25, 60000, "Python")
    
    # Print objects
    print("Person:", person)
    print("Employee:", employee)
    print("Programmer:", programmer)

    # Print the lang
    print("\nOur Programmer knows:", programmer.get_lang())
    
    # Print salaries before and after raise
    print(f"\n{employee}'s salary before raise: {employee.get_salary()}")
    print(f"{programmer}' salary before raise: {programmer.get_salary()}")
    
    # Print salaries after raise
    print(f"\n{employee}'s salary after raise: {employee.get_salary() * Employee.amnt_of_raise :.2f}")
    print(f"{programmer}' salary after raise: {programmer.get_salary() * programmer.amnt_of_raise :.2f}")

if __name__ == "__main__":
    main()