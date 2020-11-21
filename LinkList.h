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
            int math_grade;                 //高数分数
            int english_grade;              //英语成绩
            int physics_grade;              //物理成绩
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
        void average(double arg[]);    //求平均成绩,输入数组存储
        void highest_grade(void);      //查找各科分数最高的同学
        List seek_student(unsigned long student_number);    //查看输入学号的同学是否在链表中并返回地址
        void query_grade(void);        //根据学号查成绩
        void amend_grade(void);        //根据学号修改成绩
        void delete_student(void);     //根据学号删除
        void add_student(void);        //添加一条
        Student(string s);
        ~Student();

};

#endif

