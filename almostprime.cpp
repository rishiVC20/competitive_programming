// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long
bool checkPrime(ll n){
    for (ll i=2; i<n/2; i++){
        if (n%i == 0)
            return false;
    }
    return true;
} 
int main() {
    ll n;
    cin>>n;
    int count = 0;
    while (n>=1){
        for (ll i=2; i<n/2; i++){
            if(n%i==0 && checkPrime(i)){
                count++;
            }
        }
        n--;
    }
    cout<<count<<endl;
    return 0;
}