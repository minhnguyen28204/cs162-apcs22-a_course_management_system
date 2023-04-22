#include <string>
#include "DoublyLinkedList.hpp"
#include "year.h"
#include "Checker.h"

using namespace std;

bool isnum(char& c);
bool ValidDate(string& dob);
bool CheckDOB(string& dob);
bool ValidSemester(int& semid);
bool ValidYear(int& year, DLinkedList<Year>& listyear);
bool isletter(char& c);
bool CheckName(string& name);
bool CheckID(string& id);
void delspace(string& fullname);
bool CheckFullName(string& fullname);
bool CheckDOW(string& dow);
bool CheckSession(string& sess);



