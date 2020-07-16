#include <iostream>
#include <ctime>
#include <string>
#include "Reservation1.h"
using namespace std;

Reservation:: Reservation()
{
    seats=10;//initialize seats to 10, meaning 10 seats available on the aeroplane
    for(int i = 0; i < 10; i++)
    {
        plane[i] = 0;//intialize all elemnts in the array to zero
    }
}

int Reservation::getSeats()
{
    return seats;//return amount of seats available
}
int Reservation:: ReserveSmoking(int seatSmoke)//reserve seats in the smoking section
{

    if(plane[seatSmoke] == 0)//if seats are available:
       {
           plane[seatSmoke] += 1;//update array element to 1 meaning seat is now taken
           reduceAvailableSeats();//reduce available seats after reservation has been made
           return seatSmoke;// return the seat location

       }

    return -1;//else if seat is taken return a -1;

}


int Reservation::reserveRandomSmoking()//random select seats in the smoking section
{
    srand(time(0));
    int randSmoking = rand() % 5;
    for( randSmoking = 0; randSmoking < 5; randSmoking++)//random seat selection are numbers (0-4)

    if (plane[randSmoking] == 0)//if seats are available:
    {
        plane[randSmoking] += 1;//update array element to 1 meaning seat is now taken
        reduceAvailableSeats();//reduce available seats after reservation has been made
        return randSmoking;//return the seat location
    }

    return 0;
}

int Reservation::reserveNonSmoking(int seatNonSmoke)//reserve seats in the non-smoking section
{

    if(plane[seatNonSmoke] == 0)//if seats are available:
    {
        plane[seatNonSmoke] += 1;//update array element to 1 meaning seat is now taken
        reduceAvailableSeats();//reduce available seats after reservation has been made
        return seatNonSmoke;//return the seat location
    }
    return -1;//else if seat is taken return a -1;
}

int Reservation::reserveRandomNonSmoking()//random select seats in the smoking section

{
    srand(time(0));
    int randNonSmoking = 5 + rand() % 5;
    for (randNonSmoking = 5; randNonSmoking < 10; randNonSmoking++)//random seat selection are numbers (5-9)

        if (plane[randNonSmoking] == 0)//if seats are available
    {
        plane[randNonSmoking] += 1;//update array element to 1 meaning seat is now taken
        reduceAvailableSeats();//reduce available seat after reservtion has been made
        return randNonSmoking;//return the seat location
    }
    return 0;
}

bool Reservation::availablesmoking()//check to see how many seats available in smoking section
{


    for ( int i=0; i < 5; ++i)//loop through array for the smoking section
    {
        if ( plane[i] == 0)//if seats are available:
        {

            return true;
        }
    }

    return false;
}

bool Reservation:: availableNonsmoking()//check to see how many seats available in the non smoking section
{
    for ( int i=5; i < 10; ++i)//loop through array for the non smoking section
    {
        if(plane[i] == 0)//if seats are available:
        {
            return true;
        }
    }
    return false;
}

void Reservation::reduceAvailableSeats()//reduce seats everytime a seat is reserved
{
    while ( seats == 0)//ensure seats never go below zero
    {
        return;
    }
    seats--;//decrement seats by 1

}




