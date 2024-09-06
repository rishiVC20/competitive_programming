// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>
#define YES cout<<'Y'<<'E'<<'S'<<endl
#define NO cout<<'N'<<'O'<<endl  

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
int main() {
    Disjoint ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    cout<<ds.findParent(1)<<' ';
    cout<<ds.findParent(2)<<' ';
    cout<<ds.findParent(3)<<' ';
    cout<<ds.findParent(4)<<' ';
    cout<<ds.findParent(5)<<' ';
    cout<<ds.findParent(6)<<' ';
    cout<<ds.findParent(7)<<' ';
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    cout<<ds.findParent(3)<<' '<<ds.findParent(7)<<' ';
    if(ds.findParent(3)==ds.findParent(7)){
        
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Not Same"<<endl;
    }
    ds.unionByRank(3,7);
    cout<<ds.findParent(3)<<' '<<ds.findParent(7)<<' ';
    if(ds.findParent(3)==ds.findParent(7)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Not Same"<<endl;
    }
    cout<<ds.findParent(1)<<' ';
    cout<<ds.findParent(2)<<' ';
    cout<<ds.findParent(3)<<' ';
    cout<<ds.findParent(4)<<' ';
    cout<<ds.findParent(5)<<' ';
    cout<<ds.findParent(6)<<' ';
    cout<<ds.findParent(7)<<' ';
    return 0;
}


