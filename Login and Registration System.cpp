#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

void header(string title) {
    system("cls");
    cout << "===================================\n";
    cout << "     " << title << "\n";
    cout << "===================================\n\n";
    Sleep(300);
}

void registerUser() {
    header("USER REGISTRATION");
    string username, password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "\nRegistration successful!\n";
    system("pause");
}

void loginUser() {
    header("USER LOGIN");
    string username, password, u, p;
    bool found = false;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    ifstream file("users.txt");
    while (file >> u >> p) {
        if (u == username && p == password) {
            found = true;
            break;
        }
    }
    file.close();

    if (found)
        cout << "\nLogin successful!\n";
    else
        cout << "\nInvalid credentials!\n";

    system("pause");
}

int main() {
    int choice;

    do {
        header("LOGIN / REGISTRATION SYSTEM");
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registerUser(); break;
            case 2: loginUser(); break;
            case 3: cout << "Goodbye!\n"; Sleep(500); break;
            default: cout << "Invalid option!\n"; Sleep(800);
        }
    } while (choice != 3);

    return 0;
}

