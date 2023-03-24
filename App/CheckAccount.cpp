#include "CheckAccount.h"
#include "LoginScreen.h"
#include "Student.h"
#include <bits/stdc++.h>
using namespace std;

void Checking(sf::RenderWindow &window, bool &isLogin, int &id, bool &Stop){
    string User;
    string Password;
    MenuFunc(window,User,Password,Stop);
    long long x = -1;
    if (User.size()) x = stoi(User);
    ifstream ifs("data.dat");
    string ID, Pass;
    while (ifs >> ID){
        ifs >> Pass;
        if (ID == User && Pass == Password) id = x, isLogin = true;
    }
    ifs.close();
}
