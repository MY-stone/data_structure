#ifndef __LINKLIST_H__
#define __LINKLIST_H__
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student
{
    private:

        //定义链表的必要元素
        typedef struct LinkList_Student
        {
            const char student_number;
            const string name;
            const string gender;
            const int age;
            const string subjet;
            int grade;
            struct LinkList_Student *next;
        }LinkList_Student,*List;

    private:
        int size = 100;
        //LinkList_Student Student_List;

        /* data */
    public:

        void setSize(int setSize);
        int getSize(void);
        void Init_List(List &L);
        void OutPut(void);
        Student();
        ~Student();

};

#endif

