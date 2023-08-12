Library Management System - README
This repository contains a simple library management system implemented in C++. It serves as a demonstration of object-oriented programming (OOP) concepts. The system allows both teachers and students to interact with the library's features.

Features
Teacher Dashboard
Teachers can log in to the system using predefined credentials and perform the following actions:

View pending book requests from students.
Student Dashboard
Students can:

Create an account using a username and password.
Log in using their credentials.
Order books from a list of available books.
View a list of ordered books.
Cancel a book order.
Check for fines (work-in-progress feature).
Files
main.cpp: The main program file that orchestrates interactions between teachers and students.
BookDetails.h: Contains the BookDetails class, which stores book information.
TeacherDashboard.h: Defines the TeacherDashboard class, allowing teachers to interact with pending book requests.
StudentInput.h: Contains the StudentDetailsInput class, managing student information input.
StudentBookChoose.h: Defines the displayBookChoice class, handling student book choices.
userLogin.h: Contains the UserLoginSection class, managing student account creation and login.
fine.h: Contains the Fine class for calculating fines (work-in-progress).
Additional Files
ShowBookList.h: Provides the ShowBookList function to display a list of ordered books.
ChoiceFile.txt: Stores the student's chosen books.
BookDetails.txt: Contains details of available books.
StudentCredentials.txt: Stores student account credentials.
Usage
Compile the program using a C++ compiler.
Run the executable.
Choose between "Teacher" and "Student" modes.
For teacher mode, enter the predefined credentials to view pending book requests.
For student mode, you can create an account, log in, order/view/cancel books, and check fines.
Notes
This project is meant for educational purposes, demonstrating OOP concepts.
The system's functionality and UI are basic and may require additional development.
Contributions, improvements, and adaptations are encouraged.
Please ensure you have the necessary files and directory structure in place.
