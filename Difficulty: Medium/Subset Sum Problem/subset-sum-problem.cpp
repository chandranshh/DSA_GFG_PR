//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
        bool subsetSum(vector<int>& arr, int idx, int target, vector<vector<int>>& dp) {
        // Base case: if target is 0, we found a subset
        if (target == 0) {
            return true;
        }
        // Base case: if we have exhausted all elements and target is not 0
        if (idx >= arr.size()) {
            return false;
        }
        
        // Check if the result is already computed
        if (dp[idx][target] != -1) {
            return dp[idx][target] == 1;
        }

        // Pick the current element if it is less than or equal to the target
        bool pick = false;
        if (arr[idx] <= target) {
            pick = subsetSum(arr, idx + 1, target - arr[idx], dp);
        }
        
        // Not pick the current element
        bool notPick = subsetSum(arr, idx + 1, target, dp);

        // Store the result in the dp array
        dp[idx][target] = (pick || notPick) ? 1 : 0;

        return pick || notPick;
    }

    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return subsetSum(arr, 0, target, dp);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends