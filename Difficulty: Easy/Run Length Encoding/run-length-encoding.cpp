//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    string encode(string s) {
        string encoded;
        int count = 1;
        
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i-1]) {
                count++;
            } else {
                encoded += s[i-1] + to_string(count);
                count = 1;
            }
        }
        
        encoded += s.back() + to_string(count);
        return encoded;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        string s;
        getline(cin,s);
        
        Solution obj;
        string res = obj.encode(s);
        
        cout<<res<<"\n";
        
    }
}

// } Driver Code Ends