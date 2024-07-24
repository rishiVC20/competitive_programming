#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    int t;
    cin>>t;
    while (t--){
       ll n;
       cin>>n;
       string s;
       cin>>s;
       int  j=0;
       int ans=0;
       for (int i=n-1; i>=0; i--){
        int digit = s[i]-'0';
        if (digit == 1){
            ans += pow(2,j);
        }
        j++;
       }
       cout<<ans<<endl;
    }
    return 0;
} 