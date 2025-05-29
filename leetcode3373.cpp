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

class Solution {
void dfs(int index,int parent,vector<vector<int>> &adj,vector<vector<int>> &ans){
    ans[index][1] += 0;
    ans[index][0] += 1;
    for(auto neigh: adj[index]){
        if(neigh == parent) continue;
        dfs(neigh,index,adj,ans);
        ans[index][1] += ans[neigh][0];
        ans[index][0] += ans[neigh][1];
    }
}

void dfs2(int index,int parent,vector<vector<int>> &adj,vector<vector<int>> &ans1,vector<vector<int>> &ans,int evenAbove,int oddAbove){
    ans[index][1]  = ans1[index][1]+evenAbove;
    ans[index][0] = ans1[index][0]+oddAbove;
    for(auto neigh: adj[index]){
        if(neigh == parent ) continue;
        int even =ans[index][1]-ans1[neigh][0];
        int odd = ans[index][0]-ans1[neigh][1];
        dfs2(neigh,index,adj,ans1,ans,odd,even);
    }
}
vector<vector<int>> helper_solve(vector<vector<int>> &edges){
    int n = 1 + edges.size();
    vector<vector<int>> adj(n);
    for(auto &vec: edges){
        int u = vec[0],v  = vec[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> ans1(n,vector<int>(2,0)),ans(n,vector<int>(2,0));
    dfs(0,-1,adj,ans1);
    dfs2(0,-1,adj,ans1,ans,0,0);
    return ans;
}
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<vector<int>> ans1 = helper_solve(edges1);
        vector<vector<int>> ans2 = helper_solve(edges2);

        // for(auto &vec: ans1){
        //     cout<<vec[0]<<" "<<vec[1]<<endl;
        // }
        int maxim = 0;
        for(auto &vec: ans2){
            maxim = max(maxim,vec[1]);
        }
        int n = edges1.size()+1;
        vector<int> ans(n);
        for(int i=0;i<n;++i){
            ans[i] = maxim + ans1[i][0];
        }
        return ans;
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