#include<bits/stdc++.h>
using namespace std;

// Function to determine if every column has at least 'k' occurrences of any character
string solve(vector<string> &strings, int k, int n){
    int  size = strings[0].size();
    vector<int> maxArr;
    // Iterate over each column
    for(int i=0; i<size; i++){
        unordered_map<char,int> mp;
        int maxi = INT_MIN;
        // Count frequency of each character in the current column
        for(int j=0; j<n; j++){
            mp[strings[j][i]]++;
            maxi = max(maxi,mp[strings[j][i]]);
        }
        cout << "Max for column " << i << ": " << maxi << endl; // Debugging line
        maxArr.push_back(maxi); // Store the maximum frequency for this column
    }
    int mini = INT_MAX;
    // Find the minimum of the maximum frequencies across all columns
    for(int i=0; i<maxArr.size(); i++){
        mini = min(mini, maxArr[i]);
    }
    // If the minimum is at least k, return "YES", else "NO"
    return (mini >= k) ? "YES" : "NO";
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<string> strings(n);
    // Read n strings
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        strings[i] = s;
    }
    // Call the solve function and print the result
    string ans = solve(strings,k,n);
    cout << ans;
}