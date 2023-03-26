#include "Save.h"
#include <string>
#include <fstream>
#include "DoublyLinkedList.hpp"
#include "Class.h"
#include "Course.h"
#include "Year.h"
#include "Login/LoginScreen.h"
#include "VoidOfUser.h"

int main()
{
    string user, Password;
    LoginScreen(user,Password);
    int ID = 0; ToInt(ID,user);
    User Who;
    getUser(ID,Who);
    DLinkedList <Class> list_class;
    Student stu1, stu2;
    Class class1, class2;
    stu1.No = 1;
    stu1.ID = 22125005;
    stu1.FirstName = "Bach";
    stu1.LastName = "Mai";
    stu1.Gender = 1;
    stu1.dob = "17/04/2004";
    stu1.Social_ID = 2009206113182;

    stu2.No = 2;
    stu2.ID = 22125045;
    stu2.FirstName = "Nghia";
    stu2.LastName = "Nguyen";
    stu2.Gender = 1;
    stu2.dob = "22/04/2004";
    stu2.Social_ID = 2009123546642;
    class1.class_name = "22CTT1";
    class2.class_name = "22CTT2";
    class1.stu_list.push_front(stu1);
    class1.stu_list.push_front(stu1);
    class2.stu_list.push_front(stu2);
    class2.stu_list.push_front(stu2);
    class2.stu_list.push_front(stu2);
    list_class.push_front(class1);
    //delete list_class.Head;
    //list_class.Head->data.stu_list.Delete();
    //list_class.Head->pNext->data.stu_list.Delete();
    //cout << list_class.Head->data.stu_list.Head;
    //cout << 1;
    //list_class.Delete();
    //-cur=cur->pNext;
    //cout << 1 << ' ' << cur->data.ID;

    Save_Classes("classes.CSV", list_class);

    return 0;
}
