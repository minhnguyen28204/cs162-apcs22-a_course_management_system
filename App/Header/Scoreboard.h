#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "DoublyLinkedList.hpp"
#include <string>
using namespace std;

struct Score
{
    int No;
    int stu_id;
    string first_name;
    string last_name;
    double tot_mark;
    double fin_mark;
    double mid_mark;
    double other_mark;
    bool operator == (const Score &other) const{
        return (No==other.No);
    }
    bool operator > (const Score &other) const{
        return (No>other.No);
    }
};


#endif
