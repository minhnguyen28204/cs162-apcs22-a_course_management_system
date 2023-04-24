#include "Checker.h"

bool isnum(char& c)
{
    if(c >= '0' && c <= '9') return true;
    return false;
}

bool ValidDate(string& dob)
{
    int day = (dob[0] - '0')* 10 + (dob[1] - '0');
    int month = (dob[3] - '0')*10 + (dob[4] - '0');
    int year = (dob[6] - '0')*1000 + (dob[7] - '0')*100 + (dob[8] - '0')*10 + (dob[9] - '0');

    if (year < 1 || year > 9999) {
        return false;
    }

    if (month < 1 || month > 12) {
        return false;
    }

    int max_day = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        max_day = 30;
    } else if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            max_day = 29;
        } else {
            max_day = 28;
        }
    }

    if (day < 1 || day > max_day) {
        return false;
    }

    return true;
}

bool CheckDOB(string& dob)
{
    if(dob.length() < 8) return false;
    int count = 0;
    for(int i = 0; i < dob.length(); ++i)
    {
        if(dob[i] == '/') count++;
        if(dob[i] != '/' && !isnum(dob[i])) return false;
    }
    if(count != 2) return false;

    if(dob.length() == 10 && (dob[2] != '/' || dob[5] != '/') ) return false;
    else if(dob.length() == 10) return true;

    if(dob.length() == 9)
    {
        if(dob[1] == '/') dob = '0' + dob;
        else if(dob[4] == '/') dob.insert(3, "0");
        else return false;
    }

    if(dob.length() == 8 && (dob[1] != '/' || dob[3] != '/') ) return false;
    else if(dob.length() == 8)
    {
        dob = '0' + dob;
        dob.insert(3, "0");
    }

    if(!ValidDate(dob)) return false;
    return true;
}

bool ValidSemester(string sem)
{
    if(sem.size() != 1) return false;
    if(sem[0] >= '1' && sem[0] <= '3') return true;
    return false;
}

bool ValidYear(int& year, DLinkedList<Year>& listyear)
{
    if(!listyear.Head)
    {
        if(year < 0 || year > 9999) return false;
    } else if(year <= listyear.Head->data.IDyear) return false;

    return true;
}

bool isletter(char& c)
{
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return true;
    return false;
}

bool CheckName(string& name)
{
    int len = name.length();
    for(int i = 0; i < len; ++i)
    {
        if(!isletter(name[i])) return false;
        name[i] = tolower(name[i]);
    }

    name[0] = toupper(name[0]);
    return true;
}

bool CheckID(string& id)
{
    int len = id.length();
    for(int i = 0; i < len; ++i)
    {
        if(!isnum(id[i])) return false;
    }
    return true;
}

void delspace(string& fullname)
{
    for(int i = 0; fullname[i] != '\0'; ++i)
    {
        if(fullname[i] == ' ' && (fullname[i + 1] == ' ' || fullname[i + 1] == '\0'))
        {
            fullname.erase(i, 1);
            i--;
        }
    }
    if(fullname[0] == ' ') fullname.erase(0, 1);
}

bool CheckGrade(string& grade)
{
    if (grade.size()==0) return false;
    int len = grade.length();
    for(int i = 0; i < len; ++i)
    {
        if(!isnum(grade[i]) && grade[i] != '.') return false;
    }

    double dgrade = stof(grade);
    if(dgrade >= 0 && dgrade <= 10) return true;
    return false;
}

bool CheckFullName(string& fullname)
{
    int len = fullname.length();
    for(int i = 0; i < len; ++i)
    {
        if(!isletter(fullname[i]) && fullname[i] != ' ') return false;
    }
    delspace(fullname);

    len = fullname.length();

    if(islower(fullname[0])) fullname[0] = toupper(fullname[0]);

    for(int i = 0; i < len - 1; ++i)
    {
        if(fullname[i] == ' ' && isletter(fullname[i + 1]) && islower(fullname[i + 1]))
        fullname[i + 1] = toupper(fullname[i + 1]);
        if(isletter(fullname[i]) && isletter(fullname[i + 1]) && isupper(fullname[i + 1]))
        fullname[i + 1] = tolower(fullname[i + 1]);
    }
    return true;
}

bool CheckDOW(string& dow)
{
    if(dow.size() != 3) return false;

    for(int i = 0; i < 3; ++i)
    {
        if(!isletter(dow[i])) return false;
        if(islower(dow[i])) dow[i] = toupper(dow[i]);
    }

    if(dow.compare("MON") != 0 && dow.compare("TUE") != 0 && dow.compare("WED") != 0  && dow.compare("THU") != 0 && dow.compare("FRI") != 0 && dow.compare("SAT") != 0 && dow.compare("SUN") != 0)
    return false;
    return true;
}

bool CheckSession(string& sess)
{
    if(sess.size() != 2) return false;

    if(isletter(sess[0]) && islower(sess[0])) sess[0] = toupper(sess[0]);

    if(sess.compare("S1") != 0 && sess.compare("S2") != 0 && sess.compare("S3") != 0 && sess.compare("S4") != 0) return false;
    return true;
}

