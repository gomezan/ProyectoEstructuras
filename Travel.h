/* 
* Names: travels.h
* Data structures: First delivery
* Authors: Carlos Andres Erazo Garzon
*          Nicolas Gil
*          Andres Gomez
* Date:
* Description: 
*/

#ifndef __TRAVEL__H__
#define __TRAVLE__H__

#include <iostream>
using namespace std;

class Travel
{
private:
    string codeRoute;
    string codeBus;
    string codeTravel;
    string date;
    string time;
    string driverName;
    double chairCost;
public:

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

  Travel(string codeRoute, string codeBus, string codeTravel, string date,
         string time, string driverName, double chairCost);

  /**
   * Name:
   * Inputs:
   * Outputs:
   * Description:
   * */

  Travel();

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

  string getDriverName();

  /**
   * Name:
   * Inputs:
   * Outputs:
   * Description:
   * */

  void setDriverName(string driverName);

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

  void setTime(string time);

  string getTime();

  void print();
};

#include "Travel.hxx"
#endif