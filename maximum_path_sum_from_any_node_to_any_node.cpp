#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

struct Node{
    ll data; 
    struct Node* left; 
    struct Node* right;

    Node(ll val) 
    { 
        data = val; 
        left = NULL; 
        right = NULL; 
    } 
}; 


ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a, ll b)
{
    return a*b/gcd(a,b);
}

ll solve(Node* root, ll &res){
    if(root == NULL) return 0;

    ll l = solve(root->left, res);
    ll r = solve(root->right, res);
    ll temp = max ( max(l,r) + root->data , root->data);
    ll ans = max( temp, l+r+root->data);
    res = max( res, ans);

    return temp;
}

int main()
{
    ios::sync_with_stdio(0);    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
        {
            struct Node* root = new Node(1);
            root->left = new Node(2);    
            root->left->left = new Node(-1);    
            root->left->left->left = new Node(-4);    
            root->left->left->right = new Node(-37);
            root->left->left->right->right = new Node(2);
            root->left->right = new Node(-14);
            root->left->right->right = new Node(-5);
            root->left->right->right->right = new Node(-52);
            root->left->right->right->right->right = new Node(3);
            root->right = new Node(30);
            root->right->right = new Node(7);

            ll res = INT_MIN;
            solve(root,res);
            cout<<res<<"\n";
        }
    return 0;
}