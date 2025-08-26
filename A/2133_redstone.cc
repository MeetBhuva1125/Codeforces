#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forloop(i, a, b) for (int i=a; i<b; i++)
#define forloopR(i, a, b) for(int i=a; i>=b; i--)
#define v1d(type, name, n) vector<type> name(n)
#define v2d(type, name, m, n) vector<vector<type>> name(m, vector<type>(n))

void solve(){
    int n;
    cin >> n;
    
    unordered_set<int> unique_gears;
    
    // Read the n gear sizes
    for (int i = 0; i < n; ++i) {
        int teeth_count;
        cin >> teeth_count;
        unique_gears.insert(teeth_count);
    }
    
    // If the number of unique gears is less than the total number of gears,
    // it means there was at least one duplicate.
    if (unique_gears.size() < n) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}