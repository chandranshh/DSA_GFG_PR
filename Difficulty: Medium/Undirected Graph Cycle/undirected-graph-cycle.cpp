//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        
        queue<pair<int, int>> q; 
        
        for (int i = 0; i < V; ++i) {
            if (!vis[i]) {
                q.push({i, -1});
                
                while (!q.empty()) {
                    int node = q.front().first;
                    int parent = q.front().second;
                    q.pop();
                    
                    vis[node] = true;
                    
                    for (const auto& sibling : adj[node]) {
                        if (!vis[sibling]) {
                            q.push({sibling, node});
                        } else if (sibling != parent) {
                             return true;
                        }
                    }
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends