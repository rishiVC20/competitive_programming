// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>
#define YES cout<<'Y'<<'E'<<'S'<<endl
#define NO cout<<'N'<<'O'<<endl  

const ll mod = 998244353;

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
ll invmod(ll a, ll m = mod) { return power(a, m - 2); }
    
ll mDiv(ll a, ll b, ll m = mod)
{
    a = a % m;
    b = b % m;
    return mul(a, invmod(b, m), m);
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    ll tt;
    cin>>tt;
    while (tt--)
    {
        
        ll n,q;
        cin>>n>>q;
        vector<ll> v1,v2;
        vi a;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
            v1.pb(x);
        }
        // sort(d.begin(),d.end());
        sort(v1.begin(),v1.end());
        vi b;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            b.pb(x);
            v2.pb(x);
        }
        sort(v2.begin(),v2.end());

        map<ll,ll>lasta,lastb,cnta,cntb;
        ll cn=1;
        for(ll i=0; i<n; i++){
            lasta[v1[i]]=i;
            lastb[v2[i]]=i;
            cnta[v1[i]]++;
            cntb[v2[i]]++;

            cn=(mul(cn,(min(v1[i],v2[i])))*1LL);
        }
        vi ans;
        ans.pb(cn%mod);
        
        while(q--){
            ll o,x;
            cin>>o>>x;
            x--;

            // ll j=min(a[x-1],b[x-1]);
            // cn /= (j);

            if(o==1){
                ll h=a[x];
                ll p=lasta[h];
                cnta[h]--;
                if(cnta[h]==0){
                    lasta[h]=-1;
                }
                else{
                    lasta[h]--;
                }

                cn=mDiv(cn,min(v1[p],v2[p]))%mod;
                // cn=(cn)/(min(v1[p],v2[p]));

                v1[p]++;
                a[x]++;
                
                cnta[v1[p]]++;
                
                if(cnta[v1[p]] == 1)
                    lasta[a[x]]=p;   
                cn = (mul(cn,(min(v1[p],v2[p])))%mod);    
            }
            else{
                ll h=b[x];
                ll p=lastb[h];
                cntb[h]--;

                if(cntb[h]==0){
                    lastb[h]=-1;
                }
                else{
                    lastb[h]--;
                }

                
                cn=mDiv(cn,min(v1[p],v2[p]))%mod;
                // cn=(cn)/(min(v1[p],v2[p]));

                v2[p]++;
                b[x]++;
                
                cntb[v2[p]]++;
                
                if(cntb[v2[p]] == 1)
                    lastb[b[x]]=p;
                cn = (mul(cn,(min(v1[p],v2[p])))%mod);
            }

            // cout<<"jo ";

            ans.pb(cn);

            
            
        }

        for(auto i:ans)
            cout<<i<<' ';

        cout<<endl;    

        
    }
    return 0;
}