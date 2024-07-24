#include<bits/stdc++.h>
using namespace std;

int main() {
    int a,b;
    char s;
    cin>>a>>s>>b;
    int p;
    switch(s){
        case '+' : p = a+b;
                cout<<p;
                break;
        case '-' : p = a-b;
                cout<<p;
                break;
        case '*' : p = a*b;
                cout<<p;
                break;
        case '/' : p = a/b;
                cout<<p;
                break;                        
    }
    return 0;
}