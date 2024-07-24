// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// ll count(string &s, string &sub, vector<bool> &b)
// {
//     ll count = 0;
//     ll pos = 0;
//     pos = s.find(sub,pos);
//     // cout<<pos<<" ";
//     if (sub == "map")
//     {
//         while (pos != std::string::npos )
//         {
//             if (b[pos+2])
//                 count++;
//             pos = s.find(sub,pos+sub.length());
//         }
//     }
//     else{
//         // b[pos] = false;
//         while (pos != std::string::npos)
//         {   
//             b[pos] = false;
//             count++;
//             pos = s.find(sub,pos+sub.length());
//         }
//     }
//     return count;
// }
// int main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         ll n;
//         cin>>n;
//         string s;
//         cin>>s;
//         vector<bool>b(s.size()+3,true);
//         // for (ll i=0; i<s.size(); i++)
//         //     cout<<b[i]<<" ";
//         string sub1 = "pie";
//         ll count1 = count(s,sub1,b);
//         // for (ll i=0; i<s.size(); i++)
//         //     cout<<b[i]<<" ";
//         // cout<<count1<<" ";
//         string sub2 = "map";
//         ll count2 = count(s,sub2,b);
//         // cout<<count2<<" ";
//         cout<<count1+count2<<endl;
//     }
//     return 0;
// }

// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll ans = 0;
        for (ll i=0; i<n-2; i++)
        {
            if (s[i]=='p' && s[i+1]=='i' && s[i+2]=='e'){
                ans++; 
                i+=2;
            }
            if (i+4<n && s[i]=='m' && s[i+1]=='a' && s[i+2]=='p' && s[i+3]=='i' && s[i+4]=='e'){
                ans++;  
                i+=4;
            }
            else if (s[i]=='m' && s[i+1]=='a' && s[i+2]=='p'){
                ans++;   
                i+=2;        
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

