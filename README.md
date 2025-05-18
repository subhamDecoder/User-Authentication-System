# Console-Based Login System in C++

A simple command-line Login System implemented in C++ that allows users to **Sign Up**, **Login**, and **Recover Forgotten Passwords** using a local file (`loginData.txt`) for storage.

---

## Features

- User Sign-Up with username, email, and password
- User Login authentication
- Password recovery by verifying username and email
- Data persistence using a text file
- Simple and intuitive console interface

---

## Technologies Used

- **C++** (Standard Library)
- File handling with `fstream`
- String manipulation

---

## How to Use

### 1. Compile the code

```bash
g++ -o login_system login_system.cpp
Replace login_system.cpp with your filename.

2. Run the program
bash
./login_system
3. Follow the on-screen menu
Press 1 to Login

Press 2 to Sign Up

Press 3 to Recover Forgotten Password

Press 4 to Exit

Program Structure
login_system.cpp — main source file containing the entire implementation.

loginData.txt — text file where user credentials are stored securely in this format:

markdown
username*email*password
Important Notes
Passwords are stored in plain text in loginData.txt. For production systems, consider encrypting passwords.

The program uses simple file-based storage, suitable only for learning or very basic use cases.

Ensure the program has write permission in the directory to create/read loginData.txt.

Example Usage
mathematica
1- Login
2- Sign-Up
3- Forgot Password
4- Exit
Enter Your Choice: 2

Enter Your User Name: johndoe
Enter Your Email Address: john@example.com
Enter Your Password: secret123
Account Created Successfully!
License
This project is licensed under the MIT License.
