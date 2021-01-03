/***************************************************************************
 * gradSchools.cc
 * Author: Louis Fiacco
 * Date: 05/01/2019
 * Class: CSCI 132
 * Assignment: Homework 8
 * Purpose: contains the definition of a new class named GradSchools that stores information about multiple School objects that are maintained in a Sortable_list
 * Input: Info for the specific schools in the gradSchools class
 * Output: Does various functions like rank the schools
 ***************************************************************************/

#include "gradSchools.h"
    
/*Implement functions from gradSchools.h file here */

GradSchools::GradSchools()
/***************************************
 *pre: None
 *post: clears the schools data member
 ****************************************/

 {
   schools.clear();
 }


void GradSchools::addSchool (string name, string state, int women, int rateAI, int rateSys,int rateTheory, int effect, int ratePubs)
/***************************************
 *pre: uses the parameters to pass through the information
 *post:create a new instance of the School class and add it to the schools list in the GradSchools object that is used to call the function
 ****************************************/
 {   
schools.insert(schools.size(), (School(name, state, women, rateAI, rateSys, rateTheory, effect, ratePubs)));
 }


void GradSchools::computeRatings (int weightWomen, int weightAI, int weightSys, int weightTheory, int weightEffect, int weightPubs)
/***************************************
 *pre: the weights to be associates with each of the six factors
 *post: compute the overallRating for each of the School objects stored in the schools array, using the computeRating() method defined for the School class
 ****************************************/
 {
 for (int i = 0; i < schools.size()-1; i++)
     {
       School entry;
       schools.retrieve(i, entry);
       entry.computeRating(weightWomen, weightAI, weightSys, weightTheory, weightEffect, weightPubs);
       schools.replace(i, entry);
       
     }
 }


void GradSchools::rankSchools (int weightWomen, int weightAI, int weightSys, int weightTheory, int weightEffect, int weightPubs)
/***************************************
 *pre: the weights to be associated with the 6 factors used to compute the overallRating
 *post:  sorts all of the School objects contained in the schools Sortable_list using the overallRating as the basis for the ranking
 ****************************************/
 {
   computeRatings(weightWomen, weightAI, weightSys, weightTheory, weightEffect, weightPubs);
   schools.selection_sort();
   cout<<endl;
   cout<<"Ranking of Grad School programs, given your preferences:"<<endl;
   for (int i = schools.size()-1; i>= 0; i--)
     {
       School x;
       schools.retrieve(i, x);
       cout<<x.name<<endl;
      
     }

 }

// I chose selection_sort() because the items in the list are big and slow-moving. Selection_sort is good to use with shorter lists
// becuase it uses fewer swaps and is O(n^2) which grows much faster with longer lists.


void GradSchools::rankSchoolsFactor (string factor)
/***************************************
 *pre:  a single string input that specifies which factor to use (e.g. "women", "AI", etc.), 
 *post: ranks the schools based on a single factor.
 ****************************************/
 {
     if(factor == "women"){
         rankSchools(1, 0,0,0,0,0);
     }
     if(factor == "AI"){
         rankSchools(0,1,0,0,0,0);
     }
      if(factor == "Sys"){
         rankSchools(0,0,1,0,0,0);
     }
       if(factor == "theory"){
         rankSchools(0,0,0,1,0,0);
     }
        if(factor == "effect"){
         rankSchools(0,0,0,0,1,0);
     }
         if(factor == "pubs"){
         rankSchools(0,0,0,0,0,1);
     }
 }


void GradSchools::printGradSchools()
/***************************************
 *pre: None
 *post: prints all of the information that is stored in the entire GradSchools object used to invoke this method
 ****************************************/
 {
     cout<<endl;
     for (int i = 0; i < schools.size()-1; i++)
     {
       School entry;
       schools.retrieve(i, entry);
       entry.printSchoolInfo();
       cout<<endl;
     }
 }
