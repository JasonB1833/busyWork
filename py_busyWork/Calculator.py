from tkinter import *
import ast

root = Tk()

# Functions for operations and buttons 
i = 0
def getNumber(num):
    global i 
    display.insert(i,num)
    i+=1


def getOperation(operator):
    global i
    length = len(operator)
    display.insert(i,operator)
    i+=length


def clearAll():
    display.delete(0,END)


def delete():
    entry = display.get()
    if len(entry):
        newEntry = entry[:-1]
        clearAll()
        display.insert(0,newEntry)
    else:
        clearAll()
        display.insert(0,"")


def equals():
    entry = display.get()
    try:
        node = ast.parse(entry, mode="eval")
        result = eval(compile(node,'<string>','eval'))
        clearAll()
        display.insert(0,result)
    except Exception:
        clearAll()
        display.insert(0,"Error")


# Number Display     
display = Entry(root)
display.grid(row = 1, columnspan = 6)

# Number Buttons 
numbers = [1,2,3,4,5,6,7,8,9]
counter = 0
for x in range(3):
    for y in range(3):
        button_text = numbers[counter]
        button = Button(root, text = button_text, width = 2, height = 2, command=lambda text = button_text:getNumber(text))
        button.grid(row = x + 2 , column = y)
        counter +=1

button = Button(root, text = "0", width = 2 , height = 2, command=lambda:getNumber(0))
button.grid(row = 5, column=1)

# Operator Buttons
count=0
operations = ['+','-','*','/','*3.14','%',"(", "**", ")","**2"]
for x in range(4):
    for y in range(3):
        if count <len(operations):
            button = Button(root,text=operations[count], width=2,height=2, command= lambda text=operations[count]:getOperation(text))
            count+=1
            button.grid(row = x + 2 , column = y+3)

# Clear/Backspace/equals buttons
Button(root,text="AC",width=2,height=2,command=clearAll ).grid(row=5,column=0)
Button(root,text="=",width=2,height=2,command=equals).grid(row=5,column=2)
Button(root, text="<-",width=2,height=2,command=lambda:delete()).grid(row=5,column=4)

root.mainloop()