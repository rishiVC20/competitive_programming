#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll t;
    cin>>t;
    while (t--){
        ll n;
        cin>>n;
        vector<int>b(n-1);
        for (int i=0; i<n-1; i++)
            cin>>b[i];
        vector<int>a;
        a.push_back(b[0]);
        for (int i=0; i<n-2; i++){
            a.push_back(min(b[i],b[i+1]));
        }    
        a.push_back(b[n-2]);
        for (auto& i:a)
            cout<<i<<" ";
        cout<<endl;    
    }    
    return 0;
}