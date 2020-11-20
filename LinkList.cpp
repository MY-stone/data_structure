#include "LinkList.h"


void Student::setSize(int setSize)
{
    this->size = setSize;
}

int Student::getSize(void)
{
    return this->size;
}

void Student::split(const char *s, vector<string>& strs, char delim = ' ') 
{
    if(s == nullptr) {
        return;
    }

    const char *head, *tail;
    head = tail = s;
    
    while(*head != '\0') {
        while(*head != '\0' && *head == delim) {
            head++;
        }

        tail = head;
        while(*tail != '\0' && *tail != delim) {
            tail++;
        }

        if(head != tail) {
            strs.push_back(string(head,tail));
            head = tail;
        } else {
            break;
        }
    }
}

void Student::Init_List(void)
{
    this->test_Score.next=NULL;
}

void Student::Input_List(void)
{
	List p, L;
    L = &(this->test_Score); 
	fstream file;
    string s_data;
    stringstream s_change;
    vector<string> vs_data;      //初始化容器

	file.open(this->file_addreess);
	if (!file) {
		cout << "未找到相关文件，无法打开！检查文件路径！" << endl;
		exit(ERROR);
	}
	
    getline(file,s_data);   //跳过第一行
    while (file.good()) {
        getline(file,s_data);
        this->split(s_data.data(),vs_data); //字符串

        p = new LinkList_Student;
        s_change<<vs_data[0];  //将string转换成其它类型
        s_change>>p->student_number; //学号

        p->name = vs_data[1];       //名字
        p->gender = vs_data[2];     //性别

        s_change<<vs_data[3];       //年龄
        s_change>>p->age;

        p->subjet = vs_data[4];     //科目
        
        s_change<<vs_data[5];       //分数
        s_change>>p->grade;
        p->next = NULL;
        vs_data.clear();            //清空容器

        L->next = p;
        L = p;

	}

	file.close();
}

void Student::OutPut(void)
{
    cout<<"测试输入"<< endl;
}

Student::Student()
{
    List Student_List;
}

Student::~Student()
{
}


