// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>
#define YES cout<<'Y'<<'E'<<'S'<<endl
#define NO cout<<'N'<<'O'<<endl  

const ll mod = 1e9+7;

ll mul (ll a, ll b, ll m=mod)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll LCM(ll a, ll b)
{
    
    a = (a*b)/(__gcd(a,b));
    return a;
}
bool customComparator(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
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
        ll n;
        cin>>n;
        vi a;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
        }
        set<ll>st;
        vi b(n);
        for(ll i=0; i<n; i++){
            st.insert(a[i]);
            b[i]=st.size();
        }
        ll m;cin>>m;
        for(ll i=0; i<m; i++){
            ll l,r;
            cin>>l>>r;
            ll p1=b[r-1];
            ll p2=b[l-1];
            if(p1-p2==0 && st.size()==1){
                cout<<-1<<' '<<-1<<endl;
            }
            else{
                ll h=a[l-1];
                ll nn=INT_MIN;
                for(ll j=l; j<r; j++){
                    if(a[j] != h){
                        nn=j;
                        break;
                    }
                }
                if(nn==INT_MIN){
                    cout<<-1<<' '<<-1<<endl;
                    continue;
                }
                cout<<l<<' '<<nn+1<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}

/*
2 3
-1 -1
1 3

2 1
-1 -1
4 2
4 6
5 3

1 2
1 2
2 3
3 2

1 3
2 4
3 4
5 3
5 4

1 2
4 2
1 3
2 3
3 2
5 4
5 4

*/