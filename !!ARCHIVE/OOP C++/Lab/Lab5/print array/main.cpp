#include <iostream>
#include <stdio.h>
#include <conio.h>
#include<string.h>
#include<ctype.h>
#include <windows.h>
using namespace std;

COORD coord = {0,0};
void gotoxy(int x, int y){
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int main(){

    //right = 77
    //left = 75
    //home = 80
    //end = 79
    //esc = 27
    //enter = 13
    char ar[10];
    char ch;
    char* pt;
    int arSize = 0;
    int col = 0;
    int row = 1;
    pt = ar;

    int i = 0;
    cout<<"Enter Value"<<endl;
while(pt<&ar[10]){
        ch = getch();
        if(isprint(ch)){
            *pt = ch;
        cout<<*pt;
            pt++;
            if (col == arSize){
            arSize++;
            };
            col++;

        }
        else if(ch == -32){
         ch = getch();
        //right arrow
        if(ch == 77){
        col++;
        pt++;
        if(col > arSize){
            col = arSize;
            pt--;
        }
        gotoxy(col,row);
        }
        //left arrow
        if(ch == 75){
        col--;
        pt--;
        if(col < 0){
            col = 0;
            pt++;
        }
        gotoxy(col,row);
        }

        //END => arrow down
        else if (ch == 79){
            col = arSize;
            pt = &ar[arSize];
            gotoxy(col,row);
        }
        //HOME
        else if (ch == 71){
            col =0;
            pt = ar;
            gotoxy(0,row);
        }
        }
        //ENTER
        else if (ch == 13){
            gotoxy(10,10);
            for(int i = 0; i<arSize; i++){
                cout<<ar[i];
            }
            gotoxy(col, row);
        }
        //ESCAPE
        else if (ch == 27){
            pt+=11;
        }
    }

return 0;
}
