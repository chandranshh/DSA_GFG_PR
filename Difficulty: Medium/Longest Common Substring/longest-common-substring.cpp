//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int helper(int idx1, int idx2, string& S1, string& S2, vector<vector<int>>& dp) {
        // base case
        if (idx1 < 0 || idx2 < 0) {
            return 0;
        }
        
        // if already computed, return the stored value
        if (dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }
        
        // if current characters match
        if (S1[idx1] == S2[idx2]) {
            dp[idx1][idx2] = 1 + helper(idx1 - 1, idx2 - 1, S1, S2, dp);
        } else { // if they don't match
            dp[idx1][idx2] = 0;
        }
        
        return dp[idx1][idx2];
    }

    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int maxLen = 0;
        
        // create a DP table initialized with -1
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxLen = max(maxLen, helper(i, j, S1, S2, dp));
            }
        }
        
        return maxLen;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends