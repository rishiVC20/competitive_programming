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
        ll n;
        cin>>n;
        char c;
        cin>>c;
        string s;
        cin>>s;
        // cout<<c<<" "<<s<<" ";
        vi a(n+1,0);
        vi cp;
        bool f = false;
        bool p1 = false;
        bool p2 = false;
        ll mini = 3;
        ll cn = 0;
        for (ll i=0; i<n; i++){
            if (s[i]==c){
                cn++;
            }
        }
        if (cn==n){
            cout<<0<<endl;
            continue;
        }
        for (ll i=1; i<=n; i++)
        {
            // char ch = s[i];
            // if (s[i]==c)    
            //     continue;
            // if (s[i] != c){
            //     f = true;
            //     a[i+1] = 1;
            //     cp.pb(i+1);
            //     // if (i+1 % 2)
            //     //     p1 = true;
            //     // if ((i+1) % 2 ==0){
            //     //     p2 = true;  
            //     //     mini = max(mini,i);
            //     // }   
            //     // if (n%2)
            //     //     mini = n; 
            // }  
            ll cnt = 0;
            for (ll j=i; j<=n; j+=i)
            {
                cnt += (s[j-1] != c);
            }  
            if (cnt==0){
                f = true;
                cout<<1<<endl;
                cout<<i<<endl;
                break;
            }
        }       

        if (!f){
            cout<<2<<endl;
            cout<<n-1<<" "<<n<<endl;
        }
        
        // for (ll i=0; i<n; i++)
        // {
        //     if (a[i+1] &&  (i+1) % mini != 0){
        //         a[i+1] = 0;
        //         p2 = true; 
        //     }
        // }        
        // ll cn = 0;
        // for (ll i=0; i<n; i++)
        // {
        //     if (a[i+1] == 1){
        //         p1 = true;
        //         cn++;
        //         // break;
        //     }
        // }
        // if (n%2 != 0)
        //     mini = n;
        // else
        //     mini = n-1;   
        // // for (auto i:cp)
        // //     cout<<i<<" ";     
        // for (ll i=0; i<cp.size(); i++)
        // {
        //     if (cp[i]%mini  != 0){
        //         p2 = true;
        //     }
        //     else {
        //         p1 = true;
        //     }
        // }
        // // if (cn==n)
        // //     p2 = false;
        // if (p1 && !p2){
        //     cout<<1<<endl;
        //     cout<<2<<endl;
        // }
        // else if (!p1 && p2){
        //     cout<<1<<endl;
        //     cout<<mini<<endl;
        // }
        // else if (p1 && p2){
        //     cout<<2<<endl;
        //     cout<<2<<' '<<mini<<endl;
        // }
    }
    return 0;
}