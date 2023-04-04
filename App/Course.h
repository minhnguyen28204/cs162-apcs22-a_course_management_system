#ifndef COURSE_H
#define COURSE_H

#include "Class.h"
#include "ScoreBoard.h"

struct Course
{
    Class registered_class;
    string ID;
    string course_name;
    string teacher_name;
    int credits_num;
    int max_students;
    string date_of_week;
    string session; // S1 (07:30), S2 (09:30), S3(13:30) and S4 (15:30)
    Scoreboard sco_board;
    void Update_Info(); // update a course info
    void Remove_A_Student();
    // in the end of semester
    // only by staff
    void Export_Students(); // Export a list of students in a course to a CSV file
    void Import_Scoreboard(); // Import from CSV file
    void view_scoreboard(); // if staff puplished, student can see it
};

#endif