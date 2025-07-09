#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        // Check if array is sorted in non-decreasing order
        bool is_sorted = true;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] > a[i + 1]) {
                is_sorted = false;
                // Found a decreasing pair - return it as derangement
                cout << "YES\n";
                cout << "2\n";
                cout << a[i] << " " << a[i + 1] << "\n";
                break;
            }
        }
        
        if (is_sorted) {
            cout << "NO\n";
        }
    }
    
    return 0;
}