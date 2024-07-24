// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int dcount=0;
    int acount=0;
    for (int i=0; i<n; i++){
        if (s[i]=='D')
            dcount++;
        else    
            acount++;    
    }
    if (dcount==acount)
        cout<<"Friendship"<<endl;
    else if (acount>dcount)
        cout<<"Anton"<<endl; 
    else
        cout<<"Danik"<<endl;       
    return 0;
}

// https://codeforces.com/problemset/problem/734/A