#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class temp {
    string userName, Email, password;
    string searchName, searchPass, searchEmail;
    fstream file;

public:
    void login();
    void signUP();
    void forgot();
    void removeUser();
} obj;

int main() {
    char choice;

    while (true) {
        cout << "\n1- Login";
        cout << "\n2- Sign-Up";
        cout << "\n3- Forgot Password";
        cout << "\n4- Remove User Data";
        cout << "\n5- Exit";
        cout << "\nEnter Your Choice: ";
        cin >> choice;

        cin.ignore();  // To handle the newline left in the buffer after cin
        switch (choice) {
        case '1':
            obj.login();
            break;
        case '2':
            obj.signUP();
            break;
        case '3':
            obj.forgot();
            break;
        case '4':
            obj.removeUser();
            break;
        case '5':
            return 0;
        default:
            cout << "Invalid Selection...!" << endl;
        }
    }
}

void temp::signUP() {
    cout << "\nEnter Your User Name: ";
    getline(cin, userName);
    cout << "Enter Your Email Address: ";
    getline(cin, Email);
    cout << "Enter Your Password: ";
    getline(cin, password);

    file.open("loginData.txt", ios::out | ios::app);
    if (file.is_open()) {
        file << userName << "*" << Email << "*" << password << endl;
        file.close();
        cout << "Account Created Successfully!" << endl;
    } else {
        cout << "Unable to open file!" << endl;
    }
}

void temp::login() {
    cout << "----------LOGIN---------" << endl;
    cout << "Enter Your User Name: ";
    getline(cin, searchName);
    cout << "Enter Your Password: ";
    getline(cin, searchPass);

    bool accountFound = false;

    file.open("loginData.txt", ios::in);
    if (file.is_open()) {
        while (getline(file, userName, '*') && getline(file, Email, '*') && getline(file, password)) {
            if (userName == searchName && password == searchPass) {
                cout << "\nAccount Login Successful!" << endl;
                cout << "Username: " << userName << endl;
                cout << "Email: " << Email << endl;
                accountFound = true;
                break;
            }
        }

        if (!accountFound) {
            cout << "Invalid Username or Password!" << endl;
        }

        file.close();
    } else {
        cout << "Unable to open file!" << endl;
    }
}

void temp::forgot() {
    cout << "\nEnter Your UserName: ";
    getline(cin, searchName);
    cout << "Enter Your Email Address: ";
    getline(cin, searchEmail);

    bool accountFound = false;

    file.open("loginData.txt", ios::in);
    if (file.is_open()) {
        while (getline(file, userName, '*') && getline(file, Email, '*') && getline(file, password)) {
            if (userName == searchName && Email == searchEmail) {
                cout << "\nAccount Found!" << endl;
                cout << "Your Password: " << password << endl;
                accountFound = true;
                break;
            }
        }

        if (!accountFound) {
            cout << "\nNo account found with the provided details!" << endl;
        }

        file.close();
    } else {
        cout << "Unable to open file!" << endl;
    }
}

void temp::removeUser() {
    cout << "\nEnter Your User Name: ";
    getline(cin, searchName);
    cout << "Enter Your Email Address: ";
    getline(cin, searchEmail);

    bool accountFound = false;
    string tempFileName = "tempData.txt";
    fstream tempFile;

    file.open("loginData.txt", ios::in);
    tempFile.open(tempFileName, ios::out | ios::app);

    if (file.is_open() && tempFile.is_open()) {
        while (getline(file, userName, '*') && getline(file, Email, '*') && getline(file, password)) {
            if (userName == searchName && Email == searchEmail) {
                cout << "\nAccount Found and Deleted!" << endl;
                accountFound = true;
            } else {
                tempFile << userName << "*" << Email << "*" << password << endl;  // Write other users to temp file
            }
        }

        if (!accountFound) {
            cout << "\nNo account found with the provided details!" << endl;
        }

        file.close();
        tempFile.close();

        // Remove the old file and rename the temp file
        remove("loginData.txt");
        rename(tempFileName.c_str(), "loginData.txt");
    } else {
        cout << "Unable to open file!" << endl;
    }
}
