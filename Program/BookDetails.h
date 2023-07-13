#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
class BookDetails
{
private:
    int S_No;
    string BookName;
    string AuthorName;
    bool approved;

public:
    void setBookDetails(string BookName, string AuthorName, int Serial_Number)
    {
        this->BookName = BookName;
        this->AuthorName = AuthorName;
        this->S_No = Serial_Number;
    }

    void insertBookDetails()
    {
        cout << "Inserting Book" << endl;
        cout << "Enter Book Name: " << endl;
        cin.ignore();
        getline(cin, BookName);
        cout << "Enter Author Name: " << endl;
        getline(cin, AuthorName);
    }

    int getSerialNumber()
    {
        return this->S_No;
    }

    string getBookName()
    {
        return this->BookName;
    }

    string getAuthorName()
    {
        return this->AuthorName;
    }

    void displayBookDetails();

    void ShowBookList(const std::vector<BookDetails> &books)
    {
        std::cout << "Book List:\n";
        for (const BookDetails &book : books)
        {
            std::cout << "Book Details" << std::endl;
            std::cout << "Book Name: " << getBookName() << std::endl;
            std::cout << "Author Name: " << getAuthorName() << std::endl;
            std::cout << std::endl;
        }
    }

    void set_approved(bool status)
    {
        approved = status;
    }

    bool isApproved() const
    {
        return approved;
    }
};

void BookDetails ::displayBookDetails()
{
    cout << "Book Details" << endl;
    cout << "Book Name: " << this->BookName << endl;
    cout << "Author Name: " << this->AuthorName << endl;
}
#endif
