/* 
* Name: Booking.h
* Data structures: First delivery
* Authors: Carlos Andres Erazo Garzon
*          Nicolas Gil
*          Andres Gomez
* Date:
* Description: 
*/

#ifndef _ROUTE_H_
#define _ROUTE_H_

#include <iostream>
using namespace std;

class Booking
{
private:
    string agency;
    string codeBooking;
    string codeRoute;
    string codeBus;
    string codeTravel; // If it's canceled it's changed to "VI000"
    int chairNumber;
    string passenger;
    string date; // Later if it's a change
    string time; // Later if it's a change
    double chairCost; //If it is canceled, it is exchanged for 15% of the value
public:

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    Booking(string agency, string codeBooking, string codeRoute, string codeBus, 
            string codeTravel, int chairNumber, string passenger, string date, 
            string time, double chairCost);

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    Booking();

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */    
    
    string getAgency();

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    void setAgency(string agency);

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    string getCodeBooking();

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    void setCodeBooking(string codeBooking);

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    string getCodeRoute();

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    void setCodeRoute(string codeRoute);

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    string getCodeBus();

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    void setCodeBus(string codeBus);

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    string getCodeTravel();

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    void setCodeTravel(string codeTravel);

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    int getChairNumber();

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    void setChairNumber(int chairNumber);

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    string getPassenger();

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    void setPassenger(string passenger);

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    string getDate();

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    void setDate(string date);

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    string getTime();

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    void setTime(string time);

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    double getChairCost();

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    void setChairCost(double chairCost);

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    void print();

};

#endif