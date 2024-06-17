//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n, -1);
        return eneCal(0, n, height, dp);
    }

    int eneCal(int idx, int n, vector<int>& height, vector<int>& dp) {
        if (idx >= n - 1) {  
            return 0;
        }

        if (dp[idx] != -1) {  
            return dp[idx];
        }

        int one = INT_MAX, two = INT_MAX;
        if (idx + 1 < n) {
            one = abs(height[idx] - height[idx + 1]) + eneCal(idx + 1, n, height, dp);
        }
        if (idx + 2 < n) {
            two = abs(height[idx] - height[idx + 2]) + eneCal(idx + 2, n, height, dp);
        }

        dp[idx] = min(one, two);
        return dp[idx];
    }
    
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends