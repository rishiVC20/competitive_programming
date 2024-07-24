// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// int main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         ll n;
//         cin>>n;
//         string s;
//         cin>>s;
//         set<ll>st;
//         ll curr = 1;
//         st.insert(1);
//         for (ll i=0; i<n; i++)
//         {
//             if (s[i]=='<')
//                 curr++;
//             else
//                 curr--;
//             cout<<curr<<" ";
//             // cout<<endl;    
//             st.insert(curr);        
//         }       
//         cout<<st.size()<<endl;
//     }
//     return 0;
// }


// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// int main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         ll n;
//         cin>>n;
//         string s;
//         cin>>s;
//         ll count = 1;
//         ll maxi = 1;
//         for (ll i=1; i<n; i++)
//         {
//             if (s[i]==s[i-1])
//             {
//                 count++;
//                 // maxi = max(maxi,count);
//             }
//             else{ 
//                 count = 1;
//             }
//             maxi = max(maxi,count);
//         }
//         cout<<maxi+1<<endl;
//     }
//     return 0;
// }
/*
3
3
6
2

*/


// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// int main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         vector<ll>arr(3);
//         for (ll i=0; i<3; i++)
//             cin>>arr[i];
//         // sort(arr.begin(),arr.end());
//         if ((arr[0]+arr[1]==arr[2]) )
//             cout<<'+'<<endl;
//         else if ((arr[0]-arr[1])==arr[2] || (arr[0]-arr[2]==arr[1]) || (arr[1]-arr[2]==arr[0]) || (arr[1]-arr[0])==arr[2] || (arr[2]-arr[0]==arr[1]) || (arr[2]-arr[1]==arr[0]))
//             cout<<'+'<<endl;    
//         else
//             cout<<'-'<<endl;               
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
        ll a,b,c;
        cin>>a>>b>>c;
        if ((a+b)==c )
            cout<<'+'<<endl;
        else if ((a-b)==c)
            cout<<'-'<<endl;    
    }
    return 0;
}

/*
+
-
-
+
+
-
+
+
-
-
+

*/