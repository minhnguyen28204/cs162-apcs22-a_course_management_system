#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "DoublyLinkedList.hpp"

struct Score
{
    int stu_info;
    double tot_mark;
    double fin_mark;
    double mid_mark;
    double other_mark;
};

struct Scoreboard
{
    DLinkedList <Score> *pScore; // haven't has score list yet.
    bool unlocked; // has been puplished or not (so that the student can view it or not)
};

#endif
