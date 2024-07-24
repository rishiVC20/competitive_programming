// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll> 

const ll mod = 1e9+7;

ll mul (ll a, ll b, ll m=mod)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll power(ll base, ll exponent)
{
    if (exponent < 0)
    {
        return 0;
    }
    ll ans = 1;
    while (exponent)
    {
        if (exponent%2==0)
        {
            base = (base*base) % mod;
            exponent = exponent/2;
        }
        else
        {
            ans = (ans*base) % mod;
            exponent--;
        }
    }
    return ans;
}


int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,m;
        cin>>n;
        vi a,b,d;
        for (ll i=0; i<n; i++)
        {
            ll x; cin>>x;
            a.pb(x);
        }       
        for (ll i=0; i<n; i++)
        {
            ll x; cin>>x;
            b.pb(x);
        }
        cin>>m;
        for (ll i=0; i<m; i++)
        {
            ll x; cin>>x;
            d.pb(x);
        }
        // sort(d.rbegin(),d.rend());
        // vi q;
        // for (ll i=0; i<n; i++)
        // {
        //     if (a[i] != b[i])
        //         q.pb(i);
        // }
        // for (auto i:q)
        //     cout<<i<<" ";
        // vector<bool>c(q.size(),true);
        // vector<bool>d2(m,true);
        // ll ui = 0;
        // bool vb = true;
        // ll t = 0;
        // for (ll i=0; i<q.size(); i++)
        // {
        //     ll r = b[q[i]];
        //     ui = 0;
        //     for (ll j=0; j<m; j++)
        //     {
        //         if (d[j]==r )
        //         {
        //             // c[i] = false;
        //             // d2[j] = false;
        //             // break;
        //             ui++;
        //             t++;
        //         }
        //         // else{
        //         //     break;
        //         // }
        //     }
        //     if (t==n)
        //         break;
        //     if (ui==0){
        //         vb = false;
        //         break;
        //     }
            
        // }

        // if (!vb){
        //     cout<<"NO"<<endl;
        //     continue;
        // }
        // cout<<"hi"<<" ";
        // // for (auto i:c)
        // //     cout<<i<<" ";
        // bool f = true;
        // for (ll i=0; i<m; i++)
        // {
        //     if (d2[i] == true && d[i-1]!=d[i] && d[i+1]!=d[i]){
        //         f = false;
        //         break;
        //     }
        // }

        // if (f)
        //     cout<<"YES"<<endl;
        // else
        //     cout<<"NO"<<endl; 

        // ll qq = q.size();
        // if (qq > m){
        //     cout<<"NO"<<endl;
        //     continue;
        // }

        map<ll,ll>mp1,mp2;
        bool k = false;
        ll cc = d[m-1];
        for (ll i=0; i<n; i++)
        {
            if (a[i] != b[i])
            {
                mp1[b[i]]++;
            }
            if (cc == b[i])
                k = true;
        }

        if (!k){
            cout<<"NO"<<endl;
            continue;
        }
        // cout<<"Hi"<<" ";
        for (ll i=0; i<m; i++)
            mp2[d[i]]++;

        bool f = true;
        for (auto i : mp1)
        {
            ll hj = i.first;
            if (i.second > mp2[hj]){
                f = false;
                break;
            }
            // if (mp2[x] < y)
            //     f = false;
        }    
        if (count(b.begin(),b.end(),d[m-1])==0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        if (f)  
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;    
        
    }
    return 0;
}