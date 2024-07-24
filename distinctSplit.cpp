// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
bool check (string &s, char &p)
{
    // cout<<s<<" ";
    for (ll i=0; i<s.size(); i++)
    {
        // cout<<"hi"<<" ";
        if (s[i] == p)
            return true;
    }
    return false;
}
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        string a = "";       
        string b = "";
        bool flag = false;
        vector<ll>ar(27,0);
        vector<ll>br(27,0);
        for (ll i=0; i<n-1; i++)
        {
            char p = s[i];

            if (ar[p-'a'] != 0 )
                flag = true;
            // cout<<flag<<" ";
            if (flag){
                b += p;
                br[p-'a']++;
            }
            else{
                a += p;
                ar[p-'a']++; 
            }       
        }  
            b+=s[n-1];
            br[s[n-1] - 'a']++;

        // cout<<a<<" "<<b<<" ";
        ll count = 0;
        for (auto i:ar){
            if (i!=0)
                count++;
        }
        for (ll i:br){
            if (i!=0)
                count++;
        }
        cout<<count<<endl;
        
    }
    return 0;
}






9
8
10
6
4
2
9
2
6
5
7
10
9
3
10
4
4
5
8
4
2
6
9
8
5
8
10
8
6
10
9
6
6
2
6
9
7
5
3
8
9
7
3
6
5
8
7
7
7
9
4
8
6
4
3
2
2
4
3
8
8
10
5
10
2
2
8
4
2
7
5
9
3
10
4
8
10
2
5