//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int starting = 0; // Starting node for DFS
        vector<int> visited(V, 0); // Visited array
        vector<int> dfs_ans; // Resultant DFS traversal
        dfs(starting, visited, adj, dfs_ans); // Correct function call
        return dfs_ans;
    }
    
    void dfs(int node, vector<int>& visited, vector<int> adj[], vector<int>& dfs_ans) {
        visited[node] = 1; // Mark the node as visited
        dfs_ans.push_back(node); // Add the node to the DFS result
        for (int neighbor : adj[node]) { // Iterate through all adjacent nodes
            if (!visited[neighbor]) { // If the neighbor is not visited
                dfs(neighbor, visited, adj, dfs_ans); // Correct function call
            }
        }
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends