//File Name: Shapes.cpp
//Created By:Jason Berroa
//Created On: 06/23/24
//Program Purpose: To demonstrate operator overloading, inheritance, and polymorphism by utilizing a class hierarchy of shapes

#include <iostream>
#include <iomanip>
using namespace std;


/******************Rectangle Class****************************/
//class declaration section
class Rectangle {
protected:
	//data members	
	int sideA;
	int sideB;
public:
	Rectangle(int, int);
	void setSideA(int);
	void setSideB(int);
	int getSideA();
	int getSideB();
	int computePerimeter();
	int computeArea();
	void operator++(); //overloaded increment operator
	void operator--(); //overloaded decrement operator
	bool operator==(Rectangle &); //overloaded is equal to operator
};


/******************Square Class****************************/
//class declaration section
class Square 
{
public:
	Square(int); //constructor
	void setSideA(int);
	void setSideB(int);
};


/******************Rectangle Class implementation****************************/

Rectangle::Rectangle(int a, int b){
	sideA = (a>0) ? a : 1;
	sideB = (b>0) ? b : 1; 
}

int Rectangle::getSideA() const{
	return sideA;
}
int Rectangle::getSideB() const{
	return sideB;
}
int Rectangle::setSideA(int) {
	sideA = (a>0) ? a : 1;
}
int Rectangle::setSideB(int) {
	sideB = (b>0) ? b:1;
}
int Rectangle::computePerimeter(){
	return 2 * (sideA + sideB);
}
int Rectangle::computeArea() {
	return sideA * sideB;
}
void Rectangle::operator++(){
	sideA++;
	sideB++;
	return *this;
}
void Rectangle::operator--(){
	sideA--;
	sideB--;
	return *this;
}
bool Rectangle::operator==(Rectangle &other){
	return (sideA == other.sideA) && (sideB == other.sideB);
}

/******************Square Class Implementation****************************/

Square::Square(int side) : Rectangle(side , side) {}

Square::setSideA(int) {
	sideA = sideB = (a>0)? a : 1;
}
Square::setSideB(int) {
	sideB = sideA = (b>0)? b : 1;
}

void displayData(Rectangle); // function prototype

int main()
{
	cout << "Testing Square." << endl;

	int side1;
	cout << "Enter the length of a side: "
	cin >> side1; 
	Square square(side1);
	cout << endl;

	displayData(square)





}

/****************************************************************************/
/* Because of inheritance and polymorphism the displayData function can be 
   passed either a Rectangle object or a Square object to display each 
   object's data.                                                           */
void displayData(Rectangle shape)
{
	cout << "\nThe length of side A is " << shape.getSideA() << endl;
	cout << "The length of side B is " << shape.getSideB() << endl;
	cout << "The perimeter is " << shape.computePerimeter() << endl;
	cout << "The area is " << shape.computeArea() << endl << endl;
}

