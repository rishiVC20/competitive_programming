#include <bits/stdc++.h>
using namespace std;


#define all(v) v.begin(), v.end()
#define sorti(v) sort(all(v))
#define rsorti(v) sort(v.rbegin(), v.rend())
#define MAXI(a) (*std::max_element((a).begin(), (a).end()))
#define MINI(a) (*std::min_element((a).begin(), (a).end()))
#define pp pair<int, int>
#define ff first
#define ss second
#define cy cout << "Yes" << endl
#define cn cout << "No" << endl
#define cinall(v)     \
    for (auto &i : v) \
    {                 \
        cin >> i;     \
    }

#define coutall(v)        \
    for (auto &i : v)     \
    {                     \
        cout << i << " "; \
    }                     \
    cout<<endl

#define ll long long
#define ld long double
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define pb push_back
#define ppb pop_back
#define read(a)       \
    for (auto &i : a) \
    cin >> i
#define gcd __gcd

const ll mod = 1000007;



int main()
{   
    
    // prenCr();  
    ios::sync_with_stdio(0);
    cin.tie(0);  
    int tc = 1;
    cin >> tc;
    while(tc--){
        ll n,k;
        cin>>n>>k;
        vector<ll> vec(n);
        cinall(vec);
        sorti(vec);

        vector<ll> ans(n+1);
        ans[0] = 0;
        vector<ll> prefix(n+1);
        prefix[0] = 0;
        for(int i=1;i<=n;i++){
            prefix[i] = prefix[i-1] + vec[i-1];
        }
        for(int i=0;i<k;i++){
            ans[i+1] = prefix[i+1];
        }
        for(int i=k;i<n;i++){
            int ansi = prefix[i+1] - prefix[i+1-k];
            ansi += ans[i-k];
            ans[i+1] = ansi;
        }

        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}

/* 


*/