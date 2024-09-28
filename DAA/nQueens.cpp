#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool check(ll row, ll col, vector<vector<string>>&v){
    ll x=row,y=col;
    ll n=v.size();
    //left
    while (y>=0){
        if (v[x][y]=="Q")
            return false;
        y--;    
    }
    x=row,y=col;
    //upper left
    while(x>=0 && y>=0){
        if (v[x][y]=="Q")   
            return false;
        x--, y--;    
    }
    x=row,y=col;
    //lower left
    while (x<n && y>=0){
        if (v[x][y]=="Q")   
            return false;
        x++, y--;    
    }

    return true;
}
void putAns(vector<vector<string>>&v, vector<vector<string>>&ans){
    vector<string>d;
    ll n=v.size();
    for (ll i=0; i<n; i++){
        string s="";
        for (ll j=0; j<n; j++){
            s += v[i][j]+" ";
        }
        d.push_back(s);
    }

    ans.push_back(d);
}
void print(vector<vector<string>>&v){
    ll n=v.size();
    for (ll i=0; i<n; i++){
        for (ll j=0; j<n; j++){
            cout<<v[i][j]<<' ';
        }
        
        // cout<<endl;
        cout<<endl;
    }
}
void solve(ll col, vector<vector<string>>&v, vector<vector<string>>&ans, ll n){
    if (col==n){
        putAns(v,ans);
        return;
    }

    bool f=false;
    for (ll i=0; i<n; i++){
        if (check(i,col,v)){
            f=true;
            cout<<"For queen "<<col+1<<endl;
            
            v[i][col]="Q";
            print(v);
            if (col+1 == n)
                cout<<"Solution found"<<endl;
            solve(col+1,v,ans,n);
            v[i][col]=".";
        }
    }
    if (!f){
        cout<<"Unable to place queen "<<col+1<<endl;
        print(v);
    }
}
int main(){
    ll n;
    cin>>n;
    vector<vector<string>>v(n,vector<string>(n,"."));
    vector<vector<string>>ans;
    solve(0,v,ans,n);
    // for (ll i=0; i<n; i++){
    //     for (ll j=0; j<n; j++){
    //         cout<<ans[i][j]<<endl;
    //     }
    //     cout<<endl;
    //     cout<<endl;
    // }

}