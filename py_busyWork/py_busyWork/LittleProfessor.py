import random as r
import operator

def main():
    correct = 0

    level_Choice = getlevel()
    
    m , s = mode()

    for i in range(10):
        no_1 , no_2 = gen_int(level_Choice) , gen_int(level_Choice)
        
        
        incorrect = 0

        while incorrect < 3:
                
            question = input(f"{no_1} {s} {no_2} =")
            
            answer = question

            correct_A = str(m(no_1,no_2))
            
            if answer == correct_A:
                print("Correct!!!")
                correct += 1
                break
            else:
                print("EEE")
                incorrect += 1
        if i == 9:
            print(f"your final score is {correct}/10")
    


def getlevel():
    PC = ""
    
    levels = {
        "1" : 5 ,
        "2" : 10 ,
        "3" : 15 ,
        "4" : 20 ,
        "5" : 30 ,
        "6" : 40 ,
        "7" : 50 ,
        "8" : 75 ,
        "9" : 100 ,
        "10" : 1000}

    while PC == "":
        playerIn = input("choose a difficulty level between 1-10: ")

        if playerIn in levels:
            PC = playerIn
        else:
            print("ERROR!!!\nyour input must be an integer between 1-10")
    return int(levels[PC])

    


def gen_int(a):
    val = r.randint(0, a)
    return val

def mode():
    final = "" 
    
    options = {
            '+' : operator.add,
            '-' : operator.sub, 
            '*' : operator.mul,
            "/" : operator.floordiv}

    while final == "":
        
        
        op_Choice = input("what do you want to practice?\n (valid options: + , - , * , / ) : ")
        
        if op_Choice in options:
            final = options[op_Choice]
        else:
            print("Please choose only from the options given.")
        
    return final , op_Choice



if __name__ == "__main__":
    main()
    
# end main