#include <string>
#include <iostream>
#include <ctime>
#include "Reservation1.h"
using namespace std;

int main() {

Reservation a;

int section;
int seatmenu;
int seat;
int response;

    do
{
    //Display Menu to choose section of the airplane
    cout<<"\n\n";
    cout<<"***************************************" <<endl;
    cout<<"*       WELCOME TO MAYA AIRLINES      *" <<endl;
    cout<<"* >>Press 1 for 'Smoking Section'     *" <<endl;
    cout<<"* >> Press 2 for 'Non-Smoking Section'*" <<endl;
    cout<<"* >>      Press 3 to Quit             *" <<endl;
    cout<<"***************************************" <<endl;
    cout<<"=====> ";
    cin>>section;

     //Switch statement to determine what option the user chose
    switch (section) {
    case 1:
        cout<<"\n>> You've Chosen the Smoking Section. Thank You!\n";
        cout<<"\n";
        cout<<"*********************************************\n";
        cout<<"*-> To let the system assign a seat, Press 4*\n";
        cout<<"*--->  To Reserve a seat, Press 3           *\n";
        cout<<"*********************************************\n";
        cout<<"=====> ";
        cin>> seatmenu;
        while ( seatmenu != 4 && seatmenu != 3)//loop code below until seatmenu is 4 or 3
        {
            cout<<"\n>>The options available are only 3 & 4.\n";
            cout<<"\n";
            cout<<"*********************************************\n";
            cout<<"*-> To let the system assign a seat, Press 4*\n";
            cout<<"*--->  To Reserve a seat, Press 3           *\n";
            cout<<"*********************************************\n";
            cout<<"=====> ";
            cin>> seatmenu;
        }

        if ( seatmenu == 3)//if user chose to reserve a seat
        {
            if (a.availablesmoking())//if seats available(smoking-sec):
            {
            cout<<">>Please choose seat to be reserved (0-4):";
            cin>> seat;
            cout<<"\n";
            while ( seat < 0 || seat > 4)//loop code below until user enter num(0-4)
            {
                cout<<"Invalid, Seat options are only(0-4)\n";
                cout<<">>Please choose seat to be reserved (0-4):";
                cin>> seat;
                cout<<"\n";
            }

            while (a.ReserveSmoking(seat) == -1 )//loop code below until seat is not taken
                {
                   if (a.availablesmoking())//if available seats smoking sec:
                    {
                    cout<<"Seat location:" <<" " << seat <<" " <<"is taken";
                    cout<<"\n>>Please choose another seat to be reserved (0-4):";
                    cin>> seat;
                    cout<<"\n";
                    while ( seat < 0 || seat > 4)//loop code below until user enter num(0-4)
                    {
                        cout<<"Invalid, Seat options are only(0-4)\n";
                        cout<<">>Please choose seat to be reserved (0-4):";
                        cin>> seat;
                        cout<<"\n";
                    }
                   }
                }

                  //Display Boarding Pass
                  cout<<"************************\n";
                  cout<<"*  BOARDING PASS       *\n";
                  cout<<"************************\n";
                  cout<<">>SEAT LOCATION:" << seat;
                  cout<<"\n>>SECTION: SMOKING\n";
                  cout<<"\nThank You for choosing Maya Airlines.♥️\n\n";
            }
            else if (!a.availablesmoking())//else if no seats are available in smoking-sec:
            {
            cout<<"\n>>Section is full\n" ">>Do you want a seat in the other section?\n";
            cout<<"*********************\n";
            cout<<">>Press 1 for yes   *\n";
            cout<<">>Press 2 for no    *\n";
            cout<<"*********************\n";
            cout<<"=====> ";
            cin>> response;
            while ( response != 1 && response != 2)//loop code until user chose 1 or 2
            {
                cout<<"\n>>The options available are only 1 & 2.\n";
                cout<<"\n>>Section is full\n" ">>Do you want a seat in the other section?\n";
                cout<<"*********************\n";
                cout<<">>Press 1 for yes   *\n";
                cout<<">>Press 2 for no    *\n";
                cout<<"*********************\n";
                cout<<"=====> ";
                cin>> response;
            }
            if( response == 1 && a.availableNonsmoking())//if user chose yes & seats are available (non-Smoking Sec):
            {
                //Display Boarding Pass
                cout<<"You have been assign a seat in the other section\n";
                cout<<"\n";
                cout<<"************************\n";
                cout<<"*  BOARDING PASS       *\n";
                cout<<"************************\n";
                cout<<">>SEAT LOCATION:" << a.reserveRandomNonSmoking();
                cout<<"\n>>SECTION:NON-SMOKING\n";

                cout<<"\nThank You for choosing Maya Airlines.♥️\n\n";

            }

            //else if user chose no:
            else if( response == 2) {
                cout<<"\nNext Flight leaves in 3 hours\n";
                cout<<"\nThank You for choosing Maya Airlines.♥️\n\n";
            }

            ///else user chose yes and seats not availabe in other section
            else {
                cout<<"\nBoth Sections are full\n";//jus added
                cout<<"Next Flight leaves in 3 hours\n";
                cout<<"\nThank You for choosing Maya Airlines.♥️\n\n";
            }

            }

          }
        else if (seatmenu == 4)//if user chose system assigned:
        {
            if (a.availablesmoking())//if seats available (smoking-sec):
            {
                //Display Boarding Pass
                cout<<"\n";
                cout<<"************************\n";
                cout<<"*  BOARDING PASS       *\n";
                cout<<"************************\n";
                cout<<">>SEAT LOCATION:" << a.reserveRandomSmoking();
                cout<<"\n>>SECTION: SMOKING\n";
                cout<<"\nThank You for choosing Maya Airlines.♥️\n\n";
            }

         else if (!a.availablesmoking())//if no seats are available(smoking-sec):
        {
                cout<<"\n>>Section is full\n" ">>Do you want a seat in the other section?\n";
                cout<<"*********************\n";
                cout<<">>Press 1 for yes   *\n";
                cout<<">>Press 2 for no    *\n";
                cout<<"*********************\n";
                cout<<"=====> ";
                cin>> response;
                while ( response != 1 && response != 2)//loop until user chooses 1 or 2
                {
                    cout<<"\n>>The options available are only 1 & 2.\n";
                    cout<<"\n>>Section is full\n" ">>Do you want a seat in the other section?\n";
                    cout<<"*********************\n";
                    cout<<">>Press 1 for yes   *\n";
                    cout<<">>Press 2 for no    *\n";
                    cout<<"*********************\n";
                    cout<<"=====> ";
                    cin>> response;
                }
        if( response == 1 && a.availableNonsmoking())//if user chose yes & seats available(non-Smoking sec)
        {
            //Display Boarding Pass
            cout<<"You have been assign a seat in the other section\n";
            cout<<"\n";
            cout<<"************************\n";
            cout<<"*  BOARDING PASS       *\n";
            cout<<"************************\n";
            cout<<">>SEAT LOCATION:" << a.reserveRandomNonSmoking();
            cout<<"\n>>SECTION:NON-SMOKING\n";
            cout<<"\nThank You for choosing Maya Airlines.♥️\n\n";
        }

        //else if user chose no:
        else if( response ==2) {
             cout<<"\nNext Flight leaves in 3 hours\n";
             cout<<"\nThank You for choosing Maya Airlines.♥️\n\n";
        }

        //else user chose yes and seats not availabe in other section
        else {
            cout<<"\nBoth Sections are full\n";//jus added
            cout<<"Next Flight leaves in 3 hours\n";
            cout<<"\nThank You for choosing Maya Airlines.♥️\n\n";
        }

        }
        }
        break;

    case 2:
        cout<<"\n>>Thank You!! You've Chosen the Non-Smoking Section.\n";
        cout<<"\n";
        cout<<"*********************************************\n";
        cout<<"*-> To let the system assign a seat, Press 4*\n";
        cout<<"*--->  To Reserve a seat, Press 3           *\n";
        cout<<"*********************************************\n";
        cout<<"=====> ";
        cin>> seatmenu;
        while ( seatmenu != 4 && seatmenu != 3)//loop until user chooses 3 or 4
        {
            cout<<"\n>>The options available are only 3 & 4.\n";
            cout<<"\n";
            cout<<"*********************************************\n";
            cout<<"*-> To let the system assign a seat, Press 4*\n";
            cout<<"*--->  To Reserve a seat, Press 3           *\n";
            cout<<"*********************************************\n";
            cout<<"=====> ";
            cin>> seatmenu;
        }

        if ( seatmenu == 3 )//if user chose to reserve a seat:
        {
            if (a.availableNonsmoking())//if seats available(non-Smoking sec):
            {
                cout<<">>Please choose seat to be reserved (5-9):";
                cin>> seat;
                cout<<"\n";
                while ( seat < 5 || seat > 9)//loop code below until user enter num(5-9)
                {
                    cout<<"Invalid, Seat options are only(5-9)\n";
                    cout<<">>Please choose seat to be reserved (5-9):";
                    cin>> seat;
                    cout<<"\n";
                }

                while (a.reserveNonSmoking(seat) == -1 )//loop code below until seat is not taken
                    {
                       if (a.availableNonsmoking())//if seats available non-Smoking sec:
                       {
                        cout<<"Seat location:" <<" " << seat <<" " <<"is taken";
                        cout<<"\n>>Please choose another seat to be reserved (5-9):";
                        cin>> seat;
                        cout<<"\n";
                        while ( seat < 5 || seat > 9)//loop code below until user enter num(5-9)
                        {
                            cout<<"Invalid, Seat options are only(5-9)\n";
                            cout<<">>Please choose seat to be reserved (5-9):";
                            cin>> seat;
                            cout<<"\n";
                        }

                       }
                    }

                      //Display Boarding Pass
                      cout<<"************************\n";
                      cout<<"*  BOARDING PASS       *\n";
                      cout<<"************************\n";
                      cout<<">>SEAT LOCATION:" << seat;
                      cout<<"\n>>SECTION: SMOKING\n";
                      cout<<"\nThank You for choosing Maya Airlines.♥️\n\n";
            }
            else if (!a.availableNonsmoking())//else if seats not available(non-Smoking sec):
            {
                cout<<"\n>>Section is full\n" ">>Do you want a seat in the other section?\n";
                cout<<"*********************\n";
                cout<<">>Press 1 for yes   *\n";
                cout<<">>Press 2 for no    *\n";
                cout<<"*********************\n";
                cout<<"=====> ";
                cin>> response;
                while ( response != 1 && response != 2)//loop until user chooses 1 or 2
                {
                    cout<<"\n>>The options available are only 1 & 2.\n";
                    cout<<"\n>>Section is full\n" ">>Do you want a seat in the other section?\n";
                    cout<<"*********************\n";
                    cout<<">>Press 1 for yes   *\n";
                    cout<<">>Press 2 for no    *\n";
                    cout<<"*********************\n";
                    cout<<"=====> ";
                    cin>> response;
                }
            if( response == 1 && a.availablesmoking())//if user chose yes & seats available(smoking-sec)
            {
                //Display Boarding Pass
                cout<<"You have been assign a seat in the other section\n";
                cout<<"\n";
                cout<<"************************\n";
                cout<<"*  BOARDING PASS       *\n";
                cout<<"************************\n";
                cout<<">>SEAT LOCATION:" << a.reserveRandomSmoking();
                cout<<"\n>>SECTION: SMOKING\n";
                cout<<"\nThank You for choosing Maya Airlines.♥️\n\n";
            }

            //else if user chose no
            else if ( response == 2){
                cout<<"\nNext Flight leaves in 3 hours\n";//jus added
                cout<<"\nThank You for choosing Maya Airlines.♥️\n\n";
            }

            //else user chose yes and seats not availabe in other section
            else {
                cout<<"\nBoth Sections are full\n";//jus added
                cout<<"Next Flight leaves in 3 hours\n";
                cout<<"\nThank You for choosing Maya Airlines.♥️\n\n";
            }

            }

          }
        else if (seatmenu == 4)//if user chose system assigned:
        {
            if (a.availableNonsmoking())//if seats available(non-Smoking sec):
            {
                //Display Boarding Pass
                cout<<"\n";
                cout<<"************************\n";
                cout<<"*  BOARDING PASS       *\n";
                cout<<"************************\n";
                cout<<">>SEAT LOCATION:" << a.reserveRandomNonSmoking();
                cout<<"\n>>SECTION:NON-SMOKING\n";
                cout<<"\nThank You for choosing Maya Airlines.♥️\n\n";
            }

         else if (!a.availableNonsmoking())//seats not available(non-Smoking sec):
        {
                cout<<"\n>>Section is full\n" ">>Do you want a seat in the other section?\n";
                cout<<"*********************\n";
                cout<<">>Press 1 for yes   *\n";
                cout<<">>Press 2 for no    *\n";
                cout<<"*********************\n";
                cout<<"=====> ";
                cin>> response;
                while ( response != 1 && response != 2)//loop until user chooses 1 or 2
                {
                    cout<<"\n>>The options available are only 1 & 2.\n";
                    cout<<"\n>>Section is full\n" ">>Do you want a seat in the other section?\n";
                    cout<<"*********************\n";
                    cout<<">>Press 1 for yes   *\n";
                    cout<<">>Press 2 for no    *\n";
                    cout<<"*********************\n";
                    cout<<"=====> ";
                    cin>> response;
                }
        if( response == 1 && a.availablesmoking())//if user chose yes & seats available(smoking-sec):
        {
            //Display Boarding Pass
            cout<<"You have been assign a seat in the other section\n";
            cout<<"\n";
            cout<<"************************\n";
            cout<<"*  BOARDING PASS       *\n";
            cout<<"************************\n";
            cout<<">>SEAT LOCATION:" << a.reserveRandomSmoking();
            cout<<"\n>>SECTION: SMOKING\n";
        }

        //else if user chose no
        else if ( response ==2) {
            cout<<"\nNext Flight leaves in 3 hours\n";//jus added
            cout<<"\nThank You for choosing Maya Airlines.♥️\n\n";
        }

        //else user chose yes and seats not availabe in other section
        else {
            cout<<"\nBoth Sections are full\n";//jus added
            cout<<"Next Flight leaves in 3 hours\n";
            cout<<"\nThank You for choosing Maya Airlines.♥️\n\n";
        }

        }
        }
        break;
    }

} while ( section != 3 );

}










