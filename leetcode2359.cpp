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

void dfs(int index,vector<int> &edges,vector<int> &dist){
    int distance = 0;
    while(index != -1 && dist[index] == -1){
        dist[index] = distance;
        distance++;
        index = edges[index];
    }
}
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n,-1),dist2(n,-1);
        dfs(node1,edges,dist1);
        dfs(node2,edges,dist2);
        int res = -1;
        int minDist = INT_MAX;
        for(int i=0;i<n;++i){
            if(dist1[i] != -1 && dist2[i] != -1){
                int val = max(dist1[i],dist2[i]);
                if(val < minDist){
                    minDist = val;
                    res = i;
                }
            }
        }
        return res;
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