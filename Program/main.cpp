#include <iostream>
#include <iomanip>
#include "BookDetails.h"
#include "Admin.h"
#include "ShowBookList.h"
#include "StudehtInput.h"
#include "StudentBookChoose.h"
#include <fstream>
#include <string>
// sing namespace std;
int main()
{
     BookDetails requestedBook;

     // making dashboard for Teacher and Student
     // for teacher

     char userChoices;
     string username, password;
     cout << "Are you teacher or a student?" << endl;
     cout << "Enter 'T' for teacher and and 'S' for student" << endl;
     cin >> userChoices;

     if (userChoices == 'T' || userChoices == 't')
     {
          cout << "Teacher Dashboard Login" << endl;

          // Taking username and password as input for teacher
          cout << "Enter your username:" << endl;
          cin >> username;

          cout << "Enter your password:" << endl;
          cin >> password;

          // Checking whether username and password are correct or not
          if (username == "teacher" && password == "password")
          {
               cout << "Teacher Dashboard Login Success!" << endl;

               // Ask the teacher for approval
               cout << "Teacher , do  you want to approve this booking? [Y/N]" << endl;
               char teacherCho;
               cin >> teacherCho;

               if (teacherCho == 'Y' || teacherCho == 'y')
               {
                    requestedBook.set_approved(true);
                    cout << "Book approved by the teacher" << endl;
               }

               else
               {
                    requestedBook.set_approved(false);
                    cout << "Book not approved by the teacher." << endl;
               }
          }
          else
          {
               cout << "Teacher Dashboard Login Failure!" << endl;
          }
     }

     else if (userChoices == 'S' || userChoices == 's')
     {
          // Book List printing
          int bookNumber, S_No, S_NoCount = 1;
          string authorName, bookName;
          cout << "********************************" << endl;
          cout << "Welcome to the Library!!" << endl;
          cout << "Enter your choice:" << endl;
          cout << "Press '1' to Order a book." << endl;
          cout << "Press '2' to View Book Details " << endl;
          cout << "Press '3' to Cancel booking." << endl;
          cout << "Press '4' to Request a new book." << endl;
          cout << "Press '0' to Exit." << endl;

          vector<BookDetails> books;

          int choice;
          do
          {
               cout << "Enter your choice:" << endl;
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

               case 4:
               {
                    string newBookName, newAuthorName;
                    cout << "Enter the name of the book you want to request:" << endl;
                    cin.ignore(); // Ignore any previous newline character in the input buffer
                    getline(cin, newBookName);

                    cout << "Enter the name of the author of the book:" << endl;
                    getline(cin, newAuthorName);

                    // Create a new BookDetails object for the requested book
                    requestedBook.setBookDetails(newBookName, newAuthorName, 1); // 1 as serial number for requested books
                    books.push_back(requestedBook);

                    cout << "Book requested successfully." << endl;
                    break;
               }

               default:
                    cout << "Invalid choice. " << endl
                         << "Please select a valid option." << endl;
                    break;
               }

          } while (choice == 1 && choice != 0);

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
          int age, rollNo;
          student.setStudentDetails(name, rollNo, age);
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
