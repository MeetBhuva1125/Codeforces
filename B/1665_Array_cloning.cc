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

    unordered_map<int,int> mp;
    int a;
    forloop(i,0,n){
        cin >> a;
        mp[a]++;
    }
    int max_freq = INT_MIN;
    for(const auto& i:mp){
        max_freq = max(max_freq, i.second);
    }

    if (max_freq == n) {
        cout << 0 << "\n";
        return;
    }

    int operations = 0;
    int current_freq = max_freq;
    while(current_freq < n){
        operations++;// 1 for the clone operation
        int swaps_this_step = min(current_freq, n - current_freq);
        operations += swaps_this_step;
        current_freq += swaps_this_step;
    }
    cout << operations << "\n";
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