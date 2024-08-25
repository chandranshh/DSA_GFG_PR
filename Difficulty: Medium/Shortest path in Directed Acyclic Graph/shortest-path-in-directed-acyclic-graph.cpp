//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<pair<int, int>>> adj(N);
        vector<int>indegree(N, 0);
        for(const auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v,wt});
            indegree[v]++;
        }
        
        queue<int> q;
        for(int i = 0; i < N; ++i) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> dist(N, INT_MAX);
        dist[0] = 0;
        
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(const auto &neighbour : adj[node]) {
                int v = neighbour.first;
                int weight = neighbour.second;
                
                if(dist[node] != INT_MAX && dist[node] + weight < dist[v]) {
                    dist[v] = dist[node] + weight;
                }
                
                if(--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        // Convert unreachable nodes to -1
        for(int i = 0; i < N; ++i) {
            if(dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends