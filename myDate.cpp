//
//  myDate.cpp
//  CECS 282 program 3
//
//  Created by Muskaan Israni on 2/29/20.
//  Copyright © 2020 Muskaan Israni. All rights reserved.
//
#include "myDate.hpp"
#include <iostream>
#include <string.h>
using namespace std;

int Greg2Julian(int month,int day,int year) {
    
    int juliandate=day-32075+1461*(year+4800+(month-14)/12)/4+367*(month-2-(month-14)/12*12)/12-3*((year+4900+(month-14)/12)/100)/4;
    return juliandate;
}
void Julian2Greg(int JD,int &month, int &day, int &year) {
    int l=JD+68569;
    int n=4*l/146097;
    l=l-(146097*n+3)/4;
    int i=4000*(l+1)/1461001;
    l=l-1461*i/4+31;
    int j=80*l/2447;
    int k=l-2447*j/80;
    l=j/11;
    j=j+2-12*l;
    i=100*(n-49)+i+l;
    
    year=i;
    month=j;
    day=k;
    
}

myDate::myDate(){
    M=5;
    D=11;
    Y=1959;
}

myDate::myDate(int userm,int userd,int usery) {
    M=userm;
    D=userd;
    Y=usery;
    if (M>12 || D>31) {
        M=5;
        D=11;
        Y=1959;
    }
}



string myDate::toString(){
    string answer;
    switch (M) {
            
        case 1: answer="January ";
            break;
        case 2: answer="February ";
            break;
        case 3: answer="March ";
            break;
        case 4: answer="April ";
            break;
        case 5: answer="May ";
            break;
        case 6: answer="June ";
            break;
        case 7: answer="July ";
            break;
        case 8: answer="August ";
            break;
        case 9: answer="September ";
            break;
        case 10: answer="October ";
            break;
        case 11: answer="November ";
            break;
        case 12: answer="December ";
            break;
        default: answer="error";
            
    }
    
    string answer2= to_string(D);
    string answer3=to_string(Y);
    string temp=" ,";
    answer2.append(temp);
    answer2.append(answer3);
    return answer.append(answer2);


}



void myDate::display () {
    switch (M) {
            
        case 1: cout<<"January "<<D<<" "<<Y;
            break;
        case 2: cout<<"February "<<D<<" "<<Y;
            break;
        case 3: cout<<"March "<<D<<" "<<Y;
            break;
        case 4: cout<<"April "<<D<<" "<<Y;
            break;
        case 5: cout<<"May "<<D<<" "<<Y;
            break;
        case 6: cout<<"June "<<D<<" "<<Y;
            break;
        case 7: cout<<"July "<<D<<" "<<Y;
            break;
        case 8: cout<<"August "<<D<<" "<<Y;
            break;
        case 9: cout<<"September "<<D<<" "<<Y;
            break;
        case 10: cout<<"October "<<D<<" "<<Y;
            break;
        case 11: cout<<"November "<<D<<" "<<Y;
            break;
        case 12: cout<<"December "<<D<<" "<<Y;
            break;
        default: cout<<"error";
            
    }
}


void myDate::increaseDate(int n) {
    int juliandatetoincrease=Greg2Julian(M, D, Y);
    
    juliandatetoincrease=juliandatetoincrease+n;
    Julian2Greg(juliandatetoincrease, M, D, Y);
}

void myDate::decreaseDate(int d) {
    int juliandatetodecrease=Greg2Julian(M, D, Y);
    juliandatetodecrease=juliandatetodecrease-d;
    Julian2Greg(juliandatetodecrease, M, D, Y);
}

int myDate::daysBetween(myDate user) {
    int myjuliandate=Greg2Julian(M, D, Y);
    int usermonth=user.M;
    int useryear=user.Y;
    int userday=user.D;
    int userjuliandate=Greg2Julian(usermonth, userday, useryear);
    int difference=userjuliandate-myjuliandate;
    return difference;
    
    
}

int myDate::getMonth() {
    return M;
}
int myDate::getDay(){
    return D;
}

int myDate::getYear() {
    return Y;
}



int myDate::dayOfYear(){
    //if leap year returns 1 if not returns 0
    int leap=0;
    if (((Y % 4 == 0) && (Y % 100!= 0)) || (Y%400 == 0)) {
        leap=1;
    } else {
        leap=0;
    }
    
    
    switch (M) {
        case 1: return D;
            break;
        case 2: return 31+D;
            break;
        case 3: if (leap==1) {
            return 31+29+D;
        } else {
            return 31+28+D;
        }
            break;
        case 4: if (leap==1) {
            return 31+29+31+D;
        } else {
            return 31+28+31+D;
        }
            
            break;
        case 5: if (leap==1) {
            return 31+29+31+30+D;
        } else {
            return 31+29+31+30+D;
        }
            break;
        case 6: if (leap==1) {
            return 31+29+31+30+31+D;
        } else {
            return 31+28+31+30+31+D;
        }
            break;
        case 7: if (leap==1) {
            return 31+29+31+30+31+30+D;
        } else {
            return 31+28+31+30+31+30+D;
        }
            break;
        case 8: if (leap==1) {
            return  31+29+31+30+31+30+31+D;
        } else {
            return 31+28+31+30+31+30+31+D;
        }
            break;
        case 9: if (leap==1) {
            return 31+29+31+30+31+30+31+31+D;
        } else {
            return 31+28+31+30+31+30+31+31+D;
        }
            break;
        case 10: if (leap==1) {
            return 31+29+31+30+31+30+31+31+30+D;
        } else {
            return 31+28+31+30+31+30+31+31+30+D;
        }
            break;
        case 11: if (leap==1) {
            return 31+29+31+30+31+30+31+31+30+31;
        } else {
            return 31+28+31+30+31+30+31+31+30+31;
        }
            break;
        case 12:
            if (leap==1) {
                return 31+29+31+30+31+30+31+31+30+31+30+D;
            } else {
                return 31+28+31+30+31+30+31+31+30+31+30+D;
            }
            break;
        default: cout<<"error";
            
    }
    
    return 0;
}

string myDate::dayName(){
    int julianforday= Greg2Julian(M, D, Y);
    int temp=julianforday%7;
    string day;
    if (temp==1) {
        day="Tuesday";
    } else {
        if (temp==2){
            day="Wednesday";
        } else {
            if (temp==3) {
                day="Thursday";
            } else {
                if (temp==4) {
                    day="Friday";
                } else {
                    if (temp==5) {
                        day="Saturday";
                    } else {
                        if (temp==6 ) {
                            day="Sunday";
                        } else {
                            if (temp==0) {
                                day="Monday";
                            }
                        }
                    }
                }
            }
        }
    }
    return day;
}
