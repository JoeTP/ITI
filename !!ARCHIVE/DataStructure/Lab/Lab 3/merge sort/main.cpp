#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;


class Employee{
public:
    int id;
    char name[20];

    Employee(){
        id = 0;
        strcpy(name, "");
    }

    Employee(int id, char *name){
        this->id = id;
        strcpy(this->name,name);
    }
};


Employee fillEmployee();
void sortByName(Employee ar[], int s); ///BUBBLE SORT
void sortById(Employee ar[], int lb, int ub); ///MERGE SORT
void merging(Employee ar[], int low, int mid, int high);
int searchByName(Employee ar[], char *name);
int searchById(Employee ar[], int id);
void print(Employee ar[]);

void switchCases(int &ca, Employee ar[]);

int main(){
    Employee ar[8] = {Employee(1,"joe"),Employee(3,"tag"),Employee(6,"ahmed"),Employee(2,"zizo"),Employee(21,"kolo"),Employee(19,"easyh"),Employee(11,"jinx"),Employee(10,"jozz")};
    int c;

    do{
    cout<<"1-Fill Employees"<<endl;
    cout<<"2-Sort By ID"<<endl;
    cout<<"3-Sort By Name"<<endl;
    cout<<"4-Search By ID"<<endl;
    cout<<"5-Search By Name"<<endl;
    cout<<"6-Print"<<endl;
    cout<<"7-Quit"<<endl;
    cin>>c;

    switchCases(c, ar);
    }while(c != 7);
    return 0;
}

Employee fillEmployee(){
    int id;
    char name[20];
    cout<<"ENTER ID: ";
    cin>>id;
    cout<<"ENTER NAME: ";
    cin>>name;
    Employee e(id,name);
    return e;
}

void sortByName(Employee ar[], int s){
    int swapped = 1, i = 0;
    Employee temp;
    while(swapped){
        swapped = 0;
        for(int j = 0; j< s -1 - i; j++){
            if((int) ar[j].name[0] > (int)ar[j+1].name[0]){
                swapped = 1;
                temp = ar[j];
                ar[j] = ar[j+1];
                ar[j+1] = temp;
            }
        }
        i++;
    }
}

void sortById(Employee ar[], int lb, int ub){
    //int mid;
    if(ub>lb){
       int mid = (lb+ub)/2;
        sortById(ar, lb, mid);
        sortById(ar, mid+1, ub);
        merging(ar, lb, mid, ub);
    }
}

void merging(Employee ar[], int low, int mid, int high){
    Employee *temp = new Employee[high - low + 1];
    int l1,l2,i;
    l1 = i = low;
    l2 = mid+1;
    while(l1 <= mid && l2 <= high){
        if(ar[l1].id < ar[l2].id){
            temp[i] = ar[l1];
            l1++; i++;
        }else{
            temp[i] = ar[l2];
            l2++; i++;
        }
    }
    while(l1<=mid){
        temp[i] = ar[l1];
        i++; l1++;
    }
    while(l2 <= high){
        temp[i] = ar[l2];
        i++; l2++;
    }
    for(i = low; i <= high; i++){
        ar[i] = temp[i];
    }
    delete[] temp;
}

int searchById(Employee ar[], int lb, int ub, int id){
    sortById(ar,lb,ub);
    int loc = -1;
    int mid;
    while(loc == -1 && lb <= ub){
         mid = (lb+ub)/2;
         if(ar[mid].id == id){loc = mid;}
         if(ar[mid].id > id){ub = mid-1;} //search in left side
         if(ar[mid].id < id){lb = mid+1;} //search in right side
    }
    return loc;
}

int searchByName(Employee ar[], int lb, int ub, char n[]){
    sortByName(ar,ub);
    int loc = -1;
    int mid;
    while(loc == -1 && lb <= ub){
         mid = (lb+ub)/2;
        if(ar[mid].name[0] == n[0]){loc = mid;}
        if(strcmp(ar[mid].name,n) > 0){ub = mid-1;}
        if(strcmp(ar[mid].name,n) < 0){lb = mid+1;}
    }
    return loc;
}

void print(Employee ar[], int s){
    for(int i = 0; i<s; i++){
        cout<<ar[i].id<<" > "<<ar[i].name<<endl;
    }
    cout<<endl;
}

void switchCases(int &ca,Employee ar[]){
switch(ca){
        case 1:{
            for(int i = 0; i<8; i++){
                ar[i] = fillEmployee();
            }
            break;}
        case 2:{
            sortById(ar,0,8);
            break;}
        case 3:{
            sortByName(ar,8);
            break;}
        case 4:{
            int loc, id;
            cout<<"ENTER ID: ";
            cin>>id;
            loc = searchById(ar,0,8,id);
            if(loc >= 0){
                cout<<ar[loc].id<<": "<<ar[loc].name<<" AT LOCATION = "<<loc<<endl<<endl;
            }else{
            cout<<"NOT FOUND"<<endl<<endl;
            }
            break;}
        case 5:{
            int loc;
            char name[20];
            cout<<"ENTER NAME: ";
            cin>>name;
            loc = searchByName(ar,0,8,name);
            if(loc >= 0){
                cout<<"ID: "<<ar[loc].id<<" NAME: "<<ar[loc].name<<" AT LOCATION = "<<loc<<endl<<endl;
            }else{
            cout<<"NOT FOUND"<<endl<<endl;
            }
            break;}
        case 6:{
            print(ar, 8);
            break;}
    }
}







