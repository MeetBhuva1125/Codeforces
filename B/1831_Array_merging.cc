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
    int n;
    cin >> n;
    v1i a(n);
    v1i b(n);
    forloop(i,0,n){
        cin >> a[i];
    }
    forloop(i,0,n){
        cin >> b[i];
    }

    auto get_max_consecutive = [](const v1i& arr) {
        umpii max_lengths;
        if (arr.empty()) {
            return max_lengths;
        }

        int current_run_val = arr[0];
        int current_run_len = 0;
        for (int x : arr) {
            if (x == current_run_val) {
                current_run_len++;
            } else {
                max_lengths[current_run_val] = max(max_lengths[current_run_val], current_run_len);
                current_run_val = x;
                current_run_len = 1;
            }
        }
        max_lengths[current_run_val] = max(max_lengths[current_run_val], current_run_len);

        return max_lengths;
    };

    umpii max_a = get_max_consecutive(a);
    umpii max_b = get_max_consecutive(b);

    int max_len = 0;

    // Combine lengths from max_b into max_a
    for(auto const& [val, len] : max_b){
        max_a[val] += len;
    }

    // Find the max length in the combined map
    for(auto const& [val, len] : max_a){
        max_len = max(max_len, len);
    }
    cout << max_len << "\n";
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


