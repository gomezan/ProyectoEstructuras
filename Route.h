/* 
* Name: Route.h
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

class Route
{
private:
    string codeRoute;
    string day;
    string cityOrg;
    string cityDst;
    int depTime;
    double kmCity;

public:

    /**
     * Name: Route
     * Inputs: CodeRoute, day, cityOrg, cityDst, depTime, kmCity
     * Outputs: None
     * Description: Builder
     * */

    Route(string codeRoute, int day, string cityOrg, string cityDst, int depTime, double kmCity);
    
    /**
     * Name: Route.
     * Inputs: None.
     * Outputs: None.
     * Description: Builder.
     * */

    Route();

    /**
     * Name: getCodeRoute.
     * Inputs: None.
     * Outputs: CodeRoute.
     * Description: Returns the code route.
     * */

    string getCodeRoute();

    /**
     * Name: setCodeRoute.
     * Inputs: codeRoute.
     * Outputs: None.
     * Description: Change the code route.
     * */

    void setCodeRoute(string codeRoute);

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    string getDay();

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    void setDay(string day);

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    string getCityOrg();

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    void setCityOrg(string cityOrg);

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    string getCityDst();

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    void setCityDst(string cityDst);

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    int getDepTime();

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    void setDepTime(int depTime);

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    double getKmCity();

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    void setKmCity(double kmCity);

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    void print();
};

#include "Route.hxx"
#endif