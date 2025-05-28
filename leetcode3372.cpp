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
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = 1 + edges1.size(),m= 1+ edges2.size();
        vector<vector<int>> adj1(n),adj2(m);
        for(auto &vec: edges1){
            int u = vec[0],v = vec[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        vector<int> indegree(m,0);
        for(auto &vec: edges2){
            int u = vec[0],v = vec[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
            indegree[u]++,indegree[v]++;
        }
        vector<vector<int>> depth(m,vector<int>(m+2,0));

        for(int i=0;i<m;++i){
            int d = 1;
            queue<pair<int,int>> q;
            q.push({i,-1});
            while(!q.empty()){
                int sze = q.size();
                depth[i][d] = sze;
                d++;
                while(sze--){
                    auto pr = q.front();
                    q.pop();
                    int node = pr.first;
                    int par = pr.second;
                    for(auto neigh: adj2[node]){
                        if(neigh == par) continue;
                        q.push({neigh,node});
                    }
                }
            }
        }
        for(int i=0;i<m;++i){
            for(int j=1;j<=m+1;++j){
                depth[i][j] += depth[i][j-1];
            }
        }

        // cout<<startnode<<endl;
        // for(int i:depth) cout<<i<<" ";
        cout<<endl;
        vector<int> ans(n,0);
        for(int i=0;i<n;++i){
            int count = 0;
            for(int j=0;j<m;++j){
                count = max(count,depth[j][min(k,m+1)]);
            }
            int d1 = 0;
            queue<pair<int,int>> q;
            q.push({i,-1});
            while(!q.empty()){
                int sze = q.size();
                if(d1 > k) break;
                d1++;
                count += sze;
                while(sze--){
                    auto pr = q.front();
                    q.pop();
                    int node = pr.first;
                    int par = pr.second;
                    for(auto neigh: adj1[node]){
                        if(neigh == par) continue;
                        q.push({neigh,node});
                    }
                }
            }
            ans[i]=count;           
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