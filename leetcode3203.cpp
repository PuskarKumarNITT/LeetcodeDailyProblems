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
int diameter(vector<vector<int>> &edges){
    int n = edges.size()+1;
    vector<vector<int>> adj(n);
    for(auto &vec: edges){
        int u = vec[0],v = vec[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int d = 0,nodeA = 0;
    queue<pair<int,int>> q;
    q.push({0,-1});
    while(!q.empty()){
        int sze = q.size();
        d++;
        int v = 1;
        while(sze--){
            auto pr = q.front();
            int node = pr.first;
            int par = pr.second;
            q.pop();
            for(auto neigh: adj[node]){
                if(neigh == par) continue;
                if(v == 1){
                    nodeA = neigh;
                    v++;
                }
                q.push({neigh,node});
            }
        }
    }
    int depth = 0;
    q.push({nodeA,-1});
    while(!q.empty()){
        int sze = q.size();
        depth++;
        while(sze--){
            auto pr = q.front();
            int node = pr.first;
            int par = pr.second;
            q.pop();
            for(auto neigh: adj[node]){
                if(neigh == par) continue;
                q.push({neigh,node});
            }
        }
    }
    return depth;
}
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int v1 = diameter(edges1),v2 = diameter(edges2);
        cout<<v1<<" "<<v2<<endl;
        int a = (v1)/2,b = (v2)/2;
        int val= a+b+1;
        val = max(val,v1-1);
        val = max(val,v2-1);
        return val;
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