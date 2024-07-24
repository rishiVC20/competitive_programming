// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll n,m;
    cin>>n>>m;
    int mini = min(n,m);
    if (mini%2)
        cout<<"Malvika"<<endl;
    else    
        cout<<"Akshat"<<endl;
    return 0;
}

// https://codeforces.com/problemset/problem/451/A