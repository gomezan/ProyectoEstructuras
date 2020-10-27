/**
* Name: Agency.h
* Data structures: First delivery
* Authors: Carlos Andres Erazo Garzon
*          Nicolas Gil
*          Andres Gomez
* Date:
* Description: 
* */

#ifndef __AGENCY__H__
#define __AGENCY__H__

#include <iostream>
using namespace std;

class Agency
{
private:
    string agencyName;
    string agencyPass;
public:

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    Agency(string agencyName, string agencyPass);

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    Agency();

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    string getAgencyName();

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    void setAgencyName(string agencyName);

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    string getAgencyPass();

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    void setAgencyPass(string agencyPass);

    /**
     * Name: 
     * Inputs:
     * Outputs: 
     * Description:
     * */

    void print();
};

#include "Agency.hxx"
#endif
