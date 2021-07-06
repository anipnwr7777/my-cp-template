#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a, ll b)
{
    return a*b/gcd(a,b);
}

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

ll solve(Node *root, ll &res){
    if(root == NULL) return 0;

    ll l = solve(root->left, res);
    ll r = solve(root->right, res);

    ll temp = max(l,r) + 1;
    ll ans = 1+l+r;
    res = max( res , ans);

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
            root->left->left = new Node(3);    
            root->left->left->left = new Node(4);    
            root->left->left->right = new Node(5);
            root->left->left->right->right = new Node(6);
            root->left->right = new Node(7);
            root->left->right->right = new Node(8);
            root->left->right->right->right = new Node(9);
            root->left->right->right->right->right = new Node(10);
            root->right = new Node(11);
            root->right->right = new Node(12);

            ll res = 0;
            solve(root,res);
            cout<<res<<"\n";
        }
    return 0;
}