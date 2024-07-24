// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    string s;
    cin>>s;
    ll n=s.size();
    ll j=0;
    // vector<int>arr(n/2);
    ll arr[n/2];
    for (ll i=0; i<n; i+=2){
        char ans=s[i];
        ll digit = ans-'0';
        // arr.push_back(digit);
        arr[j++]=digit;
    }
    // sort(arr.begin(),arr.end());
    sort(arr,arr+(n/2)+1);
    int p=0;
    for (ll i=0; i<n; i+=2){
        char l=arr[p++] + '0';
        s[i]=l;
    }
    cout<<s<<endl;
    return 0;
}