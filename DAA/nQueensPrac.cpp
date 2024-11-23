#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isSafe(ll row, ll col, vector<vector<string>>v, ll n){
    ll x=row,y=col;

    while(y >= 0){
        if(v[x][y]=="Q")
            return false;
        y--;    
    }
    x=row,y=col;
    while(x>=0 && y>=0){
        if(v[x][y]=="Q")
            return false;
        x--,y--;    
    }
    x=row,y=col;
    while(x<n && y>=0){
        if(v[x][y]=="Q")
            return false;
        x++,y--;    
    }

    return true;
}
void putAns(vector<vector<string>>&v, vector<vector<string>>&ans){
    vector<string>d;

    for(ll i=0; i<v.size(); i++){
        string s="";
        for(ll j=0; j<v[0].size(); j++){
            s += v[i][j]+" ";
        }
        d.push_back(s);
    }

    ans.push_back(d);
}
void solve(ll col, vector<vector<string>>&v, vector<vector<string>>&ans, ll n){
    if(col == n){
        putAns(v,ans);
        return;
    }

    for(ll i=0; i<n; i++){
        if(isSafe(i,col,v,n)){
            v[i][col]="Q";
            solve(col+1,v,ans,n);
            v[i][col]=".";
        }
    }
}
void solve2(ll col, vector<vector<string>>&v, vector<vector<string>>&ans, ll n, vector<bool>&x, vector<bool>&y, vector<bool>&z){
    if(col==n){
        putAns(v,ans);
        return;
    }

    for(ll i=0; i<n; i++){
        if(!x[i] && !y[i+col] && !z[(n-1)+(col-i)]){
            v[i][col]="Q";
            x[i]=true;
            y[i+col]=true;
            z[(n-1)+(col-i)]=true;
            solve2(col+1,v,ans,n,x,y,z);
            v[i][col]=".";
            x[i]=false;
            y[i+col]=false;
            z[(n-1)+(col-i)]=false;
        }
    }
}
int main(){
    ll n;
    cout<<"Enter the number of Queens to be placed: ";
    cin>>n;
    cout<<endl;
    vector<vector<string>>v(n,vector<string>(n,"."));
    vector<vector<string>>ans;

    vector<bool>x(n,false);
    vector<bool>y(2*n-1,false);
    vector<bool>z(2*n-1,false);
    // solve(0,v,ans,n);
    solve2(0,v,ans,n,x,y,z);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[0].size(); j++){
            cout<<ans[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
    }

    cout<<endl;

}