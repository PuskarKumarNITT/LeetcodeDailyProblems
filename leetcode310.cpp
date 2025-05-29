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
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto &vec: edges){
            int u = vec[0],v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }
        queue<int> q;
        int count = n;
        for(int i=0;i<n;++i){
            if(indegree[i] == 1){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int sze = q.size();
            ans.clear();
            while(sze--){
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for(auto neigh: adj[node]){
                    indegree[neigh]--;
                    if(indegree[neigh] == 1) q.push(neigh);
                }
            }
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