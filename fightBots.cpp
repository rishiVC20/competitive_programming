#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,x,y;cin>>n>>x>>y;
        string s;
        cin>>s;
        vector<pair<ll,ll>>v;
        ll p=0,q=0;
        bool f=false;
        for(ll i=0; i<n; i++){
            if(s[i]=='R'){
                p++;
            }
            else if(s[i]=='L'){
                p--;
            }
            else if(s[i]=='U'){
                q++;
            }
            else{
                q--;
            }
            if(abs(p-x)+abs(q-y)==i+1){
                f=true;
                break;
            }
            v.push_back({p,q});
        }

        
        
        if(f){
            cout<<"YES"<<endl;;
        }
        else{
            cout<<"NO"<<endl;
        }

    }
    return 0;
}