//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
       vector<vector<int>>adj(N);
       for(const auto &edge : edges){
           int u = edge[0];
           int v = edge[1];
           adj[u].push_back(v);
           adj[v].push_back(u);
       }
       
       vector<int>dist(N, -1);
       
       dist[src] = 0;
       queue<int>q;
       q.push(src);
       
       while(!q.empty()){
           const auto& node = q.front();
           q.pop();
           for(const auto & neighbour : adj[node]){
               if(dist[neighbour] == -1){
                   dist[neighbour] = dist[node]+1;
                   q.push(neighbour);
               }
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
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends