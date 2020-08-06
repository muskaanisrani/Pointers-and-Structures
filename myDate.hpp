

//Muskan Israni
//017537908
//CECS 282 Prog 3
//3rd march 2020
//  myDate.hpp
//  CECS 282 program 3
//
//  Created by Muskaan Israni on 2/29/20.
//  Copyright © 2020 Muskaan Israni. All rights reserved.
//

#include <iostream>
using namespace std;
#ifndef myDate_hpp
#define myDate_hpp

#include <stdio.h>



class myDate {
    
private:
    int M;
    int D;
    int Y;
    
public:
    
    myDate();
    myDate(int userm,int userd,int usery);
    void display ();
    void increaseDate(int n);
    void decreaseDate(int d);
    int daysBetween(myDate user);
    int getMonth();
    int getDay();
    int getYear();
    int dayOfYear();
    string dayName();
    //myDate randomDate(myDate S,myDate f);
    string toString();
    
    
    
    
    
    
    
    
    
};

//int Greg2Julian(int month,int day,int year);
#endif /* myDate_hpp */
