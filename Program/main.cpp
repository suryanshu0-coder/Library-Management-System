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
     BookDetails requestedBook;
     vector<BookDetails> requestedBooks;
     vector<BookDetails> approvedBooks;
     vector<BookDetails> books;
     vector<BookDetails> pendingRequests;
     int i;

     /*
          // Populate some sample data for demonstration purposes
          pendingRequests.push_back(BookDetails("Book 1", "Author 1", 1));
          pendingRequests.push_back(BookDetails("Book 2", "Author 2", 2));
          pendingRequests.push_back(BookDetails("Book 3", "Author 3", 3));


     */


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
          cin.ignore();
          getline(cin, username);

          cout << "Enter your password:" << endl;
          getline(cin, password);

          // Checking whether username and password are correct or not
          if (username == "teacher" && password == "password")
          {
               cout << "Teacher Dashboard Login Success!" << endl;

               // Displaying the list of requested books that to be approved/rejected by the teacher.
               cout << "List of the pending requested books: " << endl;
               for (const auto &book : pendingRequests)
               {
                    cout << "Book Name: " << book.getBookName() << endl;
                    cout << "Author Name: " << book.getAuthorName() << endl;
                    cout << "Serial Number: " << book.getSerialNumber() << endl;
                    cout << "Approval Status: " << (book.isApproved() ? "Approved" : "Rejected") << endl;
                    cout << "----------------------------" << endl;
               }

               string line;

               ifstream inputThefile("../txt file/ChoiceFile.txt");

               if (!inputThefile.is_open())
               {
                    cerr << "Error opening file." << endl;
                    return 1;
               }

               ;
               while (getline(inputThefile, line))
               {
                    cout << line << endl;
               }

               inputThefile.close();

               cout << "Do you want to approve or reject the book? [Y/N] " << endl;

               char teacherChoice;
               cin >> teacherChoice;

               if (teacherChoice == 'Y' || teacherChoice == 'y')
               {
                    cout << "Enter the serial no of the book you want to approve/reject" << endl;
                    int serialNumber;
                    cin >> serialNumber;

                    bool found = false; // variable to find whether the book ia found or not.

                    for (auto &book : pendingRequests)
                    {
                         if (book.getSerialNumber() == serialNumber)
                         {
                              found = true;

                              // Set the book's approval/rejection status
                              cout << "Do you want to approve (A) or reject (R) this book? ";
                              char approvalChoice;
                              cin >> approvalChoice;

                              if (approvalChoice == 'A' || approvalChoice == 'a')
                              {
                                   book.set_approved(true);

                                   cout << "Book approved by the teacher." << endl;

                                   // Move the approved book from pendingRequests to books vector
                                   approvedBooks.push_back(book);
                                   // Write the approved book details to the file "approvedBooks.txt"
                                   ofstream approvedBookFile("../txt file/approvedBooks.txt");
                                   if (approvedBookFile.is_open())
                                   {
                                        approvedBookFile << "Book Name: " << book.getBookName() << endl;
                                        approvedBookFile << "Author Name: " << book.getAuthorName() << endl;
                                        approvedBookFile << "Serial Number: " << book.getSerialNumber() << endl;
                                        approvedBookFile << "----------------------------" << endl;
                                        approvedBookFile.close();
                                        cout << "Approved book written to file " << endl;
                                   }
                                   else
                                   {
                                        cout << "Unable to open the file." << endl;
                                   }
                              }
                              else if (approvalChoice == 'R' || approvalChoice == 'r')
                              {
                                   book.set_approved(false);
                                   cout << "Book rejected by the teacher." << endl;
                              }
                              else
                              {
                                   cout << "Invalid choice. Book status remains unchanged." << endl;
                              }

                              // Update the "requestedBooks.txt" file with the updated status
                              ofstream requestedBookFile("../txt file/requestedBooks.txt");
                              if (requestedBookFile.is_open())
                              {
                                   requestedBookFile << "Requested Books: " << endl;
                                   for (const auto &book : requestedBooks)
                                   {
                                        requestedBookFile << "Book Name: " << book.getBookName() << endl;
                                        requestedBookFile << "Author Name: " << book.getAuthorName() << endl;
                                        requestedBookFile << "Serial Number: " << book.getSerialNumber() << endl;
                                        requestedBookFile << "Status: " << (book.isApproved() ? "Approved" : "Requested") << endl;
                                        requestedBookFile << "----------------------------" << endl;
                                   }
                                   requestedBookFile.close();
                                   cout << "Requested books status updated in file." << endl;
                              }
                              else
                              {
                                   cout << "Unable to open the file." << endl;
                              }

                              break;
                         }
                         i++;
                    }

                    if (!found)
                    {
                         cout << "Book with serial number " << serialNumber << " not found." << endl;
                    }
               }
          }
          else
          {
               cout << "Teacher Dashboard Login Failure!" << endl;
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
          cout << "********************************" << endl;
          cout << "Welcome to the Library!!" << endl;
          cout << "Enter your choice:" << endl;
          cout << "Press '1' to Order a book." << endl;
          cout << "Press '2' to View Book Details " << endl;
          cout << "Press '3' to Cancel booking." << endl;
          cout << "Press '4' to Request a new book." << endl;
          cout << "Press '0' to Exit." << endl;

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
                    approvedBooks.push_back(requestedBook);

                    cout << "Book requested successfully." << endl;
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

          // Add the requested book to the vector shared between teacher and student.
          requestedBooks.push_back(requestedBook);
          cout << "Book requested successfully." << endl;
     }
     else
     {
          cout << "Invalid Dashboard." << endl;
     }

     return 0;
}
