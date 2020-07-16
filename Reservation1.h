//Program created by Gilbert Young

#ifndef PROGSET_H
#define PROGSET_H
#include <string>
#include <iostream>
using namespace std;

class Reservation
{
public:
    Reservation();
    int getSeats();
    int ReserveSmoking(int seatSmoke);
    int reserveRandomSmoking();
    int reserveNonSmoking(int seatNonSmoke);
    int reserveRandomNonSmoking();
    bool availablesmoking();
    bool availableNonsmoking();


private:
    void reduceAvailableSeats();
    int seats;
    int plane[10];







};

#endif // PROGSET_H
