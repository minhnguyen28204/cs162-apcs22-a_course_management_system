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

struct Scoreboard
{
    DLinkedList <Score> score_list; // haven't has score list yet.
    bool unlocked; // has been puplished or not (so that the student can view it or not)
};

#endif
