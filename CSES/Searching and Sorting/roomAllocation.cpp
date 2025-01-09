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

class Disjoint{
    vector<ll>size,rank,parent;
public:
    Disjoint(ll n){
        size.resize(n+1,1);
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(ll i=0; i<=n; i++)
            parent[i]=i;
    }
    ll findParent(ll node){
        if(node==parent[node])
            return node;
        return parent[node]=(findParent(parent[node]));
    }
    void unionByRank(ll u, ll v){
        ll ulp_u=findParent(u);
        ll ulp_v=findParent(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(ll u, ll v){
        ll ulp_u=findParent(u);
        ll ulp_v=findParent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
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
bool customComparator(const tuple<ll,ll,ll>&a, const tuple<ll,ll,ll>&b)
{
    if(get<0>(a) == get<0>(b))
        return get<1>(a) < get<1>(b);
    return get<0>(a) < get<0>(b);
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
    ll tt=1;
    // cin>>tt;
    while (tt--)
    {
        ll n;
        cin>>n;
        // cout<<"ji";
        vector<tuple<ll,ll,ll>>v;

        for(ll i=0; i<n; i++){
            ll x,y;cin>>x>>y;
            v.pb({x,y,i});
        }   

        sort(v.begin(),v.end(),customComparator);

        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
        vi d(n);

        ll cn=0;
        for(ll i=0; i<n; i++){
            if(pq.empty()){
                pq.push({get<1>(v[i]),++cn});
                d[i]=cn;
                // cout<<"4 ";
                continue;
            }
            // cout<<"hi";
            auto fr=pq.top();

            if(fr.first < get<0>(v[i])){
                // cout<<"1 ";
                ll j=fr.second;
                pq.pop();
                pq.push({get<1>(v[i]),j});
                d[i]=j;
            }
            else{
                // cout<<"2 ";
                pq.push({get<1>(v[i]),++cn});
                d[i]=cn;
            }
        }

        vi ans(n);
        ll maxi=1;
        for(ll i=0; i<n; i++){
            ans[get<2>(v[i])]=d[i];
            maxi=max(maxi,d[i]);
        }

        cout<<maxi<<endl;
        for(auto i:ans)
            cout<<i<<" ";
        cout<<endl;    

        // for(ll i=0; i<v.size(); i++){
        //     cout<<get<0>(v[i])<<' '<<get<1>(v[i])<<' '<<get<2>(v[i])<<endl;
        // }
 
        // vector<tuple<ll,ll,ll>>mrg;
        // // queue<ll>q;
        // priority_queue<ll,vi,greater<ll>>q;
        // mrg.pb({get<0>(v[0]),get<1>(v[0]),1});
        // q.push(get<1>(mrg[0]));
        // for(ll i=1; i<n; i++){
        //     if(get<0>(v[i]) <= get<1>(mrg.back()) && (!q.empty() && q.top() >= get<0>(v[i]))){
        //         // cout<<"1 ";
        //         // mrg.back().second=max(mrg.back().second,v[i].second);
        //         get<1>(mrg.back())=max(get<1>(mrg.back()),get<1>(v[i]));
        //         get<2>(mrg.back())=get<2>(mrg.back())+1;
        //         q.push(get<1>(v[i]));
        //     }
        //     else{
        //         // cout<<"2 ";
        //         while(!q.empty() && q.top() < get<0>(v[i])){
        //             q.pop();
        //         }
        //         mrg.pb({get<0>(v[i]),get<1>(v[i]),1});
        //         q.push(get<1>(v[i]));
        //     }
        // }
        // cout<<endl;

        // ll cn=1;
        // for(ll i=0; i<mrg.size(); i++){
        //     cn=max(cn,get<2>(mrg[i]));
            // cout<<get<0>(mrg[i])<<' '<<get<1>(mrg[i])<<' '<<get<2>(mrg[i])<<endl;
        // }

        // for(ll i=0; i<mrg.size(); i++){
        //     cout<<get<0>(mrg[i])<<' '<<get<1>(mrg[i])<<' '<<get<2>(mrg[i])<<endl;
        // }

        // cout<<cn<<endl;
        // vi ans(n);
        // ll t=0;
        // for(ll i=0; i<mrg.size(); i++){
        //     ll j=1;
        //     for(ll k=0; k<get<2>(mrg[i]); k++){
        //         // cout<<j<<' ';
        //         // cout<<get<2>(v[t])<<' ';
        //         ans[get<2>(v[t])]=j;
        //         t++;
        //         j++;
        //     }
        // }

        // for(ll i=0; i<v.size(); i++){
        //     cout<<get<0>(v[i])<<' '<<get<1>(v[i])<<' '<<get<2>(v[i])<<endl;
        // }
        // for(ll i=0; i<ans.size(); i++)
        //     cout<<ans[i]<<' ';

        // cout<<endl;

        // priority_queue<ll,vi,greater<ll>>pq;
        // queue<ll>q;
        // q.push(v[0].second);
        // cout<<q.size()<<' ';
        // for(ll i=1; i<v.size(); i++){
        //     if(q.front() < v[i].first){
        //         while(!q.empty() && q.front() <= v[i].first){
        //             q.pop();
        //         }
        //         q.push(v[i].second);
        //     }
        //     else{
        //         q.push(v[i].second);
        //         cout<<q.size()<<' ';
        //     }
            
        // }

        // cout<<endl;


    }
    return 0;
}