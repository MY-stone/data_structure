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
	List p, r;
	fstream file;
    string s_data;
    vector<string> vs_data;      //初始化容器
	file.open(this->file_addreess);
	if (!file) {
		cout << "未找到相关文件，无法打开！检查文件路径！" << endl;
		exit(ERROR);
	}
	
    getline(file,s_data);   //跳过第一行
    while (file.good()) {
        getline(file,s_data);
        this->split(s_data.data(),vs_data);
        
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


