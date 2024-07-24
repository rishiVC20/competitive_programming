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

bool checkPalin(vi &a)
{
    ll i=0, j=a.size()-1;
    while (i <= j)
    {
        if (a[i] != a[j])
            return false;
        i++;
        j--;  
    }

    return true;
}

ll pointeri(vi &a)
{
    ll i=0, j=a.size()-1;
    while (i <= j)
    {
        if (a[i] != a[j])
            return a[i];
        i++;
        j--;  
    }

    // return true;
}

ll pointerj(vi &a)
{
    ll i=0, j=a.size()-1;
    while (i <= j)
    {
        if (a[i] != a[j])
            return a[j];
        i++;
        j--;    
    }

    // return true;
}
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        vi a;
        for (ll i=0; i<n; i++)
        {
            ll x; cin>>x;
            a.pb(x);
        }       
        if (n<=1){
            cout<<"YES"<<endl;
            continue;
        }
        // ll p1=-1, p2=-1;
        // bool c = false;
        // for (ll i=0; i<n-1; i++)
        // {
        //     for (ll j=i+1; j<n; j++)
        //     {
        //         if (a[i] == a[j])
        //         {
        //             p1 = i;
        //             p2 = j;
        //             c = true;
        //             break;
        //         }
        //     }
        //     if (c)
        //         break;
        // }
        // cout<<p1<<" "<<p2<<" ";
        // ll k;
        
        // bool f = true;
        // if (p1==-1 || p2==-1){
        //     cout<<"NO"<<endl;
        //     continue;
        // }
        
        // else{
        //     if (p2-p1 == 2){
        //         k = a[p1+1];
        //         for (ll i=0; i<p1; i++){
        //             if (a[i] != k){
        //                 f = false;
        //             } 
        //         }
        //     }
        //     else if (p2-p1 > 2){
        //         k = a[p1+1];
        //         for (ll i=p1+1; i<p2-1; i++){
        //             if (a[i]!=a[i+1]){
        //                 f = false;
        //                 break;
        //             }
        //         }
        //         if (f){
        //             for (ll i=0; i<p1; i++){
        //                 if (a[i]!=k){
        //                     f = false;
        //                 }
        //             }
        //             for (ll i=p2; i<n; i++){
        //                 if (a[i]!= k){
        //                     f = false;
        //                 }
        //             }
        //         }
        //     }
        // }
        // if (f)
        //     cout<<"YES"<<endl;
        // else
        //     cout<<"NO"<<endl;   

        bool cp = checkPalin(a);
        if (cp){
            cout<<"YES"<<endl;
            continue;
        }

        vi ii = a;
        vi jj = a;
        ll seei = pointeri(a);
        ll seej = pointerj(a);


        ii.erase(remove(ii.begin(),ii.end(),seei),ii.end());
        jj.erase(remove(jj.begin(),jj.end(),seej),jj.end());
        // for (ll i=0; i<n; i++)
        // {
        //     a.erase()
        // }

        bool p1 = checkPalin(ii);
        bool p2 = checkPalin(jj);

        if (p1 || p2)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;    
    }
    return 0;
}

// vec.erase(std::remove(vec.begin(), vec.end(), 22), vec.end());