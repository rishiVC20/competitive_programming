// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    string s;
    cin>>s;
    ll n = s.size();
    ll curr=1;
    ll maxi = INT_MIN;
    for (int i=0; i<n-1; i++){
        if(s[i]==s[i+1]){
            curr++;
            maxi=max(maxi,curr);
        }
        else{
            curr=1;
        }
    }   
    if (maxi>=7)
        cout<<"YES"<<endl;
    else    
        cout<<"NO"<<endl;    
    return 0;
}

// https://codeforces.com/problemset/problem/96/A