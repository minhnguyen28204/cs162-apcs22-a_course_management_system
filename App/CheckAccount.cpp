#include "CheckAccount.h"
#include "LoginScreen.h"
#include "Student.h"
#include <bits/stdc++.h>
using namespace std;

void Checking(sf::RenderWindow &window, bool &isLogin, Student &who, bool &Stop){
    string User;
    string Password;
    MenuFunc(window,User,Password,Stop);
    long long x = -1;
    if (User.size()) x = stoi(User);
    ifstream ifs("data.dat");
    int ID, Gender;
    string LastName, DoB, SID, Pass;
    while (ifs >> ID){
        ifs >> LastName >> Gender >> DoB >> SID >> Pass;
        if (ID == x && Password == Pass){
            isLogin = true;
            who.DoB = DoB;
            who.Gender = Gender;
            who.ID = ID;
            who.LastName = LastName;
            who.Password = Pass;
            who.Social_ID = SID;
        }
    }
    ifs.close();
}
