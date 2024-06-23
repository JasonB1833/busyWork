// File Name: Shapes.cpp
// Created By: Jason Berroa
// Created On: 06/23/24
// Program Purpose: To demonstrate operator overloading, inheritance, and polymorphism by utilizing a class hierarchy of shapes

#include <iostream>
#include <iomanip>
using namespace std;


/******************Rectangle Class****************************/
// class declaration section
class Rectangle {
protected:
    // data members    
    int sideA;
    int sideB;

public:
    Rectangle(int, int);
    void setSideA(int);
    void setSideB(int);
    int getSideA() const;
    int getSideB() const;
    int computePerimeter() const;
    int computeArea() const;
    void operator++(); // overloaded increment operator
    void operator--(); // overloaded decrement operator
    bool operator==(Rectangle&); // overloaded is equal to operator
};

/******************Square Class****************************/
// class declaration section
class Square : public Rectangle {
public:
    Square(int); // constructor
    void setSideA(int);
    void setSideB(int);
};

/******************Rectangle Class implementation****************************/

Rectangle::Rectangle(int a, int b) {
    sideA = (a > 0) ? a : 1; // ensures each side is equal to 1 if not above 0
    sideB = (b > 0) ? b : 1;
}

// getters
int Rectangle::getSideA() const {
    return sideA;
}

int Rectangle::getSideB() const {
    return sideB;
}

// setters
void Rectangle::setSideA(int a) {
    sideA = (a > 0) ? a : 1;
}

void Rectangle::setSideB(int b) {
    sideB = (b > 0) ? b : 1;
}


int Rectangle::computePerimeter() const {       // formula for perimeter
    return 2 * (sideA + sideB);
}

int Rectangle::computeArea() const {            // formula for area
    return sideA * sideB;
}

void Rectangle::operator++() {                  // increment operator
    ++sideA;
    ++sideB;
}

void Rectangle::operator--() {                  // decrement operator
    if (sideA > 1) --sideA;
    if (sideB > 1) --sideB;
}

bool Rectangle::operator==(Rectangle& other) {  // is equal to / boolean operator
    return (sideA == other.sideA) && (sideB == other.sideB);
}

/******************Square Class Implementation****************************/

Square::Square(int side) : Rectangle(side, side) {}

// setters
void Square::setSideA(int a) { // ensures each side is equal to 1 if not above 0 and equal to perpendicular side 
    sideA = sideB = (a > 0) ? a : 1;
}

void Square::setSideB(int b) {
    sideA = sideB = (b > 0) ? b : 1;
}

void displayData(const Rectangle& shape); // function prototype

int main() {
    cout << "Testing Square class." << endl;

    int side1;

    cout << "Enter the length of a side: "; // prompt user for length
    cin >> side1;

    Square square(side1); // create instance of square with recorded value

    displayData(square); // display func with square instance passed into it

    cout << endl << endl << "After calling the increment operator" << endl;
    ++square;
    displayData(square); // display data after increment
    cout << endl;

    cout << "Testing Rectangle class." << endl;

    int rectSide1;
    int rectSide2;

    cout << "Enter the length of the first side: "; // prompt user for rectangle sides
    cin >> rectSide1;
    cout << endl << "Enter the length of the second side: ";
    cin >> rectSide2;

    Rectangle rectangle(rectSide1, rectSide2); // create instance of rectangle with recorded variables

    displayData(rectangle);

    cout << endl << "After calling the decrement operator." << endl;

    --rectangle;
    displayData(rectangle); // display after decrement

    if (rectangle == square) { // final if statement to test the boolean operator overload
        cout << "The shapes are the same." << endl;
    }
    else {
        cout << "The shapes are different." << endl;
    }

    return 0;
}

/****************************************************************************/
/* Because of inheritance and polymorphism the displayData function can be
   passed either a Rectangle object or a Square object to display each
   object's data.                                                           */
void displayData(const Rectangle& shape) {
    cout << "\nThe length of side A is " << shape.getSideA() << endl;
    cout << "The length of side B is " << shape.getSideB() << endl;
    cout << "The perimeter is " << shape.computePerimeter() << endl;
    cout << "The area is " << shape.computeArea() << endl << endl;
}
