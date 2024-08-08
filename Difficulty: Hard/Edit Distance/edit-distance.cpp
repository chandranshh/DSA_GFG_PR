//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int editDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
        return helper(word1, word2, 0, 0, dp);
    }

private:
    int helper(string& word1, string& word2, int i, int j, vector<vector<int>>& dp) {
        if (i == word1.length()) {
            return word2.length() - j;
        }
        if (j == word2.length()) {
            return word1.length() - i;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (word1[i] == word2[j]) {
            dp[i][j] = helper(word1, word2, i + 1, j + 1, dp);
        } else {
            dp[i][j] = 1 + min(helper(word1, word2, i + 1, j, dp),
                               min(helper(word1, word2, i, j + 1, dp),
                                   helper(word1, word2, i + 1, j + 1, dp)));
        }

        return dp[i][j];
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends