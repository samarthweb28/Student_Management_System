Student Management System
A simple console program in C to manage student records. Data is saved in a file called data, so records are kept between runs.
Features
Add a student (roll number, name, marks)
Display all students
Search a student by roll number
Edit a student's name and marks
Automatic saving and loading from the data file
Requirements
A C compiler such as GCC
How to Compile and Run
gcc student.c -o student
./student
On Windows, run student.exe instead of ./student.
Menu
1. Add Student
2. Display Students
3. Search Student
4. Edit Student
5. Exit
Data File
Records are stored in a plain text file named data.
The file is created in the folder you run the program from, after the first student is added.
Each line holds one student: roll name marks
Example:
101 Rahul 85.50
102 Priya 92.00
Notes
Maximum of 100 students.
Names must be a single word (no spaces).
Roll numbers are not checked for duplicates.
