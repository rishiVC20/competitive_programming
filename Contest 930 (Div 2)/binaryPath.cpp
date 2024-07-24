// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// ll countPaths(string &s1,string &s2,string &s3,string &s4)
// {
//     ll count = 1;
//     for (ll i=0; i<s1.size()-2; i++)
//     {
//         if (s1[i]=='1' && s2[i]=='0')
//             count++;
//     }
//     for (ll i=0; i<s1.size()-2; i++)
//     {
//         if ((s1[i]=='0' && s2[i]=='0') && s1[i+1]=='0')
//             count+=2;
//     }
//     for (ll i=0; i<s1.size()-1; i++)
//     {
//         if ((s1[i]=='1' && s2[i]=='1') && (s1[i+1]=='1' && s2[i+1]=='0'))
//             count++;
//     }
//     for (ll i=0; i<s1.size()-2; i++)
//     {
//         if ((s1[i]=='0' && s2[i]=='0') && s1[i+1]=='1')
//             count++;
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
//         string s1,s2;
//         cin>>s1>>s2;
//         string s3;
//         ll p = 0;
//         bool flag = true;
//         for (ll i=0; i<n; i++){
//             if (s2[i]=='0' && s1[i]=='1'){
//                 p=i;
//                 flag = false;
//                 break;
//             }
//         }
//         bool k = true;
//         for (ll i=0; i<n; i++)
//         {
//             if (s1[i]=='0' && s2[i]=='0')
//                 continue;
//             else{
//                 k = false;
//                 break;
//             }    
//         }
//         // if (k)
//         // {
//         //     cout<<s1<<endl;
//         //     cout<<n<<endl;
//         //     continue;
//         // }
//         string s4 = "";
//         if (flag)
//         {
//             s3 = s1.substr(0,n);
//             s4 = s4+s3;
//             // s3 = s2.substr(n-1);
//             s4 = s4+s2[n-1];
//         }
//         else{
//             s3 = s1.substr(0,p);
//             s4 = s4+s3;
//             s3 = s2.substr(p-1,n-1);
//             s4 = s4+s3;
//         }
//         // ll count = countPaths(s1,s2,s3,s4);
//         cout<<s4<<endl;
//         ll a = s4.size()-1;
//         ll b = s2.size()-1;
//         ll cnt=0;
//         while (true)
//         {
//             if (s4[a--] == s2[b--])
//                 cnt++;
//             else
//                 break;    
//         }
//         cout<<cnt<<endl;
//         // if (k)
//         // {
//         //     cout<<n<<endl;
//         //     continue;
//         // }
//         // cout<<count<<endl;
//         // cout<<s4.size()-1<<endl;
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
        string s1,s2;
        cin>>s1>>s2;
        ll i=0;
        while (i<n-1 && s1[i+1]<=s2[i])
            i++;
        string ans="";
        string s3 = s1.substr(0,i+1);
        ans += s3;
        s3 = s2.substr(i);
        ans += s3;
        cout<<ans<<endl;    
        ll j=i; 
        ll cnt = 1;
        while (j>0 && s2[j-1]==s1[j]){
            cnt++;
            j--;
        }   
        cout<<cnt<<endl;
    }
    return 0;
}