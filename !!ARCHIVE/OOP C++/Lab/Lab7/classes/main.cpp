#include <iostream>
#include <string.h>

using namespace std;

//1 ) make class with 2 constructors (default and parameterized)
//2 ) use the fill and print student
class Student {
int id;
char name[20];
double grade;

public:
    Student(){
    id = 0;
    name[20] = {0};
    grade = 0;
}

Student(int i, char n[20], int g){
    id = i;
    strcpy(name,n);
    grade = g;
}

    void setId(int i){
    id = i;
    }
    void setName(char n[20]){
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
};

Student fillStudent();
void printStudent(Student st);


int main()
{
    Student s1;
    Student s2(5,"ALO",10);
    printStudent(s2);
    cout<<endl;
    s1 = fillStudent();
    printStudent(s1);
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
