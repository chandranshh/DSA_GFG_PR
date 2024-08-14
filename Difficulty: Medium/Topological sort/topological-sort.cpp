//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//dfs topo using stack and recursion + backtrack
/*class Solution
{
    private:
    void dfs(int node, vector<int>& vis, stack<int>& st, vector<int> adj[]){
        vis[node] = 1;
        for(auto neighbour : adj[node]){
            if(vis[neighbour] == 0){
                dfs(neighbour, vis, st, adj);
            }
        }
        st.push(node);
    }
    
    public:
    vector<int> topoSort(int V, vector<int> adj[]) 
    {
        vector<int> vis(V, 0);
        stack<int> st;
        vector<int> ans; 
        
        for(int node = 0; node < V; node++){
            if(vis[node] == 0){
                dfs(node, vis, st, adj);
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};
*/

//bfs using queue
class Solution
{
    public:
    vector<int> topoSort(int V, vector<int> adj[]) 
    {
        int indegree[V] = {0};
        for(int node = 0; node < V; node++){
            for(auto neighbour : adj[node]){
                indegree[neighbour]++;
            }
        }
        
        queue<int>q;
        for(int node = 0; node < V;node++){
            if(indegree[node]==0){
                q.push(node);
            }
        }
        
        vector<int>topoAns;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto node = q.front();
                q.pop();
                topoAns.push_back(node);
                for(auto neighbour : adj[node]){
                    indegree[neighbour]--;
                    if(indegree[neighbour]==0){
                        q.push(neighbour);
                    }
                }
            }
        }
        
        return topoAns;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends