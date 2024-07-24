// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,a,b;
        cin>>n>>a>>b;
        if (a*2 <= b){
            cout<<a*n<<endl;
            continue;
        }       
        cout<<(n/2)*b+(n%2)*a<<endl;
    }
    return 0;
}