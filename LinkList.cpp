#include<iostream>
#include<fstream>
#include<string>
#include "LinkList.h"


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
    }LinkList_Student;

private:
    int size = 100;
    LinkList_Student List;

    /* data */
public:

    void setSize(int setSize)
    {
        size = setSize;
    }

    int getSize(void)
    {
        return size;
    }

public:
    void Init_List(&LinkList_Student L)
    {
        L = new LNode;
	    L->next = NULL;
    }

    void Input_List(&LinkList_Student L)
    {
        int i;
        List p, r;
        r = L;
        char filename[20] = { 0 };
        cout << "请输入顺序表L" << st << "的数据文件名称（文件名+“.txt”，如List" << st << ".txt）：" << endl;
        ++st;
        gets(filename);
        fstream file;
        file.open(filename);
        if (!file) {
            cout << "未找到相关文件，无法打开！" << endl;
            exit(ERROR);
        }
        while (!file.eof()) {
            p = new LNode;
            file >> p->data;
            p->next = NULL;
            r->next = p;
            r = p;
            n++;
	}
	file.close();
    }
    void Clear_List(&LinkList_Student L)
    {

    }

    void Destroy_List(&LinkList_Student L)
    {

    }




    Student(/* args */);
    ~Student();
};

//构造函数
Student::Student(/* args */)
{
}

//析构函数
Student::~Student()
{
}
