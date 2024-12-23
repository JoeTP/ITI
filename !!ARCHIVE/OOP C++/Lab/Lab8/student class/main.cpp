#include <iostream>
#include <string.h>

using namespace std;

//1 ) make class with 2 constructors (default and parameterized)
//2 ) use the fill and print student
class Student {
int id;
char name[20];
double grade;
static int counter;
static char school[7];

public:
    Student(){
    id = 0;
    name[20] = {0};
    grade = 0;
    counter++;
    }
    Student(int i, char *n, int g){
    id = i;
    strcpy(name,n);
    grade = g;
    counter++;
    }

    void setId(int i){
    id = i;
    }
    void setName(char *n){
    strcpy(name,n);
    }
    void setGrade(int g){
    grade = g;
    }

    int getId(){
    return id;
    }
    char* getName(){
    return name;
    }
    double getGrade(){
    return grade;
    }
    //
    static int  getCounter(){
        return counter;
    }
    static char* getSchool(){
        return school;
    }
    static void setSchool(char sch[7]){
                strcpy(school,sch);
        }

    ~Student(){
    counter--;

    }
};

int Student::counter = 0;
char Student::school[7] = "Madina";
Student fillStudent();
void printStudent(Student st);


int main()
{
    int stn;
    cout<<"Enter number of students: ";
    cin>>stn;
    Student *s = new Student[stn];
    cout<<endl;
    if(s){

        cout<<"Students of "<<Student::getSchool()<<" Scool:"<<endl;
    //fill student data
        for(int i =0; i<stn; i++){
            s[i]= fillStudent();
        cout<<"###Number of Students => "<<Student::getCounter()<<endl;
        cout<<endl;
        }
    //print students data
        for (int i =0; i<stn; i++){
            printStudent(s[i]);
        }
    cout<<endl;
    cout<<"###Number of Students => "<<Student::getCounter()<<endl;
    delete[] s;
    }
    cout<<"###Number of Students => "<<Student::getCounter()<<endl;


    //change school
    char sName[7];
    cout<<endl<<endl;
    cout<<"Change School name: ";
    cin>>sName;
    Student::setSchool(sName);
    cout<<"New school name: "<<Student::getSchool()<<endl;

    return 0;
}

void printStudent(Student st){
    cout<<endl;
    cout<<"Student Information"<<endl;
    cout<<"___________________"<<endl;
    cout<<"ID: "<<st.getId()<<endl;
    cout<<"Name: "<<st.getName()<<endl;
    cout<<"Degree: "<<st.getGrade()<<endl;

}

Student fillStudent(){
 Student s;
 int id;
 char name[20];
 int grade;

 cout<<"Enter student ID: ";
 cin>> id;
 s.setId(id);
 cout<<"Enter student Name: ";
 cin>> name;
 s.setName(name);
 cout<<"Enter student Degree: ";
 cin>>grade;
 s.setGrade(grade);
return s;
}
