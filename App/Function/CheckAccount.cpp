#include "CheckAccount.h"
#include "Student.h"
#include <bits/stdc++.h>
using namespace std;

void Checking(string user, string Password, bool &isLogin, int &id, bool &Stop, User &Who, bool &is_student){
    string temp = "Information/" + user + ".dat";
    ifstream ifs(temp);
    if (!ifs.is_open()){
        return;
    }
    string Pass;
    ifs >> Pass;
    ifs >> is_student;
    ifs >> Who.FirstName;
    ifs >> Who.LastName;
    ifs >> Who.Gender;
    ifs >> Who.dob;
    ifs >> Who.Social_ID;
    if (Pass == Password) isLogin = true, Stop = true, Who.ID = user;
    ifs.close();
}
