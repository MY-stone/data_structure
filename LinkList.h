#ifndef __LINKLIST_H__
#define __LINKLIST_H__
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
#define ERROR 0

class Student
{
    public:
    //定义链表的必要元素
        typedef struct LinkList_Student
        {
            unsigned long student_number;   //学号
            string name;                    //姓名
            string gender;                  //性别
            int age;                        //年龄
            string subjet;                  //科目
            int grade;                      //分数
            struct LinkList_Student *next;
        }LinkList_Student,*List;

    private:
        int size = 100;
        LinkList_Student test_Score = {0};
        string file_addreess = "D:/code/data_structure/LinkList/data.txt";//文件地址
    public:

        void setSize(int setSize);
        int getSize(void);
        void split(const char *s,vector<string>& strs, char delim); 
        void Init_List();        //初始化链表,封闭操作
        void Input_List(void);   //将文件内容写入链表
        void OutPut(void);
        Student();
        ~Student();

};

#endif

