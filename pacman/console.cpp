#include "console.h"
#include <iostream>

using namespace std;

string Console::askForServerIp() {
    string str;

        cout << "Enter string for testing : ";
        cin  >> str;
        cout << "\nString is : " << str << endl;


    string ip;
    cout << "Welcome to Pacman!" << endl;
    cout << "Please provide the server IP:" << endl;
    cin >> ip;
    cout << "Thank you.";

    return ip;
}
