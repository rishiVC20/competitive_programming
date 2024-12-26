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

// class Disjoint{
//     vector<ll>size,rank,parent;
// public:
//     Disjoint(ll n){
//         size.resize(n+1,1);
//         parent.resize(n+1);
//         rank.resize(n+1,0);
//         for(ll i=0; i<=n; i++)
//             parent[i]=i;
//     }
//     ll findParent(ll node){
//         if(node==parent[node])
//             return node;
//         return parent[node]=(findParent(parent[node]));
//     }
//     void unionByRank(ll u, ll v){
//         ll ulp_u=findParent(u);
//         ll ulp_v=findParent(v);
//         if(ulp_u == ulp_v) return;
//         if(rank[ulp_u]<rank[ulp_v]){
//             parent[ulp_u]=ulp_v;
//         }
//         else if(rank[ulp_u]>rank[ulp_v]){
//             parent[ulp_v]=ulp_u;
//         }
//         else{
//             parent[ulp_v]=ulp_u;
//             rank[ulp_u]++;
//         }
//     }
//     void unionBySize(ll u, ll v){
//         ll ulp_u=findParent(u);
//         ll ulp_v=findParent(v);
//         if(ulp_u == ulp_v) return;
//         if(size[ulp_u]<size[ulp_v]){
//             parent[ulp_u]=ulp_v;
//             size[ulp_v]+=size[ulp_u];
//         }
//         else{
//             parent[ulp_v]=ulp_u;
//             size[ulp_u]+=size[ulp_v];
//         }
//     }
// };
// ll mul (ll a, ll b, ll m=mod)
// {
//     a = a % m;
//     b = b % m;
//     return (((a * b) % m) + m) % m;
// }
// ll LCM(ll a, ll b)
// {
    
//     a = (a*b)/(__gcd(a,b));
//     return a;
// }
// bool customComparator(const pair<int, int> &a, const pair<int, int> &b)
// {
//     return a.second < b.second;
// }
// ll power(ll base, ll exponent)
// {
//     if (exponent < 0)
//     {
//         return 0;
//     }
//     ll ans = 1;
//     while (exponent)
//     {
//         if (exponent%2==0)
//         {
//             base = (base*base) % mod;
//             exponent = exponent/2;
//         }
//         else
//         {
//             ans = (ans*base) % mod;
//             exponent--;
//         }
//     }
//     return ans;
// }
// void build(ll ind, ll low, ll high, vi a, vi &seg){
//     if(low==high){
//         seg[ind]=a[low];
//         return;
//     }

//     ll mid=(low+high)/2;

//     build(2*ind+1,low,mid,a,seg);    
//     build(2*ind+2,mid+1,high,a,seg);

//     seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);    

// }

// ll query(ll ind, ll low, ll high, ll l, ll r, vi seg){
    
//     if(low>=l && high<=r){
//         return seg[ind];
//     }
    
//     if(high<l || low>r){
//         return 0;
//     }

//     ll mid=(low+high)/2;
//     ll left=query(2*ind+1,low,mid,l,r,seg);
//     ll right=query(2*ind+2,mid+1,high,l,r,seg);

//     return left+right;
// }
struct node{
    ll sum;
    node(){
        sum=0;
    }
};
node t[4*200000];

node merge(node a, node b){
    node ans;
    ans.sum=a.sum+b.sum;

    return ans;
}

void build(ll ind, ll l, ll r, vi &a){
    if(l == r){
        // t[ind].sum=0;
        t[ind].sum=a[l];
        return;
    }

    ll mid=(l+r)/2;
    build(2*ind,l,mid,a);
    build(2*ind+1,mid+1,r,a);

    t[ind] = merge(t[2*ind],t[2*ind+1]);
}

void update(ll ind, ll l, ll r, ll pos, ll val){
    if(pos<l || pos>r)
        return;

    if(l==r){
        t[ind].sum=val;
        return;
    }    

    ll mid=(l+r)/2;
    update(2*ind,l,mid,pos,val);
    update(2*ind+1,mid+1,r,pos,val);

    t[ind]=merge(t[2*ind],t[2*ind+1]);
}

node query(ll ind, ll l, ll r, ll lq, ll rq){
    if(l>rq || r<lq)
        return  node();

    if(l>=lq && r<=rq){
        return t[ind];
    }

    ll mid=(l+r)/2;

    return merge(query(2*ind,l,mid,lq,rq),query(2*ind+1,mid+1,r,lq,rq));
}

int main() {
    ll tt=1;
    // cin>>tt;
    while (tt--)
    {
        ll n,q;
        cin>>n>>q;

        vi a;
        a.pb(0);
        for(ll i=1; i<=n; i++){
            ll x;cin>>x;
            a.pb(x);
        }


        build(1,1,n,a);

        while(q--){
            ll ch;
            cin>>ch;

            if(ch==1){
                ll k,u;
                cin>>k>>u;
                update(1,1,n,k,u);
            }
            else{
                // for(ll i=1; i<=n; i++){
                //     cout<<t[i].sum<<' ';
                // }
                ll a,b;
                cin>>a>>b;

                node ans=query(1,1,n,a,b);

                cout<<ans.sum<<endl;
            }
        }


    }
    return 0;
}