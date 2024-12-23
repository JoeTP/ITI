#include <iostream>

using namespace std;

//1 ) make a struct to fill data using fill FUNCTION  (return student)=> press enter when finished to print the data again using FUNCTION TOO (void)
//2 ) fill 3 students
//3 ) ask user to enter number of students and make dynamic allocation

struct Student {
int id;
char name[20];
double grades [3];
};
Student fillStudent();
void printStudent(Student* st);


int main()
{
    int sno;
    cout<<"Enter number of Students: ";
    cin>> sno;
    cout<<endl;
    Student* sp = new Student[sno];
    if(sp){

    for(int i = 0; i <sno; i++){
    cout<<"Student "<<i+1<<" Information"<<endl;
    *(sp+i) = fillStudent();
    cout<<endl;
    }

    for(int i = 0; i<sno; i++){
    printStudent(sp+i);
    }
    delete(sp);
    }

    return 0;
}

void printStudent(Student* st){
    cout<<endl;
    cout<<"Student "<<"\""<<st -> name<<"\""<<" Information"<<endl;
    cout<<"_____________________________________"<<endl;
    cout<<"ID: "<<st -> id<<endl;
    cout<<"Name: "<<st -> name<<endl;
    cout<<"Degrees: ";
    for (int i = 0; i < 3; i++){
        cout<<st ->grades[i]<<" ";
    }

}

Student fillStudent(){
 Student s;
 cout<<"Enter student ID: ";
 cin>> s.id;
 cout<<"Enter student Name: ";
 cin>> s.name;
 cout<<"Enter student Degrees (3 subjects) : ";
 for(int i = 0; i < 3; i++){
    cin>> s.grades[i];
 }
return s;
}
