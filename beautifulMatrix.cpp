// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    // ll t;
    // cin>>t;
    // while (t--){
        // vector<int>arr;
        int arr[5][5];
        ll ans=0;
        int x;
        for (int i=0; i<5; i++){
            for (int j=0; j<5; j++){  
                cin>>arr[i][j];
                
            }
        }
        for (int i=0; i<5; i++){
            for (int j=0; j<5; j++){
                if (arr[i][j]==1){
                    ans = abs(j-2)+abs(i-2);    
                    break;  
                }
            }
        }
        cout<<ans<<endl;
    // }   
    return 0;
}

//https://codeforces.com/problemset/problem/263/A