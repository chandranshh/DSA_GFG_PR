//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> dp(n + 1, -1);
        return eneCal(0, n, k, height, dp);
    }

    int eneCal(int idx, int n, int k, vector<int>& height, vector<int>& dp) {
        if (idx >= n - 1) {
            return 0;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        int jumpK = INT_MAX;
        int jump = 0;
        for (int i = 1; i <= k; i++) {
            if (idx + i < n) {
                jump = abs(height[idx] - height[idx + i]) + eneCal(idx + i, n, k, height, dp);
            }
            jumpK = min(jumpK, jump);
        }
        dp[idx] = jumpK;
        return jumpK;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends