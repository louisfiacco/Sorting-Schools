/***************************************************************************
 * school.cc
 * Author: Louis Fiacco
 * Date: 05/01/2019
 * Class: CSCI 132
 * Assignment: Homework 8
 * Purpose: contains the specification for a new class named School for storing information about a single graduate school program
 * Input: The info for the schools
 * Output: various funtions defined for the School class 
 ***************************************************************************/

#include "school.h"

/*Implement functions from school.h file here */

School::School()
/***************************************
 *pre: None
 *post: Default constructor and should initialize the integer data members to zero.
 ****************************************/
{
    women = 0;
    rateAI = 0;
    rateSys = 0;
    rateTheory = 0;
    effectiveness = 0;
    ratePubs = 0;
    overallRating = 0;
}

School::School (string myName, string myState, int theWomen, int myRateAI, int myRateSys,int myRateTheory, int myEffectiveness, int myRatePubs)
/***************************************
 *pre: constructor method that has 8 parameters corresponding to the first 8 data members for the School class
 *post: Assigns variables to the parameters
 ****************************************/
{
    name = myName;
    state = myState;
    women = theWomen;
    rateAI = myRateAI;
    rateSys = myRateSys;
    rateTheory = myRateTheory;
    effectiveness = myEffectiveness;
    ratePubs = myRatePubs;
    overallRating = 0;
}



void School::printSchoolInfo ()
/***************************************
 *pre: None
 *post:prints all of the information contained in a single School object
 ****************************************/
{
    cout<<"Name: "<<name<<endl;
    cout<<"State: "<<state<<endl;
    cout<<"Rating of number of women PhD's: "<<women<<endl; 
    cout<<"Rating of AI program: "<<rateAI<<endl;
    cout<<"Rating of Systems program: "<<rateSys<<endl;
    cout<<"Rating of Theory program: "<<rateTheory<<endl;
    cout<<"Effctiveness rating: "<<effectiveness<<endl;
    cout<<"Rating of faculty publications: "<<ratePubs<<endl;
    cout<<"Overall rating: "<<overallRating<<endl;
}

void School::computeRating (int weightWomen, int weightAI, int weightSys, int weightTheory, int weightEffect, int weightPubs)
/***************************************
 *pre: has 6 inputs that represent weights (an integer between 0 and 5) to be associated with each of the 6 factors used to evaluate graduate programs 
 *post:compute an overall rating for the school's graduate program and assign this value to the overallRating data member
 ****************************************/
{
   overallRating = (women * weightWomen) + (rateAI * weightAI) + (rateSys * weightSys) + (rateTheory * weightTheory) + (effectiveness * weightEffect) + (ratePubs * weightPubs);
   

    
}


// For the operator overloads, They input the schools and they output boolean values.
bool operator ==(const School &x, const School &y)
{
    return x.overallRating == y.overallRating;
}
bool operator !=(const School &x, const School &y)
{
    return x.overallRating != y.overallRating;
}
bool operator >=(const School &x, const School &y)
{
    return x.overallRating >= y.overallRating;
}
bool operator <=(const School &x, const School &y)
{
    return x.overallRating <= y.overallRating;
}
bool operator <(const School &x, const School &y)
{
    return x.overallRating <= y.overallRating;
}
bool operator >(const School &x, const School &y)
{
    return x.overallRating <= y.overallRating;
}
