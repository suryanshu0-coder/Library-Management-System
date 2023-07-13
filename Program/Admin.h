#ifndef ADMIN_H
#define ADMIN_H
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
class Admin{
         private:
         bool approved;

         public:
         friend void set_approved();
         friend bool isApproved();
          
};

#endif