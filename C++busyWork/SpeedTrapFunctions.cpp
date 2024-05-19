
// SpeedTrapFunctions by Jason Berroa
// 05/18/2024

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int getSpeed(); // Prototype for user input
float SpeedTicket(int x); // Prototype for Switch case arguement with the ticket calculations

const float baseTicket = 60.25; // global symbolic constant

int main()
{
    srand(static_cast <unsigned int> (time(0))); //sets the srand to seed from internal clock 
        int speedLimit{ 25 + rand() % 41 }; // produces random speed limit from 25-65 

    int y = 0;// sets variable for the coming while loop to act as a 'break' condition

    while (y == 0){

        cout << "The Speed limit is " << speedLimit << endl;

        int speed = getSpeed(); // Calls the function to recieve input from the user

        int x = speed - speedLimit; // Find the difference between the speed given and speedlimit
   
        if (x <= 0) { // in case they are within limits
            cout << "The Driver is within the limit." << endl;

        }else {
            float Ticket = SpeedTicket(x);

            cout << "This is the ticket: $" << fixed << setprecision(2) << Ticket << endl; // output ticket solution with two decimal format
            }
            
        cout << "Would you like to input another speeding violation? (y or n only please): " << endl; // prompt user to iterate the while loop again
        char answer;
        cin >> answer;

        if (answer == 'y' or answer == 'Y') {
                continue;
            }
        else {
                cout << "Have a nice day!" << endl;
                y = y++;
            }
    
   
    }
}

int getSpeed() { // func for taking input from user
    cout << "Please enter the Drivers speed: ";
     int speed;
    cin >> speed;

    cout << "The Drivers speed was " << speed << endl;

        return speed;
}

float SpeedTicket(int x) { // this was supposed to be a switch case but i just found out switch case statements dont work with ranges 
   
    if (x < 5) { // base ticket, 4 over speed limit
        return baseTicket;
    
    }else if (x < 10) { // 5 over ticket
        return baseTicket + (baseTicket * 0.05);

    }else if (x < 20) { // 10 over ticket
        return baseTicket + (baseTicket * 0.10);
    
    }else               // 20 over ticket
        return baseTicket + (baseTicket * 0.20); 

    
}


