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

void solve() {
    int n;
    cin >> n;
    v1i occupied(n, 0); // Using a more descriptive name 'occupied'
    bool possible = true;   // Flag to track validity

    forloop(i, 0, n) {
        int temp;
        cin >> temp;
        int k = temp - 1;

        // If we've already found a violation, we still need to read the
        // remaining inputs for this test case to not break the next one.
        if (!possible) {
            continue;
        }

        // Check the rule for passengers after the first one
        if (i > 0) {
            bool has_occupied_neighbor = false;
            if (k > 0 && occupied[k - 1] == 1) {
                has_occupied_neighbor = true;
            }
            if (k < n - 1 && occupied[k + 1] == 1) {
                has_occupied_neighbor = true;
            }

            if (!has_occupied_neighbor) {
                possible = false; // Set flag to false instead of returning
            }
        }
        
        // Mark the current seat as occupied
        occupied[k] = 1;
    }

    if (possible) {
        cout << "yes\n";
    } else {
        cout << "no\n";
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


