#ifndef FINE_H
#define FINE_H

#include <iostream>
#include <vector>
using namespace std;
class Fine
{
private:
    int finePerDay; // Fine amount per day for late returns
    vector<string> lateBooks; // Store the names of books returned late
    int totalFine; // Total fine amount accumulated

public:
    Fine(int finePerDay) : finePerDay(finePerDay), totalFine(0) {}

    // Record late book returns
    void addLateBook(const string& bookName)
    {
        lateBooks.push_back(bookName);
    }

    // Calculate and display the fine for a user
    void calculateFine(const std::string& username)
    {
        if (lateBooks.empty())
        {
            cout << username << ", you have no fines." << endl;
            return;
        }

        int numLateBooks = lateBooks.size();
        int fineAmount = numLateBooks * finePerDay;
        totalFine += fineAmount;

        cout << "Dear " << username << ", you have " << numLateBooks << " late book(s):" << endl;
        for (const string& book : lateBooks)
        {
            cout << "- " << book << endl;
        }

        cout << "Total fine amount: $" << fineAmount << endl;
    }

    // Get the total fine accumulated
    int getTotalFine()
    {
        return totalFine;
    }

    // Clear late book list and reset total fine
    void clearFines()
    {
        lateBooks.clear();
        totalFine = 0;
    }
};

#endif
