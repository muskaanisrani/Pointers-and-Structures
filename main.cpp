//
//  main.cpp
//  cecs 282 program 3 structs and pointers
//
//  Created by Muskaan Israni on 3/16/20.
//  Copyright © 2020 Muskaan Israni. All rights reserved.
//
#include "myDate.hpp" // X-code users change this to myDate.hpp
#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
struct Student {
private:
    char name[30];
    int studentID;
    char grade;
    myDate birthday;
    string homeTown;
    
    
public:
    void Set(char n[],int s,char g,myDate x,string h) {
        
        strcpy(name,n);
        studentID=s;
        grade=g;
        birthday=x;
        homeTown=h;
        
    }
    
    void display(){

        cout<<left;

        cout<<setw(20)<<name<<setw(10)<<studentID<<setw(10)<<grade<<setw(20);
        cout<<birthday.toString();
        cout<<setw(15)<<homeTown;
        
    }
    
    void setname(string n) {
        
    }
    
    
    string getname(){
        return name;
    }
    int getstudentID(){
        return studentID;
    }
    void setstudentID(int a){
        studentID=a;
    }
    myDate getbirthday(){
        return birthday;
    }
    string gethomeTown(){
        return homeTown;
    }
    void sethomeTown(string b){
        homeTown=b;
    }
    char getgrade(){
        return grade;
    }
    void setgrade(char a){
        grade=a;
    }

};


int Greg2Julian2(int month,int day,int year) {
    
    int juliandate=day-32075+1461*(year+4800+(month-14)/12)/4+367*(month-2-(month-14)/12*12)/12-3*((year+4900+(month-14)/12)/100)/4;
    return juliandate;
}



void sortbyStudentID(Student *arr[],int n) {
    
    
    
    for (int j=0;j<n;j++ ) {
        for (int i=0;i<n-1;i++) {
            
            
            if (arr[i]->getstudentID()>arr[i+1]->getstudentID()) {
                Student *temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                
            }
            
        }
    }
    
}


void sortbyGrade(Student *arr[],int n) {
    
    
    
    for (int j=0;j<n;j++ ) {
        for (int i=0;i<n-1;i++) {
            
            
            if ((int)arr[i]->getgrade()>(int)arr[i+1]->getgrade()) {
                Student *temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                
            }
            
        }
    }
    
}


void sortbyname(Student *arr[],int n) {
    for (int j=0;j<n;j++) {
        for (int i=0;i<n-1;i++) {
            int x=arr[i]->getname().compare(arr[i+1]->getname());
            if (x>0) {
                Student *temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
    }
    
}
void sortbybirthday(Student *arr[],int n){
    for (int j=0;j<n;j++) {
        
        for (int i=0;i<n-1;i++) {
            int m=arr[i]->getbirthday().getMonth();
            int d=arr[i]->getbirthday().getDay();
            int y=arr[i]->getbirthday().getYear();
            int m2=arr[i+1]->getbirthday().getMonth();
            int d2=arr[i+1]->getbirthday().getDay();
            int y2=arr[i+1]->getbirthday().getYear();
            int c1=Greg2Julian2(m,d,y);
            int c2=Greg2Julian2(m2, d2, y2);
            if (c1>c2) {
                Student *temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                
            }
        }
    }
    
}



void sortbyhometown(Student *arr[],int n) {
    for (int j=0;j<n;j++) {
        for (int i=0;i<n-1;i++) {
            int x=arr[i]->gethomeTown().compare(arr[i+1]->gethomeTown());
            if (x>0) {
                Student *temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                
                
            }
            
        }
        
    }
    
}

myDate randomDate(myDate S,myDate F) {
    
    int range=S.daysBetween(F);
    int x=rand()%range;
    myDate d=S;
    S.increaseDate(x);
    return S;
}


void display(Student *a[],int d) {
    cout<<left;
    cout<<setw(20)<<"Name";
    cout<<setw(10)<<"StudentID";
    cout<<setw(10)<<"Grade";
    cout<<setw(20)<<"birthday";
    cout<<setw(15)<<"hometown";
    cout<<"\n";

    for (int i=0;i<10;i++) {
        a[i]->display();
        cout<<"\n";
        
    }

}


void populate (Student *a[],int n) {
    
    string names[10]={"Tom Thumb","Fred Flinstone","Sponge bob","Muskan Israni","Elon Musk","Riddhima Israni","Claudia Sulevski","Kajal Israni","Keira Wong","Callie Lauren"};
    
    int studentIDs[10]={1002,1995,2987,1234,9999,1737,1456,2345,6767,5643};
    
    char grades[10]={'C','D','B','A','B','C','E','F','A','B'};
    
    string hometowns[10]={"Small Ville","Bedrock","Bikini bottom","Mumbai","Boston","Delhi","Los Angeles","Mumbai","New York","Florida"};
    
    myDate randomdate2;
    for (int i=0;i<n;i++) {
        a[i]=new Student;
        
        char temp[30];
        strcpy(temp, names[i].c_str());
        randomdate2=randomDate(myDate (1,1,1999),myDate(12,21,2004));
        a[i]->Set(temp,studentIDs[i],grades[i],randomdate2,hometowns[i]);
        
    }
    
}


int main(int argc, const char * argv[]) {

    
    string homeTown2="";
    Student *arr [10];


    
    populate(arr,10);
    
    int choice=0;
    while (choice!=6) {
    cout<<"1) display list sorted by name \n";
    cout<<"2) display list sorted by student ID \n";
    cout<<"3) display list sorted by grade \n";
    cout<<"4) display list sorted by birthday \n";
    cout<<"5) display list sorted by hometown \n";
    cout<<"6) exit";

    cin>>choice;
    
    
    if (choice==1) {
        cout<<"sorted by name \n";
        sortbyname(arr,10);
        display(arr, 10);
    } else {
        if (choice==2) {
            cout<<"sorted by studentID \n";
            sortbyStudentID(arr,10);
            display(arr, 10);
        } else {
            if (choice==3) {
                cout<<"sorted by grade \n";
                sortbyGrade(arr,10);
                display(arr, 10);
            } else {
                if (choice==4) {
                    cout<<"sorted by birthday \n";
                    sortbybirthday(arr,10);
                    display(arr, 10);
                } else {
                    if (choice==5) {
                        cout<<"sorted by hometown \n";
                        sortbyhometown(arr,10);
                        display(arr, 10);
                    } else {
                        cout<<"exit";
                    }
                }
            }
        }
    
        
        
        
    }
        
      
        
        
        
        
        
        

        }
    }


    



        


    
    




    

