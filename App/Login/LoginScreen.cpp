#include <string>
#include <iostream>
#include <fstream>
#include "LoginScreen.h"
using namespace std;

bool Check(std::string &user, std::string &password){
    ifstream ifs("Infomation/Account.dat");
    string ID, pass;
    while (ifs>>ID){
        ifs>>pass;
        if (ID==user && pass==password){
            ifs.close();
            return true;
        }
    }
    ifs.close();
    return false;
}

void LoginScreen(std::string &user, std::string &password){
    cout << "-------------------------------------------------------------\n";
    cout << "|             Course Management System                      |\n";
    cout << "-------------------------------------------------------------\n";
    cin.ignore();
    system("cls");
    while (1){
        cout << "Username: ";
        std::getline(std::cin, user);
        cout << "Password: ";
        std::getline(std::cin,password);
        if (Check(user,password)){
            cout << "Login success!\n";
            break;
        }
        else{
            cout << "Wrong password!\n";
        }
    }
}
