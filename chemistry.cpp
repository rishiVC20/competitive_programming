// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// bool check_palindrome(string s)
// {
//     ll i = 0;
//     ll j = s.size()-1;
//     while (i < j)
//     {
//         if (s[i++] != s[j--])
//             return false;
//     }
//     return true;
// }
// int main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         ll n,k;
//         cin>>n>>k;
//         string s;
//         cin >>s;
//         if (k==0)
//         {
//             if (check_palindrome(s))
//                 cout<<"YES"<<endl;
//             else
//                 cout<<"NO"<<endl;    
//         }
//         else if (k == n-1)
//             cout<<"YES"<<endl;
//         else if (k==2)
//         {   
//             ll p = 0;
//             for (ll i=0; i<s.size()-1; i++)
//             {
//                 for (ll j=i+1; j<s.size(); j++)
//                 {
//                     s.erase(s[i],1);
//                     s.erase(s[j],1);
//                     if (check_palindrome(s))
//                     {
//                         cout<<"YES"<<endl;
//                         p = 1;
//                         break;
//                     }
//                 }
//                 if (p)
//                     break;
//             }
//             if (!p)
//                 cout<<"NO"<<endl;
//         }

//     }
//     return 0;
// }

// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
bool check_palindrome(string s)
{
    ll i = 0;
    ll j = s.size()-1;
    while (i < j)
    {
        if (s[i++] != s[j--])
            return false;
    }
    return true;
}
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
            vector<ll>arr(26,0);
            for (ll i=0; i<n; i++)
            {
                arr[s[i]-'a']++;
            }
            ll count = 0; 
            for (ll i=0; i<arr.size(); i++)
            {
                if (arr[i] %2 != 0)
                    count++;
            }
            if (count > k+1)
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl; 
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1883/B