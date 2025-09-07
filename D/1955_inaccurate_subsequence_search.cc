#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double dd;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_map<int,int> umpii;
typedef unordered_map<long long, long long> umpll;
typedef vector<int> v1i;
typedef vector<long long> v1l;
typedef vector<vector<int>> v2i;
typedef vector<vector<long>> v2l;

// Functions as alternatives to macros (more type-safe)
template<typename T>
vector<T> v1d_t(int n) { return vector<T>(n,0); }
template<typename T>
vector<vector<T>> v2d_t(int m, int n) { return vector<vector<T>>(m, vector<T>(n,0)); }

#define forloop(i, a, b) for(int i=a; i<b; i++)
#define forloopR(i, a, b) for(int i=a; i>=b; i--)
// #define v1d(type, name, n) vector<type> name(n,0)
// #define v2d(type, name, m, n) vector<vector<type>> name(m, vector<type>(n,0))

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    v1i a(n);
    forloop(i, 0, n) cin >> a[i];

    umpii b_freq;
    forloop(i, 0, m) {
        int b_val;
        cin >> b_val;
        b_freq[b_val]++;
    }

    umpii window_freq;
    int match_count = 0;
    int ans = 0;

    // Initialize the first window (from 0 to m-1)
    forloop(i, 0, m) {
        int val = a[i];
        window_freq[val]++;
        if (b_freq.count(val) && window_freq[val] <= b_freq[val]) {
            match_count++;
        }
    }

    if (match_count >= k) {
        ans++;
    }

    // Slide the window from index m to the end
    forloop(i, m, n) {
        // Add the new element a[i
        int new_val = a[i];
        window_freq[new_val]++;
        if (b_freq.count(new_val) && window_freq[new_val] <= b_freq[new_val]) {
            match_count++;
        }

        // Remove the old element a[i - m]
        int old_val = a[i - m];
        if (b_freq.count(old_val) && window_freq[old_val] <= b_freq[old_val]) {
            match_count--;
        }
        window_freq[old_val]--;

        if (match_count >= k) {
            ans++;
        }
    }
    cout << ans << "\n";
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
