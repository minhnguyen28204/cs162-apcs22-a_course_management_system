#include <string>
#include <iostream>
#include <fstream>
#include "LoginScreen.h"
using namespace std;

bool Check(std::string &user, std::string &password){
    ifstream ifs("Information/Account.dat");
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
void ToInt(int &ID, std::string user){
    for(int i=0; i<user.size(); i++){
        ID = ID*10 + (user[i]-'0');
    }
}

void LoginScreen(std::string &user, std::string &password){
    cout << "-------------------------------------------------------------\n";
    cout << "|             Course Management System                      |\n";
    cout << "-------------------------------------------------------------\n";
    char c;
    while ((c=cin.get())!='\n');
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
            char c;
            while ((c=cin.get())!='\n');
        }
        system("cls");
    }
}
