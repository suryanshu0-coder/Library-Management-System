#ifndef USERLOGIN_H
#define USERLOGIN_H
#include <iostream>
#include <string>
using namespace std;

class UserLoginSection
{
private:
         string username;
         string password;
         string inputUsername, inputPassword;
         bool loginSuccessful;

public:
         string getUsername()
         {
                  return this->username;
         }
         string getPassword()
         {
                  return this->password;
         }

         void CreateAccount()
         {
                  cout << "Create the new username: " << endl;
                  cin.ignore();
                  getline(cin, username);

                  cout << "Create the new password: " << endl;
                  getline(cin, password);
         }

         void LoginAccount()
         {

                  cout << "Enter the username: " << endl;
                  getline(cin, inputUsername);

                  cout << "Enter the password: " << endl;
                  getline(cin, inputPassword);

                  if (this->username == inputUsername && this->password == inputPassword)
                  {
                           cout << "Login Success!" << endl;
                  }
                  else
                  {
                           cout << "Login Failed!" << endl;
                  }
         }

         bool isLoginSuccessful()
         {
                  return loginSuccessful;
         }
};
#endif