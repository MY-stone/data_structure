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
        s_change.clear();

        p->name = vs_data[1];       //名字
        p->gender = vs_data[2];     //性别

        s_change<<vs_data[3];       //年龄
        s_change>>p->age;
        s_change.clear();

        s_change<<vs_data[4];       //高数分数
        s_change>>p->math_grade;
        s_change.clear();

        s_change<<vs_data[5];       //英语分数
        s_change>>p->english_grade;
        s_change.clear();

        s_change<<vs_data[6];       //物理分数
        s_change>>p->physics_grade;
        s_change.clear();

        p->next = NULL;
        vs_data.clear();                //清空容器

        L->next = p;
        L = p;

	}

	file.close();
}

void Student::average(double arg[9])
{
    int n_all = 0,n_man = 0,n_woman = 0;
    double math_average = 0,english_average = 0,physics_average = 0;
    double man_math_average = 0,man_english_average = 0,man_physics_average = 0;
    double woman_math_average = 0,woman_english_average = 0,woman_physics_average = 0;

    List p;
    p = this->test_Score.next;

    while(p!=NULL){
        if(p->gender=="男"){
            n_all++;
            n_man++;

            man_math_average += p->math_grade;
            man_english_average += p->english_grade;
            man_physics_average += p->physics_grade;
        }
        else{
            n_all++;
            n_woman++;

            woman_math_average += p->math_grade;
            woman_english_average += p->english_grade;
            woman_physics_average += p->physics_grade;
        }

        p = p->next;       
    }

    //计算平均成绩
    arg[0] = man_math_average = man_math_average/n_man;
    arg[1] = man_english_average = man_english_average/n_man;
    arg[2] = man_physics_average = man_physics_average/n_man;

    arg[3] = woman_math_average = woman_math_average/n_woman;
    arg[4] = woman_english_average = woman_english_average/n_woman;
    arg[5] = woman_physics_average = woman_physics_average/n_woman;

    arg[6] = math_average = (man_math_average + woman_math_average)/2;
    arg[7] = english_average = (man_english_average + woman_english_average)/2;
    arg[8] = physics_average = (man_physics_average + woman_physics_average)/2;

    cout<<"男生高数平均："<<man_math_average<<endl;
    cout<<"男生英语平均："<<man_english_average<<endl;
    cout<<"男生物理平均："<<man_physics_average<<endl;
    cout<<"女生高数平均："<<woman_math_average<<endl;
    cout<<"女生英语平均："<<woman_english_average<<endl;
    cout<<"女生物理平均："<<woman_physics_average<<endl;
    cout<<"高数平均："<<math_average<<endl;
    cout<<"英语平均："<<english_average<<endl;
    cout<<"物理平均："<<physics_average<<endl;
}

void Student::highest_grade(void)
{
    List p,mp,ep,pp;
    p = this->test_Score.next;

    int highest_math = p->math_grade,highest_english = p->english_grade,highest_physics = p->physics_grade;

    while(p != NULL){
        if(p->math_grade > highest_math){
            highest_math = p->math_grade;
            mp = p;
        }

        if(p->english_grade > highest_english){
            highest_english = p->english_grade;
            ep = p;
        }

        if(p->physics_grade > highest_physics){
            highest_physics = p->physics_grade;
            pp = p;
        }

        p = p->next;
    }

    cout<<"高数成绩最好："<<mp->student_number<<" "<<mp->name<<" "<<"成绩："<<mp->math_grade<<endl;
    cout<<"英语成绩最好："<<ep->student_number<<" "<<ep->name<<" "<<"成绩："<<ep->english_grade<<endl;
    cout<<"物理成绩最好："<<pp->student_number<<" "<<pp->name<<" "<<"成绩："<<pp->physics_grade<<endl;

}

Student::List Student::seek_student(unsigned long student_number)
{
    List p;
    p = this->test_Score.next;

    while(p!=NULL && (p->student_number != student_number)){
        p = p->next;
    }

    if(p!=NULL)
        return p;
    else{
        cout<<"该学号不存在，请检查输入"<<endl;
        return NULL;
    }
}

void Student::query_grade(void)
{
    List p = NULL;
    unsigned int student_number = 0;
    cout<<"请输入要查询的学号：";
    cin>>student_number;
    
    p = this->seek_student(student_number);

    if(p!=NULL){
        cout<<"学号："<<p->student_number<<endl;
        cout<<"姓名："<<p->name<<endl;
        cout<<"性别："<<p->gender<<endl;
        cout<<"年龄："<<p->age<<endl;
        cout<<"数学成绩："<<p->math_grade<<endl;
        cout<<"英语成绩："<<p->english_grade<<endl;
        cout<<"物理成绩："<<p->physics_grade<<endl;
    }

}

void Student::amend_grade(void)
{
    List p = NULL;
    int type = 0,grade = 0;
    unsigned int student_number = 0;
    cout<<"请输入要修改成绩的学号：";
    cin>>student_number;
    
    p = this->seek_student(student_number);

    if(p!=NULL){
        cout<<"您将修改"<<p->name<<"的成绩" <<endl;
        cout<<"请输入要修改成绩的科目：1.高数,2.英语,3.物理"<<endl;
        cin>>type;
        cout<<"请输入要修改的成绩：";
        cin>>grade;
        
        if(type == 1)
            p->math_grade = grade;
        else if(type  == 2)
            p->english_grade = grade;
        else    
            p->physics_grade = grade;

        cout<<"修改后的成绩:";
        cout<<"数学:"<<p->math_grade<<" ";
        cout<<"英语："<<p->english_grade<<" ";
        cout<<"物理："<<p->physics_grade<<""<<endl;
    }   
}

void Student::delete_student(void)
{
    List p,d;
    p = &(this->test_Score);
    unsigned int student_number = 0;
    cout<<"请输入要删除的学号：";
    cin>>student_number;
    
    while(p->next!=NULL && (p->next->student_number != student_number)){
        p = p->next;
    }

    if(p->next!=NULL){
        d = p->next;
        p->next = p->next->next;
        free(d);
    }       
    else{
        cout<<"该学号不存在，请检查输入"<<endl;
    }
}

void Student::add_student(void)
{
	List p, L;
    L = &(this->test_Score); 
    
    while(L->next!=NULL){
        L = L->next;
    }

    string s_data;
    stringstream s_change;
    vector<string> vs_data;      //初始化容器

    cout<<"请输入要添加的信息：学号 姓名 性别 年龄 高数分数 英语分数 物理分数"<<endl;
    getline(cin,s_data);
    this->split(s_data.data(),vs_data); //字符串

    p = new LinkList_Student;   
    s_change<<vs_data[0];  //将string转换成其它类型
    s_change>>p->student_number; //学号
    s_change.clear();

    p->name = vs_data[1];       //名字
    p->gender = vs_data[2];     //性别

    s_change<<vs_data[3];       //年龄
    s_change>>p->age;
    s_change.clear();

    s_change<<vs_data[4];       //高数分数
    s_change>>p->math_grade;
    s_change.clear();

    s_change<<vs_data[5];       //英语分数
    s_change>>p->english_grade;
    s_change.clear();

    s_change<<vs_data[6];       //物理分数
    s_change>>p->physics_grade;
    s_change.clear();

    p->next = NULL;
    vs_data.clear();                //清空容器

    L->next = p;
}

Student::Student(string s = "D:/code/data_structure/LinkList/data.txt")
{
    this->file_addreess = s;
}

Student::~Student()
{
}


