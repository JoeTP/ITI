#include <iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<stdio.h>
#include <conio.h>
#include<queue>
#include<map>
using namespace std;




int main()
{

    ///PRACTICE 1
    long long a,b,c,d,x;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;

    x = (a*b)-(c*d);
    cout<<"Difference = "<<x;


    ///PRACTICE 2
    int x;
    cin>>x;

    if(x == 100){
        cout<<"X is 100"<<endl;
    }else if(x > 100){
        cout<<"X > 100"<<endl;
    }else {
        cout<<"X < 100"<<endl;
    }

    ///PRACTICE 3
    int x, f = 1;
    cin>>x;
    for(int i = 1; i <= x; i++){
        f *= i;
    }
    cout<<"Factorial "<<x<<" = "<<f<<endl;


    ///PRACTICE 4
    int x, check = 0;
    cin>>x;

    for(int i = 2; i < x && !check; i++){
        if(x%i == 0){
            check++;
        }
    }
    if(check){
        cout<<"NON PRIME"<<endl;
        }
    else{
        cout<<"PRIME"<<endl;
        }



    ///PRACTICE 5-1
    int row = 0, col =0, x;
    char c = '#';
    cin>> x;
    while(row <= x){
        while(col < row){
            cout<<c;
            col++;
        }
        cout<<endl;
        row++;
        col = 0;
    }

    ///PRACTICE 5-2
    int ar[5] = {4, 6, 8, 1, 32};
    int minim = INT_MAX;

    for(int i = 0; i<5; i++){
        if(minim > ar[i]){
            minim = ar[i];
        }
    }
    cout<<"MIN IS "<< minim<<endl;



    ///PRACTICE 6
    int ar[3][4] = {{1,23,6,2},{7,4,6,3},{8,7,7,10}};
    int sumEv[3] = {0};
    int sumOd[3] = {0};
    int row = 3, col = 4;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(ar[i][j] % 2 == 0){
                sumEv[i] += ar[i][j];
            }else{
                sumOd[i] += ar[i][j];
            }
        }
    }

    for(int i = 0; i< row; i++){
        for(int j = 0; j < col; j++){
            cout<<ar[i][j]<< "\t";
        }
        cout<<endl;
    }

    cout<<endl;
    cout<<"EVEN SUM \t ODD SUM"<<endl;
    for(int i = 0; i<row; i++){
        cout<<sumEv[i]<<"\t\t  "<<sumOd[i]<<endl;
    }

    ///PRACTICE 7
    vector<int> v(3);
    for(int i = 0; i < v.size(); i++){
        cin>>v[i];
    }

    sort(v.begin(),v.end());

    for(int i = 1; i < v.size()+1; i++){
        if(v[i-1] != i){
            cout<<"MISSING: "<<i<<endl;
            break;
        }
        cout<<v[i-1]<<" ";
    }

    ///PRACTICE 8
    stack<char> st;
    string ch;

    cin>>ch;

    for(int i = 0; i < ch.size(); i++){
        if(ch[i] == '{'){
            st.push(ch[i]);
        }
        else if(ch[i] == '}' && !st.empty() && st.top() == '{'){
            st.pop();
        }else{
            st.push('}');
        }
    }

    if(st.empty()){
        cout<<"VALID"<<endl;
    }else{
        cout<<"INVALID"<<endl;
    }


    ///PRACTICE 9
    priority_queue<pair<int,int>> pQ;
    vector<int> v;
    int freq[50] = {0};

    for(int i = 0; i < v.size();i++){
        cin>>v[i];
    }

    for(int i = 0; i < 50; i++){
        freq[v[i]++];
    }

    for(int i = 0; i< 50; i++){
      if(freq[i]) pQ.push({freq[i],i});
    }

    while(!pQ.empty()){
        cout<<pQ.top().first<<"\t"<<pQ.top().second<<endl;
        pQ.pop();
    }


    ///PRACRICE 10
    map<string, int> mp;
    string name;
    int test;
    cin>>test;
    while(test--){
    int q;
    cin>>q;

    if(q == 1){
        int price;
        cin>>name;
        cin>>price;
        mp[name] +=price;
    }else{
        cout<< mp[name]<<endl;
        }
    }




    return 0;
}











