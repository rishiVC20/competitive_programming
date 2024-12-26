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

void build(ll ind, ll l, ll r){
    if(l == r){
        t[ind].sum=0;
        return;
    }

    ll mid=(l+r)/2;
    build(2*ind+1,l,mid);
    build(2*ind+2,mid+1,r);

    t[ind] = merge(t[2*ind+1],t[2*ind+2]);
}

void update(ll ind, ll l, ll r, ll pos, ll val){
    if(pos<l || pos>r)
        return;

    if(l==r){
        t[ind].sum+=val;
        return;
    }    

    ll mid=(l+r)/2;
    update(2*ind+1,l,mid,pos,val);
    update(2*ind+2,mid+1,r,pos,val);

    t[ind]=merge(t[2*ind+1],t[2*ind+2]);
}

node query(ll ind, ll l, ll r, ll lq, ll rq){
    if(l>rq || r<lq)
        return  node();

    if(l>=lq && r<=rq){
        return t[ind];
    }

    ll mid=(l+r)/2;

    return merge(query(2*ind+1,l,mid,lq,rq),query(2*ind+2,mid+1,r,lq,rq));
}

int main() {
    ll tt=1;
    // cin>>tt;
    while (tt--)
    {
        ll n,q;
        cin>>n>>q;

        vi a;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
        }

        build(0,0,n-1);

        while(q--){
            ll ch;
            cin>>ch;

            if(ch==1){
                ll a,b,u;
                cin>>a>>b>>u;
                a--,b--;

                update(0,0,n-1,a,u);
                update(0,0,n-1,b+1,-u);
            }
            else{
                ll k;
                cin>>k;
                k--;

                node ans=query(0,0,n-1,0,k);

                cout<<ans.sum+a[k]<<endl;
            }
        }
    }
    return 0;
}