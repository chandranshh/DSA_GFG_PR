//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        // Initialize variables
        int max_len = 0;
        int curr_sum = 0;
        unordered_map<int, int> sum_index_map;
        
        for (int i = 0; i < n; ++i) {
            curr_sum += arr[i];
            
            // If the current sum is 0, update max_len
            if (curr_sum == 0) {
                max_len = i + 1;
            }
            
            // If the current sum is seen before, update max_len
            if (sum_index_map.find(curr_sum) != sum_index_map.end()) {
                max_len = max(max_len, i - sum_index_map[curr_sum]);
            } else {
                // Store the first occurrence of the current sum
                sum_index_map[curr_sum] = i;
            }
        }
        
        return max_len;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends