//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
         unordered_map<int, int> freq;
    vector<int> result(2, 0);

    // Count the frequency of each element in the array
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Find the repeating and missing numbers
    for (int i = 1; i <= n; i++) {
        if (freq[i] == 0) {
            result[1] = i; // Missing number
        } else if (freq[i] > 1) {
            result[0] = i; // Repeating number
        }
    }

    return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends