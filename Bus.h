/* 
* Name: Bus.h
* Data structures: First delivery
* Authors: Carlos Andres Erazo Garzon
*          Nicolas Gil
*          Andres Gomez
* Date:
* Description: 
*/

#ifndef _BUS_H_
#define _BUS_H_

#include <iostream>
using namespace std;

class Bus
{
private:
    string codeBus;
    char type; // c-> current s -> special
    int chairs;
public:

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    Bus(string codeBus, char type, int chairs);

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    Bus();

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    string getcodeBus();

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    void setcodeBus(string codeBus);

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    char getType();

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    void setType(char type);

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    int getChairs();

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    void setChairs(int chairs);

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    void print();
};

#include "Bus.hxx"
#endif