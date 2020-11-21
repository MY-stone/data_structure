#include <iostream>
#include <fstream>
#include "LinkList.h"

using namespace std;

int main()
{
    Student s("D:/code/data_structure/LinkList/data.txt");
    double average[9] = {0};//mm,me,mp,wm,we,wp,am,ae,ap
    s.Init_List();
    s.Input_List();
    s.average(average);
    s.highest_grade();

    s.query_grade();
    s.amend_grade();
    s.delete_student();
    s.add_student();

    getchar();
}


