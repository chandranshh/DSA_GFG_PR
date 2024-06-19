//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) 
    {
        vector <vector<int>> dp(n, vector<int>(n + 1, 0));
        
        for(int N = 0; N <= n; N++)
            dp[0][N] = N * price[0]; 
        
        for(int index = 1; index < n; index++)
        {
            for(int N = 1; N < n + 1; N++)
            {
                int not_take = 0 + dp[index - 1][N]; 
                int take = INT_MIN;
                
                int rodLen = index + 1;
                    
                if(rodLen <= N)
                    take = price[index] + dp[index][N - rodLen];
                    
                dp[index][N] = max(take, not_take);
            }
        }
        
        return dp[n - 1][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends