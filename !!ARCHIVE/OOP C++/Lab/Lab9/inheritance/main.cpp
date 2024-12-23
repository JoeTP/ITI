#include <iostream>
#include <string.h>
using namespace std;

class Person{
   protected:
    int id;
    char name[20];

    public:
    Person(){
    id = 0;
    name[20] = {0};
    }

    Person(int v, char ar[20]){
    id = v;
    strcpy(name, ar);
    }

    int getId(){return id;}
    char* getName(){return name;}

    void setId(int v){id = v;}
    void setName(char ar[20]){strcpy(name,ar);}

   virtual void printData(){
    cout<<"ID: "<<id<<endl;
    cout<<"Name: "<<name<<endl;
    }
};
class Customer : public Person{
    char contact[20];
    Person *pers;

    public:
    Customer(){
    contact[20] = {0};
    }
    Customer(int i, char n[20], char con[20]) : Person(i,n){
        strcpy(contact, con);
    }

    Customer(Person *p, char con[20]){
        pers = p;
        if(p){strcpy(contact, con);}
    }

    char* getContact(){return contact;}
    void setContact(char ar[20]){strcpy(contact,ar);}

      virtual  void printData(){
          Person::printData();
        cout<<"Contact Info "<<contact<<endl;
        }

};

class Employee : public Person{
    char companyName[20];
    Person *pers;

    public:
    Employee(){
    companyName[20] = {0};
    }

    Employee(Person *p, char comp[20]){
        pers = p;
        if(p != NULL){strcpy(companyName, comp);}
    }

    Employee(int i, char n[20], char comp[20]) : Person(i,n){
        strcpy(companyName, comp);
    }
    char* getCompanyName(){return companyName;}
    void setCompanyName(char ar[20]){strcpy(companyName,ar);}

      virtual  void printData(){
          Person::printData();
        cout<<"Company Name: "<<companyName<<endl;
        }
};

void printAll(Person *p);

int main()
{
    Person p(2,{"PersonName"});
    p.printData();
    cout<<endl;
    Customer c (2, {"CustName"},{"01111111"});
    c.printData();
    cout<<endl;
    Employee e(5,{"EmpName"},{"ITI"});
    e.printData();

    cout<<endl<<endl;


    printAll(&p);
    cout<<endl;
    printAll(&e);
    cout<<endl;
    printAll(&c);
    return 0;
}

void printAll(Person *p){
    p->printData();
}
