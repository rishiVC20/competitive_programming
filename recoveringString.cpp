// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--){
        ll n;
        cin>>n;
        string minis = "zzz";
        string curr = "";
        for (int i=0; i<26; i++){
            for (int j=0; j<26; j++){
                for (int k=0; k<26; k++){
                    if (i+j+k+3==n){
                        curr += (i +'a');
                        curr += (j +'a');
                        curr += (k +'a');
                        minis = min(curr,minis);
                    }
                }
            }
        }
        cout<<minis<<endl;
    }   
    
    // https://codeforces.com/contest/1931/problem/A