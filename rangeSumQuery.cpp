#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin>>n>>q;
    vector<int>ans;
    for (int i =0; i<n; i++)
    {
        cin>>ans[i];
    }
    int l,r;
    vector<int>summation;
    for (int i=0; i<q; i++)
    {
        cin>>l;
        cin>>r;
        int result = 0;
        do{
            result += ans[l-1];
            l++;
        }
        while (l != r);
        summation.push_back(result);
    }
    for (int i=0; i<q; i++)
    {
        cout<<summation[i]<<endl;
    }
    
    return 0;
}