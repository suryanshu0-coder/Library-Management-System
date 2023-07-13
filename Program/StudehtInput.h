#ifndef STUDENTINPUT_H
#define STUDENTINPUT_H
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
class StudentDetailsInput{
         private:
         string name;
         int roll_no;
         int age;

         public:
         void setStudentDetails(string n ,int r, int a){
                  name=n;
                  roll_no=r;
                  age=a;
         }

         void inputStudentFDetails(){
                  cout<<"Enter your name: "<<endl;
                  cin >> name;

                  cout<<"Enter your roll_no: "<<endl;
                  cin>> roll_no;

                  cout<<"Enter your age: "<<endl;
                  cin>> age;
         }

         string getStudentName(){
                  return name;
         }

         int getStudentRoll_no(){
                  return roll_no;
         }

         int getStudentAge(){
                  return age;
         }

         void getStudentDetails(){
                  getStudentName();
                  getStudentRoll_no();
                  getStudentAge();
         }
  
};

#endif