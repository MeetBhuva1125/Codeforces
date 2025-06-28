#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        
        // Count frequency of 0s and 1s
        int freq0 = 0, freq1 = 0;
        for(char c : s){
            if(c == '0') freq0++;
            else freq1++;
        }
        
        // Since n is even, we have exactly n/2 pairs
        int pairs = n / 2;
        
        // We want exactly k good pairs and (pairs-k) bad pairs
        // Good pairs: both positions have same character (uses 2 of same type)
        // Bad pairs: positions have different characters (uses 1 of each type)
        
        int bad_pairs = pairs - k;
        
        // For bad pairs, we need exactly bad_pairs of each character type
        // Check if we have enough characters for bad pairs
        if(bad_pairs > freq0 || bad_pairs > freq1){
            cout << "NO" << endl;
            continue;
        }
        
        // Remaining characters after using for bad pairs
        int remaining_0 = freq0 - bad_pairs;
        int remaining_1 = freq1 - bad_pairs;
        
        // These remaining characters must form exactly k good pairs
        // Each good pair uses 2 characters of the same type
        // So total remaining should be 2*k
        if(remaining_0 + remaining_1 != 2 * k){
            cout << "NO" << endl;
            continue;
        }
        
        // Check if we can form exactly k good pairs from remaining characters
        // We need both remaining_0 and remaining_1 to be even
        // (since each good pair uses 2 characters of same type)
        if(remaining_0 % 2 == 0 && remaining_1 % 2 == 0){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}