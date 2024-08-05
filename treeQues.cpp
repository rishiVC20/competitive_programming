// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>
#define YES cout<<'Y'<<'E'<<'S'<<endl
#define NO cout<<'N'<<'O'<<endl  

// struct Node
// {
//     /* data */
//     ll data;
//     Node* left;
//     Node* right;
// };

struct TreeNode {
     int data;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : data(x), left(NULL), right(NULL) {}
 };

// class BST{
//     TreeNode* root;
//     TreeNode* head;
//     TreeNode *getNode(ll data);
// };

// Node *BST ::getNode(ll data)
// {
//     Node *temp = new Node;
//     temp->data = data;
//     return temp;
// }

// void createTree(TreeNode* temp, vi &a, ll st, ll end){
//     if (st==end){
//          p = temp->data;
//         return p;
//     }
//     ll mid = (st+end)/2 + 1;
//     TreeNode* q = new TreeNode(a[mid]);
// }

class btree{
public:
    TreeNode* root;

    btree(){
        root = NULL;
    }

    void inorder(TreeNode* x){
        if(x == NULL)return;

        if(x->left)inorder(x->left);
        cout<<x->data<<" ";
        if(x->right)inorder(x->right);
    }
};

TreeNode* buildTree(vi &nums, int start, int end){
        // if (start == end)
        //     return new TreeNode(nums[start]);
        if (start > end)
            return NULL;
        TreeNode* temp;
        // if (start <= end){    
            int mid = ((end-start+1)/2 + start);
            temp = new TreeNode(nums[mid]);
            temp->left = buildTree(nums, start, mid-1);
            temp->right = buildTree(nums, mid+1, end);
        // }
        return temp;        
    }

bool rec(TreeNode* x , ll req){
    if(x==NULL) return 0;

    if(x->data == req)return 1;

    bool flag1,flag2;
    flag1 = rec(x->left , req);
    flag2 = rec(x->right , req);

    if(flag1 || flag2){
        cout<<x->data<<" ";
        return 1;
    }

    return 0;
}

int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        ll x; cin>>x;
        vi a;
        int n = s.size();
        bool f=true;
        for (ll i=0; i<n; ){
            if (f){
                ll k = s[i]-'0';
                i++;
                a.pb(k);
            }
            else{
                ll k = s[i]-'0';
                i++;
                if (i==n){
                    a.pb(k);
                    break;
                }
                ll h = s[i]-'0';
                i++;
                ll q = k*10+h;
                a.pb(q);
            }
            f=!f;
        }
        sort(a.rbegin(),a.rend());
        for (auto i:a)
            cout<<i<<' ';
        cout<<endl;    

        ll sz = a.size();
        btree bt;
        bt.root = buildTree(a,0,sz-1);
        // bt.inorder(bt.root);
        // cout<<endl;

        if(bt.root ->data == x)cout<<"root"<<endl;
        else
            rec(bt.root , x);

        // vector<vector<int>>sol;
        // queue<TreeNode*>q;
        // q.push(temp);
        // bool w=true;
        // while (!q.empty()){
        //     int size = q.size();
        //     vector<int>ans(size);
        //     for (int i=0; i<size; i++){
        //         TreeNode* first = q.front();
        //         q.pop();
        //         // int in = f ? i:size-i-1;
        //         ans[i] = first->data;
        //         if (first->left)
        //             q.push(first->left);
        //         if (first->right)
        //             q.push(first->right);    
        //     }
        //     // f=!f;
        //     sol.push_back(ans);
        // }
        // for (int i=0; i<sol.size(); i++){
        //     if (!w){
        //         vector<int>kp = sol[i];
        //         reverse(kp.begin(),kp.end());
        //         sol[i] = kp;
        //     }
        //     w=!w;
        // }

        // int kk = sol.size();
        // for (int i=0; i<kk; i++){
        //     ll uu = sol[i].size();
        //     for (ll j=0; j<uu; j++){
        //         cout<<sol[i][j]<<' ';
        //     }
        //     cout<<endl;
        // }
        
    }
    return 0;
}