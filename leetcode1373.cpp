#include<bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define ld long double
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<long long,long long>
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vvi vector<vector<int>>
#define f(i,n) for(int i=0;i<n;++i)
#define inp(i,n,arr) for(long long i=0;i<n;++i) cin>>arr[i]
vector<int> dx = {-1,0,1,0};
vector<int> dy = {0,1,0,-1};
#define MOD 1000000007


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
using ll = long long;
class Solution {
pair<ll,pair<ll,ll>> solve(TreeNode *root,ll &maxim){   // {sum,{minVal,maxVal}};
    if(!root) return {0,{INT_MAX,INT_MIN}};
    if(!root->left && !root->right){
        maxim = max((ll)root->val,maxim);
        return {root->val,{root->val,root->val}};
    }
    pair<ll,pair<ll,ll>> l = solve(root->left,maxim);
    pair<ll,pair<ll,ll>> r = solve(root->right,maxim);
    if(l.second.second < root->val && root->val < r.second.first){
        ll sum = l.first+r.first+root->val;
        maxim = max(maxim,sum);
        ll minVal = min((ll)l.second.first,(ll)root->val);
        ll maxVal = max((ll)r.second.second,(ll)root->val);
        return {sum,{minVal,maxVal}};
    }
    return {0LL,{INT_MIN,INT_MAX}};
}
public:
    int maxSumBST(TreeNode* root) {
        ll maxim = 0;
        pair<ll,pair<ll,ll>> val = solve(root,maxim);
        return maxim;
    }
};

void solve(){
   
}

int main(){
    fastio;

    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}