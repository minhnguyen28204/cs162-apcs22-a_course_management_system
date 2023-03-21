#include <iostream>
#include "Student.h"
#include "LinkedList.hpp"

int main(){
    SLLinkedList<Student> List_Students;
    List_Students.push_front({22125058,"Minh","Nguyen",1,"28-02-2004","11111"});
    std::cout << List_Students.Head->data.LastName << '\n';
    std::cout << List_Students.size() << '\n';
    List_Students.remove([&](Student P){
                    if (P.ID==22125058) return true;
                    return false;
                        });
    std::cout << List_Students.size();

    return 0;
}
