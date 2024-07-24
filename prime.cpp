// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
bool isPrime(int n){
    if (n<=1){
        return false;
    }
    for (int i=2; i*i<=n; i++){
        if (n%i==0)
            return false;
    }
    return true;
}
int main() {
    ll t;
    cin>>t;
    while (t--){
        ll n,m;
        cin>>n>>m;
        for (int i=n; i<=m; i++){
            if (isPrime(i)){
                cout<<i<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}

https://www.spoj.com/problems/PRIME1/cstart=10