// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int main() {
    ll t;
    cin>>t;
    while (t--){
        ll n;
        cin>>n;
        bool flag=false;
        for (ll i=2; i<n/2; i++){
            if (n%i == 0 && i%2 != 0){
                flag = true;
                break;
            }
        }
        if (flag)
            cout<<"YES"<<endl;
        else    
            cout<<"NO"<<endl;    
    }
    return 0;
}