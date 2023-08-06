#include <iostream>
#include <iomanip>
#include "BookDetails.h"
#include "ShowBookList.h"
#include "StudentInput.h"
#include "StudentBookChoose.h"
#include "userLogin.h"
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main()
{
     vector<BookDetails> books;
     int i;

     // making dashboard for Teacher and Student
     // for teacher
     char userChoices;
     string username, password;
     cout << "Are you teacher or a student?" << endl;
     cout << "Enter 'T' for teacher and and 'S' for student" << endl;
     cin >> userChoices;

     if (userChoices == 'T' || userChoices == 't')
     {
          cout << "\033[1;32m"; // Set text color to bright green
          cout << "Teacher Dashboard Login...." << endl;
          cout << "\033[0m"; // Reset text color to default

          // Taking username and password as input for teacher
          cout << "Enter your username:" << endl;
          cin.ignore();
          getline(cin, username);

          cout << "Enter your password:" << endl;
          getline(cin, password);

          // Checking whether username and password are correct or not
          if (username == "teacher" && password == "password")
          {
               cout << "\033[1;32m"; // Set text color to bright green
               cout << "Teacher Dashboard Login Success!...." << endl;
               cout << "\033[0m"; // Reset text color to default

               // Displaying the list of requested books that to be approved/rejected by the teacher.
               cout << "List of the pending requested books: " << endl;

               string line;
               ifstream inputThefile("../txt file/BookDetails.txt");

               if (!inputThefile.is_open())
               {
                    cerr << "Error opening file." << endl;
                    return 1;
               }

               
               while (getline(inputThefile, line))
               {
                    cout << line << endl;
               }

               inputThefile.close();
          }
          else
          {
               cout << "\033[1;31m"; // Set text color to bright red
               cout << "Teacher Dashboard Login \033[0;31mFailure!\033[0m" << endl;
               cout << "\033[0m"; // Reset text color to default
          }
     }

     else if (userChoices == 'S' || userChoices == 's')
     {

          UserLoginSection u1;
          u1.CreateAccount();
          u1.LoginAccount();

          // Book List printing
          int bookNumber, S_No, S_NoCount = 1;
          string authorName, bookName;

          cout << "\033[1;33m"; // Set text color to bright yellow
          cout << "*********************************************" << endl;
          cout << "*         Welcome to the Library!!          *" << endl;
          cout << "*********************************************" << endl;
          cout << "\033[0m"; // Reset text color to default

          cout << "\033[1;32m"; // Set text color to bright green
          cout << "Enter your choice:" << endl;
          cout << "Press '1' to \033[4;32mOrder a book.\033[0m" << endl;       // Underline "Order a book"
          cout << "Press '2' to \033[4;32mView Book Details.\033[0m" << endl;  // Underline "View Book Details"
          cout << "Press '3' to \033[4;32mCancel booking.\033[0m" << endl;     // Underline "Cancel booking"
          cout << "Press '4' to \033[4;32mRequest a new book.\033[0m" << endl; // Underline "Request a new book"
          cout << "\033[1;31m";                                                // Set text color to bright red
          cout << "Press '0' to Exit." << endl;
          cout << "\033[0m"; // Reset text color to default

          int choice;
          do
          {
               cout << "\033[1;31m"; // Set text color to dark red
               cout << "Enter your choice:" << endl;
               cout << "\033[0m";
               cin >> choice;
               switch (choice)
               {
               case 1:
               {
                    BookDetails addNewBook;
                    addNewBook.insertBookDetails();
                    addNewBook.setBookDetails(addNewBook.getBookName(), addNewBook.getAuthorName(), S_NoCount);
                    books.push_back(addNewBook);
                    addNewBook.getSerialNumber();
                    S_NoCount++;
                    break;
               }

               case 2:
               {
                    ShowBookList();
                    break;
               }

               case 3:
               {
                    // Display the list of ordered books
                    cout << "List of Ordered Books:" << endl;
                    for (int i = 0; i < books.size(); i++)
                    {
                         cout << i + 1 << ". " << books[i].getBookName() << endl;
                    }

                    // Ask the student to select a book to cancel
                    cout << "Enter the number of the book you want to cancel:" << endl;
                    int cancelChoice;
                    cin >> cancelChoice;

                    // Check if the selected book is within a valid range
                    if (cancelChoice >= 1 && cancelChoice <= books.size())
                    {
                         // Remove the selected book from the vector
                         books.erase(books.begin() + cancelChoice - 1);
                         cout << "Book canceled successfully." << endl;
                    }
                    else
                    {
                         cout << "Invalid book selection." << endl;
                    }
                    break;
               }

               default:
                    cout << "Invalid choice. " << endl
                         << "Please select a valid option." << endl;
                    break;
               }

          } while (choice != 0);

          if (!books.empty())
          {
               ofstream BookFile("../txt file/BookDetails.txt");
               if (BookFile.is_open())
               {
                    BookFile << left << setw(10) << "S.No" << setw(20) << "Book Name" << setw(20) << "Author Name " << endl;
                    for (int i = 0; i < books.size(); i++)
                    {
                         BookDetails book = books[i];
                         BookFile << left << setw(10) << book.getSerialNumber() << setw(20) << book.getBookName() << setw(20) << book.getAuthorName() << endl;
                    }
                    BookFile.close();
                    cout << "Book details written to file." << endl;
               }

               else
               {
                    cout << "Unable to open the file." << endl;
               }
          }
          else
          {
               cout << "No book added." << endl;
          }
          // Student Input
          StudentDetailsInput student;
          string name;
          int rollNo;
          student.setStudentDetails(name, rollNo);
          student.getStudentDetails();

          // Book Choosen By Student Writing to file
          displayBookChoice BookChoosenByStudent;
          cout << endl;
          BookChoosenByStudent.displayChoice();
     }
     else
     {
          cout << "Invalid Dashboard." << endl;
     }

     return 0;
}
