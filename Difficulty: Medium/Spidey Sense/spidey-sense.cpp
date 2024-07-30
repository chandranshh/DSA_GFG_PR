//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

    public:
    vector<vector<int> > findDistance(vector<vector<char> >& matrix, int n, int m) 
    { 
        vector<vector<int>>dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        queue<pair<pair<int,int>,int>>q; //<<x,y>,steps>
        vector<vector<int>> ans(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j]=='B'){
                    q.push({{i,j},0});
                    ans[i][j]=0;
                }
            }
        }
        
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int x = q.front().first.first;
                int y = q.front().first.second;
                int steps = q.front().second;
                q.pop();
                for(const auto& dir : dirs){
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    
                    if(nx >= 0 && nx < n && ny >=0 && ny < m && matrix[nx][ny] == 'O' && ans[nx][ny] == -1){
                        ans[nx][ny]=steps+1;
                        q.push({{nx,ny},steps+1});
                    }
                }
            }
        }
        
        return ans;
    } 
};

//{ Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while(t--)
    {
    	int M,N;
        cin>>M;
        cin>>N;

        vector<vector<char> > matrix(M);
        for(int i=0; i<M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin>>matrix[i][j];
        }

        vector<vector<int> >result;
        Solution obj;
        result = obj.findDistance(matrix, M,N); 
        for(int i=0; i<M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout<<result[i][j]<<" ";
            cout<<"\n";
        }
    }

    return 0;
}
// } Driver Code Ends