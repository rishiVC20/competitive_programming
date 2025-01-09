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
    
public:
vector<ll>size,rank,parent;
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



// ll getSize(ll node) {
//     return node.pa;
// }

int main() {
    ll tt;
    cin>>tt;
    while (tt--)
    {
        ll n;
        cin>>n;

        vi a;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            x--;
            a.pb(x);
        }

        Disjoint d(n);
        set<ll>st;

        for(ll i=0; i<n; i++){
            // if(st.find(a[i]) == st.end()){
                d.unionBySize(a[i],a[a[i]]);
                // st.insert(a[i]);
                // st.insert(a[a[i]]);
            // }
            
        }

        
        vi b;
        set<ll>k;
        for(auto i:a){
            // cout<<d.findParent(i)<<' ';
            // cout<<d.size[d.findParent(i)]<<' ';
            if(k.find(d.findParent(i)) == k.end()){
                // cout<<"hio ";
                // cn += d.size[i];
                // b.pb(d.size[i]);
                b.pb(d.size[d.findParent(i)]);
                // cout<<d.size[i]<<' ';
                k.insert(d.findParent(i));
            }
        }
        // for(auto i:b)
        //     cout<<i<<' ';
        

        if(b.size()==1){
            // cout<<"k";
            cout<<0<<endl;
            continue;
        }

        sort(b.begin(),b.end());
        priority_queue<ll,vi,greater<ll>>pq;
        for(auto i:b){
            pq.push(i);
        }

        vi z;
        while(pq.size() > 1){
            ll v1=pq.top();
            pq.pop();
            ll v2=pq.top();
            pq.pop();
            pq.push(v1+v2);
            z.pb(v1+v2);
        }
        // z.pb(pq.top());
        // ll cn=b[0]+b[1];
        // vi c;
        // c.pb(cn);
        // for(ll i=2; i<b.size(); i++){
        //     ll m= (b[i]+c.back());
        //     c.pb(m);
        //     // cout<<i<<' ';
        // }

        // cn+=accumulate(b.begin(),b.end(),0LL);
        // cout<<c.size()<<"h ";
        ll j=0;
        for(auto i:z){
            j+=i;
            // cout<<i<<' ';
        }

        cout<<j<<endl;
        // ll cn=accumulate(b.begin(),b.end(),0LL);

        // cout<<cn<<endl;
    }
    return 0;
}