#include "CheckAccount.h"
#include "Student.h"
#include <bits/stdc++.h>
using namespace std;

void Checking(string User, string Password, bool &isLogin, int &id, bool &Stop){
    long long x = -1;
    if (User.size()) x = stoi(User);
    ifstream ifs("Data/data.dat");
    string ID, Pass;
    while (ifs >> ID){
        ifs >> Pass;
        if (ID == User && Pass == Password) id = x, isLogin = true, Stop = true;
    }
    ifs.close();
}
