//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
int findFloor(vector<long long> arr, long long n, long long x) {
   int start = 0;
        int end = n-1;
       
        int ans = -1;
        
        while(start <= end){
             int mid = start + (end-start)/2;
            if(arr[mid] == x )
                return mid;
            
            else if(arr[mid] > x)
                end = mid - 1;
            
            else{
                start = mid + 1;
                ans = mid;
            }
            
            
        }
        
        return ans;
}

};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends